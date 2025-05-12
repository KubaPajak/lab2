#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale>
#include <cmath>


void przydzielPamiec1D(int * &tab, int n){
    tab = new int[n];
    if (tab == nullptr) {
        std::cerr << "Nie można przydzielić pamięci!" << std::endl;
        exit(1);
    }
}

void przydzielPamiec2D(int ** &tab, int w, int k){
    tab = new int*[w];
    for (int i = 0; i < w; ++i) {
        tab[i] = new int[k];
    }
    if (tab == nullptr) {
        std::cerr << "Nie można przydzielić pamięci!" << std::endl;
        exit(1);
    }



}

// optymalna funkcja sprawdzająca czy liczba jest pierwsza

void wypelnijTablice1D(int * tab, int n, int a, int b){
    std::srand(std::time(0));
    for (int i = 0; i < n; ++i) {
        tab[i] = rand() % (b - a + 1) + a;
    }
}

void wypelnijTablice2D(int ** tab, int w, int k, int a, int b){
    std::srand(std::time(0));
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < k; ++j) {
            tab[i][j] = rand() % (b - a + 1) + a;
        }
    }

}

void usunTablice1D(int * &tab){
    delete[] tab;
    tab = nullptr;
    std::cout << "Tablica 1D została usunięta." << std::endl;
}

void usunTablice2D(int ** &tab, int w){
    for (int i = 0; i < w; ++i) {
        delete[] tab[i];
    }
    delete[] tab;
    tab = nullptr;
    std::cout << "Tablica 2D została usunięta." << std::endl;
}

void wyswietl1D(int * tab, int n){
    std::cout << "Tablica 1D: ";
    for (int i = 0; i < n; ++i) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

void wyswietl2D(int ** tab, int w, int k){
    std::cout << "Tablica 2D: " << std::endl;
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < k; ++j) {
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void sortowanieBabelkowe(int * tab, int n, int tryb){
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if ((tryb == 1 && tab[j] > tab[j + 1]) || (tryb == 2 && tab[j] < tab[j + 1])) {
                std::swap(tab[j], tab[j + 1]);
            }
        }
    }
}

void sortowaniePrzezWstawianie(int * tab, int n, int tryb){
    for (int i = 1; i < n; ++i) {
        int key = tab[i];
        int j = i - 1;
        while (j >= 0 && ((tryb == 1 && tab[j] > key) || (tryb == 2 && tab[j] < key))) {
            tab[j + 1] = tab[j];
            --j;
        }
        tab[j + 1] = key;
    }
}

void sortowaniePrzezWybor(int * tab, int n, int tryb){
    for (int i = 0; i < n - 1; ++i) {
        int index = i;
        for (int j = i + 1; j < n; ++j) {
            if ((tryb == 1 && tab[j] < tab[index]) || (tryb == 2 && tab[j] > tab[index])) {
                index = j;
            }
        }
        std::swap(tab[i], tab[index]);
    }
}

void sortowanieBabelkowe2Dwzgledemkolumny(int ** tab, int w, int k, int tryb, int kolumna){
    for (int i = 0; i < w - 1; ++i) {
        for (int j = 0; j < w - i - 1; ++j) {
            if ((tryb == 1 && tab[j][kolumna] > tab[j + 1][kolumna]) || (tryb == 2 && tab[j][kolumna] < tab[j + 1][kolumna])) {
                std::swap(tab[j], tab[j + 1]);
            }
        }
    }

}
void wykonajZadanie2_2(){
int *tab = nullptr;
int n,tryb;
std::cout << "Podaj rozmiar tablicy 1D: ";
std::cin >> n;
przydzielPamiec1D(tab, n);
int a, b;
std::cout << "Podaj zakres losowania (a, b): ";
std::cin >> a >> b;
wypelnijTablice1D(tab, n, a, b);
std::cout << "Podaj tryb sortowania(1 - rosnąco, 2 - malejąco): ";
std::cin >> tryb;
if (tryb != 1 && tryb != 2) {
    std::cerr << "Nieprawidłowy tryb sortowania!" << std::endl;
    usunTablice1D(tab);
    return;
}
std::cout << "Tablica przed sortowaniem: ";
wyswietl1D(tab, n);
std::cout<< "Sortowanie bąbelkowe: ";
sortowanieBabelkowe(tab, n, tryb);
wyswietl1D(tab, n);
usunTablice1D(tab);
}

void wykonajZadanie2_3(){
int *tab = nullptr;
int n,tryb;
std::cout << "Podaj rozmiar tablicy 1D: ";
std::cin >> n;
przydzielPamiec1D(tab, n);
int a, b;
std::cout << "Podaj zakres losowania (a, b): ";
std::cin >> a >> b;
wypelnijTablice1D(tab, n, a, b);
std::cout << "Podaj tryb sortowania (1 - rosnąco, 2 - malejąco): ";
std::cin >> tryb;
if (tryb != 1 && tryb != 2) {
    std::cerr << "Nieprawidłowy tryb sortowania!" << std::endl;
    usunTablice1D(tab);
    return;
}
std::cout << "Tablica przed sortowaniem: ";
wyswietl1D(tab, n);
std::cout<< "Sortowanie przez wybor: ";
sortowaniePrzezWybor(tab, n, tryb);
wyswietl1D(tab, n);
usunTablice1D(tab);
}

void wykonajZadanie2_4(){
int *tab = nullptr;
int n,tryb;
std::cout << "Podaj rozmiar tablicy 1D: ";
std::cin >> n;
przydzielPamiec1D(tab, n);
int a, b;
std::cout << "Podaj zakres losowania (a, b): ";
std::cin >> a >> b;
wypelnijTablice1D(tab, n, a, b);
std::cout << "Podaj tryb sortowania (1 - rosnąco, 2 - malejąco): ";
std::cin >> tryb;
if (tryb != 1 && tryb != 2) {
    std::cerr << "Nieprawidłowy tryb sortowania!" << std::endl;
    usunTablice1D(tab);
    return;
}
std::cout << "Tablica przed sortowaniem: ";
wyswietl1D(tab, n);
std::cout<< "Sortowanie przez wstawianie: ";
sortowaniePrzezWstawianie(tab, n, tryb);
wyswietl1D(tab, n);
usunTablice1D(tab);
}

void wykonajZadanie2_5(){
int **tab = nullptr;
int w, k, tryb, numerKolumny;
std::cout << "Podaj rozmiar tablicy 2D (wiersze i kolumny): ";
std::cin >> w >> k;
przydzielPamiec2D(tab, w, k);
int a, b;
std::cout << "Podaj zakres losowania (a, b): ";
std::cin >> a >> b;
wypelnijTablice2D(tab, w, k, a, b);
std::cout << "Podaj tryb sortowania (1 - rosnąco, 2 - malejąco): ";
std::cin >> tryb;
if (tryb != 1 && tryb != 2) {
    std::cerr << "Nieprawidłowy tryb sortowania!" << std::endl;
    usunTablice2D(tab, w);
    return;

}
std::cout << "Podaj numer kolumny do sortowania (1 - " << k << "): ";
std::cin >> numerKolumny;
if (numerKolumny < 0 || numerKolumny >= k) {
    std::cerr << "Nieprawidłowy numer kolumny!" << std::endl;
    usunTablice2D(tab, w);
    return;

}
std::cout << "Tablica przed sortowaniem: " << std::endl;
wyswietl2D(tab, w, k);
std::cout<< "Sortowanie bąbelkowe wg kolumny " << numerKolumny << ": " << std::endl;
sortowanieBabelkowe2Dwzgledemkolumny(tab, w, k, tryb, numerKolumny);
wyswietl2D(tab, w, k);
usunTablice2D(tab, w);

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

        case 2: wykonajZadanie2_3();
        break;

        case 3: wykonajZadanie2_4();
        break;

        case 4: wykonajZadanie2_5();
        break;

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