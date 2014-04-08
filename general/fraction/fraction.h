// object to describe a mathematical point

#ifndef FRACTION_H
#define FRACTION_H
#include <math.h>
#include <string>

using namespace std;

class fraction
{
public:
  fraction();
	fraction(int num, int den);
  fraction(int wholeNum);
	~fraction() {}
	
  fraction& operator=(const fraction &rhs);
  fraction& operator=(const int &rhs);
  
  fraction operator+(const fraction &rhs);
  fraction operator-(const fraction &rhs);
  fraction operator*(const fraction &rhs);
  fraction operator/(const fraction &rhs);

  fraction operator+(const int &rhs);
  fraction operator-(const int &rhs);
  fraction operator*(const int &rhs);
  fraction operator/(const int &rhs);
  
  
	int getNum() {return nNum;}
	int getDen() {return nDen;}
  float getFloat() {return (1.*nNum)/nDen;}
  string print(bool bNatural=false);
  bool validFraction() {return bBadFrac;}
	void reduceFraction();
  int largestCommonFactor();
  
private:
	int nNum;
	int nDen;
  bool bBadFrac;
};
#endif