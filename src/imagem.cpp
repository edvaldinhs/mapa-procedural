#include "cor.h"
#include "paleta.h"
#include "imagem.h"
#include <iostream>
#include <fstream>
#include <string>

void Imagem::criarImagem(Paleta imgPaleta, Imagem img) {
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
            file << imgPaleta.getCor(5).r << " " << imgPaleta.getCor(5).g << " " << imgPaleta.getCor(5).b;
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
    Imagem img(4, 7);
    img.criarImagem(paleta, img);
    return 0;
}