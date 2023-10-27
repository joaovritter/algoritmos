#include <iostream>
#include <unordered_set>
#include <sstream>

using namespace std;

typedef unordered_set<int> Conjunto; // Definindo um tipo para representar conjuntos de inteiros

// Função para imprimir os elementos de um conjunto
void imprimirConjunto(Conjunto conjunto) {
    cout << "{ ";
    for (auto elemento : conjunto) {
        cout << elemento << " ";
    }
    cout << "}" << endl;
}

// Função para calcular a união de dois conjuntos
Conjunto uniaoConjunto(const Conjunto& conjunto1, const Conjunto& conjunto2) {
    Conjunto resultado = conjunto1;
    resultado.insert(conjunto2.begin(), conjunto2.end());// Insere todos os elementos do conjunto2 no conjunto resultado
    return resultado;
}

// Função para calcular a interseção de dois conjuntos
Conjunto intersecaoConjunto(const Conjunto& conjunto1, const Conjunto& conjunto2) {
    Conjunto resultado;
    for (auto elemento : conjunto1) { // Itera sobre os elementos do conjunto1
        if (conjunto2.find(elemento) != conjunto2.end()) { // se o elemento estiver presente em conjunto2, o elemento é comum a ambos os conjuntos
            resultado.insert(elemento); 
        }
    }
    return resultado;
}

// Função para calcular a diferença entre dois conjuntos
Conjunto diferencaConjunto(const Conjunto& conjunto1, const Conjunto& conjunto2) {
    Conjunto resultado;
    for (auto elemento : conjunto1) {
        if (conjunto2.find(elemento) == conjunto2.end()) {
            resultado.insert(elemento);
        }
    }
    return resultado;
}

// Função para calcular o complemento de um conjunto em relação a outro
Conjunto complementoConjunto(const Conjunto& conjunto1, const Conjunto& conjunto2) {
    Conjunto resultado;
    for (auto elemento : conjunto1) {
        if (conjunto2.find(elemento) == conjunto2.end()) {
            resultado.insert(elemento);
        }
    }
    return resultado;
}

int main() {
    // Declaração dos conjuntos e do conjunto de resultado
    Conjunto conjuntoA, conjuntoB, conjuntoC, conjuntoResultado;

    string input;
    // Preenchendo o conjunto A
    cout << "Preencha o conjunto A (elementos separados por virgula): ";
    getline(cin, input);
    stringstream ssA(input);
    int elementoA;
    while (ssA >> elementoA) { // O loop executa a leitura dos elementos da string, um por um, até não haver mais elementos
        conjuntoA.insert(elementoA);
        if (ssA.peek() == ',') // Verifica se o próximo caractere na string é uma vírgula e, se for, o ignora
            ssA.ignore();
    }

    // Preenchendo o conjunto B
    cout << "Preencha o conjunto B (elementos separados por virgula): ";
    getline(cin, input);
    stringstream ssB(input);
    int elementoB;
    while (ssB >> elementoB) {
        conjuntoB.insert(elementoB);
        if (ssB.peek() == ',')
            ssB.ignore();
    }

    // Preenchendo o conjunto C
    cout << "Preencha o conjunto C (elementos separados por virgula): ";
    getline(cin, input);
    stringstream ssC(input);
    int elementoC;
    while (ssC >> elementoC) {
        conjuntoC.insert(elementoC);
        if (ssC.peek() == ',')
            ssC.ignore();
    }

    // Imprimindo os conjuntos A, B e C
    cout << "Conjunto A: ";
    imprimirConjunto(conjuntoA);
    cout << "\n";

    cout << "Conjunto B: ";
    imprimirConjunto(conjuntoB);
    cout << "\n";

    cout << "Conjunto C: ";
    imprimirConjunto(conjuntoC);
    cout << "\n";

    // Realizando operações de conjunto e imprimindo os resultados
    cout << "Uniao de conjunto A e conjunto B: ";
    conjuntoResultado = uniaoConjunto(conjuntoA, conjuntoB);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    cout << "Intersecao de conjunto A e conjunto B: ";
    conjuntoResultado = intersecaoConjunto(conjuntoA, conjuntoB);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    cout << "Diferenca (conjunto A - conjunto B): ";
    conjuntoResultado = diferencaConjunto(conjuntoA, conjuntoB);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    cout << "Diferenca (conjunto B - conjunto A): ";
    conjuntoResultado = diferencaConjunto(conjuntoB, conjuntoA);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    cout << "Uniao de conjunto A, conjunto B e conjunto C: ";
    conjuntoResultado = uniaoConjunto(conjuntoA, conjuntoB);
    conjuntoResultado = uniaoConjunto(conjuntoResultado, conjuntoC);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    cout << "Intersecao de conjunto A, conjunto B e conjunto C: ";
    conjuntoResultado = intersecaoConjunto(conjuntoA, conjuntoB);
    conjuntoResultado = intersecaoConjunto(conjuntoResultado, conjuntoC);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    cout << "Diferenca (conjunto A - conjunto B - conjunto C): ";
    conjuntoResultado = diferencaConjunto(conjuntoA, conjuntoB);
    conjuntoResultado = diferencaConjunto(conjuntoResultado, conjuntoC);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    cout << "Diferenca (conjunto B - conjunto A - conjunto C): ";
    conjuntoResultado = diferencaConjunto(conjuntoB, conjuntoA);
    conjuntoResultado = diferencaConjunto(conjuntoResultado, conjuntoC);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    // Calculando o complemento de A em relação a B
    cout << "Complemento de A em relacao a B: ";
    conjuntoResultado = complementoConjunto(conjuntoA, conjuntoB);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    // Calculando o complemento de B em relação a A
    cout << "Complemento de B em relacao a A: ";
    conjuntoResultado = complementoConjunto(conjuntoB, conjuntoA);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    // Calculando o complemento de A em relação a C
    cout << "Complemento de A em relacao a C: ";
    conjuntoResultado = complementoConjunto(conjuntoA, conjuntoC);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    // Calculando o complemento de B em relação a C
    cout << "Complemento de B em relacao a C: ";
    conjuntoResultado = complementoConjunto(conjuntoB, conjuntoC);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    // Calculando o complemento de C em relação a A
    cout << "Complemento de C em relacao a A: ";
    conjuntoResultado = complementoConjunto(conjuntoC, conjuntoA);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    // Calculando o complemento de C em relação a B
    cout << "Complemento de C em relacao a B: ";
    conjuntoResultado = complementoConjunto(conjuntoC, conjuntoB);
    imprimirConjunto(conjuntoResultado);
    cout << "\n";

    return 0;
}
