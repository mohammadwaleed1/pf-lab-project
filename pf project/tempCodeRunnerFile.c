
        // Move to the next word in the category
        wordIndex = wordIndex + 1;  // Wrap around if reaching the end
    }
    printf("\nTime's up! You guessed %d words correctly & %d incorrectly.\n", correctWordCount,incorrectwordcount);
    return 0;
}
