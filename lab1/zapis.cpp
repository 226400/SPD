#include <iostream>
#include <fstream>

using namespace std;
CO_WPISAC


int main()
{
cout << "CO_WPISAC";
cin>>CO_WPISAC;


fstream plik;
plik.open("CO_OTOWRZYC",ios::out | ios::app);  //otwarcie pliku do zapisu out, zapis dodatkowy na koncu pliku app
plik<<CO_WPISAC<<endl;

plik.close();
return 0;
}
