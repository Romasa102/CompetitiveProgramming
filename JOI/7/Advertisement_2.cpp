#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    P XE[N];
    set<ll> num;
    rep(i,N)cin>>XE[i].first>>XE[i].second;
    sort(XE,XE+N);
    deque<P> dif;
    vector<bool> ppl;//whether they're gonna buy it or not
    ppl.resize(N, false);
    rep(i,N)dif.push_back({XE[i].first-XE[i].second,i});
    sort(dif.begin(),dif.end());//use the dif to determine the people who u give to
    ll curM = 0;
    rep(i,N){
        if(ppl[i]){
            curM = max(curM,XE[i].first+XE[i].second);
            continue;//if u have visited continue
        }
        if(curM>=(XE[i].first+XE[i].second)){
            continue;
        }
        ll search = XE[i].first-XE[i].second;
        auto bestPower = (upper_bound(dif.begin(), dif.end(),make_pair(dif.front().first, 1LL<<50)) - 1);
        if(bestPower->second<=i){
            while(!dif.empty()&&dif.front().second<=i){
                dif.pop_front();
            }
        }
        if(dif.empty()){
            ppl[i]=true;
        }else{
            bestPower = (upper_bound(dif.begin(), dif.end(),make_pair(dif.front().first, 1LL<<50)) - 1);
            if(bestPower->first<=search){
                ppl[bestPower->second]=true;
            }else{
                ppl[i] = true;
            }
        }
    }
    ll ans = 0;
    rep(i,N){
        if(ppl[i]){
            ans ++;
        }
    }
    cout << ans << endl;
}