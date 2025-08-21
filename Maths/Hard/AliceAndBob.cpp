#include <iostream>
#include <vector>
using namespace std;
//This was asked in sprinklr's OA for my internship
class Solution{
    const int MOD=1e9+7;
    // Fast power for inverse modulo
    long long mod_pow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2) result = (result * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
    bool is_magic_sum(int S, int A, int B) {
        while (S > 0) {
            int d = S % 10;
            if (d != A && d != B) return false;
            S /= 10;
        }
        return true;
    }
    long long comb(int n, int k, const vector<long long>& fact, const vector<long long>& invFact) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }
        public:
    int numberOfMagicNums(int A,int B,int N){
        // Precompute factorials and inverse factorials
        vector<long long> fact(N + 1, 1), invFact(N + 1, 1);
        for (int i = 1; i <= N; ++i)
            fact[i] = (fact[i - 1] * i) % MOD;
        invFact[N] = mod_pow(fact[N], MOD - 2, MOD);
        for (int i = N - 1; i >= 0; --i)
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        long long answer = 0;
        for (int k = 0; k <= N; ++k) {
            int sum = k * A + (N - k) * B;
            if (is_magic_sum(sum, A, B))
                answer = (answer + comb(N, k, fact, invFact)) % MOD;
        }
        return answer;
    }
};



int main() {
    Solution s;
    int A, B, N;
    cin >> A >> B >> N;
    cout<<"The Number of Magic Numbers in the range (1,"<<N<<"): "<<s.numberOfMagicNums(A,B,N)<<endl;
    return 0;
}
