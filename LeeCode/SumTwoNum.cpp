#include<iostream>
#include<vector>
using namespace std;


class Solution{
    public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> ans;
        for(int i = 0; i < nums.size() -1; i++){
            for(int j = 0; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};


int main(){
    Solution sol;
    vector<int> num{2, 7, 11, 15};
    int target = 9;
    cout<<sol.twoSum(num, target) <<endl;

    return 0;
}