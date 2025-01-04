#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

float paraYatirma(float yatirilacakPara, float hesaptakiBakiye) {
	hesaptakiBakiye += yatirilacakPara;
	printf("Hesabinizdaki yeni mevcut bakiye %f\n", hesaptakiBakiye);
	return hesaptakiBakiye;
}

float paraCek(float cekilecekPara, float hesaptakiBakiye) {				
	if(cekilecekPara <= hesaptakiBakiye) {
		hesaptakiBakiye -= cekilecekPara;
		printf("Para cekme islemi basarili.\n");
		printf("Hesabinizda kalan bakiye: %f", hesaptakiBakiye);					
	} else {
		printf("Hesabinizda yeterli bakiye yok!");
	}
	return hesaptakiBakiye;
}

// ATM SISTEMI
void main() {
	bool kartTakiliMi = true;
	float hesaptakiBakiye = 200;
	float cekilecekPara, yatirilacakPara;
	int sifre = 5555;
	int adminSifre = 0000;
	int secilenIslem, girilenSifre;
	int yapilacakIslemSayisi, i;
	char islemler[] = {"PARA YATIRMA"};
	
	// KART TAKILDIKTAN SONRASI GIBI DUSUNELIM
	if(kartTakiliMi) {
		printf("4 haneli PIN giriniz:");
		scanf("%d", &girilenSifre);
		
		if(girilenSifre == sifre || girilenSifre == adminSifre) {
			if(girilenSifre == adminSifre) {
				printf("ADMIN GIRISI YAPILDI!\n\n");
			} else {
				printf("GIRIS BASARILI!\n\n");
			}
			
			printf("Yapmak istediginiz islem sayisi:");
			scanf("%d", &yapilacakIslemSayisi);
			
			for(i = yapilacakIslemSayisi;i>=0;i--){
				if(i==0) {
					kartTakiliMi=false;
					printf("\n\nIslem sonlandi!");
				} else {
					printf("\nISLEM SECINIZ\n");
					printf("1-PARA YATIRMA\n");
					printf("2-PARA CEKME\n");
					printf("3-KART IADE\n");
					scanf("%d", &secilenIslem);
					
					if(secilenIslem == 1 && kartTakiliMi) {
						printf("\nHesabinizdaki mevcut bakiye %f\n", hesaptakiBakiye);
						printf("Yatirilacak para miktarini giriniz:");
						scanf("%f", &yatirilacakPara);
						hesaptakiBakiye = paraYatirma(yatirilacakPara, hesaptakiBakiye);
					} else if (secilenIslem == 2 && kartTakiliMi) {
						printf("\nHesabinizdaki mevcut bakiye %f\n", hesaptakiBakiye);
						printf("Cekilecek para miktarini giriniz:");
						scanf("%f", &cekilecekPara);
						hesaptakiBakiye = paraCek(cekilecekPara, hesaptakiBakiye);
					} else if(secilenIslem == 3 && kartTakiliMi) {
						kartTakiliMi = false;
						printf("\nKart iadesi yapildi.\n");
					} else {
						if(kartTakiliMi) {
							printf("\nHatali islem girisi yapildi!");
						} else {
							printf("\nIslem yapabilmek icin kartinizi takiniz.\n");
							printf("Kartiniz takilsin mi?(E/H):");
							char girilenHarf;
							scanf(" %c", &girilenHarf);						
							if(girilenHarf == 'e' || girilenHarf == 'E') {
								kartTakiliMi = true;
								i++;
								printf("\nKartiniz takildi!\n");
							} else {
								kartTakiliMi = false;
							}
						}
					}
				}
			}
		} else {
			printf("\nGirilen sifre hatali! Tekrar deneyiniz.");
		}
	} else {
		printf("\nIslem yapabilmek icin kartinizi takiniz.\n");
	}
}


