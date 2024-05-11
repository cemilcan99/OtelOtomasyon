#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
FILE *dosya,*yedek;
struct musteri{
 char ad[100];
 char soyad[100];
 long long int kimlik,tel;
 int kgun;
 };
struct musteri kisi;
void musteriGirisi(); 
void musteriGoruntule();
void musteriSilme();
void musteriArama();
void musteriDegistirme();
int main(){
	char secim;
do {
    system("cls");
    printf("Cemil Can Almaz \n\n\n");
    printf("***************************************\n");
    printf("*          Garden Otel                *\n");
    printf("***************************************\n");
    printf("*            MENU                     *\n");
    printf("***************************************\n");
    printf("* 1. Rezervasyon Kayit                *\n");
    printf("* 2. Musteri Bilgileri                *\n");
    printf("* 3. Musteri Kayit Silme              *\n");
    printf("* 4. Musteri Bilgilerini Arama        *\n");
    printf("* 5. Musteri Bilgilerini Degistirme   *\n");
    printf("* 6. Sistemden Cikis                  *\n");
    printf("***************************************\n");
    printf("Lutfen islemi seciniz: \n");
    
    

 secim = getch();
        switch (secim) {
 case '1':{ 
 system("cls");
 musteriGirisi();
  break;
 }
 case '2':{ 
 system("cls");
 musteriGoruntule();
  break;
 }
 case '3':{ 
 system("cls");
 musteriSilme();
 
  break;
 }
 case '4':{ 
 system("cls");
 musteriArama();
  break;
 }
 case '5':{ 
 system("cls");
 musteriDegistirme();
  break;
 }
 case '6':{ 
 printf("\nCikis Yapildi...");
  return 0;
  break;
 }
 default:{
  printf("Hatali Giris");
  
 }
}
}while(1);

}
void musteriGirisi(){
 int i=0;
 dosya=fopen("Otel.txt","a+"); 
 if(dosya == NULL){
  puts("Dosya acilamadi.");
  exit(1);}
 puts("\nMusteri bilgilerini girin: ");
 
 
 do{ 
  i++;
  fflush(stdin);
  printf("%d.Musterinin Adi : ",i);
  gets(kisi.ad);
  printf("%d.Musterinin Soyadi : ",i);
  gets(kisi.soyad);
  printf("%d.Musterinin Kimlik Numarasi : ",i);
  scanf("%lld",&kisi.kimlik);
  printf("%d.Musterinin Telefon Numarasi : ",i);
  scanf("%lld",&kisi.tel);
  printf("%d.Musterinin Kalacagi gun sayisi: ",i);
  scanf("%d",&kisi.kgun);
  printf("\n");
  
  
  fprintf(dosya,"%s %s %lld %lld %d\n",kisi.ad,kisi.soyad,kisi.kimlik,kisi.tel,kisi.kgun);
  puts("Yeni bir kayit icin bir tusa, cikmak icin ESC tusuna basiniz.");
 }while(getch()!=27);
 fclose(dosya);
 printf("\nBilgiler kaydedildi devam etmek icin bir tusa basin ...");
 getch();
}
void musteriGoruntule(){
dosya = fopen("Otel.txt","r"); 
 if(dosya == NULL){
  printf("Dosya acilamadi.");
  exit(1);
   
 }
 puts(" -----------------------------------------Otelimizde Bulunan Aktif Musteri Listesi -------------------------------------");
 while(!feof(dosya)){ 
  fflush(stdout);
  fscanf(dosya,"%s %s %lld %lld %d\n",kisi.ad,kisi.soyad,&kisi.kimlik,&kisi.tel,&kisi.kgun); 
   
  printf("\n Musteri Adi:%s\n Musteri Soyadi:%s\n Musteri Kimlik:%lld\n Musteri Tel:%lld\n Kalacagi gun:%d\n -------------------------------------------------------",kisi.ad,kisi.soyad,kisi.kimlik,kisi.tel,kisi.kgun);
   
 }
  
 fclose(dosya);
 printf("\nBilgiler listelendi devam etmek icin bir tusa basin ...");
 getch();
}
 void musteriSilme(){
 long long int tc,durum=0;
 printf("\nSilinecek musterini kimlik numarasini giriniz : ");
 scanf("%lld",&tc);
 dosya = fopen("Otel.txt","r");
 yedek = fopen("yedek.txt","w");
 if(dosya == NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
 while(!feof(dosya)){
  fscanf(dosya,"%s %s %lld %lld %d\n",kisi.ad,kisi.soyad,&kisi.kimlik,&kisi.tel,&kisi.kgun); 
    if(tc != kisi.kimlik){ 
     fprintf(yedek,"%s %s %lld %lld %d\n",kisi.ad,kisi.soyad,kisi.kimlik,kisi.tel,kisi.kgun);
     
    }
    else durum=1;
 }
 fclose(dosya);
 fclose(yedek);
 if(durum == 1){
  remove("Otel.txt"); 
  rename("yedek.txt","Otel.txt");
  puts("Silme islemi tamamlandi devam etmek icin bir tusa basin");
 } 
 else{ 
  remove("yedek.txt"); 
  printf("%lld numarasinda musteri bulunamadi devam etmek icin bir tusa basin ...",tc);
 }
 fflush(stdin);
 getch();
}
void musteriArama(){ 
 long long int kim;
 int durum=0;
 fflush(stdin);
 printf("\nKimligi Giriniz: ");
 scanf("%lld",&kim);
 dosya=fopen("Otel.txt","r");
 if( dosya==NULL ){
  puts("Dosya acilamadi");
  exit(1);
 }
  while(!feof(dosya)){
   fscanf(dosya,"%s %s %lld %lld %d\n",kisi.ad,kisi.soyad,&kisi.kimlik,&kisi.tel,&kisi.kgun); 
   if(kisi.kimlik== kim){ 
    printf("\nAdi: %s\nSoyadi: %s\nKimlik:%lld\nTel:%lld\nKalacagi gun sayisi:%d\nDevam etmek icin bir tusa basiniz...",kisi.ad,kisi.soyad,kisi.kimlik,kisi.tel,kisi.kgun);
    ;
   }
  }
  fclose(dosya);
  if(kisi.kimlik !=kim){ 
   puts("Musteri bulunamadi devam etmek icin bir tusa basiniz...");
  }
 getch();
 
}
void musteriDegistirme(){
 long long int tcno,durum=0;
 printf("\nBilgilerini degistireceginiz musterinin kimlik numarasini giriniz: ");
 scanf("%lld",&tcno);
 dosya = fopen("Otel.txt","r");
 yedek = fopen("yedek.txt","w");
 if(dosya == NULL){
  puts("Dosya acilamadi");
  exit(1);
 }
 while(!feof(dosya)){
  fscanf(dosya,"%s %s %lld %lld %d\n",kisi.ad,kisi.soyad,&kisi.kimlik,&kisi.tel,&kisi.kgun); 
  if(tcno != kisi.kimlik){
   fprintf(yedek,"%s %s %lld %lld %d\n",kisi.ad,kisi.soyad,kisi.kimlik,kisi.tel,kisi.kgun);
  }
  else{
   fflush(stdin);
   printf("Musterinin Adi : ");
   gets(kisi.ad);
   printf("Musterinin Soyadi : ");
   gets(kisi.soyad);
   printf("Musterinin Kimlik Numarasi : ");
   scanf("%lld",&kisi.kimlik);
   printf("Musterinin Telefon Numarasi : ");
   scanf("%lld",&kisi.tel);
   printf("Musterinin Kalacagi gun sayisi: ");
   scanf("%d",&kisi.kgun);
  
      printf("\n");
      fprintf(yedek,"%s %s %lld %lld %d",kisi.ad,kisi.soyad,kisi.kimlik,kisi.tel,kisi.kgun); 
      durum=1; 
  }
 }
 fclose(dosya);
 fclose(yedek);
 if(durum == 1){ 
  remove("Otel.txt");
  rename("yedek.txt","Otel.txt");
  puts("Musteri bilgileri degistirildi devam etmek icin bir tusa basin...");
 }
 else{
  remove("yedek.txt");
  puts("Ilgili musteri bulunamadi devam etmek icin bir tusa basin...");
 }
 
 getch();
}
