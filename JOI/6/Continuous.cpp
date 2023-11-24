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
    ll fans = 0;
    rep(i,N){
        rep(j,3){
            ll ans = 0;
            stack<P> St;
            rep(k,N){
                if(i==k){
                    if(St.empty()){
                        St.push({j,1});
                        continue;
                    }
                    if(j+1==St.top().first){
                        if(St.empty())continue;
                        St.top().second++;
                    }else{
                        if(St.top().second>=4){
                            St.pop();
                        }
                        if(j+1==St.top().first){
                            St.push({j+1,1});
                            St.top().second++;
                        }
                    }
                    continue;
                }
                if(St.empty()){
                    St.push({A[k],1});
                    continue;
                }
                if(A[k]==St.top().first){
                    St.top().second++;
                }else{
                    if(St.top().second>=4){
                        if(St.empty())continue;
                        St.pop();
                    }
                    St.push({A[k],1});
                }
            }
            while(!St.empty()){
                if(St.empty())continue;
                ans += St.top().second;
                St.pop();
            }
            fans=max(fans,ans);
        }
    }
    cout << fans << endl;
}