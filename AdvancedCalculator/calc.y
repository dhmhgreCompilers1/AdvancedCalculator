%language "C++"

%{
#include <iostream>
#include "calc.tab.h"
#include "CompositeConcrete.h"
using namespace std;
extern int yylex(yy::parser::semantic_type *yylval);
extern FILE *yyin;
%}
%verbose
%error-verbose

%code requires{
	#include "Composite.h"
}

%union{
	CSTNode *node;
}

%start explist
%token <node> NUMBER VARIABLE
%right '='
%left '+' '-'
%left '*' '/' '%'
%type <node> explist expression
%%

explist: expression ';'			
		| explist expression ';' 
		;

expression : NUMBER 
		   | VARIABLE
		   | '(' expression ')'  { $$ = $2; }
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
