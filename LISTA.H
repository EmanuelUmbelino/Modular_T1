/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Lista
*
*  Arquivo gerado:              LISTA.H
*  Letras identificadoras:      LST
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar uma lista encadeada.
*     Ao iniciar a execução do programa não existe lista.
*     A lista poderá estar vazia. Neste caso o primeiro nó será NULL.
*
***************************************************************************/


/***********************************************************************
*
*  $TC Tipo de dados: LST Descritor do nó da lista
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/

typedef struct lista LST ;


/***********************************************************************
*
*  $FC Função: LST Criar lista
*
*  $ED Descrição da função
*     Cria uma nova lista vazia.
*
*  $FV Valor retornado
*     LST
*
***********************************************************************/

	LST * LST_CriarLista ( void ) ;


/***********************************************************************
*
*  $FC Função: LST Insere
*
*  $EP Parâmetros
*     $P x - valor a ser inserido na lista
*     $P p - ponteiro de ponteiro para lista
*
*  $ED Descrição da função
*	  Função que insere o novo valor no início da lista.
*
***********************************************************************/
	
	void LST_Insere ( int x, LST **p ) ;


/***********************************************************************
*
*  $FC Função: LST Imprime 
*
*  $ED Descrição da função
*     Imprime todos os elementos da lista partindo do início da lista.
*     Não imprimirá nada caso a lista esteja vazia.
*
***********************************************************************/
	
	void LST_Imprime ( LST *le ) ;

