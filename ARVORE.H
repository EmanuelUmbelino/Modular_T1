#if ! defined( ARVORE_ )
#define ARVORE_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo árvore
*
*  Arquivo gerado:              ARVORE.H
*  Letras identificadoras:      ARV
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: elu - Emanuel Lima Umbelino
*        jpk - João Pedro Kalil
*        phs - Pedro Henrique Soares
*
*  $HA Histórico de evolução:
*     Versão   Autores  Data           Observações
*      1.30      elu    03/04/2019     Refeita forma de inserção na lista de inteiros
*      1.20      phs    02/04/2019     Especificação da função de inserção de valor em lista de inteiros.
*      1.10    elu/jpk  29/03/2019     Criadas funções para gerar e imprimir a costura das folhas,
*                                      além de adicionada a condição de retorno para costura vazia.
*      1.00    elu/jpk  25/03/2019     Inicializado projeto
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar árvores binárias.
*     A árvore possui uma cabeça que contém uma referência para a raiz da
*     árvore e outra para um nó corrente da árvore.
*     A cada momento o módulo admite no máximo uma única árvore.
*     Ao iniciar a execução do programa não existe árvore.
*     A árvore poderá estar vazia. Neste caso a raiz e o nó corrente
*     serão nulos, embora a cabeça esteja definida.
*     O nó corrente será nulo se e somente se a árvore estiver vazia.
*
***************************************************************************/
 
#if defined( ARVORE_OWN )
   #define ARVORE_EXT
#else
   #define ARVORE_EXT extern
#endif


/***********************************************************************
*
*  $TC Tipo de dados: ARV Condições de retorno
*
*
***********************************************************************/

   typedef enum {

         ARV_CondRetOK = 0 ,
               /* Executou correto */

         ARV_CondRetNaoCriouRaiz = 1 ,
               /* Não criou nó raiz */

         ARV_CondRetErroEstrutura = 2 ,
               /* Estrutura da árvore está errada */

         ARV_CondRetNaoEhFolha = 3 ,
               /* Não é folha relativa à direção de inserção desejada */

         ARV_CondRetArvoreNaoExiste = 4 ,
               /* árvore não existe */

         ARV_CondRetArvoreVazia = 5 ,
               /* árvore está vazia */

         ARV_CondRetNohEhRaiz = 6 ,
               /* Nó corrente é raiz */

         ARV_CondRetNaoPossuiFilho = 7 ,
               /* Nó corrente não possui filho na direção desejada */

         ARV_CondRetFaltouMemoria = 8 ,
               /* Faltou memória ao alocar dados */

         ARV_CondRetCosturaNaoExiste = 9,
               /* Costura não foi gerada */

   } ARV_tpCondRet ;


/***********************************************************************
*
*  $FC Função: ARV Criar árvore
*
*  $ED Descrição da função
*     Cria uma nova árvore vazia.
*     Caso já exista uma árvore, esta será destruída.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetFaltouMemoria
*
***********************************************************************/

   ARV_tpCondRet ARV_CriarArvore( void ) ;


/***********************************************************************
*
*  $FC Função: ARV Destruir árvore
*
*  $ED Descrição da função
*     Destrói o corpo e a cabeça da árvore, anulando a árvore corrente.
*     Faz nada caso a árvore corrente não exista.
*
***********************************************************************/

   void ARV_DestruirArvore( void ) ;


/***********************************************************************
*
*  $FC Função: ARV Adicionar filho à esquerda
*
*  $EP Parâmetros
*     $P ValorParm - valor a ser inserido no novo nó.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetErroEstrutura
*     ARV_CondRetFaltouMemoria
*     ARV_CondRetNaoEhFolha     - caso não seja folha para a esquerda
*
***********************************************************************/

   ARV_tpCondRet ARV_InserirEsquerda( char ValorParm, int a, int b ) ;


/***********************************************************************
*
*  $FC Função: ARV Adicionar filho à direita
*
*  $EP Parâmetros
*     $P ValorParm - valor a ser inserido no novo nó
*     $P a - primeiro valor da lista de inteiros
*     $P b - segundo valor da lista de inteiros
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetErroEstrutura
*     ARV_CondRetFaltouMemoria
*     ARV_CondRetNaoEhFolha     - caso não seja folha para a direita
*
***********************************************************************/

   ARV_tpCondRet ARV_InserirDireita( char ValorParm, int a, int b ) ;


/***********************************************************************
*
*  $FC Função: ARV Ir para nó pai
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetNoEhRaiz
*
***********************************************************************/

   ARV_tpCondRet ARV_IrPai( void ) ;


/***********************************************************************
*
*  $FC Função: ARV Ir para nó à esquerda
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetNaoPossuiFilho   - nó corrente não possui filho à esquerda
*
***********************************************************************/

   ARV_tpCondRet ARV_IrNoEsquerda( void ) ;


/***********************************************************************
*
*  $FC Função: ARV Ir para nó à direita
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetNaoPossuiFilho   - nó corrente não possui filho à direita
*
***********************************************************************/

   ARV_tpCondRet ARV_IrNoDireita( void ) ;


/***********************************************************************
*
*  $FC Função: ARV Obter valor corrente
*
*  $EP Parâmetros
*     $P ValorParm - É o parámetro que receberá o valor contido no nó.
*                    Este parámetro é passado por referência.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*
***********************************************************************/

   ARV_tpCondRet ARV_ObterValorCorr( char * ValorParm ) ;


/***********************************************************************
*
*  $FC Função: ARV Costurar folhas da arvore
*
*  $ED Descrição da função
*     Constroi uma costura entre as folhas da árvore em ordem alfabética
*     do valor contido no nó.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetFaltouMemoria
*
***********************************************************************/

   ARV_tpCondRet ARV_CosturarFolhas( void ) ;


/***********************************************************************
*
*  $FC Função: ARV Imprime costura das folhas da arvore
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetCosturaNaoExiste
*
***********************************************************************/

   ARV_tpCondRet ARV_ImprimeCostura( void ) ;


/***********************************************************************
*
*  $FC Função:  LST Imprime a lista de inteiros do nó corrente
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*
***********************************************************************/

   ARV_tpCondRet ARV_ImprimeLista( ) ;

#undef ARVORE_EXT

/********** Fim do módulo de definição: Módulo árvore **********/

#else
#endif
