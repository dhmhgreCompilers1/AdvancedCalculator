#include "Composite.h"

// initialize static variables
CSTNode* g_root = NULL;
int CSTNode::ms_serialCounter = 0;
const char* g_nodeTypeLabels[] = { "EXPLIST", "EXP_NUMBER", "EXP_VARIABLE", "EXP_ADDITION", "EXP_SUBTRATION",
	"EXP_MULTIPLICATION","EXP_DIVISION", "EXP_MODULO","EXP_ASSIGNMENT", "EXP_UNARYPLUS", "EXP_UNARYMINUS" };

CSTNode::CSTNode(NodeType type, int num, ...) :m_nodeType{ type } {
	va_list argumentList;
	CSTNode* child;

	va_start(argumentList, num);

	m_serial = ms_serialCounter++;
	m_graphvizLabel = g_nodeTypeLabels[m_nodeType];
	m_children = new list<CSTNode*>();

	for (int i = 0; i < num; i++) {
		child = va_arg(argumentList, CSTNode*);
		m_children->push_back(child);
		child->SetParent(this);
	}

	va_end(argumentList);
}

CSTNode::~CSTNode() {
	list<CSTNode*>::iterator it;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		delete* it;
	}
	delete m_children;
}

NodeType CSTNode::GetNodeType() {
	return m_nodeType;

}
string CSTNode::GetGraphVizLabel() {
	return m_graphvizLabel + "_" + to_string(m_serial);
}

void CSTNode::PrintSyntaxTree(ofstream* dotfile, CSTNode* parent) {
	list<CSTNode*>::iterator it;
	cout << "Visiting node " << m_graphvizLabel << std::endl;
	for (it = m_children->begin(); it != m_children->end(); it++) {
		(*it)->PrintSyntaxTree(dotfile,this);
	}
}


