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
    ll N,K,X;
    cin >> N >> K >> X;
    ll A[N];
    rep(i,N)cin >> A[i];
    sort(A,A+N,greater<ll>());
    ll counter = (N-K);
    while(X>0 && counter < N){
        X-=A[counter];
        counter++;
    }
    if(counter > N || X > 0){
        cout << -1 << endl;
        return 0;
    }
    cout << counter << endl;
}