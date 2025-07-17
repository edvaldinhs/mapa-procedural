#include "terreno.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//Construtor de Terreno
Terreno::Terreno(int n) {
        int ladoTemp = 2;
        for (int i = 1; i < n; i++) {
            ladoTemp *= 2;
        }
        lado = ladoTemp + 1;
        matrizAltitudes = altitudeDefault();
    }

//Destrutor de Terreno
Terreno::~Terreno() {
    if (matrizAltitudes) {
        for (int i = 0; i < lado; ++i) {
            delete[] matrizAltitudes[i];
        }
        delete[] matrizAltitudes;
        matrizAltitudes = nullptr;
    }
}


int Terreno::getLinhas() {
    return lado;
}

int Terreno::getColunas() {
    return lado;
}

int **Terreno::altitudeDefault() {
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

void Terreno::diamond(int x, int y, int size, int randmax) {
    int randmin = -randmax;
    int r = (rand() % (randmax - randmin + 1)) + randmin;
    int media = (matrizAltitudes [x] [y] + matrizAltitudes [x + size] [y] + matrizAltitudes [x] [y + size] + matrizAltitudes [x + size] [y + size]) / 4;
    matrizAltitudes [x + (size / 2)] [y + (size / 2)] = media + r;
    return;
}

void Terreno::square(int x, int y, int size, int randmax) {
    int media = 0;
    int meioSize = size / 2;
    int randmin = -randmax;
    int r = (rand() % (randmax - randmin + 1)) + randmin;
    if (x == 0) {
        media = (matrizAltitudes [x] [y - meioSize] + matrizAltitudes [x + meioSize] [y] + matrizAltitudes [x] [y + meioSize]) / 3;
        matrizAltitudes [x] [y] = media + r;
        return;
    }
    else if (y == 0) {
        media = (matrizAltitudes [x + meioSize] [y] + matrizAltitudes [x] [y + meioSize] + matrizAltitudes [x - meioSize] [y]) / 3;
        matrizAltitudes [x] [y] = media + r;
        return;
    }
    else if (x == lado - 1) {
        media = (matrizAltitudes [x] [y - meioSize] + matrizAltitudes [x] [y + meioSize] + matrizAltitudes [x - meioSize] [y]) / 3;
        matrizAltitudes [x] [y] = media + r;
        return;
    }
    else if (y == lado - 1) {
        media = (matrizAltitudes [x] [y - meioSize] + matrizAltitudes [x + meioSize] [y] + matrizAltitudes [x - meioSize] [y]) / 3;
        matrizAltitudes [x] [y] = media + r;
        return;
    }
    else {
        media = (matrizAltitudes [x] [y - meioSize] + matrizAltitudes [x + meioSize] [y] + matrizAltitudes [x] [y + meioSize] + matrizAltitudes [x - meioSize] [y]) / 4;
        matrizAltitudes [x] [y] = media + r;
        return;
    }
}

void Terreno::diamondSquare(double rugosidade) {
    srand(time(0));
    double randmax = 50.0;
    int min = 0;
    int max = 50;

    matrizAltitudes[0][0] = (rand() % (max - min + 1)) + min;
    matrizAltitudes[0][lado - 1] = (rand() % (max - min + 1)) + min;
    matrizAltitudes[lado - 1][0] = (rand() % (max - min + 1)) + min;
    matrizAltitudes[lado - 1][lado - 1] = (rand() % (max - min + 1)) + min;

    int size = lado - 1;

    while (size > 1) {
        // etapa diamond
        for (int i = 0; i < lado - 1; i += size) {
            for (int j = 0; j < lado - 1; j += size) {
                diamond(i, j, size, (int)randmax);
            }
        }

        // etapa square
        int count = 0;
        for (int i = 0; i < lado; i += size / 2) {
            if (count % 2 == 0) {
                for (int j = (size / 2); j < lado; j += size) {
                    square(j, i, size, (int)randmax);
                }
            } else {
                for (int j = 0; j < lado; j += size) {
                    square(j, i, size, (int)randmax);
                }
            }
            count++;
        }

        randmax *= rugosidade;
        // if (randmax < 0.5) randmax = 0.5;
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


// int main() {
//     Terreno malha (4);
//     malha.readAltitudes("mapa.txt");
//     malha.diamondSquare(0.5);
//     for (int i = 0; i < malha.getLinhas(); i++) {
//         for (int j = 0; j < malha.getColunas(); j++) {
//             std::cout << malha.matrizAltitudes [i] [j] << " ";
//         }
//         std::cout << std::endl;
//     }
// }