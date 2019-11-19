#pragma once
template <typename T> struct Node {
	T item;
	Node<T>* nextNode;
	Node<T>* prevNode;
};

template <class T> class LinkedList {

protected:
		Node<T>* head;
		Node<T>* tail;
		int length;


public:

	LinkedList() 
	{
		head = nullptr; 
		tail = nullptr;
		length = 0;
	}
	
	~LinkedList() 
	{
		if (length != 0) {
			for (int i = 0; i < length; i++) {
				Node<T>* temp = getNode(i);
				delete temp;
			}
		}
	}
	
	void addAtHead(T t) 
	{
		Node<T>* node = new Node<T>();
		node->item = t;
		if (length == 0)
		{
			head = node;
			tail = node;
		}
		else {
			node->nextNode = head;
			head->prevNode = node;
			head = node;
		}
		length = length + 1;
	}

	Node<T>* getHead() 
	{
		return head;
	}

	void addAtTail(T t)
	{
		Node<T>* node = new Node<T>();
		node->item = t;
		if (length == 0) {
			head = node;
			tail = node;
		}
		else {
			node->prevNode = tail;
			tail->nextNode = node;
			tail = node;
		}
		length = length + 1;
	}
	
	Node<T>* getNode(int index) 
	{
		if (index >= length || index < 0) {
			return nullptr;
		}
		Node<T>* next = head;
		for (int i = 0; i < index; i++) {
			next = next->nextNode;
		}
		return next;
	}
	
	void insertItem(T t, int index) 
	{
		Node<T>* node = new Node<T>();
		node->item = t;
		if (index > length) {
			return;
		}
		else if (index == 0) {
			addAtHead(t);
		}
		else if (index == length) {
			addAtTail(t);
		}
		else {
			Node<T>* next = getNode(index);
			next->prevNode->nextNode = node;
			node->prevNode = next->prevNode;
			next->prevNode = node;
			node->nextNode = next;
			length = length + 1;
		}
	}

	void removeNode(Node<T>* node) {
		if (node == head) {
			removeNode(0);
		}
		else if (node == tail) {
			removeNode(length - 1);
		}
		else {
			node->prevNode->nextNode = node->nextNode;
			node->nextNode->prevNode = node->prevNode;
			delete node;
			length = length - 1;
		}
	}

	void removeNode(int index) {
		if (index == 0) {
			head->nextNode->prevNode = nullptr;
			Node<T>* temp = head;
			head = head->nextNode;
			delete temp;
			length = length - 1;
		}
		else if (index == length - 1) {
			tail->prevNode->nextNode = nullptr;
			Node<T>* temp = tail;
			tail = tail->prevNode;
			delete tail;
			length = length - 1;
		}
		else if (!(index < 0 || index >= length)) {
			Node<T>* node = getNode(index);
			node->prevNode->nextNode = node->nextNode;
			node->nextNode->prevNode = node->prevNode;
			delete node;
			length = length - 1;
		}
	}

	void push(T t) {
		addAtHead(t);
	}

	void append(T t) {	
		addAtTail(t);
	}

	T pop() {
		if(length == 0){
			return NULL;
		}
		T item = head->item;
		removeNode(0);
		return item;
	}

};
	
	
