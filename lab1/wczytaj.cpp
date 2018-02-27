#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
string imie, nazwisko;
int nr_tel;


int main()
{


fstream plik;
plik.open("PLIK_DO_OTWARCIA",ios::in );  //otwarcie pliku do odczytu in,

if(plik.good()==false)
{
  cout<<"nie ma takiego pliku";
  exit(0);
}
string linia;
int nr_linii=1;
while(getline(plik,linia))
{
  cout<<linia<<endl;

  nr_linii++;
}

plik.close();
return 0;
}
