const double PI = acos(-1); // PI 값을 지정해 놓음
typedef complex<double> cpx;

void FFT(vector<cpx> &f, cpx w){
    int n = f.size();
    if(n == 1) return;
    vector<cpx> even(n/2), odd(n/2);
    for(int i = 0; i < n; ++i)
        (i%2 ? odd : even)[i/2] = f[i];
    FFT(even, w*w);
    FFT(odd, w*w);
    cpx wp(1, 0);
    for(int i = 0; i < n/2; ++i){
        f[i] = even[i] + wp*odd[i];
        f[i + n/2] = even[i] - wp*odd[i];
        wp *= w;
    }
}
 
vector<int> multiply(vector<int> f1, vector<int> f2){
    vector<cpx> a(all(f1));
    vector<cpx> b(all(f2));
    int n = 1;
    while(n < a.size()+1 || n < b.size()+1) n *= 2;
    n *= 2;
    a.resize(n);
    b.resize(n);
    vector<cpx> c(n); 
    cpx w(cos(2*PI/n), sin(2*PI/n));
    FFT(a, w);
    FFT(b, w);
    for(int i = 0; i < n; ++i)
        c[i] = a[i]*b[i];
    FFT(c, cpx(1, 0)/w);
    for(int i = 0; i < n; ++i){
        c[i] /= cpx(n, 0);
        c[i] = cpx(round(c[i].real()), round(c[i].imag()));
    }
    vector<int> f3;
    for(int e=0;e<sz(c);e++) f3.push_back((int)(c[e].real()+(c[e].real()>0?0.5:-0.5)));
    return f3;
}