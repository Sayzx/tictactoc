#include <stdio.h>
#include <stdlib.h>
char grid[3][3];
void InitGrid() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

void PrintGrid() {
    printf("Tic Tac Toe\n");
    printf("  1 | 2 | 3 \n");
    printf(" ---|---|---\n");
    printf("  4 | 5 | 6 \n");
    printf(" ---|---|---\n");
    printf("  7 | 8 | 9 \n");

    printf("Current Board:\n");
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", grid[i][j]);
            if (j < 2) {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2) {
            printf("-----------\n");
        }
    }
}

int AddGrid(char playerChoice, int position) {
    int row = (position - 1) / 3;
    int col = (position - 1) % 3;

    if (grid[row][col] == ' ') {
        grid[row][col] = playerChoice;
        return 1;
    } else {
        printf("Position déjà prise. Réessayez.\n");
        return 0;
    }
}

int CheckWin(char playerChoice) {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == playerChoice && grid[i][1] == playerChoice && grid[i][2] == playerChoice) {
            return 1;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (grid[0][j] == playerChoice && grid[1][j] == playerChoice && grid[2][j] == playerChoice) {
            return 1;
        }
    }

    if ((grid[0][0] == playerChoice && grid[1][1] == playerChoice && grid[2][2] == playerChoice) ||
        (grid[0][2] == playerChoice && grid[1][1] == playerChoice && grid[2][0] == playerChoice)) {
        return 1;
    }
    return 0;
}

int main() {
    InitGrid();
    char playerChoice = 'X';
    int currentPlayer = 1;

    printf("Joueur 1: X, Joueur 2: O\n");

    int moves = 0;

    while (1) {
        PrintGrid();

        int position;
        printf("Joueur %d, entrez la position (1-9): ", currentPlayer);

        if (scanf("%d", &position) != 1 || position < 1 || position > 9) {
            // Si scanf a échoué ou que la position est invalide, nettoie le flux d'entrée
            while (getchar() != '\n');
            printf("Position invalide. Réessayez.\n");
            continue;
        }

        if (AddGrid(playerChoice, position)) {
            moves++;
            if (CheckWin(playerChoice)) {
                PrintGrid();
                printf("Joueur %d ( %c ) a gagné !\n", currentPlayer, playerChoice);
                break;
            } else if (moves == 9) {
                PrintGrid();
                printf("Match nul !\n");
                break;
            } else {
                playerChoice = (playerChoice == 'X') ? 'O' : 'X';
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        } else {
            printf("Position déjà prise. Réessayez.\n");
        }
    }
    return 0;
}
