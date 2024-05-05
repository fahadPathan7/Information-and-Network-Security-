#include <bits/stdc++.h>
using namespace std;

int main() {
    string cipher = "odroboewscdrolocdcwkbdmyxdbkmdzvkdpybwyeddrobo";
    for (int key = 0; key < 26; key++) {
        cout << "For key: " << key << endl;
        for (int j = 0; j < cipher.length(); j++) {
            int decrypt = (((int)cipher[j] - key) % 26 + 97);
            cout << (char)decrypt;
        }
        cout << endl;
    }
}