#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("mountains.in","r",stdin);
    freopen("mountains.out","w",stdout);
    ll N;
    cin >> N;
    vector<P> mountain(N);
    rep(i,N)cin >> mountain[i].first >> mountain[i].second;
    vector<P> dif(N);
    vector<P> sum(N);
    vector<ll> work(N,-1);//-1 undefined , 0 false, 1 work
    rep(i,N){
        dif[i] = {mountain[i].second - mountain[i].first,i};
        sum[i] = {mountain[i].first + mountain[i].second,i};
    }
    sort(dif.begin(),dif.end(),greater<P>());
    sort(sum.begin(),sum.end(),greater<P>());
    rep(i,N){
        if(work[dif[i].second]!=0){
            ll cash = i;
            map<ll,ll> search;
            search[dif[cash].second]=1;
            while(cash+1 <= N-1 && dif[cash].first==dif[cash+1].first){
                cash++;
                if(work[dif[cash].second]!=0){
                    search[dif[cash].second]=1;
                }
            }
            while(search.size()>0){
                if(search.find(sum.back().second) != search.end()){
                    search.erase(sum.back().second);
                    if(search.size() == 0){
                        work[sum.back().second]=1;
                        sum.pop_back();
                        break;
                    }
                }
                work[sum.back().second]=0;
                sum.pop_back();
            }
        }
    }
    ll ans = 0;
    rep(i,N){
        if(work[i]==1)ans++;
    }
    cout << ans << endl;
}