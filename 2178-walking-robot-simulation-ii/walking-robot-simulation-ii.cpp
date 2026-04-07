class Robot {
private:

    int row, col;
    int x, y;
    int dir = 0; // E = 0, N = 1, W = 2, S = 3.
    int perimeter;
public:
    Robot(int width, int height) {
        row = height;
        col = width;
        x = 0;
        y = 0;
        perimeter = 2 * (width + height) - 4;
    }
    
    void step(int num) {
        
        if(perimeter == 0)
            return;
        
        num %= perimeter;

        if(num == 0 && x != 0 && y != 0)
            return;
        if(num == 0 && x == 0 && y == 0) {
            dir = 3;
            return;
        }

        while(num) {

            if(dir == 0){   // East

                int moves = min(num, col - 1 - x);
                x += moves;
                num -= moves;

                if(num > 0)
                    dir = (dir + 1) % 4;
            }
            else if(dir == 1){  // North

                int moves = min(num, row - 1 - y);
                y += moves;
                num -= moves;

                if(num > 0)
                    dir = (dir + 1) % 4;
            }
            else if(dir == 2){  // West
                
                int moves = min(num, x);
                x -= moves;
                num -= moves;

                if(num > 0)
                    dir = (dir + 1) % 4;
            }
            else { // South

                int moves = min(num, y);
                y -= moves;
                num -= moves;

                if(num > 0)
                    dir = (dir + 1) % 4;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        
        if(dir == 0)
            return "East";
        else if(dir == 1)
            return "North";
        else if(dir == 2)
            return "West";
        else
            return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */