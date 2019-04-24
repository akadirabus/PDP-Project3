#include "RastgeleKarakter.h"

//RastgeleKarakter sınıfı tarafından oluşturulan yapı için yer ayıran default değeri atayan ve döndüren fonksiyon
RastgeleKarakter KarakterOlustur(){
	RastgeleKarakter karakter;

	karakter = (RastgeleKarakter)malloc(sizeof(struct RASTGELEKARAKTER));
	karakter->rastgele = RastgeleOlustur();

	return karakter;
}

//ASCII sınırlamalarına göre LFSR(Linear-Feedback Shift Register) algoritmasını kullanarak rastgele üretilen sayıyı karakter olarak döndüren fonksiyon
char Karakter(RastgeleKarakter rast){
	unsigned ranstgeleSayi = RastgeleUret(rast->rastgele, 122);

	while(ranstgeleSayi < 65 || ranstgeleSayi > 122 || (ranstgeleSayi < 97 && ranstgeleSayi > 90)){
		ranstgeleSayi = RastgeleUret(rast->rastgele, 122);
	}

	return (char)ranstgeleSayi;
}

//Karakter fonksiyonunun göstericisi
char* KARAKTER(RastgeleKarakter rast, unsigned adet){
	char *karakter_dizi = (char *)malloc(sizeof(char) * adet);

	int i;
	for(i = 0; i < adet; i++){
		karakter_dizi[i] = Karakter(rast);
	}

	return karakter_dizi;
}

//Üretilen rastgele sayıyı girilen sınırlar içerisinde üreterek karakter olarak döndüren fonksiyon
char KarakterlerArasinda(RastgeleKarakter rast, char first, char last){
	unsigned sayi = RastgeleUret(rast->rastgele, 122);

	while(sayi < (int)first || sayi > (int)last || (sayi < 97 && sayi > 90)){
		sayi = RastgeleUret(rast->rastgele, 122);
	}

	return (char)sayi;
}

//KarakterArasinda fonksiyonunun göstericisi
char* KARAKTERLERARASINDA(RastgeleKarakter rast, char first, char last, unsigned adet){
	unsigned sayi = RastgeleUret(rast->rastgele, 122);
	char *karakter_dizi = (char *)malloc(sizeof(char) * adet);

	unsigned i;
	for(i = 0; i < adet; i++){
		while(sayi < (int)first || sayi > (int)last){
			sayi = RastgeleUret(rast->rastgele, 122);
		}
			karakter_dizi[i] = (char)sayi;
			sayi = RastgeleUret(rast->rastgele, 122);
	}
	karakter_dizi[adet] = '\0';
	return karakter_dizi;
}

//Tanımlı olan dizinin indisine rastgele üretilen sayı ile ulaşarak karakter olarak döndüren fonksiyon
char Secim(RastgeleKarakter rast, char* karakter_dizi){
	unsigned length = (sizeof(karakter_dizi) / sizeof(karakter_dizi[0])) - 1;
	unsigned sayi = RastgeleUret(rast->rastgele, length);

	while(sayi < 0 || sayi >= length || sayi == 6){
		sayi = RastgeleUret(rast->rastgele, length);
	}
	return (char)karakter_dizi[sayi];
}

//Secim fonksiyonunun göstericisi
char* SECIM(RastgeleKarakter rast, char* karakter_dizi, unsigned adet){
	unsigned length = (sizeof(karakter_dizi) / sizeof(karakter_dizi[0])) - 1;
	unsigned sayi = RastgeleUret(rast->rastgele, length);

	char *dizi = (char *)malloc(sizeof(char) * adet);

	unsigned i;
	for(i = 0; i < adet; i++){
		while(sayi < 0 || sayi >= length || sayi == 6){
			sayi = RastgeleUret(rast->rastgele, length);
		}
		dizi[i] = karakter_dizi[sayi];
		sayi = RastgeleUret(rast->rastgele, length);
	}
	dizi[adet] = '\0';
	return dizi;

}

//Otomatik çöp temizle olmadığı için program sonlanmadan sınıfın bellekteki yerini iade eden fonksiyon
void KarakterYoket(RastgeleKarakter rast){
	if(rast == NULL){
		return;
	}
	else{
		free(rast->rastgele);
		rast->rastgele = NULL;
		free(rast);
		rast = NULL;
	}
}
