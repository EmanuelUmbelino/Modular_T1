#include <stdio.h>
#include <stdlib.h>
#include "LISTA.H"


struct lista 
{
      int data; 
      LST *prox;
};

/***************************************************************************
*
*  Função: LST Criar lista encadeada de inteiros
*
*  $ED Descrição da função
*		Retorna um ponteiro para LST apontando para NULL, criando então
*		o início da lista encadeada de inteiros
*
***************************************************************************/

LST * LST_CriarLista ()
{
	return NULL;
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

LST * LST_Insere (int x, LST *p)
{
	LST *nova;
	
	nova =(LST*)malloc(sizeof (LST));
	if (nova == NULL) 
	{
		printf("Erro na alocação de memória para o nó da lista\n");
		return NULL;
	} /* if */
	
	nova->data = x;
	nova->prox = p;
	p = nova;
	return p ;
}

/***************************************************************************
*
*  Função: LST Criar lista encadeada de inteiros
*  
***************************************************************************/

void LST_Imprime (LST *le)
{
	if (le != NULL) 
	{
		printf ("%d -> ", le->data);
		LST_Imprime (le->prox);
	} /* if */ 
	else
	{
		printf("NULL\n");
	}/* else */
}