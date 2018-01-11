#include<iostream>
using namespace std;
 
void countingsort(int A[], int B[], int k, int rozmiar)
{
int i;
int *C = new int [k+1]; // utworzenie tablicy na statystyki; wszystkie liczby w tablicy sa nie wieksze od k, a C[i] okresla ile razy wystapila liczb i
for (i = 0; i <= k; i++) // zerowanie tablicy pomocniczej
C[i] = 0;
for (i = 0; i < rozmiar; i++)
C[(A[i])]++;
// C[i] zawiera teraz liczbe wystapien liczby i w ciagu wejsciowym
for (i = 1; i <= k; i++)
C[i] += C[i-1];
// C[i] zawiera teraz liczbe elementow mniejszych lub rownych i
for (i = rozmiar-1; i >= 0; i--)
{
B[(C[(A[i])])-1] = A[i]; // wpisanie do tablicy wynikowej pod okreœlony indeks A[i]
C[(A[i])]--; // zmniejszenie indeksu C[i] - odejmujemy wpisana przed chwila liczbe
}
delete [] C;
}
 
int max_liczba(int tablica[], int rozmiar)
{
int max = tablica[0];
for (int i = 1; i < rozmiar; i++)
{
if (max < tablica[i])
max = tablica[i];
}
return max;
}
 
int main()
{
int ilosc_liczb, i;
cout << "Podaj ilosc licz do posortowania: ";
cin >> ilosc_liczb;
// utworzenie dynamicznej dwoch tablic na 'ilosc_liczb' elementow
int *tablica_wejsciowa = new int [ilosc_liczb]; // tablica zawierajaca ciag wejsciowy
int *tablica_wyjsciowa = new int [ilosc_liczb]; // tablica zawierajaca posortowany ciag
 
for (i = 0; i < ilosc_liczb; i++) // wczytywanie liczb do tablicy
{
cout << "Podaj liczba: ";
cin >> tablica_wejsciowa[i];
}
 
int k = max_liczba(tablica_wejsciowa, ilosc_liczb); // wyszukanie najwiekszej liczby w ciagu wejsciowym
countingsort(tablica_wejsciowa,tablica_wyjsciowa, k, ilosc_liczb); // wywolanie funkcji sortujacej
 
for (i = 0; i < ilosc_liczb; i++) // wypisanie posortowanej tablicy
cout << "tablica[" << i << "] = " << tablica_wyjsciowa[i] << endl;
 
// zwolnienie tablic zaalokowanych dynamicznie
delete [] tablica_wejsciowa;
delete [] tablica_wyjsciowa;
 
return 0;
}