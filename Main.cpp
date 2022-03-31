#include <iostream>
#include <stdlib.h>
#include "LinkedList.h"
#include "ArrayList.h"
#include <chrono>

using namespace std;

void linkedListProporty();
void arrayListProporty();

int main()
{
    linkedListProporty();
    arrayListProporty();
    return 0;
}

void linkedListProporty()
{
    auto beginList = std::chrono::high_resolution_clock::now();
    cout << "Linked list ile işlemler: " << endl;
    LinkedList *linkedList = new LinkedList();
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
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - beginList);
    cout << "Linked List ekleme suresi => " << elapsed.count() << " mikro-saniye" << endl;
    cout << "" << endl;
}

void arrayListProporty()
{
    auto beginArray = std::chrono::high_resolution_clock::now();
    ArrayList *arrayList = new ArrayList();
    cout << "Array list ile işlemler: " << endl;
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
    auto endArray = std::chrono::high_resolution_clock::now();
    auto elapsedArray = std::chrono::duration_cast<std::chrono::microseconds>(endArray - beginArray);
    cout << "Array ekleme suresi => " << elapsedArray.count() << " mikro-saniye" << endl;
    cout << "" << endl;
}
