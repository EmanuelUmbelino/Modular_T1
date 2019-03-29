#include <stdio.h>
#include <stdlib.h>
#include "LISTA.H"

typedef struct lista LST;
struct lista 
{
      int data; 
      LST *prox;
};

LST * LST_CriaLista ()
{
	LST *cabeca;
	cabeca = (LST*) malloc(sizeof (LST));
	cabeca->prox = NULL;
	return cabeca;
}

void LST_InsereElemento (int x, LST *p)
{
	LST *nova;
	nova = (LST*) malloc(sizeof (LST));
	nova->data = x;
	nova->prox = p->prox;
	p->prox = nova;
}

void LST_RemoveElemento (LST *p)
{
	if (p->prox != NULL)
	{
		LST *lixo;
		lixo = p->prox;
		p->prox = lixo->prox;
		free (lixo);
	}
}

void LST_ImprimeLista (LST *le)
{
	if (le->prox != NULL) 
	{
		printf ("%d\n", le->prox->data);
		LST_Imprime_Lista (le->prox);
	}
}