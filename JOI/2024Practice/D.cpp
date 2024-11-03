#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M;
    string S;
    cin >> N >> M >> S;
    queue<ll> num;
    rep(i,M){
        if(S[i] == 'I'){
            char current = 'I';
            ll continuous = 0;
            while(S[i] == current){
                if(S[i] == 'I')continuous++;
                i++;
                if(current == 'I'){
                    current = 'O';
                }else{
                    current = 'I';
                }
            }
            i--;
            num.push(continuous-1);
        }
    }
    ll ans = 0;
    while(!num.empty()){
        ll cur = num.front();
        num.pop();
        if(cur >= N){
            ans += cur-N+1;
        }
    }
    cout << ans << endl;
}