#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct pedido
{
    char namePed[200];
    char numPed[200];
    char qtdPed[200];
    char valorped[200];
    int cod;
}logP[200];

struct cadastro
{
  
    char nome[200];
    char data[200];
    int vazio,cod;
    struct pedido clientePed;
   
}log[200];
//AQUI DECLARO AS FUNÇÕES A SEREM USADAS
int verifica_pos(void);
int verifica_cod( int cod );
int opt;
void cadastroP(int cod,int pos);
void list();
void cadastroPedido();
void consultaCod (void);
void excluirCliente (void);

int main(void){ //INICIO DO MAIN
    printf("*******RESTAURANTE DO BANANIL*******");
    int i,Opcao,OpcaoCliente,posicao,retorno;
    int codaux;
    do
    {
        printf("1 - Cadastrar Novo Cliente\n");
        printf("4 - Excluir Cliente\n");
        printf("5 - Cadastrar Pedido\n");
        printf("6 - Alterar Pedido\n");
        printf("7 - Excluir Pedido\n");
        printf("8 - Sair\n");
        printf(" Selecione uma opcao por favor: ");
        scanf("%d", &Opcao);
        getchar();
        if (Opcao == 1)
        {
            printf("Voce selecionou a opcao 1 - Cadastrar Novo Cliente\n");
            posicao=verifica_pos();

                if ( posicao != -1 )
                {

                    printf("\nEntre com um codigo de 1 a 200 para seu cadastro: \n");
                    scanf("%d",&codaux);fflush(stdin);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastroP( codaux, posicao );
                    else{
                        printf("\nCodigo ja existente ou invalido pressione enter para voltar ao menu principal\n");
                        getchar();
                        printf("\033[H\033[J");
                        main();
                    }

                }
                else
                    printf("\nNao e possivel realizar mais cadastros!\n");

                break;
 
        }
     
    }while(OpcaoCliente =!3 || OpcaoCliente > 3 || OpcaoCliente < 0 || OpcaoCliente == 0);
        }
        
        else if (Opcao == 4)
        {
            printf("Voce selecionou a opcao 4 - Excluir Cliente\n");
            excluirCliente();
        }
        else if (Opcao == 5)
        {
            printf("Voce selecionou a opcao 5 - Cadastrar Pedido\n");
            cadastroPedido();
        }
        else if (Opcao == 6)
        {
            printf("Voce selecionou a opcao 6 - Alterar Pedido\n");
        }
        else if (Opcao == 7)
        {
            printf("Voce selecionou a opcao 7 - Excluir Pedido\n");
        }
        else if (Opcao == 8)
        {
            printf("Voce selecionou a opcao 8 - Sair\n");
        }
        else{
            printf("Opcao invalida, favor pressione enter para voltar ao menu principal");
            getchar();
           printf("\033[H\033[J");
        }
        }    while (Opcao != 8 || Opcao < 8);

} // FIM DO MAIN
void list(){ // Lista os usuarios cadastrados.
    int i,j;  
    for(i=0;i<200;i++){
        if(log[i].cod!=NULL){
            printf("\nCodigo: %d \nNome: \n\n", log[i].cod,log[i].nome,log[i]);
    }
}
    printf("Pressione enter para volta ao menu principal");
    getchar();
    printf("\033[H\033[J");

} //FIM DO LIST
void cadastroP(int cod, int pos){ //Cadastro das pessoas
    int i;
    do{
    pos = verifica_pos();
    log[pos].cod = cod;
        printf("\nDigite seu nome: ");
        gets(log[pos].nome);
        log[pos].vazio = 1;
        printf("\nDigite enter para efetuar novo cadastro ou qualquer outra tecla para voltar ao menu principal");
        scanf("%d", &opt);
        opt ==1;
        getchar();  
    }while(opt==1);
   printf("\033[H\033[J");
    main();

} // FIM DO CADASTRO DE PESSOAS
int verifica_pos( void ) //VERIFICADOR DA POSIÇÃO
{
    int cont = 0;

    while ( cont <= 200 )
    {

        if ( log[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

} // FIM DO VERIFICADOR
int verifica_cod( int cod ) // VERIFICADOR DE CÓDIGO
{
    int cont = 0;

    while ( cont <= 200 )
    {
        if ( log[cont].cod == cod )
            return(0);

        cont++;
    }

    return(1);

} // FIM DO VERIFICADOR
void cadastroPedido(){ //Cadastro dos pedidos
    printf("\033[H\033[J");;    
    int i;
    int Option;
    int mesa;
    int OpcaoPedido;
    char nomeCad[200];
    printf("\nDigite seu nome como esta no cadastro: ");
    gets(nomeCad);
    for(i=0;i<200;i++){
            if(strcmp(log[i].nome, nomeCad)==0){
                do{
                printf("\nEscolha o seu pedido: "); //PEDIDOS MERAMENTE ILUSTRATIVOS, COLOQUEI SÓ PARA VER SE CONSEGUIA ANEXAR A 1 CADATRO MAS NÃO CONSEGUI.
                printf("\n1- Sanduba esperto");
                printf("\n2- Salada");
                printf("\n3- Raviolli\n:");
                scanf("%d", &OpcaoPedido);
                if(OpcaoPedido == 1){
                    strcpy(log[i].clientePed.namePed, "Sanduba esperto");
                    printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.",log[i].clientePed.namePed);
                    printf("\nPressione 1 para continuar pedindo ou 2 para voltar ao menu principal: ");
                    scanf("%d", &Option);
                    i++;}
                }
                else if(OpcaoPedido == 2){
                    strcpy(log[i].clientePed.namePed, "Salada");
                    printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", log[i].clientePed.namePed);
                    printf("\nPressione 1 para continuar pedindo ou 2 para voltar ao menu principal: ");
                    scanf("%d", &Option);
                    i++;
                   }
                   else if(OpcaoPedido == 3){
                    strcpy(log[i].clientePed.namePed, "Raviolli");
                    printf("\nVoce escolheu %s, seu pedido foi adicionado ao seu cadastro.", log[i].clientePed.namePed);
                    printf("\nPressione 1 para continuar pedindo ou 2 para voltar ao menu principal: ");
                    scanf("%d", &Option);
                    i++;
                }
    }
        
        struct filaElementos
{
 int comeco, fim;
 int elementos[m];
};

void iniciarFila(struct filaElementos *fila)
{
fila->comeco = 0;
fila->fim = -1;
}

void inserir(struct filaElementos *fila, int d)
    if(fila->fim == m - 1)
    printf("Fila está lotada, aguarde... \n");
else
{
    fila->fim++;
    fila->elementos[fila->fim] = x;
}
}
void consultar(struct filaElementos *fila)
{
int i = 0;
    if(fila->fim < fila->comeco)
    printf("fila Vazia \n");
else
{
while(i < m)
{
    printf(" Listando todos os pedidos  = %d \n", fila->elementos[i]);
i++;
}
}
}

void consultarComecoFila(struct filaElementos *fila)
{
int i = 0;
printf("O primeiro pedido em fila : %d \n", fila->elementos[fila->comeco]);
}

void remover(struct filaElementos *fila){
    if(fila->fim < fila->comeco)
    printf("fila Vazia\n");
else
fila->comeco++;
}
void esvaziar(struct filaElementos *fila){
    if(fila->fim < fila->comeco)
    printf("fila Vazia\n");
else
{
int i;
for (i = 0; i < m; ++i)
{
fila->fim--;
}
}
}
int main()
{
int i;
struct filaElementos fila;
int x;
iniciarFila(&fila);
for(i = 0; i < m; i++)
{
        printf("Informe o código da opção desejada = \n");
        scanf("%d", &x);
        inserir(&fila, x);
}
    remover(&fila);
    consultar(&fila);
    esvaziar(&fila);
    consultar(&fila);
    consultarComecoFila(&fila);
return 0;
}
   
   

   
}
}
} // FIM DO CADASTRO DE PEDIDOS.
void consultaCod (void) // CONSULTAR 1 CADASTRADO QUALQUER VIA CÓDIGO DADO POR USUÁRIO.
{
    int cont = 0, cod;

    printf("\nEntre com o codigo\n");
    scanf("%d",&cod);
    fflush(stdin);
   printf("\033[H\033[J");

    while ( cont <= 200 )
    {

        if (log[cont].cod==cod)
        {
            if (log[cont].vazio==1)
            {
               
                printf("\nCodigo: %d \nNome: \n\n", log[cont].cod,log[cont].nome,log[cont]);
               

                system ("pause");

              printf("\033[H\033[J");

                break;

            }
        }

        cont++;

        if ( cont > 200 ){
            printf("\nCodigo nao encontrado, pressione enter para voltar ao menu principal\n");
            getchar();
            printf("\033[H\033[J");
        }

    }
} // FIM DA FUNÇÃO CONSULTAR
void excluirCliente(void)  // EXCLUI CLIENTE
{
    int cod, cont = 0;
    char resp;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    scanf("%d", &cod );

    while ( cont <= 200 )
    {

        if ( log[cont].cod == cod )
        {

            if (log[cont].vazio == 1 )
            {
                printf("\nCodigo: %d \nNome: \n\n", log[cont].cod,log[cont].nome,log[cont]);
                getchar();
                printf("\nDeseja realmente exlucir? s/n: ");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    log[cont].vazio=0;
                    log[cont].cod = NULL;
                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 200 )
            printf("\nCodigo nao encontrado\n");

    }

    system("pause");
   printf("\033[H\033[J");

}
