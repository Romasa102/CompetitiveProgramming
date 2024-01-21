#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("cowdance.in","r",stdin);
    freopen("cowdance.out","w",stdout);
    ll N,T;cin >> N >> T;
    vector<ll>d(N);rep(i,N)cin >> d[i];
    ll left=0,right=1LL<<62;
    ll fAns = N;
    while(right-left>1){
        ll mid = (left+right)/2;
        priority_queue<ll,vector<ll>,greater<ll>>dancing;
        if(mid>N){
            right = mid;
            continue;
        }
        rep(i,mid){
            dancing.push(d[i]);
        }
        ll cur = mid;
        ll time = 0;
        while(!dancing.empty()){
            ll smallest = dancing.top();
            dancing.pop();
            time = max(time,smallest);
            if(cur < N){
                dancing.push(smallest+d[cur]);
                cur++;
            }
        }
        if(time <= T){
            fAns = min(fAns,mid);
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << fAns << endl;
}