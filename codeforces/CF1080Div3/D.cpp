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
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> diff1(n-1);
        vector<ll> diff2(n-2);
        rep(i,n)cin>>a[i];
        rep(i,n-1){
            diff1[i]=a[i+1]-a[i];
        }
        rep(i,n-2){
            diff2[i]=diff1[i+1]-diff1[i];
        }
        vector<ll> ans(n);
        repp(i,1,n-1){
            ans[i]=diff2[i-1]/2;
        }
        ans[0]=a[n-1];
        rep(i,n-1){
            ans[0]-=ans[n-i-1]*i;
        }ans[0]/=(n-1);
        ans[n-1]=a[0];
        rep(i,n-1){
            ans[n-1]-=ans[i]*i;
        }
        ans[n-1]/=(n-1);
        rep(i,n){
            cout << ans[i] << " ";
        }cout << endl;
    }
}