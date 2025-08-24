class Solution {
private:

    bool isPossible_to_make_bouquet(vector<int> &arr, int &day, int &k, int &m){

        int count = 0;
        int bouquet = 0;

        for(int ele: arr){

            if(ele <= day)
                count++;
            else {
                bouquet += (count / k);
                count = 0;
            }
        }

        bouquet += (count / k);

        return (bouquet >= m);
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();

        if(n / k < m)
            return -1;
        
        int low = INT_MAX;
        int high = INT_MIN;

        for(int ele: bloomDay){
            
            low = min(low, ele);
            high = max(high, ele);
        }

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(isPossible_to_make_bouquet(bloomDay, mid, k, m))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};