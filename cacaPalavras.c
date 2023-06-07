#include <stdio.h>
#include <string.h>
#define M 10
#define N 10
#define W 7
#define MAX_LENGHT 10

void topVerify(char grade[M][N], char *word, int i, int j, int length) {
    
    int wordCounter = 0;
    int k;
    
    for (k = i; k > i - length; k--) {
        if (grade[k][j] == word[wordCounter]) {
            wordCounter++;
        }
    }
    if (wordCounter == length) {
        printf("ACHAMOS A PALAVRA %s - INICIO [%d][%d] - FIM [%d][%d]\n", word, i+1, j+1, k+2, j+1);
    }
}

void bottomVerify(char grade[M][N], char *word, int i, int j, int length) {
    
    int wordCounter = 0;
    int k;
    
    for (k = i; k < i + length; k++) {
        if (grade[k][j] == word[wordCounter]) {
            wordCounter++;
        }
    }
    if (wordCounter == length) {
        printf("ACHAMOS A PALAVRA %s - INICIO [%d][%d] - FIM [%d][%d]\n", word, i+1, j+1, k, j+1);
    }
}

void rightVerify(char grade[M][N], char *word, int i, int j, int length) {
    
    int wordCounter = 0;
    int k;
    
    for (k = j; k < j + length; k++) {
        if (grade[i][k] == word[wordCounter]) {
            wordCounter++;
        }
    }
    if (wordCounter == length) {
        printf("ACHAMOS A PALAVRA %s - INICIO [%d][%d] - FIM [%d][%d]\n", word, i+1, j+1, i+1, k);
    }
}

void leftVerify(char grade[M][N], char *word, int i, int j, int length) {
    
    int wordCounter = 0;
    int k;
    
    for (k = j; k > j - length; k--) {
        if (grade[i][k] == word[wordCounter]) {
            wordCounter++;
        }
    }
    if (wordCounter == length) {
        printf("ACHAMOS A PALAVRA %s - INICIO [%d][%d] - FIM [%d][%d]\n", word, i+1, j+1, i+1, k+2);
    }
}

void principalVerify(char grade[M][N], char *word) {
    
    int lenght = strlen(word);
    // printf("%s-%d\n", word, lenght);
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if(grade[i][j] == word[0]){
                
                if(i >= lenght-1){
                    
                    topVerify(grade, word, i, j, lenght);
                    // if(j >= lenght-1)
                    //      printf("verificar cima/esquerda\n");
                    // if(N-j >= lenght)
                    //      printf("verificar cima/direita\n");
                }
                
                if(M-i >= lenght){
                    bottomVerify(grade, word, i, j, lenght);
                    // if(j >= lenght-1)
                    //      printf("verificar baixo/esquerda\n");
                    // if(N-j >= lenght)
                    //      printf("verificar baixo/direita\n");
                  }
                  
                if(N-j >= lenght)
                     rightVerify(grade, word, i, j, lenght);
                if(j >= lenght-1)
                     leftVerify(grade, word, i, j, lenght);
            }
        }
    }
}

int main() {
    
    char grade[M][N] = {
        {'S', 'A', 'P', 'A', 'A', 'C', 'A', 'V', 'A', 'A'},
        {'A', 'A', 'P', 'A', 'D', 'A', 'V', 'U', 'U', 'J'},
        {'T', 'A', 'P', 'A', 'A', 'P', 'A', 'S', 'O', 'N'},
        {'A', 'S', 'J', 'A', 'V', 'M', 'V', 'A', 'R', 'A'},
        {'J', 'P', 'O', 'A', 'T', 'R', 'R', 'A', 'S', 'R'},
        {'A', 'O', 'J', 'A', 'L', 'O', 'R', 'A', 'A', 'A'},
        {'O', 'P', 'A', 'O', 'M', 'O', 'U', 'P', 'S', 'L'},
        {'P', 'A', 'P', 'P', 'M', 'V', 'A', 'U', 'A', 'A'},
        {'O', 'A', 'T', 'A', 'L', 'S', 'V', 'A', 'P', 'A'},
        {'A', 'O', 'T', 'T', 'R', 'A', 'A', 'S', 'O', 'P'}
    };
    
    char words[W][MAX_LENGHT] = {
        "SAPATO",
        "UVA",
        "LARANJA",
        "PAO",
        "AMORA",
        "SAPO",
        "SOPA"
    };
    
    for(int i=0; i<W; i++){
        principalVerify(grade, words[i]);
    }

    return 0;
}
