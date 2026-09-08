class Solution {
public:
    void solveSubset(vector<int>& nums , vector<int> output, int index , vector<vector<int>>& ans){

        //base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }
        //exclude call
        solveSubset(nums , output , index + 1, ans);

        //include call
        int element = nums[index];
        output.push_back(element);
        solveSubset(nums , output , index + 1, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        int index = 0;
        solveSubset(nums , output , index , ans);
        return ans;
    }
};