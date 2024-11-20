#include <stdio.h>
#include <string.h>
#include <time.h>


void displayTitle() {
    printf("                        \t┓┏             \n");
    printf("                        \t┣┫┏┓┏┓┏┓┏┳┓┏┓┏┓\n");
    printf("                        \t┛┗┗┻┛┗┗┫┛┗┗┗┻┛┗\n");
    printf("                        \t       ┛       \n\n");
    printf("Welcome to the Word Guessing Game!\n");
}
int main() {
    displayTitle();
    char guessword[20]; 
    int categoryChoice;
    char guess;
    time_t startTime = time(NULL);  
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
    int wordIndex = 0;                                         

    while (difftime(time(NULL), startTime) < 20) {               
        char word[20]; 
        strcpy(word, categories[categoryChoice - 1][wordIndex]);  
        int incorrectAttempts = 0;
        for (int i = 0; i < strlen(word); i++) {              
            guessword[i] = '_';
        }
        guessword[strlen(word)] = '\0';

        while (incorrectAttempts <= 6) {   
            int correctGuess = 0;
            printf("\nCurrent word: ");                      
            for (int i = 0; i < strlen(word); i++) {
                printf("%c ", guessword[i]);
            }
            
            printf("\nEnter a letter: ");                    
            scanf(" %c", &guess);
            for (int i = 0; i < strlen(word); i++) {
                if (word[i] == guess && guessword[i] == '_') {
                    guessword[i] = guess;
                    correctGuess = 1;
                }
            }
                if (!correctGuess) {
                incorrectAttempts++;                         
                printf("Incorrect guess!");
                int figure = 6 - incorrectAttempts;
                switch (figure) {                           
                case 5: printf("\n O\n"); break;
                case 4: printf("\n O\n |\n"); break;
                case 3: printf("\n O\n/|\n"); break;
                case 2: printf("\n O\n/|\\\n"); break;
                case 1: printf("\n O\n/|\\\n/ \n"); break;
                case 0: printf("\n O\n/|\\\n/ \\\n"); break;
                default: printf("\n\n");
            }
            } else {
                printf("Good guess!\n");
            }
               
            if (strcmp(word, guessword) == 0) {           
                printf("\nCongratulations! You guessed the word: %s\n", word);
                correctWordCount++;                       
                break;
            }
        }

        if (incorrectAttempts > 6) {
            printf("\nYou've been hanged! The word was: %s\n", word);
            incorrectwordcount++;                        
        }
        wordIndex = wordIndex + 1;                      
    }
    printf("\nTime's up! You guessed %d words correctly & %d incorrectly.\n", correctWordCount,incorrectwordcount);
    return 0;
}
