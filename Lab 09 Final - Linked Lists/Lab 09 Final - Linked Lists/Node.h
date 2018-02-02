#pragma once
#include <ostream>
class Node
{
public:
	Node(const char* const word, Node* next) 
		: str(word), nextNode(next) {}
	~Node();

public: 
	void        Append	(const char* const appendedWord);
	Node*       getNode ();
	const char* getStr  ();

	friend      std::ostream& operator <<(std::ostream& os, Node* nodeP);

protected:
	Node*			  nextNode;
	const char* const str;
	
};
std::ostream& operator <<(std::ostream& os, Node* nodeP);


