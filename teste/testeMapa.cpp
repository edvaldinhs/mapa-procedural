#include "../src/cor.h"
#include "../src/imagem.h"
#include "../src/paleta.h"
#include "../src/terreno.h"

// para compilar: g++ ../paleta/paleta.cpp ../paleta/imagem.cpp ../paleta/terreno.cpp testeMapa.cpp -o testeMapa.out

int main() {
    Paleta paleta("../paletas/Classica.txt");
    Terreno malha(9);
    malha.diamondSquare(0.6, 50);
    malha.writeAltitudes("mapaPreenchido.txt");
    Imagem mapa(malha.getLinhas(), malha.getLinhas());
    for (int i = 0; i < malha.getColunas(); i++) {
        for (int j = 0; j < malha.getColunas(); j++) {
            mapa.setPixel(i, j, paleta.getCor(malha.getMatriz() [i] [j]));
        }
    }

		mapa.sombrear(malha, 0.6);
    mapa.criarImagem(paleta, "mapa.ppm");
    return 0;
}