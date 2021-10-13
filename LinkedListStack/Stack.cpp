#include "Stack.h"

Stack::Stack(const Stack& stack)
{
	*this = stack;
}

Stack::~Stack()
{
	while (!Empty())
	{
		Pop();
	}
}

Stack& Stack::operator=(const Stack& stack)
{
	Stack temp;
	Element* iter = stack.endptr;
	while (iter != nullptr)
	{
		temp.Push(iter->data);
		iter = iter->prevptr;
	}

	while (!temp.Empty())
	{
		Push(temp.Pop());
	}

	return *this;
}

void Stack::Push(int val)
{
	Element* e = new Element(val, endptr);
	endptr = e;
}

int Stack::Pop()
{
	if (Empty())
	{
		return -1;
	}
	Element* e = endptr;
	const int data = e->data;
	endptr = e->prevptr;
	delete e;
	return data;
}

int Stack::Size() const
{
	if (Empty())
	{
		return 0;
	}
	return endptr->CountElements();
}

bool Stack::Empty() const
{
	return endptr == nullptr;
}

Stack::Element::Element(int val, Element* const ptr)
	:
	data(val),
	prevptr(ptr)
{
}

int Stack::Element::CountElements() const
{
	if (prevptr == nullptr)
	{
		return 1;
	}
	return prevptr->CountElements() + 1;
}
