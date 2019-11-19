// PracticeC.cpp : Defines the entry point for the application.
//

#include "CPractice.h"

int main()
{
	LinkedList <int>* a = new LinkedList<int>();
	int b = 5;
	int* c = &b;
	a->addAtHead(1);
	a->addAtTail(3);
	a->insertItem(2, 1);
	a->insertItem(4, 3);
	a->insertItem(5, 0);
	Node<int>* temp = a->getHead();
	a->removeNode(2);
	std::cout << a->getHead()->item << std::endl;
	std::cout << *c << std::endl;
	int x;
	std::cin >> x;
	delete a;
	return 0;
}

