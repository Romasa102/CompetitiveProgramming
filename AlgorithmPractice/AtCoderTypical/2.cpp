#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    if(N%2==1)return 0;
    vector<string> sets;
    for(ll i = 0;i<(1LL<<N); i++){
        char cur[N];
        rep(j,N){
            cur[i] = 'a';
        }
        rep(j,N){
            if(i&1<<j){
                cur[j] = 'b';
            }
        }
        sets.push_back(cur);
    }
    rep(i,sets.size()){
        queue<char> Lbracket;
        rep(j,sets[i].size()){
            if(sets[i][j] == '('){
                Lbracket.
            }
        }
    }
}