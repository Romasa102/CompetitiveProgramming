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
int main(){
    string S;
    cin >> S;
    ll Map[10];
    set<ll> ans;
    int l = -1;
    int r;
    vector<int> oddNow;
    while(l >= 0 && l < S.length()){
        l++;
        r = l+1;
        Map[S[l]]++;
        Map[S[r]]++;
        while (l < r && r < S.length())
        {
            r++;
            Map[S[r]]++;
            r++;
            Map[S[r]]++;
        }
    }
}