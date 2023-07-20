#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void escreverArquivo(string diretorio, string conteudo);
string lerArquivo(string diretorio);

const string diretorio = "save/dados.txt"; //a cada pasta coloca-se uma nova barra e no final deve ser o nome do arquivo e a extensão.

int main()
{
    return 0;

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
