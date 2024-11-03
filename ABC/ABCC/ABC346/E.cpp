#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll H,W,M;
    cin >> H >> W >> M;
    ll initi =H*W;
    map<P,ll> did;
    ll task[M];
    ll a[M];
    ll x[M];
    map<ll,ll> skip;
    rep(i,M){
        cin >> task[i] >> a[i] >> x[i];
        if(did.find({task[i],a[i]})!=did.end()){
            skip[did[{task[i],a[i]}]]=1;
        }
        did[{task[i],a[i]}]=i;
    }
    map<ll,ll> color;
    for(ll i=M-1;i>=0;i--){
        if(skip.find(i)!=skip.end())continue;
        if(task[i]==1){
            color[x[i]]+=W;
            if(H==0)continue;
            H--;
        }
        if(task[i]==2){
            color[x[i]]+=H;
            if(W==0)continue;
            W--;
        }
    }
    ll cur =0;
    color[0]=0;
    ll siz = color.size()-1;
    for(auto i:color){
        if(i.first==0)continue;
        if(i.second==0)siz--;
        cur += i.second;
    }
    if(initi != cur){
        siz++;
    }
    cout << siz<< endl;
    for(auto i:color){
        if(i.first==0){
            if(initi==cur)continue;
            cout << 0 << " " << initi - cur << endl;
            continue;
        }
        if(i.second==0)continue;
        cout << i.first << " " << i.second << endl;
    }
}