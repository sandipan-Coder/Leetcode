class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n = cardPoints.size();
        int maxPoint = 0;
        int currPoint = 0;

        for(int i = 0; i < k; i++)
            currPoint += cardPoints[i];
        
        maxPoint = currPoint;

        for(int i = 1; i <= k; i++) {

            currPoint -= cardPoints[k - i];
            currPoint += cardPoints[n - i];

            maxPoint = max(maxPoint, currPoint);
        }

        return maxPoint;
    }
};