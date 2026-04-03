class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        if(target == 1)
            return 0;
        
        int moves = 0;
        if(maxDoubles == 0)
            return (target - 1);
        
        int ans = target;
        int maxD = maxDoubles;

        while(ans > 1 && maxD) {

            if(ans % 2) {
                ans -= 1;
                moves++;
            }
            else{
                ans /= 2;
                maxD--;
                moves++;
            }
        }

        if(ans > 1)
            moves += (ans - 1);
        
        return moves;
    }
};