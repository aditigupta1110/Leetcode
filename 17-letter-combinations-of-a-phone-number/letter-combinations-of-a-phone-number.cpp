class Solution {
private:
    void solve(vector<string>& ans, string output, int index, string mapping[], string digits)
    {
        if(index >= digits.length()){
            ans.push_back(output);
            return;
        }

        int number = digits[index] - '0';       //to find the number - 2, 3 in 23
        string value = mapping[number];

        for(int i = 0; i<value.length(); i++)
        {
            output.push_back(value[i]);
            solve(ans, output, index+1, mapping, digits);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        
        if(digits.length()==0)
            return ans;
        int index = 0;
        string output = "";

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(ans, output, index, mapping, digits);
        return ans;
    }
};