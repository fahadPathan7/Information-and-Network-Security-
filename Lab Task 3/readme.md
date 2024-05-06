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
After replacing the header of the encrypted files with the header of the real image, I got the following images and it is impossible to see any useful information from the encrypted images. <br>

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
