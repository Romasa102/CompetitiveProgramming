#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    string S[N];
    rep(i,N){
        cin >> S[i];
    }
    rep(i,N){
        if(S[i][0] != 'H'&& S[i][0] != 'D'&& S[i][0] != 'C'&& S[i][0] != 'S'){
            cout << "No" << endl;
            return 0;
        }
        if(S[i][1] != 'A' &&S[i][1] != '2' &&S[i][1] != '3' &&S[i][1] != '4' &&S[i][1] != '5' &&S[i][1] != '6' &&S[i][1] != '7' &&S[i][1] != '8' &&S[i][1] != '9' &&S[i][1] != 'T' &&S[i][1] != 'J' &&S[i][1] != 'Q' &&S[i][1] != 'K'){
            cout << "No" << endl;
            return 0;
        }
    }
    rep(i,N){
        rep(j,N){
            if(i != j){
                if(S[i] == S[j]){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}