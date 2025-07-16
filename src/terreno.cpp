#include "terreno.h"
#include <fstream>
#include <iostream>
#include <string>

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

void Terreno::diamond(int x, int y, int size) {
    int media = (matrizAltitudes [x] [y] + matrizAltitudes [x + size] [y] + matrizAltitudes [x] [y + size] + matrizAltitudes [x + size] [y + size]) / 4;
    matrizAltitudes [x + (size / 2)] [y + (size / 2)] = media;
    return;
}

void Terreno::diamondSquare(int size, double rugosidade) {
    /* aqui a gente tem que gerar aleatoriamente os valores
    dos 4 cantos da matriz */
    size = lado - 1;
    while (size > 1) {
        // etapa diamond
        for (int i = 0; i < lado - 1; i += size) {
            for (int j = 0; j < lado - 1; j += size) {
                diamond(i, j, size);
            }
        }
        // etapa square
        

        size /= 2;
    }
}

void Terreno::writeAltitudes(std::string arquivo) {
    std::ofstream file(arquivo);
    if (!file.is_open()) {
        std::cout << "Erro de abertura" << std::endl;
        return;
    }
    file << lado << " " << lado << "\n";
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            file << matrizAltitudes [i] [j];
            if (j != lado - 1) {
                file << " ";
            }
        }
        if (i != lado - 1) {
            file << "\n";
        }
    }
    file.close();
    return;
}


void Terreno::readAltitudes(std::string arquivo) {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        std::cout << "Erro de abertura" << std::endl;
        return;
    }

    std::string sizeLinha;
    std::getline(file, sizeLinha);
    int espaco = sizeLinha.find(' ');
    lado = std::stoi(sizeLinha.substr(0, espaco));

    if (matrizAltitudes) {
        for (int i = 0; i < lado; ++i)
            delete[] matrizAltitudes[i];
        delete[] matrizAltitudes;
    }

    matrizAltitudes = new int *[lado];
    for (int i = 0; i < lado; i++) {
        matrizAltitudes[i] = new int[lado];
    }

    int i = 0;
    std::string linha;
    while (std::getline(file, linha) && i < lado) {
        int j = 0;
        std::string num = "";

        for (char c : linha) {
            if (c == ' ') {
                if (num != "") {
                    matrizAltitudes[i][j++] = std::stoi(num);
                    num = "";
                }
            } else {
                num += c;
            }
        }

        if (num != "" && j < lado) {
            matrizAltitudes[i][j++] = std::stoi(num);
        }

        i++;
    }

    file.close();
}


int main() {
    Terreno malha (2);
    malha.readAltitudes("mapa.txt");
    malha.diamondSquare(1, 0.5);
    for (int i = 0; i < malha.getLinhas(); i++) {
        for (int j = 0; j < malha.getColunas(); j++) {
            std::cout << malha.matrizAltitudes [i] [j] << " ";
        }
        std::cout << std::endl;
    }
}