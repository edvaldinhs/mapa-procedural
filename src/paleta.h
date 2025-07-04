#ifndef PALETA_H
#define PALETA_H
#include <string>
#include <fstream>

struct Cor {
    int r, g, b;

    //definindo a comparação para o tipo cor
    bool operator==(const Cor& outra) const {
        //compara cada valor r, g e b de uma cor com outra
        //Cor a; Cor b; a == b
        return r == outra.r && g == outra.g && b == outra.b;
    }
};

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
    Cor getCor(int valores){
        return cores[valores];
    }
    void lerArquivo(std::string arquivoTexto) {
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
};
#endif