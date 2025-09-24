#include <iostream>
#include "src/cor.h"
#include "src/imagem.h"
#include "src/paleta.h"
#include "src/terreno.h"
#include <string>

// Linux:
// para compilar: g++ ./src/paleta.cpp ./src/imagem.cpp ./src/terreno.cpp main.cpp -o a.out

// Windows:
// para compilar: g++ ./src/paleta.cpp ./src/imagem.cpp ./src/terreno.cpp main.cpp -o a.exe

/** Menu de seleção de paleta
     * @param range Nome do arquivo da paleta a ser lido
     * @return nome da paleta
     */
std::string selecionarPaleta(int &range) {
    int opcao;
    std::string paletaEscolhida;

    std::cout << "=== Menu de Paletas ===\n";
    std::cout << "1. Classica\n";
    std::cout << "2. TC-Magical-Forest\n";
    std::cout << "3. Realista\n";
    std::cout << "4. Cinza\n";
    std::cout << "Escolha uma opção (1-4): ";
    std::cin >> opcao;

    switch (opcao) {
        case 1:
            paletaEscolhida = "Classica";
                range = 50;
            break;
        case 2:
            paletaEscolhida = "TC-Magical-Forest";
            range = 70;
            break;
        case 3:
            paletaEscolhida = "Realista";
            range = 36;
            break;
        case 4:
            paletaEscolhida = "Cinza";
            range = 100;
            break;
        default:
            std::cout << "Opção inválida. Usando paleta padrão: classica.\n";
            paletaEscolhida = "Classica";
    }

    std::cout << "Você escolheu a paleta: " << paletaEscolhida << "\n";
    return paletaEscolhida;
}

int main() {
    char continuar;
    unsigned short ordem;

    do {
        int range = 0;

        Paleta paleta("./paletas/" + selecionarPaleta(range) + ".txt");
        std::cout << "|| A imagem será quadrada com lados de tamanho 2ⁿ+1.";
        std::cout << "\n|| Digite o valor para n: ";
        std::cin >> ordem;
        Terreno malha(ordem);
        malha.diamondSquare(0.6, range);
        malha.writeAltitudes("mapaPreenchido.txt");
        Imagem mapa(malha.getLinhas(), malha.getLinhas());
        
        for (int i = 0; i < malha.getColunas(); i++) {
            for (int j = 0; j < malha.getColunas(); j++) {
                mapa.setPixel(i, j, paleta.getCor(malha.getMatriz()[i][j]));
            }
        }

        mapa.sombrear(malha, 0.6);
        mapa.criarImagem(paleta, "mapa.ppm");

        std::cout << "\n--   Mapa Criado!   --\n";
        std::cout << "-- Verifique o ppm! --\n";

        std::cout << "Deseja criar outro mapa? (s/n): ";
        std::cin >> continuar;
        std::cout << "\n";

        
    //Limpa o terminal depois de selecionar para criar outro mapa
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    } while (continuar == 's' || continuar == 'S');

    return 0;
}
