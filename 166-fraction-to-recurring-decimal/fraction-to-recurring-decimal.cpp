class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if (numerator == 0) 
            return "0";
        
        string result;
        
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) 
            result += "-";
        
        long long nume = abs((long long)numerator);
        long long denom = abs((long long)denominator);
        
        // Integer part
        result += to_string(nume / denom);
        long long remainder = nume % denom;
        if (remainder == 0) 
            return result;
        
        result += ".";
        
        unordered_map<long long, int> seen;
        while (remainder != 0) {
            if (seen.count(remainder)) {
                result.insert(seen[remainder], "(");
                result += ")";
                break;
            }
            seen[remainder] = result.size();
            remainder *= 10;
            result += to_string(remainder / denom);
            remainder %= denom;
        }
        
        return result;
    }
};