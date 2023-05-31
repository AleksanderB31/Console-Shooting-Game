#pragma once
#include "plansha.h"
void plansha::rysuj(plansha p, blok*& tab) {
	for (int i = 0; i < STALA_PLANSZOWA; i++)
		cout << "-";
	cout << endl;
	typedef stack<blok>kopia;
	int roz2;
	kopia* kopie = new kopia[p.ilosc_kolumn];
	kopia* kopie2 = new kopia[p.ilosc_kolumn];
	for (int i = 0; i < ilosc_kolumn; i++) {
		int roz = p.kolumny[i].size();
		for (int j = 0; j < roz; j++) {
			kopie[i].push(p.kolumny[i].top());
			kopie2[i].push(p.kolumny[i].top());
			p.kolumny[i].pop();
		}
	}
	for (int i = 0; i < p.ilosc_bloczkow; i++) {
		for (int j = 0; j < p.ilosc_kolumn; j++) {
			roz2 = kopie2[j].size();
			if (i < roz2) {
				cout << kopie[j].top().cialo << "  ";
				p.kolumny[j].push(kopie[j].top());
				kopie[j].pop();
			}
			else cout << "      ";
		}
		cout << endl;
	}
	int max = 0;
	for (int i = 0; i < p.ilosc_kolumn; i++) {
		if (kolumny[i].size() > max) {
			max = kolumny[i].size();
		}
	}
	for (int i = 0; i < WYSOKOSC_PLANSZY - max - 1; i++)
		cout << endl;
	cout << setw((STALA_PLANSZOWA) / 2 + 2) << "=[]=" << endl;
	for (int i = 0; i < STALA_PLANSZOWA; i++)
		cout << "-";
	cout << endl;
	delete[]kopie;
	delete[]kopie2;
}
void plansha::tworzenie(plansha& p, blok*& tab) {
	int it = 0;
	kolumny = new kolumna[p.ilosc_kolumn];
	for (int i = 0; i < p.ilosc_kolumn; i++) {
		p.pole.push_back(kolumny[i]);
		for (int j = 0; j < p.ilosc_bloczkow; j++) {
			kolumny[i].push(tab[it]);
			it++;
		}
	}
}
void plansha::strzal(plansha& p, blok*& tab) {
	int s;
	cout << "Wybierz kolumne do strzalu: " << endl;
	cin >> s;
	if (s <= p.ilosc_kolumn) {
		if (p.kolumny[s - 1].top().cialo == "####") {
			p.kolumny[s - 1].pop();
		}
		else if (p.kolumny[s - 1].top().cialo == "#%%#") {
			if (p.kolumny[s - 1].size() == 1) {
				p.kolumny[s - 1].pop();
			}
			if (p.kolumny[s - 1].size() > 1) {
				p.kolumny[s - 1].pop();
				p.kolumny[s - 1].pop();
			}
		}
		else if (p.kolumny[s - 1].top().cialo == "#oo#") {
			if (p.kolumny[s - 1].size() == 2) {
				p.kolumny[s - 1].pop();
				p.kolumny[s - 1].pop();
			}
			if (p.kolumny[s - 1].size() == 1) {
				p.kolumny[s - 1].pop();
			}
			else if (p.kolumny[s - 1].size() > 2) {
				p.kolumny[s - 1].pop();
				p.kolumny[s - 1].pop();
				p.kolumny[s - 1].pop();
			}
		}
	}
	else cout << "Podano zle dane" << endl;
	cout << endl;
}
void plansha::wzrost(plansha& p, blok*& tab, int& iterator, int r, int n, int& bloczki, int rnd) {
	if (iterator == r + rnd) {
		for (int i = 0; i < p.ilosc_kolumn; i++) {
			kolumny[i].push(tab[bloczki]);
			bloczki++;
		}
		p.ilosc_bloczkow++;
		iterator = 0;
	}
}
bool plansha::przegrana(plansha& p) {
	for (int i = 0; i < p.ilosc_kolumn; i++) {
		if (p.kolumny[i].size() == WYSOKOSC_PLANSZY - 1) {
			return 0;
		}
	}
}
bool plansha::wygrana(plansha& p) {
	for (int i = 0; i < p.ilosc_kolumn; i++) {
		if (p.kolumny[i].size() == 0) {
			return 0;
		}
	}
}