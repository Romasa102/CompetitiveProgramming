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
    vector<ll> Xcoords;
    vector<ll> Ycoords;
    vector<pair<P,P>> coords(N);
    rep(i,N){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        coords[i].first.first = x1;
        coords[i].first.second = y1;
        coords[i].second.first = x2;
        coords[i].second.second = y2;
        Xcoords.push_back(x1);
        Xcoords.push_back(x2);
        Ycoords.push_back(y1);
        Ycoords.push_back(y2);
    }
    sort(Xcoords.begin(),Xcoords.end());
    sort(Ycoords.begin(),Ycoords.end());
    auto it = unique(Xcoords.begin(), Xcoords.end());
    Xcoords.resize(distance(Xcoords.begin(), it));
    it = unique(Ycoords.begin(), Ycoords.end());
    Ycoords.resize(distance(Ycoords.begin(), it));

    vector<vector<bool>> compmap(Xcoords.size(),vector<bool> (Ycoords.size(),false));

    map<ll,ll> compX;
    map<ll,ll> compY;

    ll counter = 0;
    for(auto i : Xcoords){
        compX[i] = counter;
        counter++;
    }
    counter = 0;
    for(auto i : Ycoords){
        compY[i] = counter;
        counter++;
    }

    vector<vector<ll>> compmapS(((int)Xcoords.size()+1),vector<ll> (Ycoords.size()+1,false));

    rep(i,N){
        ll c = compX[coords[i].first.first];
        ll a = compY[coords[i].first.second];
        ll d = compX[coords[i].second.first];
        ll b = compY[coords[i].second.second];
        compmapS[c][a]++;
        compmapS[c][b]--;
        compmapS[d][a]--;
        compmapS[d][b]++;
    }
    rep(i,Xcoords.size()){
        repp(j,1,Ycoords.size()){
            compmapS[i][j] += compmapS[i][j-1];
        }
    }
    repp(i,1,Xcoords.size()){
        rep(j,Ycoords.size()){
            compmapS[i][j] += compmapS[i-1][j];
        }
    }
    ll ans = 0;
    rep(i,Xcoords.size()){
        rep(j,Ycoords.size()){
            if(compmapS[i][j]){
                ll xs,ys;
                    xs = Xcoords[i+1] - Xcoords[i];
                    ys = Ycoords[j+1] - Ycoords[j];
                ans += xs * ys;
            }
        }
    }
    /*
    rep(i,Xcoords.size()){
        cout << Xcoords[i] << " ";
    }cout << endl;
    rep(i,Ycoords.size()){
        cout << Ycoords[i] << " ";
    }cout << endl;

    rep(i,Xcoords.size()){
        rep(j,Ycoords.size()){
            cout << compmap[i][j];
        }cout << endl;
    }
    */
    cout << ans << endl;
}