#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <time.h>
#include "plansha.h"
#include "blok.h"
#define WYSOKOSC_PLANSZY 15
#define STALA_PLANSZOWA p.ilosc_kolumn * 4 + (p.ilosc_kolumn - 1) * 2
#define ILOSC_MAX_BLOCZKOW   p.ilosc_kolumn * p.ilosc_bloczkow*  p.ilosc_kolumn * p.ilosc_bloczkow
using namespace std;
class blok;
class plansha;
void wczytaj(plansha& p, int& r, int& n) {
	int spr = 0;
	cout << "Podaj ilosc kolumn:" << endl;
	cin >> p.ilosc_kolumn;
	cout << "Podaj ilosc bloczkow w kolumnie wieksza niz 0 i mniejsza niz " << WYSOKOSC_PLANSZY - 6 << ":" << endl;
	while (spr != 1) {
		cin >> p.ilosc_bloczkow;
		if (p.ilosc_bloczkow > 0 && p.ilosc_bloczkow < (WYSOKOSC_PLANSZY - 6))
			spr = 1;
		else cout << "Zla wartosc, podaj wartosc ponownie:" << endl;
	}
	cout << "Co r+rnd ruchow do wszystkich kolumn dodawany jest jeden blok zmniejszajac przestrzen dla gracza. Parametr rnd jest wartoscia losowa z przedzialu[0, n)" << endl;
	cout << "Wybierz parametr r:" << endl;
	cin >> r;
	cout << "Wybierz parametr n:" << endl;
	cin >> n;
}
int main() {
	int r;
	int n;
	int iterator = 0;
	plansha p;
	wczytaj(p, r, n);
	int bloczki = p.ilosc_kolumn * p.ilosc_bloczkow;
	srand(time(NULL));
	int rnd;
	rnd = rand() % n;
	cout << "plansha rosnie co " << r + rnd << "ruchow" << endl;
	blok* tab = new blok[ILOSC_MAX_BLOCZKOW];
	tab->losuj(p, tab);
	p.tworzenie(p, tab);
	p.rysuj(p, tab);
	while (p.przegrana(p) && p.wygrana(p)) {
		p.strzal(p, tab);
		iterator++;
		p.wzrost(p, tab, iterator, r, n, bloczki, rnd);
		p.rysuj(p, tab);
	}
	if (p.wygrana(p) == 0) {
		cout << "Wygrales!!" << endl;
	}
	else if (p.przegrana(p) == 0) {
		cout << "Przegrales!!" << endl;
	}
	cout << "Koniec gry";
	delete[]tab;
}
