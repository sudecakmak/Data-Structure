// Sude Çakmak
// 152120201044

#include "Deque.h"
#include <iostream>

Deque::Deque() {

	this->head = this->tail = NULL;
	this->noOfItems = 0;

}

Deque::~Deque() {

	this->tail = NULL;

	while (this->head != NULL) {

		DequeNode *dequeNode = this->head;
		this->head = this->head->next;
		delete dequeNode;
	}

	this->noOfItems = 0;
}


void Deque::AddFront(int item) {

	DequeNode *dequeNode = new DequeNode(item);

	if (this->head == NULL)
	{
		this->head = this->tail = dequeNode;
	}
	else
	{
		dequeNode->next = head;
		this->head->prev = dequeNode;
		this->head = dequeNode;
	}

	this->noOfItems++;
}

void Deque::AddRear(int item) {

	DequeNode *dequeNode = new DequeNode(item);

	if (this->tail == NULL)
	{
		this->head = this->tail = dequeNode;
	}
	else
	{
		dequeNode->prev = tail;
		this->tail->next = dequeNode;
		this->tail = dequeNode;
	}

	this->noOfItems++;
}

int Deque::RemoveFront() {

	if (this->head == NULL) throw std::exception("RemoveFront()::Empty deque");

	int front = this->head->item;
	DequeNode *dequeNode = this->head;

	this->head = this->head->next;

	if (this->head == NULL)
	{
		this->tail = NULL;
	}
	else
	{
		this->head->prev = NULL;
	}

	delete dequeNode;
	this->noOfItems = noOfItems - 1;

	return front;
}

int Deque::RemoveRear() {

	if (this->head == NULL) throw std::exception("RemoveRear()::Empty deque");

	int rear = this->tail->item;
	DequeNode *dequeNode = this->tail;

	this->tail = this->tail->prev;

	if (this->tail == NULL)
	{
		this->head = NULL;
	}
	else
	{
		this->tail->next = NULL;
	}

	delete dequeNode;
	this->noOfItems = noOfItems - 1;

	return rear;
}

int Deque::Front() {

	if (this->head == NULL)
	{
		throw std::exception("Front()::Empty deque");
	}

	return this->head->item;
}

int Deque::Rear() {

	if (this->head == NULL)
	{
		throw std::exception("Rear()::Empty deque");
	}

	return this->tail->item;
}
