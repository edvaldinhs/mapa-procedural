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