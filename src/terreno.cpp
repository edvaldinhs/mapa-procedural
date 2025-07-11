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

// int **Terreno::diamondSquare(int n, double rugosidade) {

// }

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
    // favor não inserir n maior que 9
    std::string size;
    getline(file, size);
    size = size [0];
    lado = stoi(size);
    delete[] matrizAltitudes;
    matrizAltitudes = new int *[lado];
    for (int i = 0; i < lado; i++) {
        matrizAltitudes [i] = new int [lado];
    }
    
    int i = 0;
    std::string linha;
    while (std::getline(file, linha) && i < lado) {
        for (int j = 0; j < linha.size(); j++) {
            std::string valor;
            int k = 0;
            if (linha [j] != ' ') {
                valor = linha [j];
                
                matrizAltitudes [i] [k] = stoi(valor);
                std::cout << matrizAltitudes [i] [k] << "s" << "\n";
                k++;
            }
        }
        i++;
    }
    file.close();
    return;
}

int main() {
    Terreno malha (2);
    malha.readAltitudes("mapa.txt");
    for (int i = 0; i < malha.getLinhas(); i++) {
        for (int j = 0; j < malha.getColunas(); j++) {
            std::cout << malha.matrizAltitudes [i] [j] << " ";
        }
        std::cout << std::endl;
    }
}