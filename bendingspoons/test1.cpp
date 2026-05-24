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

vector<ll> num = {2,3,5,7,11,13,17,19,23,29,31,37,41,47,53,59,67,71,83,89,101,107,109,113,127,131,137,139,149,157,167,179,181,191,197,199,211,227,233,239,251,257,263,269,281,293,307,311,317,337,347,353,359,379,389,401,409,419,431,443,449,461,467,479,487,491,499,503,509,521,541,557,563,569,571};


std::vector<long long> prime_factorization(long long n) {
    std::vector<long long> factors;
    for (long long i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}


int main(){
    ll N;
    cin >> N;
    map<ll,ll> mp;
    rep(i,num.size()){
        mp[num[i]]=1;
    }
    ll ans = 0;
    vector<ll> counts;
    repp(i,2,N+1){
        ll cur = 0;
        auto list = prime_factorization(i);
        for(auto j : list){
            if(mp[j]==1){
                cur++;
                ans++;
            }
        }
        counts.push_back(cur);
    }
    sort(counts.begin(),counts.end(),greater<ll>());
    rep(i,counts.size()){
        cout << counts[i] << " ";
    }
    cout << endl;
    cout << ans << endl;
}