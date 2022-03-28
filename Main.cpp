#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include "ArrayList.h"
#include <chrono>

using namespace std;

void SureHesaplama(auto begin, string listAdi); // süre hesaplıyor

int main()
{
    auto beginList = std::chrono::high_resolution_clock::now();
    cout << "Linked list ile işlemler: " << endl;
    LinkedList *linkedList = new LinkedList();
    linkedList->yazdir();
    linkedList->olustur();
    linkedList->yazdir();
    linkedList->ekle(3, 0);
    linkedList->yazdir();
    linkedList->ekle(5, 0);
    linkedList->yazdir();
    linkedList->ekle(7, 1);
    linkedList->yazdir();
    linkedList->ekle(4, 2);
    linkedList->yazdir();
    linkedList->guncelle(15, 1);
    linkedList->yazdir();
    linkedList->sil(2);
    linkedList->yazdir();
    linkedList->bosalt();
    linkedList->yazdir();

    cout << "" << endl;
    SureHesaplama(beginList, "Linked");
    cout << "" << endl;

    auto beginArray = std::chrono::high_resolution_clock::now();
    cout << "Array list ile işlemler: " << endl;
    ArrayList *arrayList = new ArrayList();
    arrayList->olustur();
    arrayList->yazdir();
    arrayList->ekle(3, 0);
    arrayList->yazdir();
    arrayList->ekle(5, 0);
    arrayList->yazdir();
    arrayList->ekle(7, 1);
    arrayList->yazdir();
    arrayList->ekle(4, 2);
    arrayList->yazdir();
    arrayList->guncelle(15, 1);
    arrayList->yazdir();
    arrayList->sil(2);
    arrayList->yazdir();
    arrayList->bosalt();
    arrayList->yazdir();

    cout << "" << endl;
    SureHesaplama(beginArray, "Array");
    cout << "" << endl;
    return 0;
}

void SureHesaplama(auto begin, string listAdi) // ikinci parametre arrayList üzerinde mi yoksa linked list üzerinde işlem yaptığımızı belli ediyor
{
    auto endArray = std::chrono::high_resolution_clock::now();
    auto elapsedArray = std::chrono::duration_cast<std::chrono::microseconds>(endArray - begin);
    cout << listAdi << " list ekleme suresi => " << elapsedArray.count() << " mikro-saniye" << endl;
}