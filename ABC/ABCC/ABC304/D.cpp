#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
using P = pair<ll,ll>;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
template<typename K, typename V>
std::pair<K,V> getMaximumValue(const std::map<K,V> &map) {
    return *std::max_element(map.begin(), map.end(), [](std::pair<K,V> const &x, std::pair<K,V> const &y) {
        return x.second < y.second;
    });
}
template<typename K, typename V>
std::pair<K,V> getMinimumValue(const std::map<K,V> &map) {
    return *std::min_element(map.begin(), map.end(), [](std::pair<K,V> const &x, std::pair<K,V> const &y) {
        return x.second < y.second;
    });
}
int main(){
    ll W,H;
    cin >> W >> H;
    ll N;
    cin >> N;
    vector<P> strawberry(N);
    rep(i,N){
        cin >> strawberry[i].first >> strawberry[i].second;
    }
    ll A,B;
    cin >> A;
    ll a[A + 2];
    a[0] = 0;
    a[A] = W;
    rep(i,A){
        cin >> a[i+1];
    }
    cin >> B;
    ll b[B+2];
    b[0] = 0;
    b[B] = H;
    rep(i,B){
        cin >> b[i+1];
    }
    vector<P> strJustX(N);
    rep(i,N){
        strJustX[i].first = strawberry[i].first;
        strJustX[i].second = i;
    }
    sort(strJustX.begin(),strJustX.end());
    P strPos[N];
    ll currentA = 0;
    rep(i,N){
        while(strJustX[i].first > a[currentA]){
            currentA++;
        }
        strPos[strJustX[i].second].first = currentA;
    }
    vector<P> strJustY(N);
    rep(i,N){
        strJustY[i].first = strawberry[i].second;
        strJustY[i].second = i;
    }
    sort(strJustY.begin(),strJustY.end());
    ll currentB = 0;
    rep(i,N){
        while(strJustY[i].first > b[currentB]){
            currentB++;
        }
        strPos[strJustY[i].second].second = currentB;
    }
    map<P,int> Num;
    rep(i,N){
        Num[strPos[i]]++;
    }
    if(Num.size() < (A+1) * (B+1)){    
        cout << '0' << " " << getMaximumValue(Num).second << endl;
    }else{
        cout << getMinimumValue(Num).second << " "<< getMaximumValue(Num).second << endl;
    }

}