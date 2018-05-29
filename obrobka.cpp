#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>

using namespace std;


int main()
{

int tab[500];
fstream plik;
plik.open("pelny.txt",ios::in );  //otwarcie pliku do odczytu in,

if(plik.good()==false)
{
  cout<<"nie ma takiego pliku";
  exit(0);
}
string linia;
int nr_linii=1;
int lin=0;
while(getline(plik,linia))
{
  // cout<<linia<<endl;
lin=  std::stoi( linia );
  tab[nr_linii-1]=lin;
  nr_linii++;
}
unordered_map<int, size_t> map;

for(auto num : tab)
    map[num] += 1;



for(const auto &pair : map)
    plik << pair.first << ','<<pair.second<<endl;;
for(const auto &pair : map)
    cout << pair.first << ','<<pair.second<<endl;;
return 0;
}
