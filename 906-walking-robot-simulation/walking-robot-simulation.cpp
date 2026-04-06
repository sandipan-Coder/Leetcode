struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};


class Solution {
private:

    int approach1(vector<int>& commands, vector<vector<int>>& obstacles){

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

                if(dir == 0) {
                    for(int i = 1; i <= com; i++) {
                        y += 1;

                        if(st.count({x, y})) {
                            y--;
                            break;
                        }
                        maxDis = max(maxDis, ((x * x) + (y * y)));
                    }
                }
                else if(dir == 2) {
                    for(int i = 1; i <= com; i++) {
                        y -= 1;

                        if(st.count({x, y})) {
                            y++;
                            break;
                        }
                        maxDis = max(maxDis, ((x * x) + (y * y)));
                    }
                }
                else if(dir == 1) {
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

    int approach2(vector<int>& commands, vector<vector<int>>& obstacles) {

        int x = 0;
        int y = 0;
        int dir = 0;  // N = 0, E = 1, S = 2, W = 3.
        int maxDis = 0;
        unordered_set<pair<int, int>, pair_hash> st;
        int dirc[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for(auto it: obstacles) {
            int x_i = it[0];
            int y_i = it[1];
            st.insert({x_i, y_i});
        }

        for(int com: commands) {
            if(com == -1)  // 90 degree Right turn
                dir = (dir + 1) % 4;
            else if(com == -2)  // 90 degree Left turn
                dir = (dir + 3) % 4;
            else {
                for(int i = 0; i < com; i++) {
                    int newX = x + dirc[dir][0];
                    int newY = y + dirc[dir][1];
                    
                    if(st.count({newX, newY}))
                        break;

                    x = newX;
                    y = newY;
                    
                    maxDis = max(maxDis, ((x * x) + (y * y)));
                }  
            }
        }

        return maxDis;
    }

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        /*
        return approach1(commands, obstacles);
        */

        return approach2(commands, obstacles);
    }
};