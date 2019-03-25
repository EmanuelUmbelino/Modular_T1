#include <stdio.h>
#include <stdlib.h>
#include "LISTA.H"

typedef struct lista LST;
struct lista 
{
      int data; 
      LST *prox;
};

LST * CriaLista ()
{
	LST *cabeca;
	cabeca = (LST*) malloc(sizeof (LST));
	cabeca->prox = NULL;
	return cabeca;
}

void Insere (int x, LST *p)
{
	LST *nova;
	nova = (LST*) malloc(sizeof (LST));
	nova->data = x;
	nova->prox = p->prox;
	p->prox = nova;
}

void Remove (LST *p)
{
	if (p->prox != NULL)
	{
		LST *lixo;
		lixo = p->prox;
		p->prox = lixo->prox;
		free (lixo);
	}
}

void Imprime (LST *le)
{
	if (le->prox != NULL) 
	{
		printf ("%d\n", le->prox->data);
		Imprime (le->prox);
	}
}