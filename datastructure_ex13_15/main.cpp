#include <iostream>
#include <iomanip>
#include <vector>
#include<string> 
#include "Package.h" // Package class definition
#include "TwoDayPackage.h" // TwoDayPackage class definition
#include "OvernightPackage.h" // OvernightPackage class definition
#include "List.h"


using namespace std;



int main()
{
   // create vector packages
       	
	

   Package *Packageptr = new Package( "Lou Brown", "1 Main St", "Boston", "MA", 
      11111, "Mary Smith", "7 Elm St", "New York", "NY", 22222, 8.5, .5 );
   Package *Packageptr2 = new TwoDayPackage( "Lisa Klein", "5 Broadway", 
      "Somerville", "MA", 33333, "Bob George", "21 Pine Rd", "Cambridge", 
      "MA", 44444, 10.5, .65, 2.0 );
   Package *Packageptr3 = new OvernightPackage( "Ed Lewis", "2 Oak St", "Boston",
      "MA", 55555, "Don Kelly", "9 Main St", "Denver", "CO", 66666, 
      12.25, .7, .25 );
    

	
	List<Package*> PackageList;
	PackageList.insertAtBack(Packageptr);
	PackageList.insertAtBack(Packageptr2);
	PackageList.insertAtBack(Packageptr3);
	

	PackageList.print();
		
		

} // end main



