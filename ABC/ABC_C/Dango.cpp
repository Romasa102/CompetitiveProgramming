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
    ll N;
    string S;
    ll maxContinuous =0 ;
    cin >> N >> S;
    bool continuous = false;
    bool haveLine = false;
    ll continuousNum = 0;
    rep(i,N){
        if(S[i] == '-'){
            haveLine = true;
            continuousNum=0;
        }
        if(S[i] == 'o'){
            continuousNum++;
        }
        if(continuousNum >= maxContinuous){
            maxContinuous = continuousNum;
        }
    }
    if(haveLine && maxContinuous!=0){
        cout << maxContinuous << endl;
    }else{
        cout << -1 << endl;
    }
    
}