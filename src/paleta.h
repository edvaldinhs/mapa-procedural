#include <string>


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
    Cor getCor(int altura){
        return cores[altura];
    }
    void lerArquivo(std::string arquivo){
        
    }
    
};