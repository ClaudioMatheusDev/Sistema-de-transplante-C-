#include "TFila.h"
#include <iostream>

using namespace std;

void TFila::Init()
{
	Comeco = NULL;
	Final  = NULL;		
} 

//-------------------------------------------------------------
bool TFila::IsEmpty()
{
	return Comeco == NULL;				
} 

//-------------------------------------------------------------
void TFila::Enqueue(TInfoFila elemento)
{
	TNoFila *novo;
	novo = new TNoFila;

	novo->dado = elemento;
	novo->prox = NULL;
	
	if( IsEmpty() )	
	{
		Comeco = novo;
		Final  = novo;					
	} // se a Fila estiver vazia
	else
	{
		Final->prox = novo;			
		Final  = novo;						
	} // se a Fila NÃÃÃÃÕOOOO estiver vazia		
} // void Enqueue(int n)

//-------------------------------------------------------------
TFila::TInfoFila TFila::Dequeue()
{
	TInfoFila aux;		
	TNoFila *no_aux;
	
	if( !IsEmpty() )			{		
		aux = Comeco->dado;			
		no_aux = Comeco;			
		Comeco = Comeco->prox;				
		delete(no_aux);
	}
	
	return aux;	
	
} // Dequeue

//-------------------------------------------------------------
TFila::TInfoFila TFila::GetDadoComeco()
{
	// se a Fila não estiver vazia
	if( !IsEmpty() )
	{
		return Comeco->dado;		
	} 
} 

//-------------------------------------------------------------
TFila::TInfoFila TFila::GetDadoFinal()
{
	// se a Fila não estiver vazia
	if( !IsEmpty() )
	{
		return Final->dado;		
	} 
} 

//-------------------------------------------------------------
TFila::TNoFila *TFila::GetPtrComeco()
{
	return Comeco;	
}

//-------------------------------------------------------------
void TFila::PrintFila()
{	
	if( !IsEmpty() )
	{
		TNoFila *aux_no;		
		cout << "\n\nO CONTEUDO DA FILA E:\n";
		aux_no = Comeco;	
		while( aux_no != NULL )		
		{
			cout << aux_no->dado.nome << "\n";
			aux_no = aux_no->prox;
		}

	} // se a fila não estiver fazia
	else 
	{
		cout << "\n\nA FILA esta vazia !!!";
	}		
	cout << "\n\n";			
} // PrintFila

//-- Construtor ------------------------------------------------
// 
TFila::TFila()
{
	Init();
}

//-- Destrutor ------------------------------------------------
TFila::~TFila()
{
	while( !IsEmpty() ) Dequeue();
}

// Obtem o total de elementos da Fila -------------------------
int TFila::Size()
{
	int total = 0;
	
	TNoFila *aux;
	
	aux = Comeco;
	while( aux != NULL )
	{
		total++;		
		aux = aux->prox;
	} // while...
	
	return total;
	
} // Size()





