#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string O;
    deque<char> S;
    ll MAP[30];
    cin >> O;
    rep(i,O.size()){
        S.push_back(O[i]);
    }
    rep(i,30)MAP[i]=0;
    rep(i,S.size()){
        MAP[S[i]-'A']++;
    }
    ll ans = 0;
    while (S.size()!=1){
        ll current = S[0]-'A';
        ll num=1;
        repp(k,1,S.size()){
            num*=k;
        }
        ll div = 1;
        for(ll j=30;j>=0;j--){
            ll factorial=1;
            repp(k,1,MAP[j]+1){
                factorial*=k;
            }
            div*=factorial;
        }
        for(ll j=current-1;j>=0;j--){
            if(MAP[j]==0)continue;
            ans+=num/div*MAP[j];
        }
        MAP[S[0]-'A']--;
        S.pop_front();
    }
    cout << ans + 1<< endl;
}