#include <string>
#include <fstream>
#include <vector>

//Oi Luis
//Fiz metade do que se pedia na paleta
//Devido minha péssima memória,
//me lembre de discutir como fazer a função lerArquivo()



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
    void lerArquivo(std::string arquivoTexto){
        std::ifstream file(arquivoTexto);
        if (file.is_open()) {
            std::string textoFinal;
            while (getline(file, arquivoTexto)) {
                textoFinal += arquivoTexto + '\n';
            }
            std::cout << textoFinal;
            bool nGet = false;
            std::string qtd = "";
            int x = 0;
            std::vector<int> v;
            std::vector<int> w;
            std::string vInt = "", wInt = "";
            for (int i = 0; i < textoFinal.size(); i++) {
                if (!nGet && textoFinal [i] != '\n') {
                    qtd += textoFinal[i];
                }
                else {
                    nGet = true;
                    i++;
                }
                if (nGet) {
                    if (x == 0 && textoFinal [i] != ' ') {
                        vInt += textoFinal [i];
                    }
                    else {
                        vInt = "";
                        x++;
                    }
                    if (x > 0 && x <= 3 && textoFinal [i] != ' ' && textoFinal [i] != '\n') {
                        wInt += textoFinal [i];
                    }
                    else {
                        wInt = "";
                        x++;
                    }
                    if (x > 3) {
                        x = 0;
                    }
                }
            }
            // v.push_back(stoi(vInt));
            quantidade = stoi(qtd);
            std::cout << vInt << std::endl;
            std::cout << wInt << std::endl;
        }
        else {
            std::cout << "Erro de abertura" << std::endl;
        }
        file.close();
    }
};
