#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    ll fans = 1LL<<60;
    rep(i,N){
        rep(j,3){
            ll ans = 0;
            stack<P> St;
            rep(k,N){
                ll cur = A[k];
                if(i==k)cur=j+1;
                if(St.empty()){
                    St.push({cur,1});
                    continue;
                }
                if(cur==St.top().first){
                    St.top().second++;
                    continue;
                }else{
                    if(St.top().second>=4){
                        St.pop();
                        if(St.empty()){
                            St.push({cur,1});
                            continue;
                        }
                        if(St.top().first!=cur){
                            St.push({cur,1});
                        }else{
                            St.top().second++;
                        }
                    }else{
                        St.push({cur,1});
                    }
                }
            }
            while(!St.empty()){
                if(St.empty())continue;
                if(St.top().second>=4){
                    St.pop();
                    continue;
                }
                ans += St.top().second;
                St.pop();
            }
            fans=min(fans,ans);
        }
    }
    cout << fans << endl;
}