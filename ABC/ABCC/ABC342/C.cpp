#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    string S;cin >> S;
    ll Q;cin >> Q;
    vector<char> c(Q),d(Q);
    map<char,char> mp;
    map<char,vector<char>> children;
    rep(i,26)children['a' + i ].push_back('a' + i);
    rep(i,26)mp['a' + i ] = ('a' + i);
    rep(i,Q){
        cin >> c[i] >> d[i];
        if(c[i] == d[i])continue;
        rep(j,children[c[i]].size()){
            children[d[i]].push_back(children[c[i]][j]);
            mp[children[c[i]][j]] = d[i];
        }
        children[c[i]].clear();
    }
    rep(i,N){
        cout << mp[S[i]];
    }cout << endl;
}