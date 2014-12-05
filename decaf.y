%token BREAK CLASS CONTINUE ELSE EXTENDS IF NEW PRIVATE PROTECTED PUBLIC RETURN STATIC SUPER THIS WHILE BOOLEAN CHAR INT VOID DECAF_NULL
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA PERIOD ASSIGN GREATER LESS NOT EQ GEQ LEQ NEQ PLUS MINUS MUL DIV AND OR MOD
%token IDENTIFIER CHARACTER STRING BOOLEAN_LITERAL DIM
%token INTEGER


%define api.value.type {struct ParseTree *}


%token-table
%locations
%{

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include "tokenType.h"
#include "parsetree.h"

using namespace std;

int yylex();
int yyerror(const char * s);

extern Token * curTok;

%}

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



%%

Start: 
		Classes						{}		
;

Classes:
		Class						{}
|		Classes Class				{}
;

Class:
		CLASS IDENTIFIER Super LBRACE Members RBRACE		{}							
|		CLASS IDENTIFIER LBRACE Members RBRACE				{	cout << "here" << endl;
																(curTok->type==RBRACE)? cout << "True": cout << "False";
															}
;

Super:
		EXTENDS IDENTIFIER					{}							


Members:
%empty							{}
|		Members Member			{}
;

Member:
		Field					{}
|		Method					{}
|		Ctor					{}
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
