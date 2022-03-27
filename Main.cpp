#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    Liste *l = new Liste();
    l->Olustur();
    l->Yazdir();

    l->Ekle(3, 0);
    l->Yazdir();
    cout << "Sıfırıncı indise 3 ekledik" << endl;
    l->Ekle(5, 0);
    l->Yazdir();
    cout << "Sıfırıncı indise 5 ekledik" << endl;
    l->Ekle(7, 1);
    l->Yazdir();
    cout << "Birinci indise 7 ekledik" << endl;
    l->Ekle(4, 2);
    l->Yazdir();
    cout << "İkinci indise 4 ekledik" << endl;
    l->Ekle(10, 4);
    l->Yazdir();
    cout << "Dördüncü indise 10 ekledik" << endl;
    l->Guncelle(15, 1);
    l->Yazdir();
    cout << "Birinci indisteki değer olan 7 yi 15 ile değiştirdik" << endl;
    l->Sil(0);
    l->Yazdir();
    cout << "Sıfırıncı indisde bulunan elemanı sildik" << endl;
    l->Bosalt();
    l->Yazdir();
    cout << "Listedeki tüm elemanları sildik" << endl;
    return 0;
}