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
    rep(_,t){
        ll x,y,R;
        cin >> x >> y >> R;
        bool done = false;
        repp(i,x-R-1,x+R+1){
            repp(j,y-R-1,y-R+1){
                if((i-x)*(i-x)+(y-j)*(y-j) == R*R){
                    if(!done){
                        cout << i << " " << j << endl;
                        done  =true;
                    }

                }
            }
        }
    }
}