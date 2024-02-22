#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#define ALPHABET_SIZE 26 
void caesarCipher(char* text, int shift);
char cipherChar(char c, int shift);
int main() {
    char text[1024]; 
    int shift;
    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin); 
    printf("Enter the shift value: ");
    scanf("%d", &shift);
    caesarCipher(text, shift);
    printf("Encrypted text: %s\n", text);
    return 0;
}
void caesarCipher(char* text, int shift) {
    int i = 0;
    while (text[i] != '\0') {
        if (isalpha(text[i])) { 
            text[i] = cipherChar(text[i], shift);
        }
        i++;
    }
}
char cipherChar(char c, int shift) {
    
    if (isupper(c)) {
        return 'A' + (c - 'A' + shift) % ALPHABET_SIZE;
    } else if (islower(c)) {
        return 'a' + (c - 'a' + shift) % ALPHABET_SIZE;
    }
    return c; 
}

