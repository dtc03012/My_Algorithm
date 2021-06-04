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

const int MAX = 55;
struct matrix{
	int arr[MAX][MAX],mod,n,A,B,C;
	matrix(int A,int B,int C,int n,int mod){
		this->mod = mod;
		this->n = n;
		this->A = A;
		this->B = B;
		this->C = C;
		memset(arr,0,sizeof(arr));
		for(int e=0;e<n;e++){
			if(e-1>=0) arr[e][e-1] = A;
			arr[e][e] = B;
			if(e+1<n) arr[e][e+1] = C;
		}
	}
	int get(int y,int x){
		return arr[y][x];
	}
	void add(int y,int x,int k){
		arr[y][x] = (arr[y][x]+k)%mod;
	}
	void zero(){
		memset(arr,0,sizeof(arr));
	}
	void one(){
		zero();
		for(int e=0;e<n;e++) arr[e][e] = 1;
	}
	friend matrix operator*(matrix A,matrix B){
		matrix C = A;
		C.zero();
		int n = A.n;
		for(int e=0;e<n;e++){
			for(int p=0;p<n;p++){
				for(int q=0;q<n;q++){
					C.add(e,p,A.get(e,q)*B.get(q,p));
				}
			}
		}
		return C;
	}
};
matrix multiply(int A,int B,int C,int n,int mod,int num){
	matrix X(A,B,C,n,mod);
	if(num==0) {
		X.one();
		return X;
	}
	if(num==1) return X;
	matrix now2 = multiply(A,B,C,n,mod,num/2);
	if(num%2==0) return now2 * now2;
	matrix Y = now2 * now2;
	return X * Y;
}
int arr[MAX];
void solve(int tc){
	while(true){
		int n,mod,a,b,c,t;
		cin >> n >> mod >> a >> b >> c >> t;
		if(n==0) break;
		matrix X = multiply(a,b,c,n,mod,t);
		for(int e=0;e<n;e++) cin >> arr[e];
		for(int e=0;e<n;e++){
			int ans = 0;
			for(int p=0;p<n;p++){
				ans = (ans + X.get(e,p)*arr[p])%mod;
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	/*
		cin >> tc;
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}