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
    ll B[N];
    ll smallest = 1LL<<40;
    ll smallestInd;
    ll smallestB;
    vector<ll> BGROUP;
    ll ans = 0;
    rep(i,N){
        cin >> A[i] >> B[i];
        if(smallest>(A[i]+B[i])){
            smallest = A[i]+B[i];
            smallestB = B[i];
            smallestInd = i;
        }else if(smallest==A[i]+B[i]){
            if(B[i] < smallestB){
                smallestB = B[i];
                smallestInd = i;
            }
        }
    }
    ans += smallest;
    vector<P> sum;
    BGROUP.push_back(smallestB);
    rep(i,N){
        if(i==smallestInd)continue;
        if(B[i]>smallestB){
            sum.push_back({A[i]+B[i]-smallestB,i});
        }else{
            sum.push_back({A[i],i});
        }
    }
    sort(sum.begin(),sum.end());
    ans+=sum[0].first;
    BGROUP.push_back(B[sum[0].second]);
    smallestB = min(smallestB,B[sum[0].second]);
    ans+=smallestB;
    vector<ll> Sum2;
    rep(i,N){
        if(i==smallestInd||i==sum[0].second){
            continue;
        }
        if(B[i] > smallestB){
            Sum2.push_back(A[i]+B[i]-smallestB);
        }else{
            Sum2.push_back(A[i]);
        }
    }
    sort(Sum2.begin(),Sum2.end());
    ans += Sum2[0];
    cout << ans << endl;
}