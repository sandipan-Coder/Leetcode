class Solution {
public:
    int countCollisions(string directions) {
        
        int n = directions.size();
        int countS = 0;

        // Trim the string If the directions has prefix 'L' & Suffix 'R'
        // Because they never collided
        int start = 0;
        int end = n - 1;

        // Trim starting 'L' s
        while(start < n && directions[start] == 'L')
            start++;
        
        // Trim Last 'R' s
        while(end >= 0 && directions[end] == 'R')
            end--;
        
        if(start > end)
            return 0;
        
        for(int i = start; i <= end; i++){

            if(directions[i] == 'S')
                countS++;
        }
        
        int elementRemoved = start;  // For removing starting elements.
        elementRemoved += (n - 1 - end); // For removing ending elements.
        return (n - countS - elementRemoved);
    }
};