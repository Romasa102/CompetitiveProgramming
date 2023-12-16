#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,k;
    cin >> n >> k;
    set<string> num;
    ll card[n];
    rep(i,n){
        cin >> card[i];
    }
    sort(card,card+n);
    do{
        string s = "";
        rep(i,k){
            s+=to_string(card[i]);
        }
        num.insert(s);
    }while(next_permutation(card,card+n));
    cout << num.size() << endl;
}