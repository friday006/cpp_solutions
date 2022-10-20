// affine_cipher_lab_3_20cp079_gautam vavadiya
// Hectoberfest2022
#include <bits/stdc++.h>
using namespace std;

string encrypt(string s, int a, int b)
{
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 65 && s[i] <= 90) || s[i] == ' ')
        {
            // if you want to except space to encrypt so put if condition
            if (s[i] != ' ')
            {
                temp = temp + (char)((((a * (s[i] - 'A')) + b) % 26) + 'A');
            }
            else
            {

                temp += s[i];
            }
        }
        else
        {
            if (s[i] != ' ')
            {
                temp = temp + (char)((((a * (s[i] - 'a')) + b) % 26) + 'a');
            }
        }
    }
    return temp;
}
string decrypt(string s, int a, int b)
{
    int inv = 0;
    string temp = "";
    for (int i = 0; i < 26; i++)
    {
        int f = (a * i) % 26;

        if (f == 1)
        {
            inv = i;
        }
    }

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 65 && s[i] <= 90) || s[i] == ' ')
        {
            if (s[i] != ' ')
            {

                temp = temp + (char)((((inv * (s[i] + 'A') - b)) % 26) + 'A');
            }
            else
            {
                temp += s[i];
            }
        }
        else
        {
            if (s[i] != ' ')
            {

                temp = temp + (char)((((inv * (s[i] + 'a') - b)) % 26) + 'a');
            }
            else
            {
                temp += s[i];
            }
        }
    }
    return temp;
}

int main()
{

    string s;
    cout << "Enter a string you want to Encrypt or Decrypt" << endl; // take string
    getline(cin, s);
    int a, b;
    cout << "Enter a Number for Multiplicative and additive" << endl;
    cin >> a >> b;

    cout << "Encrypt string" << endl;
    s = encrypt(s, a, b); // function call to Encrypt string
    cout << s << endl;

    cout << "Decrypt string" << endl;
    s = decrypt(s, a, b); // function call to Decrypt string
    cout << s << endl;
}
