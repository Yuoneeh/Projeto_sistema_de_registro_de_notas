#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

struct Aluno {
    string nome;
    float A1 = 0, A2 = 0, AF = 0;
};

int Filtrar(const vector<Aluno>& alunos) {
    int opcaofiltro;
    cout << "\nOrdenar por...";
    cout << "\n1. Aprovados";
    cout << "\n2. Reprovados";
    cout << "\n3. Voltar";
    cout << "\nEscolha uma opcao: ";
    cin >> opcaofiltro;

    system("cls");

    if (alunos.empty()) {
        cout << "Nenhum aluno cadastrado.\n";
        system("pause");
        return opcaofiltro;
    }

    cout << left << setw(15) << "Nome"
         << setw(10) << "A1"
         << setw(10) << "A2"
         << setw(10) << "AF"
         << setw(15) << "Situacao" << endl;

    for (const Aluno& a : alunos) {
        float media = a.A1 + a.A2;
        string situacao;

        if (media >= 6) {
            situacao = "Aprovado";
        } else {
            float novaMedia = (a.A1 < a.A2 ? a.AF + a.A2 : a.A1 + a.AF);
            situacao = novaMedia >= 6 ? "Aprovado c/ AF" : "Reprovado";
        }

        if ((opcaofiltro == 1 && (situacao == "Aprovado" || situacao == "Aprovado c/ AF")) ||
            (opcaofiltro == 2 && situacao == "Reprovado")) {
            cout << left << setw(15) << a.nome
                 << setw(10) << a.A1
                 << setw(10) << a.A2
                 << setw(10) << a.AF
                 << setw(15) << situacao << endl;
        }
    }

    cout << "\nPressione ENTER para retornar ao menu.";
    cin.ignore();
    cin.get();

    return opcaofiltro;
}

int Logo() {
    cout << " $$$$$$\\   $$$$$$\\  $$\\   $$\\  $$$$$$\\   $$$$$$\\  $$\\             $$\\       $$$$$$\\   $$$$$$\\   $$$$$$\\ " << endl;
    cout << "$$  __$$\\ $$  __$$\\ $$ |  $$ |$$  __$$\\ $$  __$$\\ $$ |            $$ |     $$  __$$\\ $$  __$$\\ $$  __$$\\ " << endl;
    cout << "$$ /  \\__|$$ /  \\__|$$ |  $$ |$$ /  $$ |$$ /  $$ |$$ |            $$ |     $$ /  $$ |$$ /  \\__|$$ /  \\__|" << endl;
    cout << "\\$$$$$$\\  $$ |      $$$$$$$$ |$$ |  $$ |$$ |  $$ |$$ |            $$ |     $$ |  $$ |$$ |$$$$\\ \\$$$$$$\\  " << endl;
    cout << " \\____$$\\ $$ |      $$  __$$ |$$ |  $$ |$$ |  $$ |$$ |            $$ |     $$ |  $$ |$$ |\\_$$ | \\____$$\\ " << endl;
    cout << "$$\\   $$ |$$ |  $$\\ $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |            $$ |     $$ |  $$ |$$ |  $$ |$$\\   $$ |" << endl;
    cout << "\\$$$$$$  |\\$$$$$$  |$$ |  $$ | $$$$$$  | $$$$$$  |$$$$$$$$\\       $$$$$$$$\\ $$$$$$  |\\$$$$$$  |\\$$$$$$  |" << endl;
    cout << " \\______/  \\______/ \\__|  \\__| \\______/  \\______/ \\________|      \\________|\\______/  \\______/  \\______/ " << endl;
    return 0;
}

int main() {
    int opcao;
    vector<Aluno> alunos;
    Aluno aluno;

    Logo();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("cls");

    do {
        cout << "\n Menu \n";
        cout << "1. Tabela de Notas\n";
        cout << "2. Incluir Notas\n";
        cout << "3. Filtrar\n";
        cout << "4. Créditos\n";
        cout << "5. Sair\n";
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

                    for (const Aluno& a : alunos) {
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
                cout << "\nPressione ENTER para retornar ao menu.";
                cin.ignore();
                cin.get();
                system("cls");
                break;

            case 2:
                cout << "Digite o nome do aluno: ";
                cin.ignore(1000, '\n');
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
                system("cls");
                Filtrar(alunos);
                break;

            case 4:
                Logo();
                cout << "\nCódigo originalmente desenvolvido por Henrique Bergotti, Hugo Trindade, Eduardo Felipe e Lucas Henrique\n";
                cout << "Pressione ENTER para retornar.";
                cin.ignore();
                cin.get();
                system("cls");
                break;

            case 5:
                cout << "Saindo...";
                break;

            default:
                cout << "Opcao invalida.\n";
        }

    } while (opcao != 5);

    return 0;
}
