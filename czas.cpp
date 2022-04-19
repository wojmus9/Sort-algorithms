
#include <ctime> 
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

void losowe(int tab[], int a){// funkcja która losuje nam liczby z zakresu od -2500 do 2500
	srand(2001); // ziarno powoduje ¿e bêd¹ losowane zawsze te same liczby
    for (int i = 0; i <a; i++)
    {
        tab[i] = rand() % 5001-2500;
    }
    
}
void pokaz(int tab[], int a){ // funkcja która wyœwietla podan¹ tablice
    for (int i = 0; i < a; i++)
        cout << tab[i] << " ";
}
void kopia(int tab[], int tab_copy[], int a){ //funkcja która kopiuje liczby z jednej do drugiej tablicy
    for(int i = 0; i<a; i++){
        tab_copy[i] = tab[i];
    }
}


 // sortowanie przez proste wstawienie    
 void sort(int tab[], int a)
{
     int pom, j;
     for(int i=1; i<a; i++)
     {
             //wstawienie elementu w odpowiednie miejsce
             pom = tab[i]; //ten element bêdzie wstawiony w odpowiednie miejsce
             j = i-1;
             
             //przesuwanie elementów wiêkszych od pom
             while(j>=0 && tab[j]>pom) 
             {
                        tab[j+1] = tab[j]; //przesuwanie elementów
                        --j;
             }
             tab[j+1] = pom; //wstawienie pom w odpowiednie miejsce
     }     
}



void sort2(int tab[], int a){ // funkcja która odwaraca nam tablice z posortowanej rosn¹co do posortowanej malej¹co 
    for(int i = a-1 ; i>0; i--){
        for(int j = i; j>=0;j--){
            if(tab[i]>tab[j])
               swap(tab[i],tab[j]);
              
        }
    }
}


void prosty_wyb(int tab[] , int a){
    for(int i = 0 ; i < a-1  ;i++){
        int c = i ;
        int b = tab[i];
        
        for(int j = i+1 ; j < a-1 ; j++){
            if(tab[j] < b ){ 
                c = j;
                b= tab[j];
                
            }
        }
        tab[c] = tab[i];
        tab[i] = b;
    }
}

void merge(int tab[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
  
    int L[n1], R[n2];
 
   
    for (int i = 0; i < n1; i++)
        L[i] = tab[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = tab[m + 1 + j];
    
    int i = 0;
    int j = 0; 
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            tab[k] = L[i];
            i++;
        }
        else {
            tab[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        tab[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        tab[k] = R[j];
        j++;
        k++;
    }
}
 



int mergeSort(int tab[],int l,int r){// sortowanie przez scalenie

    if(l>=r){
        return 0;
    }
    int m = (l+r)/2;
    mergeSort(tab,l,m);
    mergeSort(tab,m+1,r);
    merge(tab,l,m,r);
}
	




void sort_babelkowe( int tab[], int a ){
	int tmp; 
    for( int i = 0; i < a; i++ )
    {   
        for( int j = 0; j < a ; j++ )
        {
            if( tab[ j ] > tab[ j + 1] )
            {
            	tmp=tab[j];
            	tab[j]=tab[j-1];
            	tab[j-1]=tmp;
			}
                
           
        }
    }
}



void wyszukiwanie_liniowe(int tab[],int a, int k)
{
    int i;
    for (i = 0; i < a; i++)
    {

        if (tab[i] == k)
        {
            cout << "wyszukiwanie liniowe.Znaleziony na pozycji w tablicy nieposortowanej: " << i +1   <<endl;
            break;
        }
    }
    if (i == a)
    {cout << "wyszukiwanie liniowe.Nie ma takiej liczby w tablicy nieposortowanej"<< endl;
	}
        
    
}
void wyszukiwanie_polow(int tab[], int dlug, int a )
{
    int pocz = 0;
    int kon = dlug - 1;
    while (pocz <= kon)
    {
        int sr = (pocz + kon) / 2;
        if ( tab[sr] == a)
        {
            cout<<"wyszukiwanie binarne. Znaleziony na pozycji w tablicy posortowanej: "<<sr+1<<endl;
            break;
        }
        else if (tab[sr] > a)
        {
            kon = sr-1;
        }
        else if (tab[sr]<a)
        {
            pocz = sr+1;
        }
        else 
        cout << "Nie ma takiej liczby w tablicy "<< endl;
    }

}


int min(int tab[], int a)
{
    int min = tab[0];

    for (int i = 1; i < a; i++)
        if (tab[i] < min)
            min = tab[i];

    return min;
}
    
int max(int tab[], int a)
{
    int max = tab[0];

    for (int i = 1; i < a; i++)
        if (tab[i] > max)
            max = tab[i];

    return max;
}    
    
    
int main() {
    system("chcp 1250");
	int rozmiar,k;
    cout << "podaj d³ugoœc tablicy: ";
    cin >> rozmiar;
    int* tablica = new int[rozmiar];
    int* tablica2 =new int [rozmiar];
   int* tablica3=new int[rozmiar];
int* tablica4=new int[rozmiar];
int* tablica5=new int[rozmiar];
  int iloscSortowan;

  
  
	cout << "Podaj ile sortowan ma sie wykonac: ";
	cin >> iloscSortowan;

     
   
   
    losowe(tablica,rozmiar);
   kopia(tablica, tablica2,rozmiar);
   kopia(tablica, tablica3,rozmiar);
   kopia(tablica, tablica4,rozmiar);
kopia(tablica, tablica5,rozmiar);
  //  pokaz(tablica,rozmiar);  

   cout << "Czas sortowañ dla tablic nie posortowanych"<<endl;
   
    time_t t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
		prosty_wyb(tablica, rozmiar);
      time_t t2 = clock();
      time_t czasprosty = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla nie posortowanej tablicy, prosty wybór: " << czasprosty << "sec" << endl;
	//pokaz(tablica,rozmiar);

    
  t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
		sort_babelkowe(tablica2, rozmiar);
      t2 = clock();
      time_t czasBabelkowego = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla nie posortowanej tablicy, babelkowe: "<< czasBabelkowego << "sec" << endl;
//  pokaz(tablica2,rozmiar);
    cout << endl;
    
t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
		sort(tablica3, rozmiar);
      t2 = clock();
      time_t czassort = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla nie posortowanej tablicy, sortowanie proste wstawienie: "<< czassort<< "sec" << endl;
    cout << endl;
   // pokaz(tablica3,rozmiar);
t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
     mergeSort(tablica4,0,rozmiar-1);
      t2 = clock();
      time_t czasmerge = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla nie posortowanej tablicy, sortowanie przez scalnie: "<< czasmerge<< "sec" << endl;
  //pokaz(tablica,rozmiar);
   
   
   cout <<"Czas sortowania dla tablicy posortowanej"<<endl;
   
    t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
		prosty_wyb(tablica, rozmiar);
      t2 = clock();
    czasprosty = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla posortowanej tablicy, prosty wybór: " << czasprosty << "sec" << endl;
   
    t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
		sort_babelkowe(tablica, rozmiar);
      t2 = clock();
      czasBabelkowego = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla posortowanej tablicy, babelkowe: "<< czasBabelkowego << "sec" << endl;
   
   
   t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
		sort(tablica, rozmiar);
      t2 = clock();
      czassort = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla posortowanej tablicy, sortowanie przez wsawienie: "<< czassort<< "sec" << endl;
   
   t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
     mergeSort(tablica,0,rozmiar-1);
      t2 = clock();
     czasmerge = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla posortowanej tablicy, sortowanie przez scalnie: "<< czasmerge<< "sec" << endl;
   
   
   cout <<"Czas sortowania dla tablicy odwróconej "<<endl;
   
   sort2(tablica,rozmiar);// odwrócenie tablicy
   // pokaz(tablica,rozmiar);
     sort2(tablica2,rozmiar);
      sort2(tablica3,rozmiar);
       sort2(tablica4,rozmiar);
       
     
     
     
     
    t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
		prosty_wyb(tablica, rozmiar);
      t2 = clock();
    czasprosty = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla tablicy posortowanej,odwróconej  prosty wybór: " << czasprosty << "sec" << endl;
	
     
   
   t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
		sort_babelkowe(tablica2, rozmiar);
      t2 = clock();
      czasBabelkowego = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla tablicy posortowanej,odwróconej b¹belkowe: "<< czasBabelkowego << "sec" << endl;
	
     
   
    t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
		sort(tablica3, rozmiar);
      t2 = clock();
      czassort = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla tablicy posortowanej,odwróconej, sortowanie przez wstawienie: "<< czassort<< "sec" << endl;
	
     
    
     t1 = clock();
	for (int i = 0; i < iloscSortowan; i++)
     mergeSort(tablica4,0,rozmiar-1);
      t2 = clock();
     czasmerge = (t2 - t1) / CLOCKS_PER_SEC;
	cout << "Czas sortowania dla tablicy posortowanej,odwróconej , sortowanie przez scalnie: "<< czasmerge<< "sec" << endl;
   
   cout<< "Podaj jakiej liczby szukamy: ";
   cin >> k;
   
// pokaz(tablica5,rozmiar);  
wyszukiwanie_liniowe(tablica5,rozmiar,k);
// nieposortowana 

//pokaz(tablica3,rozmiar);
   
 wyszukiwanie_polow(tablica3,rozmiar,k);
// posotowana 
cout << "Najmnieszy element w tablicy: " <<min(tablica,rozmiar)<<endl;
cout << "Najwiêkszy element w tablicy: " << max(tablica,rozmiar)<<endl;



	return 0;
}
    
