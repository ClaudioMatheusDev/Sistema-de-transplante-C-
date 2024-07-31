#include <iostream>
#include "TFila.h"
#include <string>
#include <conio.h>

using namespace std;

//VARIAVEIS GLOBAIS
TFila F1, F2, F3, F4, F5;
void limpaTela();
void menuInicial();
void Cadastrar_Paciente();
void tamanho_Filas();
void retiraPaciente();
void pessoas_Porfila();
void consultar_PacienteTel();

int main(int argc, char** argv) {
    menuInicial();
    return 0;
}//MAIN

void limpaTela(){
    system("CLS");
}//FUNÇÃO PARA LIMPAR A TELA

void menuInicial() {
    // Opção escolhida pelo usuário
    int opcao = 0;
    
    // Enquanto o usuário não digita uma opção válida, mostra o menu novamente
    while(opcao < 1 || opcao > 6) {
        limpaTela();
        cout << "\n\nSISTEMA DE GERENCIAMENTO DE TRANSPLANTE DE CORACAO\n";
        cout << "\nESCOLHA UMA OPCAO: \n";
        cout << "1- Visualizar Tamanho das filas\n";
        cout << "2- Cadastrar Novo Paciente\n";
        cout << "3- Listagem de Todos Pacientes Por Filas\n";
        cout << "4- Retirar um Paciente da Filas\n";
        cout << "5- Consultar Paciente por Nome\n";
        cout << "6- Sair do sistema\n";
        cout << "------------------------------------------------\n";
        cout << "Escolha uma opcao: ";
        
        // Faz a leitura da opção
        cin >> opcao;
        
        // Faz algo de acordo com a opção escolhida
        switch (opcao){
            case 1: 
                tamanho_Filas();
                break;
            case 2:
                Cadastrar_Paciente();
                break;
            case 3:
                pessoas_Porfila();
                break;
            case 4:
                retiraPaciente();
                break;
            case 5:
                consultar_PacienteTel();
                break;
            case 6:
                cout << "\nSaindo do sistema...\n";
                break;
        }
    } 
}

void Cadastrar_Paciente() {
	
    TFila::TInfoFila paciente;
    
    int grau;
    char opcao;
    
	limpaTela();
    cout << "\n\nSISTEMA DE GERENCIAMENTE DE TRANSPLANTES DE CORACAO\n";
    cout << "\nCadastro de Paciente\n\n";
    
    cout << "\nInforme o nome do Paciente:  ";
   	fflush(stdin);
    getline(cin, paciente.nome);
    
    cout << "\nTelefone:   ";
    fflush(stdin);
    getline(cin, paciente.telefone);
    
    cout << "\nGrau  de Urgencia (de 1 a 5): ";
    cin >> grau;
    
    if (grau == 1 ) F1.Enqueue(paciente);
    else if (grau == 2 ) F2.Enqueue(paciente);
    else if (grau == 3 ) F3.Enqueue(paciente);
    else if (grau == 4 ) F4.Enqueue(paciente);
    else if (grau == 5 ) F5.Enqueue(paciente);
    
    cout << "\nPaciente cadastrado com sucesso!";
    
    cout <<"Deseja cadastrar um novo paciente? (S/N)";
    cin >> opcao;
    
    if(opcao != 'S' && opcao != 's'){
    	menuInicial();
	}else{
		Cadastrar_Paciente();
	}
}//CADASTRO DE PACINTES 

void tamanho_Filas(){
	limpaTela();
	cout << "\n\nSISTEMA DE GERENCIAMENTE DE TRANSPLANTES DE CORACAO\n";
    cout << "\nNúmero de pessoas por filas\n\n";
    
    cout << "\nFila----------------Paciente";
    cout << "\n 1  ---------------- "<< F1.Size() << " " ;
    cout << "\n 2  ---------------- "<< F2.Size() << " " ;
    cout << "\n 3  ---------------- "<< F3.Size() << " " ;
    cout << "\n 4  ---------------- "<< F4.Size() << " " ;
    cout << "\n 5  ---------------- "<< F5.Size() << " " ;
    
    cout << "\n\nAperte qualquer tecla para voltar para o menu Principal";
    getch();
    menuInicial();
}//IMPRIMIR O NÚMERO DE PESSOAS POR FILA

void retiraPaciente(){
	TFila::TInfoFila paciente;
	int grau;
	char opcao;
	
	void limpaTela();
	
	cout << "\n\nSISTEMA DE GERENCIAMENTE DE TRANSPLANTES DE CORACAO\n";
	cout << "\nRetirada de Paciente\n\n";
	
	if(!F5.IsEmpty()){
		paciente = F5.GetDadoComeco();
		grau = 5;
	}else if(!F4.IsEmpty()){
		paciente = F4.GetDadoComeco();
		grau = 4;
	}else if (!F3.IsEmpty()){
		paciente = F3.GetDadoComeco();
		grau = 3;
	}else if(!F2.IsEmpty()){
		paciente = F2.GetDadoComeco();
		grau = 2;
	}else if (!F1.IsEmpty()){
		paciente = F1.GetDadoComeco();
		grau = 1;
} else{
	cout <<"\n\nNão tem nenhum paciente na fila de espera!";
	grau = 0;
	
	cout <<"\n\nPrecione qualquer tecla para continuar";
	getch();
	menuInicial();
	}
	
	if( grau  != 0){
		cout << "\n\nO PROXIMO PACIENTE PARA RECEBER O TRANSPLANTE É: ";
		cout << "\nNome....................." << paciente.nome;
		cout << "\nTelefone....................." << paciente.telefone;
		cout << "\nGrau....................." << grau;	
		
		cout << "\nDeseja realmente retirar esté paciente da fila? (S/N) ";
		cin >> opcao;
		
			if(opcao == 'S' || opcao == 's'){
			if( grau == 1) F1.Dequeue();
			else if ( grau == 2) F2.Dequeue();
			else if ( grau == 3) F3.Dequeue();
			else if ( grau == 4) F4.Dequeue();
			else if ( grau == 5) F5.Dequeue();
		
			}
			cout << "Paciente retirado da fila!!";
			cout << "Precione algo para retornar para o menu: ";
			getch();
			menuInicial();
		}
	}//RETIRAR O PACIENTE MAIS URGENTE PARA TRANSPLANTE
	

void pessoas_Porfila(){
	 limpaTela();
	cout << "\n\nSISTEMA DE GERENCIAMENTE DE TRANSPLANTES DE CORACAO\n";
	cout << "\nNúmero de pessoas por filas\n\n";
	
	cout << "\n------Fila 1 ------ ";
	F1.PrintFila();
	cout << "\nFila 2 - ";
	F2.PrintFila();
	cout << "\nFila 3 - ";
	F3.PrintFila();
	cout << "\nFila 4 - ";
	F4.PrintFila();
	cout << "\nFila 5 - ";
	F5.PrintFila();
	
	cout <<"\n\nPrecione qualquer tecla para continuar";
	getch();
    menuInicial();
}//IMPRIME A FILAS E O NOME DAS PESSOAS

void consultar_PacienteTel(){
    string nome;
    bool pacienteEncontrado = false;

    cout << "\n\nSISTEMA DE GERENCIAMENTE DE TRANSPLANTES DE CORACAO\n";
    cout << "\nConsulta de Paciente por Nome\n\n";

    cout << "Digite o nome do paciente que deseja consultar: ";
    cin.ignore();
    getline(cin, nome);

    for (int i = 5; i >= 1; --i) {
        TFila::TNoFila *aux_no = NULL;
        switch (i) {
            case 1: aux_no = F1.GetPtrComeco(); break;
            case 2: aux_no = F2.GetPtrComeco(); break;
            case 3: aux_no = F3.GetPtrComeco(); break;
            case 4: aux_no = F4.GetPtrComeco(); break;
            case 5: aux_no = F5.GetPtrComeco(); break;
        }
        
        int posicao = 1;
        while (aux_no != NULL) { 
            if (aux_no->dado.nome == nome) {
                cout << "Paciente encontrado na Fila " << i << " - Grau " << i << " - Posição na fila: " << posicao << endl;
                cout << "Nome: " << aux_no->dado.nome << endl;
                cout << "Telefone: " << aux_no->dado.telefone << endl;
                pacienteEncontrado = true;
                break;
            }
            aux_no = aux_no->prox;
            ++posicao;
        }
    }
    if (!pacienteEncontrado) {
        cout << "Paciente não encontrado.\n";
    }

    cout << "\n\nPressione qualquer tecla para voltar ao menu principal";
    getch();
    menuInicial();
}//PROCURAR PACIENTE PELO NOME


