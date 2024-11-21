#include <stdio.h>
#include <string.h>
#include <time.h>

//Time limit in seconds is 30 seconds
void displayTitle() {
    printf("===================================================================================\n");
    printf("                        \t┓┏             \n");
    printf("                        \t┣┫┏┓┏┓┏┓┏┳┓┏┓┏┓\n");
    printf("                        \t┛┗┗┻┛┗┗┫┛┗┗┗┻┛┗\n");
    printf("                        \t       ┛       \n");
    printf("Welcome to the Word Guessing Game!\n");
    printf("===================================================================================\n");
}
void printHangman(int incorrectAttempts) {
    switch (6 - incorrectAttempts) {
        case 5: printf("\n   O   \n"); break;
        case 4: printf("\n   O   \n   |   \n"); break;
        case 3: printf("\n   O   \n  /|   \n"); break;
        case 2: printf("\n   O   \n  /|\\ \n"); break;
        case 1: printf("\n   O   \n  /|\\ \n  /    \n"); break;
        case 0: printf("\n   O   \n  /|\\ \n  / \\ \n"); break;
        default:printf("\n\n"); break;
    }
 printf("------------------------\n");
}
int main() {
    displayTitle();
    char guessword[20]; 
    int categoryChoice;
    char guess;
    time_t startTime = time(NULL);  // Record the start time 
    int correctWordCount = 0;      
    int incorrectwordcount = 0;
   
    char categories[4][25][20] = {
        // Food
        {"pizza", "burger", "pasta", "sushi", "salad", "steak", "taco", "burrito", "noodles", "dumplings",
         "sandwich", "omelet", "curry", "soup", "bagel", "cheesecake", "brownie", "waffle", "pancake", "apple",
         "banana", "grape", "orange", "pear", "kiwi"},
        // Countries
        {"canada", "brazil", "germany", "france", "italy", "mexico", "japan", "china", "india", "spain",
         "norway", "sweden", "finland", "australia", "poland", "turkey", "greece", "russia", "egypt", "chile",
         "argentina", "peru", "nigeria", "kenya", "ghana"},
        // Animals
        {"tiger", "lion", "elephant", "zebra", "giraffe", "dolphin", "shark", "whale", "penguin", "bear",
         "wolf", "fox", "rabbit", "deer", "kangaroo", "panda", "cheetah", "leopard", "hippo", "rhino",
         "bat", "eagle", "sparrow", "owl", "peacock"},
        // Sports
        {"soccer", "cricket", "tennis", "badminton", "hockey", "basketball", "baseball", "rugby", "golf", "volleyball",
         "cycling", "boxing", "fencing", "judo", "karate", "rowing", "sailing", "skiing", "surfing", "archery",
         "darts", "polo", "squash", "taekwondo", "wrestling"}
    };
    printf("Select a category:\n1. Food\n2. Countries\n3. Animals\n4. Sports\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &categoryChoice);

    if (categoryChoice < 1 || categoryChoice > 4) {
        printf("Invalid choice.\n");
        return 0;
    }

    int wordIndex = 0;                                         // Start with the first word
    printf("\nGame starts now! You have 30 seconds. Good luck!\n");
    printf("=====================================\n");
    
    // Continue playing until time is up
    while (difftime(time(NULL), startTime) < 20) {                //Time limit in seconds is 30 seconds
        char word[20]; 
        strcpy(word, categories[categoryChoice - 1][wordIndex]);  // Copy the word from array to word array
        int incorrectAttempts = 0;

        for (int i = 0; i < strlen(word); i++) {              // Prepare the initial guessedWord with underscores
            guessword[i] = '_';
        }
        guessword[strlen(word)] = '\0';

        while (incorrectAttempts < 6) {   // Game loop for each word
            int correctGuess = 0;
            printf("\nCurrent word: ");                      // Display the current state of the word
            for (int i = 0; i < strlen(word); i++) {
                printf("%c ", guessword[i]);
            }
            
            printf("\nEnter a letter: ");                    // player will make a guess
            scanf(" %c", &guess);
            for (int i = 0; i < strlen(word); i++) {
                if (word[i] == guess && guessword[i] == '_') {
                    guessword[i] = guess;
                    correctGuess = 1;
                }
            }

            if (!correctGuess) {
                incorrectAttempts++;                         // Increase incorrect attempts if the guess is wrong
                printf("Incorrect guess!");
                printHangman(incorrectAttempts);
    
            } else {
                printf("Good guess!\n");
            }
               
            if (strcmp(word, guessword) == 0) {            // Check if the word is fully guessed
                printf("\nCongratulations! You guessed the word: %s\n", word);
                correctWordCount++;                       // Increment the count of correctly guessed words
                break;
            }
        }
        if (incorrectAttempts == 6) {
            printf("\nYou've been hanged! The word was: %s\n", word);
            incorrectwordcount++;                        // counts the wrong word
        }
        wordIndex = wordIndex + 1;                       //to go to next word
    }
    printf("===========================================================");
    printf("\nTime's up!\n\n");
    printf("You guessed %d words correctly.\n\n", correctWordCount);
    printf("You guessed %d words inccorrectly.\n", incorrectwordcount);
    printf("===========================================================");
    return 0;
}
