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
    ll X,Y;cin >> X >> Y;
    if(X%16 == 0){
        X/=16;
    }else{
        cout << "No" << endl;return 0;
    }
    if(Y%9==0){
        Y/=9;
    }else{
        cout << "No" << endl;return 0;
    }
    if(X==Y){
        cout << "Yes" << endl;return 0;
    }else{
        cout << "No" << endl;return 0;
    }
}