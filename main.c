// ADC3 - Projeto Agenda Médica
//
// FEITO -->    basico+melhorar interface com usuario  
// FEITO -->    telas melhores   0,5
// FEITO -->    não marcar no mesmo horario    0,5 
// FEITO -->    possibilitar alterar valor do convenio 0,5
// FEITO -->    possibilitar inclusão/exclusão de convenios 0,5
// FEITO -->    criatividade 0,5
//
// *************************************************
// --->  aulas 04/10 11/10 
// --->  Apresentar 18/10 
// *************************************************
//
// ---------------------
// Ficha da Consulta   ]
// ------------------------------------------------------------
// Hora             Nome                  Celular             ]
//                                                            ]
// Codigo           Convenio              Valor               ]
//                                                            ]
// ------------------------------------------------------------
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, k;
int hora;
int codigo_aux;
int escolha;
char fechar;
int numero_da_ficha=1;

//STRUCT FICHA CONVENIO
struct FichaConvenio {
    int codigo_aux;
	int codigo;
	char  nome[50];
	int valor;
}; 

struct FichaConvenio convenio[20];


//STRUCT FICHA MEDICA
struct FichaMedica {
   int hora;
   char  nome[50];
   char  celular[50];
   int codigo;
   struct FichaConvenio fichaC;   
};

struct FichaMedica ficha[12];

//BANCO DE DADOS DOS CONVENIOS
void bancoDadosConvenio () {
	convenio[0].codigo = 100;
 	strcpy(convenio[0].nome, "Unimed");
 	convenio[0].valor = 30;
 	
 	convenio[1].codigo = 101;
 	strcpy(convenio[1].nome, "Porto");
 	convenio[1].valor = 40;
 	
 	convenio[2].codigo = 102;
 	strcpy(convenio[2].nome, "Particular");
 	convenio[2].valor = 400;
 	
 	convenio[3].codigo = 0;
 	strcpy(convenio[3].nome, "");
 	convenio[3].valor = 0;
}

//FUNCAO AUTOPREENCHER VALOR DOS CONVENIOS
void autopreencher(int atual){
    for (i=0; i<20; i++){
	    if (convenio[i].codigo == ficha[atual].codigo) {
		    strcpy (ficha[atual].fichaC.nome, convenio[i].nome);
		    ficha[atual].fichaC.valor = convenio[i].valor;
		    break;
	    }
    }	
}  

//FUNCAO VISUALIZAR FICHAS MEDICAS
void visualizar() {
    printf("===========================================================================\n");
    printf("Hora  | Nome                       | Celular           | Código | Convênio       | Valor\n");
    printf("===========================================================================\n");

    for (k = 0; k < 12; k++) {
        // Verificar se a hora é maior que zero para evitar exibir horas não preenchidas
        if (ficha[k].hora > 0) {
            printf("%-5i | %-26s | %-17s | %-6i | %-14s | %i\n",
                   ficha[k].hora, ficha[k].nome, ficha[k].celular, ficha[k].codigo,
                   ficha[k].fichaC.nome, ficha[k].fichaC.valor);
        }
    }

    printf("===========================================================================\n");

}

//FUNCAO VISUALIZAR FICHAS DOS CONVENIOS
void visualizar_convenio() {
    printf("============================================\n");
    printf("Codigo  | Nome                       | Valor\n");
    printf("============================================\n");

    for (k = 0; k < 20; k++) {

        if (convenio[k].codigo > 0) {
            printf("%-7i | %-26s | %-5i\n", convenio[k].codigo, convenio[k].nome, convenio[k].valor);
        }
    }

    printf("============================================\n");

}

int main() {
    //IMPORTA O BANCO DE DADOS DOS CONVENIOS
    bancoDadosConvenio ();
    
    //CRIA LOOP PARA EXECUÇÃO DO PROGRAMA A PARTIR DE UM MENU PRINCIPAL
    do {
    	system ("clear");
        printf("MENU\n");
        printf("1. Visualizar fichas medicas\n");
        printf("2. Incluir fichas medicas\n");
        printf("3. Apagar fichas medicas\n");
        printf("4. Alterar fichas medicas\n");
        printf("5. Visualizar convenios\n");
        printf("6. Incluir convenios\n");
        printf("7. Apagar convenios\n");
        printf("8. Alterar convenios\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        
        scanf("%d", &escolha);
        system ("clear");

        //DEFINE O QUE CADA OPÇÃO ESCOLHIDA NO MENU PRINCIPAL FAZ
        switch (escolha) {
            case 1:
                printf("Você escolheu VISUALIZAR FICHAS MEDICAS.\n");
                
                visualizar ();
				printf("Tecle algo para voltar");
				scanf("%c%c", &fechar, &fechar);

				break;
            case 2:
                printf("Você escolheu INCLUIR FICHAS MEDICAS.\n");

                visualizar ();
                
                while (hora<6||hora>18){
                    
                    printf("\nDigite a hora da consulta (formato 24H entre 6h e 18h) sem repetir os horarios ja marcados na lista acima: ");
                    scanf("%i", &hora);
                    for (k=0;k<12;k++){
                        if (hora==ficha[k].hora){
                            printf("\nHorario indisponivel, digite um horario valido\n");
                            hora=0;
                            break;
                        }
                    }
                }
                
                ficha[hora-6].hora= hora;
                
				printf("\nDigite seu nome: ");
				scanf("%s", &ficha[hora-6].nome);
				
				printf("\nDigite seu celular: ");
				scanf("%s", &ficha[hora-6].celular);
				
				printf("\nDigite seu codigo do convenio: ");
				scanf("%i", &ficha[hora-6].codigo);
				
                autopreencher(hora-6);
                hora=0;
                break;
            case 3:
                printf("Você escolheu APAGAR FICHAS MEDICAS.\n");

                visualizar ();
                printf("Digite o horario que deseja apagar:  ");
                scanf("%i", &hora);
        
                ficha[hora-6].hora = 0;
                strcpy (ficha[hora-6].nome, "");
                strcpy (ficha[hora-6].celular, "");
                ficha[hora-6].codigo = 0;
                autopreencher(hora-6);
                hora=0;
                break;
            case 4:
                printf("Você escolheu ALTERAR FICHAS MEDICAS.\n");
                // Coloque o código para ALTERAR aqui. 
                visualizar ();
                printf("Digite o horario que deseja alterar:  ");
                scanf("%i", &hora);
        
                ficha[hora-6].hora = 0;
                hora=0;
                
                while (hora<6||hora>18){
                    
                    printf("\nDigite o novo horario da consulta (formato 24H entre 6h e 18h) sem repetir os horarios ja marcados na lista acima: ");
                    scanf("%i", &hora);
                    for (k=0;k<12;k++){
                        if (hora==ficha[k].hora){
                            printf("\nHorario indisponivel, digite um horario valido\n");
                            hora=0;
                            break;
                        }
                    }
                }
                
                ficha[hora-6].hora= hora;
                
				printf("\nDigite seu nome: ");
				scanf("%s", &ficha[hora-6].nome);
				
				printf("\nDigite seu celular: ");
				scanf("%s", &ficha[hora-6].celular);
				
				printf("\nDigite seu codigo do convenio: ");
				scanf("%i", &ficha[hora-6].codigo);
				
                autopreencher(hora-6);
                hora=0;
                break;
            case 5:
                printf("Você escolheu VISUALIZAR CONVENIOS.\n");
                // Coloque o código para VISUALIZAR CONVENIO aqui.
                visualizar_convenio();
				printf("Tecle algo para voltar");
				scanf("%c%c", &fechar, &fechar);

				break;
			case 6:
                printf("Você escolheu INCLUIR CONVENIOS\n");
                // Coloque o código para INCLUIR CONVENIO aqui
                
                visualizar_convenio();
                
                while (codigo_aux<103||codigo_aux>120){
                    
                    printf("\nDigite o codigo do novo convenio (numero de 103 ate 119): ");
                    scanf("%i", &codigo_aux);
                    for (k=0;k<20;k++){
                        if (codigo_aux==convenio[k].codigo){
                            printf("\nCodigo indisponivel, digite outro valido\n");
                            codigo_aux=0;
                            break;
                        }
                    }
                }
                
                convenio[codigo_aux-100].codigo= codigo_aux;
                
				printf("\nDigite o nome do convenio: ");
				scanf("%s", &convenio[codigo_aux-100].nome);
				
				printf("\nDigite o valor para esse convenio: ");
				scanf("%i", &convenio[codigo_aux-100].valor);
			
                codigo_aux=0;
                break;
            case 7:
                printf("Você escolheu APAGAR CONVENIOS.\n");
                // Coloque o código para APAGAR CONVENIO aqui.
                
                visualizar_convenio();
                printf("Digite o codigo do convenio que deseja apagar: ");
                scanf("%i", &codigo_aux);
                convenio[codigo_aux-100].codigo= 0;
                strcpy (convenio[codigo_aux-100].nome, "");
                convenio[codigo_aux-100].valor= 0;
                codigo_aux=0;
                break;
            case 8:
                printf("Você escolheu ALTERAR CONVENIOS.\n");
                // Coloque o código para ALTERAR CONVENIO aqui. 
                
                visualizar_convenio();
                printf("Digite o codigo do convenio que deseja alterar: ");
                scanf("%i", &codigo_aux);
        
                convenio[codigo_aux-100].codigo= 0;
                codigo_aux=0;
                
                while (codigo_aux<100||codigo_aux>120){
                    
                    printf("\nDigite o codigo do convenio (numero de 100 ate 119): ");
                    scanf("%i", &codigo_aux);
                    for (k=0;k<20;k++){
                        if (codigo_aux==convenio[k].codigo){
                            printf("\nCodigo indisponivel, digite outro valido\n");
                            codigo_aux=0;
                            break;
                        }
                    }
                }
                
                convenio[codigo_aux-100].codigo= codigo_aux;
                
				printf("\nDigite o nome do convenio: ");
				scanf("%s", &convenio[codigo_aux-100].nome);
				
				printf("\nDigite o valor para esse convenio: ");
				scanf("%i", &convenio[codigo_aux-100].valor);
			
                codigo_aux=0;
                break;
            case 9:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
        
    } while (escolha != 9);

   return 0;
}


