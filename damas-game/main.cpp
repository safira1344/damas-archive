#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

#define VAZIO 0
#define BRANCA 1
#define PRETA 2

using namespace std;

struct Jogador
{
    string nome;
    int vitorias;
    int quantidadePartidas;
};

void escreverArquivo(string diretorio, string conteudo);
string lerArquivo(string diretorio);
void escreverArquivoBinario(string diretorio, string conteudo);
string lerArquivoBinario(string diretorio);

void inicializarTabuleiro();
void printaTabuleiro();
bool movimentoValido();
void movimentar();
bool verificaVitoria();
void iniciarJogo();
void tutorial();
void salvarPlacar();
void printarPlacar();

const string diretorio = "save/dados.txt"; // a cada pasta coloca-se uma nova barra e no final deve ser o nome do arquivo e a extensço.
const int TAM_TABULEIRO = 8;

int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {VAZIO};
int jogadorAtual;

int main()
{
    tutorial();

    jogadorAtual = BRANCA; // Primeiro jogador sempre é o branco
    inicializarTabuleiro();
    iniciarJogo();
    int ugabuga;
    cin>> ugabuga;
    return 0;
}

void salvarPlacar()
{ 
    // Verificar se ja existe um jogador com o mesmo nome no arquivo de placar, se existir atualizar a pontuação dele, se não, criar ele
}

void printarPlacar()
{ 
    // Ler todas as structs do arquivo e printar ordenadamente por quantidade de vitórias
}

bool verificaVitoria()
{
    return true;
}

void tutorial()
{
    cout << "Regras..." << endl;
}

void iniciarJogo()
{
    bool temVencedor = false;
    printaTabuleiro();
    do
    {
        movimentar();
        printaTabuleiro();
        temVencedor = verificaVitoria();
    } while (temVencedor == false);
}

void movimentar()
{
    // verificar quem é o jogador atual
    // Do
    // receber o input do jogador (cin>>) digite a letra referente a linha e depois o numero referente a coluna
    // traduzir as letras das linhas para índice. Ex: A = 0, B=1, C=2... H=7
    // While
    // verificar se o input do jogador é um movimento valido -> bool isValid = movimentoValido()
    // se verdade = movimentar ou comer
    // se não = pedir o input novamente

    //
}

void printaTabuleiro()
{
    system("CLS"); // Limpa tela
    // Printa primeira Linha e asciis
    cout << "   0  1  2  3  4  5  6  7" << endl;
    cout << " " << (char)(201);
    for (int i = 0; i < 23; i++)
    {

        if ((i + 1) % 3 == 0)
        {
            cout << (char)(203);
        }
        else
        {
            cout << (char)(205);
        }
    }
    int linhaIndex = 0;
    int letras = 65;
    cout << (char)(187) << endl;

    // Printar todo conteúdo interno que se repete
    for (int linha = 0; linha < 7; linha++)
    {
        cout << (char)(letras + linha) << (char)(186);
        // Printar as peças
        for (int coluna = 0; coluna < 8; coluna++)
        {
            if (tabuleiro[linha][coluna] == BRANCA)
            {
                cout << " " << (char)(219) << (char)(186);
            }
            else if (tabuleiro[linha][coluna] == PRETA)
            {
                cout << " " << (char)(177) << (char)(186);
            }
            else
            {
                cout << "  " << (char)(186);
            }
        }
        cout << (char)(letras + linha);

        cout << endl;
        // Printar as linhas ascii
        cout << " " << (char)(204);
        for (int i = 0; i < 23; i++)
        {

            if ((i + 1) % 3 == 0)
            {
                cout << (char)(206);
            }
            else
            {
                cout << (char)(205);
            }
        }
        cout << (char)(185) << endl;
    }

    cout << (char)(letras + 8) << (char)(186);

    for (int coluna = 0; coluna < 8; coluna++)
    {
        // Printa as peças que estão na ultima linha do tabuleiro
        if (tabuleiro[7][coluna] == BRANCA)
        {
            cout << " " << (char)(219) << (char)(186);
        }
        else if (tabuleiro[7][coluna] == PRETA)
        {
            cout << " " << (char)(177) << (char)(186);
        }
        else
        {
            cout << "  " << (char)(186);
        }
    }
    // Printa as ultima linha
    cout << (char)(letras + 8);
    cout << endl;
    cout << " " << (char)(200);
    for (int i = 0; i < 23; i++)
    {

        if ((i + 1) % 3 == 0)
        {
            cout << (char)(202);
        }
        else
        {
            cout << (char)(205);
        }
    }
    cout << (char)(188) << endl;

    cout << "   0  1  2  3  4  5  6  7" << endl;
}

// o tabuleiro começa com as peças brancas em cima e as peças pretas em baixo
void inicializarTabuleiro()
{
    // Colocar vazio em todas posições do tabuleiro ao iniciar
    for (int linha = 0; linha < 8; linha++)
    {
        for (int coluna = 0; coluna < 8; coluna++)
        {
            tabuleiro[linha][coluna] = VAZIO;
        }
        
    }
    
    // lado das peças brancas
    for (int linha = 0; linha < 3; linha++)
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++)
            if ((linha + coluna) % 2 == 0)
                tabuleiro[linha][coluna] = BRANCA;

    // lado das peças pretas
    for (int linha = 5; linha < 8; linha++)
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++)
            if ((linha + coluna) % 2 == 1)
                tabuleiro[linha][coluna] = PRETA;
}

bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaChegada, int colunaChegada)
{

    // valida se as posiççes de chegada estço corretas
    if (linhaChegada < 0 || linhaChegada >= TAM_TABULEIRO || colunaChegada < 0 || colunaChegada >= TAM_TABULEIRO)
    {
        return false;
    }

    // movimento do jogo sç ç valido na diagonal e possuem uma casinha de diferença(distancia)
    int diferencaLinha = linhaChegada - linhaOrigem;
    int diferencaColuna = colunaChegada - colunaOrigem;
    if (diferencaColuna > 1 || diferencaColuna < -1)
    {
        return false;
    }

    if (diferencaColuna == 0)
    {
        return false;
    }

    // nao permite as peças pretas descerem
    if (diferencaLinha == 1 && jogadorAtual == PRETA)
    {
        return false;
    }

    // nao permite as pecas brancas subirem
    if (diferencaLinha == -1 && jogadorAtual == BRANCA)
    {
        return false;
    }

    // verifica se o destino for diferente de vazio
    if (tabuleiro[linhaChegada][colunaChegada] != VAZIO)
    {
        // fazer verificaçço se a próxima casinha está vazia também
        return false;
    }

    return true;
}

void escreverArquivo(string diretorio, string conteudo)
{
    fstream arquivo(diretorio, ios::out); // fstream funciona como tipo de arquivo
    arquivo << conteudo;
    arquivo.close(); //
}

string lerArquivo(string diretorio)
{
    fstream arquivo(diretorio, ios::in);
    string linha;
    string conteudo;

    while (getline(arquivo, linha)) // getline pega a primeira linha do arquivo e joga na variçvel linha, se tiver informaçço em linha getline retorna 1, senço tiver retorna 0.
    {
        conteudo += linha + "\n";
    }
    arquivo.close();
    return conteudo;
}
