#pragma once
#include "Node.h"
class LinkedList : public Node
{
public:
	LinkedList () : Node(nullptr, this) {}
	~LinkedList();

public:
	bool isEmpty ();
	void Add     (const char* const addedWord);
	void Output  (std::ostream& os);
};
std::ostream& operator << (std::ostream& os, LinkedList& list);

