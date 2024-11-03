#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll N;cin >> N;
    ll A[N];
    ll total = 0;
    rep(i,N){
        cin >> A[i];
        total+=A[i];
    }
    vector<ll> prefixS(2*N+1);
    prefixS[0]=0;
    rep(i,N){
        prefixS[i+1] = prefixS[i]+A[i];
    }
    rep(i,N){
        prefixS[N+i+1] = prefixS[N+i]+A[i];
    }
    ll left=0,right=total/2;
    while(right-left>1){//minValue
        bool work = false;
        ll mid = (left+right)/2;
        rep(i,N){
            auto it = lower_bound(prefixS.begin(),prefixS.end(),prefixS[i]+mid);//end itr for the min;
            auto it1 = lower_bound(prefixS.begin(),prefixS.end(),*it+mid);
            if(total - (*it - prefixS[i]) - (*it1 - *it) >= mid){
                work = true;
            }
        }
        if(work){
            left = mid;
        }else{
            right = mid;
        }
    }
    cout << left << endl;
}