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
ll gcd(ll a,ll b){
    if(a==0)return b;
    if(b==0)return a;
    if(a>b)swap(a,b);
    return gcd(a,b%a);
}
int main(){
    ll A,B;
    cin >> A >> B;
    ll gcdv = gcd(A,B);
    ll aside = A/gcdv;
    ll bside = B/gcdv;
    //to check overflow do the division w the max.
    if(gcdv * aside > 1000000000000000000/bside){
        cout << "Large" << endl;
        return 0;
    }
    cout << gcdv * aside * bside << endl;
}