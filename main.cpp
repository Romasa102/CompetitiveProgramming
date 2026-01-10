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
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
int main(){
    string T_list[4] = {"eraser", "dreamer", "erase", "dream"};
    string joins[6] = {"erd", "ere", "amd", "ame", "see", "sed"};
    vector<int> threes;
    string S;
    cin >> S;

    for (int i=0; i < (S.length() - 3); i++){
        for (int j=0; j<6; j++){
            if (S.substr(i,3) == joins[j]){
                threes.push_back(i+1);
            }
        }
    }

    threes.push_back(S.length() -1);
    int i =0;
    int k =0;
    bool present = false;
    while (i<(S.length())){
        for (int j=0; j<4; j++){
            if (S.substr(i,(threes[k]-i)+1) == T_list[j]){
                present = true;
            }

        }
        if (present){
            if ((threes[k+1]- threes[k]) >2){
                i = threes[k] + 1;
            }
            k += 1;
        }
        else{
            cout << "NO" << endl;
            return 0;
        }
        present = false;

    }

    cout << "YES" << endl;
    return 0;

}
 