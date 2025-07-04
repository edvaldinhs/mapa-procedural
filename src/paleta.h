#ifndef PALETA_H
#define PALETA_H
#include <string>
#include <fstream>
#include <iostream>
#include "cor.h"

class Paleta {
    int quantidade;
    Cor cores [100];
    int valores [100];
    public:
    Paleta(std::string arquivo){
        lerArquivo(arquivo);
    }
    Paleta(int quantidade, Cor cores[], int valores[]) {
        this->quantidade = quantidade;

        for (int i = 0; i < quantidade && i < 100; ++i) {
            this->cores[i] = cores[i];
            this->valores[i] = valores[i];
        }
    }
    Cor getCor(int valores);
    void lerArquivo(std::string arquivoTexto);
};
#endif