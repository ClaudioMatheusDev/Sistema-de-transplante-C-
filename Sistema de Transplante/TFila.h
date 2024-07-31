#include <iostream>
#ifndef TFILA_H
#define TFILA_H

using namespace std;

class TFila
{
	//------------------------------------------------------------------------------
	public:
		//--- Definição da Estrutura da Fila -------------------------		
		//typedef int TInfoFila;
		
		typedef struct {			
			string nome;
			string telefone;				
		} TInfoFila;
		
		
		struct TNoFila {	
			TInfoFila dado;	
			TNoFila *prox;		
		};
				
		int Size();

		bool IsEmpty();
		void Enqueue(TInfoFila elemento);
		TInfoFila Dequeue();
		TInfoFila GetDadoComeco();
		TInfoFila GetDadoFinal();
		TNoFila * GetPtrComeco();
		void PrintFila();		
		TFila();
		~TFila();
		
		
	//------------------------------------------------------------------------------
	protected:
		TNoFila *Comeco;
		TNoFila *Final;
		void Init();

}; // class TFila

#endif
