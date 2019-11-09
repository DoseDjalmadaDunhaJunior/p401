#include <iostream>
#include <cstring>

using namespace std;

class Operacao {
#define tam 200
public:
    char txt[tam];
    char pilhaNumeros[tam];
    char pilhaSinais[tam];
    char T[tam];
    int po;
    int tamanhoT;
    int posicaoNumeros = 0;
    int posicaoSinais = 0;
    int vN = 0;
    char* ver;
    bool prio = false;

    void desempilha(){
        if(pilhaSinais[0] == '+'){
            tamanhoT++;
            T[tamanhoT] = T[tamanhoT-1] + 1;
            printf("LDA %c\n"
                   "ADA %c\n"
                   "STA %c\n\n", pilhaNumeros[0],pilhaNumeros[1],T[tamanhoT]);
            vN = 0;
            posicaoSinais--;
        }
        else if(pilhaSinais[0] == '-'){
            printf("LDA %c\n"
                   "SUB %c\n"
                   "STA %c\n\n", pilhaNumeros[0],pilhaNumeros[1],T[tamanhoT]);
            vN = 0;
            posicaoSinais--;        }
        else if((posicaoSinais == 1) && (pilhaSinais[0] == '*')){
            printf("LDA %c\n"
                   "MUL %c\n"
                   "STA %c\n\n", pilhaNumeros[0],pilhaNumeros[1],T[tamanhoT]);
            vN = 0;
            posicaoSinais--;        }
        else if((posicaoSinais == 1) && (pilhaSinais[0] == '/')){
            printf("LDA %c\n"
                   "DIV %c\n"
                   "STA %c\n\n", pilhaNumeros[0],pilhaNumeros[1],T[tamanhoT]);
            vN = 0;
            posicaoSinais--;        }
    }

    int conta(char* vet,int po) {
        if (vet[po] == '*' && posicaoSinais == 0) {
            vet[posicaoSinais] = vet[po];
            posicaoSinais++;
        } else if (vet[po] == '*' && posicaoSinais == 1) {
            desempilha();
        } else if (vet[po] == '/' && posicaoSinais == 0) {
            posicaoSinais++;
        } else if (vet[po] == '/' && posicaoSinais == 1) {

        } else if (vet[po] == '+' && (posicaoSinais == 0 || (posicaoSinais == 1 && (vet[0] == '*' ||
                                                                                    vet[0] == '/')))) {
            posicaoSinais++;
        } else if (vet[po] == '-' && (posicaoSinais == 0 || (posicaoSinais == 1 && (vet[0] == '*' ||
                                                                                    vet[0] == '/')))) {
            posicaoSinais++;
        }
        po++;
    }
};


int main() {
    Operacao oi;
    char y[tam];
    char* tt = "3*(5-2+6-(3*5)+1)-2";
    //char* tt = "3*8";
    //oi.conta(tt,0,0,y);

    return 0;
}