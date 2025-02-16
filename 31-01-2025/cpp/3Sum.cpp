// https://leetcode.com/problems/3sum/description/

// code 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
       vector<vector<int>>ans;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(k>j){
                int sum= nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(k>j && nums[k]==nums[k+1]) k--;
                    while(k>j && nums[j] == nums[j-1]) j++;
                }
            }
       }
       return ans;
    }
};

/*      Test Cases

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Input: nums = [0,1,1]
Output: []

Input: nums = [0,0,0]
Output: [[0,0,0]]


*/