#include <vector>
#include <iostream>

std::vector<int> successor(std::vector<int> nums) {
    for (int i = 0; i < nums.size();i++){ //start iterating from the LSB
        if(nums[i] < 2){
            nums[i]++; //increment the least significant bit if less than 2.
            return nums; //after the increment the answer is already done so return it.
        }
        nums[i]=0; //if the bit was 2 you must carry thus turn that number to 0 and move on to the next bit
    }
    nums.push_back(1); //when the carry did not fit add 1 to the MSB
    return nums;
}

#include <vector>
#include <iostream>
#include <algorithm>

bool leq(std::vector<int> A,std::vector<int> B){
    for(int i = std::max(A.size()-1,B.size()-1); i>=0; i--){ //start the iteration by comparing the MSB
        int a = 0;
        int b = 0; //initialize both bits with 0
        if(i < A.size())a = A[i]; //only update the current bits if the index is under the list's size
        if(i < B.size())b = B[i];
        if (a < b) return true; //since iterating down from MSB, if there is any difference that dominate the inequality
        if (a > b) return false;
    }
    return true; //if it haven't returned anything after the whole iteration it suggests two value being equal thus return true.
}

#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> tritwise_min(const std::vector<int>& xs, const std::vector<int>& ys) {
    std::vector<int> ans; //make an empty vector
    for (int i = 0; i < std::min(xs.size(),ys.size());i++){ //only check up to the bits which both list have
        ans.push_back(std::min(xs[i],ys[i])); //get the smallest bits
    }
    return ans; //return the answer
}


#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> f(std::vector<int> A, const std::vector<int>& B) {
    if(!leq(A,B))return std::vector<int>(); //if A is bigger than B then return before the code crashes
    std::vector<int> ans = A; //initialize the current tritwise min with A
    A = successor(A); //increment A
    while(leq(A,B)){ //while A is smaller or equal to B
        ans = tritwise_min(A, ans); //get the tritwise_min
        A = successor(A); //increment A
    }
    return ans; //if A reaches B it means they computed the tritwise MIN between all the integer between A and B
}

#include <vector>
#include <iostream>
#include <algorithm>
std::vector<int> f(const std::vector<int>& A, const std::vector<int>& B) {
    if(!leq(A,B))return std::vector<int>(); //if A is bigger than B then return before the code crashes
    int n = std::min(A.size(), B.size()); //get the smaller bitsize
    std::vector<int> ans = std::vector<int>(n); //initialize the answer vector with this size all bit filled in 0
    for (int i = n; i >= 0; i--) { //iterate down from the MSB
        int a = 0;
        int b = 0; //initialize both bits with 0
        if(i < A.size())a = A[i]; //only update the current bits if the index is under the list's size
        if(i < B.size())b = B[i];
        ans[i] = a; // the bits is either a<b or a==b therefore either way set a
        if (a != b) return ans; // if a!=b it means a<b all the bits below this is 0 as the lower bits must go through 
        // 0 once in order to increment this bit
    }
    return ans; // if it reaches the bottom A is equal to B
}
