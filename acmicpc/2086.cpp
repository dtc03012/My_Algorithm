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

const lld mod = 1e9;
struct matrix{
	lld A[2][2];
	matrix(){
		A[0][0] = A[0][1] = A[1][0] = 1;
		A[1][1] = 0;
	}
	void zero(){
		memset(A,0,sizeof(A));
	}
	lld get(int y,int x){
		return A[y][x];
	}
	void add(int y,int x,lld k){
		A[y][x] = (A[y][x]+k)%mod;
	}
	friend matrix operator*(matrix& A,matrix& B){
		matrix X;
		X.zero();
		for(int e=0;e<2;e++){
			for(int p=0;p<2;p++){
				for(int q=0;q<2;q++){
					X.add(e,p,A.get(e,q)*B.get(q,p));
				}
			}
		}
		return X;
	}
};

matrix multiply(lld num){
	if(num==1) return matrix();
	matrix now = multiply(num/2);
	if(num%2==0) return now * now;
	matrix X = now * now;
	matrix Y = matrix();
	return X * Y;
}
void solve(int tc){
	lld a,b;
	cin >> a >> b;
	a--;
	a += 3;
	b += 3;
	matrix A = multiply(a);
	matrix B = multiply(b);
	lld f1 = A.get(1,1) + 1;
	lld f2 = B.get(1,1) + 1;
	f2 -= f1;
	f2 = (f2%mod+mod)%mod;
	cout << f2;
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