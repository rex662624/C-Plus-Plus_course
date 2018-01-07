#include <iostream>
#include <iomanip>
#include "Time.h"
using namespace std ;


Time::Time( int hr, int min, int sec )
{
 
 	setTime( hr, min, sec );
} 


Time &Time::setTime( int h, int m, int s ) 
{
 	
 	setHour( h );
 	setMinute( m );
 	setSecond( s );
	return *this; 
} 
Time &Time::setHour( int h ) 
{
 	int hours = ( h >= 0 && h < 24 ) ? h : 0;
 	totalSeconds = ( hours * 3600 ) + ( getMinute() * 60 ) + getSecond();
	return *this; 
}
Time &Time::setMinute( int m ) 
{
	int minutes = ( m >= 0 && m < 60 ) ? m : 0; 
	totalSeconds = ( getHour() * 3600 ) + ( minutes * 60 ) + getSecond();
	return *this; 
 }
Time &Time::setSecond( int s )
 {
	int seconds = ( s >= 0 && s < 60 ) ? s : 0;
	totalSeconds = ( getHour() * 3600 ) + ( getMinute() * 60 ) + seconds;
	return *this;
 } 


 int Time::getHour() const
 {
	return ( totalSeconds- (totalSeconds% 3600) )/3600;
 } 


int Time::getMinute() const
 {
 return ( totalSeconds% 3600- totalSeconds % 60)/60;
 } 


int Time::getSecond() const
{
return totalSeconds % 60;
} 


void Time::printUniversal() const
{
cout << setfill( '0' ) << setw( 2 ) <<getHour() << ":"
<< setw( 2 ) << getMinute() << ":" << setw( 2 ) << getSecond();
}

void Time::printStandard() const
{
	int hour = getHour();
cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 )
<< ":" << setfill( '0' ) << setw( 2 ) <<getMinute()
<< ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM" : " PM" );
} 
