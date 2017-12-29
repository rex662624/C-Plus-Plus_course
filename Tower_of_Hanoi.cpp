#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
void move(int,int,int,int);

int main(int argc, char** argv) 
{
	
	int n;
	cout<<"¿é¤J¶ê½L¼Æ:";
	cin>>n;
	cout<<endl;
	move(n,1,3,2);

system("pause");
return 0;
}
void move(int n,int n1,int n3,int n2) 
{
	if(n==1)
	{
		
		cout<<"move disk from "<<n1<<" to  "<<n3<<endl;

		
	}	
	
	else
	{
		move(n-1,n1,n2,n3);
		move(1,n1,n3,n2);
		move(n-1,n2,n3,n1);
	}
}
