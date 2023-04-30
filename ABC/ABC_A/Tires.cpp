#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    string ans;
    ans = S.substr(S.length() - 2);
    if(ans == "er"){
        cout << "er" << endl;
    }else if(ans == "st"){
        cout << "ist" << endl;
    }
}