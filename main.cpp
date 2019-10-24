#include <iostream>
#include <cstring>

using namespace std;

class Operacao {
#include <iostream>

#define tam 200
public:
    char txt[tam];
    char pimm[tam];
    char piN[tam];
    int po;
    int ip = 0;
    int mm = 0;
    int vN = 0;
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

    char desempilhaN() {
        int a = vN;
        vN--;
        return piN[a];
    }

    void empilhaMM(char o) {
        pimm[mm] = o;
        mm++;
    }

    char desempilhaMM() {
        int a = mm;
        mm--;
        return pimm[a];
    }

    void conta(char* str,int p) {
        strcpy(txt,str);
        po = p;
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
                desempilhaMM();
            }
            po++;
        }
        else if(txt[po] == '+' || txt[po] == '-'){
            if(mm == 0){
                prio = false;
                //empilhaMM(txt[po]);
            }
            else{
                desempilhaMM();
            }
            po++;
        }
        else if(txt[po] == '('){
            Operacao op;
            op.conta(txt,po);

        }
    }
};


int main() {
    /*
    puts("insira uma expressão");
    scanf("%[^\n]", txt);
    fflush(stdin);
    ea();
     */
    return 0;
}