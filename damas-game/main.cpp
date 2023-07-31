#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include "gconio.h"

#define VAZIO 0
#define BRANCA 1
#define PRETA 2

using namespace std;

typedef struct jogador
{
    string nome;
    int vitorias;
    int quantidadePartidas;
} Jogador;

// Funções de arquivo
void escreverArquivo(string diretorio, string conteudo);
string lerArquivo(string diretorio);
void salvarTabuleiro();
void carregarTabuleiro();
void salvarPlacar(Jogador *Jogadores);

// Funções de interface
void printarPlacar();
void printaTabuleiro();
void mostrarGanhador();
void tutorial();

// Funções de jogo
void menu();
bool movimentoValido(int linhaOrigem, int linhaChegada, int colunaOrigem, int colunaChegada, bool isMovimentando);
bool movimentoValido(int linhaOrigem, int linhaChegada, int colunaOrigem, int colunaChegada);
void movimentar();
bool verificaVitoria();
void jogando();

// Funções de inicialização
void inicializarTabuleiro();
void iniciarJogo();

const int TAM_TABULEIRO = 8;

int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {VAZIO};
int jogadorAtual;

void salvarTabuleiro()
{
    // Percorrer o tabuleiro e salvar na variavel conteudo
    string conteudo = "";
    for (int linha = 0; linha < TAM_TABULEIRO; linha++)
    {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++)
        {
            conteudo += to_string(tabuleiro[linha][coluna]); 
        }
    }
    escreverArquivo("save/tabuleiro.txt", conteudo);
}

void carregarTabuleiro()
{
    // Ler o arquivo e salvar na variavel conteudo
    string conteudo = lerArquivo("save/tabuleiro.txt");
    int contador = 0;

    // Percorrer a string conteudo e salvar no tabuleiro
    for (int linha = 0; linha < TAM_TABULEIRO; linha++)
    {
        for (int coluna = 0; coluna < TAM_TABULEIRO; coluna++)
        {
            tabuleiro[linha][coluna] = (int)conteudo[contador];
            contador++;
        }
    }
}

int main()
{
    menu();
    inicializarTabuleiro();

    getch();
    return 0;
}

void menu()
{
    Jogador *Jogadores = new Jogador[2];
    textcolor(GREEN);

    cout << "Digite o nome do jogador 1: ";
    cin >> Jogadores[0].nome;
    Jogadores[0].vitorias = 0;
    Jogadores[0].quantidadePartidas = 0;

    cout << "Digite o nome do jogador 2: ";
    cin >> Jogadores[1].nome;
    Jogadores[1].vitorias = 0;
    Jogadores[1].quantidadePartidas = 0;

    salvarPlacar(Jogadores);

    while (true)
    {

        textbackground(BLACK);
        clrscr();
        // textbackground(RED);
        // textcolor(LIGHTGRAY);
        gotoxy(34, 7);
        cout << (char)(201);
        for (int i = 0; i < 43; i++)
        {
            cout << (char)(205);
        }
        cout << (char)(187);

        for (int i = 8; i <= 18; i++)
        {
            gotoxy(34, i);
            cout << (char)(186);
            for (int j = 0; j < 44; j++)
            {
                if (j == 43)
                {
                    cout << (char)(186);
                    break;
                }
                cout << " ";
            }
        }
        gotoxy(34, 19);
        cout << (char)(200);
        for (int i = 0; i < 43; i++)
        {
            cout << (char)(205);
        }
        cout << (char)(188);

        gotoxy(41, 9);
        cout << "Bem vindo ao jogo de Damas! ";
        gotoxy(38, 11);
        cout << "0 - Tutorial";
        gotoxy(38, 12);
        cout << "1 - Jogar";
        gotoxy(38, 13);
        cout << "2 - Placar";
        gotoxy(38, 14);
        cout << "3 - Sair";
        gotoxy(38, 16);
        cout << "Digite a opcao desejada: ";

        int opcao;
        cin >> opcao;
        textbackground(BLACK);
        // textcolor(WHITE);

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
            getch();
            break;
        case 3:
            clrscr();
            gotoxy(30, 3);
            printf("--APERTE QUALQUER TECLA PARA FECHAR O PROGRAMA--");
            gotoxy(0, 5);
            printf("  ___  ___ ___   ___ ___  ___     _ ___ ___ _____ \n");
            printf(" |   \\/ __|_ _| | _ \\ _ \\/ _ \\ _ | | __/ __|_   _|\n");
            printf(" | |) \\__ \\| |  |  _/   / (_) | || | _| (__  | |  \n");
            printf(" |___/|___/___| |_| |_|_\\\\____/ \\__/|___\\__ | |_|  \n");
            printf("                                                  \n");
            gotoxy(32, 14);
            getch();

            exit(0);

            break;
        }
    }
}

void salvarPlacar(Jogador *Jogadores)
{
    // Percorrer o vetor de jogadores e salvar no arquivo
    string conteudo;
    string diretorio = "save/placar.txt";
    conteudo = Jogadores[0].nome + " " + to_string(Jogadores[0].vitorias) + "\n" + Jogadores[1].nome + " " + to_string(Jogadores[1].vitorias) + "\n";
    escreverArquivo(diretorio, conteudo);
}

void printarPlacar()
{
    // Ler o arquivo e salvar na variavel conteudo
    string diretorio = "save/placar.txt";
    string conteudo = lerArquivo(diretorio);
    cout << conteudo;
}

bool verificaVitoria()
{
    // Verificar se o jogador atual tem peças no tabuleiro
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            // Se tiver, verificar se o jogador atual tem movimentos possíveis
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

    // Se não tiver, o outro jogador venceu
    return true;
}

void tutorial()
{
    clrscr();
    // textbackground(RED);
    // textcolor(LIGHTGRAY);

    for (int i = 1; i < 20; i++)
    {
        gotoxy(10, i);
        for (int j = 0; j < 100; j++)
        {
            cout << " ";
        }
    }

    gotoxy(50, 2);
    cout << "=====Regras=====";

    gotoxy(20, 4);
    cout << "Tabuleiro e Pecas";

    gotoxy(12, 6);
    cout << "1- O jogo pode ser jogado em um tabuleiro 8x8, com casas alternando entre pretas e brancas. ";
    gotoxy(12, 8);
    cout << "2- Cada jogador tem 12 pecas, representadas por pecas brancas e pecas pretas.";
    gotoxy(12, 10);
    cout << "3- Movem-se diagonalmente para frente, promovem-se a dama na ultima linha. Capturas obrigatorias.";
    gotoxy(12, 12);
    cout << "4- Objetivo: capturar todas as pecas do adversario ou bloquea-las.";
    gotoxy(12, 14);
    cout << "5- Maneira de Jogar: letras A-H para linhas, numeros 0-7 para colunas. Divirta-se!";
    gotoxy(12, 18);
    cout << "Pressione qualquer tecla para voltar ao menu principal... ";
    cin.ignore();
    getch();
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
    cout << "Pressione qualquer tecla para sair";
    getch();
    clrscr();
    menu();
}

void mostrarGanhador()
{
    cout << "Jogador " << ((jogadorAtual == BRANCA) ? "Branco" : "Preto") << " ficou sem movimentos!" << endl;
    cout << "Jogador " << ((jogadorAtual == BRANCA) ? "Preto" : "Branco") << " venceu!" << endl;
}

void iniciarJogo()
{

    jogadorAtual = BRANCA; // Primeiro jogador sempre é o branco
    inicializarTabuleiro();
    jogando();
}

void movimentar()
{
    int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
    char letraOrigem, letraDestino;

    gotoxy(5, 27);
    cout << "(0)(0) para Sair ";
    gotoxy(0, 20);

    // Pede a posição da peça que o jogador quer mover
    cout << "Jogador " << ((jogadorAtual == BRANCA) ? "Branco" : "Preto") << ", digite a letra e numero da peca que deseja mover: ";
    cin >> letraOrigem >> colunaOrigem;

    if (letraOrigem == '0' && colunaOrigem == 0)
    {
        salvarTabuleiro();
        clrscr();
        menu();
    }
    // Pede a posição da peça que o jogador quer mover
    cout << "Jogador " << ((jogadorAtual == BRANCA) ? "Branco" : "Preto") << ", digite a letra e numero do destino: ";
    cin >> letraDestino >> colunaDestino;

    // Converte a letra para um número de 0 a 7 (A = 0, B = 1, etc)
    linhaOrigem = ((int)toupper(letraOrigem)) - 65;
    linhaDestino = ((int)toupper(letraDestino)) - 65;

    // Verifica se o movimento é válido
    if (movimentoValido(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, true))
    {
        tabuleiro[linhaDestino][colunaDestino] = jogadorAtual;
        tabuleiro[linhaOrigem][colunaOrigem] = VAZIO;

        // trocar o jogador atual
        jogadorAtual = (jogadorAtual == BRANCA) ? PRETA : BRANCA;
    }
    else
    {
        cout << "Movimento invalido. Tente novamente." << endl;
        movimentar();
    }
}

void printaTabuleiro()
{
    textcolor(WHITE);
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

    cout << (char)(letras + 7) << (char)(186);

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
    textcolor(GREEN);

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
            if ((linha + coluna) % 2 == 0)
                tabuleiro[linha][coluna] = PRETA;
}

bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool isMovimentando)
{
    // Valida se as posições destino estão dentro do tabuleiro
    if (linhaDestino < 0 || linhaDestino >= TAM_TABULEIRO || colunaDestino < 0 || colunaDestino >= TAM_TABULEIRO)
    {
        cout << "Posicao de destino invade o tamanho do tabuleiro" << endl;
        return false;
    }

    int diferencaLinha = linhaDestino - linhaOrigem;
    int diferencaColuna = colunaDestino - colunaOrigem;

    // Verifica se a peça é do jogador atual
    if (tabuleiro[linhaOrigem][colunaOrigem] != jogadorAtual)
    {
        cout << "A peca nao e sua" << endl;
        return false;
    }

    if (tabuleiro[linhaDestino][colunaDestino] != VAZIO)
    {
        cout << "Posicao de destino esta ocupada" << endl;
        return false;
    }

    // Verifica se é um movimento de captura (comer peça)
    if (abs(diferencaColuna) == 2 && abs(diferencaLinha) == 2)
    {
        int linhaCaptura = (linhaOrigem + linhaDestino) / 2;
        int colunaCaptura = (colunaOrigem + colunaDestino) / 2;

        // Verifica se a posição de destino está vazia
        if (tabuleiro[linhaDestino][colunaDestino] != VAZIO)
        {
            cout << "Posicao de destino esta ocupada" << endl;
            return false;
        }

        int captura = tabuleiro[linhaCaptura][colunaCaptura];
        // Verifica se há uma peça do oponente entre a origem e o destino
        if (jogadorAtual == captura || captura == VAZIO)
        {
            cout << "Nao ha peca do oponente entre a origem e o destino" << endl;
            return false;
        }

        // Realiza a captura (comer peça)
        if (isMovimentando == true)
        {
            tabuleiro[linhaCaptura][colunaCaptura] = VAZIO;
        }
        return true;
    }

    // Movimento no jogo é válido na diagonal e com uma casinha de diferença (distância)
    if (abs(diferencaColuna) != 1 || abs(diferencaLinha) != 1)
    {
        cout << "Movimento inserido nao e na diagonal" << endl;
        return false;
    }

    // Não permite que as peças pretas desçam
    if (diferencaLinha == 1 && tabuleiro[linhaOrigem][colunaOrigem] == PRETA)
    {
        cout << "Peca preta nao pode descer" << endl;
        return false;
    }

    // Não permite que as peças brancas subam
    if (diferencaLinha == -1 && tabuleiro[linhaOrigem][colunaOrigem] == BRANCA)
    {
        cout << "Peca branca nao pode subir" << endl;
        return false;
    }

    return true;
}

bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino)
{
    // Valida se as posições destino estão dentro do tabuleiro
    if (linhaDestino < 0 || linhaDestino >= TAM_TABULEIRO || colunaDestino < 0 || colunaDestino >= TAM_TABULEIRO)
        return false;

    int diferencaLinha = linhaDestino - linhaOrigem;
    int diferencaColuna = colunaDestino - colunaOrigem;

    // Verifica se a peça é do jogador atual
    if (tabuleiro[linhaOrigem][colunaOrigem] != jogadorAtual)
        return false;

    // Verifica se a posição de destino está vazia
    if (tabuleiro[linhaDestino][colunaDestino] != VAZIO)
        return false;

    // Verifica se é um movimento de captura (comer peça)
    if (abs(diferencaColuna) == 2 && abs(diferencaLinha) == 2)
    {
        int linhaCaptura = (linhaOrigem + linhaDestino) / 2;
        int colunaCaptura = (colunaOrigem + colunaDestino) / 2;

        // Verifica se a posição de destino está vazia
        if (tabuleiro[linhaDestino][colunaDestino] != VAZIO)
            return false;

        int captura = tabuleiro[linhaCaptura][colunaCaptura];

        // Verifica se há uma peça do oponente entre a origem e o destino
        if (jogadorAtual == captura || captura == VAZIO)
            return false;

        return true;
    }

    // Movimento no jogo é válido na diagonal e com uma casinha de diferença (distância)
    if (abs(diferencaColuna) != 1 || abs(diferencaLinha) != 1)
        return false;

    // Não permite que as peças pretas desçam
    if (diferencaLinha == 1 && tabuleiro[linhaOrigem][colunaOrigem] == PRETA)
        return false;

    // Não permite que as peças brancas subam
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
    ifstream arquivo(diretorio);
    if (!arquivo.is_open())
    {
        cout << "Arquivo nao encontrado" << endl;
        return "";
    }
    string linha;
    string conteudo;

    while (getline(arquivo, linha)) // getline pega a primeira linha do arquivo e joga na variçvel linha, se tiver informação em linha getline retorna 1, senço tiver retorna 0.
    {
        conteudo += linha + "\n";
    }
    arquivo.close();
    return conteudo;
}