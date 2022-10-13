#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cout<<"Enter any string : ";
    cin>>str;

    int k;
    cout<<"Enter Key for the cipher text : ";
    cin>>k;

    string t;

    for(int i=0;i<str.length();i++){
        int chindex = (str[i] - 'A') + k;
        char ch = 'A' + (chindex%26);
        t+=ch;
    }

    cout<<t<<endl;
    return 0;
}