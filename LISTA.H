/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Lista
*
*  Arquivo gerado:              LISTA.H
*  Letras identificadoras:      LST
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar uma lista encadeada.
*     Ao iniciar a execução do programa não existe lista.
*     A lista poderá estar vazia. Neste caso o primeiro nó será NULL
*
***************************************************************************/

typedef struct lista LST;


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
	LST * LST_CriarLista ();

/***********************************************************************
*
*  $FC Função: LST Insere
*
*  $EP Parâmetros
*     $P ValorParm - valor a ser inserido na lista
*
*  $ED Descrição da função
*	  Função que insere o novo valor no início da lista.
*
***********************************************************************/
	
	LST * LST_Insere(int x, LST *p);

/***********************************************************************
*
*  $FC Função: LST Imprime 
*
*  $ED Descrição da função
*     Imprime todos os elementos da lista partindo do início da lista.
*     Não imprimirá nada caso a lista esteja vazia.
*
***********************************************************************/
	
	void LST_Imprime (LST *le);

