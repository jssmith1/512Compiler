%{
#define TOKEN(t) (curTok = new Token(t, strdup(yytext), yylineno));


#include "tokenType.h"
#include "parsetree.h"

#include "decaf.tab.h"
#include <iostream>

using namespace std;
int yyerror(const char * s);
int commentStart;


Token * curTok;
%} 


idC [$0-9a-zA-Z_]
idsC [$a-zA-Z_]
space [ \n\t\r]
dimension ("["{space}*"]"{space}*)+

%x COMMENT
%option yylineno


%%
"break"			  TOKEN(BREAK); yylval.tokPtr = curTok; return BREAK;
"class"			  TOKEN(CLASS); yylval.tokPtr = curTok; return CLASS;
"continue"		  TOKEN(CONTINUE); yylval.tokPtr = curTok; return CONTINUE;
"else"			  TOKEN(ELSE); yylval.tokPtr = curTok; return ELSE;
"extends"		  TOKEN(EXTENDS); yylval.tokPtr = curTok; return EXTENDS;
"if"			  TOKEN(IF); yylval.tokPtr = curTok; return IF;
"new"			  TOKEN(NEW); yylval.tokPtr = curTok; return NEW;
"private"		  TOKEN(PRIVATE); yylval.tokPtr = curTok; return PRIVATE;
"protected"		  TOKEN(PROTECTED); yylval.tokPtr = curTok; return PROTECTED;
"public"		  TOKEN(PUBLIC); yylval.tokPtr = curTok; return PUBLIC;
"return"		  TOKEN(RETURN); yylval.tokPtr = curTok; return RETURN;
"static"		  TOKEN(STATIC); yylval.tokPtr = curTok; return STATIC;
"super"			  TOKEN(SUPER); yylval.tokPtr = curTok; return SUPER;
"this"			  TOKEN(THIS); yylval.tokPtr = curTok; return THIS;
"while"			  TOKEN(WHILE); yylval.tokPtr = curTok; return WHILE;
"boolean"		  TOKEN(BOOLEAN);  yylval.tokPtr = curTok; return BOOLEAN;
"char" 			  TOKEN(CHAR); yylval.tokPtr = curTok; return CHAR;
"int" 			  TOKEN(INT); yylval.tokPtr = curTok; return INT;
"void"			  TOKEN(VOID); yylval.tokPtr = curTok; return VOID;
"("				  TOKEN(LPAREN); yylval.tokPtr = curTok; return LPAREN;
")"				  TOKEN(RPAREN); yylval.tokPtr = curTok; return RPAREN;
"{"				  TOKEN(LBRACE); yylval.tokPtr = curTok; return LBRACE;
"}"				  TOKEN(RBRACE); yylval.tokPtr = curTok; return RBRACE;
"["				  TOKEN(LBRACKET); yylval.tokPtr = curTok; return LBRACKET;
"]"				  TOKEN(RBRACKET); yylval.tokPtr = curTok; return RBRACKET;
";"			  TOKEN(SEMICOLON); yylval.tokPtr = curTok; return SEMICOLON;
","				  TOKEN(COMMA); yylval.tokPtr = curTok; return COMMA;
"."				  TOKEN(PERIOD); yylval.tokPtr = curTok; return PERIOD;
"="				  TOKEN(ASSIGN); yylval.tokPtr = curTok; return ASSIGN;
">"				  TOKEN(GREATER); yylval.tokPtr = curTok; return GREATER;
"<"				  TOKEN(LESS); yylval.tokPtr = curTok; return LESS;
"!"				  TOKEN(NOT); yylval.tokPtr = curTok; return NOT;
"=="			  TOKEN(EQ); yylval.tokPtr = curTok; return EQ;
">="			  TOKEN(GEQ); yylval.tokPtr = curTok; return GEQ;
"<="			  TOKEN(LEQ); yylval.tokPtr = curTok; return LEQ;
"!="			  TOKEN(NEQ); yylval.tokPtr = curTok; return NEQ;
"+"				  TOKEN(PLUS); yylval.tokPtr = curTok; return PLUS;
"-"				  TOKEN(MINUS); yylval.tokPtr = curTok; return MINUS;
"*"				  TOKEN(MUL); yylval.tokPtr = curTok; return MUL;
"/"				  TOKEN(DIV); yylval.tokPtr = curTok; return DIV;
"&&"			  TOKEN(AND); yylval.tokPtr = curTok; return AND;
"||"			  TOKEN(OR); yylval.tokPtr = curTok; return OR;
"%"				  TOKEN(MOD); yylval.tokPtr = curTok; return MOD;


"true"|"false"	{
					TOKEN(BOOLEAN_LITERAL);
					yylval.tokPtr = curTok; return BOOLEAN_LITERAL;
				}

"null"			TOKEN(DECAF_NULL); yylval.tokPtr = curTok; return DECAF_NULL;

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
			    	yylval.tokPtr = curTok; return IDENTIFIER;
                }
                
[0-9]+			{
					TOKEN(INTEGER);
					yylval.tokPtr = curTok; return INTEGER;
				}

{dimension}				{
							TOKEN(DIM);
							yylval.tokPtr = curTok; return DIM;
						}

\'([^\'\n\\]|(\\.))\'   	{
								TOKEN(CHARACTER);
  								yylval.tokPtr = curTok; return CHARACTER;
							}

 \'([^\'\n\\]|(\\.))[\n]	{
 								yyerror("Character not terminated");
 							}
 							
 							
\"((\\.)|[^\\"])*\"		{
								TOKEN(STRING);
								yylval.tokPtr = curTok; return STRING;
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
