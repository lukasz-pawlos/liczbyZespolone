#include "Statystyka.hh"
#include <iostream>


Staty inicjuj_statystyki(Staty &TEST)
{
  TEST.odp_dobra=0;
  TEST.odp_zla=0;
  return TEST;
}

Staty dodaj_dobra(Staty &TEST)
{
  ++TEST.odp_dobra;
  return TEST;
}

Staty dodaj_zla(Staty &TEST)
{
  ++TEST.odp_zla;
  return TEST;
}

void Statystyki(Staty &TEST)
{
  double Wynik;
  Wynik=(TEST.odp_dobra/(TEST.odp_dobra+TEST.odp_zla))*100;
  cout << "Liczba poprawnych odpowiedzi: " << TEST.odp_dobra << endl;
  cout << "Liczba zlych odpowiedzi: " << TEST.odp_zla << endl;
  cout << "Wynik procentowy: " << Wynik << "%" << endl;	 
}
