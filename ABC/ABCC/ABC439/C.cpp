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
    ll N;
    cin >> N;
    ll A[N];
    rep(i,N)cin >> A[i];
    vector<P> sevenN;
    vector<P> fiveN;
    vector<P> threeN;
    map<ll,P> divided;
    rep(i,N){
        if(A[i]%7 == 0){
            sevenN.push_back({A[i]/7,i});
            divided[A[i]/7]={i,7};
        }
        if(A[i]%5 == 0){
            fiveN.push_back({A[i]/5,i});
            divided[A[i]/5]={i,5};
        }
        if(A[i]%3 == 0){
            threeN.push_back({A[i]/3,i});
            divided[A[i]/3]={i,3};
        }
    }
    for (auto it = divided.begin(); it != divided.end(); it++)
    {
        `
    }
}
