#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,k;
    cin >> n >> k;
    ll Num[k];
    map<ll,bool> have;
    bool white = false;
    rep(i,k){
        cin >> Num[i];
        if(Num[i] == 0){
            white = true;
            continue;
        }
        have[Num[i]] = true;
    }
    sort(Num,Num+k);
    ll contCount[n];
    ll ans = 0;
    repp(i,1,n){
        if(have.find(i) != have.end()){
            contCount[i] = contCount[i-1] +1;
            ans = max(ans,contCount[i]);
        }else{
            contCount[i] = 1;
        }
    }
    ll cash = 0;
    ll num = 0;
    for(int i = n - 1; i > 0; i--){
        if(cash != 0){

        }
        if(contCount[i] != 1){
            cash = contCount[i];
        }
    }
}