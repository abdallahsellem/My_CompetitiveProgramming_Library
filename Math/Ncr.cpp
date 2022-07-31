int nCr(int n, int r) {
    int num = (fact[n] % MOD * fast_power((fact[n - r] % MOD * fact[r] % MOD) % MOD, MOD - 2) % MOD) % MOD;
    return num;
}
 