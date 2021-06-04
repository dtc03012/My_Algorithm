lld ext_gcd (lld A, lld B, lld *X, lld *Y){
    lld x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}
 
pair<lld, lld> chinese_remainder_theorem(vector<lld> A, vector<lld> M) {
    if(A.size() != M.size()) return {-1,-1};
    int n = A.size();
    lld a1 = A[0];
    lld m1 = M[0];
    for ( int i = 1; i < n; i++ ) {
        lld a2 = A[i];
        lld m2 = M[i];
        lld g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1};
        lld p, q;
        ext_gcd(m1/g, m2/g, &p, &q);
        lld mod = m1 / g * m2;
        lld x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;
        a1 = x;
        if (a1 < 0) a1 += mod;
        m1 = mod;
    }
    return {a1, m1};
}