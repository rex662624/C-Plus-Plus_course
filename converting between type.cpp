#include <iostream>

using namespace std;

class Cents
{
	friend ostream &operator<<( ostream &, const Cents & );
public:
    Cents(int nCents=0)
    {
        SetCents(nCents);
    }
 
    // Overloaded int cast
    operator int() { return m_nCents; }
    
    int GetCents() { return m_nCents; }
    void SetCents(int nCents) { m_nCents = nCents; }

private:
    int m_nCents;
};

class Dollars
{
	friend ostream &operator<<( ostream &, const Dollars & );
//	friend istream &operator>>( istream &, String & );
public:
     Dollars(int nDollars=0)
     { 
         m_nDollars = nDollars;
     }
     // Allow us to convert Dollars into Cents
     operator Cents() 
	 { 
	  return Cents(m_nDollars * 100);
	 }

private:
    int m_nDollars;
};
ostream &operator<<( ostream &output, const Dollars &d )
{
 output << d.m_nDollars;
 return output; // enables cascading
} // end function operator<<

ostream &operator<<( ostream &output, const Cents &c )
{
 output << c.m_nCents;
 return output; // enables cascading
} // end function operator<<

int main()
{
    Cents cCents(700); 
	int allCents;
    allCents = static_cast<int>(cCents);
    Dollars nDollars(20); 
	cCents = static_cast<Cents>(nDollars); // converting to Cents 
    cout << allCents << '\n' << nDollars << " dollars is convert to " << cCents << " cents" << endl; // cDollars will be cast to a Cents
 
    return 0;
}

