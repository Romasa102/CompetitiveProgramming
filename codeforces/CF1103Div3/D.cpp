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
        ll n,k;
        cin >> n >> k;
        ll a[n];
        rep(i,n)cin >> a[i];
        sort(a,a+n,greater<ll>());
        ll cur = 0;
        bool work = false;
        while(cur<n){
            ll biggest = a[cur];
            ll biggestC = 0;
            repp(i,cur,n){
                if(a[i]==biggest){
                    biggestC++;
                }else{
                    break;
                }
            }
            //cout << "number of biggest num " << biggest << " is : " << biggestC << endl;
            if(biggestC%2==0){
                work = true;
                cout << "Yes" << endl;
                break;
            }else{
                ll secBiggestC = 0;
                repp(i,cur,n){
                    if(a[i] >= (biggest-k) && a[i]!=biggest){
                        secBiggestC++;
                    }
                }
                if(secBiggestC!=0){
                    work = true;
                    cout << "Yes" << endl;
                    break;
                }else{
                    cur += biggestC;
                }
            }
        }
        if(!work){
            cout << "No" << endl;
        }
    }
}