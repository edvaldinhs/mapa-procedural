#include "../../src/terreno.cpp"

int main() {
    Terreno malha (3);
    malha.diamondSquare(0.5, 50);
    for (int i = 0; i < malha.getLinhas(); i++) {
        for (int j = 0; j < malha.getColunas(); j++) {
            std::cout << malha.getMatriz() [i] [j] << " ";
        }
        std::cout << std::endl;
    }
}