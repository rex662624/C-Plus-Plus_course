
#ifndef TIME_H
#define TIME_H
class Time
{
	public:
	Time( int = 0,int=0,int=0 ); 
 
	int getHour() const; 
	int getMinute() const; 
	int getSecond() const; 
 
	Time &setTime( int, int, int );
	Time &setHour( int ); 
	Time &setMinute( int ); 
	Time &setSecond( int );

	void printUniversal() const; 
	void printStandard() const; 

	private:
	int totalSeconds;
}; 
#endif



