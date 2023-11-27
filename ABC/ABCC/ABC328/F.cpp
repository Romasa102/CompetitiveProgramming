#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
vector<vector<ll>> child;
vector<ll> parent;
vector<ll> num;//number itself
ll find(ll x){
    if(parent[x]==x){
        return x;
    }
    return find(parent[x]);
}
void Unite(ll a,ll b,ll d){//a=b+d, b=a-d
    if(num[a]==1LL<<60 && num[b]==1LL<<60){
        num[a]=0;
        num[b]=-d;
        parent[b]=a;
        child[a].push_back(b);
        return;
    }
    if(child[find(a)].size()>child[find(b)].size()){//merge b into a
        ll cha = (num[a]-d)-num[b];
        for(ll i:child[find(b)]){
            child[find(a)].push_back(i);
            num[i]+=cha;
        }
        child[find(b)].clear();
        parent[find(b)]= find(a);
    }else{//merge a into b //a=b+d, b=a-d
        ll cha = (num[b]+d)-num[a];
        for(ll i:child[find(a)]){
            child[find(b)].push_back(i);
            num[i]+=cha;
        }
        child[find(a)].clear();
        parent[find(a)]= find(b);
    }
}
int main(){
    ll N,Q;
    cin >> N >> Q;
    parent.resize(N+1);
    child.resize(N+1,{});
    rep(i,N+1)child[i].push_back(i);
    rep(i,N+1)parent[i]=i;
    num.resize(N+1,1LL<<60);
    vector<ll> ans;
    rep(i,Q){
        ll a,b,d;
        cin >> a >> b >> d;
        a--;b--;
        if(find(a)== find(b)){
            if(num[a]-d==num[b]){
                ans.push_back(i+1);
            }
        }else{
            Unite(a,b,d);
            ans.push_back(i+1);
        }
    }
    for(ll i: ans){
        cout << i << " ";
    }cout << endl;
}