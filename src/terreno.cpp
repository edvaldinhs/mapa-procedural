#include "terreno.h"
#include "fstream"
#include <iostream>

int Terreno::getLinhas() {
    return lado;
}

int Terreno::getColunas() {
    return lado;
}

int **Terreno::altitudeDefault(int n) {
    int **matrizAltitudes = new int *[lado];
    for (int i = 0; i < lado; i++) {
        matrizAltitudes [i] = new int [lado];
    }
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            matrizAltitudes [i] [j] = 0;
        }
    }
    return matrizAltitudes;
}

int Terreno::getAltitude(int linha, int coluna) {
    return matrizAltitudes [linha] [coluna];
}

// int **Terreno::diamondSquare(int n, double rugosidade) {

// }

int main() {
    Terreno malha (2);
    for (int i = 0; i < malha.getLinhas(); i++) {
        for (int j = 0; j < malha.getColunas(); j++) {
            std::cout << malha.matrizAltitudes [i] [j] << " ";
        }
        std::cout << std::endl;
    }
}