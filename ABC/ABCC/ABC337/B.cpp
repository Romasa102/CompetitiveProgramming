#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    char Phase = 'A';
    rep(i,S.size()){
        if(S[i] == Phase){
            continue;
        }
        if(S[i] == 'B' && Phase == 'A'){
            Phase = 'B';
            continue;
        }
        if(S[i] == 'C' && (Phase == 'A'||Phase == 'B')){
            Phase = 'C';
            continue;
        }
        cout << "No" << endl;
        return  0;
    }
    cout << "Yes" << endl;
}