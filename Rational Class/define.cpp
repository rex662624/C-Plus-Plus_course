#include "rational.h"
#include <iostream>
#include <iomanip>
using namespace std;

int *Rational::reduce(int num,int denom)
{
     int a = num, b = denom, c; 
	 int* ans = new int[2];
      while ( a != 0 ) {
         c = a; a = b%a;  b = c;
      }
      ans[0]= num/b; 
	  ans[1]= denom/b;
	  return ans;

}

Rational::Rational(int a, int b)
{
	int *reduced = reduce(a,b);
	num = reduced[0];
	den = reduced[1];
}
/*-----------*/
Rational Rational::add(const Rational & r2)
{ 
	int a = (num * r2.den) + (r2.num * den);
	int b = den * r2.den;
	Rational final(a,b);
	return final;
}
Rational Rational::sub(const Rational & r2)
{
	int a = (num * r2.den) - (r2.num * den);
	int b = den * r2.den;
	Rational final(a,b);
	return final;
 
}
Rational Rational::mult(const Rational & r2)
{
	int a= (num * r2.num);
	int b = den * r2.den;
	Rational final(a,b);	
	return final;
}
    
Rational Rational::divide(const Rational & r2)
{
	int a = num * r2.den;
	int b = den * r2.num;
	Rational final(a,b);
	return final;

}
/*-------------*/
void Rational::print()
{
	cout<< num<<"/" << den << endl;
}
    
void Rational::printFloat()
{
	double n = (double) num/den;
	cout<<fixed<<setprecision(3) <<n<< endl;
}

