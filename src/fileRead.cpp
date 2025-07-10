#include "paleta.h"
#include <iostream>
#include <fstream>
#include <string>

void lerArquivo(const std::string nomeArquivo) {
    std::ifstream file(nomeArquivo);
        if (!file.is_open()) {
            std::cout << "Erro de abertura" << std::endl;
            return;
        }
    std::string resultado = "";
    for (int i = 0; i < nomeArquivo.size(); i++) {
        getline(file, resultado);
    }

}