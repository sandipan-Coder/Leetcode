class Spreadsheet {
    vector<vector<int>> grid;
public:
    Spreadsheet(int rows) {
        grid.assign(rows+1, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        
        int col = cell[0] - 'A';
        int n = cell.size();
        int row = 0;

        for(int i = 1; i < n; i++)
            row = (row * 10) + (cell[i] - '0');

        grid[row][col] = value;
    }
    
    void resetCell(string cell) {

        int col = cell[0] - 'A';
        int n = cell.size();
        int row = 0;

        for(int i = 1; i < n; i++)
            row = (row * 10) + (cell[i] - '0');

        grid[row][col] = 0;
    }
    
    int getValue(string formula) {
        
        int num1 = 0;
        int num2 = 0;
        int n = formula.size();
        int idx = 1;

        // Derive num1.
        if(isalpha(formula[idx])){
            int col = formula[idx] - 'A';
            idx++;
            int row = 0;

            while(formula[idx] != '+'){
                row = (row * 10) + (formula[idx] - '0');
                idx++;
            }

            num1 = grid[row][col];
        }
        else{
            while(formula[idx] != '+'){
                num1 = (num1 * 10) + (formula[idx] - '0');
                idx++;
            }
        }

        idx++;
        // Derive num1.
        if(isalpha(formula[idx])){
            int col = formula[idx] - 'A';
            idx++;
            int row = 0;

            while(idx < n){
                row = (row * 10) + (formula[idx] - '0');
                idx++;
            }

            num2 = grid[row][col];
        }
        else{
            while(idx < n){
                num2 = (num2 * 10) + (formula[idx] - '0');
                idx++;
            }
        }

        return (num1 + num2);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */