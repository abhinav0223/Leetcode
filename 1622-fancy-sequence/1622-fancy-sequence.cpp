class Fancy {
    vector<long long> seq;
    long long mult;
    long long add;

    static const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = result * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return result;
    }

    long long modInverse(long long a) {
        return power(a, MOD - 2);
    }

public:
    Fancy() : mult(1), add(0) {}

    void append(int val) {
        long long raw = ((val - add % MOD + MOD) % MOD) * modInverse(mult) % MOD;
        seq.push_back(raw);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mult = mult * m % MOD;
        add  = add  * m % MOD;
    }

    int getIndex(int idx) {
        if (idx >= (int)seq.size()) return -1;
        return (seq[idx] * mult % MOD + add) % MOD;
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