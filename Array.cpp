#include <iostream>
#include <stdlib.h>

using namespace std;

void BasaEkle();
void OrtayaEkle();
void SonaEkle();

int main()
{
    // BasaEkle();
    OrtayaEkle();
    // SonaEkle();
    return 0;
}

void BasaEkle()
{
    int arr[6];
    for (int i = 0; i < 5; i++)
        arr[i] = i;
    cout << "Baslangic dizisi: " << endl;
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    int newValue;
    cout << "Basa eleman ekleyin: ";
    cin >> newValue;
    for (int i = 5; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = newValue;
    cout << "Yeni dizi:" << endl;
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
}

void OrtayaEkle()
{
    int arr[6];
    for (int i = 0; i < 5; i++)
        arr[i] = i;
    cout << "Baslangic dizisi: " << endl;
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;
    int newValue;
    cout << "Ortaya eleman ekleyin: ";
    cin >> newValue;
    for (int i = 5; i > 3; i--)
        arr[i] = arr[i - 1];
    arr[3] = newValue;

    cout << "Yeni dizi: " << endl;
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";
}

void SonaEkle()
{
    int arr[6];
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
    }
    cout << "Baslangic dizisi" << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int newValue;
    cout << "Sona eleman ekleyin: ";
    cin >> newValue;
    arr[5] = newValue;

    cout << "Yeni dizi" << endl;
    for (int i = 0; i < 6; i++)
        cout << arr[i] << " ";

    int *newArray = new int[7];
    for (int i = 0; i < 6; i++)
    {
        newArray[i] = arr[i];
    }

    cout << "Sona eleman ekleyin: ";
    cin >> newValue;
    newArray[6] = newValue;

    cout << "Yeni dizi" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << newArray[i] << " ";
    }
}
