#include "my_class.h"

My_class::My_class(int a, float b)
{
	this->a = a;
	this->b = b;
}

void My_class::Out()
{
	cout << a << " " << b << "\n";
}

My_class My_class::operator=(My_class& T)
{
	a = T.a;
	b = T.b;
	return *this;
}
