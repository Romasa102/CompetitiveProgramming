#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<char,char>;
int main(){
    string S,T;
    cin >> S >> T;
    int c = 0;
    int L[100];
    P O[1000];
    rep(i,S.size()){
        if(S[i] != T[i]){
            L[c] = i;
            O[c].first = T[i];
            O[c].second = S[i];
            c++;
        }
    }
    if(c == 0){
        cout << "Yes" << endl;
        return 0;
    }else if(c != 2){
        cout << "No" << endl;
        return 0;
    }else{
        if(abs(L[0] - L[1]) == 1){
            if(O[0].first == O[1].second &&O[1].first == O[0].second){
                cout << "Yes" << endl;
                return 0;
            }
        }cout << "No" << endl;
    }
}