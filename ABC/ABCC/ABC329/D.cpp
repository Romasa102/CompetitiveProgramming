#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
struct myComp {
    bool operator()(
            pair<ll, ll> &a,
            pair<ll, ll> &b)
    {
        if(a.first < b.first){
            return true;
        }else if(a.first > b.first){
            return false;
        }else{
            return a.second > b.second;
        }
        return true;
    }
};
int main(){

    ll N,M;
    cin >> N >> M;
    ll A[M];
    rep(i,M){
        cin >> A[i];
        A[i]--;
    }
    map<ll,ll> num;
    priority_queue<P,vector<P>,myComp> ppl;
    rep(i,M){
        num[A[i]]++;
        ppl.push({num[A[i]],A[i]+1});
        cout << ppl.top().second << endl;
    }
}