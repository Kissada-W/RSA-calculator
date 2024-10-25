# RSA Encryption and Decryption Program

This C program implements the fundamental operations of RSA cryptography, including key generation, encryption, and decryption. It is designed as a learning tool for Capture the Flag (CTF) challenges, cryptographic tasks, or for educational purposes in understanding RSA-based cryptography. The program runs on Linux and uses standard C libraries.

## Overview

The program calculates RSA keys based on two prime numbers provided by the user and uses them to encrypt and decrypt numeric messages. It includes utility functions for prime checking, computing the greatest common divisor (GCD), modular exponentiation, and calculating the modular inverse.

## Features

- **Prime Number Verification**: Ensures the input values for key generation are valid prime numbers.
- **GCD Calculation**: Uses the Euclidean algorithm to check if the public exponent `e` and `r` (Euler's Totient) are coprime.
- **Modular Inverse Calculation**: Finds the private exponent `d` such that `(d * e) % r == 1`.
- **Modular Exponentiation**: Efficient computation for encryption and decryption using modular exponentiation.
- **RSA Key Generation**: Computes RSA public and private keys based on user-provided prime inputs.
- **Encryption and Decryption**: Allows the user to encrypt and decrypt messages based on the generated RSA keys.

## Functions

### `is_prime(unsigned long long num)`

Checks if a given number `num` is prime.

- **Parameters**: `num` - The number to check.
- **Returns**: `true` if prime, `false` otherwise.

### `gcd(unsigned long long a, unsigned long long b)`

Calculates the greatest common divisor of `a` and `b` using the Euclidean algorithm.

- **Parameters**: `a`, `b` - Input numbers.
- **Returns**: GCD of `a` and `b`.

### `mod_inverse(unsigned long long e, unsigned long long phi)`

Computes the modular inverse of `e` modulo `phi`.

- **Parameters**: `e` - Public exponent, `phi` - Euler's Totient.
- **Returns**: The modular inverse `d`, which is used for decryption.

### `mod_exp(unsigned long long base, unsigned long long exp, unsigned long long mod)`

Performs modular exponentiation, computing `(base^exp) % mod`. This function is used for both encryption and decryption in RSA.

- **Parameters**: `base`, `exp`, `mod` - The base, exponent, and modulus.
- **Returns**: The result of `(base^exp) % mod`.

### `encrypt(unsigned long long plaintext, unsigned long long e, unsigned long long N)`

Encrypts the plaintext using the RSA public key `(e, N)`.

- **Parameters**: `plaintext`, `e`, `N` - The message to encrypt, the public exponent, and modulus.
- **Returns**: The encrypted ciphertext.

### `decrypt(unsigned long long ciphertext, unsigned long long d, unsigned long long N)`

Decrypts the ciphertext using the RSA private key `(d, N)`.

- **Parameters**: `ciphertext`, `d`, `N` - The encrypted message, the private exponent, and modulus.
- **Returns**: The decrypted plaintext.

## Usage

1. **Input Primes**: The program prompts the user to input two prime numbers, `p` and `q`. It ensures that both numbers are valid primes.
2. **Key Generation**: The program computes:
   - `N = p * q` (modulus).
   - `r = (p - 1) * (q - 1)` (Euler's Totient).
   - `e` (public exponent) is selected such that `gcd(e, r) == 1`.
   - `d` (private exponent) is computed as the modular inverse of `e` modulo `r`.
3. **Encryption**: The user provides a numeric plaintext (less than `N`) for encryption. The program encrypts the message using the public key.
4. **Decryption**: The encrypted message is decrypted using the private key, and the decrypted plaintext is displayed.

### Example Output

```plaintext
Enter a prime number p: 17
Enter a prime number q: 23

========== RSA Key Calculation ==========
Prime number p: 17
Prime number q: 23
-----------------------------------------
N = p * q = 391
r = (p-1)*(q-1) = 352
Public key (e, N) = (3, 391)
Private key (d, N) = (235, 391)
=========================================
Enter a plaintext (numeric) to encrypt (must be less than N): 123
Encrypted ciphertext: 292
Decrypted plaintext: 123
```

## Error Handling

- **Prime Verification**: If the user enters a number that is not prime, the program will prompt for re-entry until valid prime numbers are provided.
- **Plaintext Validation**: The program ensures that the plaintext is smaller than `N`. If it is not, the program will display an error and terminate.

## Requirements

- **Operating System**: Designed for Linux systems.
- **Compiler**: Compatible with any C compiler (e.g., GCC).
- **Libraries**: The program only relies on standard C libraries:
  - `stdio.h` for input/output operations.
  - `math.h` for mathematical functions.
  - `stdbool.h` for boolean data types (`true`/`false`).

## Conclusion

This program serves as a compact tool for understanding RSA encryption and decryption processes, supporting both learning and practical application in cryptographic CTF challenges or educational tasks. It simplifies key RSA-related operations such as key generation, encryption, and decryption, making it suitable for those interested in cryptography or solving problems involving RSA.
