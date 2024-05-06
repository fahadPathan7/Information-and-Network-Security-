# <p align='center'> Lab task 2 (Checkpoint 1)

## Question
The following cipher has been created using the Caesar cipher. Write a program to decipher it.
```bash
Cipher: odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo
```
Write a program to break it and display the result. Show it your teacher.

## Solution approach
- No key is given. So I need to show all the possible cases.
- Possible range of keys 0-25 (mod values of 26)

## Solution
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string cipher = "odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo";
    for (int key = 0; key < 26; key++) {
        cout << "For key: " << key << endl;
        // for each of the keys printing the real text (assumption)
        for (int j = 0; j < cipher.length(); j++) {
            int decrypt = (((int)cipher[j] - key) % 26 + 97); // getting the real ASCII value
            cout << (char)decrypt; // printing as character
        }
        cout << endl;
    }
}
```

## Output
For key: 0 <br>
hwkhuhxplvwkhehvwvpduwfrqwudfwsodwiruprxwwkhuh <br>
For key: 1 <br>
gvjgtgwokuvjgdguvuoctveqpvtcevrncvhqtoqwvvjgtg <br>
For key: 2 <br>
fuifsfvnjtuifcftutnbsudpousbduqmbugpsnpvuuifsf <br>
For key: 3 <br>
ethereumisthebestsmartcontractplatformoutthere <br>
For key: 4 <br>
dsgdqdtlhrsgdadrsrlzqsbnmsqzbsokzsenqlntssgdqd <br>
For key: 5 <br>
crfcpcskgqrfczcqrqkypramlrpyarnjyrdmpkmsrrfcpc <br>
For key: 6 <br>
bqebobrjfpqebybpqpjxoqzlkqoxzqmixqclojlrqqebob <br>
For key: 7 <br>
apdanaqieopdaxaopoiwnpykjpnwyplhwpbknikqppdana <br>
For key: 8 <br>
zoczmzphdnoczwznonhvmoxjiomvxokgvoajmhjpooczmz <br>
For key: 9 <br>
ynbylyogcmnbyvymnmgulnwihnluwnjfunzilgionnbyly <br>
For key: 10 <br>
xmaxkxnfblmaxuxlmlftkmvhgmktvmietmyhkfhnmmaxkx <br>
For key: 11 <br>
wlzwjwmeaklzwtwklkesjlugfljsulhdslxgjegmllzwjw <br>
For key: 12 <br>
vkyvivldzjkyvsvjkjdriktfekirtkgcrkwfidflkkyviv <br>
For key: 13 <br>
ujxuhukcyijxuruijicqhjsedjhqsjfbqjvehcekjjxuhu <br>
For key: 14 <br>
tiwtgtjbxhiwtqthihbpgirdcigprieapiudgbdjiiwtgt <br>
For key: 15 <br>
shvsfsiawghvspsghgaofhqcbhfoqhdzohtcfacihhvsfs <br>
For key: 16 <br>
rgurerhzvfgurorfgfznegpbagenpgcyngsbezbhggurer <br>
For key: 17 <br>
qftqdqgyueftqnqefeymdfoazfdmofbxmfradyagfftqdq <br>
For key: 18 <br>
pespcpfxtdespmpdedxlcenzyeclneawleqzcxzfeespcp <br>
For key: 19 <br>
odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo <br>
For key: 20 <br>
ncqnandvrbcqnknbcbvjaclxwcajlcyujcoxavxdccqnan <br>
For key: 21 <br>
mbpmzmcuqabpmjmabauizbkwvbzikbxtibnwzuwcbbpmzm <br>
For key: 22 <br>
laolylbtpzaolilzazthyajvuayhjawshamvytvbaaolyl <br>
For key: 23 <br>
kznkxkasoyznkhkyzysgxziutzxgizvrgzluxsuazznkxk <br>
For key: 24 <br>
jymjwjzrnxymjgjxyxrfwyhtsywfhyuqfyktwrtzyymjwj <br>
For key: 25 <br>
ixliviyqmwxlifiwxwqevxgsrxvegxtpexjsvqsyxxlivi <br>

<hr>