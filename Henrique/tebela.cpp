#include <iostream>
#include <string>
#include <iomanip> // Para formatação da tabela

using namespace std;

int main() {
    int n; // Número de pessoas
    cout << "Digite o número de pessoas: ";
    cin >> n;

    // Criando arrays para armazenar os nomes e idades
    string nomes[n];
    int idades[n];

    // Coletando os dados do usuário
    for (int i = 0; i < n; i++) {
        cout << "Digite o nome da pessoa " << i + 1 << ": ";
        cin.ignore(); // Para ignorar o newline que fica no buffer após cin
        getline(cin, nomes[i]);
        cout << "Digite a idade de " << nomes[i] << ": ";
        cin >> idades[i];
    }

    // Exibindo a tabela
    cout << "\nTabela de Dados\n";
    cout << left << setw(20) << "Nome" << setw(10) << "Idade" << endl;
    cout << "-------------------------------" << endl;
    
    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << nomes[i] << setw(10) << idades[i] << endl;
    }

    return 0;
}
