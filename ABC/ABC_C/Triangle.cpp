#include <bits/stdc++.h>
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using namespace std;
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    vector<P> pos(N);
    rep(i,N){
        cin >> pos[i].first >> pos[i].second;
    }
    ll ans = 0;
    ll tricount = 0;
    for(ll i = 0; i < N - 2; i++){
        for(ll j = i + 1; j < N - 1; j++){
            for(ll k = j + 1; k < N; k++){
                tricount++;
                if((pos[i].first - pos[j].first) * (pos[j].second - pos[k].second) == (pos[j].first - pos[k].first) * (pos[i].second - pos[j].second)){
                    ans++;
                }
            }
        }
    }
    cout << tricount - ans << endl;
}