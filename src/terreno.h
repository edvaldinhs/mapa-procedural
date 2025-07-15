#ifndef TERRENO_H
#define TERRENO_H
#include <string>
struct Terreno {
    int lado;
    int **matrizAltitudes;
    int **altitudeDefault(int n);
    void diamond(int lado);
    int **square(int n, double rugosidade);

    public:
    Terreno(int n) {
        int ladoTemp = 2;
        for (int i = 1; i < n; i++) {
            ladoTemp *= 2;
        }
        lado = ladoTemp + 1;
        matrizAltitudes = altitudeDefault(n);
    }

    void diamondSquare(int n, double rugosidade);
    int getAltitude(int linha, int coluna);
    int getLinhas();
    int getColunas();
    void writeAltitudes(std::string arquivo);
    void readAltitudes(std::string arquivo);
};

#endif