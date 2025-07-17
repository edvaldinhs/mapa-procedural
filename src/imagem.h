#ifndef IMAGEM_H
#define IMAGEM_H
#include "paleta.h"
#include <vector>

class Imagem {
    int comprimento;
    int altura;
    Cor **pixels;

    public:
    Imagem(int comp, int alt);
    void escurecer(double fator);
    int getComp();
    int getAlt();
    Cor **criaPixel();
    Cor getPixel(int comp, int alt);
    void setPixel(int comp, int alt, Cor doPixel);
    void criarImagem(Paleta imgPaleta, std::string arquivo);
    ~Imagem();
};

#endif