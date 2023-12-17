#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("blocks.in", "r", stdin);
    ll N;
    cin >> N;
    string a[N],b[N];
    rep(i,N){
        cin >> a[i] >> b[i];
    }
    vector<ll> alphabet(26,0);
    rep(i,N){
        vector<ll> cash1(26,0);
        vector<ll> cash2(26,0);
        rep(j,a[i].size()){
            cash1[a[i][j]-'a']++;
        }
        rep(j,b[i].size()){
            cash2[b[i][j]-'a']++;
        }
        rep(j,26){
            alphabet[j] += max(cash1[j],cash2[j]);
        }
    }
    freopen("blocks.out", "w", stdout);
    rep(i,26){
        cout << alphabet[i] << endl;
    }
}