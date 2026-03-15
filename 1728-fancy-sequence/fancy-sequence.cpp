class Fancy {

    vector<long long> store;
    long long add;
    long long mult;

    int MOD = 1e9 + 7;
private:

    long long power(long long a, long long b) {

        if(b == 0)
            return 1;
        
        long long half = power(a, b/2);
        long long ans = (half * half) % MOD;
    
        if(b % 2)
            ans = (ans * a) % MOD;
        
        return ans;
    }

public:

    Fancy() {
        
        store.clear();
        add = 0;
        mult = 1;
    }
    
    void append(int val) {

        long long x = ((val - add) % MOD + MOD) * power(mult, MOD - 2) % MOD;
        store.push_back(x);
    }
    
    void addAll(int inc) {
        
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        
        add = (add * m) % MOD;
        mult = (mult * m) % MOD;
    }
    
    int getIndex(int idx) {
        
        if(idx >= store.size())
            return -1;
        
        return ((store[idx] * mult) % MOD + add) % MOD; 
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */