#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <cmath>

void przydzieleniePamieci1D(int *tab, int n){
    tab = new int[n];
}

void zwolnijPamiec1D(int *tab){
    delete[] tab;
}

void wyswietlTablice(int *tab, int n){
    for (int i=0; i<n; i++){
        std::cout<< tab[i]<< " ";
    }
    std::cout<< std::endl;
}

void wypelnijTablice(int *tab, int n, int a, int b){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        tab[i] = rand() % (b - a + 1) + a;
    }
}

void sortowanieBabelkowe(int *tab, int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (tab[j] > tab[j+1]){
                std::swap(tab[j], tab[j+1]);
            }
        }
    }
}




void wykonajZadanie2_2(){
    int *tab;
    int a,b;
    std::cout<<"Podaj przedział losowania liczb :"<<std::endl;
    std::cout<<"Podaj dolny zakres: "<< std::endl;
    std::cin>> a;
    std::cout<<"Podaj górny zakres: "<< std::endl;
    std::cin>> b;
    if (a>b){
        std::cout<< "Błędny zakres. Podaj ponownie."<<std::endl;
        return;
    }
    int n;
    std::cout<< "Podaj liczbę elementów tablicy: "<< std::endl;
    std::cin>> n;
    if (n<=0){
        std::cout<< "Błędna liczba elementów. Podaj ponownie."<<std::endl;
        return;
    }
    przydzieleniePamieci1D(tab, n);
    wypelnijTablice(tab, n, a, b);
    std::cout<< "Wypełniona tablica: "<< std::endl;
    wyswietlTablice(tab, n);
    sortowanieBabelkowe(tab, n);
    std::cout<< "Posortowana tablica: "<< std::endl;
    wyswietlTablice(tab, n);
    zwolnijPamiec1D(tab);
    std::cout<< "Zwolniono pamięć tablicy."<< std::endl;


    std::cout<< "Wykonano zadanie 2.2"<<std::endl;
}







int main(){
setlocale(LC_ALL, "");
    int wybor;
  do{
    std::cout<<std::endl;
    std::cout<< "----------Menu----------"<<std::endl;
    std::cout<< "1. zadanie 2.2"<<std::endl;
    std::cout<< "2. zadanie 2.3"<<std::endl;
    std::cout<< "3. zadanie 2.4"<<std::endl;
    std::cout<< "4. zadanie 2.5"<<std::endl;
    std::cout<< "5. wyjście z programu"<<std::endl;
    std::cout<< "------------------------"<<std::endl;
    std::cout<< "Wybierz numer zadania do wykonania: "<< std::endl;
    std::cin>> wybor;
  
    switch (wybor){
        case 1: wykonajZadanie2_2();
        break;

        //case 2: wykonajZadanie1_3();
        //break;

        //case 3: wykonajZadanie1_4();
        //break;

        //case 4: wykonajZadanie1_5();
        //break;

        case 5:
        std::cout<< "Koniec programu."<<std::endl;
        break;

        default:
        std::cout<< "Nieprawidłowy wybór. Wybierz ponownie."<<std::endl;
        break;
    }

}while(wybor!=5);

return 0;
}