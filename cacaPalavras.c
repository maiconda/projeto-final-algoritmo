#include <stdio.h>
#include <string.h>
#define M 10
#define N 10
#define W 7
#define MAX_LENGHT 10

void topVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    
    int wordCounter = 0, k;
    
    for (k = i; k > i - length; k--) {
        if (grade[k][j] == word[wordCounter]) {
            wordCounter++;
        }
    }
    if (wordCounter == length) {
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, k+1, j);
        (*verifyCounter)++;
    }
}

void bottomVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    
    int wordCounter = 0, k;
    
    for (k = i; k < i + length; k++) {
        if (grade[k][j] == word[wordCounter]) {
            wordCounter++;
        }
    }
    
    if (wordCounter == length) {
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, k-1, j);
        (*verifyCounter)++;
    }
}

void rightVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    
    int wordCounter = 0, k;
    
    for (k = j; k < j + length; k++) {
        if (grade[i][k] == word[wordCounter]) {
            wordCounter++;
        }
    }
    if (wordCounter == length) {
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i, k-1);
        (*verifyCounter)++;
    }
}

void leftVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    
    int wordCounter = 0, k;
    
    for (k = j; k > j - length; k--) {
        if (grade[i][k] == word[wordCounter]) {
            wordCounter++;
        }
    }
    if (wordCounter == length) {
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i, k+1);
        (*verifyCounter)++;
    }
}

void topRightVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    
    int wordCounter = 0, k, l = i;
    
    for (k = j; k < j + length; k++) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        }
        l--;
    }
    if (wordCounter == length) {
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, l+1, k-1);
        (*verifyCounter)++;
    }
}

void topLeftVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    
    int wordCounter = 0, k, l = i;
    
    for (k = j; k > j - length; k--) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        }
        l--;
    }
    if (wordCounter == length) {
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, l+1, k+1);
        (*verifyCounter)++;
    }
}

void bottomLeftVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    
    int wordCounter = 0, k, l = i;
    
    for (k = j; k > j - length; k--) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        }
        l++;
    }
    if (wordCounter == length) {
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, l-1, k+1);
        (*verifyCounter)++;
    }
}

void bottomRightVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    
    int wordCounter = 0, k, l = i;
    
    for (k = j; k < j + length; k++) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        }
        l++;
    }
    if (wordCounter == length) {
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, l-1, k-1);
        (*verifyCounter)++;
    }
}

void principalVerify(char grade[M][N], char *word) {
    
    int lenght = strlen(word), verifyCounter = 0;
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if(grade[i][j] == word[0]){
                
                if(i >= lenght-1){
                    topVerify(grade, word, i, j, lenght, &verifyCounter);
                    if(j >= lenght-1)
                         topLeftVerify(grade, word, i, j, lenght, &verifyCounter);
                    if(N-j >= lenght)
                         topRightVerify(grade, word, i, j, lenght, &verifyCounter);
                }
                
                if(M-i >= lenght){
                    bottomVerify(grade, word, i, j, lenght, &verifyCounter);
                    if(j >= lenght-1)
                         bottomLeftVerify(grade, word, i, j, lenght, &verifyCounter);
                    if(N-j >= lenght)
                         bottomRightVerify(grade, word, i, j, lenght, &verifyCounter);
                  }
                  
                if(N-j >= lenght)
                     rightVerify(grade, word, i, j, lenght, &verifyCounter);
                if(j >= lenght-1)
                     leftVerify(grade, word, i, j, lenght, &verifyCounter);
            }
        }
    }
    
    if(verifyCounter == 0){
        printf("%s - [%d][%d], [%d][%d]\n", word, 0, 0, 0, 0);
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
