#include "paleta.h"

class Imagem {
    int comprimento;
    int altura;
    Cor pixels;
    public:
    Imagem(int comp, int alt) {
        comprimento = comp;
        altura = alt;
    }
    void criarImagem(Paleta imgPaleta, Imagem img);
};