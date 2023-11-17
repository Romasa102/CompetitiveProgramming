#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll M,N;
    cin >> N>>M;
    ll L[N];
    ll maxL;
    rep(i,N){
        cin >> L[i];
        maxL=max(maxL,L[i]);
    }
    rep(i,N)L[i]++;
    ll left = maxL;
    ll right = 1LL<<50;
    while(left+1<right){
        ll mid=(left+right)/2;
        ll current = 0;
        ll usedR=1;
        rep(i,N){
            current+=L[i];
            if(current>mid){
                usedR++;
                current=L[i];
            }
        }
        if(usedR<=M){
            right = mid;
        }else{
            left = mid;
        }
    }
    cout << right-1<< endl;
}