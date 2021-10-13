#include "Stack.h"

Stack::Stack()
{
}

Stack::Stack(const Stack& stack)
{
	*this = stack;
}

Stack::~Stack()
{
	while (endptr != nullptr)
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
	if (endptr == nullptr)
	{
		return -1;
	}
	Element* e = endptr;
	int data = endptr->data;
	endptr = e->prevptr;
	delete e;
	return data;
}

int Stack::Size() const
{
	if (endptr == nullptr)
	{
		return 0;
	}
	int count = 1;
	Element* iter = endptr;
	while (iter->prevptr != nullptr)
	{
		iter = iter->prevptr;
		count++;
	}
	return count;
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
