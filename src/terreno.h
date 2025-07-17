#ifndef TERRENO_H
#define TERRENO_H
#include <string>

class Terreno {
    int lado;
    int **matrizAltitudes;
    /** Aplica o valor padrão 0 a todas as células de um terreno
     * @return matriz de altitudes zerada
     */
     int **altitudeDefault();
    
     /** Etapa "Diamond" do algoritmo diamond-square
     * @param x Coordenada X do canto superior esquerdo do quadrado
     * @param y Coordenada Y do canto superior esquerdo do quadrado
     * @param size Comprimento dos lados do diamante - 1
     * @param randmax Valor máximo da variação aletória
     */
    void diamond(int x, int y, int size, int randmax);
    
    /** Etapa "Square" do algoritmo diamond-square
     * @param x Coordenada X do centro de um diamante
     * @param y Coordenada Y do centro de um diamante
     * @param size Comprimento dos lados do quadrado - 1
     * @param randmax Valor máximo da variação aletória
     */
    void square(int x, int y, int size, int randmax);

    public:
    /**Construtor parametrizado para a classe Terreno.
     * @param n Expoente que será aplicado a 2 para gerar o tamanho do lado
     * @return Terreno com todos os valores em 0 (Default)
     */
    Terreno(int n);

    /** Gera proceduralmente as altitudes de um terreno
     * @param rugosidade Constante que altera o valor máximo da variação aleatória
     */
    void diamondSquare(int n, double rugosidade);
    int getAltitude(int linha, int coluna);
    int getLinhas();
    int getColunas();
    void writeAltitudes(std::string arquivo);
    void readAltitudes(std::string arquivo);
    
    ~Terreno();
};

#endif