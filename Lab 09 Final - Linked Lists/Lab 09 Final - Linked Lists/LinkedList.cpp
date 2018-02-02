#include "LinkedList.h"
#include <iostream>

LinkedList::~LinkedList()
{
	Node* tmp = this->getNode();
	while (tmp != this)
	{
		Node* tmp2 = tmp;
		tmp = tmp->getNode();
		delete tmp2;
	}
}

bool LinkedList::isEmpty()
{

	if (this == getNode())
	{
		return true;
	}
	return false;
}

void LinkedList::Add(const char * const addedWord)
{
	Node* current;
	Node* previous = this;
	bool  done     = false;
	while (!done)
	{
		current = previous->getNode();
		
		if (isEmpty())
		{
			previous->Append(addedWord);
			done = true;
		}
		
		else if (addedWord[0] < current->getStr()[0])
		{
			previous->Append(addedWord);
			done = true;
		}
		else if (current->getNode() == this)
		{
			current->Append(addedWord);
			done = true;
		}
		else
		{
			previous = current;
		}
	}
}

void LinkedList::Output(std::ostream & os)
{
	std::cout << "List Begin\n";
	
	Node* tmp = this->getNode();
	
	while (tmp != this)
	{
		os << tmp << std::endl;
		tmp = tmp->getNode();
	}
	std::cout << "List End\n";
}

std::ostream & operator<<(std::ostream & os, LinkedList & list)
{
	list.Output(os);
	return os;
}
 