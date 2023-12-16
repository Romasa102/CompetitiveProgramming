#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,M,Q;
    cin >> N >> M >> Q;
    P PA[N];
    rep(i,N){
        cin >> PA[i].first >> PA[i].second;
        PA[i].second--;
    }
    vector<ll> total(N+1,0);
    total[0]=0;
    repp(i,1,N+1){
        total[i]=total[i-1]+PA[i-1].first;
    }
    vector<vector<P>>types(M+1,vector<P>(1,{0,0}));//types[type][index]={index,number}
    rep(i,N){
        if(types[PA[i].second].size()==1){
            types[PA[i].second].push_back({i+1,PA[i].first});
        }else{
            types[PA[i].second].push_back({i+1,PA[i].first+(ll)types[PA[i].second][types[PA[i].second].size()-1].second});
        }
    }
    rep(i,Q){
        ll t,l,r;
        cin >> t >> l >> r;
        t--;l--;
        ll normalPrice = total[r]-total[l];
        ll discountPriceL=0;
        if(lower_bound(types[t].begin(),types[t].end(), make_pair(l,1LL<<60))!=types[t].begin()){
            discountPriceL = (*(lower_bound(types[t].begin(),types[t].end(), make_pair(l,1LL<<60))-1)).second;
        }
        ll discountPriceR = 0;
        if(upper_bound(types[t].begin(),types[t].end(), make_pair(r,1LL<<60))!=types[t].begin()){
            discountPriceR = (*(upper_bound(types[t].begin(),types[t].end(), make_pair(r,1LL<<60))-1)).second;
        }
        cout << normalPrice-(discountPriceR-discountPriceL)/2 << endl;
    }
}