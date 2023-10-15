#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    string S;
    cin >> N >> S;
    multiset<ll> ORI;
    ll ans = 0;
    rep(i,N){
        ORI.insert(S[i]-'0');
    }
    rep(i,3162280){
        ll powered = i*i;
        multiset<ll> TEST;
        while(powered!=0){
            TEST.insert(powered%10);
            powered/=10;
        }
        if(ORI.size()>=TEST.size()) {
            while (TEST.size() != ORI.size()) {
                TEST.insert(0);
            }
        }else{
            break;
        }
        if(TEST==ORI){
            ans++;
        }
    }
    cout << ans << endl;
}