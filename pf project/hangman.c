#include <stdio.h>
#include <string.h>
#include <time.h>

// Time limit is 30 seconds

int main() {
    char guessedWord[20] = {0};     // Initialize with null characters
    int categoryChoice;
    char guess;
    time_t start_Time = time(NULL); // Record the start time
    int correctWordCount = 0;       // Counter for correctly guessed words

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

    // Choose a category
    printf("Select a category:\n1. Food\n2. Countries\n3. Animals\n4. Sports\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &categoryChoice);

    if (categoryChoice < 1 || categoryChoice > 4) {
        printf("Invalid choice.\n");
        return 1;
    }

    int wordIndex = 0;  // Start with the first word

    // Continue playing until time is up
    while (difftime(time(NULL), start_Time) < 30) {
        char word[20];  // Create a local array to store the selected word
        strcpy(word, categories[categoryChoice - 1][wordIndex]);  // Copy the word into the local array
        int incorrectAttempts = 0;

        // Prepare the initial guessedWord with underscores
        for (int i = 0; i < strlen(word); i++) {
            guessedWord[i] = '_';
        }
        guessedWord[strlen(word)] = '\0';  // Null-terminate the guessed word

        // Game loop for each word
        while (incorrectAttempts <= 6 && difftime(time(NULL), start_Time) < 30) {
            int correctGuess = 0;

            // Display the current state of the word
            printf("\nCurrent word: ");
            for (int i = 0; i < strlen(word); i++) {
                printf("%c ", guessedWord[i]);
            }

            // Display the hangman state
            switch (6 - incorrectAttempts) {
                case 5:
                     printf("\n O\n"); 
                     break;
                case 4: 
                    printf("\n O\n |\n"); 
                    break;
                case 3: 
                    printf("\n O\n/|\n"); 
                    break;
                case 2: 
                    printf("\n O\n/|\\\n"); 
                    break;
                case 1: 
                    printf("\n O\n/|\\\n/ \n");
                     break;
                case 0: 
                    printf("\n O\n/|\\\n/ \\\n"); 
                    break;
                default: 
                    printf("\n\n");
            }

            // Get user's guess
            printf("\nEnter a letter: ");
            scanf(" %c", &guess);

            // Check if the guess is in the word
            for (int i = 0; i < strlen(word); i++) {
                if (word[i] == guess && guessedWord[i] == '_') {
                    guessedWord[i] = guess;
                    correctGuess = 1;
                }
            }

            if (!correctGuess) {
                incorrectAttempts++;  // Increase incorrect attempts if the guess is wrong
                printf("Incorrect guess!");
            } else {
                printf("Good guess!\n");
            }

            // Check if the word is fully guessed
            if (strcmp(word, guessedWord) == 0) {
                printf("\nCongratulations! You guessed the word: %s\n", word);
                correctWordCount++;  // Increment the count of correctly guessed words
                break;
            }
        }

        if (incorrectAttempts > 6) {
            printf("\nYou've been hanged! The word was: %s\n", word);
        }

        // Move to the next word in the category
        wordIndex = (wordIndex + 1) % 25;  // Wrap around if reaching the end
    }

    // Display the number of correctly guessed words when time is up
    printf("\nTime's up! You guessed %d word(s) correctly.\n", correctWordCount);

    return 0;
}




