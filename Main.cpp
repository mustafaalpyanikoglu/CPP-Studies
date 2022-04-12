#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include "ArrayList.h"
#include <chrono>

using namespace std;

void linkedListProporty(int listSize);
void arrayListProporty(int arraySize);

int main()
{
    //---------------Linked List Islemleri----------------------
    linkedListProporty(100);
    linkedListProporty(1000);
    linkedListProporty(10000);

    //---------------Array List Islemleri----------------------
    arrayListProporty(100);
    arrayListProporty(1000);
    arrayListProporty(10000);
    return 0;
}

void linkedListProporty(int listSize)
{
    auto beginList = std::chrono::high_resolution_clock::now();
    cout << listSize << " Elemanlı Linked list ile ekleme-güncelleme-silme işlemler: " << endl;
    LinkedList *linkedList = new LinkedList();
    linkedList->olustur();
    for (int i = 0; i < listSize; i++)
    {
        linkedList->ekle(i, i);
    }
    cout << "Linked list ekleme işlemler: " << endl;
    linkedList->ekle(3, 0);
    cout << "   Başa eleman ekledik" << endl;
    linkedList->ekle(3, linkedList->sayac / 2);
    cout << "   Ortaya eleman ekledik" << endl;
    linkedList->ekle(3, linkedList->sayac);
    cout << "   Sona eleman ekledik" << endl;
    cout << "" << endl;

    cout << "Linked list güncelleme işlemler: " << endl;
    linkedList->guncelle(7, 0);
    linkedList->guncelle(7, linkedList->sayac / 2);
    linkedList->guncelle(7, linkedList->sayac - 1);
    cout << "" << endl;

    cout << "Linked list silme işlemler: " << endl;
    linkedList->sil(0);
    linkedList->sil(linkedList->sayac / 2);
    linkedList->sil(linkedList->sayac - 1);
    cout << "" << endl;

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - beginList);
    cout << "Linked List işlem suresi => " << elapsed.count() << " mikro-saniye" << endl;
    cout << "" << endl;
}

void arrayListProporty(int arraySize)
{
    auto beginArray = std::chrono::high_resolution_clock::now();
    ArrayList *arrayList = new ArrayList();
    cout << arraySize << " Elemanlı array list ile ekleme-güncelleme-silme işlemler: " << endl;
    arrayList->olustur();
    for (int i = 0; i < arraySize - 1; i++)
    {
        arrayList->ekle(i, i);
    }
    arrayList->ekle(3, 0);
    cout << "   Başa eleman ekledik" << endl;
    arrayList->ekle(3, arrayList->sayac / 2);
    cout << "   Ortaya eleman ekledik" << endl;
    arrayList->ekle(3, arrayList->sayac);
    cout << "   Sona eleman ekledik" << endl;
    cout << "" << endl;

    cout << "Array güncelleme işlemleri: " << endl;
    arrayList->guncelle(7, 0);
    arrayList->guncelle(7, arrayList->sayac / 2);
    arrayList->guncelle(7, arrayList->sayac - 1);
    cout << "" << endl;

    cout << "Array silme işlemleri: " << endl;
    arrayList->sil(0);
    arrayList->sil(arrayList->sayac / 2);
    arrayList->sil(arrayList->sayac - 1);
    cout << "" << endl;
    auto endArray = std::chrono::high_resolution_clock::now();
    auto elapsedArray = std::chrono::duration_cast<std::chrono::microseconds>(endArray - beginArray);
    cout << "Array ekleme suresi => " << elapsedArray.count() << " mikro-saniye" << endl;
    cout << "" << endl;
}
