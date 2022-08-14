#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <locale.h>
#include <stdbool.h>


void linhaCol(int lin, int col);
void box(int lin1, int col1, int lin2, int col2);
int menu(int lin1, int col1, int qtd, char lista[3][40]);
void textColor(int letras, int fundo);

//COR DA LETRA
enum{BLACK, //0
BLUE, //1
GREEN, //2
CYAN, //3
RED, //4
MAGENTA, //5
BROWN, //6
LIGHTGRAY, //7
DARKGRAY, //8
LIGHTBLUE, //9
LIGHTGREEN, //10
LIGHTCYAN, //11
LIGHTRED, //12
LIGHTMAGENTA, //13
YELLOW, //14
WHITE //15

};
//COR DO FUNDO
enum{_BLACK=0, //0
_BLUE=16, //1
_GREEN=32, //2
_CYAN=48, //3
_RED=64, //4
_MAGENTA=80, //5
_BROWN=96, //6
_LIGHTGRAY=112, //7
_DARKGRAY=128, //8
_LIGHTBLUE=144, //9
_LIGHTGREEN=160, //10
_LIGHTCYAN=176, //11
_LIGHTRED=192, //12
_LIGHTMAGENTA=208, //13
_YELLOW=224, //14
_WHITE=240 //15
};

void textColor(int letra, int fundo){
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), letra + fundo);
}

void linhaCol(int lin, int col){
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});// coorddenada na tela


//funcao para deixar o cursor invisivel
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO info;
info.dwSize = 100;
info.bVisible = FALSE;
SetConsoleCursorInfo(consoleHandle, &info);
}
void box(int lin1, int col1, int lin2, int col2){
int i,j , tamlin, tamcol;

//achar o tamanho do box
tamlin = lin2 - lin1;
tamcol = col2 - col1;

//Monta o Box

for (i=col1; i<=col2; i++){ // linhas
linhaCol(lin1,i);
printf("%c",196);
linhaCol(lin2,i);
printf("%c",196);
}

for (i=lin1; i<=lin2; i++){ //colunas
linhaCol(i,col1);
printf("%c",179);
linhaCol(i,col2);
printf("%c",179);
}
for (i=lin1+1;i<lin2;i++){
for(j=col1+1;j<col2;j++){
linhaCol(i,j);printf(" ");
}
}
//Posi��o dos cantos
linhaCol(lin1,col1);
printf("%c",218);
linhaCol(lin1,col2);
printf("%c",191);
linhaCol(lin2,col1);
printf("%c",192);
linhaCol(lin2,col2);
printf("%c",217);

}
int menu(int lin1, int col1, int qtd, char lista[3][40]){
int opc=1, lin2, col2, linha,i,tamMaxItem, tecla;

//calcula as coordenadas
tamMaxItem = strlen(lista[0]);
//tamanho maximo do item
for(i=1; i<qtd;i++){
if(strlen(lista[i])>tamMaxItem){
tamMaxItem = strlen(lista[i]);
}
}
lin2 = lin1+(qtd*2+2);
col2 = col1+tamMaxItem+4;

//Monta Tela
textColor(WHITE, _BLUE);
setlocale(LC_ALL,"C");
box(lin1,col1,lin2,col2);
setlocale(LC_ALL,"");
//la�o das opc�es
while(1){

linha=lin1+2;
for(i=0;i<qtd;i++){
if(i+1==opc)textColor(BLACK, _LIGHTGREEN);
else textColor(WHITE, _BLUE);
linhaCol(linha,col1+2);
printf("%s",lista[i]);
linha +=2;
}

//Aguarda tecla
linhaCol(1,1);
tecla= getch();
linhaCol(22,1);
//printf(" tecla: %d ",tecla);
//Op��o
if(tecla==27){ //ESC
opc=0; break;
}
else if(tecla==13){ //ENTER
break;
}
//Seta para cima
else if(tecla==72){ //se possivel seleciona o item anterior - seta para cima
if(opc>1)opc--; // se opcao for maior que 1, pode voltar

}
else if(tecla==80 ){ //seta para baixo
if (opc<qtd)opc++; //Se opcao for menor que quantidade de itens, posso avan�ar

//printf("tecla: %d ",opc);
}
}
return opc;
}

int main()
{
int opc;
char lista[11][40]={ "MENU PRINCIPAL - DIGITE A OP��O DESEJADA\n  " , "1. BATERIA 01" , "2. BATERIA 02" , "3. BATERIA 03" , "4. OBTER CLASSIFICA��O GERAL NA TELA" , "5. EXPORTAR CLASSIFICA��O GERAL" ,"6. SAIR DO SISTEMA"};

setlocale(LC_ALL,"");
while(true)
{
opc = menu(10,10,8,lista);

if (opc==7)
{
break;
}

linhaCol(1,1);
textColor(WHITE, _RED);
//printf("\nEscolheu a op��o %d", opc);

textColor(WHITE, _BLACK);
linhaCol(24,1);
printf("");

//testando o sistema integrado
//variaveis
    int eq1bat1min, eq1bat1seg, eq1bat1mile;
    int eq2bat1min, eq2bat1seg, eq2bat1mile;
    int eq3bat1min, eq3bat1seg, eq3bat1mile;
    int eq4bat1min, eq4bat1seg, eq4bat1mile;
    int eq5bat1min, eq5bat1seg, eq5bat1mile;
    int eq1bat2min, eq1bat2seg, eq1bat2mile;
    int eq2bat2min, eq2bat2seg, eq2bat2mile;
    int eq3bat2min, eq3bat2seg, eq3bat2mile;
    int eq4bat2min, eq4bat2seg, eq4bat2mile;
    int eq5bat2min, eq5bat2seg, eq5bat2mile;
    int eq1bat3min, eq1bat3seg, eq1bat3mile;
    int eq2bat3min, eq2bat3seg, eq2bat3mile;
    int eq3bat3min, eq3bat3seg, eq3bat3mile;
    int eq4bat3min, eq4bat3seg, eq4bat3mile;
    int eq5bat3min, eq5bat3seg, eq5bat3mile;
    int min1bat1,seg1bat1,mele1bat1;
    int min1bat2,seg1bat2,mele1bat2;
    int min1bat3,seg1bat3,mele1bat3;
    int min2bat1,seg2bat1,mele2bat1;
    int min2bat2,seg2bat2,mele2bat2;
    int min2bat3,seg2bat3,mele2bat3;
    int min3bat1,seg3bat1,mele3bat1;
    int min3bat2,seg3bat2,mele3bat2;
    int min3bat3,seg3bat3,mele3bat3;
    int min4bat1,seg4bat1,mele4bat1;
    int min4bat2,seg4bat2,mele4bat2;
    int min4bat3,seg4bat3,mele4bat3;
    int min5bat1,seg5bat1,mele5bat1;
    int min5bat2,seg5bat2,mele5bat2;
    int min5bat3,seg5bat3,mele5bat3;
    int pmaior1, smaior1;
    int pmaior2, smaior2;
    int pmaior3, smaior3;
    int pmaior4, smaior4;
    int pmaior5, smaior5;
    int media1, media2, media3, media4, media5;
    int min1, seg1, mm1;
    int min2, seg2, mm2;
    int min3, seg3, mm3;
    int min4, seg4, mm4;
    int min5, seg5, mm5;
    int sel, i;

system ("cls");

    switch(opc){

    case 1:
            {
            int opc;
            char lista[11][40]={ "SEJAM BEM VINDOS AOS SISTEMA FAST SYSTEM","TRABALHO FEITO POR:","ROGERIO","LUIGI","PEDRO","LUIZ","MATEUS","VOLTAR AO MENU PRINCIPAL"};

            setlocale(LC_ALL,"");
            while(true)
            {
            opc = menu(10,10,8,lista);


            if (opc==8)
            {
            system("pause");
            system("cls");
            break;
            }

            linhaCol(1,1);
            textColor(WHITE, _RED);
            //printf("\nEscolheu a op��o %d", opc);

            textColor(WHITE, _BLACK);
            linhaCol(24,1);
            printf("");

            }
            }
            break;
            system ("cls");


    case 2:
            system ("cls");
            {
            int opc;
            char lista[11][40]={ "DIGITE O TEMPO DA BATERIA 1 DE CADA UMA DAS EQUIPES:\n","1. Tempo da Equipe 1 na bateria 1:","2. Tempo da Equipe 2 na bateria 1:","3. Tempo da Equipe 3 na bateria 1:","4. Tempo da Equipe 4 na bateria 1:","5. Tempo da Equipe 5 na bateria 1:", "6.Voltar ao menu principal"};

            setlocale(LC_ALL,"");
            while(true)
            {
            opc = menu(10,10,8,lista);

            if (opc==7)
            {
            system("pause");
            system("cls");
            break;
            }

            linhaCol(1,1);
            textColor(WHITE, _RED);
            //printf("\nEscolheu a op��o %d", opc);

            textColor(WHITE, _BLACK);
            linhaCol(24,1);
            printf("");

            if (opc == 1){
                system("pause");
                system ("cls");
            }
            else if (opc == 2){
                system("cls");
                printf("Digite o tempo da equipe 1 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq1bat1min, &eq1bat1seg, &eq1bat1mile);
                printf("Tempo %d:%d:%d \n", eq1bat1min, eq1bat1seg, eq1bat1mile);
                min1bat1 = eq1bat1min*60000;
                seg1bat1 = eq1bat1seg*1000;
                mele1bat1 = min1bat1 + seg1bat1 + eq1bat1mile;
                system("pause");
                system ("cls");

                }

            else if (opc == 3){
                system("cls");
                printf("Digite o tempo da equipe 2 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq2bat1min, &eq2bat1seg, &eq2bat1mile);
                printf("Tempo %d:%d:%d \n", eq2bat1min, eq2bat1seg, eq2bat1mile);
                min2bat1 = eq2bat1min*60000;
                seg2bat1 = eq2bat1seg*1000;
                mele2bat1 = min2bat1 + seg2bat1 + eq2bat1mile;
                system("pause");
                system ("cls");
            }
            else if (opc == 4){
                system("cls");
                printf("Digite o tempo da equipe 3 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq3bat1min, &eq3bat1seg, &eq3bat1mile);
                printf("Tempo %d:%d:%d \n", eq3bat1min, eq3bat1seg, eq3bat1mile);
                min3bat1 = eq3bat1min*60000;
                seg3bat1 = eq3bat1seg*1000;
                mele3bat1 = min3bat1 + seg3bat1 + eq3bat1mile;
                system("pause");
                system ("cls");
            }

            else if (opc == 5){
                system("cls");
                printf("Digite o tempo da equipe 4 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq4bat1min, &eq4bat1seg, &eq4bat1mile);
                printf("Tempo %d:%d:%d \n", eq4bat1min, eq4bat1seg, eq4bat1mile);
                min4bat1 = eq4bat1min*60000;
                seg4bat1 = eq4bat1seg*1000;
                mele4bat1 = min4bat1 + seg4bat1 + eq4bat1mile;
                system("pause");
                system ("cls");
            }

             else if (opc == 6){
                system("cls");
                printf("Digite o tempo da equipe 5 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq5bat1min, &eq5bat1seg, &eq5bat1mile);
                printf("Tempo %d:%d:%d \n", eq5bat1min, eq5bat1seg, eq5bat1mile);
                min5bat1 = eq5bat1min*60000;
                seg5bat1 = eq5bat1seg*1000;
                mele5bat1 = min5bat1 + seg5bat1 + eq5bat1mile;
                system("pause");
                system("cls");
             }
            }
            }
            break;
            system ("cls");


    case 3:
            system ("cls");
            {
            int opc;
            char lista[11][40]={ "DIGITE O TEMPO DA BATERIA 2 DE CADA UMA DAS EQUIPES:\n","1. Tempo da Equipe 1 na bateria 2:","2. Tempo da Equipe 2 na bateria 2:","3. Tempo da Equipe 3 na bateria 2:","4. Tempo da Equipe 4 na bateria 2:","5. Tempo da Equipe 5 na bateria 2:", "6.Voltar ao menu principal"};

            setlocale(LC_ALL,"");
            while(true)
            {
            opc = menu(10,10,8,lista);

            if (opc==7)
            {
            system("pause");
            system("cls");
            break;
            }

            linhaCol(1,1);
            textColor(WHITE, _RED);
            //printf("\nEscolheu a op��o %d", opc);

            textColor(WHITE, _BLACK);
            linhaCol(24,1);
            printf("");

            if (opc == 1){
                system("pause");
                system ("cls");
            }
            else if (opc == 2){
                system("cls");
                printf("Digite o tempo da equipe 1 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq1bat2min, &eq1bat2seg, &eq1bat2mile);
                printf("Tempo %d:%d:%d \n", eq1bat2min, eq1bat2seg, eq1bat2mile);
                min1bat2 = eq1bat2min*60000;
                seg1bat2 = eq1bat2seg*1000;
                mele1bat2 = min1bat2 + seg1bat2 + eq1bat2mile;
                system("pause");
                system ("cls");

                }

            else if (opc == 3){
                system("cls");
                printf("Digite o tempo da equipe 2 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq2bat2min, &eq2bat2seg, &eq2bat2mile);
                printf("Tempo %d:%d:%d \n", eq2bat2min, eq2bat2seg, eq2bat2mile);
                min2bat2 = eq2bat2min*60000;
                seg2bat2 = eq2bat2seg*1000;
                mele2bat2 = min2bat2 + seg2bat2 + eq2bat2mile;
                system("pause");
                system ("cls");
            }
            else if (opc == 4){
                system("cls");
                printf("Digite o tempo da equipe 3 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq3bat2min, &eq3bat2seg, &eq3bat2mile);
                printf("Tempo %d:%d:%d \n", eq3bat2min, eq3bat2seg, eq3bat2mile);
                min3bat2 = eq3bat2min*60000;
                seg3bat2 = eq3bat2seg*1000;
                mele3bat2 = min3bat2 + seg3bat2 + eq3bat2mile;
                system("pause");
                system ("cls");
            }

            else if (opc == 5){
                system("cls");
                printf("Digite o tempo da equipe 4 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq4bat2min, &eq4bat2seg, &eq4bat2mile);
                printf("Tempo %d:%d:%d \n", eq4bat2min, eq4bat2seg, eq4bat2mile);
                min4bat2 = eq4bat2min*60000;
                seg4bat2 = eq4bat2seg*1000;
                mele4bat2 = min4bat2 + seg4bat2 + eq4bat2mile;
                system("pause");
                system ("cls");
            }

             else if (opc == 6){
                system("cls");
                printf("Digite o tempo da equipe 5 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq5bat2min, &eq5bat2seg, &eq5bat2mile);
                printf("Tempo %d:%d:%d \n", eq5bat2min, eq5bat2seg, eq5bat2mile);
                min5bat2 = eq5bat2min*60000;
                seg5bat2 = eq5bat2seg*1000;
                mele5bat2 = min5bat2 + seg5bat2 + eq5bat2mile;
                system("pause");
                system("cls");
             }
            }
            }
            break;
            system ("cls");

    case 4:
            system ("cls");
            {
            int opc;
            char lista[11][40]={ "DIGITE O TEMPO DA BATERIA 3 DE CADA UMA DAS EQUIPES:\n","1. Tempo da Equipe 1 na bateria 3:","2. Tempo da Equipe 2 na bateria 3:","3. Tempo da Equipe 3 na bateria 3:","4. Tempo da Equipe 4 na bateria 3:","5. Tempo da Equipe 5 na bateria 3:", "6.Voltar ao menu principal"};

            setlocale(LC_ALL,"");
            while(true)
            {
            opc = menu(10,10,8,lista);

            if (opc==7)
            {
            system("pause");
            system("cls");
            break;
            }

            linhaCol(1,1);
            textColor(WHITE, _RED);
            //printf("\nEscolheu a op��o %d", opc);

            textColor(WHITE, _BLACK);
            linhaCol(24,1);
            printf("");

            if (opc == 1){
                system("pause");
                system ("cls");
            }
            else if (opc == 2){
                system("cls");
                printf("Digite o tempo da equipe 1 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq1bat3min, &eq1bat3seg, &eq1bat3mile);
                printf("Tempo %d:%d:%d \n", eq1bat3min, eq1bat3seg, eq1bat3mile);
                min1bat3 = eq1bat3min * 60000;
                seg1bat3 = eq1bat3seg * 1000;
                mele1bat3 = min1bat3 + seg1bat3 + eq1bat3mile;
                system("pause");
                system ("cls");

                }

            else if (opc == 3){
                system("cls");
                printf("Digite o tempo da equipe 2 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq2bat3min, &eq2bat3seg, &eq2bat3mile);
                printf("Tempo %d:%d:%d \n", eq2bat3min, eq2bat3seg, eq2bat3mile);
                min2bat3 = eq2bat3min * 60000;
                seg2bat3 = eq2bat3seg * 1000;
                mele2bat3 = min2bat3 + seg2bat3 + eq2bat3mile;
                system("pause");
                system ("cls");
            }
            else if (opc == 4){
                system("cls");
                printf("Digite o tempo da equipe 3 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq3bat3min, &eq3bat3seg, &eq3bat3mile);
                printf("Tempo %d:%d:%d \n", eq3bat3min, eq3bat3seg, eq3bat3mile);
                min3bat3 = eq3bat3min * 60000;
                seg3bat3 = eq3bat3seg * 1000;
                mele3bat3 = min3bat3 + seg3bat3 + eq3bat3mile;
                system("pause");
                system ("cls");
            }

            else if (opc == 5){
                system("cls");
                printf("Digite o tempo da equipe 4 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq4bat3min, &eq4bat3seg, &eq4bat3mile);
                printf("Tempo %d:%d:%d \n", eq4bat3min, eq4bat3seg, eq4bat3mile);
                min4bat3 = eq4bat3min * 60000;
                seg4bat3 = eq4bat3seg * 1000;
                mele4bat3 = min4bat3 + seg4bat3 + eq4bat3mile;
                system("pause");
                system ("cls");
            }

             else if (opc == 6){
                system("cls");
                printf("Digite o tempo da equipe 5 na seguinte forma: (minutos:segundos:milisegundos) \n");
                scanf("%d%d%d", &eq5bat3min, &eq5bat3seg, &eq5bat3mile);
                printf("Tempo %d:%d:%d \n", eq5bat3min, eq5bat3seg, eq5bat3mile);
                min5bat3 = eq5bat3min * 60000;
                seg5bat3 = eq5bat3seg * 1000;
                mele5bat3 = min5bat3 + seg5bat3 + eq5bat3mile;
                system("pause");
                system("cls");
             }
            }
            }

            break;
            system ("cls");


    case 5:

            printf("CLASSIFICA��O GERAL POR EQUIPES\n\n");


            //formula para pegar os 2 melhores tempos

            //equipe 01 ver qal os maiores tempos.mele1bat1, mele1bat2, mele1bat3

            pmaior1 = mele1bat1;
            if (mele1bat2>=pmaior1){
                smaior1=pmaior1;
                pmaior1=mele1bat2;
            }else{
            smaior1=mele1bat2;
            }
            if (mele1bat3>=pmaior1){
                smaior1=pmaior1;
                pmaior1=mele1bat3;
            }else
            if(mele1bat3>=smaior1){
                smaior1=mele1bat3;
            }

            //equipe 02 ver qal os maiores tempos.mele2bat1, mele2bat2, mele2bat3

            pmaior2 = mele2bat1;
            if (mele2bat2>=pmaior2){
                smaior2=pmaior2;
                pmaior2=mele2bat2;
            }else{
            smaior2=mele2bat2;
            }
            if (mele2bat3>=pmaior2){
                smaior2=pmaior2;
                pmaior2=mele2bat3;
            }else
            if(mele2bat3>=smaior2){
                smaior2=mele2bat3;
            }

            //equipe 03 ver qal os maiores tempos, mele3bat1, mele3bat2, mele3bat3

            pmaior3 = mele3bat1;
            if (mele3bat2>=pmaior3){
                smaior3=pmaior3;
                pmaior3=mele3bat2;
            }else{
            smaior3=mele3bat2;
            }
            if (mele3bat3>=pmaior3){
                smaior3=pmaior3;
                pmaior3=mele3bat3;
            }else
            if(mele3bat3>=smaior3){
                smaior3=mele3bat3;
            }

            //equipe 04 ver qal os maiores tempos, mele4bat1, mele4bat2, mele4bat3

             pmaior4 = mele4bat1;
            if (mele4bat2>=pmaior4){
                smaior4=pmaior4;
                pmaior4=mele4bat2;
            }else{
            smaior4=mele4bat2;
            }
            if (mele4bat3>=pmaior4){
                smaior4=pmaior4;
                pmaior4=mele4bat3;
            }else
            if(mele4bat3>=smaior4){
                smaior4=mele4bat3;
            }

             //equipe 04 ver qal os maiores tempos,mele5bat1, mele5bat2, mele5bat3

             pmaior5 = mele5bat1;
            if (mele5bat2>=pmaior5){
                smaior5=pmaior5;
                pmaior5=mele5bat2;
            }else{
            smaior5=mele5bat2;
            }
            if (mele5bat3>=pmaior5){
                smaior5=pmaior5;
                pmaior5=mele5bat3;
            }else
            if(mele5bat3>=smaior5){
                smaior5=mele5bat3;
            }

          //achando a media entre os 2 melhores tempos

            media1 = (pmaior1 + smaior1)/2;
            media2 = (pmaior2 + smaior2)/2;
            media3 = (pmaior3 + smaior3)/2;
            media4 = (pmaior4 + smaior4)/2;
            media5 = (pmaior5 + smaior5)/2;

            //passando milesegundos para minutos:segudos:milesegundos

            min1 = (media1/60000);
            seg1 = (media1%60000)/1000;
            mm1 = (media1%60000)%1000;

            min2 = (media2/60000);
            seg2 = (media2%60000)/1000;
            mm2 = (media2%60000)%1000;

            min3 = (media3/60000);
            seg3 = (media3%60000)/1000;
            mm3 = (media3%60000)%1000;

            min4 = (media4/60000);
            seg4 = (media4%60000)/1000;
            mm4 = (media4%60000)%1000;

            min5 = (media5/60000);
            seg5 = (media5%60000)/1000;
            mm5 = (media5%60000)%1000;

            int v [5] = {media1, media2, media3, media4, media5};//colocara em ordem crescente a classificação.
int aux;
int x,y;

for(x=0;x<4;x++)
{
for(y=x+1; y<=4; y++)
{
if(v[y]<v[x])
{
aux=v[y];
v[y]=v[x];
v[x]=aux;


}
}
}
            for (i=0; i<=4;i++){


                if( v[i] == media1){
                    printf(" Equipe 1 com o tempo em milesegundos de %d\n\n ",v[i]);
                }
                else{
                    if( v[i] == media2)
                    {
                    printf(" Equipe 2 com o tempo em milesegundos de %d\n\n ",v[i]);
                    }
                    else{
                    if( v[i] == media3)
                    {
                    printf(" Equipe 3 com o tempo em milesegundos de %d\n\n ",v[i]);
                    }
                    else{
                    if( v[i] == media4)
                    {
                    printf(" Equipe 4 com o tempo em milesegundos de %d\n\n ",v[i]);
                    }
                    else{
                    if( v[i] == media5)
                    {
                    printf(" Equipe 5 com o tempo em milesegundos de %d\n\n ",v[i]);
                    }
                }
                }
                }
                }

            }

            system("pause");
            system("cls");
            break;



    case 6:

    system("cls");
            printf("5. Exportar classificação geral \n");

            FILE *arq;

            arq = fopen("Classificação Geral por Equipes.txt", "w");

            fprintf(arq,"\n Equipe 01 tempo de :%d\n Equipe 02 tempo de :%d\n Equipe 03 tempo de :%d\n Equipe 04 tempo de :%d\n Equipe 05 tempo de :%d\n", media1, media2, media3, media4, media5);


            fclose(arq);

            system("pause");
            system("cls");
            break;


    printf("\n\tPressione ENTER para continuar!\n");
    getchar();
    }
}

return 0;
}

