#include <stdio.h>
#include <string.h>

#define M 10
#define N 10
#define W 7
#define ML 10

void topVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    int wordCounter = 0, k;

    for (k = i; k > i - length; k--) {
        if (grade[k][j] == word[wordCounter]) {
            wordCounter++;
        }
    }

    if (wordCounter == length) {
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i - length + 1, j);
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
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i + length - 1, j);
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
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i, j + length - 1);
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
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i, j - length + 1);
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
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i - length + 1, j + length - 1);
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
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i - length + 1, j - length + 1);
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
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i + length - 1, j - length + 1);
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
        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i + length - 1, j + length - 1);
        (*verifyCounter)++;
    }
}

int principalVerify(char grade[M][N], char *word) {
    int length = strlen(word);
    int verifyCounter = 0;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grade[i][j] == word[0]) {
                topVerify(grade, word, i, j, length, &verifyCounter);
                topLeftVerify(grade, word, i, j, length, &verifyCounter);
                topRightVerify(grade, word, i, j, length, &verifyCounter);
                bottomVerify(grade, word, i, j, length, &verifyCounter);
                bottomLeftVerify(grade, word, i, j, length, &verifyCounter);
                bottomRightVerify(grade, word, i, j, length, &verifyCounter);
                rightVerify(grade, word, i, j, length, &verifyCounter);
                leftVerify(grade, word, i, j, length, &verifyCounter);
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

int main() {
    char gradeString[] = "SAPAACAVAAAAPADAVUUJTAPAAPASONASJAVMVARAJPOATRRASRAOJALORAAAOPAOMOUPSLPAPPMVAUAAOATALSVAPAAOTTRAASOP";
    char grade[M][N];
    char words[W][ML] = {
        "SAPATO",
        "UVA",
        "LARANJA",
        "PAO",
        "AMORA",
        "SAPO",
        "SOPA"
    };
    
    //Ao adicionar ou remover palavras na matriz words, é necessário adaptar o valor da constante W localizada na linha 6 :)

    if (convertString(gradeString, grade) == 1) {
        for (int i = 0; i < W; i++) {
            if (principalVerify(grade, words[i]) == 0){
                printf("%s - [0][0], [0][0]\n", words[i]);
            }
        }
    } else {
        printf("Por favor, adicione uma matriz válida");
    }

    return 0;
}
