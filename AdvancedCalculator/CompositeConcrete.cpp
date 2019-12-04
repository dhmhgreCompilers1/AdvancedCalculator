#include "CompositeConcrete.h"

CExpList::CExpList(CExpression* expr) : CSTNode(EXPLIST,1,expr) {}
CExpList::CExpList(CExpList* explst, CExpression* expr) : CSTNode(EXPLIST, 2, explst,expr) {}
CExpList::~CExpList() {}
void CExpList::PrintSyntaxTree(ofstream* dotfile) {
	if (m_parent != nullptr) {
		(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	}
	CSTNode::PrintSyntaxTree(dotfile);
}

CExpression::CExpression(NodeType tp, int num,CExpression *arg1, CExpression* arg2) :CSTNode(tp,num,arg1,arg2)  {	 }
CExpression::~CExpression() {}


CExpressionAddition::CExpressionAddition(CExpression*larg, CExpression*rarg) : CExpression(EXP_ADDITION,2,larg,rarg) {}
CExpressionAddition::~CExpressionAddition() {}
void CExpressionAddition::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}

CExpressionSubtraction::CExpressionSubtraction(CExpression* larg, CExpression* rarg) : CExpression(EXP_SUBTRATION, 2, larg, rarg) {}
CExpressionSubtraction::~CExpressionSubtraction() {}
void CExpressionSubtraction::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}

CExpressionMultiplication::CExpressionMultiplication(CExpression* larg, CExpression* rarg) : CExpression(EXP_MULTIPLICATION, 2, larg, rarg) {}
CExpressionMultiplication::~CExpressionMultiplication() {}
void CExpressionMultiplication::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}

CExpressionDivision::CExpressionDivision(CExpression* larg, CExpression* rarg) : CExpression(EXP_DIVISION, 2, larg, rarg) {}
CExpressionDivision::~CExpressionDivision() {}
void CExpressionDivision::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}

CExpressionModulo::CExpressionModulo(CExpression* larg, CExpression* rarg) : CExpression(EXP_MODULO, 2, larg, rarg) {}
CExpressionModulo::~CExpressionModulo() {}
void CExpressionModulo::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}

CExpressionUnaryPlus::CExpressionUnaryPlus(CExpression* arg) : CExpression(EXP_UNARYPLUS, 1, arg) {}
CExpressionUnaryPlus::~CExpressionUnaryPlus() {}
void CExpressionUnaryPlus::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}

CExpressionUnaryMinus::CExpressionUnaryMinus(CExpression* arg) : CExpression(EXP_UNARYMINUS, 1, arg) {}
CExpressionUnaryMinus::~CExpressionUnaryMinus() {}
void CExpressionUnaryMinus::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}

CExpressionAssignment::CExpressionAssignment(CExpressionVARIABLE* var, CExpression* expr) : CExpression(EXP_ASSIGNMENT, 2, var, expr) {}
CExpressionAssignment::~CExpressionAssignment() {}
void CExpressionAssignment::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}

CExpressionVARIABLE::CExpressionVARIABLE(char* text) : CExpression(EXP_VARIABLE, 0) {
	m_text = string(text);
}
CExpressionVARIABLE::~CExpressionVARIABLE() {}
void CExpressionVARIABLE::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}
string CExpressionVARIABLE::GetGraphVizLabel() {
	return m_graphvizLabel + "_" + to_string(m_serial) + "_" +m_text;
}

CExpressionNUMBER::CExpressionNUMBER(char* text, double value) : CExpression(EXP_NUMBER, 0) {
	m_text = string(text);
	m_value = value;
}
CExpressionNUMBER::~CExpressionNUMBER() {}
void CExpressionNUMBER::PrintSyntaxTree(ofstream* dotfile) {
	(*dotfile) << "\"" << m_parent->GetGraphVizLabel() << "\"->\"" << GetGraphVizLabel() << "\";\n";
	CSTNode::PrintSyntaxTree(dotfile);
}
string CExpressionNUMBER::GetGraphVizLabel() {
	return m_graphvizLabel + "_" + to_string(m_serial) + "_" + m_text;
}
