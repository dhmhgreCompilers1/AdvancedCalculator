%language "C++"

%{
#include <iostream>
#include "calc.tab.h"

using namespace std;
extern int yylex(yy::parser::semantic_type *yylval);
extern FILE *yyin;
%}
%verbose
%error-verbose

%start explist
%token NUMBER VARIABLE
%right '='
%left '+' '-'
%left '*' '/' '%'
%%

explist: expression ';'
		| explist expression ';'
		;

expression : NUMBER
		   | VARIABLE
		   | '(' expression ')'
		   | expression '+' expression
		   | expression '-' expression
		   | expression '*' expression
		   | expression '/' expression		   
		   | expression '%' expression
		   | '+' expression 
		   | '-' expression 
		   | VARIABLE '=' expression
		   ;

%%

namespace yy{
	void parser::error(yy::location const &loc, const string &message){
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}
