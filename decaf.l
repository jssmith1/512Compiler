idC [$0-9a-zA-Z_]
idsC [$a-zA-Z_]
space [ \n\t\r]
dimension ("["{space}*"]"{space}*)+

%x COMMENT
%option yylineno

%{
#define TOKEN(t) (curTok = new Token(t, strdup(yytext), yylineno));


#include "decaf.tab.h"
#include <iostream>
#include "tokenType.h"
using namespace std;
int yyerror(const char * s);
int commentStart;



Token * curTok;
%} 

%%
"break"			  TOKEN(BREAK); return BREAK;
"class"			  TOKEN(CLASS); return CLASS;
"continue"		  TOKEN(CONTINUE); return CONTINUE;
"else"			  TOKEN(ELSE); return ELSE;
"extends"		  TOKEN(EXTENDS); return EXTENDS;
"if"			  TOKEN(IF); return IF;
"new"			  TOKEN(NEW); return NEW;
"private"		  TOKEN(PRIVATE); return PRIVATE;
"protected"		  TOKEN(PROTECTED); return PROTECTED;
"public"		  TOKEN(PUBLIC); return PUBLIC;
"return"		  TOKEN(RETURN); return RETURN;
"static"		  TOKEN(STATIC); return STATIC;
"super"			  TOKEN(SUPER); return SUPER;
"this"			  TOKEN(THIS); return THIS;
"while"			  TOKEN(WHILE); return WHILE;
"boolean"		  TOKEN(BOOLEAN);  return BOOLEAN;
"char" 			  TOKEN(CHAR); return CHAR;
"int" 			  TOKEN(INT); return INT;
"void"			  TOKEN(VOID); return VOID;
"("				  TOKEN(LPAREN); return LPAREN;
")"				  TOKEN(RPAREN); return RPAREN;
"{"				  TOKEN(LBRACE); return LBRACE;
"}"				  TOKEN(RBRACE); return RBRACE;
"["				  TOKEN(LBRACKET); return LBRACKET;
"]"				  TOKEN(RBRACKET); return RBRACKET;
");"			  TOKEN(SEMICOLON); return SEMICOLON;
","				  TOKEN(COMMA); return COMMA;
"."				  TOKEN(PERIOD); return PERIOD;
"="				  TOKEN(ASSIGN); return ASSIGN;
">"				  TOKEN(GREATER); return GREATER;
"<"				  TOKEN(LESS); return LESS;
"!"				  TOKEN(NOT); return NOT;
"=="			  TOKEN(EQ); return EQ;
">="			  TOKEN(GEQ); return GEQ;
"<="			  TOKEN(LEQ); return LEQ;
"!="			  TOKEN(NEQ); return NEQ;
"+"				  TOKEN(PLUS); return PLUS;
"-"				  TOKEN(MINUS); return MINUS;
"*"				  TOKEN(MUL); return MUL;
"/"				  TOKEN(DIV); return DIV;
"&&"			  TOKEN(AND); return AND;
"||"			  TOKEN(OR); return OR;
"%"				  TOKEN(MOD); return MOD;


"true"|"false"	{
					TOKEN(BOOLEAN_LITERAL);
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
					TOKEN(IDENTIFIER)
			    	return IDENTIFIER;
                }
                
[0-9]+			{
					TOKEN(INTEGER);
					return INTEGER;
				}

{dimension}				{
							TOKEN(DIM);
							return DIM;
						}

\'([^\'\n\\]|(\\.))\'   	{
								TOKEN(CHARACTER);
  								return CHARACTER;
							}

 \'([^\'\n\\]|(\\.))[\n]	{
 								yyerror("Character not terminated");
 							}
 							
 							
\"((\\.)|[^\\"])*\"		{
								TOKEN(STRING);
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
