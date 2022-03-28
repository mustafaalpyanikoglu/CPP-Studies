#include <iostream>
#include <stdlib.h>

using namespace std;

struct ArrayList
{
    int *bas;                // dizinin başlangıç adresini tutar
    void olustur();          // başlangıç için gereken tanımları içerir
    void ekle(int, int);     // değer ve sıra numarası alarak ekleme yapar
    void guncelle(int, int); // değer ve sıra numarası alarak günceller
    void sil(int);           // sıra numarası alarak silme yapar
    void yazdir();           // liste içeriğini ekrana yazar
    void bosalt();           // listenin bellek alanlarını iade eder
    int sayac;               // liste kaç eleman olduğunu tutar
};

void ArrayList::olustur()
{
    sayac = 10;
    bas = new int[sayac];           // arrayi oluşturduk ve adresini bas'a atadık
    for (int i = 0; i < sayac; i++) // tüm array elemanlarına 0 atıyoruz
    {
        bas[i] = 0;
    }
}

void ArrayList::yazdir()
{
    // bas işaretçisine dokunma çünkü ipin ucu kaçarsa diğer verilerde kaybolur
    if (sayac == 0)
    {
        cout << "Liste bos!!" << endl;
        return;
    }

    for (int i = 0; i < sayac; i++) // array'i yazdırıyoruz
    {
        cout << bas[i] << " ";
    }
    cout << endl;
}

void ArrayList::ekle(int deger, int indis)
{
    for (int i = sayac; indis < i; i--) // değiştirmek istediğimiz indisten büyük indisleri bir arttırıyoruz ve istediğimiz indis boş kalıyor
    {
        bas[i] = bas[i - 1];
    }
    bas[indis] = deger; // istediğimiz indise değeri atıyoruz
    cout << indis << ". indise " << deger << " ekliyoruz" << endl;
    sayac++;
}

void ArrayList::guncelle(int deger, int indis)
{
    int tut;
    for (int i = 0; i < sayac; i++) // Array'i dönüyoruz
    {
        if (i == indis) // istediğimiz indise geldiğinde o değeri istediğimiz değerle değiştiriyoruz
        {
            tut = bas[i]; // hangi değeri değiştirdiğimizi yazmak için int değerde tutuyoruz
            bas[i] = deger;
        }
    }
    cout << indis << ". indisdeki " << tut << " değerini " << deger << " ile değiştiriyoruz." << endl;
}

void ArrayList::sil(int indis)
{
    for (int i = indis; i < sayac; i++) // istediğimiz indisten büyük indisleri bir küçük indisine yazarak ilerliyoruz bu arada istediğimiz indisde silinmiş oluyor
    {
        bas[i] = bas[i + 1];
    }
    cout << indis << ". indisdeki degeri sildik" << endl;
    sayac--;
}

void ArrayList::bosalt()
{
    sayac = 0;
    for (int i = 0; i < sayac; i++) // tüm array elemanlarını tek tek siliyoruz.
    {
        delete bas;
    }
    cout << "Listeyi boşaltıyoruz" << endl;
}
