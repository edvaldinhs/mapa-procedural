#include "cor.h"
#include "paleta.h"
#include <iostream>
#include <fstream>
#include <string>

void criarImagem(Paleta imgPaleta, int comprimento, int altura) {
    std::ofstream file("mapa.ppm");
    if (!file.is_open()) {
        std::cout << "Erro de abertura" << std::endl;
        return;
    }
    file << "P3\n";
    file << comprimento << " " << altura << "\n";
    file << "255\n";
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < comprimento; j++) {
            file << imgPaleta.getCor(2).r;
            if (j != comprimento - 1) {
                file << " ";
            }
        }
        if (i != altura - 1) {
            file << "\n";
        }
    }
    file.close();
}

int main() {
    Paleta paleta("../paleta.ppm");
    criarImagem(paleta, 4, 7);
    return 0;
}