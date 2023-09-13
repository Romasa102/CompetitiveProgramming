#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i,o,n) for(ll i = o; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    ll n;
    cin >> n;
    vector<ll> row;
    rep(i,n){
        ll a;
        cin >> a;
        row.push_back(a);
    }
    vector<P> rowS;
    rep(i,n){
        if(i == 0){
            rowS.push_back({row[i],1});
            continue;
        }
        if(row[i] == row[i-1]){
            rowS.back() = {row[i],rowS.back().second+1};
        }else{
            rowS.push_back({row[i],1});
        }
    }
    ll ans = 0;
    map<ll,bool> searched;
    while(true){
        stack<P> S;
        ll deleted = 0;
        bool found = false;
        rep(i,rowS.size()-1){
            if(rowS[i].second == 1 && searched.find(i) == searched.end()){
                searched[i] = true;
                found = true;
                ll count = i+1;
                while(true){
                    if(count>=rowS.size()||S.empty()){
                        break;
                    }
                    if(rowS[count].first == S.top().first){
                        if(count == i+1){
                            if(rowS[count].second+S.top().second >= 3){
                                deleted += rowS[count].second + S.top().second;
                                S.pop();
                                count++;
                                continue;
                            }else{
                                break;
                            }
                        }
                        if(rowS[count].second+S.top().second >= 4) {
                            deleted += rowS[count].second + S.top().second;
                            S.pop();
                            count++;
                            continue;
                        }else{
                            break;
                        }
                    }else{
                        break;
                    }
                }
                if(deleted!=0){
                    deleted++;
                }
                ans = max(ans,deleted);
                break;
            }else{
                S.push(rowS[i]);
            }
        }
        if(!found){
            break;
        }
    }
    cout << n - ans << endl;
}