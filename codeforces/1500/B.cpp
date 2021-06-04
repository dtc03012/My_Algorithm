#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef pair<int,int> pi;
typedef pair<lld,lld> pl;
typedef pair<int,lld> pil;
typedef pair<lld,int> pli;
typedef vector<int> vit;
typedef vector<vit> vitt;
typedef vector<lld> vlt;
typedef vector<vlt> vltt;
typedef vector<pi> vpit;
typedef vector<vpit> vpitt;
typedef long double ld;
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define mk(a,b) make_pair(a,b)
bool isrange(int y,int x,int n,int m){
	 if(0<=y&&y<n&&0<=x&&x<m) return true;
	 return false;
}
int dy[4] = {1,0,-1,0},dx[4]={0,1,0,-1},ddy[8] = {1,0,-1,0,1,1,-1,-1},ddx[8] = {0,1,0,-1,1,-1,1,-1};

const int MAX = 505050;
int ck1[MAX*2],ck2[MAX*2],n,m;
lld k;
vector<lld> v;
lld ext_gcd ( lld A, lld B, lld *X, lld *Y ){
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

pair<lld, lld> chinese_remainder_theorem( vector<lld> A, vector<lld> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/
 
    int n = A.size();
 
    lld a1 = A[0];
    lld m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
 
    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        lld a2 = A[i];
        lld m2 = M[i];
 
        lld g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/
 
        /** Merge the two equations*/
        lld p, q;
        ext_gcd(m1/g, m2/g, &p, &q);
 
        lld mod = m1 / g * m2; /** LCM of m1 and m2*/
 
        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        lld x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;
 
        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
}
bool can(lld x){
	lld gcdnm = __gcd(n,m);
	lld plus = 1ll*n*m;
	plus /= gcdnm;
	lld tot = x;
	for(int e=0;e<sz(v);e++){
		if(v[e]<=x){
			lld now = 1 + (x-v[e])/plus;
			tot -= now;
		}
	}
	if(tot>=k) return true;
	return false;
}
void solve(int tc){
	memset(ck1,-1,sizeof(ck1));
	memset(ck2,-1,sizeof(ck2));
	scanf("%d%d%lld",&n,&m,&k);
	for(int e=0;e<n;e++){
		int r;
		scanf("%d",&r);
		ck1[r] = e;
	}
	for(int e=0;e<m;e++){
		int r;
		scanf("%d",&r);
		ck2[r] = e;
	}
	for(int e=0;e<MAX*2;e++){
		if(ck1[e]!=-1&&ck2[e]!=-1){
			lld f = ck1[e], fmod = n;
			lld fv = __gcd(f,fmod);
			lld s = ck2[e], smod = m;
			lld sv = __gcd(s,smod);
			vector<lld> A,B;
			A.push_back(f);
			A.push_back(s);
			B.push_back(fmod);
			B.push_back(smod);
			pl xx = chinese_remainder_theorem(A,B);
			if(xx.x!=-1)v.push_back(xx.x+1);
		}
	}
	lld ll = k,rr = 1e18,mid,ans = 1e18;
	while(ll<=rr){
		mid = (ll+rr)/2;
		if(can(mid)){
			ans = min(ans,mid);
			rr = mid - 1;
		}else ll = mid + 1;
	}
	printf("%lld\n",ans);
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}