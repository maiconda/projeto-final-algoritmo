#include <stdio.h>
#include <string.h>

#define M 20
#define N 20
#define W 9
#define ML 30

struct Finded {
    char word[ML];
    int x1;
    int y1;
    int x2;
    int y2;
};

void topVerify(char[][N], char[], int, int, int, int*, struct Finded*, int*);
void bottomVerify(char[][N], char[], int, int, int, int*, struct Finded*, int*);
void rightVerify(char[][N], char[], int, int, int, int*, struct Finded*, int*);
void leftVerify(char[][N], char[], int, int, int, int*, struct Finded*, int*);
void topRightVerify(char[][N], char[], int, int, int, int*, struct Finded*, int*);
void topLeftVerify(char[][N], char[], int, int, int, int*, struct Finded*, int*);
void bottomLeftVerify(char[][N], char[], int, int, int, int*, struct Finded*, int*);
void bottomRightVerify(char[][N], char[], int, int, int, int*, struct Finded*, int*);
int principalVerify(char[][N], char[], struct Finded*, int*);
int convertString(char[], char[][N]);
void printWords(int*, struct Finded*);

int main() {
    char gradeString[] = "AZOAAOAVAFAZOTTOAVACALPADUMVUGAOPADUMVOGTTGAAOASOETIEAAOAMOEATJOVPRARRATJLVSPARRJAOARRATSTJAOAAURPSTAOJALIVRYIAOJATPVAAIONRLMETFAOONRAMMEFUOPAPPTVAMNLPACPTAANNAOVTSTOUROAEAAAPCURAAAOTTRAASSSOLWTRAASNPAZOATOAVA  ZEQROAVAFAOPADUMVNGANPPPUMVUGTREAAOAOOETROAIZASOEARJLVMTARRARJTVPVARRJAOACAZINAGROOAREBSTAOJA LVAAIAOJAL PDNIONRDMEEFUOONRLMEDFOOPDEDICACAOPAPPTVAENAOZATTOURAAOVATIOTRZAAOTTRAASNPAOTTRAASNO";
    char grade[M][N];
    char words[W][ML] = {
        "PARALELEPIPEDO",
        "ALGORITMOS NOTA DEZ",
        "COMPUTACAO NOTA DEZ",
        "DEDICACAO",
        "CAMPUS",
        "ORGANIZACAO",
        "SOL",
        "LOSS",
        "ATENCAO"
    };
    
    struct Finded findedWords[W * 3];
    int findedCounter = 0;
    
    if (convertString(gradeString, grade) == 1) {
        for (int i = 0; i < W; i++) {
            if (principalVerify(grade, words[i], findedWords, &findedCounter) == 0){
                strcpy(findedWords[findedCounter].word, words[i]);
                findedWords[findedCounter].x1 = 0;
                findedWords[findedCounter].y1 = 0;
                findedWords[findedCounter].x2 = 0;
                findedWords[findedCounter].y2 = 0;
                findedCounter++;
            }
        }
        
        printWords(&findedCounter, findedWords);
        
    } else {
        printf("Por favor, adicione uma matriz válida");
    }

    return 0;
}

void topVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter, struct Finded* findedWords, int *findedCounter) {
    int wordCounter = 0, k;

    for (k = i; k > i - length; k--) {
        if (grade[k][j] == word[wordCounter]) {
            wordCounter++;
        } else {
            return;
        }
    }
    
    strcpy(findedWords[*findedCounter].word, word);
    findedWords[*findedCounter].x1 = i;
    findedWords[*findedCounter].y1 = j;
    findedWords[*findedCounter].x2 = i - length + 1;
    findedWords[*findedCounter].y2 = j;
    (*findedCounter)++;
    (*verifyCounter)++;

}

void bottomVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter, struct Finded* findedWords, int *findedCounter) {
    int wordCounter = 0, k;

    for (k = i; k < i + length; k++) {
        if (grade[k][j] == word[wordCounter]) {
            wordCounter++;
        } else {
            return;
        }
    }

    strcpy(findedWords[*findedCounter].word, word);
    findedWords[*findedCounter].x1 = i;
    findedWords[*findedCounter].y1 = j;
    findedWords[*findedCounter].x2 = i + length - 1;
    findedWords[*findedCounter].y2 = j;
    (*findedCounter)++;
    (*verifyCounter)++;
}

void rightVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter, struct Finded* findedWords, int *findedCounter) {
    int wordCounter = 0, k;

    for (k = j; k < j + length; k++) {
        if (grade[i][k] == word[wordCounter]) {
            wordCounter++;
        } else {
            return;
        }
    }

    strcpy(findedWords[*findedCounter].word, word);
    findedWords[*findedCounter].x1 = i;
    findedWords[*findedCounter].y1 = j;
    findedWords[*findedCounter].x2 = i;
    findedWords[*findedCounter].y2 = j + length - 1;
    (*findedCounter)++;
    (*verifyCounter)++;
}

void leftVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter, struct Finded* findedWords, int *findedCounter) {
    int wordCounter = 0, k;

    for (k = j; k > j - length; k--) {
        if (grade[i][k] == word[wordCounter]) {
            wordCounter++;
        } else {
            return;
        }
    }
    
    strcpy(findedWords[*findedCounter].word, word);
    findedWords[*findedCounter].x1 = i;
    findedWords[*findedCounter].y1 = j;
    findedWords[*findedCounter].x2 = i;
    findedWords[*findedCounter].y2 = j - length + 1;
    (*findedCounter)++;
    (*verifyCounter)++;
}

void topRightVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter, struct Finded* findedWords, int *findedCounter) {
    int wordCounter = 0, k, l = i;

    for (k = j; k < j + length; k++) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        } else {
            return;
        }
        l--;
    }

    strcpy(findedWords[*findedCounter].word, word);
    findedWords[*findedCounter].x1 = i;
    findedWords[*findedCounter].y1 = j;
    findedWords[*findedCounter].x2 = i - length + 1;
    findedWords[*findedCounter].y2 = j + length - 1;
    (*findedCounter)++;
    (*verifyCounter)++;
}

void topLeftVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter, struct Finded* findedWords, int *findedCounter) {
    int wordCounter = 0, k, l = i;

    for (k = j; k > j - length; k--) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        } else {
            return;
        }
        l--;
    }

    strcpy(findedWords[*findedCounter].word, word);
    findedWords[*findedCounter].x1 = i;
    findedWords[*findedCounter].y1 = j;
    findedWords[*findedCounter].x2 = i - length + 1;
    findedWords[*findedCounter].y2 = j - length + 1;
    (*findedCounter)++;
    (*verifyCounter)++;
}

void bottomLeftVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter, struct Finded* findedWords, int *findedCounter) {
    int wordCounter = 0, k, l = i;

    for (k = j; k > j - length; k--) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        } else {
            return;
        }
        l++;
    }
    
    strcpy(findedWords[*findedCounter].word, word);
    findedWords[*findedCounter].x1 = i;
    findedWords[*findedCounter].y1 = j;
    findedWords[*findedCounter].x2 = i + length - 1;
    findedWords[*findedCounter].y2 = j - length + 1;
    (*findedCounter)++;
    (*verifyCounter)++;
}

void bottomRightVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter, struct Finded* findedWords, int *findedCounter) {
    int wordCounter = 0, k, l = i;

    for (k = j; k < j + length; k++) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        } else {
            return;
        }
        l++;
    }

    strcpy(findedWords[*findedCounter].word, word);
    findedWords[*findedCounter].x1 = i;
    findedWords[*findedCounter].y1 = j;
    findedWords[*findedCounter].x2 = i + length - 1;
    findedWords[*findedCounter].y2 = j + length - 1;
    (*findedCounter)++;
    (*verifyCounter)++;
}

int principalVerify(char grade[M][N], char *word, struct Finded* findedWords, int *findedCounter) {
    int length = strlen(word);
    int verifyCounter = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grade[i][j] == word[0]) {
                topVerify(grade, word, i, j, length, &verifyCounter, findedWords, findedCounter);
                topLeftVerify(grade, word, i, j, length, &verifyCounter, findedWords, findedCounter);
                topRightVerify(grade, word, i, j, length, &verifyCounter, findedWords, findedCounter);
                bottomVerify(grade, word, i, j, length, &verifyCounter, findedWords, findedCounter);
                bottomLeftVerify(grade, word, i, j, length, &verifyCounter, findedWords, findedCounter);
                bottomRightVerify(grade, word, i, j, length, &verifyCounter, findedWords, findedCounter);
                rightVerify(grade, word, i, j, length, &verifyCounter, findedWords, findedCounter);
                leftVerify(grade, word, i, j, length, &verifyCounter, findedWords, findedCounter);
            }
        }
    }
    
    if(verifyCounter == 0){
        return 0;
    } else {
        return 1;
    }
}

int convertString(char *gradeString, char grade[M][N]) {
    int k = 0, length = strlen(gradeString);

    if (length != M * N) {
        return 0;
    } else {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                grade[i][j] = gradeString[k];
                k++;
            }
        }
        return 1;
    }
}

void printWords(int *findedCounter, struct Finded* findedWords){
    for (int i = 0; i < *findedCounter; i++) {
        printf("%s - [%d][%d], [%d][%d]\n", findedWords[i].word, findedWords[i].x1, findedWords[i].y1, findedWords[i].x2, findedWords[i].y2);
    }
}
