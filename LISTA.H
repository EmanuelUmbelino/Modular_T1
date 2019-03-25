/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Lista
*
*  Arquivo gerado:              LISTA.H
*  Letras identificadoras:      LST
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar uma lista encadeada.
*     A lista possui uma cabe�a que cont�m uma refer�ncia para a ra�z da
*     lista e outra para um n� corrente da lista.
*     Ao iniciar a execu��o do programa n�o existe lista.
*     A lista poder� estar vazia. Neste caso o primeiro e o n� corrente
*     ser�o nulos, embora a cabe�a esteja definida.
*     O n� corrente ser� nulo se e somente se a lista estiver vazia.
*
***************************************************************************/

typedef struct lista LST;

/***********************************************************************
*
*  $FC Fun��o: LST Criar lista
*
*  $ED Descri��o da fun��o
*     Cria uma nova lista vazia.
*
*  $FV Valor retornado
*     LST
*
***********************************************************************/
	LST * CriaLista ();

/***********************************************************************
*
*  $FC Fun��o: LST Insere
*
*  $EP Par�metros
*     $P ValorParm - valor a ser inserido na lista
*
*  $ED Descri��o da fun��o
*	  Fun��o que insere o novo valor no in�cio da lista.
*
***********************************************************************/
	
	void Insere(int x, LST *p);

/***********************************************************************
*
*  $FC Fun��o: LST Remove 
*
*  $ED Descri��o da fun��o
*     Remove o primeiro elemento da lista.
*     Faz nada caso a lista esteja vazia.
*
***********************************************************************/

	void Remove (LST *p);

/***********************************************************************
*
*  $FC Fun��o: LST Imprime 
*
*  $ED Descri��o da fun��o
*     Imprime todos os elementos da lista partindo do in�cio da lista.
*     N�o imprimir� nada caso a lista esteja vazia.
*
***********************************************************************/
	
	void Imprime (LST *le);
