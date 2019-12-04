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

explist: expression ';'				{ $$ = g_root = new CExpList((CExpression*) $1); }
		| explist expression ';'	{ $$ = g_root = new CExpList((CExpList *)$1, (CExpression*) $2); }
		;

expression : NUMBER   { $$= $1; }
		   | VARIABLE { $$= $1; }
		   | '(' expression ')'  { $$ = $2; }
		   | expression '+' expression { $$ = new CExpressionAddition((CExpression *)$1, (CExpression*) $3); }
		   | expression '-' expression { $$ = new CExpressionSubtraction((CExpression *)$1, (CExpression*) $3); }
		   | expression '*' expression { $$ = new CExpressionMultiplication((CExpression *)$1, (CExpression*) $3); }
		   | expression '/' expression { $$ = new CExpressionDivision((CExpression *)$1, (CExpression*) $3); }		    
		   | expression '%' expression { $$ = new CExpressionModulo((CExpression *)$1, (CExpression*) $3); }
		   | '+' expression			{ $$ = new CExpressionUnaryPlus((CExpression*) $2); }
		   | '-' expression			{ $$ = new CExpressionUnaryMinus((CExpression*) $2); }
		   | VARIABLE '=' expression { $$ = new CExpressionAssignment((CExpressionVARIABLE *)$1, (CExpression*) $3); }
		   ;

%%

namespace yy{
	void parser::error(yy::location const &loc, const string &message){
		std::cerr << "error at " << loc << ": " << message << std::endl;
	}
}
