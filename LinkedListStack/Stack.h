#pragma once

class Stack
{
private:
	class Element
	{
	public:
		Element(int val, Element* const ptr);
		int CountElements() const;
		Element* prevptr;
		int data;
	};
public:
	Stack();
	Stack(const Stack& stack);
	~Stack();
	Stack& operator=(const Stack& stack);
	void Push( int val );
	int Pop();
	int Size() const;
	bool Empty() const;
private:
	Element* endptr = nullptr;
};