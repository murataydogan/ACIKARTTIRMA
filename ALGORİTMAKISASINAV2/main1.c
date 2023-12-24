#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct {
    int teklifveren_no;
    double teklif;
} Teklif;

typedef struct {
    int teklifveren_sayisi;
    Teklif *teklifler;
} Arttirma;

double odemeyi_hesapla(Arttirma a, int kazanan_no) {
    double odeme = 0.0;
    double en_yuksek_teklif = -1.0;

    //en yuksek teklifi buluyoruz.
    int i ;
	for ( i = 0; i < a.teklifveren_sayisi; i++) {
        if (a.teklifler[i].teklif > en_yuksek_teklif) {
            en_yuksek_teklif = a.teklifler[i].teklif;
        }
    }

    //yapilacak odemeyi hesapliyoruz.
    
	for ( i = 0; i < a.teklifveren_sayisi; i++) {
        if (i != kazanan_no) {
            odeme = (en_yuksek_teklif );
        }
    }
    return odeme;
}

void acikarttirma(Arttirma a) {
    double enyuksek_teklif = -1.0;
    int kazanan_no = -1;
    int i ;
	//en yuksek teklifi veren kullanicinin numarasini belirliyoruz.
	for ( i = 0; i < a.teklifveren_sayisi; i++) {
        if (a.teklifler[i].teklif > enyuksek_teklif) {
            enyuksek_teklif = a.teklifler[i].teklif;
            kazanan_no = i;
        }
    }
    printf("Kazanan teklif sahibi= %d\n", a.teklifler[kazanan_no].teklifveren_no);
    double odeme = odemeyi_hesapla(a, kazanan_no);
    printf("Odeme= %.2lf\n", odeme);
}

int main() {
    Arttirma arttirma;

    //arttirmanin basýnda kullanicidan girilicek teklif sayisini aliyoruz.
    printf("Teklif sayisini girin: ");
    scanf("%d", &arttirma.teklifveren_sayisi);

    // Teklif dizisinin boyutunu olcup arttirma.teklifveren_sayisi boyutu ile carparak arttirma.teklifler adlý dizinin kodumuz bitene kadar kullanýlmasýný saglar.
    //malloc komutu bellekte ihtiyac duyulan boyuyu belirler.
    arttirma.teklifler = (Teklif *)malloc(arttirma.teklifveren_sayisi * sizeof(Teklif));

    //kullanicidan teklifleri alýyoruz.
    int i ;
	for ( i = 0; i < arttirma.teklifveren_sayisi; i++) {
        printf("Teklifveren %d'in teklifini girin: ", i + 1);
        
		scanf(" %lf" , &arttirma.teklifler[i].teklif);
        arttirma.teklifler[i].teklifveren_no=i+1;   
 }
    

    //acikarttirma fonskiyonunu cagiriyoruz.
    acikarttirma(arttirma);

    //arttirma.teklifler icin bellekte acilan yerin bosaltilmasini saglar.
    free(arttirma.teklifler);

    return 0;
}














