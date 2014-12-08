%{
#include "parsetree.h"
#include "tokenType.h"

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int yylex();
int yyerror(const char * s);

extern ParseTree * top;
extern Token * curTok;

ParseTree * buildBopTree(Token * op, ParseTree * one, ParseTree * four){
          ParseTree * temp = new ParseTree("expr");
          temp->addChild(new ParseTree(op));
          temp->addChild(one);
          temp->addChild(four);
          return temp;
} 


%}

%token <tokPtr> BREAK CLASS CONTINUE ELSE EXTENDS IF NEW PRIVATE PROTECTED PUBLIC RETURN STATIC SUPER THIS WHILE BOOLEAN CHAR INT VOID DECAF_NULL
%token <tokPtr> LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA PERIOD ASSIGN GREATER LESS NOT EQ GEQ LEQ NEQ PLUS MINUS MUL DIV AND OR MOD
%token <tokPtr> IDENTIFIER CHARACTER STRING BOOLEAN_LITERAL DIM
%token <tokPtr> INTEGER

%type <treePtr> Start Classes Class Members Super Member Field Method Ctor Modifiers Modifier FormalArgs FormalArgList 
%type <treePtr> FormalArg Type BracketLst PrimitiveType VarDeclaratorList VarDeclarator VarDeclaratorId Block Statements 
%type <treePtr> Statement Expression Primary NewArrayExpr Dimensions Dimension NonNewArrayExpr FieldExpr ArrayExpr Literal ActualArgs ExprList

%token-table
%locations
%code requires {

				}


%right ASSIGN
%left OR
%left AND
%left NEQ
%left EQ
%nonassoc LEQ
%nonassoc GEQ
%nonassoc LESS
%nonassoc GREATER
%left MINUS
%left PLUS
%left MOD
%left DIV
%left MUL
%precedence NOT UMINUS UPLUS
%precedence IFX
%precedence ELSE


%union { 
 Token * tokPtr; /* Token Pointer*/ 
 ParseTree * treePtr; /* Parse Tree Pointer*/ 
} 


%%


Start: 
		Classes						{top = $$ = $1;}		
;

Classes:
		Class						{$$ = new ParseTree("classes");
									$$ -> addChild($1);}
|		Classes Class				{$1 -> addChild($2);
									$$=$1;}
;

Class:
		CLASS IDENTIFIER Super LBRACE Members RBRACE		{$$ = new ParseTree("class");
															$$->addChild(new ParseTree($2)); //Ident
															$$->addChild($5); //Members
															$$->addChild($3); //Super		
															}							
|		CLASS IDENTIFIER LBRACE Members RBRACE				{$$ = new ParseTree("class");
															$$->addChild(new ParseTree($2)); //class name	
															$$->addChild($4); //Members
															}
;


Super:
		EXTENDS IDENTIFIER					{$$ = new ParseTree("super");
											$$->addChild(new ParseTree($2));
											}							


Members:
%empty							{$$ = new ParseTree("members");}
|		Members Member			{$1-> addChild($2);
								$$=$1;}
;

Member:
		Field					{$$ = $1;}
|		Method					{$$ = $1;}
|		Ctor					{$$ = $1;}
;

Field:
		Modifiers Type VarDeclaratorList SEMICOLON			{$$ = new ParseTree("field");
															$$->addChild($1);
															$$->addChild($2);
															$$->addChild($3);
															}
;

Method:
		Modifiers Type IDENTIFIER FormalArgs Block			{$$ = new ParseTree("method");
															$$->addChild($1);
															$$->addChild($2);
															$$->addChild(new ParseTree($3));
															$$->addChild($4);
															$$->addChild($5);
															}
;

Ctor:
		Modifiers IDENTIFIER FormalArgs	Block				{$$ = new ParseTree("ctor");
															$$->addChild($1);
															$$->addChild(new ParseTree("blank"));
															$$->addChild(new ParseTree($2));
															$$->addChild($3);
															$$->addChild($4);
															}
;

Modifiers:
%empty								{$$ = new ParseTree("modifiers");}
|		Modifiers Modifier 			{$1->addChild($2);
									$$=$1;}
;

Modifier:
		STATIC				{$$ = new ParseTree($1);}
|		PUBLIC				{$$ = new ParseTree($1);}
|		PRIVATE				{$$ = new ParseTree($1);}
|		PROTECTED			{$$ = new ParseTree($1);}
;		

FormalArgs:
		LPAREN FormalArgList RPAREN			{$$ = $2;}
|		LPAREN RPAREN						{$$ = new ParseTree("formalArgList");}
;

FormalArgList:
		FormalArg							{$$ = new ParseTree("formalArgList");
											$$->addChild($1);}
|		FormalArgList COMMA FormalArg		{$1->addChild($3);
											$$=$1;}
;

FormalArg:
		Type VarDeclaratorId				{$$ = new ParseTree("formalArg");
											$$->addChild($1);
											$$->addChild($2);}
;

Type:
		PrimitiveType BracketLst			{$$ = new ParseTree("type"); //If you have a bracketLst, you have an array
											$$->addChild($1); 			
											if ($2) $$->addChild($2);}			
|		IDENTIFIER	BracketLst				{$$ = new ParseTree("type");
											$$->addChild(new ParseTree($1));
											if ($2) $$->addChild($2);}
;

BracketLst:
%empty							{$$ = NULL;}
|		DIM						{$$ = new ParseTree($1);}
								
;

PrimitiveType:
		BOOLEAN					{$$ = new ParseTree($1);}
|		CHAR					{$$ = new ParseTree($1);}
|		INT						{$$ = new ParseTree($1);}
|		VOID					{$$ = new ParseTree($1);}
;

VarDeclaratorList:
		VarDeclarator								{$$ = new ParseTree("varDecLst");
													$$->addChild($1);}
|		VarDeclaratorList COMMA VarDeclarator		{$1->addChild($3);
													$$ = $1;}
;

VarDeclarator:
		VarDeclaratorId							{$$ = new ParseTree("varDec");
												$$->addChild($1);}
|		VarDeclaratorId ASSIGN Expression		{$$ = new ParseTree("varDec");
												$$->addChild($1);
												$$->addChild($3);}
;

VarDeclaratorId:
		IDENTIFIER	BracketLst					{$$ = new ParseTree("varDecId");
												$$->addChild(new ParseTree($1));
												if ($2) $$->addChild($2);}
;

Block:
		LBRACE Statements RBRACE				{$$ = $2;}
;

Statements:
%empty									{$$ = new ParseTree("statements");}
|		Statements Statement			{$1->addChild($2);
										$$ = $1;}

Statement:
		SEMICOLON													{$$ = new ParseTree("blankStmt");
																	$$->addChild(new ParseTree($1));}
|		Type VarDeclaratorList SEMICOLON							{$$ = new ParseTree("declStmt");
																	$$->addChild($1);
																	$$->addChild($2);
																	}
|		IF LPAREN Expression RPAREN Statement %prec IFX				{$$ = new ParseTree("ifStmt");
																	$$->addChild($3);
																	$$->addChild($5);
																	}
|		IF LPAREN Expression RPAREN Statement ELSE Statement		{$$ = new ParseTree("ifStmt");
																	$$->addChild($3);
																	$$->addChild($5);
																	$$->addChild($7);}
|		Expression SEMICOLON										{$$ = new ParseTree("exprStmt");
																	$$->addChild($1);}
|		WHILE LPAREN Expression RPAREN Statement					{$$ = new ParseTree("whileStmt");
																	 $$->addChild($3);
																	 $$->addChild($5);}
|		RETURN Expression SEMICOLON									{$$ = new ParseTree("returnStmt");
																	$$ -> addChild(new ParseTree($1));
																	$$ -> addChild($2);}
|		RETURN	SEMICOLON											{$$ = new ParseTree("returnStmt");
																	$$ -> addChild(new ParseTree($1));
																	}
|		CONTINUE SEMICOLON											{$$ = new ParseTree("contStmt");
				 													$$->addChild(new ParseTree($1));
																	}
|		BREAK SEMICOLON												{$$ = new ParseTree("breakStmt");
																	$$->addChild(new ParseTree($1));}
|		Block														{$$ = new ParseTree("blockStmt");
																	$$->addChild($1);} 
;

Expression:
		Expression ASSIGN Expression			{$$ = buildBopTree($2, $1, $3);}
|		Expression OR Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression AND Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression EQ Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression NEQ Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression LESS Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression GREATER Expression			{$$ = buildBopTree($2, $1, $3);}		
|		Expression LEQ Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression GEQ Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression PLUS Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression MINUS Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression MUL Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression DIV Expression				{$$ = buildBopTree($2, $1, $3);}		
|		Expression MOD Expression				{$$ = buildBopTree($2, $1, $3);}		
|		PLUS Expression	%prec UPLUS				{$$ = new ParseTree("expr");
												$$->addChild(new ParseTree($1));
												$$->addChild($2);}
|		MINUS Expression %prec UMINUS			{$$ = new ParseTree("expr");
												$$->addChild(new ParseTree($1));
												$$->addChild($2);}
|		NOT Expression							{$$ = new ParseTree("expr");
												$$->addChild(new ParseTree($1));
												$$->addChild($2);}
|		Primary									{$$ = new ParseTree("expr");
												$$ -> addChild($1);}
;

Primary:
		NewArrayExpr				{$$ = new ParseTree("primary");
									$$->addChild($1);}
|		NonNewArrayExpr				{$$ = new ParseTree("primary");
									$$->addChild($1);}
|		IDENTIFIER					{$$ = new ParseTree("primary");
									$$->addChild(new ParseTree($1));}
;

NewArrayExpr:
		NEW IDENTIFIER Dimensions				{$$ = new ParseTree("newAryExp");
												$$->addChild(new ParseTree($2));
												$$->addChild($3);}
|		NEW PrimitiveType Dimensions			{$$ = new ParseTree("newAryExp");
												$$->addChild($2);
												$$->addChild($3);}

;

Dimensions:
		Dimension					{$$ = new ParseTree("dimensions");
									$$ -> addChild($1);}
|		Dimensions Dimension		{$1->addChild($2);
									$$ = $1;}
;

Dimension:
		LBRACKET Expression RBRACKET		{$$ = new ParseTree("dimension");
											$$->addChild($2);}
;

NonNewArrayExpr:
		Literal									{$$ = new ParseTree("literal_expr");
												 $$->addChild($1);}
|		THIS									{$$ = new ParseTree("this_expr");
												$$->addChild(new ParseTree($1));}
|		LPAREN Expression RPAREN				{$$ = $2;}
|		NEW IDENTIFIER ActualArgs				{$$ = new ParseTree("newObj_expr");
												$$->addChild(new ParseTree($2));
												$$->addChild($3);}
|		IDENTIFIER ActualArgs					{$$ = new ParseTree("call_expr");
												$$->addChild(new ParseTree($1));
												$$->addChild($2);}
|		Primary PERIOD IDENTIFIER ActualArgs	{$$ = new ParseTree("methodCall_expr");
												$$->addChild($1);
												$$->addChild(new ParseTree($3));
												$$->addChild($4);}
|		SUPER PERIOD IDENTIFIER ActualArgs		{$$ = new ParseTree("superCall_expr");
												$$->addChild(new ParseTree($1));
												$$->addChild(new ParseTree($3));
												$$->addChild($4);}
|		ArrayExpr								{$$ = $1;}
|		FieldExpr								{$$ = $1;}
;

FieldExpr: 
		Primary PERIOD IDENTIFIER				{$$ = new ParseTree("fieldExpr");
												$$->addChild($1);
												$$->addChild(new ParseTree($3));}
|		SUPER PERIOD IDENTIFIER					{$$ = new ParseTree("fieldExpr");
												$$->addChild(new ParseTree($1));
												$$->addChild(new ParseTree($3));}
;

ArrayExpr: 
		IDENTIFIER Dimension					{$$ = new ParseTree("arryExpr");
												$$->addChild(new ParseTree($1));
												$$->addChild($2);}
|		NonNewArrayExpr Dimension				{$$ = new ParseTree("arryExpr");
												$$->addChild($1);
												$$->addChild($2);}
;

Literal:
		DECAF_NULL					{$$ = new ParseTree($1);}
|		BOOLEAN_LITERAL				{$$ = new ParseTree($1);}
|		INTEGER						{$$ = new ParseTree($1);}
|		CHARACTER					{$$ = new ParseTree($1);}
|		STRING						{$$ = new ParseTree($1);}
;

ActualArgs:
		LPAREN ExprList	RPAREN					{$$ = $2;}
|		LPAREN RPAREN							{$$ = new ParseTree("exprList");}
;

ExprList:
		Expression						{$$ = new ParseTree("exprList");
										$$->addChild($1);}
|		ExprList COMMA Expression		{$1->addChild($3);
										$$ = $1;}
;


%%
const char * const* token_table = yytname;

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
