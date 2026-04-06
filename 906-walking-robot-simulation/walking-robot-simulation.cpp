struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        int x = 0;
        int y = 0;
        char dir = 'N';
        int maxDis = 0;
        unordered_set<pair<int, int>, pair_hash> st;
        
        for(auto it: obstacles) {
            int x_i = it[0];
            int y_i = it[1];
            st.insert({x_i, y_i});
        }

        for(int com: commands) {
            if(com == -1) {  // 90 degree Right turn
                
                if(dir == 'N')
                    dir = 'E';
                else if(dir == 'S')
                    dir = 'W';
                else if(dir == 'E')
                    dir = 'S';
                else
                    dir = 'N';
            }
            else if(com == -2){     // 90 degree Left turn

                if(dir == 'N')
                    dir = 'W';
                else if(dir == 'S')
                    dir = 'E';
                else if(dir == 'E')
                    dir = 'N';
                else
                    dir = 'S';
            }
            else {

                if(dir == 'N') {
                    for(int i = 1; i <= com; i++) {
                        y += 1;

                        if(st.count({x, y})) {
                            y--;
                            break;
                        }
                        maxDis = max(maxDis, ((x * x) + (y * y)));
                    }
                }
                else if(dir == 'S') {
                    for(int i = 1; i <= com; i++) {
                        y -= 1;

                        if(st.count({x, y})) {
                            y++;
                            break;
                        }
                        maxDis = max(maxDis, ((x * x) + (y * y)));
                    }
                }
                else if(dir == 'E') {
                    for(int i = 1; i <= com; i++) {
                        x += 1;    

                        if(st.count({x, y})) {
                            x--;
                            break;
                        }
                        maxDis = max(maxDis, ((x * x) + (y * y)));
                    }
                }
                else {
                    for(int i = 1; i <= com; i++) {
                        x -= 1;

                        if(st.count({x, y})) {
                            x++;
                            break;
                        }
                        maxDis = max(maxDis, ((x * x) + (y * y)));
                    }
                }
            }
        }

        return maxDis;
    }
};