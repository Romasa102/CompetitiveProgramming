#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);
    ll N,B;cin>>N>>B;
    ll f[N];rep(i,N)cin >> f[i];
    ll s[B+1],d[B+1];rep(i,B)cin >> s[i] >> d[i];
    priority_queue<P> pq;
    rep(i,N){
        pq.push({f[i],i});
    }
    vector<ll> minS(N+1,0);
    vector<ll> gap(N+1,0);
    rep(i,N){
        if(pq.empty())break;
        while(!pq.empty()){
            ll TopInd = pq.top().second;
            if(TopInd+1>=N){
                if(gap[TopInd-1]+1<=i){
                    pq.pop();
                    ll NewGap = gap[TopInd-1]+1;
                    gap[TopInd]=NewGap;
                    ll curs = -gap[TopInd-1];
                    for(ll j = 0; j > curs; j--){
                        if(TopInd-1+j<0)continue;
                        gap[TopInd-1+j]=NewGap;
                    }
                    continue;
                }
            }else if(TopInd-1<=0){
                if(gap[TopInd+1]+1<=i){
                    pq.pop();
                    ll NewGap = gap[TopInd+1]+1;
                    gap[TopInd]=NewGap;
                    ll cur = gap[TopInd+1];
                    rep(j,cur){
                        if(TopInd+1+j>=N)continue;
                        gap[TopInd+1+j]=NewGap;
                    }
                    continue;
                }
            }else if(gap[TopInd+1]+gap[TopInd-1]+1<=i){
                pq.pop();
                ll NewGap = gap[TopInd+1]+gap[TopInd-1]+1;
                gap[TopInd]=NewGap;
                ll cur =gap[TopInd+1];
                rep(j,cur){
                    if(TopInd+1+j>=N)continue;
                    gap[TopInd+1+j]=NewGap;
                }
                ll curs = -gap[TopInd-1];
                for(ll j = 0; j > curs; j--){
                    if(TopInd-1+j<0)continue;
                    gap[TopInd-1+j]=NewGap;
                }
                continue;
            }
            break;
        }
        minS[i]=pq.top().first;
    }
    rep(i,B){
        if(s[i] >= minS[d[i]-1]){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }
}