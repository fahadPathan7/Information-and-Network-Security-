# <p align='center'>Lab 3: Symmetric encryption & hashing<p>

## ✔️ Task 1
### Solution
**Text file:**
```text
I am Fahad Pathan. Undergrad student of Software Engineering at SUST.
```

**Commands:** <br>
Encrypt using AES-128 in ECB mode:
```bash
openssl enc -aes-128-ecb -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/output_ecb.bin -K 00112233445566778889aabbccddeeff
```

Encrypt using AES-128 in CBC mode:
```bash
openssl enc -aes-128-cbc -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/output_cbc.bin -K 00112233445566778889aabbccddeeff -iv 0102030405060708
```

Encrypt using AES-128 in CFB mode:
```bash
openssl enc -aes-128-cfb -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/output_cfb.bin -K 00112233445566778889aabbccddeeff -iv 0102030405060708
```

**Output files:** <br>
ECB mode: <br>
<img src="./Images/Task 1/ecb.png" alt="output_ecb" width="500"/>
<br><br>
CBC mode: <br>
<img src="./Images/Task 1/cbc.png" alt="output_cbc" width="500"/>
<br><br>
CFB mode: <br>
<img src="./Images/Task 1/cfb.png" alt="output_cfb" width="500"/>

<hr>

## ✔️ Task 2
### Solution
**Real image:** <br>
<img src="./Images/Task 2/real.png" alt="real_image" width="500"/>

**Commands:** <br>
Encryption using ECB mode:
```bash
openssl enc -aes-128-ecb -e -in ~/Desktop/securityTest/sample.bmp -out ~/Desktop/securityTest/encrypted_ecb.bmp -K 00112233445566778889aabbccddeeff
```

Encryption using CBC mode:
```bash
openssl enc -aes-128-cbc -e -in ~/Desktop/securityTest/sample.bmp -out ~/Desktop/securityTest/encrypted_cbc.bmp -K 00112233445566778889aabbccddeeff -iv 0102030405060708
```

**Output files:** <br>
After replacing the header of the encrypted files with the header of the real image, <br>
I got the following images and it is impossible to see any useful information from the encrypted images. <br>
(The images looks similar. I tried several times but they didn't change. maybe due to colorful pixels or complex image.) <br>

ECB mode: <br>
<img src="./Images/Task 2/ecb.png" alt="encrypted_ecb" width="500"/>
<br><br>
CBC mode: <br>
<img src="./Images/Task 2/cbc.png" alt="encrypted_cbc" width="500"/>

<hr>

## ✔️ Task 3
### Solution
**Text file:** <br>
<img src="./Images/Task 3/real.png" alt="real_image" width="500"/>

**Encryption Commands:** <br>
ECB mode:
```bash
openssl enc -aes-128-ecb -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/encrypted_test_ecb.txt -K 00112233445566778899aabbccddeeff
```

CBC mode:
```bash
openssl enc -aes-128-cbc -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/encrypted_test_cbc.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

CFB mode:
```bash
openssl enc -aes-128-cfb -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/encrypted_test_cfb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

OFB mode:
```bash
openssl enc -aes-128-ofb -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/encrypted_test_ofb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

**Encrypted files with corruption at the 30th byte:** <br>
ECB mode: <br>
<img src="./Images/Task 3/corrupted_ecb.png" alt="encrypted_test_ecb" width="500"/>

CBC mode: <br>
<img src="./Images/Task 3/corrupted_cbc.png" alt="encrypted_test_cbc" width="500"/>

CFB mode: <br>
<img src="./Images/Task 3/corrupted_cfb.png" alt="encrypted_test_cfb" width="500"/>

OFB mode: <br>
<img src="./Images/Task 3/corrupted_ofb.png" alt="encrypted_test_ofb" width="500"/>

**Decryption Commands:** <br>
ECB mode:
```bash
openssl enc -aes-128-ecb -d -in ~/Desktop/securityTest/encrypted_test_ecb.txt -out ~/Desktop/securityTest/decrypted_test_ecb.txt -K 00112233445566778899aabbccddeeff
```

CBC mode:
```bash
openssl enc -aes-128-cbc -d -in ~/Desktop/securityTest/encrypted_test_cbc.txt -out ~/Desktop/securityTest/decrypted_test_cbc.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

CFB mode:
```bash
openssl enc -aes-128-cfb -d -in ~/Desktop/securityTest/encrypted_test_cfb.txt -out ~/Desktop/securityTest/decrypted_test_cfb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

OFB mode:
```bash
openssl enc -aes-128-ofb -d -in ~/Desktop/securityTest/encrypted_test_ofb.txt -out ~/Desktop/securityTest/decrypted_test_ofb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

**Decrypted files:** <br>
ECB mode: <br>
<img src="./Images/Task 3/dec_ecb.png" alt="decrypted_test_ecb" width="500"/>

In the case of ECB mode,
- each block of plaintext is encrypted independently.
- since each block is encrypted separately, the corruption affects only one block.
- as a result, only the corrupted block will be affected, and the rest of the blocks will be decrypted correctly.
- it is possible to recover all information except for the corrupted block.

CBC mode: <br>
<img src="./Images/Task 3/dec_cbc.png" alt="decrypted_test_cbc" width="500"/>

In the case of CBC mode,
- each block of plaintext is XORed with the previous ciphertext block before encryption.
- if a single bit of the ciphertext is corrupted, it affects the decryption of the current and subsequent blocks due to error propagation.
- therefore, in CBC mode, only the block where the corruption occurred and all subsequent blocks cannot be recovered.
- The preceding blocks can be recovered correctly.

CFB mode: <br>
<img src="./Images/Task 3/dec_cfb.png" alt="decrypted_test_cfb" width="500"/>

In the case of CFB mode,
- the ciphertext of the previous block is encrypted and XORed with the current plaintext block to generate the current ciphertext block.
- if a single bit of the ciphertext is corrupted, it affects the decryption of the current block.
- since the encryption process uses the corrupted ciphertext block to generate the subsequent ciphertext blocks, the error propagates to  all subsequent blocks.
- as a result, in CFB mode, none of the plaintext blocks after the corrupted block can be recovered.

OFB mode: <br>
<img src="./Images/Task 3/dec_ofb.png" alt="decrypted_test_ofb" width="500"/>

In the case of OFB mode,
- the key stream is generated independently of the plaintext.
- if a single bit of the ciphertext is corrupted, it does not affect the decryption of subsequent blocks because the key stream is not influenced by the ciphertext.
- therefore, in OFB mode, all plaintext blocks except the corrupted block can be recovered.

<hr>

## ✔️ Task 4
### Solution
Here I tested the previous text files.

**Commands:** <br>
ECB mode:
```bash
openssl enc -aes-128-ecb -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/encrypted_test_ecb.txt -K 00112233445566778899aabbccddeeff
```

CBC mode:
```bash
openssl enc -aes-128-cbc -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/encrypted_test_cbc.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

CFB mode:
```bash
openssl enc -aes-128-cfb -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/encrypted_test_cfb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

OFB mode:
```bash
openssl enc -aes-128-ofb -e -in ~/Desktop/securityTest/test.txt -out ~/Desktop/securityTest/encrypted_test_ofb.txt -K 00112233445566778899aabbccddeeff -iv 0102030405060708090a0b0c0d0e0f10
```

**Observations and Explanations:** <br>
- ECB mode requires padding because it encrypts each block independently. If the plaintext size is not a multiple of the block size, padding is needed to fill the last block.
- CBC mode also requires padding for the same reason as ECB. Additionally, CBC mode requires an IV (Initialization Vector) for the XOR operation with the first block, but padding is still needed for the last block.
- CFB mode does not require padding because it operates on a byte level rather than block level. The ciphertext length is the same as the plaintext length.
- OFB mode also does not require padding because it generates a key stream independently of the plaintext. The ciphertext length matches the plaintext length.

<hr>

## ✔️ Task 5
### Solution
**Text file:** <br>
```text
Sylhet is a beautiful city
```

**Commands:** <br>
```bash
# MD5
openssl dgst -md5 ~/Desktop/securityTest/test.txt

# SHA-256
openssl dgst -sha256 ~/Desktop/securityTest/test.txt

# SHA-512
openssl dgst -sha512 ~/Desktop/securityTest/test.txt
```

**Output:** <br>
MD5: <br>
<img src="./Images/Task 5/md5.png" alt="md5" width="700"/>

SHA-256: <br>
<img src="./Images/Task 5/sha_256.png" alt="sha256" width="700"/>

SHA-512: <br>
<img src="./Images/Task 5/sha_512.png" alt="sha512" width="700"/>

**Observations and Explanations:** <br>
- Hash Length:
    - MD5 produces a 128-bit (16-byte) hash value.
    - SHA-256 produces a 256-bit (32-byte) hash value.
    - SHA-512 produces a 512-bit (64-byte) hash value.
- Security Levels:
    - MD5 is considered weak and vulnerable to collision attacks.
    - SHA-256 and SHA-512 offer stronger security properties and are recommended for security-critical applications.
- Speed:
    - MD5 is faster than SHA-256 and SHA-512.
    - SHA-512 is slower than SHA-256.

<hr>

## ✔️ Task 6
### Solution
**Text file:** <br>
```text
Sylhet is a beautiful city
```

**Commands:** <br>
Short key length:
```bash
# HMAC-MD5
openssl dgst -hmac "secret" -md5 -hex ~/Desktop/securityTest/test.txt

# HMAC-SHA256
openssl dgst -hmac "secret" -sha256 -hex ~/Desktop/securityTest/test.txt

# HMAC-SHA1
openssl dgst -hmac "secret" -sha1 -hex ~/Desktop/securityTest/test.txt
```

Long key length:
```bash
# HMAC-MD5
openssl dgst -hmac "this_is_a_longer_secret_key" -md5 -hex ~/Desktop/securityTest/test.txt

# HMAC-SHA256
openssl dgst -hmac "this_is_a_longer_secret_key" -sha256 -hex ~/Desktop/securityTest/test.txt

# HMAC-SHA1
openssl dgst -hmac "this_is_a_longer_secret_key" -sha1 -hex ~/Desktop/securityTest/test.txt
```

**Observations:** <br>
HMAC-MD5:
- Short key: Limited key length increases vulnerability to brute-force attacks.
- Long key: Extended key length strengthens security, mitigating brute-force risks.
- <img src="./Images/Task 6/md5.png" alt="md5" width="500"/>
<br>

HMAC-SHA256:
- Short key: Reduced key size raises susceptibility to brute-force attacks.
- Long key: Expanded key size significantly boosts security.
- <img src="./Images/Task 6/sha256.png" alt="sha256" width="500"/>
<br>

HMAC-SHA1:
- Short key: Smaller keys are more vulnerable to brute-force attacks despite SHA1's inherent strength.
- Long key: Larger keys enhance security significantly, making brute-force attacks impractical.
- <img src="./Images/Task 6/sha1.png" alt="sha1" width="500"/>

<hr>

## ✔️ Task 7
### Solution
**Text file:** <br>
```text
Assignment done
```

**Commands:** <br>
```bash
openssl dgst -md5 ~/Desktop/securityTest/test.txt
openssl dgst -sha256 ~/Desktop/securityTest/test.txt
```

**Output:** <br>
H1: <br>
<img src="./Images/Task 7/h1.png" alt="H1" width="500"/>

H2: <br>
<img src="./Images/Task 7/h2.png" alt="H2" width="500"/>

**Observations:** <br>
- The hash values of H1 and H2 are different.
- After changing the text file, the hash values of H1 and H2 changed.
- H1 uses MD5, while H2 uses SHA-256.
- MD5 produces a 128-bit hash value, while SHA-256 produces a 256-bit hash value.

**Code to calculate same bits:**
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string h1, h2;
    cin >> h1 >> h2; // taking input
    int sameBits = 0;
    for (int i = 0; i < min(h1.length(), h2.length()); i++) {
        if (h1[i] == h2[i]) sameBits++;
    }
    cout << sameBits << endl; // output
}
```

<hr>