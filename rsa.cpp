#include <iostream>
#include <math.h>
#include <fstream>

/* Algorytm Euklidesa.
Zwraca najwiekszy wspólny dzielnik. */
int gcd(unsigned long long a,unsigned long long int b) {
    int tmp;
    while (b != 0)  {
      tmp = b;
      b = a % b;
      a = tmp;
    }
    return a;
}

/* Rozszerzony Algorytm Euklidesa.
https://en.wikibooks.org/wiki/Algorithm_Implementation/Mathematics/Extended_Euclidean_algorithm
*/
int egcd(unsigned long long e, unsigned long long fi) {
    long d = 0;
    long x1 = 0;
    long x2 = 1;
    long y1 = 1;
    long temp = fi;

    int temp1;
    int temp2;
    int x;
    int y;

    while (e > 0) {
        temp1 = temp/e;
        temp2 = temp - temp1 * e;
        temp = e;
        e = temp2;

        x = x2- temp1* x1;
        y = d - temp1 * y1;

        x2 = x1;
        x1 = x;
        d = y1;
        y1 = y;
    }
    if (temp == 1) {
        return d + fi;
    }
    else return 0;
}


// zwraca wartość (base^exp) % mod
int powerModulo(unsigned long long base, unsigned long long exp, unsigned long long mod) {

    if(mod == 1) return 0;

    int result = 1;

    for(uint i = 0; i < exp; ++i){
        result = (result * base) % mod;
    }
    return result;
}

// int generator()
// {

// }
int partition(int tablica[], int p, int r)
{
int x = tablica[p];
int i = p, j = r, w;
while (true)
{
while (tablica[j] > x)
j--;
while (tablica[i] < x)
i++;
if (i < j)
{
w = tablica[i];
tablica[i] = tablica[j];
tablica[j] = w;
i++;
j--;
}
else
return j;
}
}

void quicksort(int tablica[], int p, int r)
{
int q;
if (p < r)
{
q = partition(tablica,p,r);
quicksort(tablica, p, q);
quicksort(tablica, q+1, r);
}
}





int main()
{
    unsigned long long p = 1237;
    unsigned long long q = 2137;
    unsigned long long n = p * q;
    unsigned long long fi = (p-1) * (q-1);
    int wpisz=2;
    int potega=0;
    int liczba=0;
    int ilosc=500;
    int tablica[ilosc];
    int bit=8;
    uint e = n/2;

    while (gcd(fi,e) > 1 && e < n) {
        ++e;
    }

    int d = egcd(e,fi);
    int data = 2137; // tajna wiadomosc

    int encrypted = powerModulo(data,e,n);





    for (int i=0; i<ilosc/2; i++)
    {
    for (int j=0; j<bit; j++)
    {
      data = encrypted%7111;
      // std::cout<<data<<std::endl;
      encrypted = powerModulo(data,e,n);
      if (encrypted%2==0)
{      potega=j;
       wpisz=1;
       liczba=liczba+pow(2,potega);
}      else  wpisz=0;

      std::cout << "   " << wpisz  ;
  }
  std::cout << " "<<liczba ;
tablica[i]=liczba;
liczba=0;
    std::cout  << std::endl;

  }



    for (int i=ilosc/2+1; i<ilosc; i++)
    {
    for (int j=0; j<bit; j++)
    {
      data = encrypted%17107;
      // std::cout<<data<<std::endl;
      encrypted = powerModulo(data,e,n);
      if (encrypted%2==0)
{      potega=j;
       wpisz=1;
       liczba=liczba+pow(2,potega);
}      else  wpisz=0;
      std::cout << "   " << wpisz  ;
  }
  std::cout << " "<<liczba ;
tablica[i]=liczba;
liczba=0;
    std::cout  << std::endl;

  }



  
  quicksort(tablica,0,ilosc-1);

  std::fstream plik;
  plik.open("pelny.txt",std::ios::out | std::ios::app);  //otwarcie pliku do zapisu out, zapis dodatkowy na koncu pliku app
  for(int i=0; i<ilosc; i++)
{
  plik<<tablica[i]<<std::endl;
}
  plik.close();
    return 0;
}
