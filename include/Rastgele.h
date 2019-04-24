#ifndef RANDOM_H
#define RANDOM_H

#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct RASTGELE{

	unsigned short ShiftRegister;

};
typedef struct RASTGELE* Rastgele;

Rastgele RastgeleOlustur();

unsigned RastgeleUret(const Rastgele, unsigned);

int system_clock();

void RastgeleYoket(Rastgele);

#endif
