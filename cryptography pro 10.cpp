#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void secure_hash(const char *input, char *output) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, input, strlen(input));
    SHA256_Final((unsigned char *)output, &sha256);
}

int main() {
    const char *input_text = "Hello, secure hashing!";
    char hashed_result[SHA256_DIGEST_LENGTH * 2 + 1];

    secure_hash(input_text, hashed_result);

    printf("Input text: %s\n", input_text);
    printf("Hashed result: %s\n", hashed_result);

    return 0;
}
