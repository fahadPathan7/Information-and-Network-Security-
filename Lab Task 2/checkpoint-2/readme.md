# <p align='center'> Lab task 2 (Checkpoint 2)

## Question
The following two ciphers have been created using a substitution cipher with different keys.
Write a program to decipher each of them. Which input was easier to break? Explain your answer.
For your convenience, a frequency distribution of English characters is given in the next page.

```text
Cipher-1: af p xpkcaqvnpk pfg, af ipqe qpri, gauuikifc tpw, ceiri udvk tiki afgarxifrphni cd eaowvmd popkwn, hiqpvri du ear jvaql vfgikrcpfgafm du cei xkafqaxnir du xrwqedearcdkw pfg du ear aopmafpcasi xkdhafmr afcd fit pkipr. ac tpr qdoudkcafm cd lfdt cepc au pfwceafm epxxifig cd ringdf eaorinu hiudki cei opceiopcaqr du cei uaing qdvng hi qdoxnicinw tdklig dvcpfg edt rndtnw ac xkdqiigig, pfg edt odvfcpafdvr cei dhrcpqnir--ceiki tdvng pc niprc kiopaf dfi mddg oafg cepc tdvng qdfcafvi cei kiripkqe
```

```text
Cipher-2: aceah toz puvg vcdl omj puvg yudqecov, omj loj auum klu thmjuv hs klu zlcvu shv zcbkg guovz, upuv zcmdu lcz vuwovroaeu jczoyyuovomdu omj qmubyudkuj vukqvm. klu vcdluz lu loj avhqnlk aodr svhw lcz kvopuez loj mht audhwu o ehdoe eunumj, omj ck toz yhyqeoveg auecupuj, tlokupuv klu hej sher wcnlk zog, klok klu lcee ok aon umj toz sqee hs kqmmuez zkqssuj tckl kvuozqvu. omj cs klok toz mhk umhqnl shv sowu, kluvu toz oezh lcz yvhehmnuj pcnhqv kh wovpue ok. kcwu thvu hm, aqk ck zuuwuj kh lopu eckkeu ussudk hm wv. aonncmz. ok mcmukg lu toz wqdl klu zowu oz ok scskg. ok mcmukg-mcmu klug aunom kh doee lcw tuee-yvuzuvpuj; aqk qmdlomnuj thqej lopu auum muovuv klu wovr. kluvu tuvu zhwu klok zlhhr klucv luojz omj klhqnlk klcz toz khh wqdl hs o nhhj klcmn; ck zuuwuj qmsocv klok omghmu zlhqej yhzzuzz (oyyovumkeg) yuvyukqoe ghqkl oz tuee oz (vuyqkujeg) cmubloqzkcaeu tuoekl. ck tcee lopu kh au yocj shv, klug zocj. ck czm'k mokqvoe, omj kvhqaeu tcee dhwu hs ck! aqk zh sov kvhqaeu loj mhk dhwu; omj oz wv. aonncmz toz numuvhqz tckl lcz whmug, whzk yuhyeu tuvu tceecmn kh shvncpu lcw lcz hjjckcuz omj lcz nhhj shvkqmu. lu vuwocmuj hm pczckcmn kuvwz tckl lcz vueokcpuz (ubduyk, hs dhqvzu, klu zodrpceeu-aonncmzuz), omj lu loj womg juphkuj ojwcvuvz owhmn klu lhaackz hs yhhv omj qmcwyhvkomk sowcecuz. aqk lu loj mh dehzu svcumjz, qmkce zhwu hs lcz ghqmnuv dhqzcmz aunom kh nvht qy. klu uejuzk hs kluzu, omj aceah'z sophqvcku, toz ghqmn svhjh aonncmz. tlum aceah toz mcmukg-mcmu lu ojhykuj svhjh oz lcz lucv, omj avhqnlk lcw kh ecpu ok aon umj; omj klu lhyuz hs klu zodrpceeu- aonncmzuz tuvu scmoeeg jozluj. aceah omj svhjh loyyumuj kh lopu klu zowu acvkljog, zuykuwauv 22mj. ghq loj aukkuv dhwu omj ecpu luvu, svhjh wg eoj, zocj aceah hmu jog; omj klum tu dom dueuavoku hqv acvkljog-dhwshvkoae yovkcuz g khnukluv. ok klok kcwu svhjh toz zkcee cm lcz ktuumz, oz klu lhaackz doeeuj klu cvvuzyhmzcaeu ktumkcuz auktuum dlcejlhhj omj dhwcmn hs onu ok klcvkg-klvuu
```

```text
Frequency distribution English characters
a: 8.05% b: 1.67% c: 2.23% d: 5.10%
e: 12.22% f: 2.14% g: 2.30% h: 6.62%
i: 6.28% j: 0.19% k: 0.95% l: 4.08%
m: 2.33% n: 6.95% o: 7.63% p: 1.66%
q: 0.06% r: 5.29% s: 6.02% t: 9.67%
u: 2.92% v: 0.82% w: 2.60% x: 0.11%
y: 2.04% z: 0.06%
```

## Solution Approach
**Using Frequency Approach**
- stored the given frequency in an unordered_map.
- calculated the frequency of given cipher text using unordered_map.
- inserted both of the maps into vector.
- sorted the vectors according to the frequency value.
- mapped both of the frequencies.
- iterated through the cipher text and decrypted.

**Using Key Approach**
- The possibility of the keys is 403x10^24 (factorial of 26). As it is a huge number I have got the key using an online decrypt website.
- Then mapped the alphabet and key.


## Solution
```cpp
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
```

## Output
```text
Decrypted cipher text 1 (frequency):
nh o foranumlor ohd, nh eous uoie, dnwwereha goy, aseie wtmr gere nhdnifehiople at snc-ymbt ocoryl, peuomie tw sni jmnuk mhderiaohdnhb tw ase frnhunflei tw fiyustsniatry ohd tw sni ncobnhoanve frtpnhbi nhat heg oreoi. na goi utcwtranhb at khtg asoa nw ohyasnhb soffehed at ieldth sncielw pewtre ase coasecoanui tw ase wneld utmld pe utcfleaely gtrked tma- ohd stg iltgly na frtueeded, ohd stg ctmhaonhtmi ase tpiaoulei--asere gtmld oa leoia reconh the bttd cnhd asoa gtmld uthanhme ase reieorus

Decrypted cipher text 2 (frequency):
unluo fas kerb rnyh aid kerb peywlnar, aid had ueei the foider om the shnre mor snjtb bears, eker sniye hns regarvaule dnsappearaiye aid wiejpeyted retwri. the rnyhes he had urowcht uayv mrog hns trakels had iof ueyoge a loyal leceid, aid nt fas popwlarlb uelneked, fhateker the old molv gncht sab, that the hnll at uac eid fas mwll om twiiels stwmmed fnth treaswre. aid nm that fas iot eiowch mor mage, there fas also hns proloiced kncowr to garkel at. tnge fore oi, uwt nt seeged to hake lnttle emmeyt oi gr. uaccnis. at inietb he fas gwyh the sage as at mnmtb. at inietb-inie theb uecai to yall hng fell-preserked; uwt wiyhaiced fowld hake ueei iearer the garv. there fere soge that shoov thenr heads aid thowcht thns fas too gwyh om a cood thnic; nt seeged wimanr that aiboie showld possess (appareitlb) perpetwal bowth as fell as (repwtedlb) niejhawstnule fealth. nt fnll hake to ue pand mor, theb sand. nt nsi't iatwral, aid trowule fnll yoge om nt! uwt so mar trowule had iot yoge; aid as gr. uaccnis fas ceierows fnth hns goieb, gost people fere fnllnic to morcnke hng hns oddntnes aid hns cood mortwie. he reganied oi knsntnic tergs fnth hns relatnkes (ejyept, om yowrse, the sayvknlle-uaccnises), aid he had gaib dekoted adgnrers agoic the houunts om poor aid wingportait magnlnes. uwt he had io ylose mrneids, witnl soge om hns bowicer yowsnis uecai to crof wp. the eldest om these, aid unluo's makowrnte, fas bowic mrodo uaccnis. fhei unluo fas inietb-inie he adopted mrodo as hns henr, aid urowcht hng to lnke at uac eid; aid the hopes om the sayvknlle- uaccnises fere mniallb dashed. unluo aid mrodo happeied to hake the sage unrthdab, septeguer 22id. bow had uetter yoge aid lnke here, mrodo gb lad, sand unluo oie dab; aid thei fe yai yeleurate owr unrthdab-yogmortaul partnes b tocether. at that tnge mrodo fas stnll ni hns tfeeis, as the houunts yalled the nrrespoisnule tfeitnes uetfeei yhnldhood aid yognic om ace at thnrtb-three


Decrypted cipher text 1 (Key):
in a particular and, in each case, different way, these four were indispensable to him-yugo amaryl, because of his quick understanding of the principles of psychohistory and of his imaginative probings into new areas. it was comforting to know that if anything happened to seldon himself before the mathematics of the field could be completely worked out- and how slowly it proceeded, and how mountainous the obstacles--there would at least remain one good mind that would continue the research

Decrypted cipher text 2 (Key):
bilbo was very rich and very peculiar, and had been the wonder of the shire for sixty years, ever since his remarkable disappearance and unexpected return. the riches he had brought back from his travels had now become a local legend, and it was popularly believed, whatever the old folk might say, that the hill at bag end was full of tunnels stuffed with treasure. and if that was not enough for fame, there was also his prolonged vigour to marvel at. time wore on, but it seemed to have little effect on mr. baggins. at ninety he was much the same as at fifty. at ninety-nine they began to call him well-preserved; but unchanged would have been nearer the mark. there were some that shook their heads and thought this was too much of a good thing; it seemed unfair that anyone should possess (apparently) perpetual youth as well as (reputedly) inexhaustible wealth. it will have to be paid for, they said. it isn't natural, and trouble will come of it! but so far trouble had not come; and as mr. baggins was generous with his money, most people were willing to forgive him his oddities and his good fortune. he remained on visiting terms with his relatives (except, of course, the sackville-bagginses), and he had many devoted admirers among the hobbits of poor and unimportant families. but he had no close friends, until some of his younger cousins began to grow up. the eldest of these, and bilbo's favourite, was young frodo baggins. when bilbo was ninety-nine he adopted frodo as his heir, and brought him to live at bag end; and the hopes of the sackville- bagginses were finally dashed. bilbo and frodo happened to have the same birthday, september 22nd. you had better come and live here, frodo my lad, said bilbo one day; and then we can celebrate our birthday-comfortabl parties y together. at that time frodo was still in his tweens, as the hobbits called the irresponsible twenties between childhood and coming of age at thirty-three
```
<hr>
