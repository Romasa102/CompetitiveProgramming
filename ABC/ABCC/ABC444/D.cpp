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
ll INF = 5000000;
int main(){
    ll N;cin>>N;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    sort(A.begin(),A.end(),greater<ll>());
    map<ll,ll> mp;
    for(ll cur: A)mp[cur]++;

    vector<ll> num(INF);
    ll cur = 0;
    for(ll i = INF-1;i>0;i--){
        cur+=mp[i];
        num[i]+=cur;
    }
    ll carry = 0;
    repp(i,1,num.size()){
        num[i]+=carry;
        carry=0;
        if(num[i]>=10){
            carry=num[i]/10;
            num[i]%=10;
        }
    }
    ll stp=INF-1;
    while(num[stp]==0)stp--;
    for(ll i=stp;i>0;i--){
        cout << num[i];
    }cout << endl;
}