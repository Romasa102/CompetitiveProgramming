#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll p[N];
    ll dis[N];
    ll RequiredDis[N];
    rep(i,N){
        cin >> p[i];
    }
    rep(i,N){
        dis[p[i]] = i-p[i];
        RequiredDis[i] = 0;
    }
    rep(i,N){
        if(-1 - dis[i] >= 0){
            RequiredDis[-1 - dis[i]]++;
        }else{
            RequiredDis[-1 - dis[i] + N]++;
        }
        if(0 - dis[i] >= 0){
            RequiredDis[-dis[i]]++;
        }else{
            RequiredDis[-dis[i] + N]++;
        }
        if(1 - dis[i] >= 0){
            RequiredDis[1 - dis[i]]++;
        }else{
            RequiredDis[1 - dis[i] + N]++;
        }
    }
    ll maxAmount = 0;
    rep(i,N){
        if(RequiredDis[i] > maxAmount){
            maxAmount = RequiredDis[i];
        }
    }
    cout << maxAmount << endl;
}