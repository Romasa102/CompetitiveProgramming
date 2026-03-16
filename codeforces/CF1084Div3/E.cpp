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
template<typename T>

vector<T> smallest_prime_factors(T n) {

    vector<T> spf(n + 1);
    for (int i = 0; i <= n; i++) spf[i] = i;


    for (T i = 2; i * i <= n; i++) {

        // 素数だったら
        if (spf[i] == i) {

            for (T j = i * i; j <= n; j += i) {

                // iを持つ整数かつまだ素数が決まっていないなら
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

template<typename T>
vector<T> factolization(T x, vector<T> &spf) {
    vector<T> ret;
    while (x != 1) {
        ret.push_back(spf[x]);
        x /= spf[x];
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    ll t;
    cin >> t;

    constexpr int MAX = 1000000;

    auto spf = smallest_prime_factors(MAX);

    while(t--){
        ll n;
        cin >> n;
        ll a[n];
        rep(i,n)cin >> a[i];
        ll curN = 0;
        bool possible=true;
        rep(i,n){
            auto result = factolization(a[i], spf);
            
            if(lower_bound(ans.begin(),ans.end(),curN) == ans.end()){
                possible = false;
            }else{
                curN = (*(lower_bound(ans.begin(),ans.end(),curN)));
            }
            cout << curN << endl;
        }
        if(possible){
            cout << "Bob"<< endl;
        }else{
            cout <<"Alice" << endl;
        }
    }
}