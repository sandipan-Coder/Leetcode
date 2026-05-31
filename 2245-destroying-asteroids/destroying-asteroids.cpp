class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(), asteroids.end());
        long long mas = mass;

        if(mass < asteroids[0])
            return false;
        
        for(int as: asteroids) {
            if(as <= mas)
                mas += as;
            else
                return false;
        }

        return true;
    }
};