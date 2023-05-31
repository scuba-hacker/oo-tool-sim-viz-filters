/************************************************************************************** * HEADER FILE: iadditionalmath.c++ * PURPOSE		: define functions specified in iadditionalmath.h **************************************************************************************/#include "iadditionalmath.h"double log2(const double value)											// return log to base 2 of value{	return log(value)/log(2); }double logx(const double value, const double x)			// return log to base x of value{	return log(value)/log(x); }double asinh(const double x)												// return arc-hyperbolic sine of x{	return log(x+sqrt(1+pow(x,2)));	}									// Got from SMP Formula Bookdouble acosh(const double x)												// return arc-hyperbolic cosine of x{ return log(x+sqrt(pow(x,2)-1));	}									// Got from SMP Formula Bookdouble atanh(const double x)												// return arc-hyperbolic tangent of x{ return 0.5*log((1+x)/(1-x)); }										// Got from SMP Formula Bookint factorial(const int x)													// return factorial of x{	int factorial=1;	for (int counter=x; counter>1; counter--)		factorial *= counter;	return factorial;}