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
    

}
class RideSharingSystem {
public:
    queue<int> rider;
    queue<int> driver;
    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty()||driver.empty()){
            return {-1,-1};
        }else{
            vector<int> ans;
            ans.push_back(driver.front());
            ans.push_back(rider.front());
            driver.pop();rider.pop();
            return ans;
        }
    }
    
    void cancelRider(int riderId) {
        queue<int> tempQueue;
        bool found = false;
        while (!rider.empty()) {
            int current = rider.front();
            rider.pop();

            if (current == riderId && !found) {
                found = true;
            } else {
                tempQueue.push(current);
            }
        }
    }
};