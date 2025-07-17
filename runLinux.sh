#!/bin/bash
EXEC="./src/a.out"

# Verifica se o executável existe
if [ ! -f "$EXEC" ]; then
    # Compila...
    echo "[INFO] Executável não encontrado. Compilando..."
    g++ ./src/paleta.cpp ./src/imagem.cpp ./src/terreno.cpp main.cpp -o "$EXEC"
    if [ $? -ne 0 ]; then
        echo "[ERRO] Falha na compilação."
        exit 1
    else
        echo "[INFO] Executando o programa..."
    fi 
fi

echo "============================="
echo "Gerador de Mapa Procedural"
echo "============================="
echo

#Executa o programa
"$EXEC"
