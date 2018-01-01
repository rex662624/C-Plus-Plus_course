#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
void turtle(int, int, int);
void print(void);
void dir(int command);
enum direction{w,d,s,a};   //wsad��ܤW�U���k;
const int size =20;
direction go = w;
int command,step;
unsigned char floor[size][size] ;
int y=0,x =0;
bool pen = false ; 

int main()
{
   for(int i = 0; i < size; i++)
   {
      for(int j = 0; j < size; j++)
      {
         floor[i][j] = '=';
      }
   }
   	 	cout << "�ж}�l��J���O: ";
   		cin >> command;
  

   while(command != 9)
   {

      if(command == 1)
      {
         pen = false;
         cout << "�z���U��" << endl;
      }
      else if(command == 2)
         {
            pen = true;
            cout << "�z�w�U��" << endl;
         }
 
      if(command == 3 || command == 4)
         dir(command);

      if(command == 5)
      {
         cout << "�п�J�Q�e�i���:" << endl;

         cin >> step;
 
         if(go ==d)
         {
            while((x + step) > 21)
            {
               cout << "�z�w�W�X�d��(20X20)�Э��s��J�B��" << endl;
               cin>> step;
            }
         }
         else if(go == w)
         {
            while((y +step) >21)
            {
               cout << "�z�w�W�X�d��(20X20)�Э��s��J�B��" << endl;
                cin>> step;
            }
         }
          else if(go == a)
         {
            while((x - step) <-1)
            {
               cout << "�z�w�W�X�d��(20X20)�Э��s��J�B��" << endl;
                cin>> step;
            }
         }
         else if(go == s)
         {
            while(( y- step) <-1)
            {
               cout << "�z�w�W�X�d��(20X20)�Э��s��J�B��"<< endl;
                cin>> step;

            }
         }
 		
         turtle(step, y, x);
         cout << "�z�ثe����m�b: " <<"["<< y << "�A" << x <<"]"<< endl;
      }

      if(command == 6)
         print();
 
      	cin >> command;

 
   }
   return 0;
}

 

void turtle(int f,int y, int x)
{
   if(go == d)
   {
      for(int i = y; i == y; i++)
      {
         for(int j = x; j < x + step; j++)
         {
            if(pen == true)
               floor[i][j] = '*';
            else
               floor[i][j] = '=';
         }
      }
      ::x += (f-1);
   }
 
   else if(go == s)
   {
      for(int i = y; i > y - step; i--)
      {
         for(int j = x; j == x; j++)
         {
  			if(pen == true)
               floor[i][j] = '*';
            else
               floor[i][j] = '=';
         }
      }
      ::y -= (f-1) ;
   }
   else if(go == a)
   {
      for(int i = y; i == y; i++)
      {
         for(int j = x; j > x - step; j--)
         {
  			if(pen == true)
               floor[i][j] = '*';
            else
               floor[i][j] = '=';
         }
      }
      ::x-=(f-1) ;
   }
   else if(go == w)
   {
      for(int i = y; i< y +step; i++)
      {
         for(int j = x; j == x; j++)
         {
  			if(pen == true)
               floor[i][j] = '*';
            else
               floor[i][j] = '=';
         }
      }
      ::y += (f-1) ;
   }
}

void print()
{
   	for(int i = 0; i < 20; i++)
   	{
      for(int j = 0; j < 20; j++)
      {
         cout << floor[i][j];
      }
      cout << endl;
   	}
}

void dir(int command)
{
   if(go == d)
   {
      if(command == 3)
      {
		go=s;
         cout << "�z�{�b����V���U��"  << endl;
      }
      else
         if(command == 4)
         {
         	go=w;
         cout << "�z�{�b����V���W��" << endl;
         }
   }
   else if(go == s)
   {
      if(command == 3)
      {
		go=a;
        cout << "�z�{�b����V������ " << endl;
      }
      else
         if(command == 4)
         {
        go = d;
      	cout << "�z�{�b����V���k�� " << endl;
         }
   }
   else if(go == a)
   {
      if(command == 3)
      {
      	go=w;
        cout << "�z�{�b����V���W�� " << endl;
      }
      else
         if(command == 4)
         {
		go=s;
        cout <<"�z�{�b����V���U�� " << endl;
         }
   }
   else if(go == w)
   {
      if(command == 3)
      {
		go=d;
        cout << "�z�{�b����V���k�� "  << endl;
      }
      else
         if(command == 4)
         {
		go=a;
        cout <<"�z�{�b����V������ "  << endl;
         }
   }
}
