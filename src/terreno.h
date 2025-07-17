#ifndef TERRENO_H
#define TERRENO_H
#include <string>

struct Terreno {
    int lado;
    int **matrizAltitudes;
    int **altitudeDefault(int n);
    void diamond(int x, int y, int size, int randmax);
    void square(int x, int y, int size, int randmax);

    public:
    /**Construtor parametrizado para a classe Terreno.
     * @param n Expoente que será aplicado a 2 para gerar o tamanho do lado
     * @return Terreno com todos os valores em 0 (Default)
     */
    Terreno(int n);

    void diamondSquare(double rugosidade);
    int getAltitude(int linha, int coluna);
    int getLinhas();
    int getColunas();
    void writeAltitudes(std::string arquivo);
    void readAltitudes(std::string arquivo);
    
    ~Terreno();
};

#endif