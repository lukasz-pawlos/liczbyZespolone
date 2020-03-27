#include <iostream>
#include "BazaTestu.hh"
#include "Statystyka.hh"

using namespace std;




int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }



  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Odpowiedz, Wynik;
  Staty Ocena;

  inicjuj_statystyki(Ocena);

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cin.clear();
    cout << " Pytanie: ";
    WyswietlWyr(WyrZ_PytanieTestowe);
    cout << " Podaj odpowiedz: ";
    cin >> Odpowiedz;
    int i=0;
    while (i<3/*cin.fail()*/)
      {
	cin.clear();
	cin.ignore(10000, '\n');
	cerr << "Zly format. Sprobuj jeszcze raz: " <<endl;
	i++;
	cout <<i<<endl;
	cin >> Odpowiedz;
	}
    Wynik=Oblicz (WyrZ_PytanieTestowe);
    if(Wynik==Odpowiedz)
      {
	cout << "Poprawna Odpowiedz"<<endl;
	dodaj_dobra(Ocena);
      }
    else
      {
	cout <<"ZLA ODPOWIEDZ"<<endl<<" Poprawny wynik to: "<<Wynik<<endl;
	dodaj_zla(Ocena);
      }
  }


  cout << endl;
  cout << " Koniec testu" << endl;
  Statystyki(Ocena);
  cout << endl;
}
