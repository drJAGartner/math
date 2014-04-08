/*******************************
 * fraction.cc                 *
 * A mathematical point object *
 * v1.0 - April 2, 2014        *
 ******************************/

#include "./fraction.h"
#include <iostream>

fraction::fraction()
:nNum(0), nDen(1), bBadFrac(false)
{
  cout << "New Fraction defaults to zero" << endl;
}

fraction::fraction(int num, int den)
:nNum(num), nDen(den), bBadFrac(false)
{
  if(nDen==0)
  {
    bBadFrac = true;
    cout << "This Fraction is set with a denominator of 0, and is not valid" <<endl;
  }
  if(nDen<0)
  {
    nNum *= -1;
    nDen *= -1;
  }
}

fraction::fraction(int wholeNum)
:nNum(wholeNum), nDen(1)
{ }

fraction& fraction::operator=(const fraction &rhs)
{
  this->nNum = rhs.nNum;
  this->nDen = rhs.nDen;
  this->bBadFrac = rhs.bBadFrac;
  return *this;
}

fraction& fraction::operator=(const int &rhs)
{
  this->nNum = rhs;
  this->nDen = 1;
  this->bBadFrac = false;
  return *this;
}

fraction fraction::operator+(const fraction &rhs)
{
  if(this->bBadFrac||rhs.bBadFrac)
  {
    return fraction(1,0);           // don't bother processing garbage
  }
  
  fraction retFrac(nNum*rhs.nDen + nDen*rhs.nNum, nDen*rhs.nDen);
  retFrac.reduceFraction();
  return retFrac;
}

fraction fraction::operator-(const fraction &rhs)
{
  if(this->bBadFrac||rhs.bBadFrac)
  {
    return fraction(1,0);           // don't bother processing garbage
  }
  
  fraction retFrac(nNum*rhs.nDen - nDen*rhs.nNum, nDen*rhs.nDen);
  retFrac.reduceFraction();
  return retFrac;
}

fraction fraction::operator*(const fraction &rhs)
{
  if(this->bBadFrac||rhs.bBadFrac)
  {
    return fraction(1,0);           // don't bother processing garbage
  }
  
  fraction retFrac(nNum*rhs.nNum, nDen*rhs.nDen);
  retFrac.reduceFraction();
  return retFrac;
}

fraction fraction::operator/(const fraction &rhs)
{
  if(this->bBadFrac||rhs.bBadFrac)
  {
    return fraction(1,0);           // don't bother processing garbage
  }
  
  fraction retFrac(nNum*rhs.nDen, nDen*rhs.nNum);
  retFrac.reduceFraction();
  return retFrac;
}

fraction fraction::operator+(const int &rhs)
{
  if(this->bBadFrac)
  {
    return fraction(1,0);           // don't bother processing garbage
  }
  
  fraction retFrac(nNum + nDen*rhs, nDen);
  retFrac.reduceFraction();
  return retFrac;
}

fraction fraction::operator-(const int &rhs)
{
  if(this->bBadFrac)
  {
    return fraction(1,0);           // don't bother processing garbage
  }
  
  fraction retFrac(nNum - nDen*rhs, nDen);
  retFrac.reduceFraction();
  return retFrac;
}

fraction fraction::operator*(const int &rhs)
{
  if(this->bBadFrac)
  {
    return fraction(1,0);           // don't bother processing garbage
  }
  
  fraction retFrac(nNum*rhs, nDen);
  retFrac.reduceFraction();
  return retFrac;
}

fraction fraction::operator/(const int &rhs)
{
  if(this->bBadFrac)
  {
    return fraction(1,0);           // don't bother processing garbage
  }
  
  fraction retFrac(nNum, nDen*rhs);
  retFrac.reduceFraction();
  return retFrac;
}


string fraction::print(bool bNatural)
{
  if(bBadFrac) return "Inf.";
  if(nNum==0) return "0";
  
  string strOut = to_string(nNum) + string("/") + to_string(nDen);
  if(nDen==1) strOut = to_string(nNum);
  if(bNatural)
  {
    strOut = to_string((1.*nNum)/(nDen));
  }
  return strOut;
}

void fraction::reduceFraction()
{
  int lcf = this->largestCommonFactor();
  while(lcf>1)
  {
    this->nNum/=lcf;
    this->nDen/=lcf;
    lcf = this->largestCommonFactor();
  }
}

int fraction::largestCommonFactor()
{
  
  bool bigNum = false;
  int nSmall = this->nNum;
  int nBig = this->nDen;
  if(nSmall<nBig)
  {
    bigNum = true;
    nSmall = this->nDen;
    nBig = this->nNum;
  }
  int nRet = nSmall;
  for( ; nRet>1; nRet--)
  {
    if((nBig%nRet==0)&&(nSmall%nRet==0)) return nRet;
    
  }
  return 1;
}