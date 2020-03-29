#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>

using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


ostream& operator << (ostream& StrWyj, LZespolona liczba);
void Wyswietl (LZespolona arg);
LZespolona sprzezenie(LZespolona Skl);
double modul (LZespolona Skl);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
bool  operator == (LZespolona Skl1,  LZespolona  Skl2);
bool operator != (LZespolona Skl1, LZespolona Skl2);
LZespolona Wczytaj();
istream& operator >> (istream& StrWej, LZespolona& liczba);



#endif
