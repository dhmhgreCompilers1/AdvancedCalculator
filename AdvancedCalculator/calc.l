%option noyywrap

%{
#include <iostream>
#include <cstdlib>
#include "calc.tab.h"
#define YY_DECL int yylex(yy::parser::semantic_type *yylval)
typedef yy::parser::token token;
%}

%%


%%