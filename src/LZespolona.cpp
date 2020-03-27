#include "LZespolona.hh"
#include <cmath>
#include <iostream>

using namespace std;


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

 ostream& operator << (ostream& StrWyj, LZespolona liczba)
{
  StrWyj << "(" << liczba.re << showpos << liczba.im << "i)" << noshowpos;
  return StrWyj;
}

istream& operator >> (istream& StrWej, LZespolona& liczba)
{
	char tmp;

	StrWej >> tmp;
	if  (tmp != '(')
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> liczba.re;
	if (!StrWej)
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}
	
	StrWej >> liczba.im;
	if (!StrWej)
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> tmp;
	if  (tmp != 'i')
	{
        	StrWej.setstate(ios::failbit);
		return StrWej;
	}

	StrWej >> tmp;
	if  (tmp != ')')
	{
		StrWej.setstate(ios::failbit);
		return StrWej;
	}

	return StrWej;
}

void Wyswietl (LZespolona arg)
{
  cout<<"("<<arg.re<<showpos<<arg.im<<"i)"<<noshowpos;
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.im * Skl2.im + Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}

LZespolona sprzezenie(LZespolona Skl)
{
    Skl.im = - (Skl.im);
    return Skl;
}

double  modul (LZespolona Skl)
{
  double Wynik;

  Wynik = sqrt(pow(Skl.re, 2) + pow(Skl.im, 2));
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
   LZespolona Wynik;
   Wynik = operator * (Skl1, sprzezenie(Skl2));
   Wynik.re = Wynik.re / pow(modul(Skl2),2);
   Wynik.im = Wynik.im / pow(modul(Skl2),2);
   return Wynik;
}
bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re == Skl2.re && Skl1.im == Skl2.im)
    return true;
  else
    return false;
}

LZespolona Wczytaj()
{
    LZespolona liczba;
    char tmp;

    cin >> tmp;
    cin >> liczba.re;
    cin >> tmp;
    cin >> liczba.im;
    if(tmp=='-')
        liczba.im=liczba.im*(-1);
    cin >> tmp;
    cin >>tmp;
    return liczba;
}



