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
*     A lista possui uma cabeça que contém uma referência para a raíz da
*     lista e outra para um nó corrente da lista.
*     Ao iniciar a execução do programa não existe lista.
*     A lista poderá estar vazia. Neste caso o primeiro e o nó corrente
*     serão nulos, embora a cabeça esteja definida.
*     O nó corrente será nulo se e somente se a lista estiver vazia.
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
	LST * LST_CriaLista();

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
	
	void LST_Insere_Elemento (int x, LST *p);

/***********************************************************************
*
*  $FC Função: LST Remove 
*
*  $ED Descrição da função
*     Remove o primeiro elemento da lista.
*     Faz nada caso a lista esteja vazia.
*
***********************************************************************/

	void LST_Remove_Elemento (LST *p);

/***********************************************************************
*
*  $FC Função: LST Imprime 
*
*  $ED Descrição da função
*     Imprime todos os elementos da lista partindo do início da lista.
*     Não imprimirá nada caso a lista esteja vazia.
*
***********************************************************************/
	
	void LST_Imprime_Lista (LST *le);

