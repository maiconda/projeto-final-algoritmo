#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define M 10
#define N 10
#define W 7
#define ML 10

int topVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    int wordCounter = 0, k;

    for (k = i; k > i - length; k--) {
        if (grade[k][j] == word[wordCounter]) {
            wordCounter++;
        }
    }

    if (wordCounter == length) {
        return 1;
    } else {
        return 0;
    }
}

int bottomVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    int wordCounter = 0, k;

    for (k = i; k < i + length; k++) {
        if (grade[k][j] == word[wordCounter]) {
            wordCounter++;
        }
    }

    if (wordCounter == length) {
        return 1;
    } else {
        return 0;
    }
}

int rightVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    int wordCounter = 0, k;

    for (k = j; k < j + length; k++) {
        if (grade[i][k] == word[wordCounter]) {
            wordCounter++;
        }
    }

    if (wordCounter == length) {
        return 1;
    } else {
        return 0;
    }
}

int leftVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    int wordCounter = 0, k;

    for (k = j; k > j - length; k--) {
        if (grade[i][k] == word[wordCounter]) {
            wordCounter++;
        }
    }

    if (wordCounter == length) {
        return 1;
    } else {
        return 0;
    }
}

int topRightVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    int wordCounter = 0, k, l = i;

    for (k = j; k < j + length; k++) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        }
        l--;
    }

    if (wordCounter == length) {
        return 1;
    } else {
        return 0;
    }
}

int topLeftVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    int wordCounter = 0, k, l = i;

    for (k = j; k > j - length; k--) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        }
        l--;
    }

    if (wordCounter == length) {
        return 1;
    } else {
        return 0;
    }
}

int bottomLeftVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    int wordCounter = 0, k, l = i;

    for (k = j; k > j - length; k--) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        }
        l++;
    }

    if (wordCounter == length) {
        return 1;
    } else {
        return 0;
    }
}

int bottomRightVerify(char grade[M][N], char *word, int i, int j, int length, int *verifyCounter) {
    int wordCounter = 0, k, l = i;

    for (k = j; k < j + length; k++) {
        if (grade[l][k] == word[wordCounter]) {
            wordCounter++;
        }
        l++;
    }

    if (wordCounter == length) {
        return 1;
    } else {
        return 0;
    }
}

void principalVerify(char grade[M][N], char *word) {
    int length = strlen(word);
    int verifyCounter = 0;
    printf("\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grade[i][j] == word[0]) {
                if (i >= length - 1) {
                    if (topVerify(grade, word, i, j, length, &verifyCounter) == 1) {
                        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i - length + 1, j);
                        verifyCounter++;
                    }
                    if (j >= length - 1) {
                        if (topLeftVerify(grade, word, i, j, length, &verifyCounter) == 1) {
                            printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i - length + 1, j - length + 1);
                            verifyCounter++;
                        }
                    }
                    if (N - j >= length) {
                        if (topRightVerify(grade, word, i, j, length, &verifyCounter) == 1) {
                            printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i - length + 1, j + length - 1);
                            verifyCounter++;
                        }
                    }
                }
                if (M - i >= length) {
                    if (bottomVerify(grade, word, i, j, length, &verifyCounter) == 1) {
                        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i + length - 1, j);
                        verifyCounter++;
                    }
                    if (j >= length - 1) {
                        if (bottomLeftVerify(grade, word, i, j, length, &verifyCounter) == 1) {
                            printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i + length - 1, j - length + 1);
                            verifyCounter++;
                        }
                    }
                    if (N - j >= length) {
                        if (bottomRightVerify(grade, word, i, j, length, &verifyCounter) == 1) {
                            printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i + length - 1, j + length - 1);
                            verifyCounter++;
                        }
                    }
                }
                if (N - j >= length) {
                    if (rightVerify(grade, word, i, j, length, &verifyCounter) == 1) {
                        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i, j + length - 1);
                        verifyCounter++;
                    }
                }
                if (j >= length - 1) {
                    if (leftVerify(grade, word, i, j, length, &verifyCounter) == 1) {
                        printf("%s - [%d][%d], [%d][%d]\n", word, i, j, i, j - length + 1);
                        verifyCounter++;
                    }
                }
            }
        }
    }
    if (verifyCounter == 0) {
        printf("%s - [%d][%d], [%d][%d]\n", word, 0, 0, 0, 0);
    }
}

int convertString(char *gradeString, char grade[M][N]) {
    int k = 0, length = strlen(gradeString);

    if (length != M * N) {
        return 0;
    } else {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                grade[i][j] = toupper(gradeString[k]);
                k++;
            }
        }
        return 1;
    }
}

int main() {
    char gradeString[M * N + 1];
    char grade[M][N];
    char userInput[ML];
    int close = 0;
    
    printf("Por favor, digite os valores da matriz em formato de String (100 caracteres): \n");
    scanf("%s", gradeString);

    int validation = convertString(gradeString, grade);

    if (validation == 1) {
        do {
            printf("\nBusque uma palavra no caça palavras ou digite 'encerrar' para sair do programa: ");
            scanf("%s", userInput);
            for (int i = 0; i < strlen(userInput); i++) {
                userInput[i] = toupper(userInput[i]);
            }

            if (strcmp(userInput, "ENCERRAR") == 0) {
                close = 1;
            } else {
                principalVerify(grade, userInput);
            }
        } while (close == 0);
    } else {
        printf("\nPor favor, adicione uma matriz em formato de String válida");
    }

    return 0;
}
