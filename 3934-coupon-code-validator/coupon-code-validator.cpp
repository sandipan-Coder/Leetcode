class Solution {
private:

    bool isValidBusiness(string str){
        return (str == "electronics" || str == "grocery" || str == "pharmacy" || str == "restaurant");
    }

    bool isValidCode(string str){
        return regex_match(str, regex("[A-Za-z0-9_]+"));
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        
        int n = code.size();
        map<string, multiset<string>> mp;
        vector<string> ans;

        for(int i = 0; i < n; i++){
            if(isActive[i] && isValidBusiness(businessLine[i]) && (code[i].size() != 0)){
                if(isValidCode(code[i]))
                    mp[businessLine[i]].insert(code[i]);
            }
        }

        for(auto &it: mp){
            for(auto ele: it.second)
                ans.push_back(ele);
        }

        return ans;
    }
};