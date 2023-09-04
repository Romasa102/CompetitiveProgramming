#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll N;
    cin >> N;
    ll I[N];
    ll J[N];
    ll K[N];
    ll R[N];
    rep(i,N){
        cin >> I[i] >> J[i] >> K[i] >> R[i];
        I[i]--;
        J[i]--;
        K[i]--;
    }
    vector<ll> broken(a+b+c,2);
    rep(i,N){
        if(R[i] == 1){
            broken[I[i]] = 1;
            broken[J[i]] = 1;
            broken[K[i]] = 1;
        }
    }
    rep(i,N){
        if(R[i] == 0){
            if(broken[I[i]] == 1 && broken[J[i]] == 1 && broken[K[i]] == 2){
                broken[K[i]] = 0;
            }
            if(broken[I[i]] == 1 && broken[J[i]] == 2 && broken[K[i]] == 1){
                broken[J[i]] = 0;
            }
            if(broken[I[i]] == 2 && broken[J[i]] == 1 && broken[K[i]] == 1){
                broken[I[i]] = 0;
            }
        }
    }
    rep(i,N){
        cout << broken[i] << endl;
    }
}