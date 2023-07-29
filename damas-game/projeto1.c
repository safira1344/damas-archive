#include <stdio.h>
#include <stdlib.h>
#include "gconio.h"
#include <locale.h>
#include <ctype.h>
#define SEGUNDOS 1
#define MINUTOS 2
#define HORAS 3
#define DIAS 4


void tela(){

    int linha, coluna=0;
    textbackground(BLUE);
    gotoxy(20,0);   //Vai pra coluna 20, linha 0
    while(coluna<72){  //Vai de 0 até 72 desenhando as colunas da direita pra esquerda
        printf("=");
        coluna++;
    }
    coluna = 0;
    for (linha = 1; linha<23; linha++){ //Vai da linha 1 até 22, descendo (a partir da coluna 20)
        gotoxy(20,linha);
        printf("||                                                                    ||");

    }
    gotoxy(20,linha); //Desce até a última linha desenhada
    for(;coluna<72; coluna++){
        printf("=");    //Desenha as colunas da direita pra esquerda já na última linha;
    }

}

void tela2(){

    int linha, coluna=0;
    textbackground(GREEN);
    gotoxy(20,0);   //Vai pra coluna 20, linha 0
    while(coluna<72){  //Vai de 0 até 72 desenhando as colunas da direita pra esquerda
        printf("=");
        coluna++;
    }
    coluna = 0;
    for (linha = 1; linha<23; linha++){ //Vai da linha 1 até 22, descendo (a partir da coluna 20)
        gotoxy(20,linha);
        printf("||                                                                    ||");

    }
    gotoxy(20,linha); //Desce até a última linha desenhada
    for(;coluna<72; coluna++){
        printf("=");    //Desenha as colunas da direita pra esquerda já na última linha;
    }

}

void convert_fahrenheit(double temperatura){
    char opcao;
    double resultado;
    do{
        textbackground(GREEN);clrscr();                                                                 //Limpa a tela e refaz a moldura
        tela();textbackground(BLUE);
        gotoxy(25,4);printf("(0) para sair");                                                           //Opções do Menu
        gotoxy(25,5);printf("(1) para converter Fahrenheit p/ Celsius");
        gotoxy(25,6);printf("(2) para converter Polegadas p/ Kelvin");gotoxy(25,9);
        opcao = getch();
        while(opcao != '0' && opcao != '1' && opcao != '2')                                              //Verificação caso escolha uma opção inválida
        {
            gotoxy(25,12);printf("Insira uma opção válida: ");
            opcao = getch();
        }
        switch (opcao) {                                                                                  // Parte de Cálculos e Resultados com base na escolha
        case '1':
            resultado = (5.0 / 9.0) * (temperatura - 32.0);
            gotoxy(25,14);printf("%.2lf Fahrenheit em Celsius é igual a %.2lf\n", temperatura, resultado);
            break;
        case '2':
            resultado = (5.0 / 9.0) * (temperatura - 32.0) + 273;
            gotoxy(25,14);printf("%.2lf Fahrenheit em Kelvin é igual a %.2lf\n",temperatura, resultado);
            break;
        default:
            break;
        }
    }while(opcao != '0' && opcao != '1' && opcao != '2');                                                 //Vai repetir até que o usuário digite 0
}

void convert_celsius(double temperatura){
    char opcao;
    double resultado;
    do{
        textbackground(GREEN);clrscr();
        tela();textbackground(BLUE);
        gotoxy(25,4);printf("(0) para sair");
        gotoxy(25,5);printf("(1) para converter Celsius p/ Fahrenheit");
        gotoxy(25,6);printf("(2) para converter Celsius p/ Kelvin");gotoxy(25,9);
        opcao = getch();
        while(opcao != '0' && opcao != '1' && opcao != '2'){   //Verificação caso escolha uma opção inválida
            gotoxy(25,12);printf("Insira uma opção válida: ");
            opcao = getch();
        }

        switch (opcao) {   // Parte de Cálculos e Resultados com base na escolha
            case '1':
                resultado = (temperatura*1.8) + 32;
                gotoxy(25,14); printf("%.2lf Celsius em Fahrenheit é igual a %.2lf\n", temperatura, resultado);
                break;
            case '2':
                resultado = temperatura + 273;
                gotoxy(25,14); printf("%.2lf Celsius em Kelvin é igual a %.2lf\n",temperatura, resultado);
                break;
            default:
                break;
        }
    }while(opcao != '0' && opcao != '1' && opcao != '2');
}

void conversor_temperatura(){
    textcolor(WHITE);
    gotoxy(30,2);
    printf("BEM VINDO AO CONVERSOR DE TEMPERATURA"); //Parte da Tela do conversor em específico
    double temperatura;
    int escolha;
    gotoxy(25,6);printf("0 - SAIR;");
    gotoxy(25,7);printf("1 - FAHRENHEIT;");
    gotoxy(25,8);printf("2 - CELSIUS;");
    gotoxy(25,9);printf("ESCOLHA UM: ");
    scanf("%d", & escolha);

    switch(escolha) {
    case 0:
        break;
    case 1:
        gotoxy(25,11);printf("Digite a temperatura para conversão: ");
        scanf("%lf", &temperatura);
        convert_fahrenheit(temperatura); //Caso 1, vai chamar a função do conversor específico passando a cópia do valor digitado de temperatura para o parâmetro da função
        break;
    case 2:
        gotoxy(25,11);printf("Digite a temperatura para conversão: ");
        scanf("%lf", &temperatura);
        convert_celsius(temperatura);
        break;
    default:
        break;
    }
}

//Conversor da unidade de massa
float kg_g(float Kg){  //1
   float grama;
   grama = Kg*1000;
   return grama;
 }

float g_kg(float g){  //2
    float kg;
    kg=g/1000;
    return kg;
 }

float g_oz(float g){  //3
    float oz ;
    oz=(g/28.3495231);
    return oz;
}

float oz_g(float oz){  //4
    float g;
    g=(oz*28.3495231);
    return g;
}

float oz_lb(float oz){  //5
    float lb;
    lb=(oz/16);
    return lb;
}

float lb_t(float lb){  //6
    float t;
    t=(lb*0.0004536);
    return t;
}

void conversor_massa(){
    int opcao;
    float lb, oz = 0, g = 0, Kg;
    do{
        textcolor(WHITE); gotoxy(30,2); printf("-BEM VINDO AO CONVERSOR DE MASSAS-");
        gotoxy(25,4); printf("(1) Conversão de KGs para Gramas");
        gotoxy(25,5); printf("(2) Conversão de Gramas para KGs");
        gotoxy(25,6); printf("(3) Conversão de Gramas para Onças");
        gotoxy(25,7); printf("(4) Conversão de Onças para Gramas");
        gotoxy(25,8); printf("(5) Conversão de Onças para Libras");
        gotoxy(25,9); printf("(6) Conversão de Libras para Toneladas");
        gotoxy(25,10); printf("(7) Encerrar Programa");
        gotoxy(25,12); printf("Digite a opção desejada: ");
        textbackground(BROWN); printf("  ");
        gotoxy(50,12); scanf("%d",&opcao);
        textbackground(BLUE);

//  Abertura do switch
        switch(opcao){
            case 1:
                gotoxy(25,14); printf("Digite o valor em Quilogramas: "); scanf("%f",&Kg);
                gotoxy(25, 16); printf("O resultado convertido em gramas: %.3fg",kg_g(Kg));
                break;
            case 2:
                gotoxy(25,14); printf("Digite o valor em gramas: "); scanf("%f",&g);
                gotoxy(25,16); printf("O resultado convertido em gramas: %.3fkg",g_kg(g));
                break;
            case 3:
                gotoxy(25,14); printf("Digite o valor em Gramas: "); scanf("%f",&g);
                gotoxy(25,16); printf("O resultado convertido em Onças: %.8foz",g_oz(g));
                break;
            case 4:
                gotoxy(25,14); printf("Digite o valor em Onças: "); scanf("%f",&oz);
                gotoxy(25,16); printf("O resultado convertido em Gramas: %.7fg",oz_g(oz));
                break;
            case 5:
                gotoxy(25,14); printf("Digite o valor em Onças: "); scanf("%f",&oz);
                gotoxy(25,16); printf("O resultado convertido em Libras: %.4flb",oz_lb(oz));
                break;
            case 6:
                gotoxy(25,14); printf("Digite o valor em Libras: "); scanf("%f",&lb);
                gotoxy(25,16); printf("O resultado convertido em Toneladas: %.7f Toneladas",lb_t(lb));
                break;
            case 7:
                break;
            default:
                gotoxy(25,12); printf("                                ");
                gotoxy(25,12); printf("Ops, tentando denovo"); Sleep(1000);
                printf("."); Sleep(1000); printf("."); Sleep(1000); printf("."); Sleep(1000);

        }
    }while((opcao<1) || (opcao>7));

}

void convert_polegadas(double valor){    // Função que converte polegadas
    textbackground(GREEN);clrscr();
    tela();textbackground(BLUE); //Toda vez que a função é chamada, limpa a tela e volta para o molde inicial
    double resultado;
    char opcao;
        do {  //Vai repetir até que seja digitado 0 (para sair)
            resultado = 0;
            gotoxy(25,4);printf("(0) para sair");
            gotoxy(25,5);printf("(1) para converter Polegadas p/ cm");
            gotoxy(25,6);printf("(2) para converter Polegadas p/ Jardas");
            gotoxy(25,7);printf("(3) para converter Polegadas p/ Pés");gotoxy(25,10);
            opcao = getch();
            while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3'){    //Verificação caso escolha uma opção inválida
                gotoxy(25,12);printf("Insira uma opção válida: ");
                opcao = getch();
            }
            switch (opcao){    // Parte de Cálculos e Resultados com base na escolha
            case '1':
                resultado = valor*2.54;
                gotoxy(25,14);printf("%.2lf Polegadas em cm é igual a aproximadamente %.2lf\n", valor, resultado);
                break;
            case '2':
                resultado = valor*0.0277;
                gotoxy(25,14);printf("%.2lf Polegadas em Jardas é igual a aproximadamente %.2lf\n",valor, resultado);
                break;
            case '3':
                resultado = valor*0.083;
                gotoxy(25,14);printf("%.2lf Polegadas em Pés é igual a aproximadamente %.2lf\n",valor, resultado);
                break;
            default:
                break;
            }
        }while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');
}

void convert_jardas(double valor){
    textbackground(GREEN);clrscr();
    tela();textbackground(BLUE);
    double resultado;
    int opcao;
        do{
            resultado = 0;
            gotoxy(25,4);printf("(0) para sair");
            gotoxy(25,5);printf("(1) para converter Jardas p/ cm");
            gotoxy(25,6);printf("(2) para converter Jardas p/ Polegadas");
            gotoxy(25,7);printf("(3) para converter Jardas p/ Pés");gotoxy(25,10);
            opcao = getch();
            while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3'){
                gotoxy(25,12);printf("Insira uma opção válida: ");opcao = getch();
            }
            switch (opcao){
            case '1':
                resultado = valor*91.44;
                gotoxy(25,14);printf("%.2lf Jardas em cm é igual a aproximadamente %.2lf\n", valor, resultado);

                break;
            case '2':
                resultado = valor*36;
                gotoxy(25,14);printf("%.2lf Jardas em Polegadas é igual a aproximadamente %.2lf\n",valor, resultado);

                break;
            case '3':
                resultado = valor*3;
                gotoxy(25,14);printf("%.2lf Jardas em Pés é igual a aproximadamente %.2lf\n",valor, resultado);
                break;
            default:
                break;
            }
        }while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');
}

void convert_pes(double valor){
    textbackground(GREEN);clrscr();
    tela();textbackground(BLUE);
    double resultado;
    char opcao;
        do{
            resultado = 0;
            gotoxy(25,4);printf("(0) para sair");
            gotoxy(25,5);printf("(1) para converter Pés p/ cm");
            gotoxy(25,6);printf("(2) para converter Pés p/ Jardas");
            gotoxy(25,7);printf("(3) para converter Pés p/ Polegadas");gotoxy(25,10);
            opcao = getch();
            while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3'){
                gotoxy(25,12);printf("Insira uma opção válida: ");
                opcao = getch();
            }
            switch (opcao){
            case '1':
                resultado = valor*30.48;
                gotoxy(25,14);printf("%.2lf Pés em cm é igual a aproximadamente %.2lf\n",valor, resultado);
                break;
            case '2':
                resultado = valor*0.33;
                gotoxy(25,14);printf("%.2lf Pés em Jardas é igual a aproximadamente %.2lf\n",valor, resultado);
                break;
            case '3':
                resultado = valor*12;
                gotoxy(25,14);printf("%.2lf Pés em Polegadas é igual a aproximadamente %.2lf\n",valor, resultado);
                break;
            default:
                break;
            }
        }while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');

}

void convert_cm(double valor){
    textbackground(GREEN);clrscr();
    tela();textbackground(BLUE);
    float resultado;
    char opcao;
        do{
            resultado = 0;
            gotoxy(25,4);printf("(0) para sair");
            gotoxy(25,5);printf("(1) para converter Centímetros p/ Polegadas");
            gotoxy(25,6);printf("(2) para converter Centímetros p/ Jardas");
            gotoxy(25,7);printf("(3) para converter Centímetros p/ Pés");gotoxy(25,10);
            opcao = getch();
            while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3') {
                gotoxy(25,12);printf("Insira uma opção válida: ");opcao = getch();
            }
            switch (opcao){
            case '1':
                resultado = valor*0.3937;
                gotoxy(25,14);printf("%.2lf cm em Polegadas é igual a aproximadamente %.2lf\n",valor, resultado);
                break;
            case '2':
                resultado = valor*0.01093;
                gotoxy(25,14);printf("%.2lf cm em Jardas é igual a aproximadamente %.2lf\n",valor, resultado);
                break;
            case '3':
                resultado = valor*0.0328;
                gotoxy(25,14);printf("%.2lf cm em Pés é igual a aproximadamente %.2lf\n",valor, resultado);
                break;
            default:
                break;
            }
        }while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');
}

void conversor_comprimento() {
    textcolor(WHITE); gotoxy(30,2); printf("BEM VINDO AO CONVERSOR DE COMPRIMENTO"); //Parte da Tela do conversor em específico
    double valor;
    int escolha;
    gotoxy(25,6); printf("0 - SAIR;");
    gotoxy(25,7); printf("1 - POLEGADAS;");
    gotoxy(25,8); printf("2 - JARDAS;");
    gotoxy(25,9); printf("3 - PÉS;");
    gotoxy(25,10); printf("4 - CENTÍMETROS;");
    gotoxy(25,11); printf("ESCOLHA UM: ");scanf("%d", & escolha);
    switch(escolha) {
    case 0:
        break;
    case 1:
        gotoxy(25,13);printf("Digite o valor para conversão: ");
        scanf("%lf", &valor);
        convert_polegadas(valor); //Caso 1, vai chamar a função do conversor específico passando a cópia do valor digitado de comprimento para o parâmetro da função
        break;
    case 2:
        gotoxy(25,13);printf("Digite o valor para conversão: ");
        scanf("%lf", &valor);
        convert_jardas(valor);
        break;
    case 3:
        gotoxy(25,13);printf("Digite o valor para conversão: ");
        scanf("%lf", &valor);
        convert_pes(valor);
        break;
    case 4:
        gotoxy(25,13);printf("Digite o valor para conversão: ");
        scanf("%lf", &valor);
        convert_cm(valor);
        break;
    default:
        break;
    }
}


void conversor_tempo_logica(int tempo, int tipo1, int tipo2){

    int resultado;
    switch(tipo1){
        case 1:
            if(tipo2 == 2){
                resultado = tempo/60;
                if (resultado==0){
                    gotoxy(25,22); printf("%d segundo(s) não atingiu 1 minuto faltando %d segundos",tempo,60-tempo);
                }else{
                    gotoxy(25,22); printf("%d segundo(s) deram aproximadamente %d minuto(s).\n",tempo, resultado);
                }
            }else if(tipo2 == 3){
                resultado = (tempo/60)/60;
                if (resultado==0){
                    gotoxy(25,22); printf("%d segundo(s) não atingiu 1 hora faltando %d segundos",tempo,3600-tempo);
                }else{
                    gotoxy(25,22); printf("%d segundo(s) deram aproximadamente %d hora(s).\n",tempo, resultado);
                }
            }else if(tipo2 == 4){
                resultado = ((tempo/60)/60)/24;
                if (resultado==0){
                    gotoxy(25,22); printf("%d segundo(s) não atingiu 1 dia faltando %d segundos",tempo,86400-tempo);
                }else{
                    gotoxy(25,22); printf("%d segundo(s) deram aproximadamente %d dia(s).\n",tempo, resultado);
                }
            }
            else{
                printf("Conversão Inválida");
            }
            break;
        case 2:
            if(tipo2==1){
                resultado = tempo*60;
                gotoxy(25,22); printf("%d minuto(s) deram aproximadamente %d segundo(s).\n",tempo, resultado);
            }else if(tipo2==3){
                resultado = tempo/60;
                if (resultado==0){
                    gotoxy(25,22); printf("%d minuto(s) não atingiu 1 hora faltando %d minuto(s)",tempo,60-tempo);
                }else{
                    gotoxy(25,22); printf("%d minuto(s) deram aproximadamente %d hora(s).\n",tempo, resultado);
                }
            }
            else if(tipo2==4){
                resultado = (tempo/60)/24;
                if (resultado==0){
                    gotoxy(25,22); printf("%d minuto(s) não atingiu 1 dia faltando %d minutos",tempo,1440-tempo);
                }else{
                    gotoxy(25,22); printf("%d minuto(s) deram aproximadamente %d dia(s).\n",tempo, resultado);
                }
            }
            break;
        case 3:
            if(tipo2==1){
                resultado = (tempo*60)*60;
                gotoxy(25,22); printf("%d hora(s) deram aproximadamente %d segundo(s).\n",tempo, resultado);
            }
            else if(tipo2==2){
                resultado = tempo*60;
                gotoxy(25,22); printf("%d hora(s) deram aproximadamente %d minuto(s).\n",tempo, resultado);
            }
            else if(tipo2==4){
                resultado = tempo/24;
                if (resultado==0){
                    gotoxy(25,22); printf("%d horas(s) não atingiu 1 dia faltando %d hora(s)",tempo,24-tempo);
                }else{
                    gotoxy(25,22); printf("%d hora(s) deram aproximadamente %d dia(s).\n",tempo, resultado);
                }
            }
            break;
        case 4:
            if(tipo2==1){
                resultado = tempo*86400;
                gotoxy(25,22); printf("%d dias deram aproximadamente %d segundo(s).\n",tempo, resultado);
            }else if(tipo2==2){
                resultado = tempo*1440;
                gotoxy(25,22); printf("%d dias deram aproximadamente %d minuto(s).\n",tempo, resultado);
            }else if(tipo2==3){
                resultado = tempo*24;
                gotoxy(25,22); printf("%d dias deram aproximadamente %d hora(s).\n",tempo, resultado);
            }
            break;
        default:
            break;
    }
}

void conversor_tempo(){
    int t1 = 1, t2 = 1, tempo=1;

    textcolor(WHITE); gotoxy(30,2); printf("BEM VINDO AO CONVERSOR DE TEMPO");

    gotoxy(25,5); printf("TIPO INICIAL DE TEMPO:");
    gotoxy(25,6); printf("0 - SAIR;");
    gotoxy(25,7); printf("%d - SEGUNDOS;",SEGUNDOS); //Chama o valor do Define (opção "1")
    gotoxy(25,8); printf("%d - MINUTOS;",MINUTOS);
    gotoxy(25,9); printf("%d - HORAS;",HORAS);
    gotoxy(25,10); printf("%d - DIAS;",DIAS);
    gotoxy(25,11); printf("ESCOLHA UM: ");

    do{
        if ((t1<0) || (t1>4)){
            gotoxy(25,11); printf("Valor Inválido, tente novamente: "); scanf("%d",&t1);
            continue;
        }
        else{
            scanf("%d",&t1);
        }
    }while((t1<0) || (t1>4));

    if (t1 == 0){
        return;
    }

    gotoxy(25, 13); printf("DIGITE A QUANTIDADE DESSE TEMPO: ");

    do{
        if(tempo<0){
            gotoxy(25,13); printf("Valor Inválido, digite um num. positivo: "); scanf("%d",&tempo);
            continue;
        }else{
            scanf("%d",&tempo);
        }
    }while(tempo<0);

    gotoxy(25,15); printf("PARA QUAL DESEJA CONVERTER?");
    gotoxy(25,16); printf("%d - SEGUNDOS;",SEGUNDOS);
    gotoxy(25,17); printf("%d - MINUTOS;",MINUTOS);
    gotoxy(25,18); printf("%d - HORAS;",HORAS);
    gotoxy(25,19); printf("%d - DIAS;",DIAS);
    gotoxy(25,21); printf("ESCOLHA UM: ");

    do{
        if ((t2<1) || (t2>4)){
            gotoxy(25,21); printf("Valor Inválido, tente novamente: "); scanf("%d",&t2);
            continue;
        }else{
            scanf("%d",&t2);
        }

    }while((t2<1) || (t2>4));

    conversor_tempo_logica(tempo,t1,t2);
    t1 = 1; t2 = 1; tempo = 1;

}

void convert_dolar(double valor)
{
    textbackground(GREEN);clrscr();
    tela();textbackground(BLUE);
    char opcao;
        do{
            gotoxy(25,4);printf("(0) para sair");
            gotoxy(25,5);printf("(1) para converter Dólar p/ Euro");
            gotoxy(25,6);printf("(2) para converter Dólar p/ Libra");
            gotoxy(25,7);printf("(3) para converter Dólar p/ Real");gotoxy(25,10);
            opcao = getch();
            while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3') {
                gotoxy(25,12);printf("Insira uma opção válida: ");opcao = getch();
            }
            switch(opcao){
                case '1':
                    gotoxy(25,14);printf("A conversão de dólar americano para Euro é: %2lf\n\n",valor*0.93739234);
                    break;
                case '2':
                    gotoxy(25,14);printf("A conversão de dólar americano para libra é: %.2lf\n\n",valor*0.83);
                    break;
                case '3':
                    gotoxy(25,14);printf("A conversão de dólar americano para real é: %.2lf\n\n",valor*5.19);
                    break;
                default:
                    break;
            }
        }while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');
}
void convert_euro(double valor){
    textbackground(GREEN);clrscr();
    tela();textbackground(BLUE);
    char opcao;
        do{
            gotoxy(25,4);printf("(0) para sair");
            gotoxy(25,5);printf("(1) para converter Euro p/ Dólar");
            gotoxy(25,6);printf("(2) para converter Euro p/ Libra");
            gotoxy(25,7);printf("(3) para converter Euro p/ Real");gotoxy(25,10);
            opcao = getch();
            while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3') {
                gotoxy(25,12);printf("Insira uma opção válida: ");opcao = getch();
            }
        switch(opcao){
            case '1':
                gotoxy(25,14);printf("A conversão de Euro para dólar é: %.2lf\n\n",valor*1.07);
                break;
            case '2':
                gotoxy(25,14);printf("A conversão de Euro para Libra é: %.2lf\n\n",valor*0.89);
                break;
            case '3':
                gotoxy(25,14);printf("A conversão de Euro para Real é: %.2lf\n\n",valor*5.54);
                break;
            default:
                break;
            }
    }while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');
}


void convert_libra(double valor){
    textbackground(GREEN);clrscr();
    tela();textbackground(BLUE);
    char opcao;
        do{
            gotoxy(25,4);printf("(0) para sair");
            gotoxy(25,5);printf("(1) para converter Libra p/ Dólar");
            gotoxy(25,6);printf("(2) para converter Libra p/ Euro");
            gotoxy(25,7);printf("(3) para converter Libra p/ Real");gotoxy(25,10);
            opcao = getch();
            while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3') {
                gotoxy(25,12);printf("Insira uma opção válida: ");opcao = getch();
            }
        switch(opcao){
        case '1':
            gotoxy(25,14);printf("A conversão de libra para dólar é: %.2lf\n\n",valor*1.20);
            break;
        case '2':
            gotoxy(25,14);printf("A conversão de libra para euro é: %.2lf\n\n",valor*1.13);
            break;
        case '3':
            gotoxy(25,14);printf("A conversão de libra para real é: %.2lf\n\n",valor*6.23);
            break;
        default:
            break;
        }
    }while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');
}

void convert_real(double valor){
    textbackground(GREEN);clrscr();
    tela();textbackground(BLUE);
    char opcao;
        do{
            gotoxy(25,4);printf("(0) para sair");
            gotoxy(25,5);printf("(1) para converter Real p/ Dólar");
            gotoxy(25,6);printf("(2) para converter Real p/ Euro");
            gotoxy(25,7);printf("(3) para converter Real p/ Libra");gotoxy(25,10);
            opcao = getch();
            while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3') {
                gotoxy(25,12);printf("Insira uma opção válida: ");opcao = getch();
            }
        switch(opcao){
        case '1':
            gotoxy(25,14);printf("A conversão de real para Dólar é: %.2lf\n\n",valor*0.19);
            break;
        case '2':
            gotoxy(25,14);printf("A conversão de real para Euro é: %.2lf\n\n",valor*0.18);
            break;
        case '3':
            gotoxy(25,14);printf("A conversão de real para Libra é: %.2lf\n\n",valor*0.16);
            break;
        default:
            break;
        }

    }while(opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3');
}

void conversor_moeda() {
     textcolor(WHITE); gotoxy(30,2); printf("BEM VINDO AO CONVERSOR DE MOEDA"); //Parte da Tela do conversor em específico
    double valor;
    int escolha;
    gotoxy(25,6); printf("0 - SAIR;");
    gotoxy(25,7); printf("1 - DÓLAR;");
    gotoxy(25,8); printf("2 - EURO;");
    gotoxy(25,9); printf("3 - LIBRA;");
    gotoxy(25,10); printf("4 - REAL;");
    gotoxy(25,11); printf("ESCOLHA UM: ");scanf("%d", & escolha);
    switch(escolha) {
    case 0:
        break;
    case 1:
        gotoxy(25,13);printf("Digite o valor para conversão: ");
        scanf("%lf", &valor);
        convert_dolar(valor); //Caso 1, vai chamar a função do conversor específico passando a cópia do valor digitado de moeda para o parâmetro da função
        break;

    case 2:
        gotoxy(25,13);printf("Digite o valor para conversão: ");
        scanf("%lf", &valor);
        convert_euro(valor);
        break;

    case 3:
        gotoxy(25,13);printf("Digite o valor para conversão: ");
        scanf("%lf", &valor);
        convert_libra(valor);
        break;

    case 4:
        gotoxy(25,13);printf("Digite o valor para conversão: ");
        scanf("%lf", &valor);
        convert_real(valor);
        break;
    default:
        break;
    }
}

float kmh_to_ms(float kmh) {
    return kmh * 1000 / 3600;
}

float kmh_to_milhas(float kmh) {
    return kmh / 1.609;
}

float kmh_to_pes(float kmh) {
    return kmh / 1.097;
}

void conversor_velocidade() {
    float velocidade;
    int escolha;
        textcolor(WHITE); gotoxy(30,2); printf("BEM VINDO AO CONVERSOR DE VELOCIDADE");
        gotoxy(25,6); printf("0 - SAIR;");
        gotoxy(25,7); printf("1 - Conversões para KM;");
        gotoxy(25,8); printf("2 - Conversões para Milhas;");
        gotoxy(25,9); printf("3 - Conversões para Pés;");
        gotoxy(25,11); printf("ESCOLHA UM: ");scanf("%d", &escolha);
        while(escolha < 0 || escolha > 3) {
            gotoxy(25,12);printf("Insira uma opção válida: ");scanf("%d", &escolha);
        }
        if(escolha != 0) {
            gotoxy(25,13);printf("Digite a velocidade: ");scanf("%f", &velocidade);

            switch (escolha) {
                case 0:
                    break;
                case 1:
                    gotoxy(25,15);printf("%.2f km/h equivale a:\n", velocidade);
                    gotoxy(25,16);printf("%.2f m/s\n", kmh_to_ms(velocidade));
                    gotoxy(25,17);printf("%.2f milhas/h\n", kmh_to_milhas(velocidade));
                    gotoxy(25,18);printf("%.2f pes/s\n", kmh_to_pes(velocidade));
                    break;
                case 2:
                    gotoxy(25,15);printf("%.2f milhas/h equivale a:\n", velocidade);
                    velocidade = velocidade * 1.609;
                    gotoxy(25,16);printf("%.2f km/h\n", velocidade);
                    gotoxy(25,17);printf("%.2f m/s\n", kmh_to_ms(velocidade));
                    gotoxy(25,18);printf("%.2f pes/s\n", kmh_to_pes(velocidade));
                    break;
                case 3:
                    gotoxy(25,15);printf("%.2f pes/s equivale a:\n", velocidade);
                    velocidade = velocidade * 1.097;
                    gotoxy(25,16);printf("%.2f km/h\n", velocidade);
                    gotoxy(25,17);printf("%.2f m/s\n", kmh_to_ms(velocidade));
                    gotoxy(25,18);printf("%.2f milhas/h\n", kmh_to_milhas(velocidade));
                    break;
                default:
                    break;
            }
        }
}

void matriz_transposta(){
        textbackground(BLACK);clrscr();
        tela2();textbackground(GREEN);
        textcolor(BLACK);

        int M[4][3];
        int T[3][4];
        int i,j;

        gotoxy(27,2); printf("===TRANSPOSTER 2000===");
        gotoxy(25,4); printf("Insira os valores da matriz 4x3 e 'tombaremos' ela para vc!");
        gotoxy(25,6); printf("Insira os valores da matriz principal: ");

        for(i=0;i<4;i++){
            for(j=0;j<3;j++){
                scanf("%d",&M[i][j]);
                gotoxy(63,6); printf("          "); gotoxy(63,6);
            }
        }

        for(i=0;i<4;i++){
            for(j=0;j<3;j++){
                T[j][i] = M[i][j];
            }
        }

        gotoxy(25,8); printf("MATRIZ NORMAL:");

        int x = 10;
        gotoxy(23,x);
        for(i=0;i<4;i++){
            for(j=0;j<3;j++){
                printf("%3d",M[i][j]);
            }
            x++;
            gotoxy(23,x);
        }

        gotoxy(45,8);
        printf("MATRIZ TOMBADA: ");

        x=11;
        gotoxy(45,x);

        for(i=0;i<3;i++){
            for(j=0;j<4;j++){
                printf("%3d",T[i][j]);
            }
            x++;
            gotoxy(45,x);
        }

        Sleep(1000);

        gotoxy(62,12); printf("O<--< tombei rs");

}


void diagonal_matriz(){
        textbackground(BLACK);clrscr();
        tela2();textbackground(GREEN);
        textcolor(BLACK);

        int ordem;

        gotoxy(27,2); printf("-BEM VINDO AO CALCULADOR DE SOMA DA DIAGONAL DA MATRIZ-");
        gotoxy(25,6); printf("(OBS: ACEITAMOS APENAS ATÉ DE ORDEM 10!!)");
        gotoxy(25,5); printf("INSIRA A ORDEM DA SUA MATRIZ: ");

        do{
            scanf("%d",&ordem);
            gotoxy(55,5); printf("    "); gotoxy(55,5);
        }while(ordem>10 || ordem<=0);

        int M[ordem][ordem],soma=0;

        gotoxy(25,8); printf("Agora insira os valores da sua matriz: ");

        for(int i=0;i<ordem;i++){
            for(int j=0;j<ordem;j++){
                scanf("%d", &M[i][j]);
                gotoxy(64,8); printf("       "); gotoxy(64,8);
                if(i==j)
                    soma += M[i][j];

            }
        }

        gotoxy(23,10); printf("SUA MATRIZ:");
        gotoxy(23,12);
        int x = 12;
        for(int i=0;i<ordem;i++){
            for(int j=0;j<ordem;j++){
                printf("%6d",M[i][j]);
            }
            x++;
            gotoxy(23,x);
        }

        gotoxy(26,x+2); printf("E A SOMA DA DIAGONAL FOI DE %d !",soma);

}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
void selection_sort(int matrix[4][4]) {

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {

      int min_i = i;
      int min_j = j;
      for (int k = i; k < 4; k++) {
        for (int l = (k == i) ? j + 1 : 0; l < 4; l++) {
          if (matrix[k][l] < matrix[min_i][min_j]) {
            min_i = k;
            min_j = l;
          }
        }
      }
      swap(&matrix[i][j], &matrix[min_i][min_j]);
    }
  }
}

void matriz_ordenada(){
    textbackground(BLACK);clrscr();
    tela2();textbackground(GREEN);
    textcolor(BLACK);

    int matriz[4][4];
    int i,j;

    gotoxy(27,2); printf("==BEM VINDO AO ORDENADOR DE MATRIZ (CRESCENTE)==");
    gotoxy(25,4); printf("INSIRA OS VALORES DA MATRIZ 4X4: ");

    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            gotoxy(58,4); printf("     ");
            gotoxy(58,4); scanf("%d",&matriz[i][j]);

        }
    }

    gotoxy(23,7); printf("SUA MATRIZ:");
        gotoxy(23,9);
        int x = 9;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                printf("%5d",matriz[i][j]);
            }
            x++;
            gotoxy(23,x);
        }
    selection_sort(matriz);
    gotoxy(50,7); printf("MATRIZ EM ORDEM CRESCENTE:");
    gotoxy(50,9);
        x = 9;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                printf("%5d",matriz[i][j]);
            }
            x++;
            gotoxy(50,x);
        }
}

void soma_matrizes(){

    textbackground(BLACK);clrscr();
    tela2();textbackground(GREEN);
    textcolor(BLACK);

    int n,i,j,x;

    gotoxy(27,2); printf("==BEM VINDO AO SOMADOR DE MATRIZES==");
    gotoxy(25,4); printf("ESCOLHA QUAL A ORDEM DA SUA MATRIZ: ");
    gotoxy(25,5); printf("OBS: LIMITE DE ORDEM 5 !!");

    do{
        gotoxy(61,4); printf("    ");
        gotoxy(61,4); scanf("%d",&n);
    }while(n<1 || n>5);

    int m1[n][n], m2[n][n], m3[n][n];

    gotoxy(25,7); printf("INSIRA OS VALORES DA MATRIZ 1: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            gotoxy(56,7); printf("    ");
            gotoxy(56,7); scanf("%d",&m1[i][j]);
        }
    }

    gotoxy(25,9); printf("INSIRA OS VALORES DA MATRIZ 2: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            gotoxy(56,9); printf("    ");
            gotoxy(56,9); scanf("%d",&m2[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            m3[i][j] = m1[i][j] + m2[i][j];
        }
    }

    gotoxy(23,11); printf("PRIMEIRA MATRIZ: ");
    x = 12;
    gotoxy(23,12);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d",m1[i][j]);
        }
        x++;
        gotoxy(23,x);
    }
    Sleep(500);
    gotoxy(55,11); printf("SEGUNDA MATRIZ: ");
    x = 12;
    gotoxy(55,12);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d",m2[i][j]);
        }
        x++;
        gotoxy(55,x);
    }
    Sleep(500);
    gotoxy(23,17); printf("MATRIZ RESULTANTE: ");
    x = 18;
    gotoxy(23,18);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d",m3[i][j]);
        }
        x++;
        gotoxy(23,x);
    }

}

void matrix(){

        textbackground(BLACK);clrscr();
        tela2();textbackground(GREEN);
        textcolor(BLACK);
        char todo;
        gotoxy(27,2); printf("<SEJA BEM VINDO À MATRIX>");
        gotoxy(24,4); printf("ESCOLHA SUA FORMA DE MANIPULAR UMA MATRIZ:");
        gotoxy(24,6); printf("1. DIAGONAL DA MATRIX;");
        gotoxy(24,7); printf("2. ===TRANSPOSTER 2000=== (M. TRANSPOSTA);");
        gotoxy(24,8); printf("3. MATRIZ CRESCENTE;");
        gotoxy(24,9); printf("4. SOMAR MATRIZES;");
        gotoxy(24,10); printf("0. SAIR;");

        gotoxy(30,12); printf("ESCOLHA: ");

        do{
            gotoxy(39,12); todo = getch();
        }while(todo != '0' && todo != '1' && todo != '2' && todo != '3' && todo != '4');

        switch (todo){
            case '0':
                break;
            case '1':
                diagonal_matriz();
                break;
            case '2':
                matriz_transposta();
                break;
            case '3':
                matriz_ordenada();
                break;
            case '4':
                soma_matrizes();
                break;
            default:
                break;
        }
}

struct RomanConverter {
    int num;
    char roman[20];
};
void convertToRoman(int num, char* roman) {
    // Array para armazenar os valores dos algarismos romanos
    struct RomanConverter romanMap[] = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };
    int i = 0;
    // Loop para converter o número em algarismos romanos
    while (num > 0) {
        int div = num / romanMap[i].num;
        num = num % romanMap[i].num;
        while (div--) {
            strcat(roman, romanMap[i].roman);
        }
        i++;
    }
}

void numeros_romanos() {

    textcolor(WHITE); gotoxy(30,2); printf("==BEM VINDO AO CONVERSOR DE NUMEROS ROMANOS==");
    struct RomanConverter rc;
    int n,i;
    gotoxy(25,4); printf("ESCOLHA QUANTAS VEZES QUER CONVERTER: ");
    gotoxy(25,5); printf("MÁXIMO: 7!! (0. PARA SAIR)");
    do{
        gotoxy(63,4); printf("     ");
        gotoxy(63,4); scanf("%d",&n);
    }while(n<0 || n>7);
    int linha = 7;
    for(i = 0;i < n;i++){
        if(n==0){
            break;
        }
        gotoxy(25,linha); printf("DIGITE UM NUMERO NORMAL INTEIRO: ");
        do{
            gotoxy(58,linha); printf("     ");
            gotoxy(58,linha); scanf("%d", &rc.num);
        }while(rc.num<=0);

        memset(rc.roman, '\0', sizeof(rc.roman)); // limpa a string roman
        convertToRoman(rc.num, rc.roman);

        gotoxy(25,linha+1); printf("NÚMERO ROMANO: %s", rc.roman);
        linha += 2;
    }
}


int main(){
    setlocale(LC_ALL,"Portuguese");

    char opcao, quer;
    int vet[8] = {0}, verifica = 0;
    int usouTempo = 0, usouComprimento = 0, usouTemperatura = 0, usouMassa = 0, usouMoeda = 0, usouVelocidade = 0, usouMatrix = 0, usouRomano = 0;

    do{
        textbackground(GREEN); clrscr(); textcolor(YELLOW);
        tela(); // Chama a função tela
        textbackground(BLUE);  //define o fundo como azul

        gotoxy(25,3); printf("--BEM VINDO AO GRAND CONVERSOR--"); //Texto de boas vindas, coluna 25, linha 3;
        gotoxy(25,5); printf("Escolha uma das seguintes opções de conversão:");
        gotoxy(25,7); textcolor(YELLOW); printf("1. Conversor de Tempo");
        gotoxy(25,8); textcolor(YELLOW); printf("2. Conversor de Comprimento");
        gotoxy(25,9); textcolor(YELLOW); printf("3. Conversor de Temperatura");
        gotoxy(25,10); textcolor(YELLOW); printf("4. Conversor de Peso");
        gotoxy(25,11); textcolor(YELLOW); printf("5. Conversor de Moeda");
        gotoxy(25,12); textcolor(YELLOW); printf("6. Conversor de Velocidade");
        gotoxy(25,13); textcolor(YELLOW); printf("7. M A T R I X");
        gotoxy(25,14); textcolor(YELLOW); printf("8. Conversor de Romanos");
        gotoxy(25,15); textcolor(YELLOW); printf("9.-Sair do Programa-");
        gotoxy(30,16); opcao = getch();

        if (opcao != '9') {
            do{
                tela();
                textcolor(YELLOW);
                char mensagem[100] = "";
                switch (opcao){
                    case '1':
                                conversor_tempo();
                                strcat(mensagem,"DESEJA CONVERTER TEMPO NOVAMENTE? (S/N) ");
                                vet[0]++;
                                verifica++;
                                break;
                    case '2':
                                conversor_comprimento();
                                strcat(mensagem,"DESEJA CONVERTER COMPRIMENTO NOVAMENTE? (S/N) ");
                                vet[1]++;
                                verifica++;
                                break;
                    case '3':
                                conversor_temperatura();
                                strcat(mensagem,"DESEJA CONVERTER TEMPERATURA NOVAMENTE? (S/N) ");
                                vet[2]++;
                                verifica++;
                                break;
                    case '4':
                                conversor_massa();
                                strcat(mensagem,"DESEJA CONVERTER MASSA NOVAMENTE? (S/N) ");
                                vet[3]++;
                                verifica++;
                                break;
                    case '5':
                                conversor_moeda();
                                strcat(mensagem,"DESEJA CONVERTER MOEDA NOVAMENTE? (S/N) ");
                                vet[4]++;
                                verifica++;
                                break;
                    case '6':
                                conversor_velocidade();
                                strcat(mensagem,"DESEJA CALCULAR VELOCIDADE NOVAMENTE? (S/N) ");
                                vet[5]++;
                                verifica++;
                                break;
                    case '7':
                                matrix();
                                strcat(mensagem,"DESEJA PERMANECER NA MATRIX? (S/N) ");
                                vet[6]++;
                                verifica++;
                                break;
                    case '8':
                                numeros_romanos();
                                strcat(mensagem,"DESEJA CALCULAR NOVAMENTE? (S/N) ");
                                vet[7]++;
                                verifica++;
                                break;
                    default:
                                while((opcao!='1') && (opcao!='2') && (opcao!='3') && (opcao!='4') && (opcao!='5') && (opcao!='6') && (opcao!='7') && (opcao!='8') && (opcao!='9')){
                                    gotoxy(30,20); printf("Opção Inválida, insira corretamente: "); opcao = getch();
                                }
                                break;
                }
                gotoxy(44,21);printf("%s", mensagem);
                quer = getch();
            }while((toupper(quer)=='S')); //Repete até q o usuário queira, pressionando 'S' ou 's'


            for (int i = 0; i < 8; i++) {
                if (vet[i] != 0) {
                    switch (i) {
                        case 0:
                            usouTempo = 1;
                            break;
                        case 1:
                            usouComprimento = 1;
                            break;
                        case 2:
                            usouTemperatura = 1;
                            break;
                        case 3:
                            usouMassa = 1;
                            break;
                        case 4:
                            usouMoeda = 1;
                            break;
                        case 5:
                            usouVelocidade = 1;
                            break;
                        case 6:
                            usouMatrix = 1;
                            break;
                        case 7:
                            usouRomano = 1;
                            break;
                    }
                }
            }
        }
    }while(opcao!='9');

    clrscr();
    if ((usouRomano == 1 && usouTempo == 1 && usouComprimento == 1 && usouTemperatura == 1 && usouMassa == 1 && usouMoeda == 1 && usouVelocidade == 1 && usouMatrix == 1)) {
        gotoxy(0,8);
        printf("   .    _  .     ________________________________________\n");
        printf("   |\\_|/__/|    /                                        \\\n");
        printf("  / / \\/ \\  \\  / Vejo que gosta de fazer conversões       \\\n");
        printf(" /__|O||O|__ \\ \\              Parabéns!                   /\n");
        printf("|/_ \\_/\\_/ _\\ | \\  ______________________________________/\n");
        printf("| | (____) | ||  |/\n");
        printf("\\/\\___/\\__/  // _/\n");
        printf("(_/         ||\n");
        printf(" |          ||\\\n");
        printf("  \\        //_/\n");
        printf("   \\______//\n");
        printf("  __|| __||\n");
        printf(" (____(____)\n");
        gotoxy(44,21);printf("Usou %d vez(es) o conversor", verifica);
        gotoxy(44,24);printf("--APERTE QUALQUER TECLA PARA SAIR--");
        getch();
        clrscr();
    }
    gotoxy(30,3);
    printf("--APERTE QUALQUER TECLA PARA FECHAR O PROGRAMA--");
    gotoxy(0,5);
    printf("  ___  ___ ___   ___ ___  ___     _ ___ ___ _____ \n");
    printf(" |   \\/ __|_ _| | _ \\ _ \\/ _ \\ _ | | __/ __|_   _|\n");
    printf(" | |) \\__ \\| |  |  _/   / (_) | || | _| (__  | |  \n");
    printf(" |___/|___/___| |_| |_|_\\\\____/ \\__/|___\\__ | |_|  \n");
    printf("                                                  \n");
    gotoxy(32,14); getch();
}
