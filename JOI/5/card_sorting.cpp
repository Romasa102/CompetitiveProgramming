#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n,k;
    cin >> n >> k;
    ll A[n];
    rep(i,n){
        cin >> A[i];
    }
    set<string> patterns;
    rep(bit,(1<<(n))-1){
        if(__builtin_popcount(bit) != k)continue;
        vector<string> have;
        rep(i,n){
            if(bit & (1 << i)){
                have.push_back(to_string(A[i]));
            }
        }
        sort(have.begin(),have.end());
        do{
            string ans = "";
            rep(i,have.size()){
                ans += have[i];
            }
            patterns.insert(ans);
        } while (next_permutation(have.begin(),have.end()));
    }
    cout << patterns.size() << endl;
}