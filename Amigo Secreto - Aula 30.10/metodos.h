#include <fstream>
#include "util.h"

void salvar(const Amigo vetor[], int totalAmigos) {
    // Abre o arquivo para escrita
    ofstream arquivo("amigos.csv", ios::trunc);

    // Verifica se o arquivo foi aberto com sucesso
    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo cripto.csv\n";
        return;
    }
    // Escreve as criptomoedas no formato do CSV   
    for (int i = 0; i < totalAmigos; i++) {
        arquivo << vetor[i].nome << ";" << vetor[i].email << endl;
    }
    // Fecha o arquivo
    arquivo.close();

}

bool jaCadastrado (string nome, Amigo vetor[], int n){
    for (int i = 0; i < n; i++){
        if (vetor[i].nome == nome){
        return true;
        }
    }
    return false;
}


void cadastrar(Amigo vetor[], int n, int &totalAmigos) {
    // Verifica se há espaço para adicionar um novo amigo
    if (totalAmigos >= n) {
        cout << "Amigo secreto lotado\n";
        return;
    }

    // Obtém dados do usuário
    string nome;
    string email;
    cout << "Informe o Nome: ";
    cin >> nome;
    cout << "Email: ";
    cin >> email;

    if (jaCadastrado( nome, vetor, totalAmigos)){
        cout << "Nome ja cadastrado\n";
        return;
    }

    // Lógica para adicionar um novo amigo ao vetor
    vetor[totalAmigos].nome = nome;
    vetor[totalAmigos].email = email;
    totalAmigos++;


    // Tenta abrir o arquivo para adicionar o novo amigo
    ofstream arquivo("amigos.csv", ios::app);
    if (arquivo.is_open()) {
        // Escreve o novo amigo no formato CSV
        arquivo << nome << "," << email << "\n";
        arquivo.close();
        cout << "Amigo adicionado a amigos.csv com sucesso.\n";
    } else {
        cout << "Erro ao abrir o arquivo amigos.csv para salvar o novo amigo.\n";
    }
}



void listar (Amigo vetor[], int totalAmigos){
    cout << "Listando Amigos\n";
    for (int i = 0; i < totalAmigos; i++){
        cout << vetor[i].nome << "  " << vetor[i].email << endl;
    }
}

void lerNomesDoArquivo(vector<string> &nomes) {
    ifstream arquivo("amigos.csv");
    if (arquivo.is_open()) {
        string nome;
        while (getline(arquivo, nome, ',')) {
            nomes.push_back(nome);
        }
        arquivo.close();
    } else {
        cout << "Erro ao abrir o arquivo amigos.csv\n";
    }
}

void embaralharNomes(vector<string> &nomes) {
    //converte esse timestamp para um valor unsigned que será usado como a semente (seed) para o gerador de números aleatórios.
    unsigned seed = static_cast<unsigned>(time(0));
    // vec.begin e .end definem o intervalo de elementos que serão embaralhados
    shuffle(nomes.begin(), nomes.end(),default_random_engine(seed)); //gerador de números aleatórios, seed para garantir sequencia diferente a cada execucao
        //shuffle embaralha a partir de um intervalo de elementos e gerador de numeros aleatorios. reorganiza aleatoriamente 
}


void gerarDuplas(const vector<string> &nomes) {
    vector<string> nomesEmbaralhados = nomes;
    embaralharNomes(nomesEmbaralhados);  

    cout << "Duplas do Amigo Secreto:\n";
    for (size_t i = 0; i < nomes.size(); ++i) {
        cout << nomes[i] << " -> " << nomesEmbaralhados[i] << endl;
    }
}

void menu (Amigo vetor [], int n, int totalAmigos) { 
    do {
    int opcao;
    vector<string> nomesAmigos;
    system ("cls");
    cout << "1 - Cadastrar Amigo\n";
    cout << "2 - Listar Amigos\n";
    cout << "3 - Gerar Amigo Secreto\n";
    cout << "4 - Sair\n";
    cout << "Opcao: ";
    cin >> opcao;

    switch (opcao){
    case 1:
        cout << "Cadastrando\n";
        cadastrar (vetor, n, totalAmigos);
        break;
    case 2:
        cout << "Listando\n";
        listar (vetor, totalAmigos);
        break;
    case 3:
        cout << "Gerando\n";
        
        lerNomesDoArquivo(nomesAmigos);
        embaralharNomes(nomesAmigos);
        gerarDuplas(nomesAmigos);
        break;
    case 4:
        exit(1);
    
    default:
    cout << "Opcao invalida!\n";
        break;
    }
    system ("pause");

  }while (true);
}