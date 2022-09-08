#include "Global.h"

void menu(){
    system("cls");
    printf("\n               Menu for SuDoku or SAT              \n");
    printf("------------------------------------------------------\n");
    printf("            1.SAT                  2.SuDoKu           \n");
    printf("            0.Exit                                    \n");
    printf("------------------------------------------------------\n");
}

void menu_SAT(){
    system("cls");
    printf("\n              Menu for SAT                \n");
    printf("-------------------------------------------\n");
    printf("     1.ReadCnfFile           2.TraverseCnf  \n");
    printf("     3.SaveCnfFile           4.ImproveDpll   \n");
    printf("     0.Exit                                   \n");
    printf("--------------------------------------------\n");
}


void Judge(status flag){
    switch (flag)
    {
    case OK:    //OK or TRUE
        printf("SUCCESS!\n");
        break;
    case ERROR:
        printf("ERROR!\n");
        exit(-1);
        break;
    case TRUE:
        printf("YES!\n");
        break;
    case FALSE:
        printf("NO!\n");
        break;
    default:
        break;
    }
}

void printOneSudoku(int f[][COL]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++)
            printf("%d ", f[i][j]);
        printf("\n");
    }
}

void printTwoSudoku(int f1[][COL], int f2[][COL]){
    // for(int i=0; i<6; i++){
    //     for(int j=0; j<9; j++) printf("%d ", f1[i][j]);
    //     printf("\n");
    // }
    // for(int i=6; i<9; i++){
    //     for(int j=0; j<9; j++) printf("%d ", f1[i][j]);
    //     for(int j=3; j<9; j++) printf("%d ", f2[i-6][j]);
    //     printf("\n");
    // }
    // for(int i=3; i<9; i++){
    //     printf("            ");
    //     for(int j=0; j<9; j++) printf("%d ", f2[i][j]);
    //     printf("\n");
    // }


    int i, j, ii, jj;
    printf("-------------------------------\n");
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 9; j++) {
            if (j % 3 == 0) printf("|");
            if (f1[i][j] != 0) printf("%2d ", f1[i][j]);
            else printf(" _ ");
            if (j == 8) printf("|\n");
        }
        if (i == 2) printf("-------------------------------\n");
        if (i == 5) printf("---------------------------------------------------\n");
    }
    for (i = 6; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if (j % 3 == 0) printf("|");
            if (f1[i][j] != 0) printf("%2d ", f1[i][j]);
            else printf(" _ ");
        }
        for(j = 3; j < 9; j++)
        {
            if (j % 3 == 0) printf("|");
            if (f2[i-6][j] != 0) printf("%2d ", f2[i-6][j]);
            else printf(" _ ");
            if (j == 8) printf("|\n");
        }
    }
    printf("---------------------------------------------------\n");
    for(i = 3; i < 9; i++)
    {
        cout << "                    ";
        for(j = 0; j < 9; j++)
        {
            if (j % 3 == 0) printf("|");
            if (f2[i][j] != 0) printf("%2d ", f2[i][j]);
            else printf(" _ ");
            if (j == 8) printf("|\n");
        }
        if (i == 5) {cout << "                    ";printf("-------------------------------\n");}
        if (i == 8) {cout << "                    ";printf("-------------------------------\n");}
    }
}
