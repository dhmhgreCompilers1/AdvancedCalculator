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
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
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
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};

class CExpressionSubtraction : public CExpression {
public:
	CExpressionSubtraction(CExpression*, CExpression*);
	virtual ~CExpressionSubtraction();
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};

class CExpressionMultiplication : public CExpression {
public:
	CExpressionMultiplication(CExpression*, CExpression*);
	virtual ~CExpressionMultiplication();
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};

class CExpressionDivision : public CExpression {
public:
	CExpressionDivision(CExpression*, CExpression*);
	virtual ~CExpressionDivision();
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};

class CExpressionModulo : public CExpression {
public:
	CExpressionModulo(CExpression*, CExpression*);
	virtual ~CExpressionModulo();
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};

class CExpressionUnaryPlus : public CExpression {
public:
	CExpressionUnaryPlus(CExpression*);
	virtual ~CExpressionUnaryPlus();
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};

class CExpressionUnaryMinus : public CExpression {
public:
	CExpressionUnaryMinus(CExpression*);
	virtual ~CExpressionUnaryMinus();
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};

class CExpressionAssignment : public CExpression {
public:
	CExpressionAssignment(CExpressionVARIABLE*, CExpression*);
	virtual ~CExpressionAssignment();
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};

class CExpressionVARIABLE : public CExpression {
public:
	CExpressionVARIABLE(char*);
	virtual ~CExpressionVARIABLE();
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};

class CExpressionNUMBER : public CExpression {
public:
	CExpressionNUMBER(char*, double);
	virtual ~CExpressionNUMBER();
	virtual void PrintSyntaxTree(ofstream* dotfile) override;
private:
};


#endif

