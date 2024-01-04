#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<ll> parents;
bool compareS(pair<P,ll> a,pair<P,ll> b){
    return a.first.second<b.first.second;
}
vector<ll> ans;
ll find(ll x){
    if(parents[x] == x){
        return x;
    }
    return find(parents[x]);
}
void countP(ll x){
    if(parents[x] == x){
        return;
    }
    ans[parents[x]]++;
    countP(parents[x]);
}
int main(){
    ll N;cin >> N;
    vector<pair<P,ll>> north;
    vector<pair<P,ll>> east;
    rep(i,N){
        char iden;
        cin >> iden;
        ll a,b;
        cin >> a >> b;
        if(iden == 'N'){
            north.push_back({{a,b},i});
        }else if(iden == 'E'){
            east.push_back({{a,b},i});
        }
    }
    sort(east.begin(),east.end(), compareS);
    sort(north.begin(),north.end());
    parents.resize(N,-1);
    ans.resize(N,0);
    rep(i,N)parents[i]=i;
    rep(i,east.size()){
        rep(j,north.size()){
            if(parents[east[i].second]!=east[i].second || parents[north[j].second]!=north[j].second)continue;
            if(east[i].first.second<north[j].first.second)continue;
            if(east[i].first.first>=north[j].first.first)continue;
            ll xdif = north[j].first.first-east[i].first.first;
            ll ydif = east[i].first.second-north[j].first.second;
            if(xdif==ydif)continue;
            if(xdif>ydif){
                parents[east[i].second]=north[j].second;
            }else{
                parents[north[j].second]=east[i].second;
            }
        }
    }
    rep(i,N)countP(i);
    rep(i,N)cout << ans[i] << endl;
}