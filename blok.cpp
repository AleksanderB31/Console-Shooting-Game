#pragma once
#include "blok.h"
void blok::losuj(plansha& p, blok*& tab) {
	srand(time(NULL));
	for (int i = 0; i < ILOSC_MAX_BLOCZKOW; i++) {
		tab[i].numer = i;
		if (rand() % 12 == 0) {
			tab[i].cialo = "#%%#";
		}
		else if (rand() % 12 == 1) {
			tab[i].cialo = "#oo#";
		}
	}
}