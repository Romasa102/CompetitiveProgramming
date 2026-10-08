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
    ll n,m;
    cin >> n >> m;

    while(n != 0){
        char c[n][m];

        bool fail = false;
        rep(i,n){
            rep(j,m){
                cin >> c[i][j];
            }
        }
        ll curCol = 0;
        ll curLen = 0;
        ll maxContinuouslen = 0;
        set<ll> colorChangeN;
        set<ll> colorChangeM;

        if(c[0][0] == '.'){
            curCol = 0;
        }else{
            curCol = 1;
        }
        rep(j,m){
            if(curCol == 0){
                if(c[0][j] == '.'){
                    curLen++;
                }else{
                    colorChangeN.insert(j);
                    curLen = 1;
                    curCol = 1;
                }
            }
            else if(curCol){
                if(c[0][j] == '#'){
                    curLen++;
                }else{
                    colorChangeN.insert(j);
                    curLen = 1;
                    curCol = 0;
                }
            }
        }

        if(c[0][0] == '.'){
            curCol = 0;
        }else{
            curCol = 1;
        }
        rep(i,n){
            if(curCol == 0){
                if(c[i][0] == '.'){
                    curLen++;
                }else{
                    colorChangeM.insert(i);
                    curLen = 1;
                    curCol = 1;
                }
            }
            else if(curCol){
                if(c[i][0] == '#'){
                    curLen++;
                }else{
                    colorChangeM.insert(i);
                    curLen = 1;
                    curCol = 0;
                }
            }
        }
        rep(i,n){
            curLen = 0;
            ll changeCnt = 0;
            if(c[i][0] == '.'){
                curCol = 0;
            }else{
                curCol = 1;
            }
            rep(j,m){
                if(curCol == 0){
                    if(c[i][j] == '.'){
                        curLen++;
                    }else{
                        changeCnt++;
                        if(colorChangeN.find(j) == colorChangeN.end()){
                            fail = true;
                        }
                        curLen = 1;
                        curCol = 1;
                    }
                }
                else if(curCol){
                    if(c[i][j] == '#'){
                        curLen++;
                    }else{
                        changeCnt++;
                        if(colorChangeN.find(j) == colorChangeN.end()){
                            fail = true;
                        }
                        curLen = 1;
                        curCol = 0;
                    }
                }
            }
            if(changeCnt != colorChangeN.size())fail = true;
        }

        rep(j,m){
            curLen = 0;
            ll changeCnt = 0;
            if(c[0][j] == '.'){
                curCol = 0;
            }else{
                curCol = 1;
            }
            rep(i,n){
                if(curCol == 0){
                    if(c[i][j] == '.'){
                        curLen++;
                    }else{
                        if(colorChangeM.find(i) == colorChangeM.end()){
                            fail = true;
                        }
                        changeCnt ++;
                        curLen = 1;
                        curCol = 1;
                    }
                }
                else if(curCol){
                    if(c[i][j] == '#'){
                        curLen++;
                    }else{
                        if(colorChangeM.find(i) == colorChangeM.end()){
                            fail = true;
                        }
                        changeCnt ++;
                        curLen = 1;
                        curCol = 0;
                    }
                }
            }
            if(changeCnt!=colorChangeM.size())fail = true;
        }
        rep(i,n){
            curLen = 0;
            if(c[i][0] == '.'){
                curCol = 0;
            }else{
                curCol = 1;
            }
            rep(j,m){
                if(curCol == 0){
                    if(c[i][j] == '.'){
                        curLen++;
                    }else{
                        curLen = 1;
                        curCol = 1;
                    }
                }
                else if(curCol){
                    if(c[i][j] == '#'){
                        curLen++;
                    }else{
                        curLen = 1;
                        curCol = 0;
                    }
                }
                maxContinuouslen = max(maxContinuouslen,curLen);
            }
        }
        rep(j,m){
            curLen = 0;
            if(c[0][j] == '.'){
                curCol = 0;
            }else{
                curCol = 1;
            }
            rep(i,n){
                if(curCol == 0){
                    if(c[i][j] == '.'){
                        curLen++;
                    }else{
                        curLen = 1;
                        curCol = 1;
                    }
                }else if(curCol){
                    if(c[i][j] == '#'){
                        curLen++;
                    }else{
                        curLen = 1;
                        curCol = 0;
                    }
                }
                maxContinuouslen = max(maxContinuouslen,curLen);
            }
        }
        ll ans = maxContinuouslen;
        bool valComf = false;
        rep(i,n){
            curLen = 0;
            bool firstT = true;
            if(c[i][0] == '.'){
                curCol = 0;
            }else{
                curCol = 1;
            }
            rep(j,m){
                if(curCol == 0){
                    if(c[i][j] == '.'){
                        curLen++;
                    }else{
                        if(!firstT){
                            if(curLen != maxContinuouslen){
                                fail = true;
                            }else{
                                valComf = true;
                            }
                        }
                        firstT = false;
                        curLen = 1;
                        curCol = 1;
                    }
                }
                else if(curCol == 1){
                    if(c[i][j] == '#'){
                        curLen++;
                    }else{
                        if(!firstT){
                            if(curLen != maxContinuouslen){
                                fail = true;
                            }else{
                                valComf = true;
                            }
                        }
                        firstT = false;
                        curLen = 1;
                        curCol = 0;
                    }
                }
            }
        }
        rep(j,m){
            curLen = 0;
            bool firstT = true;

            if(c[0][j] == '.'){
                curCol = 0;
            }else{
                curCol = 1;
            }
            rep(i,n){
                if(curCol == 0){
                    if(c[i][j] == '.'){
                        curLen++;
                    }else{
                        if(!firstT){
                            if(curLen != maxContinuouslen){
                                fail = true;
                            }else{
                                valComf = true;
                            }
                        }
                        firstT = false;
                        curLen = 1;
                        curCol = 1;
                    }
                }
                else if(curCol){
                    if(c[i][j] == '#'){
                        curLen++;
                    }else{
                        if(!firstT){
                            if(curLen != maxContinuouslen){
                                fail = true;
                            }else{
                                valComf = true;
                            }
                        }
                        firstT = false;
                        curLen = 1;
                        curCol = 0;
                    }
                }
            }
        }
        if(fail){
            cout << -1 << endl;
        }else if(valComf == false){
            cout << 0 << endl;
        }else{
            cout << ans << endl;
        }
        cin >> n >> m;
    }
}