#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int opcao;
	float A1, A2, AF, Aprovacao, media;
	
	do{
		cout << "\n Menu \n";
		cout << "\n 1. Tabela de Notas. \n";
		cout << "\n 2. Inclua as Notas. \n";
		cout << "\n 3. Sair. \n";
		cin >> opcao;
		
		switch (opcao){
			case 1:
				cout << "\nTabela de notas\n";
				cout << left << setw(10) << "A1" << setw(10) << "A2" << setw(10) << "Aprovacao";  
				cout << left << setw(10) << A1 << setw(10) << A2 << setw(10) << Aprovacao;
				
				Aprovacao = (A1 + A2);
		
				if (Aprovacao >= 6 ){
					cout << setw(10) << "Aprovado.";
				}else{
					cout << setw(10) << "Reprovado.";
				}
				break;
				
			case 2:
				 cout << "Digite a A1 ";
				 cin >> A1;
				while (A1 > 5 || A1 < 0 ){
					cout << "Digite novamente a A1 ";
					cin >> A1;
				}
				cout << "Digite a A2 ";	
				cin >> A2;
				while (A2 > 5 || A2 < 0 ){
					cout << "Digite novamente a A2";
					cin >> A2;
				}
				media = (A1 + A2);
				if ( media < 6)
				cout << "Voce foi Reprovado Faca a AF. ";
				cin >> AF;
				
				if (A1 < A2){
					A1 = AF;
				}else{
					A2 = AF;
				}
				
				media = (A1 + A2);
				else {
					AF = 0;
				} 
				
				Aprovacao = media;
				
				 
			system("cls");
			break;
				
			case 3:
				cout << "Saindo \n";
				system("cls");
				break;
			default:
				cout << "opcao invalida \n";
		}
	} while (opcao != 3);
return 0;
}
