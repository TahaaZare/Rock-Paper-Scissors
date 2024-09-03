#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int game(char user, char system) {
    if (user == system)
        return 0; //Draw

    if ((user == 's' && system == 'p') || (user == 'p' && system == 'z') || (user == 'z' && system == 's'))
        return 1; // User win

    return -1; // System wins
}


int main() {
    int rounds = 3;
    int userScore = 0, systemScore = 0;
    char user, system, result;

    srand(time(NULL));
    printf("\nWelcome to Rock Paper Scissors!\n");

    for (int i = 1; i <= rounds; ++i) {
        int n = rand() % 100;
        if (n < 33)
            system = 's';
        else if (n > 33 && n < 66)
            system = 'p';
        else
            system = 'z';

        printf("\nRound %d: Enter 's' for STONE, 'p' for PAPER, and 'z' for SCISSOR: \n", i);
        scanf(" %c", &user);

        result = game(user, system);

        if (result == 1) {
            printf("You win this round!\n");
            userScore++;
        } else if (result == -1) {
            printf("Computer wins this round!\n");
            systemScore++;
        } else {
            printf("It's a draw this round!\n");
        }
    }

    printf("\nGame Over!\n");
    if (userScore > systemScore)
        printf("Congratulations! You win the match!\n");
    else if (userScore < systemScore)
        printf("Oops! Computer wins the match!\n");
    else
        printf("It's a tie! No clear winner.\n");

    printf("Final scores: You %d - %d Computer\n", userScore, systemScore);
    return 0;
}
