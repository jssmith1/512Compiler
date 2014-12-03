idC [$0-9a-zA-Z_]
idsC [$a-zA-Z_]
space [ \n\t\r]
dimension ("["{space}*"]"{space}*)+

%x COMMENT
%option yylineno

%{
#include "decaf.tab.h"
#include <iostream>
using namespace std;

int yyerror(const char * s);
int commentStart;
%} 

%%
"break"			return BREAK;
"class"			return CLASS;
"continue"		return CONTINUE;
"else"			return ELSE;
"extends"		return EXTENDS;
"if"			return IF;
"new"			return NEW;
"private"		return PRIVATE;
"protected"		return PROTECTED;
"public"		return PUBLIC;
"return"		return RETURN;
"static"		return STATIC;
"super"			return SUPER;
"this"			return THIS;
"while"			return WHILE;
"boolean"		return BOOLEAN; 
"char" 			return CHAR;
"int" 			return INT;
"void"			return VOID;

"("				return LPAREN;
")"				return RPAREN;
"{"				return LBRACE;
"}"				return RBRACE;
"["				return LBRACKET;
"]"				return RBRACKET;
";"				return SEMICOLON;
","				return COMMA;
"."				return PERIOD;

"="				return ASSIGN;
">"				return GREATER;
"<"				return LESS;
"!"				return NOT;
"=="			return EQ;
">="			return GEQ;
"<="			return LEQ;
"!="			return NEQ;
"+"				return PLUS;
"-"				return MINUS;
"*"				return MUL;
"/"				return DIV;
"&&"			return AND;
"||"			return OR;
"%"				return MOD;


"true"|"false"	{
					yylval.sVal = yytext;
					return BOOLEAN_LITERAL;
				}

"null"			return DECAF_NULL;

"abstract"		yyerror("Reserved word");
"byte"			yyerror("Reserved word");
"case"			yyerror("Reserved word");
"catch"			yyerror("Reserved word");
"const"			yyerror("Reserved word");
"default"		yyerror("Reserved word");
"do"			yyerror("Reserved word");
"double"		yyerror("Reserved word");
"final"			yyerror("Reserved word");
"finally"		yyerror("Reserved word");
"for"			yyerror("Reserved word");
"implements"	yyerror("Reserved word");
"import"		yyerror("Reserved word");
"instanceof"	yyerror("Reserved word");
"interface"		yyerror("Reserved word");
"long"			yyerror("Reserved word");
"native"		yyerror("Reserved word");
"goto"			yyerror("Reserved word");
"package"		yyerror("Reserved word");
"short"			yyerror("Reserved word");
"switch"		yyerror("Reserved word");
"synchronized"	yyerror("Reserved word");
"throw"			yyerror("Reserved word");
"throws"		yyerror("Reserved word");
"transient"		yyerror("Reserved word");
"try"			yyerror("Reserved word");
"volatile"		yyerror("Reserved word");

"byvalue"		yyerror("Reserved word");
"cast"			yyerror("Reserved word");
"future"		yyerror("Reserved word");
"generic"		yyerror("Reserved word");
"inner"			yyerror("Reserved word");
"none"			yyerror("Reserved word");
"operator"		yyerror("Reserved word");
"outer"			yyerror("Reserved word");
"rest"			yyerror("Reserved word");
"var"			yyerror("Reserved word");
"float"			yyerror("Forbidden word");

{idsC}{idC}*	{	
					yylval.sVal = yytext;
                	return IDENTIFIER;
                }
                
[0-9]+			{
					yylval.iVal = atoi(yytext);
					return INTEGER;
				}

{dimension}				{
							yylval.sVal=yytext;
							return DIM;
						}

\'([^\'\n\\]|(\\.))\'   	{
								yylval.sVal = yytext;
  								return CHARACTER;
							}

 \'([^\'\n\\]|(\\.))[\n]	{
 								yyerror("Character not terminated");
 							}
 							
 							
\"((\\.)|[^\\"])*\"		{
								yylval.sVal = yytext;
								return STRING;
							} 							

\"((\\.)|[^\\"])*[\n]		{
								yyerror("String not terminated");
							}

\/\/.*$   

"/*"       			BEGIN(COMMENT); commentStart = yylineno;
<COMMENT>([^*]|\*[^/])*
<COMMENT>"*/" 		BEGIN(INITIAL);
<COMMENT><<EOF>> 	{
						printf("Missing */ for block comment beginning on line %d\n",
						commentStart); return -1;
					}


{space}

<<EOF>>         return -1;

.				{printf("Stray %s on line %d\n", yytext, yylineno);}
%%

int yywrap(void) {
    return 1;
}

void bogus(int x, char * y) {
     yyunput(0, NULL);
}    
