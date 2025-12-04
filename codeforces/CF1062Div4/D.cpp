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
vector<ll> prime_factorize(ll N) {
    vector<ll> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back(a);
    }
    if (N != 1) res.push_back(N);
    return res;
}
vector<ll> Eratosthenes( const ll N )
{
    vector<bool> is_prime( N + 1 );
    for( ll i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    vector<ll> P;
    for( ll i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( ll j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}
int main(){
    ll t;
    cin >> t;
    vector<ll> prime_nums = Eratosthenes(1e7);
    rep(_,t){
        ll n;
        cin >> n;
        ll a[n];
        vector<ll> primes;
        ll minAns = 1000000000;
        rep(i,n){
            cin >> a[i];
            vector<ll> factors = prime_factorize(a[i]);
            rep(i,prime_nums.size()){
                if(find(factors.begin(),factors.end(),prime_nums[i])==primes.end()){
                    minAns =  min(minAns,prime_nums[i]);
                    break;
                }
            }
            cout << minAns << endl;
        }
    }
}