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


const int MAX = 2020;
int arr[MAX],sum[MAX];
void solve(int tc){
	int n;
	cin >> n;
	int tot = 0;
	for(int e=1;e<=n;e++){
		cin >> arr[e];
		tot ^= arr[e];
		sum[e] = sum[e-1] ^ arr[e];
	}
	for(int e=2;e<=n;e++){
		int f1 = sum[e-1];
		int f2 = tot ^ f1;
		if(f1==f2){
			cout << "YES\n";
			return;
		}
	}
	for(int e=2;e<=n-1;e++){
		for(int p=e;p<=n-1;p++){
			int f1 = sum[e-1];
			int f2 = sum[p] ^ sum[e-1];
			int f3 = sum[n] ^  sum[p];
			if(f1==f2&&f2==f3){
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
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