#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#define DISCOS 6
using namespace std;
void imprimeMatriz(char matriz[][3], int pos1, int pos2){
    cout << "move disco de: " << pos1+1 << " --> " << pos2+1 << endl;
    for(int i=0; i<DISCOS; i++){
        for(int j=0; j<3; j++){
            cout << setw(3) << matriz[i][j];
        }
        cout << endl;
    }
    cout<<"===================="<<endl;
    cout<<"enter para continuar";
    cin.get();
    system("clear");

}

void moverDisco(int daqui, int praca,char  matriz[][3]){

    int discoAcima = 0;
    for (int i = 0; i < DISCOS; i++){
        if (matriz[i][daqui]!='*'){
            discoAcima = i;
            break;
        }
        
    }
    
    
    char disco = matriz[discoAcima][daqui];
    int posvazioa = 0;
    for (int i = DISCOS; i !=0; i--){
        if (matriz[i][praca]=='*'){
            posvazioa = i;
            break;
        }
        
    }
    
    matriz[posvazioa][praca]=disco;
    matriz[discoAcima][daqui]='*';


    imprimeMatriz(matriz, daqui, praca);

    
}

int char2Line(char c){
    if(c=='A'){
        return 0;
    }
    if(c=='B'){
        return 1;
    }
    if(c=='C'){
        return 2;
    }
    return -1;

}
void hanoi(int discos, char a, char b, char c, char matriz[][3]){
    if(discos == 1){
        moverDisco(char2Line(a),char2Line(c),matriz);

        return;
    }
    hanoi(discos-1, a, c, b,matriz);

    moverDisco(char2Line(a),char2Line(c),matriz);
    hanoi(discos-1, b, a, c,matriz);



 
}
void constroimatriz(int discos, char matriz[][3]){
    for(int i=0; i<DISCOS; i++){
        for(int j=0; j<3; j++){
            matriz[i][j]='*';
        }
    }
    for(int i=0; i<DISCOS; i++){
        matriz[i][0]=i+'A';
    }
    
}
int main(){
    char matriz[DISCOS][3];

    constroimatriz(DISCOS,matriz);
     system("clear");
    imprimeMatriz(matriz,-1,-1);
    hanoi(DISCOS, 'A', 'B', 'C',matriz);
    return 0;
}