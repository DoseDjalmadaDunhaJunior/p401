#include <iostream>
#include <cstring>

using namespace std;

class Operacao {
#define tam 200
public:
    char txt[tam];
    char pimm[tam];
    char piN[tam];
    int po;
    int tamanhoT;
    int ip = 0;
    int mm = 0;
    int vN = 0;
    char* ver;
    bool prio = false;

    char* imprime(){
        if(true){

        }
        printf("LDA %c\n"
               "conta algo%c\n"
               "STA %c\n", piN[0],piN[1]);

        return "t1";
    }

    void empilhaN(char n) {
        piN[vN] = n;
        vN++;
    }

    void desempilhaGeral(){
        if(pimm[0] == '+'){
            printf("LDA %c\n"
                   "ADA %c\n"
                   "STA T%i\n\n", piN[0],piN[1],tamanhoT+1);
            vN = 0;
            mm--;
        }
        else if(pimm[0] == '-'){
            printf("LDA %c\n"
                   "SUB %c\n"
                   "STA T%i\n\n", piN[0],piN[1],tamanhoT+1);
            vN = 0;
            mm--;
        }
        else if((mm == 1) && (pimm[0] == '*')){
            printf("LDA %c\n"
                   "MUL %c\n"
                   "STA T%i\n\n", piN[0],piN[1],tamanhoT+1);
            vN = 0;
            mm--;
        }
        else if((mm == 1) && (pimm[0] == '/')){
            printf("LDA %c\n"
                   "DIV %c\n"
                   "STA T%i\n\n", piN[0],piN[1],tamanhoT+1);
            vN = 0;
            mm--;
        }
        else if((pimm[0] == '*' || pimm[0] == '/') && (mm > 1) && (pimm[1] == '*')){

        }



    }

    void empilhaMM(char o) {
        pimm[mm] = o;
        mm++;
    }

    char desempilhaMM() {
        int a = mm;
        mm--;
        imprime();
        return pimm[a];
    }

    void conta(char* str,int p,int size) {
        if(po == 1){

        }

        tamanhoT = size;
        strcpy(txt,str);
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
    }

private:

    void conta(){
        char ver = txt[po];
        if(txt[po] == ')'){
            po++;
        }

        if(!prio && vN == 2){
            desempilhaGeral();
        }
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
            po++;
            op.conta(txt,po,tamanhoT);

        }
        if(txt[po] == 0){
            desempilhaGeral();
        }
        if(vN > 0 || mm > 0){
            conta();
        }

    }

};


int main() {
    Operacao oi;
    char* tt = "8+(5-7)-4";
    oi.conta(tt,0,0);
    return 0;
}