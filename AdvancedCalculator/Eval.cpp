#include "CompositeConcrete.h"

double VisitEvalHelper(CSTNode *node, int child) {	
	return node->GetChild(child)->Eval(node);
}

double CExpList::Eval(CSTNode* parent) {
	double lvalue, rvalue, result = 0;

	// Preorder Action :

	// Visit Children
	lvalue = VisitEvalHelper(this, 0);
	if (m_children->size() > 1) {
		rvalue = VisitEvalHelper(this, 1);
	}
	// Post Order Action : Calculate Result

	return result;
}
double CExpressionAddition::Eval(CSTNode* parent) {
	double lvalue,rvalue, result=0;
	
	// Preorder Action :

	// Visit Children
	lvalue = VisitEvalHelper(this,0);
	rvalue = VisitEvalHelper(this,1);
	// Post Order Action : Calculate Result

	return result=lvalue+rvalue;
}
double CExpressionSubtraction::Eval(CSTNode* parent) {
	double lvalue, rvalue, result = 0;
	// Preorder Action :

	// Visit Children
	lvalue = VisitEvalHelper(this, 0);
	rvalue = VisitEvalHelper(this, 1);
	// Post Order Action : Calculate Result

	return result = lvalue - rvalue;
}
double CExpressionMultiplication::Eval(CSTNode* parent) {
	double lvalue, rvalue, result = 0;
	// Preorder Action :

	// Visit Children
	lvalue = VisitEvalHelper(this, 0);
	rvalue = VisitEvalHelper(this, 1);
	// Post Order Action : Calculate Result

	return result = lvalue * rvalue;
}
double CExpressionDivision::Eval(CSTNode* parent) {
	double lvalue, rvalue, result = 0;
	// Preorder Action :

	// Visit Children
	lvalue = VisitEvalHelper(this, 0);
	rvalue = VisitEvalHelper(this, 1);
	// Post Order Action : Calculate Result

	return result = lvalue / rvalue;
}
double CExpressionModulo::Eval(CSTNode* parent) {
	double lvalue, rvalue, result = 0;
	// Preorder Action :

	// Visit Children
	lvalue = VisitEvalHelper(this, 0);
	rvalue = VisitEvalHelper(this, 1);
	// Post Order Action : Calculate Result

	return result = (int)lvalue % (int)rvalue;
}
double CExpressionUnaryPlus::Eval(CSTNode* parent) {
	double lvalue, result = 0;
	// Preorder Action :

	// Visit Children
	lvalue = VisitEvalHelper(this, 0);
	// Post Order Action : Calculate Result

	return result = +lvalue ;
}
double CExpressionUnaryMinus::Eval(CSTNode* parent) {
	double lvalue, result = 0;
	// Preorder Action :

	// Visit Children
	lvalue = VisitEvalHelper(this, 0);
	// Post Order Action : Calculate Result

	return result = -lvalue;
}
double CExpressionAssignment::Eval(CSTNode* parent) {
	double result=0;
	CExpressionVARIABLE* var;
	// Preorder Action :

	// Visit Children
	var = (CExpressionVARIABLE *)GetChild(0);
	result = VisitEvalHelper(this, 1);
	
	// Post Order Action : Calculate Result
	var->m_value = result;
	cout << var->m_text << "=" << result << endl;
	return result;
}
double CExpressionVARIABLE::Eval(CSTNode* parent) {
	double result = m_value;
	
	return result;
}
double CExpressionNUMBER::Eval(CSTNode* parent) {
	double result=m_value;
	
	return result;
}