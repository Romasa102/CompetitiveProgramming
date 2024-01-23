#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("socdist.in","r",stdin);
    freopen("socdist.out","w",stdout);
    ll N,M;cin >> N >> M;
    vector<P> grass(M);rep(i,M)cin >> grass[i].first >> grass[i].second;
    sort(grass.begin(),grass.end());
    ll left=0,right=1LL<<62;
    ll fAns = 1;
    while(right-left>1){
        ll mid = (left+right)/2;
        ll counter = 0;
        ll current = 0;
        bool work = false;
        while(true){
            counter++;
            P finds = {current,-1};
            auto consideration = upper_bound(grass.begin(),grass.end(),finds);
            if(current > (*(consideration-1)).second){
                if(consideration == grass.end())break;
                current = (*(consideration)).first;
            }
            current += mid;
            if(counter >= N)work = true;
        }
        if(work){
            left = mid;
            fAns = max(fAns,mid);
        }else{
            right = mid;
        }
    }
    cout << fAns << endl;
}