#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//FONKSÝYONLAR
void firma_girisi();
void add_otobus();
void sefer_info();
void sefer_koltuk();
void musteri_girisi();
void list_sefer();
void sefer_rez();
void show_rez();
void cikis();

int a,b;

int main()
{
    char i;
    system("cls");
    printf("\t\tHFTTF ULASIM");
    printf("\n\n   ANA MENU\n");                          //ANA MENU
    printf("1--> FIRMA GIRISI\n");
    printf("2--> MUSTERI GIRISI\n");
    printf("3--> CIKIS\n\n");
    hatali_giris:
    printf("\nLutfen bir giris yapiniz:> ");
    scanf(" %c",&i);
    switch(i)
    {
    case '1':                             //ANA MENU OPSÝYONLARI
        firma_girisi();
        break;
    case '2':
        musteri_girisi();
        break;
    case '3':
        cikis();
        break;
        default:printf("\nHatali giris yaptiniz!!\n");
        goto hatali_giris;
        break;
    }
    return 0;
}

void firma_girisi()
{
    char firma_secim;
    system("cls");
    printf("\nFIRMA GIRISI\n\n");
    printf("1--> Otobus Ekle\n");
    printf("2--> Sefer Bilgisi Ekle\n");
	printf("3--> Sefer/Koltuk Bilgisi\n");
	printf("4--> Bir Ust Menuye Don\n");
    firma_hata:
    printf("\nLutfen bir giris yapiniz:> ");
    scanf(" %c",&firma_secim);
    switch(firma_secim)
    {
    case '1':
        add_otobus();
        break;
    case '2':
        sefer_info();
        break;
    case '3':
        sefer_koltuk();
        break;
    case '4':
        main();
        break;
        default:printf("\nGecersiz deger girdiniz.\n");
        goto firma_hata;
        break;

}
}
void add_otobus()
{
   FILE * busekle;
   busekle = fopen("1busekle.txt", "a+");
   int kpst,personel,oto_no,orta,i,j,otogir;
   char cins[50],model[50];int otoveri[30][3];
   system("cls");

   printf("Kayit ettirmek istediginiz otobus adetini giriniz: ");
   scanf("%d",&otogir);
   printf("\nKaydettirdiginiz otobuslere sirasiyla atamak istediginiz kapasiteyi ve modeli giriniz.\n");

for(oto_no=0;oto_no<otogir;oto_no++)
{
  printf("Kapasite: ");
  scanf("%d",&kpst);
if(kpst>30)
{
   strcpy(cins, "uzun yol");
}
else if (kpst<30)
{
    strcpy(cins, "kisa yol");
}
else if(kpst=30)
{
    {printf("30 kapasiteli otobus icin personel sayisi secin (2 veya 3): ");
    scanf("%d",&orta);}
    if(orta==2)
        strcpy(cins, "kisa yol");
    else if(orta==3)
        strcpy(cins, "uzun yol");
}
if(strcmp(cins,"uzun yol"))
    {personel=2;
    printf("\nPersonel sayisi 2 olarak atanmistir.\n");}
    else
    {personel=3;
    printf("\nPersonel sayisi 3 olarak atanmistir.\n");}

  otoveri[oto_no][0]=oto_no+1;
  otoveri[oto_no][1]=kpst;
  otoveri[oto_no][2]=personel;
  printf("Otobus Modeli: ");
  scanf("%s",&model);
}

for(i=0;i<otogir;i++)
{
    for(j=0;j<3;j++)
    {
        fprintf(busekle," %d        ",otoveri[i][j]);
        printf(" %d        ",otoveri[i][j]);
    }
    printf("\n");
    fprintf(busekle,"\n");
}
printf("\nDevam etmek icin bir tusa basiniz:>");
getch();
fclose(busekle);
system("cls");
firma_girisi();
}


void sefer_info()
{
FILE * seferbilgi, * busekle, * eklebus;
 busekle = fopen("1busekle.txt","r");
 seferbilgi = fopen("sefbil.txt", "a+");
 eklebus = fopen("1busekle.txt", "r");
int saat,dakika,hasilat,kpst,tutar,uzunluk,onlysaat,oto_no,busno,personel,bussecim,kapasite,person;
char sehir1[50];char sehir2[50];char sefno[100];
float tahmin,baslangic,varis;

system("cls");
//RANDOM HEX ATAMASI
char str[] = "0123456789ABCDEF";
printf("Sefer Numarasi: ");

    srand((unsigned int) time(0) + getpid());
    uzunluk = 4;
    printf("69");
    while(uzunluk--)
    {
        putchar(str[rand() % 16]);
        srand(rand());
     }
     printf("\nYukaridaki sefer numarasini giriniz: ");
     scanf("%s",&sefno);
// HEX ATAMASI BÝTTÝ

     while(fscanf(busekle,"%d %d %d",&oto_no,&kpst,&personel)!=EOF){printf("%d\n",oto_no);}
     printf("\nyukarida bulunan otobus numaralarindan istediginizi secin:\n");
      scanf("%d",&bussecim);
     while(fscanf(eklebus,"%d %d %d",&busno,&kpst,&personel)!=EOF){
        if(bussecim==busno){
            printf("Sectiginiz otobusun bilgileri :\nOtobus Numarasi: %d Kapasite: %d Personel Sayisi: %d",bussecim,kpst,personel);
        }
     }
      printf("\n\nYukaridaki kapasite ve personel sayisini art arda girerek dogrulayiniz.\n\n\nKapasiteyi giriniz: ");
      scanf("%d",&kapasite);
      printf("\nPersonel Sayisini giriniz: ");
      scanf("%d",&person);
     uzunhata:
     printf("\nSectiginiz otobusun sefer baslangic saatini girin: ");                //ASAGIDAKI IF-ELSE, GÝRÝLEN SAATÝ OGRENCÝ NUMARAMLA DUZENLEMEK ICIN
     scanf("%d",&saat);
     dakika = saat%100;
if(dakika!=9)
    {printf("Bu saatte sefer gerceklesemez.\n");
    onlysaat = saat/100 - dakika/100;
    printf("Sefer saatiniz %d09 olarak guncellendi.\n",onlysaat);
    baslangic=(saat-dakika)+ 9;
    }
else{
    baslangic=saat;
}
printf("Varis Saati: ");
scanf("%f",&varis);
if(baslangic>varis){
tahmin = 24 - abs((varis/100) - (baslangic/100));
printf("\nSefer yaklasik %.1f saat surecektir\n",tahmin);}
else{
    tahmin = varis/100 - baslangic/100;
    printf("\nSefer yaklasik %.1f saat surecektir\n",tahmin);
}
if((tahmin>4 && kapasite<30)||(tahmin>4 && kapasite==30 && person==2))
    {printf("Kisa yol otobusuyle 4 saatten uzun yolculuk yapilamaz..\nTekrar saat giriniz.");goto uzunhata;}
printf("\nSefer baslangic sehri: ");
scanf(" %s",&sehir1);

printf("\nVarilacak Sehir: ");
scanf(" %s",&sehir2);

printf("\nToplam Hasilat: ");
scanf("%d",&hasilat);

tutar = hasilat/kapasite;
printf("\nKisi basi fiyat: %d",tutar);
fprintf(seferbilgi, "%s %d %d %d %.0f %.0f %s %s %d %d \n",sefno,bussecim,kapasite,person,baslangic,varis,sehir1,sehir2,hasilat,tutar);

printf("\nDevam etmek icin bir tusa basiniz:>");
getch();

fclose(seferbilgi);fclose(busekle);fclose(eklebus);
firma_girisi();

}

void sefer_koltuk()
{
FILE * seferbilgi, * busekle, * damn;
 busekle = fopen("1busekle.txt","r");
 seferbilgi = fopen("sefbil.txt", "r");
 damn = fopen("sefbil.txt", "r" );
 system("cls");

 int oto_no,baslangic,varis,kpst,tutar,hasilat,i,j,k,bussecim,kapasite,person;
 char sehir1[50];char sehir2[50];char hexsecim[100];char sefno[100];char nosef[100];


 while (fscanf(seferbilgi,"%s %d %d %d %d %d %s %s %d %d",&sefno,&bussecim,&kapasite,&person,&baslangic,&varis,&sehir1,&sehir2,&hasilat,&tutar)!=EOF){printf("%s\n",sefno);}
  printf("\n\nYukarida bulunan sefer numaralarindan sectiginiz bir tanesini giriniz.\n");
  scanf("%s",hexsecim);
 while (fscanf(damn,"%s %d %d %d %d %d %s %s %d %d",&nosef,&bussecim,&kapasite,&person,&baslangic,&varis,&sehir1,&sehir2,&hasilat,&tutar)!=EOF)
 {
        if (strcmp(hexsecim,nosef)==0)
        {{
            system("cls");
            printf("Sefer NO: %s \t Otobus NO: %d \t Kapasite: %d \t Personel Sayisi: %d \nKalkis: %d \t Varis: %d \t Kalkis Sehri: %s \t Varis Sehri: %s   Hasilat: %d -- Kisi Basi Tutar: %d \n\n\n",nosef,bussecim,kapasite,person,baslangic,varis,sehir1,sehir2,hasilat,tutar);
        }
              printf("        1        2        3        4\n");
              for(i=0;i<=(kapasite/4);i++){
              if(i!=kapasite/4)
              printf("%2d.",i+1);
              else if(i==kapasite/4 && (kapasite%4)!=0)
                              printf("%2d.",i+1);
              for(j=0;j<4;j++)
              {if(i<=(kapasite/4)-1)
               printf("  [%2d,%2d]",i+1,j+1);
               else
                {for(i==kapasite/4;k<(kapasite%4);k++)
                    printf("  [%2d,%2d]",i+1,k+1);
               }}
               printf("\n");}}}

 fclose(seferbilgi);fclose(busekle);fclose(damn);
 printf("\nGeri donmek icin bir tusa basin:>");
 getch();
 firma_girisi();
}
void musteri_girisi()
{
    system("cls");
    char b;
    printf("\nMUSTERI GIRISI\n\n");
    printf("1--> Seferleri Listele\n");
    printf("2--> Sefer Rezervasyonu Yap\n");
	printf("3--> Bir Ust Menuye Don\n");
	printf("4--> Rezervasyon Goster\n");
	must_hata:
    printf("\nLutfen bir giris yapiniz:> ");
    scanf(" %c",&b);
    switch(b)
    {
    case '1':
        list_sefer();
        break;
    case '2':
        sefer_rez();
        break;
    case '3':
        main();
        break;
    case '4':
        show_rez();
        break;
        default:printf("\nGecersiz deger girdiniz.\n");
        goto must_hata;
        break;
}}
void list_sefer()
{
   FILE * seferbilgi, * damn;
 seferbilgi = fopen("sefbil.txt", "r");
 damn = fopen("sefbil.txt", "r" );
 system("cls");
 int baslangic,varis,kpst,tutar,bussecim,kapasite,person,hasilat;
 char sehir1[50];char sehir2[50];char hexsecim[50];char sefno[100];char nosef[100];

 while (fscanf(damn,"%s %d %d %d %d %d %s %s %d %d",&nosef,&bussecim,&kapasite,&person,&baslangic,&varis,&sehir1,&sehir2,&hasilat,&tutar)!=EOF)
 {
printf("Sefer NO: %s \t Otobus NO: %d \t Kapasite: %d \t Personel Sayisi: %d \nKalkis: %d \t Varis: %d \t Kalkis Sehri: %s \t Varis Sehri: %s \t Kisi Basi Tutar: %d \n\n\n",nosef,bussecim,kapasite,person,baslangic,varis,sehir1,sehir2,tutar);
}
fclose(seferbilgi);fclose(damn);
printf("\n\nMenuye donmek icin bir tusa basiniz.\n");
getch();
musteri_girisi();
}

void sefer_rez()
{
FILE * seferbilgi, * busekle, * tuck, * rezerve, * dolu;
 busekle = fopen("1busekle.txt","r");
 seferbilgi = fopen("sefbil.txt", "r");
 tuck = fopen("sefbil.txt", "r" );
 rezerve = fopen("rezervasyon.txt", "a+");
 dolu = fopen("doluluk.txt", "a+");
 system("cls");

 int oto_no,baslangic,varis,kpst,tutar,hasilat,i,j,k,bussecim,kapasite,person,a,b,deneme;
 char sehir1[50];char sehir2[50];char hexsecim[100];char sefno[100];char nosef[100];char isim[40];char soy[40];char onay;char rezno[10];
 char ilksehir[50];char sonsehir[50];int kalk,var,fiat,kolpst;

 while (fscanf(seferbilgi,"%s %d %d %d %d %d %s %s %d %d",&sefno,&bussecim,&kapasite,&person,&baslangic,&varis,&sehir1,&sehir2,&hasilat,&tutar)!=EOF){printf("%s\n",sefno);}
  printf("\n\nRezervasyon yapmak istediginiz sefer numarasini giriniz.\n");
  scanf(" %s",&hexsecim);
 while (fscanf(tuck,"%s %d %d %d %d %d %s %s %d %d",&nosef,&bussecim,&kapasite,&person,&kalk,&var,&ilksehir,&sonsehir,&hasilat,&fiat)!=EOF)
 {
        if (strcmp(hexsecim,nosef)==0)
        {printf("%s %d %d %d %d %d %s %s %d %d\n\n",hexsecim,bussecim,kapasite,person,kalk,var,ilksehir,sonsehir,hasilat,fiat);kolpst=kapasite;system("cls");
    fprintf(rezerve,"Sefer Numarasi: %s   Kalkis: %d   Varis: %d   Nereden: %s  Nereye: %s  Tutar: %d",hexsecim,kalk,var,ilksehir,sonsehir,fiat);

        }}
              printf("              OTOBUSUN DURUMU\n\n");
              printf("        1        2        3        4\n");
              for(i=0;i<=(kolpst/4);i++){
              if(i!=(kolpst/4))
              printf("%2d.",i+1);
              else if(i==kolpst/4 && (kolpst%4)!=0)
                printf("%2d.",i+1);
              for(j=0;j<4;j++)
              {if(i<=(kolpst/4)-1)
               printf("  [%2d,%2d]",i+1,j+1);
               else
                {for(i==kolpst/4;k<(kolpst%4);k++)
                    printf("  [%2d,%2d]",i+1,k+1);
               }}
               printf("\n");}


        printf("\n\nLutfen isminizi giriniz: ");
        scanf("%s",&isim);
        printf("\nLutfen soyadinizi giriniz: ");
        scanf("%s",&soy);
        printf("\n\nAlttaki koltuklar secilmistir.\n---------------------------------------------------------------\n");
        while(fscanf(dolu," (%d,%d) ",&a,&b)!=EOF){
        printf("(%d,%d)",a,b);}
        printf("\n---------------------------------------------------------------");
        printf("\n\nSecilmis koltuklar haricinde dilediginiz koltugun konumunu belirtiniz.\nOrnegin yatayda 6, dikeyde 3 ise bu koltugun konumu (6,3)dur.\n\n");
        printf("Yataydaki konumu girin:> ");
        scanf("%d",&a);
        printf("\nDikeydeki konumu girin:> ");
        scanf("%d",&b);
        fprintf(dolu," (%d,%d) ",a,b);

        system("cls");

    printf("---------------------------------------------------------------\n");
	printf("Bilgilerinizi Gozden Gecirin.\n");
	printf("---------------------------------------------------------------\n\n");
	printf("AD:\t%s",isim);
	printf("\nSoyad:\t%s",soy);
	printf("\nSefer Numarasi:\t%s",hexsecim);
	printf("\nSecilen Koltugun Konumu: (%d,%d)",a,b);
	printf("\n---------------------------------------------------------------\n\n");

    printf("Bileti Onayla (e/h):> ");
	start:
	scanf(" %c",&onay);
	if(onay == 'e')
	{
	    printf("\nBilgileriniz onaylandi!\n---------------------------------------------------------------\n\n");

        char str[] = "0123456789ABCDEFKLMN";

        srand((unsigned int) time(0) + getpid());
        deneme = 8;

         while(deneme--)
    {
        putchar(str[rand() % 20]);
        srand(rand());
     }

        printf("\n\nYukaridaki rezervasyon numaranizi girip kaydedin.\nBu numarayi unutmamaya dikkat ediniz!!\n");
        scanf("%s",&rezno);
        fprintf(rezerve,"  %s AD: %s   SOYAD: %s   Konum: (%d,%d) \n",rezno,isim,soy,a,b);
		printf("\n\n=====================");
		printf("\n Rezervasyon tamamlandi\n");
		printf("=====================");
		printf("\n\nUst menuye donmek icin bir tusa basiniz.\n");fclose(rezerve);fclose(seferbilgi);fclose(busekle);fclose(tuck);fclose(dolu);
		getch();musteri_girisi();
	}
	else
	{
		if(onay=='h'){
			printf("\nRezervasyon tamamlanmadi! Bir ust menuye donmek icin bir tusa basiniz.");
			getch();musteri_girisi();
		}
		else
		{
			printf("\nGecersiz giris. Bir daha giriniz-----> ");
			goto start;
		}}}

void show_rez()
{
FILE * rezerve, *rezermeve;
rezerve = fopen("rezervasyon.txt", "r");
rezermeve = fopen("rezervasyon.txt", "r");

int oto_no,baslangic,varis,kpst,tutar,hasilat,i,j,k,bussecim,kapasite,person,a,b,deneme;int kalk,var,fiat;char ilksehir[50];char sonsehir[50];
char sehir1[50];char sehir2[50];char hexsecim[50];char sefno[100];char nosef[100];char isim[40];char soy[40];char onay;char rezno[10];char rezerno[10];
system("cls");
printf("Lutfen size ait rezervasyon numaranizi girin\n");
scanf(" %s",&rezerno);

while(fscanf(rezermeve,"Sefer Numarasi: %s   Kalkis: %d   Varis: %d   Nereden: %s  Nereye: %s  Tutar: %d  %s AD: %s   SOYAD: %s   Konum: (%d,%d) \n",&hexsecim,&kalk,&var,&ilksehir,&sonsehir,&fiat,&rezno,&isim,&soy,&a,&b)!=EOF)
{
    if(strcmp(rezerno,rezno)==0)
        {printf("\n\nSefer Numarasi: %s   Kalkis: %d   Varis: %d   Nereden: %s  Nereye: %s  Tutar: %d \n%s AD: %s   SOYAD: %s   Konum: (%d,%d) \n",hexsecim,kalk,var,ilksehir,sonsehir,fiat,rezno,isim,soy,a,b);}
    }

           printf("\nUst menuye donmek icin bir tusa basiniz.\n");
           getch();musteri_girisi();


fclose(rezerve);fclose(rezermeve);
}
void cikis()
{
    printf("\nTesekkurler, yine bekleriz.\n\n");
}







