#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    ll A[N];rep(i,N)cin >> A[i];
    ll minN = 1LL<<32;
    ll cur = 0;
    rep(i,N){
        cur += A[i];
        minN = min(minN,cur);
    }
    if(minN >=0){
        cout << cur << endl;
    }else{
        cout << cur-minN << endl;
    }
}