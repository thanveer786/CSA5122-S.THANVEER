#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5
#define MAX_TEXT_SIZE 512

// Function to initialize the 5x5 key square
void initializeKeySquare(char keySquare[SIZE][SIZE], const char *key) {
    int flag[26] = {0}, x = 0, y = 0;

    // Loop through the key to add it to the key square
    for (int i = 0; key[i] != '\0'; i++) {
        char c = toupper(key[i]);

        if (c < 'A' || c > 'Z') continue;

        // Handling 'J' same as 'I'
        if (c == 'J') c = 'I';

        if (!flag[c - 'A']) {
            keySquare[x][y++] = c;
            flag[c - 'A'] = 1;

            if (y == SIZE) {
                y = 0;
                x++;
            }
        }
    }

    // Fill the key square with the remaining letters
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue; // Skip 'J'

        if (!flag[c - 'A']) {
            keySquare[x][y++] = c;
            if (y == SIZE) {
                y = 0;
                x++;
            }
        }
    }
}

// Function to prepare the text (remove non-letters, handle duplicates, and make even length)
void prepareText(char *input, char *output) {
    int i, j = 0;
    int len = strlen(input);
    for (i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            output[j++] = toupper(input[i]);
        }
    }
    output[j] = '\0';

    // Insert 'X' between duplicate letters and make the length even
    for (i = 0; i < j; i += 2) {
        if (output[i] == output[i + 1]) {
            memmove(output + i + 2, output + i + 1, j - i);
            output[i + 1] = 'X';
            j++;
            output[j] = '\0'; // Null-terminate the string after modification
        }
    }

    // If the length of the string is odd, append 'X' to make it even
    if (j % 2 != 0) {
        output[j++] = 'X';
        output[j] = '\0';
    }
}

// Function to find the position of a character in the key square
void findPosition(char keySquare[SIZE][SIZE], char c, int *row, int *col) {
    if (c == 'J') c = 'I'; // Treat 'J' as 'I'

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keySquare[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

// Function to perform the Playfair encryption on digraphs
void encryptDigraph(char keySquare[SIZE][SIZE], char a, char b, char *encryptedDigraph) {
    int row1, col1, row2, col2;
    findPosition(keySquare, a, &row1, &col1);
    findPosition(keySquare, b, &row2, &col2);

    // Same row
    if (row1 == row2) {
        encryptedDigraph[0] = keySquare[row1][(col1 + 1) % SIZE];
        encryptedDigraph[1] = keySquare[row2][(col2 + 1) % SIZE];
    }
    // Same column
    else if (col1 == col2) {
        encryptedDigraph[0] = keySquare[(row1 + 1) % SIZE][col1];
        encryptedDigraph[1] = keySquare[(row2 + 1) % SIZE][col2];
    }
    // Rectangle
    else {
        encryptedDigraph[0] = keySquare[row1][col2];
        encryptedDigraph[1] = keySquare[row2][col1];
    }
}

// Function to encrypt the prepared text using the key square
void encryptText(char keySquare[SIZE][SIZE], const char *text, char *encryptedText) {
    char preparedText[MAX_TEXT_SIZE];
    prepareText((char *)text, preparedText);

    int len = strlen(preparedText);
    for (int i = 0; i < len; i += 2) {
        char encryptedDigraph[3] = {0};
        encryptDigraph(keySquare, preparedText[i], preparedText[i + 1], encryptedDigraph);
        encryptedText[i] = encryptedDigraph[0];
        encryptedText[i + 1] = encryptedDigraph[1];
    }
    encryptedText[len] = '\0';
}

int main() {
    char keySquare[SIZE][SIZE];
    char key[] = "THANVEER";
    char text[] = "thabrez";
    char encryptedText[MAX_TEXT_SIZE];

    initializeKeySquare(keySquare, key);
    encryptText(keySquare, text, encryptedText);

    printf("Original text: %s\n", text);
    printf("Encrypted text: %s\n", encryptedText);

    return 0;
}

