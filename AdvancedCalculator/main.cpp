#include <iostream>
#include <fstream>
#include "calc.tab.h"
extern FILE* yyin;
using namespace std;


void main(int argc, char** argv) {
	
	ofstream* dotfile;
	fopen_s(&yyin, "test.txt", "r");
	yy::parser* p = new yy::parser();
	p->parse();
	cout << "Finished!!!";	

	dotfile = new ofstream("ST.dot", std::ofstream::out);
	(*dotfile) << "digraph G{\n";
	g_root->PrintSyntaxTree(dotfile);
	(*dotfile) << "}";
	dotfile->close();

	system("dot -Tgif ST.dot -o ST.gif");
}