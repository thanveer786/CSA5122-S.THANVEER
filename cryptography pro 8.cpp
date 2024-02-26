#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int power(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    long long int prime = 23;
    long long int base = 5;

    printf("Common prime number (p): %lld\n", prime);
    printf("Common base (g): %lld\n", base);

    long long int alice_private = 6;
    long long int bob_private = 15;

    long long int alice_public = power(base, alice_private, prime);
    long long int bob_public = power(base, bob_private, prime);

    printf("\nAlice's public key: %lld\n", alice_public);
    printf("Bob's public key: %lld\n", bob_public);

    long long int alice_shared_secret = power(bob_public, alice_private, prime);
    long long int bob_shared_secret = power(alice_public, bob_private, prime);

    printf("\nShared Secret (Alice): %lld\n", alice_shared_secret);
    printf("Shared Secret (Bob): %lld\n", bob_shared_secret);

    return 0;
}
