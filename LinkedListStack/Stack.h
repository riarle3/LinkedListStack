#pragma once

class Stack
{
private:
	class Element
	{
	public:
		Element(int val, Element* const ptr)
			:
			data(val),
			prevptr(ptr)
		{
		}
		Element(const Element& src)
			:
			data(src.data)
		{
			if (src.prevptr != nullptr)
			{
				prevptr = new Element(*src.prevptr);
			}
			else
			{
				prevptr = nullptr;
			}
		}
		int CountElements() const
		{
			if (prevptr == nullptr)
			{
				return 1;
			}
			return prevptr->CountElements() + 1;
		}
		Element* prevptr;
		int data;
	};
public:
	class Iterator
	{
	public:
		Iterator() = default;
		Iterator(Element* pEle)
			:
			pElement(pEle)
		{}
		Iterator& operator++()
		{
			pElement = pElement->prevptr;
			return *this;
		}
		int& operator*() const
		{
			return pElement->data;
		}
		bool operator!=(Iterator rhs) const
		{
			return pElement != rhs.pElement;
		}
	private:
		Element* pElement = nullptr;
	};
	class ConstIterator
	{
	public:
		ConstIterator() = default;
		ConstIterator(const Element* pEle)
			:
			pElement(pEle)
		{}
		ConstIterator& operator++()
		{
			pElement = pElement->prevptr;
			return *this;
		}
		const int& operator*() const
		{
			return pElement->data;
		}
		bool operator!=(ConstIterator rhs) const
		{
			return pElement != rhs.pElement;
		}
	private:
		const Element* pElement = nullptr;
	};
public:
	Stack() = default;
	Stack(const Stack& stack)
	{
		*this = stack;
	}
	~Stack()
	{
		Clear();
	}
	Stack& operator=(const Stack& stack)
	{
		if (&stack != this)
		{
			Clear();
			if (!stack.Empty())
			{
				endptr = new Element(*stack.endptr);
			}
		}
		return *this;
	}
	void Push( int val )
	{
		Element* e = new Element(val, endptr);
		endptr = e;
	}
	int Pop()
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
	int Peek()
	{
		if (Empty())
		{
			return -1;
		}
		return endptr->data;
	}
	int Size() const
	{
		if (Empty())
		{
			return 0;
		}
		return endptr->CountElements();
	}
	bool Empty() const
	{
		return endptr == nullptr;
	}
	void Clear()
	{
		while (!Empty())
		{
			Pop();
		}
	}
	Iterator begin()
	{
		return{ endptr };
	}
	Iterator end()
	{
		return { };
	}
	ConstIterator begin() const
	{
		return { endptr };

	}
	ConstIterator end() const
	{
		return { };

	}
private:
	Element* endptr = nullptr;
};