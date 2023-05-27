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
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repp(i, c, n) for (ll i = c; i < (n); ++i)
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;

unsigned long long pow2shift(unsigned long long in, int pow) {
    if (pow == 0) {
        return 1;
    }

    return in << (pow - 1);
}

int main(){
    string S;
    unsigned long long N;
    cin >> S >> N;
    unsigned long long numberNow = 0;
    vector<unsigned long long> unknown;
    rep(i,S.length()){
        if((S[i]) == '1'){
            numberNow+=pow2shift(2, i);
        }else if(S[i] == '?'){
            unknown.push_back(pow2shift(2, i));
        }
    }
    unsigned long long remaining;
    if(N < numberNow){
        cout << -1 << endl;
        return 0;
    }
    remaining = N-numberNow;
    for (ll i = unknown.size()-1; i >= 0; i--)
    {
        if(remaining >= unknown[i]){
            remaining-=unknown[i];
        }
    }
    cout << N - remaining << endl;
}