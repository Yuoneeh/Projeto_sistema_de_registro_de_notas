#include <iostream>
#include <string>
#include <iomanip> // Para formata��o da tabela

using namespace std;

int main() {
    int n; // N�mero de pessoas
    cout << "Digite o n�mero de pessoas: ";
    cin >> n;

    // Criando arrays para armazenar os nomes e idades
    string nomes[n];
    int idades[n];

    // Coletando os dados do usu�rio
    for (int i = 0; i < n; i++) {
        cout << "Digite o nome da pessoa " << i + 1 << ": ";
        cin.ignore(); // Para ignorar o newline que fica no buffer ap�s cin
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
