#include <bits/stdc++.h>
using namespace std;
int main(){
    string str = "abcdefghijklmnopqrstuvwxyz";
    int P[30];
    for (int i = 0; i < 26; i++)
    {
        cin >> P[i];
    }

    string S;
    for (int i = 0; i < 26; i++)
    {
        S += str[P[i] - 1];
    }
    cout << S << endl;
}