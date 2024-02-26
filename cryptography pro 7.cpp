#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate greatest common divisor
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return result;
}

// Function to generate keys
void generateKeys(long long *publicKey, long long *privateKey, long long *n) {
    long long p = 61; // You can choose your own prime numbers
    long long q = 53;
    *n = p * q;
    long long totient = (p - 1) * (q - 1);

    *publicKey = 17; // You can choose your own public key
    while (*publicKey < totient && gcd(*publicKey, totient) != 1) {
        (*publicKey)++;
    }

    *privateKey = 1;
    while (((*privateKey) * (*publicKey)) % totient != 1) {
        (*privateKey)++;
    }
}

// Function to encrypt a message
long long encrypt(long long message, long long publicKey, long long n) {
    return power(message, publicKey, n);
}

// Function to decrypt a ciphertext
long long decrypt(long long ciphertext, long long privateKey, long long n) {
    return power(ciphertext, privateKey, n);
}

int main() {
    long long publicKey, privateKey, n;

    generateKeys(&publicKey, &privateKey, &n);

    long long message = 42;
    long long ciphertext = encrypt(message, publicKey, n);
    long long decryptedMessage = decrypt(ciphertext, privateKey, n);

    printf("Original Message: %lld\n", message);
    printf("Encrypted Message: %lld\n", ciphertext);
    printf("Decrypted Message: %lld\n", decryptedMessage);

    return 0;
}
