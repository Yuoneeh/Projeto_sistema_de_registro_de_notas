#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

struct Aluno {
    string nome;
    float A1 = 0, A2 = 0, AF = 0;
};

int main() {
    int opcao;
    vector<Aluno> alunos;
    Aluno aluno;

    do {
        cout << "\n Menu \n";
        cout << "1. Tabela de Notas\n";
        cout << "2. Incluir Notas\n";
        cout << "3. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
        case 1:
            if (alunos.empty()) {
                cout << "Nenhum aluno cadastrado.\n";
            } else {
                cout << left << setw(15) << "Nome"
                     << setw(10) << "A1"
                     << setw(10) << "A2"
                     << setw(10) << "AF"
                     << setw(15) << "Situacao" << endl;

                for (size_t i = 0; i < alunos.size(); i++) {
    				Aluno a = alunos[i];
    				float media = a.A1 + a.A2;
    				string situacao;

    			if (media >= 6) {
      				situacao = "Aprovado";
    			} else {
      				float novaMedia = (a.A1 < a.A2 ? a.AF + a.A2 : a.A1 + a.AF);
       				 situacao = novaMedia >= 6 ? "Aprovado c/ AF" : "Reprovado";
    			}

                    cout << left << setw(15) << a.nome
                         << setw(10) << a.A1
                         << setw(10) << a.A2
                         << setw(10) << a.AF
                         << setw(15) << situacao << endl;
                }
            }
            break;

        case 2:
            cout << "Digite o nome do aluno: ";
            cin.ignore();
            getline(cin, aluno.nome);

            cout << "Digite a nota A1: ";
            cin >> aluno.A1;
            while (aluno.A1 < 0 || aluno.A1 > 5) {
                cout << "Digite A1 novamente: ";
                cin >> aluno.A1;
            }

            cout << "Digite a nota A2: ";
            cin >> aluno.A2;
            while (aluno.A2 < 0 || aluno.A2 > 5) {
                cout << "Digite A2 novamente: ";
                cin >> aluno.A2;
            }

            if ((aluno.A1 + aluno.A2) < 6) {
                cout << "Voce foi reprovado. Digite a nota da AF: ";
                cin >> aluno.AF;
            } else {
                aluno.AF = 0;
            }

            alunos.push_back(aluno);
            system("cls");
            break;

        case 3:
            cout << "Saindo...\n";
            break;

        default:
            cout << "Opcao invalida.\n";
        }

    } while (opcao != 3);

    return 0;
}
