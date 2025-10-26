class Bank {

    int n;
    vector<long long> totalMoney;
public:
    Bank(vector<long long>& balance) {
        
        n = balance.size();
        totalMoney = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        
        if(account1 > n || account2 > n || totalMoney[account1 - 1] < money)
            return false;
        
        totalMoney[account1 - 1] -= money;
        totalMoney[account2 - 1] += money;

        return true;   
    }
    
    bool deposit(int account, long long money) {
        
        if(account > n )
            return false;

        totalMoney[account - 1] += money;

        return true;
    }
    
    bool withdraw(int account, long long money) {
        
        if(account > n || totalMoney[account - 1] < money)
            return false;

        totalMoney[account - 1] -= money;

        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */