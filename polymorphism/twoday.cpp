#include "TwoDayPackage.h" 

	TwoDayPackage::TwoDayPackage( const string &sName,const string &sAddress, const string &sCity, const string &sState,
	int sZIP, const string &rName, const string &rAddress,const string &rCity, const string &rState, int rZIP,double w, double cost, double fee )
	: Package( sName, sAddress, sCity, sState, sZIP,rName, rAddress, rCity, rState, rZIP, w, cost )
	{
	setFee( fee );
	} 

	void TwoDayPackage::setFee( double fee )
	{
		if(fee<0)
		{
			Fee=0;
		}
		else
		{
			Fee=fee;
		}
	} 

	double TwoDayPackage::getFee() const
	{
	return Fee;
	}
	
	double TwoDayPackage::calculateCost() const
	{
	return Package::calculateCost() + getFee();
	}

