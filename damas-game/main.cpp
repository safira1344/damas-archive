#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

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
bool movimentoValido(int linhaOrigem, int linhaChegada, int colunaOrigem, int colunaChegada, bool isMovimentando);
bool movimentoValido(int linhaOrigem, int linhaChegada, int colunaOrigem, int colunaChegada);
void movimentar();
bool verificaVitoria();
void iniciarJogo();
void jogando();
void tutorial();
void salvarPlacar();
void printarPlacar();
void menu();
void mostrarGanhador();
bool comerPeca(int linhaCaptura, int colunaCaptura);

const string diretorio = "save/dados.txt"; // a cada pasta coloca-se uma nova barra e no final deve ser o nome do arquivo e a extens�o.
const int TAM_TABULEIRO = 8;

int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {VAZIO};
int jogadorAtual;

int main()
{
    // Ler o nome dos jogadores
    // Buscar no arquivo de placar se j� existe um jogador com o mesmo nome
    // Se existir, carregar os dados dele
    // Se n�o existir, criar um novo jogador

    menu();

    int travaFechamentoDaJanelaDoTerminal; // Vari�vel para impedir que o programa feche ap�s a execu��o
    cin >> travaFechamentoDaJanelaDoTerminal;
    return 0;
}

void menu()
{
    cout << "Bem vindo ao jogo de Damas!" << endl;
    cout << "0 - Tutorial" << endl;
    cout << "1 - Jogar" << endl;
    cout << "2 - Placar" << endl;
    cout << "3 - Sair" << endl;
    cout << "Digite a op��o desejada: ";
    int opcao;
    cin >> opcao;
    switch (opcao)
    {
    case 0:
        tutorial();
        break;
    case 1:
        iniciarJogo();
        break;
    case 2:
        printarPlacar();
        break;
    case 3:
        exit(0);
        break;
    }
}

void salvarPlacar()
{
    // Verificar se ja existe um jogador com o mesmo nome no arquivo de placar, se existir atualizar a pontua��o dele, se n�o, criar ele
}

void printarPlacar()
{
    // Ler todas as structs do arquivo e printar ordenadamente por quantidade de vit�rias
}

bool verificaVitoria()
{
    // Verificar se o jogador atual tem pe�as no tabuleiro
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            // Se tiver, verificar se o jogador atual tem movimentos poss�veis
            if (tabuleiro[i][j] == jogadorAtual)
            {
                if (movimentoValido(i, j, i + 1, j + 1) ||
                    movimentoValido(i, j, i + 1, j - 1) ||
                    movimentoValido(i, j, i - 1, j + 1) ||
                    movimentoValido(i, j, i - 1, j - 1) ||
                    movimentoValido(i, j, i + 2, j + 2) ||
                    movimentoValido(i, j, i + 2, j - 2) ||
                    movimentoValido(i, j, i - 2, j + 2) ||
                    movimentoValido(i, j, i - 2, j - 2))
                {
                    return false;
                }
            }
        }
    }

    // Se n�o tiver, o outro jogador venceu
    return true;
}

void tutorial()
{
    cout << setw(50);
    cout << "Regras" << endl;
    cout << endl;
    cout << setw(55);
    cout << "Tabuleiro e Pe�as" << endl;
    cout << endl;
    cout << setw(60);
    cout << "1- O jogo � jogado em um tabuleiro 8x8, com casas alternando entre pretas e brancas. " << endl;
    cout << setw(60);
    cout << "2- Cada jogador tem 12 pe�as, representadas por pe�as brancas e pe�as pretas." << endl;
    cout << setw(60);
    cout << "3- Movem-se diagonalmente para frente, promovem-se a dama na �ltima linha. Capturas obrigat�rias." << endl;
    cout << setw(60);
    cout << "4- Objetivo: capturar todas as pe�as do advers�rio ou bloque�-las." << endl;
    cout << setw(60);
    cout << "5- Nota��o: letras A-H para linhas, n�meros 0-7 para colunas. Divirta-se!" << endl;
}

void jogando()
{
    bool temVencedor = false;
    do
    {
        printaTabuleiro();
        movimentar();
        temVencedor = verificaVitoria();
    } while (temVencedor == false);

    mostrarGanhador();
    menu();
}

void mostrarGanhador()
{
    cout << "Jogador " << ((jogadorAtual == BRANCA) ? "Branco" : "Preto") << " ficou sem movimentos!" << endl;
    cout << "Jogador " << ((jogadorAtual == BRANCA) ? "Preto" : "Branco") << " venceu!" << endl;
}

void iniciarJogo()
{
    jogadorAtual = BRANCA; // Primeiro jogador sempre � o branco
    inicializarTabuleiro();
    jogando();
}

void movimentar()
{
    int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
    char letraOrigem, letraDestino;
    cout << "Jogador " << ((jogadorAtual == BRANCA) ? "Branco" : "Preto") << ", digite a letra e numero da pe�a que deseja mover: ";
    cin >> letraOrigem >> colunaOrigem;
    cout << "Jogador " << ((jogadorAtual == BRANCA) ? "Branco" : "Preto") << ", digite a letra e numero do destino: ";
    cin >> letraDestino >> colunaDestino;

    linhaOrigem = ((int)toupper(letraOrigem)) - 65;
    linhaDestino = ((int)toupper(letraDestino)) - 65;

    if (movimentoValido(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, true))
    {
        tabuleiro[linhaDestino][colunaDestino] = jogadorAtual;
        tabuleiro[linhaOrigem][colunaOrigem] = VAZIO;

        // trocar o jogador atual
        jogadorAtual = (jogadorAtual == BRANCA) ? PRETA : BRANCA;
    }
    else
    {
        cout << "Movimento inv�lido. Tente novamente." << endl;
        movimentar();
    }
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

    // Printar todo conte�do interno que se repete
    for (int linha = 0; linha < 7; linha++)
    {
        cout << (char)(letras + linha) << (char)(186);
        // Printar as pe�as
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

    cout << (char)(letras + 7) << (char)(186);

    for (int coluna = 0; coluna < 8; coluna++)
    {
        // Printa as pe�as que est�o na ultima linha do tabuleiro
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
    cout << (char)(letras + 7);
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

// o tabuleiro come�a com as pe�as brancas em cima e as pe�as pretas em baixo
void inicializarTabuleiro()
{
    // Colocar vazio em todas posi��es do tabuleiro ao iniciar
    for (int linha = 0; linha < 8; linha++)
    {
        for (int coluna = 0; coluna < 8; coluna++)
        {
            tabuleiro[linha][coluna] = VAZIO;
        }
    }

    // lado das pe�as brancas
    for (int linha = 0; linha < 3; linha++)
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++)
            if ((linha + coluna) % 2 == 0)
                tabuleiro[linha][coluna] = BRANCA;

    // lado das pe�as pretas
    for (int linha = 5; linha < 8; linha++)
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++)
            if ((linha + coluna) % 2 == 0)
                tabuleiro[linha][coluna] = PRETA;
}

bool comerPeca(int linhaCaptura, int colunaCaptura)
{
    tabuleiro[linhaCaptura][colunaCaptura] = VAZIO;
}

bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool isMovimentando)
{
    // Valida se as posi��es destino est�o dentro do tabuleiro
    if (linhaDestino < 0 || linhaDestino >= TAM_TABULEIRO || colunaDestino < 0 || colunaDestino >= TAM_TABULEIRO)
    {
        cout << "Posi��o de destino invade o tamanho do tabuleiro" << endl;
        return false;
    }

    int diferencaLinha = linhaDestino - linhaOrigem;
    int diferencaColuna = colunaDestino - colunaOrigem;

    // Verifica se a pe�a � do jogador atual
    if (tabuleiro[linhaOrigem][colunaOrigem] != jogadorAtual)
    {
        cout << "A pe�a n�o � sua" << endl;
        return false;
    }

    // Verifica se � um movimento de captura (comer pe�a)
    if (abs(diferencaColuna) == 2 && abs(diferencaLinha) == 2)
    {
        int linhaCaptura = (linhaOrigem + linhaDestino) / 2;
        int colunaCaptura = (colunaOrigem + colunaDestino) / 2;

        // Verifica se a posi��o de destino est� vazia
        if (tabuleiro[linhaDestino][colunaDestino] != VAZIO)
        {
            cout << "Posi��o de destino est� ocupada" << endl;
            return false;
        }

        int captura = tabuleiro[linhaCaptura][colunaCaptura];
        // Verifica se h� uma pe�a do oponente entre a origem e o destino
        if (jogadorAtual == captura || captura == VAZIO)
        {
            cout << "N�o h� pe�a do oponente entre a origem e o destino" << endl;
            return false;
        }

        // Realiza a captura (comer pe�a)
        if (isMovimentando == true)
        {
            comerPeca(linhaCaptura, colunaCaptura);
        }
        // to do: atualizar o placar
        return true;
    }

    // Movimento no jogo � v�lido na diagonal e com uma casinha de diferen�a (dist�ncia)
    if (abs(diferencaColuna) != 1 || abs(diferencaLinha) != 1)
    {
        cout << "Movimento inserido nao e na diagonal" << endl;
        return false;
    }

    // N�o permite que as pe�as pretas des�am
    if (diferencaLinha == 1 && tabuleiro[linhaOrigem][colunaOrigem] == PRETA)
    {
        cout << "Pe�a preta n�o pode descer" << endl;
        return false;
    }

    // N�o permite que as pe�as brancas subam
    if (diferencaLinha == -1 && tabuleiro[linhaOrigem][colunaOrigem] == BRANCA)
    {
        cout << "Pe�a branca n�o pode subir" << endl;
        return false;
    }

    return true;
}

bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino)
{
    // Valida se as posi��es destino est�o dentro do tabuleiro
    if (linhaDestino < 0 || linhaDestino >= TAM_TABULEIRO || colunaDestino < 0 || colunaDestino >= TAM_TABULEIRO)
        return false;

    int diferencaLinha = linhaDestino - linhaOrigem;
    int diferencaColuna = colunaDestino - colunaOrigem;

    // Verifica se a pe�a � do jogador atual
    if (tabuleiro[linhaOrigem][colunaOrigem] != jogadorAtual)
        return false;

    // Verifica se � um movimento de captura (comer pe�a)
    if (abs(diferencaColuna) == 2 && abs(diferencaLinha) == 2)
    {
        int linhaCaptura = (linhaOrigem + linhaDestino) / 2;
        int colunaCaptura = (colunaOrigem + colunaDestino) / 2;

        // Verifica se a posi��o de destino est� vazia
        if (tabuleiro[linhaDestino][colunaDestino] != VAZIO)
            return false;

        int captura = tabuleiro[linhaCaptura][colunaCaptura];

        // Verifica se h� uma pe�a do oponente entre a origem e o destino
        if (jogadorAtual == captura || captura == VAZIO)
            return false;

        return true;
    }

    // Movimento no jogo � v�lido na diagonal e com uma casinha de diferen�a (dist�ncia)
    if (abs(diferencaColuna) != 1 || abs(diferencaLinha) != 1)
        return false;

    // N�o permite que as pe�as pretas des�am
    if (diferencaLinha == 1 && tabuleiro[linhaOrigem][colunaOrigem] == PRETA)
        return false;

    // N�o permite que as pe�as brancas subam
    if (diferencaLinha == -1 && tabuleiro[linhaOrigem][colunaOrigem] == BRANCA)
        return false;

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

    while (getline(arquivo, linha)) // getline pega a primeira linha do arquivo e joga na vari�vel linha, se tiver informa��o em linha getline retorna 1, sen�o tiver retorna 0.
    {
        conteudo += linha + "\n";
    }
    arquivo.close();
    return conteudo;
}

// TODO: implementar a verifica��o de comer pe�a obrigatoriamente?????
// TODO: verificar condi��o de comer mais de uma pe�a na mesma rodada
