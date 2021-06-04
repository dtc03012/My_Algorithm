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

const int MAX = 1010101;
int A[MAX],B[MAX];
void solve(int tc){
	int n;
	cin >> n;
	vector<pi> v;
	for(int e=0;e<n;e++) cin >> A[e];
	for(int e=0;e<n;e++) cin >> B[e];
	for(int e=0;e<n;e++){
		int X = (B[e]-A[e]);
		int Y = A[e] - 2*X;
		v.push_back(mk(X,Y));
	}
	sort(v.begin()+1,v.end());
	int tot = 0;
	for(int p=0;p<sz(v);p++){
		if(p>tot){
			cout << "NO\n";
			return;
		}
		tot += min(v[p].x,n-p-v[p].y);
	}
	cout << "YES\n";
}


int main(void){
	
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