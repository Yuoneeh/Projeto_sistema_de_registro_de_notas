#include <iostream>
#include <iomanip>
using namespace std;
	
void mostrarTabela(float A1, float A2, float AF) {
    float media = A1 + A2;

    cout << "\nTabela de Notas\n";
    cout << left << setw(10) << "A1"
         << setw(10) << "A2"
         << setw(10) << "AF"
         << "Status\n";

    cout << left << setw(10) << A1
         << setw(10) << A2
         << setw(10) << AF;

    if (media >= 6) {
        cout << "Aprovado\n";
    } else {
        cout << "Reprovado\n";
    }
}

float lerNota(string nomeNota) {
    float nota;
    do {
        cout << "Digite " << nomeNota << " (0 a 5): ";
        cin >> nota;
        if (nota < 0 || nota > 5) {
            cout << "Valor invalido! ";
        }
    } while (nota < 0 || nota > 5);
    return nota;

}

void incluirNotas(float &A1, float &A2, float &AF) {
    A1 = lerNota("A1");
    A2 = lerNota("A2");

    float media = A1 + A2;

    if (media < 6) {
        cout << "Media insuficiente. Necessario fazer AF.\n";
        AF = lerNota("AF");

        if (A1 < A2)
            A1 = AF;
        else
            A2 = AF;
    } else {
        AF = 0;
    }
}

int main() {
    int opcao;
    float A1 = 0, A2 = 0, AF = 0;
    bool notasInseridas = false;

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Tabela de Notas\n";
        cout << "2. Incluir Notas\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                if (notasInseridas)
                    mostrarTabela(A1, A2, AF);
                else
                    cout << "\nNenhuma nota foi inserida ainda.\n";
					cout << 5 << std::endl;
                break;

            case 2:
                incluirNotas(A1, A2, AF);
                notasInseridas = true;
                system("cls");
                break;

            case 3:
                cout << "Saindo...\n";
                break;

            default:
                cout << "Opcao invalida.\n";
                system("cls");
        }
    } while (opcao != 3);

    return 0;
}

