/*
 * Ahmet Galip Sengun
 * 20/02/2020
 * Bu program terminale kullanicinin secimine gore duz ucgen, ters ucgen veya elmas bastirir.
 */

#include <iostream>

using namespace std;

void DuzUcgen(int);
void TersUcgen(int);

int main()
{
    int n,boyut=0,ctr=0;
    cout << "Yapilacak islemi seciniz:" << endl;
    cout << "1: Duz ucgen\n2: Ters ucgen\n3: Elmas\n0: Cikis" << endl;
    cin >> n; // hangi islemin yapilacagýný belirleme
    if (n<0 || n>=4){
        cout << "Gecersiz sayi girildi"; // 1,2,3 veya 0 girilmediyse program -1 doner ve sonlanir
        return -1;
    }
    if (n==0){
        cout << "Cikis yapiliyor.." << endl; // kullanici '0' girerse program sonlanir
        return 0;
    }

    while (1){ // boyut alma

        if (n==1 || n==2){
            cout << "Boyut giriniz: " << endl;
            cin >> boyut;
            if (boyut%2 == 0 || boyut<3 || boyut>15){// eger boyut belirli aralýklarda degilse
                cout << "Hatali boyut girdiniz!" << endl;
                ctr++;
            }
        else
            break; // gecerli bir boyut degeri girildiyse donguden cikilir
        }
        if (n==3){
            cout << "Boyut giriniz: " << endl;
            cin >> boyut;
            if (boyut%2 == 0 || boyut<5 || boyut>15){
            cout << "Hatali boyut girdiniz!" << endl;
            ctr++;
            }
        else
            break; // gecerli bir boyut degeri girildiyse donguden cikilir
        }
        if (ctr==3){ // eger 3 kere hatali boyut girildiyse program hata mesaji verir ve kapanir.
            cout << "3 kere hatali giris yaptiniz\nProgram sonlandiriliyor.." << endl;
            return -1;
        }
    }
    switch (n) { // sekil bastýrma
        case 1: DuzUcgen(boyut);
            break;
        case 2: TersUcgen(boyut);
            break;
        case 3: DuzUcgen(boyut);// elmas seklini bastirmak icin düz ücgen ve ters ucgen fonksiyonu sirasiyla caðirilir
                TersUcgen(boyut);
            break;
        default:
            cout << "hatali islem" << endl; // hata durumu icin
            return -1;
    }

    return 0;
}

void DuzUcgen(int n) // duz ucgen yazdýrma fonksiyonu
{
    for (int i = 0;i < (n + 1) / 2;i++) {

        for (int j = 1;j <= (n - 1) / 2 - i;j++) {
            cout << " ";
        }
        for (int k = 0;k <= 2 * i;k++)
            cout << "*";
        cout << endl;
    }
}

void TersUcgen(int n) { // ters ucgen yazdýrma fonksiyonu
    int i = 0, j = 0, k = 0;

    while (i < (n + 1) / 2) {
        while (k < i) {
            cout << " ";
            k++;
        }
        while (j < n - i * 2) {
            cout << "*";
            j++;
        }
        cout << endl;
        i++, j = 0, k = 0;
    }
}
