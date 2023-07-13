class Solution {
public:
    void solve(vector<string>& ans, int index, vector<string>& mapping, string op, string digits) {
        // BASE CASE 
        if (index >= digits.length()) {
            ans.push_back(op);
            return;
        }

        int digit = digits[index] - '0'; // conversion from char to int
        string value = mapping[digit];

        for (int j = 0; j < value.length(); j++) {
            char ch = value[j];
            op.push_back(ch);
            solve(ans, index + 1, mapping, op, digits);
            // backtrack
            op.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) {
            return ans;
        }

        string empty = "";
        int index = 0;
        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        solve(ans, index, mapping, empty, digits);

        return ans;
    }
};
