#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include <time.h>
#include "validasi.c"

#define MAX_VILLA 10
#define MAX_BARIS 100

char nama[30], nohp[15], username[20], password[20], konfirmasi[10], uang_dibayar[10];
char usernameadmin[20], passwordadmin[20], useron[100];
int umur, upd, harga_per_malam;
int halaman = 0, halamanuser = 0, halamanadmin = 0, halamanmenu = 0, halamandatavilla = 0;
int cek = 0, cekuser = 0, cekadmin = 0, cekmenu = 0, cekdatavilla = 0;
int  selectal = 0, s_update = 0, s_delete = 0;
int pilihan[10];

typedef struct {
    char namavilla[50];
    int harga_per_malam;
    
} Villa;

Villa villa_list[MAX_VILLA];
int villa = 0;


                        ///////////////////////////////////////////////////
                        ////Fungsi untuk mendapatkan timestamp saat ini////
                        ///////////////////////////////////////////////////

void waktu(char *timestamp_str, time_t bataswaktu) {
    struct tm *waktu = localtime(&bataswaktu);
    strftime(timestamp_str, 100, "%Y-%m-%d %H:%M:%S", waktu);
}

void koor(int x,int y){
    COORD koor;
    koor.X=x;
    koor.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),koor);
}

int text = 7, background = 0;
int teks_color, teks_background;

void textcolor(int new_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), new_color + background * 16);
    text = new_color;
}
void backgroundcolor(int new_color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text + new_color * 16);
    background = new_color;
}

void setcolor(int text, int background){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), background * 16 + text);
}

void warna(){
    textcolor(0);
    backgroundcolor(15);
}

void reset(){
    textcolor(4);
    backgroundcolor(15);
}

void bayarsukses(){
    textcolor(2);
}

void bingkai(){
    textcolor(4);
    backgroundcolor(15);
    int a=174,b=43;
    char s=219;
            for(int i=0; i<b; i++){
                koor(0,0+i);
                for(int j=0; j < a; j++){
                if(i==0||i==b-1||j==0||j==a-1){
                    printf("%c",219);
                }else
                printf(" ");
                }
            }
}

void bingkaibooking(){
    textcolor(4);
    backgroundcolor(15);
    int a=152,b=25;
    char s=219;
            for(int i=0; i<b; i++){
                koor(10,4+i);
                for(int j=0; j < a; j++){
                if(i==0||i==b-1||j==0||j==a-1){
                    printf("%c",219);
                }else
                printf(" ");
                }
            }
}

void bingkaihistory(){
    textcolor(4);
    backgroundcolor(15);
    int a=132,b=26;
    char s=219;
            for(int i=0; i<b; i++){
                koor(20,4+i);
                for(int j=0; j < a; j++){
                if(i==0||i==b-1||j==0||j==a-1){
                    printf("%c",219);
                }else
                printf(" ");
                }
            }
}

void gambar(){
    textcolor(4);

    koor(3, 32); printf("                _[]_                      "); Sleep(5);
    koor(3, 33); printf(" __[]___[]___[]/____\\_[]_                "); Sleep(5);
    koor(3, 34); printf("/______________|[][]|____\\               "); Sleep(5);
    koor(3, 35); printf("/______________|[][]|____\\               "); Sleep(5);
    koor(3, 36); printf("|[][]|[][]|[][]|[][]|[][]|__[]_           "); Sleep(5);
    koor(3, 37); printf("|  /\\|/\\  |  /\\|  /\\|/\\  |_____\\    "); Sleep(5);
    koor(3, 38); printf("|[]|||||[]|[]|||[]|||||[]|[_]|||          "); Sleep(5);
    koor(3, 39); printf("|[]|||||[]|[]|||[]|||||[]|[_]|||          "); Sleep(5);
    koor(3, 40); printf("===================================       "); Sleep(5);
    koor(3, 41); printf("=========================================="); Sleep(5);

    koor(130,32); printf("                _[]_                      "); Sleep(5);
    koor(130,33); printf(" __[]___[]___[]/____\\_[]_                "); Sleep(5);
    koor(130,34); printf("/______________|[][]|____\\               "); Sleep(5);
    koor(130,35); printf("/______________|[][]|____\\               "); Sleep(5);
    koor(130,36); printf("|[][]|[][]|[][]|[][]|[][]|__[]_           "); Sleep(5);
    koor(130,37); printf("|  /\\|/\\  |  /\\|  /\\|/\\  |_____\\    "); Sleep(5);
    koor(130,38); printf("|[]|||||[]|[]|||[]|||||[]|[_]|||          "); Sleep(5);
    koor(130,39); printf("|[]|||||[]|[]|||[]|||||[]|[_]|||          "); Sleep(5);
    koor(130,40); printf("===================================       "); Sleep(5);
    koor(130,41); printf("=========================================="); Sleep(5);
}

void teksloading() {
    textcolor(4);
    backgroundcolor(15);
    for (int i = 0; i < 16; i++)
    {
        setcolor(i,15);

    koor(3, 32); printf("                _[]_                      "); Sleep(5);
    koor(3, 33); printf(" __[]___[]___[]/____\\_[]_                "); Sleep(5);
    koor(3, 34); printf("/______________|[][]|____\\               "); Sleep(5);
    koor(3, 35); printf("/______________|[][]|____\\               "); Sleep(5);
    koor(3, 36); printf("|[][]|[][]|[][]|[][]|[][]|__[]_           "); Sleep(5);
    koor(3, 37); printf("|  /\\|/\\  |  /\\|  /\\|/\\  |_____\\    "); Sleep(5);
    koor(3, 38); printf("|[]|||||[]|[]|||[]|||||[]|[_]|||          "); Sleep(5);
    koor(3, 39); printf("|[]|||||[]|[]|||[]|||||[]|[_]|||          "); Sleep(5);
    koor(3, 40); printf("===================================       "); Sleep(5);
    koor(3, 41); printf("=========================================="); Sleep(5);

    koor(130,32); printf("                _[]_                      "); Sleep(5);
    koor(130,33); printf(" __[]___[]___[]/____\\_[]_                "); Sleep(5);
    koor(130,34); printf("/______________|[][]|____\\               "); Sleep(5);
    koor(130,35); printf("/______________|[][]|____\\               "); Sleep(5);
    koor(130,36); printf("|[][]|[][]|[][]|[][]|[][]|__[]_           "); Sleep(5);
    koor(130,37); printf("|  /\\|/\\  |  /\\|  /\\|/\\  |_____\\    "); Sleep(5);
    koor(130,38); printf("|[]|||||[]|[]|||[]|||||[]|[_]|||          "); Sleep(5);
    koor(130,39); printf("|[]|||||[]|[]|||[]|||||[]|[_]|||          "); Sleep(5);
    koor(130,40); printf("===================================       "); Sleep(5);
    koor(130,41); printf("=========================================="); Sleep(5);

    }
    textcolor(4);
    backgroundcolor(15);
    koor(75,30); printf("L  O  A  D  I  N  G");
}

void loading(){
    char q=222,  //blok setengah ▐ q
        r=223,  // kotak atas   ▀ r
        s=219,  //blok          █ s
        t=187,  //kanan atas    ╗ t
        u=188,  //kanan bawah   ╝ u
        v=186,  //lurus atas    ║ v
        x=205,  //lurus garis   ═ x
        w=201,  //kiri atas     ╔ w
        y=200,  //kiri bawah    ╚ y
        z=220;  //kotak bawah   ▄ z
         
    for (int j = 0; j < 70; j++){
    koor(49+j,31);
    printf("%c%c%c",x,x,x);
    koor(49+j,33);
    printf("%c%c%c",x,x,x);
    if (j == 0){
        koor(48,31); printf("%c",w);
        koor(48,32); printf("%c",v);
        koor(121,32);printf("%c",v);
        koor(48,33); printf("%c",y);
        koor(121,33);printf("%c",u);
        koor(121,31);printf("%c",t);
    }
    if(j==69){
        for (int i = 0; i < 36; i++){
                Sleep(100);
                koor(50+i*2, 32);
                printf("%c",s);
                koor(96,30);
                printf("%d%%",i*2+30);
            }
        }
    }
}

void garisjudul(){
    char z=220;  //kotak bawah   ▄ z
    for(int i = 0; i < 82;i++){
    koor(47+i,10); printf("%c",z);
    }
}

void welcome(){
   char a=191,
        b=218,
        c=194,
        d=179,
        e=195,
        f=192,
        g=193,
        h=217,
        i=193;

        koor(73, 1); printf("%c %c%c%c%c %c%c%c%c%c%c%c%c%c  %c%c%c%c%c",a,b,b,a,a,b,a,b,a,b,c,a,b,a,b,c,a,b,a);
        koor(73, 2); printf("%c%c%c%c %c %c %c%c%c%c%c%c    %c %c%c",d,d,d,e,d,d,d,d,d,d,d,e,d,d,d); 
        koor(73, 3); printf("%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c   %c %c%c",f,g,h,f,h,f,h,f,h,f,h,h,f,f,h,i,f,h);
}

void judul() {
    bingkai();

    SetConsoleOutputCP(65001);

    koor(47, 4); printf("██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗    ██╗   ██╗██╗██╗     ██╗      █████╗ ");
    koor(47, 5); printf("██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║    ██║   ██║██║██║     ██║     ██╔══██╗");
    koor(47, 6); printf("██║  ██║██║   ██║   ██║   ██║     ███████║    ██║   ██║██║██║     ██║     ███████║");
    koor(47, 7); printf("██║  ██║██║   ██║   ██║   ██║     ██╔══██║    ╚██╗ ██╔╝██║██║     ██║     ██╔══██║");
    koor(47, 8); printf("██████╔╝╚██████╔╝   ██║   ╚██████╗██║  ██║     ╚████╔╝ ██║███████╗███████╗██║  ██║");
    koor(47, 9); printf("╚═════╝  ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝      ╚═══╝  ╚═╝╚══════╝╚══════╝╚═╝  ╚═╝");

    SetConsoleOutputCP(437);

}

int kotaknama(int a, int b, int c){
 char q=222,  //blok setengah ▐ q
      r=223,  // kotak atas   ▀ r
      s=219,  //blok          █ s
      t=187,  //kanan atas    ╗ t
      u=188,  //kanan bawah   ╝ u
      v=186,  //lurus atas    ║ v
      x=205,  //lurus garis   ═ x
      w=201,  //kiri atas     ╔ w
      y=200,  //kiri bawah    ╚ y
      z=220;  //kotak bawah   ▄ z

    for (int j = 0; j < 69; j++)
{
    koor(a+j,c);
    printf("%c%c",x,x);
    koor(a+j,c+2);
    printf("%c%c",x,x);

    if (j == 0){
        koor(a,c);
        printf("%c",w);
        koor(a, c+1);
        printf("%c",v);
        koor(a,c+2);
        printf("%c",y);
        koor(b, c+1);
        printf("%c",v);
        koor(b,c+2);
        printf("%c",u);
        koor(b,c);
        printf("%c",t);
        }
    }
}

void intro(){
    textcolor(4);
    backgroundcolor(15);
    judul();
    welcome();
    garisjudul();
    teksloading();
    gambar();
    loading();
}

void kotak(int x, int y){
    int a=30,b=9;
    char s=219;
        for(int i=0; i<b; i++){
            koor(x,y+i); 
            for(int j=0; j < a; j++){
            if(i==0||i==b-1||j==0||j==a-1 || j == a - 2 || j == 1){
                printf("%c",219);
            }else{
                printf(" ");
            }
            }
        }
}

void tampilan1(){
    warna();
    kotak(18,18);
    koor(25,22); printf("U   S   E   R");
    reset();

    kotak(70,18);
    koor(78,22); printf("A  D  M  I  N");

    kotak(122,18);
    koor(128,22); printf("A  B  O  U  T");
}

void tampilan2(){
    kotak(18,18);
    koor(25,22); printf("U   S   E   R");

    warna();
    kotak(70,18);
    koor(78,22); printf("A  D  M  I  N");
    reset();

    kotak(122,18);
    koor(128,22); printf("A  B  O  U  T");
}

void tampilan3(){
    kotak(18,18);
    koor(25,22); printf("U   S   E   R");

    kotak(70,18);
    koor(78,22); printf("A  D  M  I  N");

    warna();
    kotak(122,18);
    koor(128,22); printf("A  B  O  U  T");
    reset();
}

void frame(int c){
    if (c == 0){
        tampilan1();
        halaman = 1;
    }
    else if (c == 1){
        tampilan2();
        halaman = 2;
    }
    else if (c == 2){
        tampilan3();
        halaman = 3;
    }
}

void pilih(){
    int c = 0;
    char inp;
    while ((inp = getch()) != 13)
    {
        if (inp == 72){
            c--;
            // 72 = ARROW ATAS
        }
        else if(inp == 80){
            c++;
            // 80 = ARROW BAWAH
        }
        else if(inp == 77){
            c++;
            // 77 = ARROW KANAN
        }
        else if(inp == 75){
            c--;
            // 75 = ARROW KIRI
        }
        else if(inp == 27){
            exit(0);
            break;
            // 27 = TOMBOL ESC
        }
        if (c < 0){
            c = 0;
        }
        else if (c > 2){
            c = 2;
        }
        frame(c);
    }
}

                                /////////////////////////////////////
                                /// T A M P I L A N    U S E R    ///
                                /////////////////////////////////////
void teksuser() {
    bingkai();
    SetConsoleOutputCP(65001);

    koor(70,10); printf(" ██    ██ ███████ ███████ ██████");  
    koor(70,11); printf(" ██    ██ ██      ██      ██   ██"); 
    koor(70,12); printf(" ██    ██ ███████ █████   ██████");
    koor(70,13); printf(" ██    ██      ██ ██      ██   ██"); 
    koor(70,14); printf("  ██████  ███████ ███████ ██   ██");

    SetConsoleOutputCP(437);
}

void pilihuser(){
    textcolor(4);
    backgroundcolor(15);
    teksuser();
    gambar();
    frameuser(0);
    pilihanuser();
    modehalamanuser(halamanuser);
}

void user(){
     system("cls");
     pilihuser();
     getch();
     cek = 1;
}


//                                /////////////////////////////////////
//                                /// T A M P I L A N   A B O U T   ///
//                                /////////////////////////////////////
void teksabout() {
    bingkai();
    SetConsoleOutputCP(65001);

    koor(60, 5); printf(" █████  ██████   ██████  ██    ██ ████████");
    koor(60, 6); printf("██   ██ ██   ██ ██    ██ ██    ██    ██   ");
    koor(60, 7); printf("███████ ██████  ██    ██ ██    ██    ██   ");
    koor(60, 8); printf("██   ██ ██   ██ ██    ██ ██    ██    ██   ");
    koor(60, 9); printf("██   ██ ██████   ██████   ██████     ██   ");

    SetConsoleOutputCP(437);
}

void pilihabout() {
    textcolor(4);
    backgroundcolor(15);
    teksabout();
    koor(50, 16); 
    printf("DUTCH  VILLA  adalah  sebuah  aplikasi  booking  villa  digital  sederhana  yang  dibuat"); Sleep(1000);
    koor(50, 17);
    printf("oleh  seorang  mahasiswa  Universitas Nasional Pasim dalam program Beasiswa PUB"); Sleep(1000);
    koor(50, 18);
    printf("yang  bernama  Ahmad Zaki Hossam Mido untuk  memenuhi  UAS  Logika  &  Algoritma  (Bahasa C)"); Sleep(1000);
    koor(50, 19);
    printf("yaitu  membuat  project  CRUD  berbasis  konsol  menggunakan Windows API."); Sleep(1000);
    koor(50, 20);
    printf("Melalui  aplikasi  ini  pengguna  dipermudah  untuk  melakukan  pembookingan"); Sleep(1000);
    koor(50, 21);
    printf("yaitu  dengan  hanya  mengisi  data  diri  untuk  daftar  akun  dan  login"); Sleep(1000);
    koor(50, 22);
    printf("setelah  login  pengguna  dapat  melakukan  pembookingan  di  dalam  aplikasi"); Sleep(1000);
    koor(50, 23);
    printf("ada  8  villa  yang  sudah  tersedia yaitu  villa:Garden,  Sunrise,  Lakeside,  Forest,"); Sleep(1000);
    koor(50, 24);
    printf("Mountainview,  Sunset,  Skyview,  Oceanview.  Nama  DUTCH  sendiri  diambil"); Sleep(1000);
    koor(50, 25);
    printf("yang  memiliki  arti  orang  belanda  atau  segala  sesuatu  yang berkaitan  dengan  belanda."); Sleep(1000);
    koor(50, 26);
    printf("dan  juga  dikarenakan  saya  terobsesi  dengan  negara  belanda  maka  dari  itu  mengambil  nama DUTCH."); Sleep(1000);
    koor(50, 27);
    printf("Sekian  informasi  tentang  aplikasi  sederhana  ini. Selamat menikmati aplikasi sederhana ini"); Sleep(1000);
    gambar();
}

void about(){
     system("cls");  
     pilihabout();
     koor(2, 2);
     printf("ESC UNTUK KEMBALI");
     int input;
     while ((input = getch()) != 27);
     cek = 1;
}

                                /////////////////////////////////////
                                /// T A M P I L A N   A D M I N   ///
                                /////////////////////////////////////
void teksadmin() {
    bingkai();
    SetConsoleOutputCP(65001);

    koor(70, 10); printf(" █████  ██████  ███    ███ ██ ███    ██");
    koor(70, 11); printf("██   ██ ██   ██ ████  ████ ██ ████   ██");
    koor(70, 12); printf("███████ ██   ██ ██ ████ ██ ██ ██ ██  ██");
    koor(70, 13); printf("██   ██ ██   ██ ██  ██  ██ ██ ██  ██ ██");
    koor(70, 14); printf("██   ██ ██████  ██      ██ ██ ██   ████");

    SetConsoleOutputCP(437);

}

void sebelumpilihadmin() {
    loginadmin();
    pilihadmin();
}

void pilihadmin() {
    textcolor(4);
    backgroundcolor(15);
    teksadmin();
    gambar();
    frameadmin(0);
    pilihanadmin();
    modehalamanadmin(halamanadmin);
}
    
void admin(){
    system("cls");
    sebelumpilihadmin();
    getch();
    cek = 1;
}

void tamppilih(){
    textcolor(4);
    backgroundcolor(15);
    judul();
    garisjudul();
    koor(2,2); printf("ESC 2 KALI UNTUK KELUAR");
    gambar();
    frame(0);
    pilih();
}

void modehalaman(int h){

    switch (h)
    {
    case 1:
        user();
        if(cek == 1){
            cek = 0;
            tamppilih();
            modehalaman(halaman);
        }
        break;
    case 2:
        admin();
        if(cek == 1){
            cek = 0;
            tamppilih();
            modehalaman(halaman);
        }
        break;
    case 3:
        about();
        if(cek == 1){
            cek = 0;
            tamppilih();
            modehalaman(halaman);
        }
        break;
    }
}


void bingdaftar(){
    int a = 88,b = 28;
    for (int i = 0; i < b; i++){
      koor(40, 9+i);
        for(int j=0; j<a; j++){
                if(i==0||i==b-1||j==0||j==1||j==a-1||j==a-2){
                    printf("%c",219);}
                else{
                    printf(" ");}
            }
    }
}

void binglogin(int x, int y){
    int a = 90,b = 13;
    for (int i = 0; i < b; i++){
      koor(x, y+i);
        for(int j=0; j<a; j++){
                if(i==0||i==b-1||j==0||j==1||j==a-1||j==a-2){
                    printf("%c",219);}
                else{
                    printf(" ");}
            }
    }
}

                                /////////////////////////////////////
                                /// T A M P I L A N  D A F T A R  ///
                                /////////////////////////////////////

void teksdaftar(int a, int b) {
    char s = 219;

    koor(a,b);  printf("%c%c%c%c%c%c   %c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c%c%c%c%c%c  %c%c%c%c%c  %c%c%c%c%c%c  ",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
    koor(a,b+1);printf("%c%c   %c%c %c%c   %c%c %c%c         %c%c    %c%c   %c%c %c%c   %c%c ",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
    koor(a,b+2);printf("%c%c   %c%c %c%c%c%c%c%c%c %c%c%c%c%c      %c%c    %c%c%c%c%c%c%c %c%c%c%c%c%c  ",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
    koor(a,b+3);printf("%c%c   %c%c %c%c   %c%c %c%c         %c%c    %c%c   %c%c %c%c   %c%c ",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
    koor(a,b+4);printf("%c%c%c%c%c%c  %c%c   %c%c %c%c         %c%c    %c%c   %c%c %c%c   %c%c",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
}

void pilihdaftar(){
    FILE *file = fopen("akun.txt", "a");

    char l_nama[100], l_username[100], l_password[100], l_nohp[20], l_umur[10];

    system("cls");
    bingkai();
    gambar();
    teksdaftar(62,3);
    textcolor(4);
    backgroundcolor(7);
    bingdaftar();
    kotaknama(49,119, 12);
    kotaknama(49,119, 17);
    kotaknama(49,119, 22);
    kotaknama(49,119, 27);
    kotaknama(49,119, 32);

    koor(72,11); printf("N A M A    L E N G K A P  "); 
    koor(72,16); printf("         U M U R          "); 
    koor(72,21); printf("     U S E R N A M E      ");
    koor(72,26); printf("     P A S S W O R D      ");
    koor(72,31); printf("N O M O R   T E L E P O N ");
    koor(50,13); valnama(l_nama);
    koor(50,18); valumur(l_umur);
    koor(50,23); valuser(l_username);
    koor(50,28); valpass(l_password);
    koor(50,33); valnohp(l_nohp);

    fprintf(file, "%s %s %s %s %s\n", l_nama, l_umur, l_username, l_password, l_nohp);
    fclose(file);
    strcpy(nama, l_nama);
    umur = atoi(l_umur);
    strcpy(username, l_username);
    strcpy(password, l_password);
    strcpy(nohp, l_nohp);
    textcolor(2);
    backgroundcolor(15);
    koor(72,38); printf("PENDAFTARAN BERHASIL.");
    textcolor(4);
    koor(72,40); printf("TEKAN APA SAJA UNTUK LANJUT");
}

void haldaftar(){
     system("cls");
     pilihdaftar();
     getch();
     cekuser = 1;
}

                                /////////////////////////////////////
                                /// T A M P I L A N  L O G I N    ///
                                /////////////////////////////////////
void tekslogin(int c, int d) {
    char s = 219;

    koor(c,d);  printf("%c%c       %c%c%c%c%c%c   %c%c%c%c%c%c    %c%c %c%c%c    %c%c",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
    koor(c,d+1);printf("%c%c      %c%c    %c%c %c%c         %c%c %c%c%c%c   %c%c",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
    koor(c,d+2);printf("%c%c      %c%c    %c%c %c%c   %c%c%c   %c%c %c%c %c%c  %c%c",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
    koor(c,d+3);printf("%c%c      %c%c    %c%c %c%c    %c%c   %c%c %c%c  %c%c %c%c",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
    koor(c,d+4);printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c    %c%c %c%c   %c%c%c%c",s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s,s);
}

void pilihlogin() {
    FILE *file;
    char username[100], password[100];
    char fnama[100], fumur[10], fuser[100], fpass[100], fnohp[20];
    int log = 0;

    bingkai();
    gambar();
    tekslogin(65,10);
    textcolor(4);
    backgroundcolor(7);
    binglogin(40,16);
    kotaknama(49,119,19);
    kotaknama(49,119,24);

    while (!log) {
        file = fopen("akun.txt", "r");

        koor(72,18); printf("     U S E R N A M E     ");
        koor(72,23); printf("     P A S S W O R D      ");
        koor(50,20); valuser(username); 
        koor(50,25); valpass(password); 

        while (fscanf(file, "%s %s %s %s %s", fnama, fumur, fuser, fpass, fnohp) != EOF) {
            if (strcmp(username, fuser) == 0 && strcmp(password, fpass) == 0) {
                log = 1;
                break;
            }
        }
        fclose(file);

        if (log) {
            for (int i = 0; i < 10; i++) {
                system("COLOR AF");
                Sleep(1);
                system("COLOR F4");
            }
            textcolor(2);
            koor(75,30); printf("LOGIN BERHASIL");
            textcolor(4);
            koor(72,40); printf("TEKAN APA SAJA UNTUK LANJUT >>");
            getch();

        } else {
            for (int i = 0; i < 10; i++) {
                system("COLOR 4F");
                Sleep(1);
                system("COLOR F4");
            }
            textcolor(4);
            koor(75,30); printf("LOGIN GAGAL");
            koor(70,35); printf("USERNAME ATAU PASSWORD SALAH");
            koor(2,2);
            printf("ESC UNTUK KEMBALI");
            int input;
            while ((input = getch()) != 13) {
                if (input == 27) {
                    tamppilih();
                    modehalaman(halaman);
                    return;
                }
            }
        }
    }
}

void hallogin(){
     system("cls");
     pilihlogin();
     cekuser = 2;
}

void tampuser1(){
    koor(2,2); printf("ESC UNTUK KEMBALI");

    warna();
    kotak(45,18);
    koor(50,22); printf("D  A  F  T  A  R");
    reset();

    kotak(100,18);
    koor(107,22); printf("L  O  G  I  N");

}

void tampuser2(){
    koor(2,2); printf("ESC UNTUK KEMBALI");

    kotak(45,18);
    koor(50,22); printf("D  A  F  T  A  R");

    warna();
    kotak(100,18);
    koor(107,22); printf("L  O  G  I  N");
    reset();
}

void modehalamanuser(int halamanuser){

    switch (halamanuser)
    {
    case 1:
            cekuser = 1;
            haldaftar();
            hallogin();
            tampmenu();
            switch (halamanmenu)
            {
            case 1:
                booking();
                break;
            case 2:
                history();
                break;
            case 3:
                profile();
                break;
            default:
                break;
            }
        break;
    case 2:
            cekuser = 2;
            hallogin();
            tampmenu();
            switch (halamanmenu)
            {
            case 1:
                booking();
                break;
            case 2:
                history();
                break;
            case 3:
                profile();
                break;
            default:
                break;
            }
        break;
    }
}

void frameuser(int d){
    if (d == 0){
        tampuser1();
        halamanuser = 1;
    }
    else if (d == 1){
        tampuser2();
        halamanuser = 2;
    }
}

void pilihanuser(){
    int d = 0;
    char inp;
    while ((inp = getch()) != 13)
    {
        if (inp == 72){
            d--;
            // 72 = ARROW ATAS
        }
        else if(inp == 80){
            d++;
            // 80 = ARROW BAWAH
        }
        else if(inp == 77){
            d++;
            // 77 = ARROW KANAN
        }
        else if(inp == 75){
            d--;
            // 75 = ARROW KIRI
        }
        else if(inp == 27){
            tamppilih();
            modehalaman(halaman);
            break;
            // 27 = TOMBOL ESC
        }
        if (d < 0){
            d = 0;
        }
        else if (d > 2){
            d = 2;
        }
        frameuser(d);
    }
}

void teksloginadmin() {

    bingkai();
    SetConsoleOutputCP(65001);

    koor(42,10); printf(" ██       ██████   ██████  ██ ███    ██      █████  ██████  ███    ███ ██ ███    ██");
    koor(42,11); printf(" ██      ██    ██ ██       ██ ████   ██     ██   ██ ██   ██ ████  ████ ██ ████   ██"); 
    koor(42,12); printf(" ██      ██    ██ ██   ███ ██ ██ ██  ██     ███████ ██   ██ ██ ████ ██ ██ ██ ██  ██");
    koor(42,13); printf(" ██      ██    ██ ██    ██ ██ ██  ██ ██     ██   ██ ██   ██ ██  ██  ██ ██ ██  ██ ██"); 
    koor(42,14); printf(" ███████  ██████   ██████  ██ ██   ████     ██   ██ ██████  ██      ██ ██ ██   ████");

    SetConsoleOutputCP(437);
}

void loginadmin() {
    FILE *file;
    char usernameadmin[100], passwordadmin[100], file_useradmin[100], file_passadmin[100];
    int log = 0;

    teksloginadmin();
    gambar();
    textcolor(4);
    backgroundcolor(7);
    binglogin(40,16);
    kotaknama(49,119,19);
    kotaknama(49,119,24);

    while (!log) {
        file = fopen("admin.txt", "r");
    
        koor(72,18); printf("     U S E R N A M E     ");
        koor(72,23); printf("     P A S S W O R D      ");
        koor(50,20); valuser(usernameadmin);
        koor(50,25); valpass(passwordadmin);

        int input;

        while (fscanf(file,"%s %s", file_useradmin, file_passadmin) != EOF) {
            if (strcmp(usernameadmin, file_useradmin) == 0 && strcmp(passwordadmin, file_passadmin) == 0) {
                log = 1;
                break;
            }
        }
        fclose(file);

        if (log) {
            for(int i = 0; i < 10; i++){
                system("COLOR AF");
                Sleep(1);
                system("COLOR F4");
            }
            textcolor(2);
            koor(75,30); printf("LOGIN BERHASIL");
            textcolor(4);
            koor(72,40); printf("ENTER UNTUK LANJUT >>");
            getch();
            system("cls");
            }
        else {
            for(int i = 0; i < 10; i++){
                system("COLOR 4F");
                Sleep(1);
                system("COLOR F4");
            }
            textcolor(4);
            koor(75,30); printf("LOGIN GAGAL");
            koor(70,35); printf("USERNAME ATAU PASSWORD SALAH");
            koor(2,2);
            printf("ESC UNTUK KEMBALI");
            while ((input = getch()) != 13)
            {
            if(input == 27){
            tamppilih();
            modehalaman(halaman);
            break;
            }
        }
    }
}
}

void tampadmin1(){
    koor(2,2); printf("ESC UNTUK LOGOUT ADMIN");

    warna();
    kotak(45,18);
    koor(52,22); printf("D A T A U S E R");
    reset();

    kotak(100,18);
    koor(106,22); printf("D A T A V I L L A");

}

void tampadmin2(){
    koor(2,2); printf("ESC UNTUK LOGOUT ADMIN");

    kotak(45,18);
    koor(52,22); printf("D A T A U S E R");

    warna();
    kotak(100,18);
    koor(106,22); printf("D A T A V I L L A");
    reset();
}

void modehalamanadmin(int halamanadmin){

    switch (halamanadmin)
    {
    case 1:
            datauser();
            cekadmin = 1;
            break;
    case 2:
            datavilla();
            cekadmin = 2;
            break;
    }
}

void frameadmin(int e){
    if (e == 0){
        tampadmin1();
        halamanadmin = 1;
    }
    else if (e == 1){
        tampadmin2();
        halamanadmin = 2;
    }
}

void pilihanadmin(){
    int e = 0;
    char inp;
    while ((inp = getch()) != 13)
    {
        if (inp == 72){
            e--;
            // 72 = ARROW ATAS
        }
        else if(inp == 80){
            e++;
            // 80 = ARROW BAWAH
        }
        else if(inp == 77){
            e++;
            // 77 = ARROW KANAN
        }
        else if(inp == 75){
            e--;
            // 75 = ARROW KIRI
        }
        else if(inp == 27){
            tamppilih();
            modehalaman(halaman);
            break;
            // 27 = TOMBOL ESC
        }
        if (e < 0){
            e = 0;
        }
        else if (e > 2){
            e = 2;
        }
        frameadmin(e);
    }
}

void userpilih(){
    textcolor(4);
    backgroundcolor(15);
    tamppilih();
    modehalaman(halaman);
    pilihuser();
    modehalamanuser(halamanuser);
    pilihadmin();
    modehalamanadmin(halamanadmin);
    tampmenu();
    modehalamanmenu(halamanmenu);

}
void teksdatauser() {

    SetConsoleOutputCP(65001);

    koor(55,2); printf(" ██████   █████  ████████  █████  ██    ██ ███████ ███████ ██████");  
    koor(55,3); printf(" ██   ██ ██   ██    ██    ██   ██ ██    ██ ██      ██      ██   ██"); 
    koor(55,4); printf(" ██   ██ ███████    ██    ███████ ██    ██ ███████ █████   ██████");
    koor(55,5); printf(" ██   ██ ██   ██    ██    ██   ██ ██    ██      ██ ██      ██   ██"); 
    koor(55,6); printf(" ██████  ██   ██    ██    ██   ██  ██████  ███████ ███████ ██   ██");

    SetConsoleOutputCP(437);

}

void tampdatauser(){
    system("cls");
    char z=220;
    
    for(int j = 0; j < 171;j++){
        koor(1+j,7);
        printf("%c",220);}

    for(int j = 0; j < 171;j++){
        koor(1+j,11);
        if(j == 12)
            printf("%c",223);
        else
            printf("%c",223);
            }

    for(int j = 0; j < 36;j++){
        koor(48,7+j);
        if(j == 0)
            printf("%c",220);
        else
            printf("%c",219);
            }
    
       for(int j = 0; j < 36;j++){
        koor(62,7+j);
        if(j == 0)
            printf("%c",220);
        else
            printf("%c",219);
            }
        
    for(int j = 0; j < 36;j++){
        koor(92,7+j);
        if(j == 0)
            printf("%c",220);
        else
            printf("%c",219);
            }

    for(int j = 0; j < 36;j++){
        koor(125,7+j);
        if(j == 0)
            printf("%c",220);
        else
            printf("%c",219);
            }

    koor(10,9);printf(" N A M A  L E N G K A P ");
    koor(49,9);printf(" U M U R ");
    koor(68,9);printf(" U S E R N A M E ");
    koor(100,9);printf(" P A S S W O R D ");
    koor(130,9);printf("N O M O R T E L P O N ");
}

void pilihdatauser(){
    int input;
    bingkai();
    tampdatauser();
    teksdatauser();
    textcolor(4);

    FILE *file = fopen("akun.txt", "r");
    
    char nama[100], username[50], password[50], nohp[20];
    int umur;
    int n = 0; 
    while (fscanf(file, "%s %d %s %s %s", nama, &umur, username, password, nohp) != EOF) {
        koor(7, 12 + n); 
        printf("%s", nama);

        koor(50, 12 + n); 
        printf("%dtahun", umur);

        koor(64, 12 + n); 
        printf("%s", username);

        koor(93, 12 + n); 
        printf("%s", password);

        koor(128, 12 + n); 
        printf("%s", nohp);
           
        n += 1; 
    }
    fclose(file);

    koor(2,2);
    printf("ESC UNTUK KEMBALI");
    while ((input = getch()) != 13)
    {
        if(input == 27){
            pilihadmin();
            modehalamanadmin(halamanadmin);
            break;
        }
    }    
}

void datauser() {
    system("cls");
    pilihdatauser();
    getch();
    cekadmin = 1;
}

void tampdatavilla1() {
    listvilla();
    koor(2,2); printf("ESC UNTUK KEMBALI");

    warna();
    kotak(45,18);
    koor(50,22); printf("T A M B A H V I L L A");
    reset();

    kotak(100,18);
    koor(106,22); printf("H A P U S V I L L A");

}

void tampdatavilla2() {
    listvilla();
    koor(2,2); printf("ESC UNTUK KEMBALI");

    kotak(45,18);
    koor(50,22); printf("T A M B A H V I L L A");

    warna();
    kotak(100,18);
    koor(106,22); printf("H A P U S V I L L A");
    reset();
}

void modehalamandatavilla(int halamandatavilla){

    switch (halamandatavilla)
    {
    case 1:
            cekdatavilla = 1;
            tambahvilla();
            break;
    case 2:
            cekdatavilla = 2;
            hapusvilla();
            break;
    }
}

void framedatavilla(int h){
    if (h == 0){
        tampdatavilla1();
        halamandatavilla = 1;
    }
    else if (h == 1){
        tampdatavilla2();
        halamandatavilla = 2;
    }
}

void pilihandatavilla(){
    int h = 0;
    char inp;
    while ((inp = getch()) != 13)
    {
        if (inp == 72){
            h--;
            // 72 = ARROW ATAS
        }
        else if(inp == 80){
            h++;
            // 80 = ARROW BAWAH
        }
        else if(inp == 77){
            h++;
            // 77 = ARROW KANAN
        }
        else if(inp == 75){
            h--;
            // 75 = ARROW KIRI
        }
        else if(inp == 27){
            pilihuser();
            modehalamanuser(halamanuser);
            break;
            // 27 = TOMBOL ESC (LOGOUT)
        }
        if (h < 0){
            h = 0;
        }
        else if (h > 2){
            h = 2;
        }
        framedatavilla(h);
    }
}

void pilihdatavilla() {
    gambar();
    framedatavilla(0);
    pilihandatavilla();
    modehalamandatavilla(halamandatavilla);
}


void datavilla() {
    system("cls");
    pilihdatavilla();
    getch();
    cekadmin = 2;
    
}

void simpanfile() {
    FILE *file = fopen("datavilla.txt", "w");

    for (int i = 0; i < villa; i++) {
        fprintf(file, "%s %d\n", villa_list[i].namavilla, villa_list[i].harga_per_malam);
    }

    fclose(file);
}

void bacafile() {
    FILE *file = fopen("datavilla.txt", "r");

    villa = 0;

    while (fscanf(file, "%s %d", villa_list[villa].namavilla, &villa_list[villa].harga_per_malam) == 2) {
        villa++;
    }

    fclose(file);
}

void tekstambahvilla() {
    bingkai();

    SetConsoleOutputCP(65001);

    koor(35,5); printf(" ████████  █████  ███    ███ ██████   █████  ██   ██     ██    ██ ██ ██      ██       █████  ");  
    koor(35,6); printf("    ██    ██   ██ ████  ████ ██   ██ ██   ██ ██   ██     ██    ██ ██ ██      ██      ██   ██"); 
    koor(35,7); printf("    ██    ███████ ██ ████ ██ ██████  ███████ ███████     ██    ██ ██ ██      ██      ███████");
    koor(35,8); printf("    ██    ██   ██ ██  ██  ██ ██   ██ ██   ██ ██   ██      ██  ██  ██ ██      ██      ██   ██ "); 
    koor(35,9); printf("    ██    ██   ██ ██      ██ ██████  ██   ██ ██   ██       ████   ██ ███████ ███████ ██   ██ ");

    SetConsoleOutputCP(437);
}

void tambahv() {
    int input;

    koor(2, 2);
    printf("ESC UNTUK KEMBALI");
    koor(22, 2);
    printf("ENTER UNTUK LANJUT");
    while ((input = getch()) != 13) {
        if (input == 27) {
            system("cls");
            pilihdatavilla();
            modehalamandatavilla(halamandatavilla);
            return;
        }
    }

    if (villa >= MAX_VILLA) {
        printf("VILLA PENUH!");
        return;
    }
    Villa villabaru;
    char harga_str[20];
    koor(50,15); 
    printf("NAMA VILLA BARU: ");
    valvilla(villabaru.namavilla);
    koor(50,17); 
    printf("HARGA/MALAM: ");
    valharga(harga_str);
    villabaru.harga_per_malam = atoi(harga_str);

    villa_list[villa] = villabaru;
    villa++;

    simpanfile();
    koor(50, 20);
    warna();
    printf("VILLA BERHASIL DITAMBAHKAN!");
    reset();
    koor(2, 2);
    printf("ESC UNTUK KEMBALI");
    while ((input = getch()) != 13) {
        if (input == 27) {
            system("cls");
            pilihdatavilla();
            modehalamandatavilla(halamandatavilla); 
        }
    }
}

void pilihtambahvilla() {
    tekstambahvilla();
    gambar();
    tambahv();

}

void tambahvilla() {
    system("cls");
    pilihtambahvilla();
    getch();
    cekdatavilla = 1;
}

void tekshapusvilla() {
    bingkai();

    SetConsoleOutputCP(65001);

    koor(35,5); printf(" ██   ██  █████  ██████  ██    ██ ███████     ██    ██ ██ ██      ██       █████ ");  
    koor(35,6); printf(" ██   ██ ██   ██ ██   ██ ██    ██ ██          ██    ██ ██ ██      ██      ██   ██"); 
    koor(35,7); printf(" ███████ ███████ ██████  ██    ██ ███████     ██    ██ ██ ██      ██      ███████");
    koor(35,8); printf(" ██   ██ ██   ██ ██      ██    ██      ██      ██  ██  ██ ██      ██      ██   ██"); 
    koor(35,9); printf(" ██   ██ ██   ██ ██       ██████  ███████       ████   ██ ███████ ███████ ██   ██");

    SetConsoleOutputCP(437);

}

void hapusv() {
    char nama[50];
    int input;

    koor(2, 2);
    printf("ESC UNTUK KEMBALI");
    koor(22, 2);
    printf("ENTER UNTUK LANJUT");
    while ((input = getch()) != 13) {
        if (input == 27) {
            system("cls");
            pilihdatavilla();
            modehalamandatavilla(halamandatavilla);
            return;
        }
    }

    koor(50,15); 
    printf("MASUKKAN NAMA VILLA YANG INGIN ANDA HAPUS: ");
    valvilla(nama);

    int n = 0;
    for (int i = 0; i < villa; i++) {
        if (strcmp(villa_list[i].namavilla, nama) == 0) {
            n = 1;
            for (int j = i; j < villa - 1; j++) {
                villa_list[j] = villa_list[j + 1];
            }
            villa--;
            koor(50,17);
            printf("VILLA BERHASIL DIHAPUS\n");
            break;
        }
    }

    if (!n) {
        koor(50,17);
        printf("TIDAK ADA VILLA.\n");
    } else {
        simpanfile();
    }
    koor(2, 2);
    printf("ESC UNTUK KEMBALI");
    while ((input = getch()) != 13) {
        if (input == 27) {
            system("cls");
            pilihdatavilla();
            modehalamandatavilla(halamandatavilla); 
        }
    }
}

void pilihhapusvilla() {
    tekshapusvilla();
    gambar();
    hapusv();

}

void hapusvilla() {
    system("cls");
    pilihhapusvilla();
    getch();
    cekdatavilla = 2;
}

void listvilla() {
    bacafile();
    koor(15,5); printf("Daftar Villa yang Tersedia:");
    int batas = 0;
    for (int i = 0; i < villa; i++) {
        koor(15,6 + batas);
        printf("Nomor: %d, Villa: %s, Harga/Malam: %d", i + 1, villa_list[i].namavilla, villa_list[i].harga_per_malam);
        batas++;
    }
}


void pembayaran(int total_harga) {
    // int uang_dibayar;
    while (1) {
        koor(80,17);
        printf("UANG ANDA: Rp");
        valbayar(uang_dibayar);

        if (atoi(uang_dibayar) < total_harga) {
            koor(80,19);
            printf("UANG ANDA KURANG");
        } else {
            int kembalian = atoi(uang_dibayar) - total_harga;
            koor(80,19);
            bayarsukses();
            printf("PAYMENT SUCCES!");
            if (kembalian > 0) {
                koor(80,18);
                reset();
                printf("KEMBALIAN: Rp%d", kembalian);
            }
            break;
        }
    }
}

void catatbooking(char* nama_villa, int jumlah_malam, int total_harga, char* waktu_mulai, char* waktu_selesai) {
    FILE *file = fopen("historybooking.txt", "a");
    
    fprintf(file, "Villa: %s, Malam: %d, Harga: Rp%d, Chek In: %s, Chek Out: %s\n", 
            nama_villa, jumlah_malam, total_harga, waktu_mulai, waktu_selesai);
    fclose(file);
}

void bookingvilla() {
    int input, jumlah_malam, pilihan_idx;
    char pilihan[10], jumlah_malam_str[10];

    bingkaibooking();
    listvilla();
    koor(2, 2);
    printf("ESC UNTUK KEMBALI");
    koor(22, 2);
    printf("ENTER UNTUK BOOKING");
    while ((input = getch()) != 13) {
        if (input == 27) {
            tampmenu();
            modehalamanmenu(halamanmenu);
            return;
        }
    }

    while (1) {
        koor(15, 18);
        printf("NOMOR VILLA YANG INGIN ANDA BOOKING: ");
        koor(52, 18);
        valpilihan(pilihan);

        pilihan_idx = atoi(pilihan) - 1;
        if (pilihan_idx < 0 || pilihan_idx >= villa) {
            koor(2, 20);
            printf("TIDAK ADA VILLA");
            continue;
        }
        break;
    }

    Villa villa_terpilih = villa_list[pilihan_idx];

    koor(15,20);
    printf("VILLA: %s", villa_terpilih.namavilla);
    koor(15,22);
    printf("JUMLAH MALAM: ");
    valmalam(jumlah_malam_str);

    jumlah_malam = atoi(jumlah_malam_str);
    int total_harga = villa_terpilih.harga_per_malam * jumlah_malam;

    koor(100, 6);
    printf("DETAIL BOOKING:");
    koor(100, 7);
    printf("VILLA: %s", villa_terpilih.namavilla);
    koor(100, 8);
    printf("JUMLAH MALAM: %d", jumlah_malam);
    koor(100, 9);
    printf("HARGA: Rp%d", total_harga);

    while (1) {
        koor(100, 15);
        printf("LAJUTKAN BOOKINGAN (y/t): ");
        valkonfir(konfirmasi);

        if (strcmp(konfirmasi, "Y") == 0 || strcmp(konfirmasi, "y") == 0) {
            pembayaran(total_harga);

            time_t waktu_mulai = time(NULL);
            time_t waktu_selesai = waktu_mulai + (jumlah_malam * 86400);
            char waktu_mulai_str[100], waktu_selesai_str[100];
            strftime(waktu_mulai_str, sizeof(waktu_mulai_str), "%Y-%m-%d %H:%M:%S", localtime(&waktu_mulai));
            strftime(waktu_selesai_str, sizeof(waktu_selesai_str), "%Y-%m-%d %H:%M:%S", localtime(&waktu_selesai));

            listvilla();

            koor(70, 20);
            printf("CHECK IN: %s", waktu_mulai_str);
            koor(70, 21);
            printf("CHECK OUT: %s", waktu_selesai_str);

            catatbooking(villa_terpilih.namavilla, jumlah_malam, total_harga, waktu_mulai_str, waktu_selesai_str);
            koor(70, 22);
            printf("BOOKING VILLA BERHASIL. TERIMA KASIH TELAH MENGGUNAKAN JASA KAMI.");
            break;
        } else if (strcmp(konfirmasi, "T") == 0 || strcmp(konfirmasi, "t") == 0) {
            koor(70, 22);
            printf("BATAL BOOKING");
            break;
        } else {
            koor(70, 22);
            printf("INVALID");
        }
    }

    koor(2, 2);
    printf("ESC UNTUK KEMBALI");
    while ((input = getch()) != 13) {
        if (input == 27) {
            tampmenu();
            modehalamanmenu(halamanmenu); 
            return;
        }
    }
}

void historybooking() {
    int input;
    char n[200];
    int v = 7;  

    FILE *file = fopen("historybooking.txt", "r");

    bingkaihistory();
    koor(30, v); printf("HISTORI BOOKING:");

    v += 1;   
    while (fgets(n, sizeof(n), file)) {
        koor(30, v); 
        printf("%s", n);  
        v++;  
    }
    fclose(file);

    koor(2,2);
    printf("ESC UNTUK KEMBALI");
    while ((input = getch()) != 13)
    {
        if(input == 27){
            tampmenu();
            modehalamanmenu(halamanmenu);
            break;
        }
    }
}

void tampmenu1(){
    warna();
    kotak(18,18);
    koor(24,22); printf("B  O  O  K  I  N  G");
    reset();

    kotak(70,18);
    koor(75,22); printf("H  I  S  T  O  R  Y");

    kotak(122,18);
    koor(128,22); printf("P  R  O  F  I  L  E");
}
 
void tampmenu2(){
    kotak(18,18);
    koor(24,22); printf("B  O  O  K  I  N  G");

    warna();
    kotak(70,18);
    koor(75,22); printf("H  I  S  T  O  R  Y");
    reset();

    kotak(122,18);
    koor(128,22); printf("P  R  O  F  I  L  E");
}

void tampmenu3(){
    kotak(18,18);
    koor(24,22); printf("B  O  O  K  I  N  G");

    kotak(70,18);
    koor(75,22); printf("H  I  S  T  O  R  Y");

    warna();
    kotak(122,18);
    koor(128,22); printf("P  R  O  F  I  L  E");
    reset();
}

                                /////////////////////////////////////
                                ///T A M P I L A N   B O O K I N G///
                                /////////////////////////////////////
void teksbooking() {
    bingkai();
    SetConsoleOutputCP(65001);
                              
 koor(55,34); printf(" ██████   ██████   ██████  ██   ██ ██ ███    ██  ██████ ");
 koor(55,35); printf(" ██   ██ ██    ██ ██    ██ ██  ██  ██ ████   ██ ██      ");
 koor(55,36); printf(" ██████  ██    ██ ██    ██ █████   ██ ██ ██  ██ ██   ███");
 koor(55,37); printf(" ██   ██ ██    ██ ██    ██ ██  ██  ██ ██  ██ ██ ██    ██");
 koor(55,38); printf(" ██████   ██████   ██████  ██   ██ ██ ██   ████  ██████ ");
                                                                                    
    SetConsoleOutputCP(437);
}

void pilihbooking() {
    system("cls");
    textcolor(4);
    backgroundcolor(15);
    teksbooking();
    gambar();
    bookingvilla();
}

void booking() {
     system("cls");
     pilihbooking();
     getch();
     cekmenu = 1;
}

                                /////////////////////////////////////
                                ///T A M P I L A N  P R O F I L E ///
                                /////////////////////////////////////
void teksprofile(int a, int b) {
    bingkai();
    SetConsoleOutputCP(65001);

    koor(a,b);   printf(" ██████  ██████   ██████  ███████ ██ ██      ███████");
    koor(a,b+1); printf(" ██   ██ ██   ██ ██    ██ ██      ██ ██      ██     ");
    koor(a,b+2); printf(" ██████  ██████  ██    ██ █████   ██ ██      ███████");
    koor(a,b+3); printf(" ██      ██   ██ ██    ██ ██      ██ ██      ██     ");
    koor(a,b+4); printf(" ██      ██   ██  ██████  ██      ██ ███████ ███████");
                                                                                                                      
    SetConsoleOutputCP(437);
}

void update(){
    char inp, tamp;
    int idx = 0;
    koor(80,39); printf("=>  <=");
    koor(83, 39);
    while((inp = getch()) != 13 || idx < 1){
        if((idx == 0 && (inp == 'Y' || inp == 'y' || inp == 'n' || inp == 'N')) && idx >=0 && idx < 1){
            idx++;
            tamp = inp;
            printf("%c",inp);
        }
        else if (inp == 8 && idx != 0){
            printf("\b \b");
            idx--;
        }
        else if(inp == 27){
            selectal = 1;
            s_update = 0;
            break;
        }
    }
    if(tamp == 'Y' || tamp == 'y'){
        s_update = 1;
    }else{
        selectal = 1;
        }
}

void pilihprofile() {
    FILE *file = fopen("akun.txt", "r");

    char n[256];
    char l_nama[256], l_umur[256], l_username[256], l_password[256], l_nohp[256];
    int found = 0;

    while (fgets(n, sizeof(n), file) != NULL) {
        sscanf(n, "%s %s %s %s %s", l_nama, l_umur, l_username, l_password, l_nohp);
        if (strcmp(l_username, username) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        strcpy(l_nama, nama);
        sprintf(l_umur, "%d", umur);
        strcpy(l_username, username);
        strcpy(l_password, password);
        strcpy(l_nohp, nohp);
    }

    system("cls");
    koor(2, 2); printf("ESC UNTUK KEMBALI");
    teksprofile(60, 3);
    gambar();
    textcolor(4);
    backgroundcolor(7);
    bingdaftar();
    kotaknama(49, 119, 12);
    kotaknama(49, 119, 17);
    kotaknama(49, 119, 22);
    kotaknama(49, 119, 27);
    kotaknama(49, 119, 32);
    koor(50, 13); printf("%s", l_nama);
    koor(50, 18); printf("%s", l_umur);
    koor(50, 23); printf("%s", l_username);
    koor(50, 28); printf("%s", l_password);
    koor(50, 33); printf("%s", l_nohp);
    koor(72, 11); printf("N A M A    L E N G K A P  "); 
    koor(72, 16); printf("         U M U R          "); 
    koor(72, 21); printf("     U S E R N A M E      ");
    koor(72, 26); printf("     P A S S W O R D      ");
    koor(72, 31); printf("N O M O R   T E L E P O N ");

    fclose(file);
}

void updata() {
    char u_nama[100], u_nohp[100], u_username[100], u_password[100];
    int u_umur, input;

    strcpy(u_nama, nama);
    u_umur = umur;
    strcpy(u_username, username);
    strcpy(u_password, password);
    strcpy(u_nohp, nohp);

    if (upd == 1) {
        koor(50, 13);
        valnama(u_nama);
        strcpy(nama, u_nama);
        s_update = 1;
    } else if (upd == 2) {
        char u_umur_str[10];
        koor(50, 18);
        valumur(u_umur_str);
        u_umur = atoi(u_umur_str);
        umur = u_umur;
        s_update = 1;
    } else if (upd == 3) {
        koor(50, 23);
        valuser(u_username);
        strcpy(username, u_username);
        s_update = 1;
    } else if (upd == 4) {
        koor(50, 28);
        valpass(u_password);
        strcpy(password, u_password);
        s_update = 1;
    } else if (upd == 5) {
        koor(50, 33);
        valnohp(u_nohp);
        strcpy(nohp, u_nohp);
        s_update = 1;
    }

    if (s_update == 1) {
        FILE *file = fopen("akun.txt", "r");
        FILE *tamp = fopen("temp.txt", "w");

        while (fscanf(file, "%s %d %s %s %s", u_nama, &u_umur, u_username, u_password, u_nohp) != EOF) {
            if (strcmp(username, u_username) == 0) {
                fprintf(tamp, "%s %d %s %s %s\n", nama, umur, username, password, nohp);
            } else {
                fprintf(tamp, "%s %d %s %s %s\n", u_nama, u_umur, u_username, u_password, u_nohp);
            }
        }

        fclose(file);
        fclose(tamp);
        remove("akun.txt");
        rename("temp.txt", "akun.txt");
    }
    koor(2, 2);
    printf("ESC UNTUK KEMBALI");
    while ((input = getch()) != 13) {
        if (input == 27) {
            system("cls");
            tampmenu();
            modehalamanmenu(halamanmenu); 
        }
    }
}

void profile() {
    int input;

    pilihprofile();

    koor(2, 2);
    printf("ESC UNTUK KEMBALI");
    koor(22, 2);
    printf("ENTER UNTUK UPDATE");
    while ((input = getch()) != 13) {
        if (input == 27) {
            tampmenu();
            modehalamanmenu(halamanmenu);
            return;
        }
    }

    char upd_str[10];
    koor(40,38); printf("Pilih data yang ingin diupdate (1.Nama, 2.Umur, 3.Username, 4.Password, 5.No HP): ");
    valpilihan(upd_str);
    upd = atoi(upd_str);
    updata();
 
}

                                /////////////////////////////////////
                                ///T A M P I L A N   B O O K I N G///
                                /////////////////////////////////////
void tekshistory() {
    bingkai();
    SetConsoleOutputCP(65001);
                                
    koor(55,34); printf(" ██   ██ ██ ███████ ████████  ██████  ██████  ██    ██ ");
    koor(55,35); printf(" ██   ██ ██ ██         ██    ██    ██ ██   ██  ██  ██  ");
    koor(55,36); printf(" ███████ ██ ███████    ██    ██    ██ ██████    ████   ");
    koor(55,37); printf(" ██   ██ ██      ██    ██    ██    ██ ██   ██    ██    ");
    koor(55,38); printf(" ██   ██ ██ ███████    ██     ██████  ██   ██    ██    ");
                                                                                    
    SetConsoleOutputCP(437);
}

void pilihhistory() {
    system("cls");
    textcolor(4);
    backgroundcolor(15);
    koor(2,2); printf("ESC UNTUK KEMBALI");
    tekshistory();
    gambar();
    historybooking();

}

void history() {
     system("cls");
     pilihhistory();
     getch();
     cekmenu = 1;
}

void modehalamanmenu(int halamanmenu){

    switch (halamanmenu)
    {
    case 1:
        booking();
        if(cekmenu == 1){
            cekmenu = 0;
            tampmenu();
            modehalamanmenu(halamanmenu);
        }
        break;
    case 2:
        history();
        if(cekmenu == 1){
            cekmenu = 0;
            tampmenu();
            modehalamanmenu(halamanmenu);
        }
        break;
    case 3:
        profile();
        if(cekmenu == 1){
            cekmenu = 0;
            tampmenu();
            modehalamanmenu(halamanmenu);
        }
        break;
    }
}

void framemenu(int f){
    if (f == 0){
        tampmenu1();
        halamanmenu = 1;
    }
    else if (f == 1){
        tampmenu2();
        halamanmenu = 2;
    }
    else if (f == 2){
        tampmenu3();
        halamanmenu = 3;
    }
}
void pilihanamenu(){
    int f = 0;
    char inp;
    while ((inp = getch()) != 13)
    {
        if (inp == 72){
            f--;
            // 72 = ARROW ATAS
        }
        else if(inp == 80){
            f++;
            // 80 = ARROW BAWAH
        }
        else if(inp == 77){
            f++;
            // 77 = ARROW KANAN
        }
        else if(inp == 75){
            f--;
            // 75 = ARROW KIRI
        }
        else if(inp == 27){
            tamppilih();
            modehalaman(halaman);
            break;
            // 27 = TOMBOL ESC
        }
        if (f < 0){
            f = 0;
        }
        else if (f > 2){
            f = 2;
        }
        framemenu(f);
    }
}

void tampmenu() {
    textcolor(4);
    backgroundcolor(15);
    judul();
    garisjudul();
    koor(2,2); printf(">> ESC UNTUK LOGOUT");
    gambar();
    framemenu(0);
    pilihanamenu();
}

void dutchvilla(){
    system("pause");
    intro();
    userpilih(); 

}