/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo lista
*
*  Arquivo gerado:              LISTA.C
*  Letras identificadoras:      LST
*
*  Projeto: Disciplina INF 1301
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - Jo�o Pedro Kalil
*        phs - Pedro Henrique Soares
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LISTA.H"


/***********************************************************************
*
*  $TC Tipo de dados: LST Descritor do n� da lista
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o do n�
*
***********************************************************************/

	struct lista 
	{
			int data ; 
			LST *prox ;
	} ;


/***************************************************************************
*
*  Fun��o: LST Criar lista encadeada de inteiros
*
*  $ED Descri��o da fun��o
*		Retorna um ponteiro para LST apontando para NULL, criando ent�o
*		o in�cio da lista encadeada de inteiros
*
***************************************************************************/

	LST * LST_CriarLista ( void )
	{
		return NULL ;
	}


/***************************************************************************
*
*  Fun��o: LST Criar lista encadeada de inteiros
*
*  $ED Descri��o da fun��o
*		Fun��o cria um novo n� do tipo LST e o insere no in�cio da lista
*		tornando esse o novo primeiro elemento da lista encadeada.
*  
***************************************************************************/

	void LST_Insere ( int x, LST ** p )
	{
		LST *nova ;
		
		nova = ( LST * ) malloc( sizeof( LST )) ;
		if (nova == NULL) 
		{
			printf("\nErro na aloca��o de mem�ria para o n� da lista\n") ;
			return ;
		} /* if */
		
		nova->data = x ;
		nova->prox = *p ;
		*p = nova ;

	} /* Fim fun��o:  LST Criar lista encadeada de inteiros */

/***************************************************************************
*
*  Fun��o: LST Imprime lista
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

	} /* Fim fun��o: LST Imprime lista */


/********** Fim do m�dulo de implementa��o: M�dulo lista **********/