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
    Paleta(std::string arquivo);
    Paleta(int quantidade, Cor cores[], int valores[]);
    Cor getCor(int valores);
    void lerArquivo(std::string arquivoTexto);
};
#endif