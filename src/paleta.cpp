#include "paleta.h"

Paleta::Paleta(std::string arquivo){
        lerArquivo(arquivo);
    }

Paleta::Paleta(int quantidade, Cor cores[], int valores[]) {
        this->quantidade = quantidade;

        for (int i = 0; i < quantidade && i < 100; ++i) {
            this->cores[i] = cores[i];
            this->valores[i] = valores[i];
        }
    }

Cor Paleta::getCor(int valores){
        return cores[valores];
    }

    void Paleta::lerArquivo(std::string arquivoTexto) {
        std::ifstream file(arquivoTexto);
        if (!file.is_open()) {
            std::cout << "Erro de abertura" << std::endl;
            return;
        }

        std::string linha;

        if (std::getline(file, linha)) {
            quantidade = std::stoi(linha);
        }

        int i = 0;
    while (std::getline(file, linha) && i < 100 && i < quantidade) {
        int valor = 0, r = 0, g = 0, b = 0;
        int pos = 0;
        int inicio = 0;
        int camposLidos = 0;

        for (int j = 0; j <= linha.size(); ++j) {
            if (j == linha.size() || linha[j] == ' ') {
                std::string parte = linha.substr(inicio, j - inicio);
                if (!parte.empty()) {
                    int numero = std::stoi(parte);
                    switch (camposLidos) {
                        case 0: valor = numero; break;
                        case 1: r = numero; break;
                        case 2: g = numero; break;
                        case 3: b = numero; break;
                    }
                    camposLidos++;
                }
                inicio = j + 1;
            }
        }

        if (camposLidos == 4) {
            valores[i] = valor;
            cores[i] = {r, g, b};
            i++;
        }
    }
    file.close();
}