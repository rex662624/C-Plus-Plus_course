#ifndef _RATIONAL_H_
#define _RATIONAL_H_
class Rational
{
public:
	Rational(int, int);
	Rational add(const Rational &);
	Rational sub(const Rational &); 
	Rational mult(const Rational &); 
	Rational divide(const Rational &);
	void print();
	void printFloat();
	int *reduce(int,int);
private:
	int num;
	int den;
		
};
 
#endif
