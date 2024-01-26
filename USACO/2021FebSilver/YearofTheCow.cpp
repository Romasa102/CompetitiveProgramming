#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<P> finalRoute;
void merge(ll a,ll b){

}
int main(){
    ll N,K;//N = number of ppl wanna meat , K = number of warp that could be made
    cin >> N >> K;
    ll year[N];
    rep(i,N)cin >> year[i];
    map<ll,ll> grp;
    rep(i,N){
        grp[(year[i]+11)/12]++;
    }
    vector<pair<ll,P>> diff;
    for(auto i = grp.begin(); i != grp.end(); i++){
        finalRoute.push_back(*i->second,*i->second);
        diff.push_back({(*(++i)->first)-(*i->first),{*i->second,*(++i)->second}});
    }
    sort(diff.begin(),diff.end());
    rep(i,N){
        finalRoute.erase(std::find(finalRoute.begin(), finalRoute.end(),diff[i].second.first));
        finalRoute.erase(std::find(finalRoute.begin(), finalRoute.end(),diff[i].second.second));
        finalRoute.push_back({diff[i].second.first,diff[i].second.second});
    }
}