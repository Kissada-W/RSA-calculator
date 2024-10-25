#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// Function to check if a number is prime
bool is_prime(unsigned long long num) {
    if (num <= 1) return false;
    if (num == 2 || num == 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (unsigned long long i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

// Function to compute GCD
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to compute modular inverse of e mod phi
unsigned long long mod_inverse(unsigned long long e, unsigned long long phi) {
    unsigned long long d = 1;
    while ((d * e) % phi != 1) {
        d++;
    }
    return d;
}

// Function for modular exponentiation: (base^exp) % mod
unsigned long long mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// RSA Encryption function
unsigned long long encrypt(unsigned long long plaintext, unsigned long long e, unsigned long long N) {
    return mod_exp(plaintext, e, N);
}

// RSA Decryption function
unsigned long long decrypt(unsigned long long ciphertext, unsigned long long d, unsigned long long N) {
    return mod_exp(ciphertext, d, N);
}

int main() {
    unsigned long long p, q, N, r, e, d, plaintext, ciphertext;

    // Input loop for p (ensure it's prime)
    do {
        printf("Enter a prime number p: ");
        scanf("%llu", &p);

        if (!is_prime(p)) {
            printf("Error: %llu is not a prime number. Please enter a valid prime number.\n", p);
        }
    } while (!is_prime(p));

    // Input loop for q (ensure it's prime)
    do {
        printf("Enter a prime number q: ");
        scanf("%llu", &q);

        if (!is_prime(q)) {
            printf("Error: %llu is not a prime number. Please enter a valid prime number.\n", q);
        }
    } while (!is_prime(q));

    // Calculate N = p * q
    N = p * q;

    // Calculate r = (p-1)*(q-1)
    r = (p - 1) * (q - 1);

    // Choose e such that 1 < e < r and gcd(e, r) = 1
    e = 3;
    while (gcd(e, r) != 1) {
        e++;
    }

    // Calculate d, the modular inverse of e mod r
    d = mod_inverse(e, r);

    // Display the results with improved formatting
    printf("\n========== RSA Key Calculation ==========\n");
    printf("Prime number p: %llu\n", p);
    printf("Prime number q: %llu\n", q);
    printf("-----------------------------------------\n");
    printf("N = p * q = %llu\n", N);
    printf("r = (p-1)*(q-1) = %llu\n", r);
    printf("Public key (e, N) = (%llu, %llu)\n", e, N);
    printf("Private key (d, N) = (%llu, %llu)\n", d, N);
    printf("=========================================\n");

    // Input plaintext to encrypt
    printf("Enter a plaintext (numeric) to encrypt (must be less than N): ");
    scanf("%llu", &plaintext);

    if (plaintext >= N) {
        printf("Error: Plaintext should be less than N (%llu)\n", N);
        return 1;
    }

    // Encrypt the plaintext
    ciphertext = encrypt(plaintext, e, N);
    printf("Encrypted ciphertext: %llu\n", ciphertext);

    // Decrypt the ciphertext
    unsigned long long decrypted = decrypt(ciphertext, d, N);
    printf("Decrypted plaintext: %llu\n", decrypted);

    return 0;
}

