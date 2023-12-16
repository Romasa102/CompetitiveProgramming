#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    map<ll,ll> counter;
    rep(i,N){
        counter[A[i]]=1;
    }
    rep(i,N){
        if(counter.find(A[i]-3)==counter.end())continue;
        counter[A[i]-3]=2;
    }
    rep(i,N){
        if(counter.find(A[i]-6)==counter.end())continue;
        if(counter[A[i]-6]==2){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}