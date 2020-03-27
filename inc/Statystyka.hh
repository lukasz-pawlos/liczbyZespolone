//#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

using namespace std;

struct Staty
{
  double odp_dobra;
  double odp_zla;
};

Staty inicjuj_statystyki(Staty &TEST);
Staty dodaj_dobra(Staty &TEST);
Staty dodaj_zla(Staty &TEST);
void Statystyki(Staty &TEST);
