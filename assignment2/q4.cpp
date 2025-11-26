a. #include <iostream>
using namespace std;

int main() {
    char s1[50], s2[50];
    cin >> s1 >> s2;

    int i = 0;
    while (s1[i] != '\0') i++;

    int j = 0;
    while (s2[j] != '\0') {
        s1[i++] = s2[j++];
    }
    s1[i] = '\0';

    cout << "Concatenated: " << s1;
}
b. 

int main() {
    char s[50];
    cin >> s;

    int i = 0;
    while (s[i] != '\0') i++;

    int j = 0;
    i--;
    while (j < i) swap(s[j++], s[i--]);

    cout << "Reversed: " << s;
}
c.
bool isVowel(char c) {
    c = tolower(c);
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}

int main() {
    char s[50], out[50];
    cin >> s;

    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (!isVowel(s[i]))
            out[j++] = s[i];
    out[j] = '\0';

    cout << "After removing vowels: " << out;
}
d. #include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;

    char s[20][50];

    for (int i = 0; i < n; i++)
        cin >> s[i];

    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (strcmp(s[i], s[j]) > 0)
                swap(s[i], s[j]);

    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++)
        cout << s[i] << endl;
}
 e.
   #include <iostream>
using namespace std;

int main() {
    char c;
    cin >> c;

    if (c >= 'A' && c <= 'Z')
        c = c + 32;

    cout << "Lowercase: " << c;
}

