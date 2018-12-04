#pragma once
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;


class TCalculator
{
	string infix, postfix;
	TStack <char> Stop;
	TStack <double> Stnum;
	int Priority(const char m) const;
public:
	void ToPostfix();
	void SetInfix();
	string GetPostfix();
	double Calculator();
};

int TCalculator::Priority(const char m) const
{
	switch (m)
	{
	case '(':
		return 0;
	case  '+':
		return 1;
	case  '-':
		return 1;
	case  '*':
		return 2;
	case  '/':
		return 2;
	case  '^':
		return 3;
	default:throw m;
	}
}

void TCalculator::ToPostfix()///////////
{
	postfix = "";
	Stop.Clear();
	string tmp = "(" + infix + ")";
	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == '(')
			Stop.Push(tmp[i]);
		if (tmp[i] >= '0'&& tmp[i] <= '9')
			postfix += tmp[i];
		if (tmp[i] == ')')
		{
			while (Stop.Top() != '(')
				postfix += Stop.Pop();
			Stop.Pop();
		}
		if (tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*' || tmp[i] == '/' || tmp[i] == '^')
		{
			postfix += ' ';
			while (Priority(tmp[i]) <= Priority(Stop.Top()))
			{
				postfix += Stop.Pop();
			}
			Stop.Push(tmp[i]);
		}
	}
}

void TCalculator::SetInfix()
{
	infix.clear();//очищает строку, встроенная
	char symbol;
	while (true)
	{
		symbol = getchar();//считывает
		if (symbol == '\n')
			break;
		else
			infix += symbol;
	}

}

string TCalculator::GetPostfix()
{
	this->ToPostfix();//этот объект вызывает функцию
	return postfix;
}

double TCalculator::Calculator()
{
	double num1, num2, res;
	Stnum.Clear();//очищается стек с числами
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
		{
			num2 = Stnum.Pop();/////
			num1 = Stnum.Pop();
			switch (postfix[i])
			{
			case '+': res = num1 + num2;
				break;
			case '-': res = num1 - num2;
				break;
			case '*': res = num1 * num2;
				break;
			case '/': res = num1 / num2;
			}
			Stnum.Push(res);
		}
		if (postfix[i] >= '0' && postfix[i] <= '9')
		{
			char *p;
			double x;
			x = strtod(&postfix[i], &p);
			Stnum.Push(x);
			int lenght = p - &postfix[i];//длина числа
			i += lenght - 1;//перескакиваем с начала большого числа на конец
		}
	}
	return Stnum.Pop();
}
