#include "rational.h"
#include <iostream>
using namespace std;

int main() {
	cout<<"�п�J����� �ΪŮ�j�}�Ʀr(�Ҧp 1/2 �M5/8 �п�J1 2 5 8)" <<endl;
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	Rational r1(a,b);
	r1.print();
	r1.printFloat();
	cout << "---------------------------------" <<endl;
 
	Rational r2(c,d);
	r2.print();
	r2.printFloat();
	cout << "---------------------------------" <<endl;
 
	cout <<"The addition is: " << endl;
	Rational ans = r1.add(r2);
	ans.print();
	ans.printFloat();
	cout << "---------------------------------" <<endl;
 
	cout <<"The subtraction is: " << endl;
	ans = r1.sub(r2);
	ans.print();
	ans.printFloat();
	cout << "---------------------------------" <<endl;
 
	cout <<"The multiplication is: " <<endl;
	ans = r1.mult(r2);
	ans.print();
	ans.printFloat();
	cout << "---------------------------------" <<endl;
 
	cout <<"The division is: " << endl;
	ans = r1.divide(r2);
	ans.print();
	ans.printFloat();
	cout << "---------------------------------" <<endl;
	
	
	system("pause");
	return 0;
}
