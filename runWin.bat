@echo off
setlocal

:: Define o caminho para o executável
set EXE=src\a.exe

:: Compilar o projeto
:: Verifica se o programa já foi compilado, caso não, compila
if not exist "%EXE%" (
    echo [INFO] Compilando...
    g++ ./src/paleta.cpp ./src/imagem.cpp ./src/terreno.cpp main.cpp -o "%EXE%"
    echo [INFO] Iniciando...
)

echo =============================
echo  Gerador de Mapa Procedural
echo =============================
echo .

:: Executar
"%EXE%"

endlocal
pause