#include <iostream>
#include <cstring>

using namespace std;

class Operacao {
#define tam 200
public:
    char txt[tam];
    char pimm[tam];
    char piN[tam];
    char T[tam];
    int po;
    int tamanhoT;
    int ip = 0;
    int mm = 0;
    int vN = 0;
    char* ver;
    bool prio = false;


    //força o vetor T ficar com as letras
    void forca(){
        for (int i = 65; i < 91; i++) {
            T[i-65] = i;
        }
    }

    //pode apagar a funçao abaixo
    char* imprime(){
        if(true){

        }
        printf("LDA %c\n"
               "conta algo%c\n"
               "STA %c\n", piN[0],piN[1]);

        return "t1";
    }

    //empilha os numeros
    void empilhaN(char n) {
        piN[vN] = n;
        vN++;
    }

    //desempilha os pilhas e imprime (tem que arrumar um pouco ainda)
    void desempilhaGeral(){

        if(pimm[0] == '+'){
            tamanhoT++;
            T[tamanhoT] = T[tamanhoT-1] + 1;
            printf("LDA %c\n"
                   "ADA %c\n"
                   "STA %c\n\n", piN[0],piN[1],T[tamanhoT]);
            vN = 0;
            mm--;
        }
        else if(pimm[0] == '-'){
            printf("LDA %c\n"
                   "SUB %c\n"
                   "STA %c\n\n", piN[0],piN[1],T[tamanhoT]);
            vN = 0;
            mm--;
        }
        else if((mm == 1) && (pimm[0] == '*')){
            printf("LDA %c\n"
                   "MUL %c\n"
                   "STA %c\n\n", piN[0],piN[1],T[tamanhoT]);
            vN = 0;
            mm--;
        }
        else if((mm == 1) && (pimm[0] == '/')){
            printf("LDA %c\n"
                   "DIV %c\n"
                   "STA %c\n\n", piN[0],piN[1],T[tamanhoT]);
            vN = 0;
            mm--;
        }
        else if((pimm[0] == '*' || pimm[0] == '/') && (mm > 1) && (pimm[1] == '*')){

    }

    }

    //empilha os sinais
    void empilhaMM(char o) {
        pimm[mm] = o;
        mm++;
    }

    int conta(char* str,int p,int size,char* algo) {
        forca();
        if(po == 1){

        }
        for (int i = 0; i < 10; i++) {
            cout<<algo[i];
        }

        puts("");
        tamanhoT = size;
        strcpy(txt,str);
        strcpy(T,algo);
        po = p;
        char ver = txt[po];

        if ((txt[po] >= '0' && txt[po] <= '9')) {
            empilhaN(txt[po]);
            po++;
        }
        else if(txt[po] == '*' || txt[po] == '/'){
            if(mm == 0 || !prio){
                empilhaMM(txt[po]);
                prio = true;
            }
            else{
                //desempilhaMM();
            }
            po++;
        }
        else if(txt[po] == '+' || txt[po] == '-'){
            if(mm == 0){
                prio = false;
                empilhaMM(txt[po]);
            }
            else{
                //desempilhaMM();
            }
            po++;
        }
        else if(txt[po] == '('){
            Operacao op;
            //op.conta(txt,po);
        }
        if(vN >0 || mm > 0){
            conta();
        }
        return tamanhoT;
    }

private:

    // essa conta no private serve para ficar no loop ate acabar o vetor
    int conta(){
        char ver = txt[po];
        //aqui identifica quando acaba as chafes e acaba a classe
        if(txt[po] == ')'){
            po++;
        }

        //ele identifica quando a prioridade da pilha é violada ou quando ja tem muito numero (mas aqui ainda esta errado)
        if(!prio && vN == 2){
            desempilhaGeral();
        }
        //identifica numero
        if ((txt[po] >= '0' && txt[po] <= '9')) {
            empilhaN(txt[po]);
            po++;
        }
        //identifica vezes ou divide
        else if(txt[po] == '*' || txt[po] == '/'){
            if(mm == 0 || !prio){
                empilhaMM(txt[po]);
                prio = true;
            }
            else{
                //desempilhaMM();
            }
            po++;
        }
        //identifica mais ou menos
        else if(txt[po] == '+' || txt[po] == '-'){
            if(mm == 0){
                prio = false;
                empilhaMM(txt[po]);
            }
            else{
                //desempilhaMM();
            }
            po++;
        }
        //identifica quando abre chave e abre uma nova classe
        else if(txt[po] == '('){
            Operacao op;
            po++;
            op.conta(txt,po,tamanhoT,T);

        }
        //identifica quando acaba o vetor
        if(txt[po] == 0){
            desempilhaGeral();
        }
        //faz a recursao
        if(vN > 0 || mm > 0){
            conta();
        }

        return tamanhoT;
    }

};


int main() {
    Operacao oi;
    char y[tam];
    char* tt = "3*(5-2+6-(3*5)+1)-2";
    //char* tt = "3*8";
    oi.conta(tt,0,0,y);

    return 0;
}