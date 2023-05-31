#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <time.h>
#include "plansha.h"
#define WYSOKOSC_PLANSZY 15
#define STALA_PLANSZOWA p.ilosc_kolumn * 4 + (p.ilosc_kolumn - 1) * 2
#define ILOSC_MAX_BLOCZKOW   p.ilosc_kolumn * p.ilosc_bloczkow*  p.ilosc_kolumn * p.ilosc_bloczkow
using namespace std;
class blok;
class plansha;
class blok {
public:
	string cialo;
	int numer;
	blok() {
		cialo = "####";
		numer = 0;
	}
	void losuj(plansha& p, blok*& tab);
	~blok() {}
};

