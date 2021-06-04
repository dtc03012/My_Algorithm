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

const int MAX = 3030;
int arr[MAX][5],gg[5];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++){
		for(int p=0;p<5;p++){
			cin >> arr[e][p];
			gg[p] = max(gg[p],arr[e][p]);
		}
	}
	int ans = 0;
	for(int e=0;e<n;e++){
		for(int p=e+1;p<n;p++){
			pi vv[5]; 
			for(int r=0;r<5;r++){
				vv[r].x = max(arr[e][r],arr[p][r]);
				vv[r].y = r;
			}
			sort(vv,vv+5);
			if(gg[vv[0].y]>vv[1].x) ans = max(ans,vv[1].x);
			else ans = max(ans,gg[vv[0].y]);
		}
	}
	cout << ans;
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