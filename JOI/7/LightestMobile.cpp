#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
map<ll,P> kids;
map<ll,P> ratios;
ll gcd(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a/gcd(a,b) * b;
}
ll weight(ll a){
    if(kids[a].first==-1 && kids[a].second==-1){
        return (ratios[a].first + ratios[a].second);
    }
    ll left = 0;
    ll right = 0;
    if(kids[a].first == -1){
        left = 1;
    }else{
        left = weight(kids[a].first);
    }
    if(kids[a].second == -1){
        right = 1;
    }else{
        right = weight(kids[a].second);
    }
    return left*right/gcd(left*ratios[a].first,right*ratios[a].second) * (ratios[a].first+ratios[a].second);
}
int main(){
    ll n;
    cin >> n;
    ll parent[n];
    rep(i,n)parent[i] = 1000;
    rep(i,n){
        ll p,q,a,b;
        cin >> p >> q >> a >> b;
        ll GCDR = gcd(p, q);
        ratios[i] = {p/GCDR,q/GCDR};
        kids[i] = {a-1,b-1};
        if(a!=0){
            parent[a-1] = i;
        }
        if(b!=0){
            parent[b-1] = i;
        }
    }
    rep(i,n){
        if(parent[i] == 1000){
            cout << weight(i) << endl;
            return 0;
        }
    }

}