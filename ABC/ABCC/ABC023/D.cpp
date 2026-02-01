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
ll INF = 1LL<<60;
ll N;
vector<ll> H;
vector<ll> S;
bool satisfiable(ll x){
    map<ll,ll> nums;
    //cout << "hey:" << x << endl;
    rep(i,N){
        if(x < H[i])return false;
        ll div = (x-H[i])/S[i];
       // if((x-H[i])%S[i])div++;
        //cout <<  div << " ";
        if(N>div)nums[div]++;
    }
    ll sumN=0;
    //cout << endl;
    for(auto i:nums){
     //   cout << i.first << " " << i.second << endl;
    }
    for(auto i:nums){
        sumN+=i.second;
        if((i.first+1)<sumN){
       //     cout << "NOOO" << endl;
            return false;
        }
    }
    return true;
}
int main(){
    cin >>N;
    H.resize(N);S.resize(N);
    rep(i,N)cin >> H[i] >> S[i];
    ll left = 0;
    ll right = INF;
    ll mid=(left+right+1)/2;
    while(right!=mid){
        //cout << left << " " << right << endl;
        if(satisfiable(mid)){
            right = mid;//mid iketakara still in range
            mid = (left+right)/2;
        }else{
            left = mid+1;//mid ha muri dakara hazusu
            mid = (left+right)/2;
        }
    }
    cout << right << endl;
}