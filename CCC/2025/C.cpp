#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

int main(){
    ll N,M,Q;
    cin >> N >> M >> Q;
    if(M==1){
        ll P[N];
        multiset<ll> ms;
        rep(i,N){
            ll c;
            cin >> c >> P[i];
            ms.insert(P[i]);
        }
        cout << *ms.rbegin() << endl;
        rep(i,Q){
            ll a,b,c;
            cin >> a >> b >> c;
            b--;
            if(a == 2){
                ms.erase(ms.find(P[b]));
                P[b] = c;
                ms.insert(c);
            }
            cout << *ms.rbegin() << endl;
        }
    }
    if(M==2){
        ll C[N],P[N];
        multiset<ll> ms1;
        multiset<ll> ms2;
        rep(i,N){
            cin >> C[i] >> P[i];
            if(C[i]==1){
                ms1.insert(P[i]);
            }else{
                ms2.insert(P[i]);
            }
        }
        cout << *ms1.rbegin()+ *ms2.rbegin() << endl;
        rep(i,Q){
            ll a,b,c;
            cin >> a >> b >> c;
            b--;
            if(a==1){
                if(C[b]==1){
                    ms1.erase(ms1.find(P[b]));
                    ms2.insert(P[b]);
                }else{
                    ms2.erase(ms2.find(P[b]));
                    ms1.insert(P[b]);
                }
            }
            if(a == 2){
                if(C[b]==1){
                    ms1.erase(ms1.find(P[b]));
                    P[b]=c;
                    ms1.insert(c);
                }else{
                    ms2.erase(ms2.find(P[b]));
                    P[b]=c;
                    ms2.insert(c);
                }
            }  
            cout << *ms1.rbegin()+ *ms2.rbegin() << endl;
        }
    }
    if(M!=1){
        vector<vector<ll>> color(M);
        ll C[N],P[N];
        rep(i,N){
            cin >> C[i] >> P[i];
            color[C[i]-1].push_back(P[i]);
        }
        vector<ll> useNum(M);
        rep(i,M){
            sort(color[i].begin(),color[i].end());
            useNum[i]=color[i][color[i].size()-1];
            color[i].pop_back();
        }
        ll biggestNow = 0;
        rep(i,M){
            if(color[i].size()==0)continue;
            biggestNow = max(biggestNow,color[i][color[i].size()-1]);
        }
        sort(useNum.begin(),useNum.end());
        ll ans = 0;
        if(useNum[0] < biggestNow){
            ans += biggestNow;
            repp(i,1,M){
                ans += useNum[i];
            }
        }else{
            rep(i,M){
                ans += useNum[i];
            }
        }
        cout << ans << endl;
    }
    
    
}