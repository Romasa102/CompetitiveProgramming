#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    ll a[N];
    rep(i,N)cin>>a[i];
    ll low=0,high=N;
    while(high-low>1){
        ll mid = (low+high)/2;
        ll res = 0, len = 1;
        repp(i,1,N){
            if(a[i-1] == a[i]){
                len++;
                if(len > mid){
                    res++;
                    i++;
                    len = 1;
                }
            }else{
                len = 1;
            }
        }
        if(res>K){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout << low<< endl;
}