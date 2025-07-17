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
     */
    Terreno(int n);

    /** Gera proceduralmente as altitudes de um terreno
     * @param rugosidade Constante que altera o valor máximo da variação aleatória
     * @param maxRange valor máximo das altitudes geradas
     */
    void diamondSquare(double rugosidade, int maxRange);

    /** Acessa o valor da altitude em uma determinada coordenada do terreno
     * @param linha Linha da coordenada
     * @param coluna Coluna da coordenada
     * @return Valor da altitude na coordenada (linha, coluna) do terreno.
     */
    int getAltitude(int linha, int coluna);

    /** Acessa o número de linhas do terreno
     * @return Valor do lado do terreno
     */
    int getLinhas();
    
    /** Acessa o número de colunas do terreno
     * @return Valor do lado do terreno
     */
    int getColunas();

    /** Acessa a matriz de altitudes do terreno
     * @return Matriz de altitudes do terreno
     */
    int** getMatriz();

    /** Escreve as dimensões de um terreno e a sua 
     * matriz de altitudes em um arquivo 
     * @param arquivo Nome do arquivo a ser gravado 
     * */
    void writeAltitudes(std::string arquivo);

    /** Lê as dimensões e a matriz de altitudes de um terreno
     *  de um arquivo e aplica em um objeto da classe Terreno
     * @param Nome do arquivo a ser lido
     * */
    void readAltitudes(std::string arquivo);
    
    /** Destrutor para a classe Terreno */
    ~Terreno();
};

#endif