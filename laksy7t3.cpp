#include <iostream>

class Hevonen {
private:
    float kavionKoko;

public:
    Hevonen(float koko) : kavionKoko(koko) {}

    float haeKavionKoko() const {
        return kavionKoko;
    }

    bool operator<(const Hevonen& toinen) const {
        return kavionKoko < toinen.haeKavionKoko();
    }
};

template <typename T>
void kuplaJärjestä(T arr[], int koko) {
    for (int i = 0; i < koko - 1; ++i) {
        for (int j = 0; j < koko - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
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
        std::cout << arr[i].haeKavionKoko() << " ";
    }
    std::cout << std::endl;
}

int main() {
    const int hevostenMaara = 5;
    Hevonen hevoset[hevostenMaara] = { Hevonen(15.0), Hevonen(12.5), Hevonen(18.2), Hevonen(14.8), Hevonen(16.3) };

    std::cout << "Alkuperäinen Hevosten taulukko: ";
    tulostaTaulukko(hevoset, hevostenMaara);

    kuplaJärjestä(hevoset, hevostenMaara);

    std::cout << "Järjestetty Hevosten taulukko: ";
    tulostaTaulukko(hevoset, hevostenMaara);

    return 0;
}

