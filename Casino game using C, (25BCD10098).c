#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char playerName[50];
    int deposit, bet, guess, randomNumber;
    int balance;
    char continueGame;
    
    // Initialize random seed
    srand(time(NULL));
    
    // Display game rules
    printf("# Casino game using c\n");
    printf("**RULES**\n\n");
    printf("1. Choose any number between 1 to 10\n");
    printf("2. If you win you will get 10 times of money you bet\n");
    printf("3. If you bet on wrong number you will lose your betting amount\n");
    printf("---\n\n");
    
    // Get player name
    printf("Enter your name : ");
    fgets(playerName, sizeof(playerName), stdin);
    // Remove newline character from name
    playerName[strcspn(playerName, "\n")] = 0;
    
    // Get deposit amount
    printf("Enter the amount of money to deposit for the game : ");
    scanf("%d", &deposit);
    
    balance = deposit;
    
    do {
        // Display current balance
        printf("\nYour current balance is $%d\n", balance);
        
        // Get bet amount
        printf("%s, Enter the money to bet : $", playerName);
        scanf("%d", &bet);
        
        // Validate bet amount
        if (bet > balance) {
            printf("You don't have enough balance to bet $%d!\n", bet);
            continue;
        }
        
        if (bet <= 0) {
            printf("Please enter a valid bet amount!\n");
            continue;
        }
        
        // Get player's guess
        printf("---\n");
        printf("Guess a number from 1 to 10: ");
        scanf("%d", &guess);
        
        // Validate guess
        if (guess < 1 || guess > 10) {
            printf("Please enter a number between 1 and 10!\n");
            continue;
        }
        
        // Generate random number between 1-10
        randomNumber = (rand() % 10) + 1;
        
        // Check if player won
        if (guess == randomNumber) {
            int winnings = bet * 10;
            balance += winnings;
            printf("\nCongratulations! You won $%d\n", winnings);
            printf("The correct number is : %d\n", randomNumber);
        } else {
            balance -= bet;
            printf("\nYou have loss $%d\n", bet);
            printf("The correct number is : %d\n", randomNumber);
        }
        
        // Display updated balance
        printf("Now you have $%d as a balance\n", balance);
        
        // Check if player has balance to continue
        if (balance <= 0) {
            printf("\nYou have no money left! Game over.\n");
            break;
        }
        
        // Ask if player wants to continue
        printf("\n---\n");
        printf("**Press 1 for Yes**\n");
        printf("**Press 2 for No**\n");
        printf("Do you want to continue (Y/N) ? ");
        
        // Clear input buffer
        while (getchar() != '\n');
        
        // Get continue decision
        scanf("%c", &continueGame);
        
        // Clear input buffer again
        while (getchar() != '\n');
        
    } while (continueGame == 'Y' || continueGame == 'y' || continueGame == '1');
    
    // Final message
    printf("\nThank you for playing, %s!\n", playerName);
    printf("Your final balance is: $%d\n", balance);
    
    return 0;
}