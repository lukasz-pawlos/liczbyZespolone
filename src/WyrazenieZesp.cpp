#include "WyrazenieZesp.hh"
#include <cmath>

using namespace std;

/*
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

LZespolona Oblicz (WyrazenieZesp WyrZ)
{
  LZespolona B;
  switch (WyrZ.Op)
    {
    case Op_Dodaj:
      B = operator + (WyrZ.Arg1, WyrZ.Arg2);
      break;

    case Op_Odejmij:
      B = operator - (WyrZ.Arg1, WyrZ.Arg2);
      break;
      
    case Op_Mnoz:
      B = operator * (WyrZ.Arg1, WyrZ.Arg2);
      break;

    case Op_Dziel:
      B = operator / (WyrZ.Arg1, WyrZ.Arg2);
      break;
    }
  return B;
}

char ZwrocSymbol (Operator operatort)
{
  char B;
  switch (operatort)
    {
    case Op_Dodaj:
      B = '+';
      break;
      
    case Op_Odejmij:
      B = '-';
      break;
      
    case Op_Mnoz:
      B = '*';
      break;
      
    case Op_Dziel:
      B = '/';
      break;
      
    }
  return B;
}

Operator WczytajSymbol(char operatort)
{
  Operator oper;
  switch (operatort)
  {
     case '+':
      oper=Op_Dodaj;
      break;
      
    case '-':
      oper=Op_Odejmij;
      break;
      
    case '*':
      oper=Op_Mnoz;
      break;
      
    case '/':
      oper=Op_Dziel;
  }
  return oper;
}

ostream& operator << (ostream& StrWyj, WyrazenieZesp wyr)
{
  StrWyj << wyr.Arg1;
  StrWyj << ZwrocSymbol (wyr.Op);
  StrWyj << wyr.Arg2 << endl;
  return StrWyj;
}

istream& operator >>(istream& StrWej, WyrazenieZesp wyr)
{
  char znak;
  StrWej >> wyr.Arg1;
  StrWej >> znak;
  wyr.Op = WczytajSymbol(znak);
  StrWej >> wyr.Arg2;
  return StrWej;
}


////////////////////////////////////

void WyswietlSymbol(Operator operatort)
{
  switch(operatort)
    {
    case Op_Dodaj:
      cout << "+";
      break;

    case Op_Odejmij:
      cout << "-";
      break;

    case Op_Mnoz:
      cout << "*";
      break;

    case Op_Dziel:
      cout << "/";
      break;
    }
}

Operator WczytajSymbol ()
{
  Operator oper;
  char operatort;
  cin >> operatort;
  switch (operatort)
    {
    case '+':
      oper=Op_Dodaj;
      break;
      
    case '-':
      oper=Op_Odejmij;
      break;
      
    case '*':
      oper=Op_Mnoz;
      break;
      
    case '/':
      oper=Op_Dziel;
    }
  return oper;
}


//Funkcja uzywa funkcji z biblioteki LZespolona

void WyswietlWyr(WyrazenieZesp  WyrZ)
{
  Wyswietl(WyrZ.Arg1);
  WyswietlSymbol(WyrZ.Op);
  Wyswietl(WyrZ.Arg2);
  cout << ""<<endl;
}

WyrazenieZesp Wczytajwyr()
{
  LZespolona A,B;
  WyrazenieZesp Z;
  A=Wczytaj();
  Operator oper = WczytajSymbol ();
  B=Wczytaj();
  Z.Arg1=A;
  Z.Arg2=B;
  Z.Op=oper;
  return Z;
}
