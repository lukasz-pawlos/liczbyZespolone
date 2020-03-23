#include "Statystyka.hh"



double inicjuj_statystyke(Staty TEST)
{
  TEST.odp_dobra=0;
  TEST.odp_zla=0;
}

double dodaj_dobra(Staty TEST)
{
  TEST.odp_dobra++;
}

double dodaj_zla(Staty TEST)
{
  TEST.odp_zla++;
}

void Wyswiet(Staty TEST)
{
  double Wynik;
  Wynik=(TEST.odp_dobra/(TEST.odp_dobra+TEST.odp_zla))*100;
  cout << "Liczba poprawnych odpowiedzi: " << TEST.odp_dobra << endl;
  cout << "Liczba zlych odpowiedzi: " << TEST.odp_zla << endl;
  cout << "Wynik procentowy: " << Wynik << "%" << endl;	 
}
