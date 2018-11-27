#pragma once
template <class T>
class TStack
{
	int MaxSize;
	int Size;
	T *Stack;
public:
	TStack(const int MS = 10);
	TStack(const TStack <T> &tmp);
	~TStack();
	TStack& operator= (const TStack &tmp);
	void Push(const int elem);
	T Pop();
	T Top() const;
	bool IsEmpty() const;
	bool IsFull() const;
	void Clear();

};
template <class T>
TStack <T>:: TStack (const int MS)
{
	MaxSize = MS;
	Stack = new T[MaxSize];
	Size = 0;
}
template <class T>
TStack <T>::TStack(const TStack <T> &tmp )
{
	MaxSize = tmp.MaxSize;
	Size = tmp.MaxSize;
	Stack new T[MaxSize];
	for (int = 0; i < Size; i++)
		mas[i] = tmp.mas[i];
}
template <class T>
TStack <T> ::~TStack() 
{
	delete[] Stack;
}

template <class T>
TStack <T> &TStack <T> ::operator= (const TStack &tmp)
{
	if (MaxSize != tmp.MaxSize)
	{
		delete[] Stack;
		Stack = new T[tmp.MaxSize];
	}
	MaxSize = tmp.MaxSize;
	Size = tmp.Size;
	for (int i = 0; i < Size; i++)
		Stack[i] = tmp.Stack[i];
	return *this;
}
template <class T>
void TStack<T> ::Push(const int elem)
{
	if (MaxSize == Size)
		throw "Stack is full";
	else
	{
		Stack[Size] = elem;
		Size++;
	}
}

template <class T>
T TStack <T>::Pop()
{
	if (Size == 0)
		throw "Stack is empty";
	else
	{
		Size--;
		return Stack[Size];
	}
}

template <class T>
T TStack<T>:: Top() const
{
	if (Size == 0)
		throw -1;
	else
		return Stack[Size - 1];
}

template <class T>
bool TStack <T>::IsEmpty() const 
{
	return (Size == 0);
}

template <class T>
bool TStack <T>::IsFull() const
{
	return (Size == MaxSize);
}

template <class T>
void TStack <T>::Clear()
{
	while (!(this->IsEmpty()))
		this->Pop();
}