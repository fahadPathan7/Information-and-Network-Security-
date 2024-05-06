#include <bits/stdc++.h>
using namespace std;

// given frequency of english alphabets
unordered_map<char, float> frequency = {
    {'a', 8.05}, {'b', 1.67}, {'c', 2.23}, {'d', 5.10}, {'e', 12.22}, {'f', 2.14}, {'g', 2.30},
    {'h', 6.62}, {'i', 6.28}, {'j', 0.19}, {'k', 0.95}, {'l', 4.08}, {'m', 2.33}, {'n', 6.95},
    {'o', 7.63}, {'p', 1.66}, {'q', 0.06}, {'r', 5.29}, {'s', 6.02}, {'t', 9.67}, {'u', 2.92},
    {'v', 0.82}, {'w', 2.60}, {'x', 0.11}, {'y', 2.04}, {'z', 0.06}
};

// function to decipher using frequency
string decipherCipherFrequency(string ciphertext) {
    unordered_map<char, int> cipherFrequency;
    for (char c : ciphertext) {
        // taking the frequency only of alphabets
        if (isalpha(c)) {
            cipherFrequency[c]++;
        }
    }

    vector<pair<char, int>> cipherVec(cipherFrequency.begin(), cipherFrequency.end()); // the frequency of the cipher text
    vector<pair<char, float>> freqVec(frequency.begin(), frequency.end()); // the given frequency of english alphabets

    sort(cipherVec.begin(), cipherVec.end(), [](pair<char, int> &a, pair<char, int> &b) {
        return a.second > b.second;
    }); // sorting the frequency of the cipher text in descending order
    sort(freqVec.begin(), freqVec.end(), [](pair<char, float> &a, pair<char, float> &b) {
        return a.second > b.second;
    }); // sorting the frequency of the english alphabets in descending order

    unordered_map<char, char> charMap;
    // mapping both the frequencies according to the sorted order
    for (int i = 0; i < cipherVec.size(); i++) {
        charMap[cipherVec[i].first] = freqVec[i].first;
    }

    string decryptedText;
    // generating the decrypted text
    for (char c : ciphertext) {
        if (isalpha(c)) {
            decryptedText += charMap[c];
        } else {
            decryptedText += c;
        }
    }

    return decryptedText;
}

// function to decipher using key
string decipherCipherKey(string ciphertext, string key) {
    unordered_map<char, char> charMap;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    for (size_t i = 0; i < key.size(); i++) {
        charMap[alphabet[i]] = key[i];
    }

    string decryptedText;
    for (char c : ciphertext) {
        if (isalpha(c)) {
            decryptedText += charMap[c];
        } else {
            decryptedText += c;
        }
    }

    return decryptedText;
}

int main() {
    // Ciphertext 1
    string cipherText1 = "af p xpkcaqvnpk pfg, af ipqe qpri, gauuikifc tpw, ceiri udvk tiki afgarxifrphni cd eao-wvmd popkwn, hiqpvri du ear jvaql vfgikrcpfgafm du cei xkafqaxnir du xrwqedearcdkw pfg du ear aopmafpcasi xkdhafmr afcd fit pkipr. ac tpr qdoudkcafm cd lfdt cepc au pfwceafm epxxifig cd ringdf eaorinu hiudki cei opceiopcaqr du cei uaing qdvng hi qdoxnicinw tdklig dvc- pfg edt rndtnw ac xkdqiigig, pfg edt odvfcpafdvr cei dhrcpqnir--ceiki tdvng pc niprc kiopaf dfi mddg oafg cepc tdvng qdfcafvi cei kiripkqe";

    // Cipher text 2
    string cipherText2 = "aceah toz puvg vcdl omj puvg yudqecov, omj loj auum klu thmjuv hs klu zlcvu shv zcbkg guovz, upuv zcmdu lcz vuwovroaeu jczoyyuovomdu omj qmubyudkuj vukqvm. klu vcdluz lu loj avhqnlk aodr svhw lcz kvopuez loj mht audhwu o ehdoe eunumj, omj ck toz yhyqeoveg auecupuj, tlokupuv klu hej sher wcnlk zog, klok klu lcee ok aon umj toz sqee hs kqmmuez zkqssuj tckl kvuozqvu. omj cs klok toz mhk umhqnl shv sowu, kluvu toz oezh lcz yvhehmnuj pcnhqv kh wovpue ok. kcwu thvu hm, aqk ck zuuwuj kh lopu eckkeu ussudk hm wv. aonncmz. ok mcmukg lu toz wqdl klu zowu oz ok scskg. ok mcmukg-mcmu klug aunom kh doee lcw tuee-yvuzuvpuj; aqk qmdlomnuj thqej lopu auum muovuv klu wovr. kluvu tuvu zhwu klok zlhhr klucv luojz omj klhqnlk klcz toz khh wqdl hs o nhhj klcmn; ck zuuwuj qmsocv klok omghmu zlhqej yhzzuzz (oyyovumkeg) yuvyukqoe ghqkl oz tuee oz (vuyqkujeg) cmubloqzkcaeu tuoekl. ck tcee lopu kh au yocj shv, klug zocj. ck czm'k mokqvoe, omj kvhqaeu tcee dhwu hs ck! aqk zh sov kvhqaeu loj mhk dhwu; omj oz wv. aonncmz toz numuvhqz tckl lcz whmug, whzk yuhyeu tuvu tceecmn kh shvncpu lcw lcz hjjckcuz omj lcz nhhj shvkqmu. lu vuwocmuj hm pczckcmn kuvwz tckl lcz vueokcpuz (ubduyk, hs dhqvzu, klu zodrpceeu-aonncmzuz), omj lu loj womg juphkuj ojwcvuvz owhmn klu lhaackz hs yhhv omj qmcwyhvkomk sowcecuz. aqk lu loj mh dehzu svcumjz, qmkce zhwu hs lcz ghqmnuv dhqzcmz aunom kh nvht qy. klu uejuzk hs kluzu, omj aceah'z sophqvcku, toz ghqmn svhjh aonncmz. tlum aceah toz mcmukg-mcmu lu ojhykuj svhjh oz lcz lucv, omj avhqnlk lcw kh ecpu ok aon umj; omj klu lhyuz hs klu zodrpceeu- aonncmzuz tuvu scmoeeg jozluj. aceah omj svhjh loyyumuj kh lopu klu zowu acvkljog, zuykuwauv 22mj. ghq loj aukkuv dhwu omj ecpu luvu, svhjh wg eoj, zocj aceah hmu jog; omj klum tu dom dueuavoku hqv acvkljog-dhwshvkoae yovkcuz g khnukluv. ok klok kcwu svhjh toz zkcee cm lcz ktuumz, oz klu lhaackz doeeuj klu cvvuzyhmzcaeu ktumkcuz auktuum dlcejlhhj omj dhwcmn hs onu ok klcvkg-klvuu";

    // calling function (frequency)
    string decipheredCipher1 = decipherCipherFrequency(cipherText1);
    string decipheredCipher2 = decipherCipherFrequency(cipherText2);

    // Output 1 (frequency)
    cout << "Decrypted cipher text 1 (frequency):" << endl;
    cout << decipheredCipher1 << endl;

    // Output 2 (frequency)
    cout << "\nDecrypted cipher text 2 (frequency):" << endl;
    cout << decipheredCipher2 << endl;

    // calling function (key)
    decipheredCipher1 = decipherCipherKey(cipherText1, "ixtohndbeqrkglmacsvwfuypjz");
    decipheredCipher2 = decipherCipherKey(cipherText2, "bxiclqyozdthngavukfwermjps");

    // Output 1 (Key)
    cout << "\n\nDecrypted cipher text 1 (Key):" << endl;
    cout << decipheredCipher1 << endl;

    // Output 2 (Key)
    cout << "\nDecrypted cipher text 2 (Key):" << endl;
    cout << decipheredCipher2 << endl;
}
