/**************************************
* rollin' dice				  *
* this is an example of how to use	  *
* the dice class, with verbose output *
**************************************/


#include "./fraction.h"
#include <iostream>

using namespace std;
int main()
{
  int inNum, inDen;
  cout << "Input numerator 1:";
  cin >> inNum;
  cout << "Input denominator 1:";
  cin >> inDen;
	fraction f1(inNum,inDen);
  cout << "Input numerator 2:";
  cin >> inNum;
  cout << "Input denominator 2:";
  cin >> inDen;
  fraction f2(inNum,inDen);
  
  if(f1.largestCommonFactor()!=1||f2.largestCommonFactor()!=1)
  {
    cout << "reducing based on common factors" << endl;
    f1.reduceFraction();
    f2.reduceFraction();
    cout << "fractions are now " << f1.print() << " and " << f2.print() << endl;
  }
  fraction f3 = f1 + f2;
  fraction f4 = f1 - f2;
  fraction f5 = f1 * f2;
  fraction f6 = f1 / f2;
  
  cout << f1.print() << " + " << f2.print() << " = " << f3.print() << endl;
  cout << f1.print() << " - " << f2.print() << " = " << f4.print() << endl;
  cout << f1.print() << " * " << f2.print() << " = " << f5.print() << endl;
  cout << f1.print() << " / " << f2.print() << " = " << f6.print() << endl;
  
  return 0;
}