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
    cout << " Pytanie: ";
    WyswietlWyr(WyrZ_PytanieTestowe);
    cout << " Podaj odpowiedz: ";
    int i=0;
    for(i=0; i<4; i++)
      {
	cin >> Odpowiedz;
	Wynik=Oblicz(WyrZ_PytanieTestowe);

	if(!cin.good() )
	  {
	    if(i<3)
	      {
		cout<< "Blad formatu liczby zespolonej, sprobuj ponownie"<<endl;
		cout<< "Twoja odpowiedz: ";
	      }
	    else
	      {
		dodaj_zla(Ocena);
		cout <<"ZLA ODPOWIEDZ"<<endl<<" Poprawny wynik to: "<<Wynik<<endl;
	      }
	    cin.clear();
	    cin.ignore(10000,'\n');
	  }
	else
	  {
	    if(Odpowiedz==Wynik)
	    {
	      dodaj_dobra(Ocena);
	      cout<< "Poprawna odpowiedz"<<endl;

	      break;
	    }
	    else
	      {
		if(Odpowiedz!=Wynik)
		  {
		    dodaj_zla(Ocena);
		    cout <<"ZLA ODPOWIEDZ"<<endl<<" Poprawny wynik to: "<<Wynik<<endl;
		    
		    break;
		}
	      }
	  }
      }

  }


  cout << endl;
  cout << " Koniec testu" << endl;
  Statystyki(Ocena);
  cout << endl;
}
