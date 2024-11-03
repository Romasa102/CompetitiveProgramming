#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string S;
    cin >> S;
    rep(i,S.size()){
        bool work = true;
        rep(j,S.size()){
            if(i == j)continue;
            if(S[i] == S[j]){
                work = false;
            }
        }
        if(work){
            cout << i + 1 << endl;
            return 0;
        }
    }
}