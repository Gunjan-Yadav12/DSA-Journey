class Solution {
  public:
    void solveSubseq(string& s, string output , int index ,vector<string>& ans ){
        
        //base case
        if(index >= s.size()){
            ans.push_back(output);
            return;
        }
        
        //exclude call 
        solveSubseq(s , output , index + 1 , ans);
        
        //include call
        char element = s[index];
        output.push_back(element);
        solveSubseq(s , output , index + 1 , ans );
    }
    
    vector<string> powerSet(string &s) {
        
        vector<string> ans;
        
        string output = "";
        
        int index = 0;
        
        solveSubseq(s , output , index  , ans);
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};