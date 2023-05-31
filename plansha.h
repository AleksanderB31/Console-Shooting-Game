#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <time.h>
#include "blok.h"
#define WYSOKOSC_PLANSZY 15
#define STALA_PLANSZOWA p.ilosc_kolumn * 4 + (p.ilosc_kolumn - 1) * 2
#define ILOSC_MAX_BLOCZKOW   p.ilosc_kolumn * p.ilosc_bloczkow*  p.ilosc_kolumn * p.ilosc_bloczkow
using namespace std;
class blok;
class plansha;
class plansha {
public:
	int ilosc_kolumn;
	int ilosc_bloczkow;
	typedef stack<blok>kolumna;
	vector<kolumna> pole;
	kolumna* kolumny;
	friend void wczytaj(plansha& p, int& r, int& n);
	void rysuj(plansha p, blok*& tab);
	void tworzenie(plansha& p, blok*& tab);
	void strzal(plansha& p, blok*& tab);
	void wzrost(plansha& p, blok*& tab, int& iterator, int r, int n, int& bloczki, int rnd);
	bool przegrana(plansha& p);
	bool wygrana(plansha& p);
};

