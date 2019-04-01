/***************************************************************************
*  $MCI Módulo de implementação: Módulo árvore
*
*  Arquivo gerado:              ARVORE.C
*  Letras identificadoras:      ARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: elu - Emanuel Lima Umbelino, jpk - João Pedro Kalil 
*
*  $HA Histórico de evolução:
*		Versão		Autores		   Data			Observações
*		 1.25		elu/jpk		28/03/2019		Criadas função para imprimir a costura das folhas.
*		 1.20		elu/jpk		28/03/2019		Criadas funções para ordenar a costura e a auxiliar para 
*												trocar nó de posição com o próximo da costura.
*		 1.10		elu/jpk		28/03/2019		Criadas funções para pegar folha mais à esquerda e para
*												costurar folhas numa lista.
*		 1.01		elu/jpk		25/03/2019		Colocado Ponteiro para Costura nos nós da Árvore
*		 1.00		elu/jpk		25/03/2019		Inicializado projeto
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>

#define ARVORE_OWN
#include "ARVORE.H"
#include "LISTA.H"
#undef ARVORE_OWN


/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor do nó da árvore
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/

   typedef struct tgNoArvore {

         struct tgNoArvore * pNoPai ;
               /* Ponteiro para pai
               *
               *$EED Assertivas estruturais
               *   É NULL sse o nó é raiz
               *   Se não for raiz, um de pNoEsq ou pNoDir de pNoPai do nó
               *   corrente apontam para o nó corrente */

         struct tgNoArvore * pNoEsq ;
               /* Ponteiro para filho à esquerda
               *
               *$EED Assertivas estruturais
               *   se pNoEsq do nó X != NULL então pNoPai de pNoEsq aponta para o nó X */

         struct tgNoArvore * pNoDir ;
               /* Ponteiro para filho à direita
               *
               *$EED Assertivas estruturais
               *   se pNoDir do nó X != NULL então pNoPai de pNoDir aponta para o nó X */

         char valor ;
               /* Valor do nó */

         LST * listaDeInteiros;
				/* Ponteiro para a lista encadeada de inteiros que cada nó terá*/

		 struct tgNoArvore * pNoCostura ;
				/* Ponteiro para próximo nó da costura */

   } tpNoArvore ;

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor da cabeça de uma árvore
*
*
*  $ED Descrição do tipo
*     A cabeça da árvore é o ponto de acesso para uma determinada árvore.
*     Por intermédio da referência para o nó corrente e do ponteiro
*     pai pode-se navegar a árvore sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a árvore em forma de co-rotina.
*
***********************************************************************/

   typedef struct tgArvore {

         tpNoArvore * pNoRaiz ;
               /* Ponteiro para a raiz da árvore */

         tpNoArvore * pNoCorr ;
               /* Ponteiro para o nó corrente da árvore */

         tpNoArvore * pNoCostura ;
               /* Ponteiro para o início da lista costura */

   } tpArvore ;

/*****  Dados encapsulados no módulo  *****/

      static tpArvore * pArvore = NULL ;
            /* Ponteiro para a cabeça da árvore */

/***** Protótipos das funções encapuladas no módulo *****/

   static tpNoArvore * CriarNo( char ValorParm ) ;

   static ARV_tpCondRet CriarNoRaiz( char ValorParm ) ;

   static void DestroiArvore( tpNoArvore * pNo ) ;

   static void CosturarFolhasAux( tpNoArvore * pNo , tpNoArvore ** ref) ;

   static tpNoArvore * PegaFolhaEsquerda( void ) ;

   static tpNoArvore * PegaFolhaEsquerdaAux( tpNoArvore * pNo ) ;

   static void OrdenaCostura( void ) ;

   static tpNoArvore * Troca( tpNoArvore * pNo ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: ARV Criar árvore
*  ****/

   ARV_tpCondRet ARV_CriarArvore( void )
   {

      if ( pArvore != NULL )
      {
         ARV_DestruirArvore( ) ;
      } /* if */

      pArvore = ( tpArvore * ) malloc( sizeof( tpArvore )) ;
      if ( pArvore == NULL )
      {
         return ARV_CondRetFaltouMemoria ;
      } /* if */

      pArvore->pNoRaiz = NULL ;
      pArvore->pNoCorr = NULL ;

      return ARV_CondRetOK ;

   } /* Fim função: ARV Criar árvore */

/***************************************************************************
*
*  Função: ARV Destruir árvore
*  ****/

   void ARV_DestruirArvore( void )
   {

      if ( pArvore != NULL )
      {
         if ( pArvore->pNoRaiz != NULL )
         {
            DestroiArvore( pArvore->pNoRaiz ) ;
         } /* if */
         free( pArvore ) ;
         pArvore = NULL ;
      } /* if */

   } /* Fim função: ARV Destruir árvore */

/***************************************************************************
*
*  Função: ARV Adicionar filho à esquerda
*  ****/

   ARV_tpCondRet ARV_InserirEsquerda( char ValorParm )
   {

      ARV_tpCondRet CondRet ;

      tpNoArvore * pCorr ;
      tpNoArvore * pNo ;

      /* Tratar vazio, esquerda */

         CondRet = CriarNoRaiz( ValorParm ) ;
         if ( CondRet != ARV_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar nó à esquerda de folha */

         pCorr = pArvore->pNoCorr ;
         if ( pCorr == NULL )
         {
            return ARV_CondRetErroEstrutura ;
         } /* if */
               
         if ( pCorr->pNoEsq == NULL )
         {
            pNo = CriarNo( ValorParm ) ;
            if ( pNo == NULL )
            {
               return ARV_CondRetFaltouMemoria ;
            } /* if */
            pNo->pNoPai      = pCorr ;
            pCorr->pNoEsq    = pNo ;
            pArvore->pNoCorr = pNo ;

            return ARV_CondRetOK ;
         } /* if */

      /* Tratar nóo folha à esquerda */

         return ARV_CondRetNaoEhFolha ;

   } /* Fim função: ARV Adicionar filho à esquerda */

/***************************************************************************
*
*  Função: ARV Adicionar filho à direita
*  ****/

   ARV_tpCondRet ARV_InserirDireita( char ValorParm )
   {

      ARV_tpCondRet CondRet ;

      tpNoArvore * pCorr ;
      tpNoArvore * pNo ;

      /* Tratar vazio, direita */

         CondRet = CriarNoRaiz( ValorParm ) ;
         if ( CondRet != ARV_CondRetNaoCriouRaiz )
         {
            return CondRet ;
         } /* if */

      /* Criar nó à direita de folha */

         pCorr = pArvore->pNoCorr ;
         if ( pCorr == NULL )
         {
            return ARV_CondRetErroEstrutura ;
         } /* if */

         if ( pCorr->pNoDir == NULL )
         {
            pNo = CriarNo( ValorParm ) ;
            if ( pNo == NULL )
            {
               return ARV_CondRetFaltouMemoria ;
            } /* if */
            pNo->pNoPai      = pCorr ;
            pCorr->pNoDir    = pNo ;
            pArvore->pNoCorr = pNo ;

            return ARV_CondRetOK ;
         } /* if */

      /* Tratar nóo folha à direita */

         return ARV_CondRetNaoEhFolha ;

   } /* Fim função: ARV Adicionar filho à direita */

/***************************************************************************
*
*  Função: ARV Ir para nó pai
*  ****/

   ARV_tpCondRet ARV_IrPai( void )
   {

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */

      if ( pArvore->pNoCorr->pNoPai != NULL )
      {
         pArvore->pNoCorr = pArvore->pNoCorr->pNoPai ;
         return ARV_CondRetOK ;
      } else {
         return ARV_CondRetNohEhRaiz ;
      } /* if */

   } /* Fim função: ARV Ir para nó pai */

/***************************************************************************
*
*  Função: ARV Ir para nó à esquerda
*  ****/

   ARV_tpCondRet ARV_IrNoEsquerda( void )
   {

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */

      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */

      if ( pArvore->pNoCorr->pNoEsq == NULL )
      {
         return ARV_CondRetNaoPossuiFilho ;
      } /* if */

      pArvore->pNoCorr = pArvore->pNoCorr->pNoEsq ;
      return ARV_CondRetOK ;

   } /* Fim função: ARV Ir para nó à esquerda */

/***************************************************************************
*
*  Função: ARV Ir para nó à direita
*  ****/

   ARV_tpCondRet ARV_IrNoDireita( void )
   {

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */

      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */

      if ( pArvore->pNoCorr->pNoDir == NULL )
      {
         return ARV_CondRetNaoPossuiFilho ;
      } /* if */

      pArvore->pNoCorr = pArvore->pNoCorr->pNoDir ;
      return ARV_CondRetOK ;

   } /* Fim função: ARV Ir para nó à direita */

/***************************************************************************
*
*  Função: ARV Obter valor corrente
*  ****/

   ARV_tpCondRet ARV_ObterValorCorr( char * ValorParm )
   {

      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pArvore->pNoCorr == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */
      * ValorParm = pArvore->pNoCorr->valor ;

      return ARV_CondRetOK ;

   } /* Fim função: ARV Obter valor corrente */


/***********************************************************************
*
*  $FC Função: ARV Imprime costura das folhas
*  ****/
   ARV_tpCondRet ARV_ImprimeCostura( void )
   {
	  tpNoArvore * pNo ;
      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pArvore->pNoCostura == NULL )
      {
         return ARV_CondRetCosturaNaoExiste ;
      } /* if */

       pNo = pArvore->pNoCostura ;

	   while ( pNo != NULL )
	   {
		   printf("%c -> ", pNo->valor) ;
		   pNo = pNo->pNoCostura ;
	   } /* while */

	   printf("NULL\n") ;

      return ARV_CondRetOK ;

   } /* Fim função: ARV Imprime costura das folhas */


/***********************************************************************
*
*  $FC Função: ARV Costurar folhas da árvore
*  ****/
   ARV_tpCondRet ARV_CosturarFolhas( void )
   {
	   tpNoArvore **ref;
      if ( pArvore == NULL )
      {
         return ARV_CondRetArvoreNaoExiste ;
      } /* if */
      if ( pArvore->pNoRaiz == NULL )
      {
         return ARV_CondRetArvoreVazia ;
      } /* if */
	  ref = (tpNoArvore **)malloc(sizeof(tpNoArvore*));
	  *ref = NULL;
      CosturarFolhasAux( pArvore->pNoRaiz , ref ) ;
      pArvore->pNoCostura = PegaFolhaEsquerda() ;
      OrdenaCostura() ;
      return ARV_CondRetOK ;

   }


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: ARV Criar nó da árvore
*
*  $FV Valor retornado
*     Ponteiro para o nó criado.
*     Será NULL caso a memória tenha se esgotado.
*     Os ponteiros do nó criado estarão nulos e o valor é igual ao do
*     parámetro.
*
***********************************************************************/

   tpNoArvore * CriarNo( char ValorParm )
   {

      tpNoArvore * pNo ;

      pNo = ( tpNoArvore * ) malloc( sizeof( tpNoArvore )) ;
      if ( pNo == NULL )
      {
         return NULL ;
      } /* if */

      pNo->pNoPai = NULL ;
      pNo->pNoEsq = NULL ;
      pNo->pNoDir = NULL ;
      pNo->valor  = ValorParm ;
      return pNo ;

   } /* Fim função: ARV Criar nó da árvore */


/***********************************************************************
*
*  $FC Função: ARV Criar nó raiz da árvore
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetFaltouMemoria
*     ARV_CondRetNaoCriouRaiz
*
***********************************************************************/

   ARV_tpCondRet CriarNoRaiz( char ValorParm )
   {

      ARV_tpCondRet CondRet ;
      tpNoArvore * pNo ;

      if ( pArvore == NULL )
      {
         CondRet = ARV_CriarArvore( ) ;

         if ( CondRet != ARV_CondRetOK )
         {
            return CondRet ;
         } /* if */
      } /* if */

      if ( pArvore->pNoRaiz == NULL )
      {
         pNo = CriarNo( ValorParm ) ;
         if ( pNo == NULL )
         {
            return ARV_CondRetFaltouMemoria ;
         } /* if */
         pArvore->pNoRaiz = pNo ;
         pArvore->pNoCorr = pNo ;

         return ARV_CondRetOK ;
      } /* if */

      return ARV_CondRetNaoCriouRaiz ;

   } /* Fim função: ARV Criar nó raiz da árvore */


/***********************************************************************
*
*  $FC Função: ARV Destruir a estrutura da árvore
*
*  $EAE Assertivas de entradas esperadas
*     pNoArvore != NULL
*
***********************************************************************/

   void DestroiArvore( tpNoArvore * pNo )
   {

      if ( pNo->pNoEsq != NULL )
      {
         DestroiArvore( pNo->pNoEsq ) ;
      } /* if */

      if ( pNo->pNoDir != NULL )
      {
         DestroiArvore( pNo->pNoDir ) ;
      } /* if */

      free( pNo ) ;

   } /* Fim função: ARV Destruir a estrutura da árvore */


/***********************************************************************
*
*  $FC Função: ARV Costurar folhas da árvore
*
***********************************************************************/

   void CosturarFolhasAux( tpNoArvore * pNo , tpNoArvore ** ref)
   {
      if ( pNo == NULL ) return ;
      CosturarFolhasAux( pNo->pNoDir, ref ) ;
      
      if ( pNo->pNoEsq == NULL && pNo->pNoDir == NULL )
      {
         if ( *ref == NULL )
         {
            pNo->pNoCostura = NULL ;
            *ref = pNo ;
            return ;
         } /* if */
         else
         {
            pNo->pNoCostura = *ref ;
            *ref = pNo ;
            return ;
         } /* else */
      }/* if */

      CosturarFolhasAux( pNo->pNoEsq, ref ) ;

   } /* Fim função: ARV Costurar folhas da árvore */


/***********************************************************************
*
*  $FC Função: ARV Pega folha mais a esquerda da árvore
*
***********************************************************************/
   tpNoArvore * PegaFolhaEsquerda( void )
   {
      return PegaFolhaEsquerdaAux( pArvore->pNoRaiz ) ;
   }

   tpNoArvore * PegaFolhaEsquerdaAux( tpNoArvore * pNo ) 
   {
      if ( pNo->pNoEsq == NULL && pNo->pNoDir == NULL )
      {
         return pNo ;
      } /* if */
      else if (pNo->pNoEsq != NULL)
      {
         return PegaFolhaEsquerdaAux( pNo->pNoEsq ) ;
      } /* else if */
      return PegaFolhaEsquerdaAux( pNo->pNoDir ) ;

   } /* Fim função: ARV Pega folha mais a esquerda da árvore */


/***********************************************************************
*
*  $FC Função: ARV Ordena a lista costura pelo valor do nó
*
***********************************************************************/
   void OrdenaCostura( void )
   {
      int tam, i, troca ;
      tpNoArvore * ant ;
      tpNoArvore * atual = pArvore->pNoCostura ;

	   for ( tam = 0; atual != NULL; tam ++, atual = atual->pNoCostura ) ;

      do
      {
         atual = pArvore->pNoCostura ;
         ant = NULL ;
         troca = 0 ;
         for ( i = 0; i < tam-1; i++ )
         {
            if ( atual != NULL )
            {
               if ( atual->valor > atual->pNoCostura->valor )
               {
                  troca++ ;
                  if ( ant == NULL )
                  {
                     pArvore->pNoCostura = Troca(atual) ;
                     ant = pArvore->pNoCostura ;
                     atual = ant->pNoCostura ;
                  } /* if */
                  else
                  {
                     ant->pNoCostura = Troca(atual) ;
                     ant = ant->pNoCostura ;
                     atual = ant->pNoCostura ;
                  } /* else */
               } /* if */
               else 
               {
                  ant = atual ;
               } /* else */
               atual = ant->pNoCostura ;
            } /* if */
         } /* for */
         tam-- ;
      } while ( troca != 0 && tam > 1 ) ;

   } /* Fim função: ARV Ordena a lista costura pelo valor do nó */


/***********************************************************************
*
*  $FC Função: ARV Troca nó de posição com o próximo da lista e retorna o ponteiro para posição atual
*
*  $EAE Assertivas de entradas esperadas
*     pNo != NULL
*
***********************************************************************/
   tpNoArvore * Troca( tpNoArvore * pNo )
   {
      tpNoArvore * aux;
      if ( pNo->pNoCostura != NULL )
      {
         aux = pNo->pNoCostura ;
         pNo->pNoCostura = pNo->pNoCostura->pNoCostura ;
         aux->pNoCostura = pNo ;
         return aux ;
      } /* if */

      return pNo ;
   } /* Fim função: ARV Troca nó de posição */


/********** Fim do módulo de implementação: Módulo árvore **********/

