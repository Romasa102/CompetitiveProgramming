#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N],C[N];
    map<ll,ll> mp;
    rep(i,N){
        cin >> A[i] >> C[i];
        if(mp.find(C[i]) == mp.end()){
            mp[C[i]] = A[i];
        }else{
            mp[C[i]]=min(mp[C[i]],A[i]);
        }
    }
    ll minM = 0;
    ll minIndex = 0;
    for(auto i: mp){
        if(i.second > minM){
            minIndex = i.first;
            minM = max(minM,i.second);
        }
    }
    cout << minM << endl;
}