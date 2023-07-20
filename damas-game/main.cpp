#include <iostream>
#include <string>
#include <fstream>

#define VAZIO 0
#define BRANCA 1
#define PRETA 2

using namespace std;

void escreverArquivo(string diretorio, string conteudo);
string lerArquivo(string diretorio);

void inicializarTabuleiro();
void printaTabuleiro();

const string diretorio = "save/dados.txt"; //a cada pasta coloca-se uma nova barra e no final deve ser o nome do arquivo e a extensão.
const int TAM_TABULEIRO = 8;

int tabuleiro [TAM_TABULEIRO][TAM_TABULEIRO] = {VAZIO};

int main()
{
    inicializarTabuleiro();
    printaTabuleiro();
    return 0;
}

void printaTabuleiro()
{
    for(int linha=0; linha<TAM_TABULEIRO; linha++)
    {
        for(int coluna=0; coluna<TAM_TABULEIRO; coluna++)
            cout<<tabuleiro[linha][coluna];
        cout<<endl;
    }
}

void inicializarTabuleiro()
{
    //lado das peças brancas
    for(int linha=0; linha<3; linha++)
        for(int coluna=0; coluna<TAM_TABULEIRO; coluna++)
            if((linha + coluna)% 2 == 0)
                tabuleiro[linha][coluna] = BRANCA;

    //lado das peças pretas
    for(int linha=5; linha<8; linha++)
        for(int coluna=0; coluna<TAM_TABULEIRO; coluna++)
            if((linha + coluna)% 2 == 1)
                tabuleiro[linha][coluna] = PRETA;

}

void escreverArquivo(string diretorio, string conteudo)
{
    fstream arquivo(diretorio, ios::out); //fstream funciona como tipo de arquivo
    arquivo<<conteudo;
    arquivo.close(); //
}

string lerArquivo(string diretorio)
{
    fstream arquivo(diretorio, ios::in);
    string linha;
    string conteudo;

    while(getline(arquivo, linha)) //getline pega a primeira linha do arquivo e joga na variável linha, se tiver informação em linha getline retorna 1, senão tiver retorna 0.
    {
        conteudo += linha + "\n";
    }
    arquivo.close();
    return conteudo;

}
