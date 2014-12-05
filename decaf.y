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



%}

%token <tokPtr> BREAK CLASS CONTINUE ELSE EXTENDS IF NEW PRIVATE PROTECTED PUBLIC RETURN STATIC SUPER THIS WHILE BOOLEAN CHAR INT VOID DECAF_NULL
%token <tokPtr> LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA PERIOD ASSIGN GREATER LESS NOT EQ GEQ LEQ NEQ PLUS MINUS MUL DIV AND OR MOD
%token <tokPtr> IDENTIFIER CHARACTER STRING BOOLEAN_LITERAL DIM
%token <tokPtr> INTEGER

%type <treePtr> Start Classes Class Members Super Member Field Method Ctor


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
															$$->addChild(new ParseTree($1)); //Starting Line
															$$->addChild(new ParseTree($2)); //Super	
															$$->addChild($5); //Members
		
		
															}							
|		CLASS IDENTIFIER LBRACE Members RBRACE				{$$ = new ParseTree("class");
															$$->addChild(new ParseTree($1)); //Starting Line
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
		Modifiers Type VarDeclaratorList SEMICOLON			{}
;

Method:
		Modifiers Type IDENTIFIER FormalArgs Block			{}
;

Ctor:
		Modifiers IDENTIFIER FormalArgs	Block				{}
;

Modifiers:
%empty								{}
|		Modifiers Modifier 		{}
;

Modifier:
		STATIC				{}
|		PUBLIC				{}
|		PRIVATE				{}
|		PROTECTED			{}
;		

FormalArgs:
		LPAREN FormalArgList RPAREN			{}
|		LPAREN RPAREN						{}
;

FormalArgList:
		FormalArg							{}
|		FormalArgList COMMA FormalArg		{}
;

FormalArg:
		Type VarDeclaratorId				{}
;

Type:
		PrimitiveType BracketLst			{}
|		IDENTIFIER	BracketLst				{}
;

BracketLst:
%empty										{}
|		BracketLst DIM		{}
;

PrimitiveType:
		BOOLEAN					{}
|		CHAR					{}
|		INT						{}
|		VOID					{}
;

VarDeclaratorList:
		VarDeclarator								{}
|		VarDeclaratorList COMMA VarDeclarator		{}
;

VarDeclarator:
		VarDeclaratorId						{}
|		VarDeclaratorId ASSIGN Expression
;

VarDeclaratorId:
		IDENTIFIER	BracketLst					{}
;

Block:
		LBRACE Statements RBRACE				{}
;

Statements:
%empty									{}
|		Statements Statement			{}

Statement:
		SEMICOLON													{}
|		Type VarDeclaratorList SEMICOLON							{}
|		IF LPAREN Expression RPAREN Statement %prec IFX						{}
|		IF LPAREN Expression RPAREN Statement ELSE Statement		{}
|		Expression SEMICOLON										{}
|		WHILE LPAREN RPAREN Statement								{}
|		RETURN Expression SEMICOLON									{}
|		RETURN	SEMICOLON											{}
|		CONTINUE SEMICOLON											{}
|		BREAK SEMICOLON												{}
|		Block														{}
;

Expression:
		Expression ASSIGN Expression			{}
|		Expression OR Expression				{}		
|		Expression AND Expression				{}		
|		Expression EQ Expression				{}		
|		Expression NEQ Expression				{}		
|		Expression LESS Expression				{}		
|		Expression GREATER Expression			{}		
|		Expression LEQ Expression				{}		
|		Expression GEQ Expression				{}		
|		Expression PLUS Expression				{}		
|		Expression MINUS Expression				{}		
|		Expression MUL Expression				{}		
|		Expression DIV Expression				{}		
|		Expression MOD Expression				{}		
|		PLUS Expression	%prec UPLUS				{}
|		MINUS Expression %prec UMINUS			{}
|		NOT Expression							{}
|		Primary									{}
;

Primary:
		NewArrayExpr			{}
|		NonNewArrayExpr			{}
|		IDENTIFIER				{}
;

NewArrayExpr:
		NEW IDENTIFIER Dimensions				{}
|		NEW PrimitiveType Dimensions			{}
;

Dimensions:
		Dimension					{}
|		Dimensions Dimension		{}
;

Dimension:
		LBRACKET Expression RBRACKET		{}
;

NonNewArrayExpr:
		Literal									{}
|		THIS									{}
|		LPAREN Expression RPAREN				{}
|		NEW IDENTIFIER ActualArgs				{}
|		IDENTIFIER ActualArgs					{}
|		Primary PERIOD IDENTIFIER ActualArgs	{}
|		SUPER PERIOD IDENTIFIER ActualArgs		{}
|		ArrayExpr								{}
|		FieldExpr								{}
;

FieldExpr: 
		Primary PERIOD IDENTIFIER				{}
|		SUPER PERIOD IDENTIFIER					{}
;

ArrayExpr: 
		IDENTIFIER Dimension					{}
|		NonNewArrayExpr Dimension				{}
;

Literal:
		DECAF_NULL					{}
|		BOOLEAN_LITERAL				{}
|		INTEGER						{}
|		CHARACTER					{}
|		STRING						{}
;

ActualArgs:
		LPAREN ExprList	RPAREN					{}
|		LPAREN RPAREN							{}
;

ExprList:
		Expression						{}
|		ExprList COMMA Expression		{}
;


%%
const char * const* token_table = yytname;

int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
