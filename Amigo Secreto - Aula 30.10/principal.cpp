#include <iostream>
#include <fstream>
#include <string>
#include <vector> // vetores dinamicos
#include <algorithm> // funcao shuffle para embaralhar os nomes no vetor
#include <random>
#include <ctime>
#define TAM 50

using namespace std;

#include "struct.h" 
#include "metodos.h"

int main (){
    Amigo *vetor;
    int totalAmigos = 0;
    vetor = new Amigo[TAM];

    vector<string> nomes; //vetor de amigos

    // Carrega as criptomoedas do arquivo CSV para o vetor antes de abrir o menu
    ifstream arquivoEntrada("amigos.csv");
    if (arquivoEntrada.is_open()) {
        string linha;
        while (getline(arquivoEntrada, linha)) {
            size_t pos1 = linha.find(',');
            size_t pos2 = linha.find(',', pos1 + 1);
            if (pos1 != string::npos && pos2 != string::npos) {
                vetor[totalAmigos].nome = linha.substr(0, pos1);
                vetor[totalAmigos].email = linha.substr(pos1 + 1, pos2 - pos1 - 1);
                totalAmigos++;
            }
        }
        arquivoEntrada.close();
    } else {
        cout << "Erro ao abrir o arquivo amigo.csv\n";
        delete[] vetor;
        return 1;
    }

    lerNomesDoArquivo(nomes);
    embaralharNomes(nomes);
    menu (vetor, TAM, totalAmigos);
    salvar (vetor, totalAmigos);
    delete[] vetor;
return 0;
}
