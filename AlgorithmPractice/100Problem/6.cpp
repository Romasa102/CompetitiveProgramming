#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    set<string> pattern;
    rep(i,0,N){
        if(i>=N-2)continue;
        rep(j,i+1,N){
            if(j>=N-1)continue;
            rep(k,j+1,N){
                string concat = "";
                concat += S[i];
                concat += S[j];
                concat += S[k];
                pattern.insert(concat);
            }
        }
    }
    cout << pattern.size() << endl;
}