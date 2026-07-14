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
    ll right = 0;
    ll fans = 0;
    rep(left,N-1){
        if (right < left) right = left;
        bool state = 0;
        if(right != N-1){
            cout << "? " << left+1 << " " << right+2 << endl;
            string ans;
            cin >> ans;
            if(ans == "Yes"){
                state = true;
            }else{
                state = false;
            }
            while (right < N-1 && state) {
                ++right;
                if(right == N-1){
                    break;
                }
                cout << "? " << left+1 << " " << right+2 << endl;
                string ans;
                cin >> ans;
                if(ans == "Yes"){
                    state = true;
                }else{
                    state = false;
                }
            }
        }
        fans += (right - left);
    }
    cout << "! " << fans << endl;
}