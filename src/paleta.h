#ifndef PALETA_H
#define PALETA_H
#include <string>
#include <fstream>
#include <iostream>
#include "cor.h"

class Paleta {
    int quantidade;
    Cor cores [100];
    int valores [100];
    public:
    /** Construtor para a classe Paleta que lê de um arquivo
     * @param arquivo Nome do arquivo da paleta a ser lido
     */
    Paleta(std::string arquivo);

    /** Construtor parametrizado para a classe Paleta
     * @param quantidade Número de cores da paleta
     * @param cores Array de cores (valores é seu índice)
     * @param valores Índice de cada cor
     */
    Paleta(int quantidade, Cor cores[], int valores[]);

    /** Acessa uma cor específica através do seu índice na paleta
     * @param valores índice do elemento a ser acessado
     * @return Cor que estava no índice (valores)
     */
    Cor getCorIndice(int valores);

    /** Acessa uma cor específica pela altura de uma célula de Terreno
     * @param valores índice da cor na paleta
     */
    Cor getCor(int valores);

    /** Lê a paleta a partir de um arquivo de texto
     * @param arquivoTexto Nome do arquivo a ser lido
     */
    void lerArquivo(std::string arquivoTexto);
};
#endif