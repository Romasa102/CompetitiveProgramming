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
    ll Q;
    cin >> Q;
    multiset<ll> trees;
    rep(i,Q){
        ll task,h;
        cin >> task >> h;
        if(task == 1){
            trees.insert(h);
            cout << trees.size() << endl;
        }else{
            trees.erase(trees.begin(),trees.upper_bound(h));
            cout << trees.size() << endl;
        }
    }
}