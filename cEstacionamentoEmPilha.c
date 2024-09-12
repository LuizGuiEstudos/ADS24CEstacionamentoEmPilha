/******************************************************************************

                            ATIVIDADE AVALIATIVA
                              ADS 24, SENAC-PR
                  ESTACIONAMENTO EM PILHA(POR ALGUM BOM MOTIVO)
                          
                          versão: 1.0
                          desc: provalvelmente versao final
                          autor: Luiz Guilherme Gimenes Medina da Silva
                          auxiliares: cachorro, papagaio, periquito

*******************************************************************************/

#define TAMANHO 10

#include <stdio.h>
#include <stdlib.h>


typedef struct pilha {
    int fim;
    int ids[TAMANHO];
} TPilha;

TPilha pCarros;
TPilha pAuxiliar;

int pilhaTamanho( TPilha *p ) 
{
    return p->fim;
}


void pilhaInsere( TPilha *p, int el ) //INSERE
{
    p->ids[p->fim] = el;
    p->fim++;
}
void pilhaInsereCarros( int el ) {
    pilhaInsere( &pCarros, el );
}
void pilhaInsereAuxiliar( int el ) {
    pilhaInsere( &pAuxiliar, el );
}

int pilhaRemove(  TPilha *p ) //REMOVE
{
    int el = p->ids[p->fim - 1];
    p->fim--;
    return el;
}
int pilhaRemoveCarros( ){ 
    return pilhaRemove(&pCarros);
}
int pilhaRemoveAuxiliar( ) {
    return pilhaRemove(&pAuxiliar);
}



void printPilha( TPilha *p ) //PRINT
{
    int i;
    printf("\n");
    for( i = p->fim -1; i>= 0; i-- ) {
        printf( "| %d | \n", p->ids[i] );
    }
}
void printPCarros(){ 
    printf( "\n\n" );
    printf( " PRINTANDO LISTA DE CARROS ALOCADOS " );
    printPilha( &pCarros );    
}
void printPAuxiliar(){
    printf( "\n\n" );
    printf( " PRINTANDO LISTA DE DESALOCAÇÃO " );
    printPilha( &pAuxiliar );
}
//TRIGGERS
  //MOVIMENTACAO

void movimentacaoRemoveEDesalocaOsAnteriores() 
{
    //REMOVE E DESALOCA
    int elToRem;
    printf("-Digite ID do carro a ser REMOVIDO: \n");
    scanf( "%d", &elToRem );
    
    int i;
    for( i=TAMANHO; i>=0; i-- ){
        int elToAuxiliar;
        elToAuxiliar = pilhaRemoveCarros();
        
        if( elToAuxiliar == elToRem  ) {
            return;
        }
        pilhaInsereAuxiliar( elToAuxiliar );
        
    }
}
void movimentacaoRealocaOsAnteriores()
{
    //REALOCA CARROS
    int i;
    for( i=pAuxiliar.fim -1; i>=0; i-- ){
        int el;
        int removido;
        el = pAuxiliar.ids[ i ];
        removido = pilhaRemoveAuxiliar( el );
        pilhaInsereCarros( removido );        
    }   
}
void movimentacaoCompleta()
{
    movimentacaoRemoveEDesalocaOsAnteriores();
    
    printPAuxiliar();
    
    movimentacaoRealocaOsAnteriores();
    printf( ">Carro removido, demais realocados" );
    printPCarros();
    
}
//ENTRADAS
int entradaCarro() 
{
    int in;
    printf( "-Digite ID do carro a ser INSERIDO: \n" );
    scanf( "%d", &in );
    return in;
}


int main()
{
    printf( " #### GERENCIAMENTO DE ESTACIONAMENTO BUGADO DO PROF. NOEL #### \n\n" );
    int acao = -1;
    while( acao!=0 ){
        printf( "\n-Escolha uma acao. 1-Inserir Carro, 2-Ver carros alocados, 3-Remocao e movimentacao, 0-Sair: \n " );
        scanf( "%d", &acao );
        switch( acao ) {
            case 0:
                printf( ">Saindo do programa..." );
                break;
            case 1:
                pilhaInsereCarros( entradaCarro() );
                break; 
            case 2:
                printPCarros();
                break;
            case 3:
                movimentacaoCompleta();
                break;
            default:
                printf(">Opcao invalida! /n");
        }
        
        
    };
    
    
    return 0;
}