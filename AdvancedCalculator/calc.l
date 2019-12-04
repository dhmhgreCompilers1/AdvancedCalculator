%option noyywrap

%{
#include <iostream>
#include <cstdlib>
#include "calc.tab.h"
#include "CompositeConcrete.h"
#include "SymbolTable.h"
using namespace std;
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
typedef yy::parser::token token;
%}

INT "0"|[1-9][0-9]*
%%
"+" {return '+';}
"-" {return '-';}
"*" {return '*';}
"/" {return '/';}
"%" {return '%';}
";" {return ';';}
"(" {return '(';}
")" {return ')';}
"=" {return '=';}

[a-zA-Z][a-zA-Z0-9_]*					{   yylval->node = g_symbolTable.GetSymbol(yytext);
											return token::VARIABLE; }
({INT}?\.{INT})|({INT}\.{INT}?)			{  yylval->node = new CExpressionNUMBER(yytext,atof(yytext));
										   return token::NUMBER;}
{INT}									{   yylval->node = new CExpressionNUMBER(yytext,(double)atoi(yytext));
											return token::NUMBER;}
[ \t\r\n]+ ;
%%