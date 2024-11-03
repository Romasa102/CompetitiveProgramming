#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll T;cin >> T;
    rep(q,T){
        ll N,Q,C;cin >> N >> Q >> C;
        ll cow[N];rep(i,N)cin >> cow[i];
        P ah[Q];
        map<ll,ll> nums;
        rep(i,Q){
            cin >> ah[i].first >> ah[i].second;
            nums[ah[i].second-1] = ah[i].first-1;
        }
        vector<ll> prefixMax(N+1);
        if(cow[0] == 0)cow[0]=1;
        prefixMax[0]=cow[0];
        bool work = true;
        repp(i,1,N){
            if(nums.find(i) == nums.end()){//no constraints
                if(cow[i]==0)cow[i]=1;
                prefixMax[i] = max(prefixMax[i-1],cow[i]);
            }else{//if there is a constraints
                if(cow[i]==0){
                    cow[i] = prefixMax[nums[i]]+1;
                    if(cow[i] > C)work = false;
                    prefixMax[i] = max(prefixMax[i-1],cow[i]);
                }else{
                    if(cow[i] < prefixMax[nums[i]]+1){
                        work = false;
                    }else{
                        prefixMax[i] = max(prefixMax[i-1],cow[i]);
                    }
                }
            }
        }
        if(!work){
            cout << -1  << endl;
            continue;
        }
        rep(i,N)cout << cow[i] << " ";
        cout << endl;
    }
}