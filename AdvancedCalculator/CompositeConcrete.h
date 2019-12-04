#ifndef COMPOSITE_CONCRETE_
#define COMPOSITE_CONCRETE_
#include "Composite.h"

class CExpressionVARIABLE;
class CExpression;
class CVARIABLE;
class CExpList : public CSTNode {
public:

	CExpList(CExpression* expr);
	CExpList(CExpList* explst, CExpression* expr);
	virtual ~CExpList();
	virtual void PrintSyntaxTree(ofstream* dotfile,CSTNode *parent) override;
private:
};

class CExpression : public CSTNode {
public:
	CExpression(NodeType tp, int num, CExpression* arg1=nullptr, CExpression* arg2=nullptr);
	virtual ~CExpression();	
private:
};

class CExpressionAddition : public CExpression {
public:
	CExpressionAddition(CExpression*, CExpression*);
	virtual ~CExpressionAddition();
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
private:
};

class CExpressionSubtraction : public CExpression {
public:
	CExpressionSubtraction(CExpression*, CExpression*);
	virtual ~CExpressionSubtraction();
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
private:
};

class CExpressionMultiplication : public CExpression {
public:
	CExpressionMultiplication(CExpression*, CExpression*);
	virtual ~CExpressionMultiplication();
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
private:
};

class CExpressionDivision : public CExpression {
public:
	CExpressionDivision(CExpression*, CExpression*);
	virtual ~CExpressionDivision();
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
private:
};

class CExpressionModulo : public CExpression {
public:
	CExpressionModulo(CExpression*, CExpression*);
	virtual ~CExpressionModulo();
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
private:
};

class CExpressionUnaryPlus : public CExpression {
public:
	CExpressionUnaryPlus(CExpression*);
	virtual ~CExpressionUnaryPlus();
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
private:
};

class CExpressionUnaryMinus : public CExpression {
public:
	CExpressionUnaryMinus(CExpression*);
	virtual ~CExpressionUnaryMinus();
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
private:
};

class CExpressionAssignment : public CExpression {
public:
	CExpressionAssignment(CExpressionVARIABLE*, CExpression*);
	virtual ~CExpressionAssignment();
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
private:
};

class CExpressionVARIABLE : public CExpression {	
public:
	string m_text;
	CExpressionVARIABLE(const char*);
	virtual ~CExpressionVARIABLE();
	string GetGraphVizLabel() override;
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
	
private:
};

class CExpressionNUMBER : public CExpression {
public:
	string m_text;
	double m_value;
	CExpressionNUMBER(const char*, double);
	virtual ~CExpressionNUMBER();
	string GetGraphVizLabel() override;
	virtual void PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) override;
private:
};


#endif

