#include "../src/cor.h"
#include "../src/imagem.h"
#include "../src/paleta.h"
#include "../src/terreno.h"

// para compilar: g++ ../src/paleta.cpp ../src/imagem.cpp ../src/terreno.cpp testeMapa.cpp -o testeMapa.out

int main() {
    Paleta paleta("../src/paleta.txt");
    Terreno malha(2);
    malha.diamondSquare(0.5);
    malha.writeAltitudes("mapaPreenchido.txt");
    Imagem mapa(malha.lado, malha.lado);
    for (int i = 0; i < malha.lado; i++) {
        for (int j = 0; j < malha.lado; j++) {
            mapa.setPixel(i, j, paleta.getCor(malha.matrizAltitudes [i] [j]));
        }
    }
    mapa.criarImagem(paleta, "mapa.ppm");
    return 0;
}