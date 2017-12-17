#include <iostream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
enum Direction {d,r,u,l };
void mazeTraverse( char [][ 12 ],int,int,int, int, int );
void print( const char[][ 12 ] );
bool edge( int, int );


int main(int argc, char** argv) 
{
	char maze[ 12 ][ 12 ] =
 { 
 	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
	{'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
	{'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
	{'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
	{'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
	{'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
	{'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
	{'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
	{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
	{'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
	{'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
	{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} 
 };
 	int x0=2;
 	int y0=0;
 	int x=2;
 	int y=0;
 	mazeTraverse( maze,x0,y0,x, y,r );
 	return 0;
}	

void mazeTraverse( char maze[][ 12 ], const int x0, const int y0,int x, int y, int direction )
{
	static int a= 0; 
 	maze[ x ][ y ] = 'X';
	print( maze );
	
	if (  x != x0 && y != y0 && edge( x, y )  )
	{
		cout << "您已達終點";
		return; 
	} 
 else if (a==1&&  x == x0 && y == y0  )
 	{
 		cout << "您回到了起點";
 		return;
 	} 
 else
 {
 a = 1;

	for (; ;direction++,direction %= 4)
{
	switch( direction )
	{
		case d:
			if (x+1>-1 && x+1 <12 && y >-1 && y <12 && maze[ x+1 ][ y ] != '#')
			{
				mazeTraverse(maze,x0,y0,x+1,y,l);
				return;
			} 
			break;
		
		case r:
			if (x >-1 && x <12 && y+1 >-1 && y+1 <12 && maze[ x ][ y+1 ] != '#')
			{
				mazeTraverse(maze,x0,y0,x,y+1,d);
				return;
			} 
			break;
			
		case u: 
			if (x-1 >-1 && x-1 <12 && y >-1 && y <12 && maze[ x-1 ][ y ] != '#')
			{
				mazeTraverse(maze,x0,y0,x-1,y,r);
			return;
			} 
			break;
			
		case l:
			if (x >-1 && x <12 && y-1 >-1 && y-1<12 && maze[ x ][ y-1 ] != '#')
			{
				mazeTraverse(maze,x0,y0,x,y-1,u);
			return;
			}
			break;
	}
}
}
} 

void print( const char maze[][ 12 ] )
 {
 	for ( int x = 0; x < 12; x++ )
 {
 	for ( int y = 0; y < 12; y++ )
	{
	cout << maze[ x ][ y ] << ' ';
	}
	cout<<endl;
  } 

 	cout << "輸入任意鍵看下一動"<<endl;
	cin.get();
 } 
 
 bool edge( int x, int y )
 {
 if ( ( x == 0 || x == 11 ) && ( y >= 0 && y <= 11 ) )
 	{
	 return 1;
	}
 else if ( ( y == 0 || y == 11 ) && ( x >= 0 && x <= 11 ) )
	{
 	 return 1;
 	}
 else
 	return 0;
 } 
