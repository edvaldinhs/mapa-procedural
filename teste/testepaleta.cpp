#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doc/doctest.h"

#include "../src/paleta.h"

TEST_CASE("Consultar cor por altura retorna a cor esperada") {
    Cor listaCores[] = {
        {255, 0, 0},
        {0, 255, 0},
        {0, 0, 255}
    };
    int valores[] = {10, 20, 30};

    Paleta paleta(3, listaCores, valores);

    CHECK(paleta.getCor(0) == Cor{255, 0, 0});
    CHECK(paleta.getCor(1) == Cor{0, 255, 0});
    CHECK(paleta.getCor(2) == Cor{0, 0, 255});
}

TEST_CASE("Ler arquivo") {
    Paleta paleta("../paleta.ppm");

    CHECK(paleta.getCor(0) == Cor{255, 0, 0});
    CHECK(paleta.getCor(1) == Cor{0, 255, 0});
    CHECK(paleta.getCor(2) == Cor{0, 0, 255});
}

