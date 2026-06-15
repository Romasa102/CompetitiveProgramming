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
        ll a,b,x;
        cin >> a >> b >> x;
        ll count = 0;
        while(a-b!=0){
            if(a < b)swap(a,b);
            if(a-b >= x){
                a/=x;
                count++;
            }else{
                if((a/x - b/x + 2)<a-b){
                    a/=x;
                    b/=x;
                    count += (a-b+2);
                    b=a;
                }else{
                    count+=(a-b);
                    b=a;
                }
            }
        }
        cout << count << endl;
    }
}