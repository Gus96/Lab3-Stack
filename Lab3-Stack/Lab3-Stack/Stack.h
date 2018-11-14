#pragma once
template <class T>
class TStack
{
	int MaxSize;
	int Size;
	T *mas;
public:
	TStack(const int MS = 10);
	TStack(const TStack <T> &tmp);
	~TStack();

};
template <class T>
TStack <T>:: TStack (const int MS)
{
	MaxSize = MS;
	mas = new T[MaxSize];
	Size = 0;
}
template <class T>
TStack <T>::TStack(const TStack <T> &tmp )
{
	MaxSize = tmp.MaxSize;
	Size = tmp.MaxSize;
	mas new T[MaxSize];
	for (int = 0; i < Size; i++)
		mas[i] = tmp.mas[i];
}
template <class T>
TStack <T> ::~TStack() 
{
	delete[] mas;
}