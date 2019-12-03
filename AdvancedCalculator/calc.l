%option noyywrap

%{
#include <iostream>
#include <cstdlib>
#include "calc.tab.h"
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

[a-zA-Z][a-zA-Z0-9_]*							{ cout << yytext << endl; return token::VARIABLE; }
[+-]?({INT}?\.{INT})|({INT}\.{INT}?)			{ cout << yytext << endl; return token::NUMBER;}
[+-]?{INT}										{ cout << yytext << endl; return token::NUMBER;}
[ \t\r\n]+ ;
%%