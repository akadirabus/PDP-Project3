#ifndef RASTGELEKARAKTER_H
#define RASTGELEKARAKTER_H

#include "Rastgele.h"

struct RASTGELEKARAKTER{

	Rastgele rastgele;

};

typedef struct RASTGELEKARAKTER* RastgeleKarakter;

RastgeleKarakter KarakterOlustur();

char Karakter(RastgeleKarakter);
char* KARAKTER(RastgeleKarakter, unsigned);

char KarakterlerArasinda(RastgeleKarakter, char, char);
char* KARAKTERLERARASINDA(RastgeleKarakter, char, char, unsigned);

char Secim(RastgeleKarakter, char*);
char* SECIM(RastgeleKarakter, char*, unsigned);

void KarakterYoket(RastgeleKarakter);

#endif
