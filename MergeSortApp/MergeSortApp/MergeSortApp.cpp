
#include <iostream>
#include <vector>

#include "MergeSort.h"

using namespace std;

/**
 * @brief Wyświetla zawartość tablicy.
 *
 * @tparam T Typ elementów tablicy.
 * @param array Tablica przeznaczona do wyświetlenia.
 */
template <typename T>
void printArray(const vector<T>& array)
{
    for (const T& element : array)
    {
        cout << element << " ";
    }

    cout << endl;
}

/**
 * @brief Funkcja główna programu.
 *
 * Tworzy dwie tablice różnych typów:
 * int oraz double.
 *
 * Następnie sortuje je przy użyciu szablonowej klasy MergeSort.
 *
 * @return 0, jeśli program zakończył działanie poprawnie.
 */
int main()
{
    // Tablica zawierająca liczby całkowite.
    vector<int> intArray = {
        10, 5, 8, 2, 15, 1, 20, 3
    };

    // Tablica zawierająca liczby zmiennoprzecinkowe.
    vector<double> doubleArray = {
        5.5, 2.2, 8.8, -1.5, 3.3, 0.7
    };

    // Wyświetlenie tablicy int przed sortowaniem.
    cout << "Tablica int przed sortowaniem:" << endl;
    printArray(intArray);

    // Wyświetlenie tablicy double przed sortowaniem.
    cout << "\nTablica double przed sortowaniem:" << endl;
    printArray(doubleArray);

    // Sortowanie tablicy liczb całkowitych.
    MergeSort<int>::sort(intArray);

    // Sortowanie tablicy liczb zmiennoprzecinkowych.
    MergeSort<double>::sort(doubleArray);

    // Wyświetlenie posortowanej tablicy int.
    cout << "\nTablica int po sortowaniu:" << endl;
    printArray(intArray);

    // Wyświetlenie posortowanej tablicy double.
    cout << "\nTablica double po sortowaniu:" << endl;
    printArray(doubleArray);

    return 0;
}
