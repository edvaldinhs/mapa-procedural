#ifndef IMAGEM_H
#define IMAGEM_H
#include "paleta.h"
#include "terreno.h"
#include <vector>

class Imagem {
    int comprimento;
    int altura;
    Cor **pixels;

    public:
    /** Construtor parametrizado da classe Imagem
     * @param comp Comprimento da imagem
     * @param alt Altura da imagem
     */
    Imagem(int comp, int alt);

    /** Acessa o comprimento de uma imagem
     * @return Comprimento da imagem
     */
    int getComp();

    /** Acessa a altura de uma imagem
     * @return Altura da imagem
     */
    int getAlt();

    /** Cria a matriz de pixels da imagem
     * @return Matriz de pixels
     */
    Cor **criaPixel();

    /** Acessa um pixel específico da imagem
     * @param comp Coordenada X do pixel na imagem
     * @param alt Coordenada Y do pixel na imagem
     */
    Cor getPixel(int comp, int alt);

    /** Escurece cada pixel da imagem
     * @param fator Fator de escurecimento (quanto menor, mais escuro)
     */
    void escurecer(double fator);

    /** Dá a cor para cada pixel da imagem */
    void setPixel(int comp, int alt, Cor doPixel);

    /** Escurece a imagem com base na altitude de cada
     * célula do Terreno e no sentido Noroeste -> Sudeste
     * @param terreno Terreno de onde vêm as altitudes
     * @param fator Fator de escurecimento (quanto menor, mais escuro)
    */
	void sombrear(Terreno& terreno, double fator);

    /** Cria uma imagem com as cores de um arqivo de paleta 
     * e grava em um arquivo ppm
     * @param imgPaleta Paleta de cores
     * @param arquivo Nome do arquivo a ser criado
    */
    void criarImagem(Paleta imgPaleta, std::string arquivo);

    /** Destrutor da classe Imagem */
    ~Imagem();
};

#endif