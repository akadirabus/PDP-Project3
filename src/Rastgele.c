#include "Rastgele.h"

//Rastgele sınıfını oluşturan ve defaul değerleri atayan fonksiyon
Rastgele RastgeleOlustur(){
	Rastgele rastgele;
	rastgele = (Rastgele)malloc(sizeof(struct RASTGELE));
	rastgele->ShiftRegister = 0x0123;
	return rastgele;
}

//LFSR(Linear-Feedback Shift Register) algoritması kullanarak rastgelelik sağlayan fonksiyon
unsigned RastgeleUret(const Rastgele rast, unsigned maks){
	rast-> ShiftRegister= ((((rast-> ShiftRegister >> 15)
                  ^  (rast-> ShiftRegister >> 6)
                  ^  (rast-> ShiftRegister >> 4)
                  ^  (rast-> ShiftRegister >> 2)
                  ^  (rast-> ShiftRegister >> 1)
                  ^  (rast-> ShiftRegister))
                  &  0x00000001)
                  << 15)
                  |  (rast-> ShiftRegister >> 1);

	return ((rast->ShiftRegister*system_clock())%maks);
}

int system_clock(){
	clock_t start = clock();
	return start;
}

void RastgeleYoket(Rastgele rast){
	if(rast == NULL) return;
	free(rast);
	rast = NULL;
}
