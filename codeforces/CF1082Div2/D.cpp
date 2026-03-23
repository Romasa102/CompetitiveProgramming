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
    while(t--){
        ll n,k;
        cin >> n >> k;
        if(n <= k && k <= 2*n-1){
            cout << "YES" << endl;
            queue<ll> nonF;
            queue<ll> F;
            rep(i,n){
                nonF.push(i+1);
            }
            //so while goal < n+((n+1)/2)/2+((n-(n+1)/2)+1)/2 just make NFNF
            //if it exceed that goal - n+((n+1)/2)/2+((n-(n+1)/2)+1)/2 is amount of NFF to make.
            //(n+1)/2/2 is must
            ll need = k-n;
            if(need > 0){
                cout << nonF.front() << " ";
                F.push(nonF.front());
                nonF.pop();
                cout << nonF.front() << " ";
                F.push(nonF.front());
                nonF.pop();
                need--;
                rep(i, need){
                    cout << nonF.front() << " " << F.front() << " ";
                    F.pop();
                    F.push(nonF.front());
                    nonF.pop();
                }
            }
            while(!F.empty()){
                cout << F.front() << " ";
                F.pop();
            }
            while(!nonF.empty()){
                cout << nonF.front() << " " << nonF.front() << " ";
                nonF.pop();
            }
            cout << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}