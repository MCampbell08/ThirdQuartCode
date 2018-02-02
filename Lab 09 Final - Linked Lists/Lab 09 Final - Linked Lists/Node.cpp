#include "Node.h"

Node::~Node()
{
	delete str;
}

void Node::Append(const char * const word)
{
	nextNode = new Node(word, nextNode);
}

Node * Node::getNode()
{
	return nextNode;
}

const char * Node::getStr()
{
	return str;
}

std::ostream & operator <<(std::ostream & os, Node * nodeP)
{
	return os << "  Node [" << nodeP->getStr() << "]";
}
