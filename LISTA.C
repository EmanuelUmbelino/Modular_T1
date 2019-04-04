/***************************************************************************
*  $MCI Módulo de implementação: Módulo lista
*
*  Arquivo gerado:              LISTA.C
*  Letras identificadoras:      LST
*
*  Projeto: Disciplina INF 1301
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LISTA.H"


/***********************************************************************
*
*  $TC Tipo de dados: LST Descritor do nó da lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/

	struct lista 
	{
			int data ; 
			LST *prox ;
	} ;


/***************************************************************************
*
*  Função: LST Criar lista encadeada de inteiros
*
*  $ED Descrição da função
*		Retorna um ponteiro para LST apontando para NULL, criando então
*		o início da lista encadeada de inteiros
*
***************************************************************************/

	LST * LST_CriarLista ( void )
	{
		return NULL ;
	}


/***************************************************************************
*
*  Função: LST Criar lista encadeada de inteiros
*
*  $ED Descrição da função
*		Função cria um novo nó do tipo LST e o insere no início da lista
*		tornando esse o novo primeiro elemento da lista encadeada.
*  
***************************************************************************/

	void LST_Insere ( int x, LST ** p )
	{
		LST *nova ;
		
		nova = ( LST * ) malloc( sizeof( LST )) ;
		if (nova == NULL) 
		{
			printf("\nErro na alocação de memória para o nó da lista\n") ;
			return ;
		} /* if */
		
		nova->data = x ;
		nova->prox = *p ;
		*p = nova ;

	} /* Fim função:  LST Criar lista encadeada de inteiros */

/***************************************************************************
*
*  Função: LST Imprime lista
*  
***************************************************************************/

	void LST_Imprime ( LST *le )
	{

		if (le != NULL) 
		{
			printf ("%d -> ", le->data) ;
			LST_Imprime (le->prox) ;
		} /* if */ 
		else
		{
			printf("NULL\n") ;
		}/* else */

	} /* Fim função: LST Imprime lista */


/********** Fim do módulo de implementação: Módulo lista **********/