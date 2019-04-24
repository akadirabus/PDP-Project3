#include "RastgeleKarakter.h"

int main(){

	//Seçimin yapılacağı karakter dizisi
	char *karakterler = "gyucne";

	//Sınıf benzetimi oluşturuldu
	RastgeleKarakter rastgele = KarakterOlustur();

	printf("Rastgele Karakter: %c\n", Karakter(rastgele));
	printf("Rastgele Karakter: %c\n", Karakter(rastgele));

	printf("Rastgele 3 Karakter: %s\n", KARAKTER(rastgele, 3));
	printf("Rastgele 3 Karakter: %s\n", KARAKTER(rastgele, 3));

	printf("Verilen iki karakter (a,k): %c\n", KarakterlerArasinda(rastgele, 'a', 'k'));

	printf("Verilen iki karakter (a,k): %s\n", KARAKTERLERARASINDA(rastgele, 'a', 'k', 2));

	printf("Belirtilen Karakterler (g,y,u,c,n,e): %c\n", Secim(rastgele, karakterler));
	printf("Belirtilen Karakterler (g,y,u,c,n,e): %c\n", Secim(rastgele, karakterler));
	printf("Belirtilen Karakterler (g,y,u,c,n,e): %s\n", SECIM(rastgele, karakterler, 2));

	KarakterYoket(rastgele);

	getchar();
	return 0;
}
