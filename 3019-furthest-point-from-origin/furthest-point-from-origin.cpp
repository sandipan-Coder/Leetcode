class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        
        int leftMove = 0;
        int rightMove = 0;

        for(char ch: moves){
            if(ch == '_'){
                leftMove--;
                rightMove++;
            }
            else if(ch == 'L'){
                leftMove--;
                rightMove--;
            }
            else{
               rightMove++; 
               leftMove++;
            }
        }

        int ans = max(abs(leftMove), abs(rightMove));
        return ans;
    }
};