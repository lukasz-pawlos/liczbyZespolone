#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

ostream& operator << (ostream& StrWyj, WyrazenieZesp wyr);
Operator WczytajSymbol();
void WyswietlSymbol (Operator operatort);
void WyswietlWyr(WyrazenieZesp  WyrZ);
LZespolona Oblicz(WyrazenieZesp  WyrZ);
WyrazenieZesp WczytajWyr ();
char ZwrocSymbol (Operator operatort);
Operator WczytajSymbol (char operatort);
istream& operator >> (istream& StrWej, WyrazenieZesp& wyr);

#endif
