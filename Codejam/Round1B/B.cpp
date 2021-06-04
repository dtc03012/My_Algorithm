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

const int MAX = 100;
lld arr[MAX];
lld nCr[MAX][MAX];
void solve(int tc){
	cout << "Case #"<< tc << ": ";
	int n,A,B;
	cin >> n >> A >> B;
	for(int e=1;e<=n;e++) cin >> arr[e];
	for(int e=n;e>=1;e--){
		if(e-A>0) arr[e-A] += arr[e];
		if(e-B>0) arr[e-B] += arr[e];
	}
	int N = n;
	while(true){
		if(N-A*MAX>0){
			cout << "IMPOSSIBLE\n";
			return;
		}
		bool suc = true;
		for(int e=1;e<=n;e++){
			bool flag = false;
			lld tot = 0;
			for(int p=0;p<MAX;p++){
				for(int q=0;q<MAX;q++){
					if(N-p*A-q*B==e){
						if(nCr[p+q][q]>=arr[e]-tot){
							flag = true;
							break;
						}else{
							tot += nCr[p+q][q];
						}
					}
				}
				if(flag) break;
			}
			if(!flag&&arr[e]) suc = false;
		}
		if(suc){
			cout << N << "\n";
			return;
		}
		N++;
	}
}


int main(void){
	for(int e=0;e<MAX;e++){
		nCr[e][e] = nCr[e][0] = 1;
	}
	for(int e=2;e<MAX;e++){
		for(int p=1;p<e;p++){
			if(nCr[e-1][p]>1e18-nCr[e-1][p-1]) nCr[e][p] = 1e18;
			else nCr[e][p] = nCr[e-1][p] + nCr[e-1][p-1];
		}
	}
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}