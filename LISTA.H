/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Lista
*
*  Arquivo gerado:              LISTA.H
*  Letras identificadoras:      LST
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - Jo�o Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar uma lista encadeada.
*     Ao iniciar a execu��o do programa n�o existe lista.
*     A lista poder� estar vazia. Neste caso o primeiro n� ser� NULL.
*
***************************************************************************/


/***********************************************************************
*
*  $TC Tipo de dados: LST Descritor do n� da lista
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o do n�
*
***********************************************************************/

typedef struct lista LST ;


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

	LST * LST_CriarLista ( void ) ;


/***********************************************************************
*
*  $FC Fun��o: LST Insere
*
*  $EP Par�metros
*     $P x - valor a ser inserido na lista
*     $P p - ponteiro de ponteiro para lista
*
*  $ED Descri��o da fun��o
*	  Fun��o que insere o novo valor no in�cio da lista.
*
***********************************************************************/
	
	void LST_Insere ( int x, LST **p ) ;


/***********************************************************************
*
*  $FC Fun��o: LST Imprime 
*
*  $ED Descri��o da fun��o
*     Imprime todos os elementos da lista partindo do in�cio da lista.
*     N�o imprimir� nada caso a lista esteja vazia.
*
***********************************************************************/
	
	void LST_Imprime ( LST *le ) ;

