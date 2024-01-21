#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);
    ll N,K;cin >> N >> K; //K,N<=1000
    ll B[N];rep(i,N)cin >> B[i]; //B<=1000
    sort(B,B+N);
    ll fAns = 0;
    repp(i,1,1000){//i is the division
        map<ll,ll> grp;
        rep(j,N){
            if(B[j] >= i){
                grp[i]+=B[j]/i;
            }
            grp[B[j]%i]++;
        }
        if(grp[i] < K/2)continue;
        grp[i]-=K/2;
        ll count = K/2;
        ll ans = 0;

        for(auto j = (--grp.end()); j != grp.begin(); j--){
            if(count == 0)break;
            if(count >= j->second){
                count -= j->second;
                ans += j->first * j->second;
            }else{
                ans += j->first * count;
                count = 0;
            }
        }
        fAns = max(fAns,ans);
    }
    cout << fAns << endl;
}