class Solution {
public:
    int totalMoney(int n) {

        int weeks = n / 7;   // full weeks
        int days = n % 7;    // remaining days
        
        // Sum of full weeks: 28 * weeks + 7 * (weeks * (weeks - 1)) / 2
        int total = 28 * weeks + 7 * (weeks * (weeks - 1)) / 2;
        
        // Remaining days: (days * (days + 1)) / 2 + days * weeks
        total += (days * (days + 1)) / 2 + days * weeks;
        
        return total; 
    }
};