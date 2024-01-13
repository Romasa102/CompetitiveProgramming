#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N,K;
    cin >> N >> K;
    vector<pair<P,ll>> tops(N);
    vector<pair<P,ll>> bottoms(N);
    rep(i,N){
        cin >> tops[i].first.first >> tops[i].first.second >> tops[i].second;
        cin >> bottoms[i].first.first >> bottoms[i].first.second >> bottoms[i].second;
    }
    string bitmask(K,1);
    bitmask.resize(N,0);
    ll ans = 0;
    do{
        ll minX=1LL<<60,maxX=0,minY=1LL<<60,maxY=0,minZ=1LL<<60,maxZ=0;
        rep(i,N){
            if(bitmask[i]){
                //this is the number u'll use;
                minX = min(minX,bottoms[i].first.first);
                maxX = max(maxX,tops[i].first.first);
                minY = min(minY,bottoms[i].first.second);
                maxY = max(maxY,tops[i].first.second);
                minZ = min(minZ,bottoms[i].second);
                maxZ = max(maxZ,tops[i].second);
            }
        }
        ans += (minX-maxX)*(minY-maxY)*(minZ-maxZ);
    }while(prev_permutation(bitmask.begin(),bitmask.end()));
    repp(k,K+1,N+1){
        string bitmasks(k,1);
        bitmasks.resize(N,0);
        do{
            ll minX=1LL<<60,maxX=0,minY=1LL<<60,maxY=0,minZ=1LL<<60,maxZ=0;
            rep(i,N){
                if(bitmasks[i]){
                    //this is the number u'll use;
                    minX = min(minX,bottoms[i].first.first);
                    maxX = max(maxX,tops[i].first.first);
                    minY = min(minY,bottoms[i].first.second);
                    maxY = max(maxY,tops[i].first.second);
                    minZ = min(minZ,bottoms[i].second);
                    maxZ = max(maxZ,tops[i].second);
                }
            }
            ans -= ((minX-maxX)*(minY-maxY)*(minZ-maxZ))*(k-K+1);
        }while(prev_permutation(bitmasks.begin(),bitmasks.end()));
    }
    cout << ans << endl;
}