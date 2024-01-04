#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("lifeguards.in","r",stdin);
    freopen("lifeguards.out","w",stdout);
    ll N;cin >> N;
    P ab[N];rep(i,N)cin>>ab[i].first>>ab[i].second;
    sort(ab,ab+N);
    ll left = 0;ll right = 0;
    ll totalT = 0;
    rep(i,N){
        if(ab[i].second>right){
            left = max(right,ab[i].first);
            totalT+=ab[i].second-left;
            right = ab[i].second;
        }
    }
    ll smallInd = totalT;
    right = 0;
    rep(i,N-1){
        smallInd=min(smallInd,min(ab[i].second,ab[i+1].first)-max(ab[i].first,right));
        right = max(right,ab[i].second);
    }
    smallInd=min(smallInd,ab[N-1].second-max(ab[N-1].first,right));
    cout << totalT-max(smallInd,0LL) << endl;
}