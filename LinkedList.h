#include <iostream>
#include <stdlib.h>
#include "ListNode.h"

using namespace std;

struct Liste
{
    Node *bas;
    void Olustur();
    void Ekle(int, int);
    void Guncelle(int, int);
    void Sil(int);
    void Yazdir();
    void Bosalt();
    int sayac;
};

void Liste::Olustur()
{
    bas = NULL; // boş bir liste oluşturduk
    sayac = 0;
}

void Liste::Ekle(int deger, int indis)
{
    Node *newNode = new Node();
    Node *tara;
    tara = bas;

    newNode->deger = deger; // newNode düğümünün değerine değeri atadık

    if (bas == NULL)
    {
        newNode->sonraki = NULL;
        bas = newNode;
        sayac++;
        return;
    }

    if (indis == 0)
    {
        newNode->sonraki = bas; // newNode düğümünün sonraki adresine listenin ilk düğüm adresi diyoruz
        bas = newNode;          // newNode değeri bas'a geçer
        sayac++;                // listenin elamınını 1 arttırdık
        return;
    }

    for (int i = 0; i < sayac; i++)
    {

        if (i == indis - 1) // benim istediğim indisin birsonrakine eklediği için indisi bir eksilttim
        {
            newNode->sonraki = tara->sonraki; // taradan sonraki adresi newNode'dan sonra gelen adrese atadık
            tara->sonraki = newNode;          // taradan sonraki adrese newNode adresinin içindeki elemanı atadık
            break;
        }
        tara = tara->sonraki; // tara tüm listeyi gezmesi için yaptık
    }
    sayac++;
}

void Liste::Guncelle(int deger, int indis)
{
    Node *newNode = new Node();
    Node *tara;
    tara = bas;

    newNode->deger = deger;

    if (bas == NULL)
    {
        return;
    }

    for (int i = 0; i < sayac; i++)
    {

        if (i == indis)
        {
            newNode->sonraki = tara->sonraki;
            *tara = *newNode;
            break;
        }
        tara = tara->sonraki;
    }
}

void Liste::Sil(int indis)
{
    Node *tara;
    Node *tut;
    tara = bas; // ilk elemanı yedekledik

    if (bas == NULL)
        return;
    if (indis < 0)
    {
        cout << "Böyle bir indis bulunmamaktadır.\n";
        return;
    }
    if (indis == 0)
    {
        bas = bas->sonraki; // ilk elemanı ikinci eleman yapıyoruz
        delete tara;        // ilk elemanı sildik
        sayac--;
        return;
    }
    for (int i = 0; i < sayac; i++)
    {
        if (i == indis - 1)
        {
            tut = tara->sonraki;          // tara silinecek düğümden bir önceki düğüm olduğu için taradan sonraki yani silinecek düğümü tutuyoruz.
            tara->sonraki = tut->sonraki; // silinecek düğümden sonraki düğümü ile silinecek düğümden önceki düğümü birbirine bağlıyoruz
            delete tut;
            break;
        }
        tara = tara->sonraki;
    }
}

void Liste::Bosalt()
{
    Node *tut;

    while (bas) // ilk düğüm olduğu sürece döngü devam eder
    {
        tut = bas;          // ilk düğümü tutuyoruz
        bas = bas->sonraki; // ilk düğümü ikinci düğümü yapıyoruz
        delete tut;
    }
    sayac = 0;
}

void Liste::Yazdir()
{
    // bas işaretçisine dokunma çünkü ipin ucu kaçarsa diğer verilerde kaybolur
    Node *tara; // geçici pointer
    tara = bas;
    if (!tara)
    {
        cout << "Liste bos!!" << endl;
        return;
    }

    while (tara)
    {
        cout << tara->deger << " ";
        tara = tara->sonraki;
    }
    cout << endl;
}
