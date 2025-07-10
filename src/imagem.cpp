#include "cor.h"
#include "paleta.h"
#include "imagem.h"
#include <iostream>
#include <fstream>
#include <string>

int Imagem::getComp() {
    return comprimento;
}

int Imagem::getAlt() {
    return altura;
}

Cor **Imagem::criaPixel() {
        Cor **matrizPixels = new Cor *[comprimento];
        for (int i = 0; i < comprimento; i++) {
            matrizPixels [i] = new Cor [altura];
        }
        return matrizPixels;
    }

Cor Imagem::getPixel(int comp, int alt) {
    return pixels[comp][alt];
}

void Imagem::setPixel(int comp, int alt, Cor doPixel) {
    pixels [comp] [alt] = doPixel;
}

void Imagem::criarImagem(Paleta imgPaleta, Imagem img) {
    std::ofstream file("flag.ppm");
    if (!file.is_open()) {
        std::cout << "Erro de abertura" << std::endl;
        return;
    }
    file << "P3\n";
    file << comprimento << " " << altura << "\n";
    file << "255\n";
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < comprimento; j++) {
            file << getPixel(j, i).r << " " << getPixel(j, i).g << " " << getPixel(j, i).b;
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
    Paleta paleta("paleta.txt");
    Imagem fotoDoc(6, 3);
    for (int i = 0; i < fotoDoc.getComp(); i++) {
        for (int j = 0; j < fotoDoc.getAlt(); j++) {
            if (j == 0) {
                fotoDoc.setPixel(i, j, paleta.getCor(8));
            }
            else if (j == 2) {
                fotoDoc.setPixel(i, j, paleta.getCor(7));
            }
            else {
                fotoDoc.setPixel(i, j, paleta.getCor(9));
            }
                    
        }
    }
    // fotoDoc.setPixel(0, 0, paleta.getCor(7));
    fotoDoc.criarImagem(paleta, fotoDoc);
    std::cout << fotoDoc.getPixel(1, 0).r << "\n";
    std::cout << fotoDoc.getPixel(1, 0).g << "\n";
    std::cout << fotoDoc.getPixel(1, 0).b << std::endl;
    return 0;
}