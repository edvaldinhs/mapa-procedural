#include "../../src/terreno.cpp"

int main() {
    Terreno malha (3);
    malha.readAltitudes("mapa.txt");
    malha.diamondSquare(0.5);
    for (int i = 0; i < malha.getLinhas(); i++) {
        for (int j = 0; j < malha.getColunas(); j++) {
            std::cout << malha.matrizAltitudes [i] [j] << " ";
        }
        std::cout << std::endl;
    }
}