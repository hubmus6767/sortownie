
#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <cstddef>

/**
 * @brief Szablonowa klasa realizuj¹ca algorytm sortowania przez scalanie.
 *
 * Klasa umo¿liwia sortowanie tablic (std::vector) ró¿nych typów danych,
 * np. int, long int, float oraz double.
 *
 * Typ T musi obs³ugiwaæ operator porównania <.
 *
 * @tparam T Typ elementów przechowywanych w tablicy.
 */
template <typename T>
class MergeSort
{
public:

    /**
     * @brief Sortuje tablicê rosn¹co za pomoc¹ algorytmu MergeSort.
     *
     * Sortowanie odbywa siê bezpoœrednio w przekazanej tablicy.
     * Pusta tablica oraz tablica zawieraj¹ca jeden element
     * nie wymagaj¹ ¿adnych operacji.
     *
     * @param array Tablica (std::vector) przeznaczona do posortowania.
     */
    static void sort(std::vector<T>& array)
    {
        // Nie ma potrzeby sortowania tablicy z mniej ni¿ dwoma elementami.
        if (array.size() < 2)
        {
            return;
        }

        // Tablica pomocnicza wykorzystywana podczas scalania.
        std::vector<T> temp(array.size());

        // Rozpoczêcie sortowania ca³ego zakresu tablicy.
        mergeSort(array, temp, 0, array.size());
    }

private:

    /**
     * @brief Rekurencyjnie dzieli tablicê na mniejsze fragmenty.
     *
     * Funkcja dzieli aktualny zakres na dwie czêœci, sortuje
     * ka¿d¹ z nich, a nastêpnie scala posortowane fragmenty.
     *
     * @param array Sortowana tablica.
     * @param temp Tablica pomocnicza.
     * @param left Pocz¹tkowy indeks zakresu.
     * @param right Koñcowy indeks zakresu (nie jest wliczany).
     */
    static void mergeSort(
        std::vector<T>& array,
        std::vector<T>& temp,
        std::size_t left,
        std::size_t right)
    {
        // Je¿eli zakres zawiera maksymalnie jeden element,
        // jest ju¿ posortowany.
        if (right - left <= 1)
        {
            return;
        }

        // Wyznaczenie œrodka aktualnego zakresu.
        const std::size_t middle = left + (right - left) / 2;

        // Rekurencyjne sortowanie lewej po³owy.
        mergeSort(array, temp, left, middle);

        // Rekurencyjne sortowanie prawej po³owy.
        mergeSort(array, temp, middle, right);

        // Po posortowaniu obu po³ówek ³¹czymy je w jedn¹.
        merge(array, temp, left, middle, right);
    }

    /**
     * @brief Scala dwa s¹siaduj¹ce, posortowane fragmenty tablicy.
     *
     * Elementy z obu fragmentów s¹ porównywane i umieszczane
     * w odpowiedniej kolejnoœci w tablicy pomocniczej.
     * Nastêpnie wynik jest kopiowany do oryginalnej tablicy.
     *
     * @param array Sortowana tablica.
     * @param temp Tablica pomocnicza.
     * @param left Pocz¹tek lewego fragmentu.
     * @param middle Koniec lewego i pocz¹tek prawego fragmentu.
     * @param right Koniec prawego fragmentu (nie jest wliczany).
     */
    static void merge(
        std::vector<T>& array,
        std::vector<T>& temp,
        std::size_t left,
        std::size_t middle,
        std::size_t right)
    {
        // Indeks aktualnie sprawdzanego elementu lewej czêœci.
        std::size_t i = left;

        // Indeks aktualnie sprawdzanego elementu prawej czêœci.
        std::size_t j = middle;

        // Indeks miejsca, w którym zapisujemy kolejny element.
        std::size_t k = left;

        // Porównywanie elementów z obu posortowanych fragmentów.
        while (i < middle && j < right)
        {
            // Wybieramy mniejszy element.
            // Przy równych elementach najpierw wybieramy lewy,
            // dziêki czemu algorytm zachowuje stabilnoœæ sortowania.
            if (!(array[j] < array[i]))
            {
                temp[k] = array[i];
                ++i;
            }
            else
            {
                temp[k] = array[j];
                ++j;
            }

            ++k;
        }

        // Przeniesienie pozosta³ych elementów lewej czêœci.
        while (i < middle)
        {
            temp[k] = array[i];
            ++i;
            ++k;
        }

        // Przeniesienie pozosta³ych elementów prawej czêœci.
        while (j < right)
        {
            temp[k] = array[j];
            ++j;
            ++k;
        }

        // Przepisanie posortowanego fragmentu do oryginalnej tablicy.
        for (std::size_t x = left; x < right; ++x)
        {
            array[x] = temp[x];
        }
    }
};

#endif // MERGESORT_H
