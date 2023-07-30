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

const string diretorio = "save/dados.txt"; // a cada pasta coloca-se uma nova barra e no final deve ser o nome do arquivo e a extensão.
const int TAM_TABULEIRO = 8;

int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {VAZIO};
int jogadorAtual;

int main()
{
    // Ler o nome dos jogadores
    // Buscar no arquivo de placar se já existe um jogador com o mesmo nome
    // Se existir, carregar os dados dele
    // Se não existir, criar um novo jogador

    menu();

    int travaFechamentoDaJanelaDoTerminal; // Variável para impedir que o programa feche após a execução
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
    cout << "Digite a opção desejada: ";
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
    // Verificar se ja existe um jogador com o mesmo nome no arquivo de placar, se existir atualizar a pontuação dele, se não, criar ele
}

void printarPlacar()
{
    // Ler todas as structs do arquivo e printar ordenadamente por quantidade de vitórias
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
    cout << setw(50);
    cout << "Regras" << endl;
    cout << endl;
    cout << setw(55);
    cout << "Tabuleiro e Peças" << endl;
    cout << endl;
    cout << setw(60);
    cout << "1- O jogo é jogado em um tabuleiro 8x8, com casas alternando entre pretas e brancas. " << endl;
    cout << setw(60);
    cout << "2- Cada jogador tem 12 peças, representadas por peças brancas e peças pretas." << endl;
    cout << setw(60);
    cout << "3- Movem-se diagonalmente para frente, promovem-se a dama na última linha. Capturas obrigatórias." << endl;
    cout << setw(60);
    cout << "4- Objetivo: capturar todas as peças do adversário ou bloqueá-las." << endl;
    cout << setw(60);
    cout << "5- Notação: letras A-H para linhas, números 0-7 para colunas. Divirta-se!" << endl;
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
    jogadorAtual = BRANCA; // Primeiro jogador sempre é o branco
    inicializarTabuleiro();
    jogando();
}

void movimentar()
{
    int linhaOrigem, colunaOrigem, linhaDestino, colunaDestino;
    char letraOrigem, letraDestino;
    cout << "Jogador " << ((jogadorAtual == BRANCA) ? "Branco" : "Preto") << ", digite a letra e numero da peça que deseja mover: ";
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
        cout << "Movimento inválido. Tente novamente." << endl;
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

bool comerPeca(int linhaCaptura, int colunaCaptura)
{
    tabuleiro[linhaCaptura][colunaCaptura] = VAZIO;
}

bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool isMovimentando)
{
    // Valida se as posições destino estão dentro do tabuleiro
    if (linhaDestino < 0 || linhaDestino >= TAM_TABULEIRO || colunaDestino < 0 || colunaDestino >= TAM_TABULEIRO)
    {
        cout << "Posição de destino invade o tamanho do tabuleiro" << endl;
        return false;
    }

    int diferencaLinha = linhaDestino - linhaOrigem;
    int diferencaColuna = colunaDestino - colunaOrigem;

    // Verifica se a peça é do jogador atual
    if (tabuleiro[linhaOrigem][colunaOrigem] != jogadorAtual)
    {
        cout << "A peça não é sua" << endl;
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
            cout << "Posição de destino está ocupada" << endl;
            return false;
        }

        int captura = tabuleiro[linhaCaptura][colunaCaptura];
        // Verifica se há uma peça do oponente entre a origem e o destino
        if (jogadorAtual == captura || captura == VAZIO)
        {
            cout << "Não há peça do oponente entre a origem e o destino" << endl;
            return false;
        }

        // Realiza a captura (comer peça)
        if (isMovimentando == true)
        {
            comerPeca(linhaCaptura, colunaCaptura);
        }
        // to do: atualizar o placar
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
        cout << "Peça preta não pode descer" << endl;
        return false;
    }

    // Não permite que as peças brancas subam
    if (diferencaLinha == -1 && tabuleiro[linhaOrigem][colunaOrigem] == BRANCA)
    {
        cout << "Peça branca não pode subir" << endl;
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
    fstream arquivo(diretorio, ios::in);
    string linha;
    string conteudo;

    while (getline(arquivo, linha)) // getline pega a primeira linha do arquivo e joga na variçvel linha, se tiver informação em linha getline retorna 1, senço tiver retorna 0.
    {
        conteudo += linha + "\n";
    }
    arquivo.close();
    return conteudo;
}

// TODO: implementar a verificação de comer peça obrigatoriamente?????
// TODO: verificar condição de comer mais de uma peça na mesma rodada
