#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptVigenere(char *input, char *key) {
    int inputLen = strlen(input);
    int keyLen = strlen(key);

    for (int i = 0, j = 0; i < inputLen; i++) {
        char currentChar = input[i];

        if (isalpha(currentChar)) {
           
            char caseOffset = isupper(currentChar) ? 'A' : 'a';

            
            char encryptedChar = (currentChar + key[j] - 2 * caseOffset) % 26 + caseOffset;

            j = (j + 1) % keyLen;

           
            input[i] = encryptedChar;
        }
    }
}

int main() {
    char plaintext[1000];
    char key[100];

    
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

  
    printf("Enter the key: ");
    scanf("%s", key);

    encryptVigenere(plaintext, key);

   
    printf("Encrypted text: %s\n", plaintext);

    return 0;
}
