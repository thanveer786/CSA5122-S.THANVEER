#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

void computeMD5(char *input, unsigned char *digest) {
    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, input, strlen(input));
    MD5_Final(digest, &context);
}

int main() {
    char input[100];
    printf("Enter the string to hash: ");
    fgets(input, sizeof(input), stdin);

    // Remove the newline character from input
    input[strcspn(input, "\n")] = 0;

    unsigned char digest[MD5_DIGEST_LENGTH];
    computeMD5(input, digest);

    printf("MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}

