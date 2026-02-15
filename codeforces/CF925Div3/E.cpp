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
    ll t;cin >> t;
    while(t--){
        ll n,m;cin>>n>>m;
        ll a[n];
        ll numZ[n];
        ll totalD=0;
        rep(i,n){
            cin >>a[i];
            numZ[i]=0;
            while(a[i]%10==0){
                a[i]/=10;
                numZ[i]++;
                totalD++;
            }
            while(a[i]>0){
                a[i]/=10;
                totalD++;
            }
        }
        sort(numZ,numZ+n,greater<ll>());
        rep(i,n){
            if(i%2==0)totalD-=numZ[i];
        }
        if(totalD>m){
            cout << "Sasha" << endl;
        }else{
            cout << "Anna" << endl;
        }
    }
}