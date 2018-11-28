#include <iostream>
#include "Stack.h"
#include "Calculator.h"
using namespace std;



void main()
{
	TCalculator a;

	a.SetInfix();
	cout<<a.GetPostfix();



	system("pause");
}
