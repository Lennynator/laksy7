#include <iostream>

template <typename T>
void kuplaJärjestä(T arr[], int koko) {
    for (int i = 0; i < koko - 1; ++i) {
        for (int j = 0; j < koko - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void tulostaTaulukko(const T arr[], int koko) {
    for (int i = 0; i < koko; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int intTaulukonKoko = 5;
    int intTaulukko[intTaulukonKoko] = { 5, 2, 9, 1, 7 };

    const int floatTaulukonKoko = 4;
    float floatTaulukko[floatTaulukonKoko] = { 3.5, 1.2, 9.8, 2.1 };

    std::cout << "Alkuperäinen int-taulukko: ";
    tulostaTaulukko(intTaulukko, intTaulukonKoko);

    kuplaJärjestä(intTaulukko, intTaulukonKoko);

    std::cout << "Järjestetty int-taulukko: ";
    tulostaTaulukko(intTaulukko, intTaulukonKoko);

    std::cout << "\nAlkuperäinen float-taulukko: ";
    tulostaTaulukko(floatTaulukko, floatTaulukonKoko);

    kuplaJärjestä(floatTaulukko, floatTaulukonKoko);

    std::cout << "Järjestetty float-taulukko: ";
    tulostaTaulukko(floatTaulukko, floatTaulukonKoko);

    return 0;
}
