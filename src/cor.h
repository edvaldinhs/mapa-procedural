#ifndef COR_H
#define COR_H

struct Cor {
    int r, g, b;

    //definindo a comparação para o tipo cor
    bool operator==(const Cor& outra) const {
        //compara cada valor r, g e b de uma cor com outra
        //Cor a; Cor b; a == b
        return r == outra.r && g == outra.g && b == outra.b;
    }
};

#endif