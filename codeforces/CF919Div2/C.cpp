#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
ll gcd(ll x,ll y){
    if(y==0)return x;
    return gcd(y,x%y);
}ll gcd_vec(vector<ll> const &A) {
    if(A.empty())return 1;
    ll ret = A[0];
    repp(i,1,A.size()){
        ret = gcd(ret, A[i]);
    }
    return ret;
}
vector<ll> divisor(ll x){
    vector<ll> ans;
    for(ll i = 1; i*i<=x; i++){
        if(x%i==0){
            ans.push_back(i);
            if(i!=x/i){
                ans.push_back(x/i);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
int main(){
    ll t;cin >> t;
    while(t--){
        ll n;cin >> n;
        vector<ll> a(n);
        rep(i,n)cin >> a[i];
        vector<ll> div = divisor(n);
        ll ans = 1;
        rep(i,div.size()){
            vector<ll> nums;
            rep(j,div[i]){//how many in each group
                repp(k,1,n/div[i]){//how many group
                    nums.push_back(abs(a[j+k*div[i]]-a[j+(k-1)*div[i]]));
                }
            }
            if(gcd_vec(nums)==0)ans++;
            if(1<gcd_vec(nums))ans++;
        }
        cout << ans << endl;
    }
}