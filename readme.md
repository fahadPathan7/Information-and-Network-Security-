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
<img src="./Lab Task 3/Images/Task 1/ecb.png" alt="output_ecb" width="500"/>
<br><br>
CBC mode: <br>
<img src="./Lab Task 3/Images/Task 1/cbc.png" alt="output_cbc" width="500"/>
<br><br>
CFB mode: <br>
<img src="./Lab Task 3/Images/Task 1/cfb.png" alt="output_cfb" width="500"/>

<hr>

## ✔️ Task 2
