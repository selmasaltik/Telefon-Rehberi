#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
typedef struct
{
    char Isim[50];
    int Yas;
    float Maas;
} personelBilgi;

void menuHazirla()
{

        printf("\n*************************************************************\n");
        printf("*                 ----------MENU-----------                 * \n");
        printf("*   1-Kayit Ekle:                                           * \n");
        printf("*   2-Listele:                                              * \n");
        printf("*   3-Duzenle:                                              * \n");
        printf("*   4-Sil:                                                  * \n");
        printf("*   5-Cikis:                                                * \n");
        printf("*                                                           * \n");
        printf("************************************************************* \n");
}

void KayitEkle()
{
    personelBilgi yeniKayit;
    FILE *per.dat;
    int kontrol=0;
    if((fp=fopen("Personelrehber.txt","a+"))==NULL)
    {
        printf("Hata!");
        exit(1);
    }
    printf("\nIsim: ");
            scanf("%s", &pBilgi.Isim);
            printf("Yas: ");
            scanf("%d", &pBilgi.Yas);
            printf("Maas: ");
            scanf("%f", &pBilgi.Maas);
            printf("\nYeni kayit icin y yoksa n <y/n>: ");
            scanf("%c",&cevap);
    if((fwrite(&yeniKayit,sizeof(yeniKayit),1,per.dat)) !=1)
    {
        printf("Hata!");
        exit(1);
    }
    fclose(per.dat));
}

void Listele()
{
    FILE *per.dat;
    personelBilgi aktifKayit;
    if((fp=fopen("Personelrehber.txt","r"))==NULL)
    {
        return -1;

    }
    while(!feof(per.dat))
    {
        if((fread(&aktifKayit,sizeof(aktifKayit),1,per.dat)) !=1)
        {
            return -1;
        }

        printf("\nIsim:%s\t",aktifKayit.isim);
        printf("Yas: %f\t\t",aktifKayit.Maas);
        printf("Maas:%d\t\t",aktifKayit.Yas);
    }

    fclose(per.dat);
}

void ikay()
{
    telephone kayit3;
    char isim[100];
    yedek yedek1;
    int i,j,a;
    FILE *fp;
    if((fp=fopen("Telefonrehber.txt","r"))==NULL)
    {
        return -1;
    }
    printf("\n Aranacak kayidin ismini giriniz: ");
    scanf("%s",isim);
    a = strlen(isim);
     while(fread(&kayit3,sizeof(kayit3),1,fp)==1)
    {
      for(i=0; i<strlen(kayit3.isim); i++)
        {
             for(j=0; j<a; j++)
            {
                yedek1.isim[j] = kayit3.isim[i] ;
                i++;

            }
            i -= a;
        if(strcmp(isim,yedek1.isim)==0)
            printf("\nIsim: %s\t Kod: %d\t Telefon: %d\n\n",kayit3.isim,kayit3.kod,kayit3.numara);
    }
    }

    fclose(fp);
}
void kayitsil()
{
    telephone kayit4;
    char metin,E;
    long int kod;
    FILE *fp,*yeni;
    if((fp=fopen("Telefonrehber.txt","r"))==NULL)
    {
        return -1;
    }
    if((yeni=fopen("Telefonrehber2.txt","w"))==NULL)
    {
        return -1;
    }
    printf("\n Silinecek kayidin kodunu giriniz: ");
    scanf("%ld",&kod);

    while(fread(&kayit4,sizeof(kayit4),1,fp) ==1)
    {

        if(kayit4.kod != kod)
        {
            fwrite(&kayit4,sizeof(telephone),1,yeni);
        }
    }
    fclose(fp);
    fclose(yeni);
    if((yeni=fopen("Telefonrehber.txt","w"))==NULL)
    {
        return -1;
    }
    if((fp=fopen("Telefonrehber2.txt","r"))==NULL)
    {
        return -1;
    }
    while(fread(&kayit4,sizeof(kayit4),1,fp) ==1)
    {
        fwrite(&kayit4,sizeof(telephone),1,yeni);
    }

    fclose(fp);
    fclose(yeni);

}

int main()
{
    setlocale(LC_ALL,"Turkish");
    char secim='0';
    menuHazirla();
    printf("\n Secimin:");
    do
    {

        secim=putchar(getchar());
        switch (secim)
        {
        case'1':
            telefonEkle();
            break;
        case'2':
            telefonlariListele();
            break;
        case'3':
            kayitduzenle();
            break;
        case'4':
            nkayitbul();
            break;
        case'5':
            ikayitbul();
            break;
        case'6':
            kayitsil();
            break;
        case'7':
            printf("\n Bizi tercih ettiginiz icin tesekkurler:");
            return 0;
            break;
        default:
            printf("\n Lutfen 1-7 arasinda secim yap:");
        }
    }
    while (secim!=7);
    return 0;
}
