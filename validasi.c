#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>


void gotoxy(int x,int y){
    COORD gotoxy;
    gotoxy.X=x;
    gotoxy.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),gotoxy);
}

/////////////////////
//    validasi     //
/////////////////////

// validasi nama
char *valnama(char *nama)
{
    char input;
    char tamp[100] = {};
    int index = 0;
    while ((input = getch()) != 13 || index < 2 || (index > 0 && tamp[index - 1] == ' '))
    {
        if (index < 21 && input != 13 && ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z') || (input == ' ' && index > 0 && tamp[index - 1] != ' ')))
        {
            printf("%c", input);
            tamp[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            index--;
            tamp[index] = '\0';
        }
    }
    printf("\n");
    return strcpy(nama, tamp);
}

// validasi umur
char *valumur(char *umur)
{
    char input;
    int index = 0;
    while ((input = getch()) != 13 || index < 1)
    {
        if ((input >= '1' && input <= '9' && index == 0) || (input >= '0' && input <= '9' && index != 0) && index < 2)
        {
            printf("%c", input);
            umur[index] = input;
            index++;
        }
        else if (input == 8 && index != 0)
        {
            printf("\b \b");
            umur[index] = '\0';
            index--;
        }
    }
    umur[index] = '\0';
    int batas;
    batas = atoi(umur);
    if (batas < 18)
    {
        for (int i = 1; i <= 3; i++)
        {
            gotoxy(60,18);
            printf("(Anda Belum Cukup Umur)");
            Sleep(1000);
            gotoxy(60,18);
            printf("                       ");
            Sleep(100);
        }
        gotoxy(50,18);
        printf("  ");
        gotoxy(50,18);
        valumur(umur);
    }
}

// validasi username
char *valuser(char *user)
{
    char input;
    char tamp[100] = {};
    int index = 0;
    while ((input = getch()) != 13 || index < 3)
    {
        if (index < 10 && (input >= 'a' && input <= 'z'))
        {
            printf("%c", input);
            tamp[index++] = input;
        }
        else if (input == 8 && index > 0)
        {
            printf("\b \b");
            tamp[--index] = '\0';
        }
    }
    printf("\n");
    return strcpy(user, tamp);
}

// validasi password
char *valpass(char *pass)
{
    char input;
    char tamp[100] = {};
    int index = 0, angka = 0;
    while ((input = getch()) != 13 || index < 8 || angka < 3)
    {
        if (index < 15 && (input >= 'a' && input <= 'z'))
        {
            printf("*");
            tamp[index++] = input;
        }
        else if (input >= '0' && input <= '9' && index < 15)
        {
            printf("*");
            tamp[index++] = input;
            angka++;
        }
        else if (input == 8 && index > 0)
        {
            if (tamp[index-1] >= '0' && tamp[index-1] <= '9')
                angka--;
            printf("\b \b");
            tamp[--index] = '\0';
        }
    }
    printf("\n");
    return strcpy(pass, tamp);
}

void v_email()
{
    char inputan;
    char bag[99] = {};
    int index = 0;
    while ((inputan = getch()) != 13 || index < 3)
    {
        if (index < 16 && (inputan >= 'a' && inputan <= 'z'
        || inputan >= 'A' && inputan <= 'Z' || inputan == ' ' && index != 0 && bag[index - 1] != ' '
        || inputan >= '0' && inputan <= '9'))
        {
            printf("%c", inputan);
            bag[index] = inputan;
            index++;
        }
        else if (inputan == 8 && index != 0)
        {
            printf("\b \b");
            index -= 1;
            bag[index] = ' ';
        }
    }
    
    printf("@gmail.com");
    // strcpy(tamp, bag);
    // strcpy(tamp, strcat(tamp, "@gmail.com"));
}


char *valnohp(char *telp)
{
    char input;
    char tamp[100] = {};
    int index = 0, x = 0;

    while ((input = getch()) != 13 || index < 11)
    {
        if (index < 13 && (index == 0 && input == '0' || index == 1 && input == '8' ||
                           index >= 2 && input >= '0' && input <= '9'))
        {
            if (index >= 2 && input == tamp[index - 1])
            {
                x++;
                if (x > 3)
                {
                    input = 0;
                }
            }
            else
            {
                x = 0;
            }

            if (input != 0)
            {
                printf("%c", input);
                tamp[index++] = input;
            }
        }
        else if (input == 8 && index > 0)
        {
            printf("\b \b");
            if (index >= 2 && tamp[index-1] == tamp[index-2])
                x--;
            index--;
            tamp[index] = '\0';
        }
    }

    printf("\n");
    return strcpy(telp, tamp);
}

char *valpilihan(char *pilihan) {
    char input;
    char temp[100] = {};
    int index = 0;
    int pil = 0; 

    while (!pil) {
        input = getch();
        
        if (index <= 2 && input >= '0' && input <= '9') { 
            printf("%c", input);
            temp[index] = input;
            index++;
        } else if (input == 8 && index > 0) {
            printf("\b \b");
            index--;
            temp[index] = '\0';
        } else if (input == 13 && index >= 1) {
            pil = 1;
        }
    }

    temp[index] = '\0'; 
    return strcpy(pilihan, temp);
}

char *valmalam(char *malam) {
    char inp;
    char tomp[100] = {};
    int idx = 0;
    int a = 0;

    while (!a) {
        inp = getch();
        
        if (idx < 3 && inp >= '0' && inp <= '9') {
            printf("%c", inp);
            tomp[idx] = inp;
            idx++;
        } else if (inp == 8 && idx > 0) {
            printf("\b \b");
            idx--;
            tomp[idx] = '\0';
        } else if (inp == 13 && idx > 0) {
            tomp[idx] = '\0';
            if (idx == 1 && tomp[0] == '0') {
                koor(2, 24);
                printf("JUMLAH MALAM TIDAK BOLEH 0!");
                idx = 0;
            } else {
                a = 1;
            }
        }
    }

    tomp[idx] = '\0'; 
    return strcpy(malam, tomp);
}

char *valkonfir(char *konf)
{
    char input;
    char tamp[3] = {};
    int index = 0;

    while (index < 1) 
    {
        input = getch();
        if (input == 'y' || input == 'Y' || input == 't' || input == 'T')
        {
            printf("%c", input);
            tamp[index++] = input;
        }
        else if (input == 8 && index > 0) 
        {
            printf("\b \b");
            index--;
        }
    }

    printf("\n");
    tamp[index] = '\0';
    return strcpy(konf, tamp);
}

char *valbayar(char *bayar) {
    char input;
    char temp[100] = {};
    int index = 0;
    int pil = 0; 

    while (!pil) {
        input = getch();
        
        if (index < 11 && input >= '0' && input <= '9') { 
            printf("%c", input);
            temp[index] = input;
            index++;
        } else if (input == 8 && index > 0) { 
            printf("\b \b");
            index--;
            temp[index] = '\0';
        } else if (input == 13 && index > 0) { 
            pil = 1;
        }
    }

    temp[index] = '\0'; 
    return strcpy(bayar, temp);
}


char *valvilla(char *villabaru)
{
    char inpuv;
    char tamv[100] = {};
    int indev = 0;
    while ((inpuv = getch()) != 13 || indev < 2 || (indev > 0 && tamv[indev - 1] == ' '))
    {
        if (indev < 21 && inpuv != 13 && ((inpuv >= 'a' && inpuv <= 'z') || (inpuv >= 'A' && inpuv <= 'Z') || (inpuv == ' ' && indev > 0 && tamv[indev - 1] != ' ')))
        {
            printf("%c", inpuv);
            tamv[indev] = inpuv;
            indev++;
        }
        else if (inpuv == 8 && indev != 0)
        {
            printf("\b \b");
            indev--;
            tamv[indev] = '\0';
        }
    }
    printf("\n");
    return strcpy(villabaru, tamv);
}

char *valharga(char *harga) {
    char input;
    char temp[100] = {};
    int index = 0;
    int pil = 0; 

    while (!pil) {
        input = getch();
        
        if (index < 11 && input >= '0' && input <= '9') { 
            printf("%c", input);
            temp[index] = input;
            index++;
        } else if (input == 8 && index > 0) { 
            printf("\b \b");
            index--;
            temp[index] = '\0';
        } else if (input == 13 && index > 0) { 
            pil = 1;
        }
    }

    temp[index] = '\0'; 
    return strcpy(harga, temp);
}