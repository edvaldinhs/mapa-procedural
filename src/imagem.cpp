#include "cor.h"
#include "paleta.h"
#include "imagem.h"
#include <iostream>
#include <fstream>
#include <string>

//Construtor de Imagem.
Imagem::Imagem(int comp, int alt) {
        comprimento = comp;
        altura = alt;
        pixels = criaPixel();
    }

//Destrutor de Imagem.
Imagem::~Imagem() {
    if (pixels) {
        for (int i = 0; i < comprimento; ++i) {
            delete[] pixels[i];
        }
        delete[] pixels;
        pixels = nullptr;
    }
}

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

void Imagem::criarImagem(Paleta imgPaleta, std::string arquivo) {
    std::ofstream file(arquivo);
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

void Imagem::escurecer(double fator) {

    if (fator < 0.0) fator = 0.0;
    if (fator > 1.0) fator = 1.0;

    for (int i = 0; i < comprimento; ++i) {
        for (int j = 0; j < altura; ++j) {
            Cor &pixel = pixels[i][j];

            pixel.r = (int)(pixel.r * fator);
            pixel.g = (int)(pixel.g * fator);
            pixel.b = (int)(pixel.b * fator);

            if (pixel.r < 0) pixel.r = 0; if (pixel.r > 255) pixel.r = 255;
            if (pixel.g < 0) pixel.g = 0; if (pixel.g > 255) pixel.g = 255;
            if (pixel.b < 0) pixel.b = 0; if (pixel.b > 255) pixel.b = 255;
        }
    }
}


void Imagem::sombrear(Terreno& terreno, double fator){
	if (fator < 0.0) fator = 0.0;
    if (fator > 1.0) fator = 1.0;

    for (int i = 0; i < comprimento; ++i) {
        for (int j = 0; j < altura; ++j) {
					if(i+1 < comprimento && j+1 < altura){
						int altAtual = terreno.getAltitude(i,j);
						int altDiag = terreno.getAltitude(i+1,j+1);
						if(altDiag < altAtual){
							Cor &pixel = pixels[i][j];

							pixel.r = (int)(pixel.r * fator);
							pixel.g = (int)(pixel.g * fator);
							pixel.b = (int)(pixel.b * fator);

							if (pixel.r < 0) pixel.r = 0; if (pixel.r > 255) pixel.r = 255;
							if (pixel.g < 0) pixel.g = 0; if (pixel.g > 255) pixel.g = 255;
							if (pixel.b < 0) pixel.b = 0; if (pixel.b > 255) pixel.b = 255;
						}
        }
			}
    }
}