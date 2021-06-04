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

const int MAX = (1<<20);
vector<int> v[MAX];
int arr[20];
void solve(int tc){
	int n;
	scanf("%d",&n);
	int mx = (1<<n);
	int lim = (1<<n);
	string a;
	cin >> a;
	for(int e=0;e<n;e++){
		arr[e] = a[e] - '0';
		for(int p=0;p<mx/lim;p++){
			if(p%2) arr[e] ^= 1;
			int ty = arr[e];
			for(int q=p*lim;q<(p+1)*lim;q++){
				v[q].push_back(ty);
				ty ^= 1;
			}
		}
		lim /= 2;
	}
	for(int e=0;e<mx;e++){
		for(int p=0;p<n;p++) printf("%d",v[e][p]);
		printf("\n");
	}
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