%token BREAK CLASS CONTINUE ELSE EXTENDS IF NEW PRIVATE
%token PROTECTED PUBLIC RETURN STATIC SUPER THIS WHILE
%token BOOLEAN CHAR INT VOID DECAF_NULL
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET SEMICOLON COMMA PERIOD
%token ASSIGN GREATER LESS NOT EQ GEQ LEQ NEQ
%token PLUS MINUS MUL DIV AND OR MOD
%token <sVal> IDENTIFIER CHARACTER STRING BOOLEAN_LITERAL
%token <iVal> INTEGER


%token-table
%locations
%{

#include <cstdlib>
#include <cstdio>
#define YYDEBUG 1
int yylex();
int yyerror(const char * s);

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



%union { 
 int iVal; /* integer value */ 
 char * sVal; /* string value*/ 
 
 //nodeType *nPtr; /* node pointer */ 
}; 

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
|		CLASS IDENTIFIER LBRACE Members RBRACE				{}
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
		PrimitiveType						{}
|		IDENTIFIER							{}
|		Type LBRACKET RBRACKET				{}
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
		IDENTIFIER								{}
|		VarDeclaratorId LBRACKET RBRACKET
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
|		IF LPAREN Expression RPAREN Statement						{}
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
