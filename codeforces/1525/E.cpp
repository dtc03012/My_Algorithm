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

const int MAX = 50505;
const int NMAX = 22;
const lld mod =  998244353;
int arr[MAX][NMAX];
lld calc(lld now,lld num){
	if(num==0) return 1;
	if(num==1) return now;
	lld now2 = calc(now,num/2);
	if(num%2==0) return (now2*now2)%mod;
	return (((now2*now2)%mod)*now)%mod;
}
void solve(int tc){
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++){
		for(int p=0;p<m;p++){
			cin >> arr[p][e];
		}
	}
	lld ans = 0;
	for(int e=0;e<m;e++){
		vector<int> v;
		for(int p=0;p<n;p++) v.push_back(arr[e][p]);
		sort(all(v));
		for(int p=1;p<=n;p++){
			for(int q=0;q<n;q++){
				if(v[q]>p) break;
				ans = (ans+calc(n,mod-2))%mod;
			}

		}
	}
	cout << ans;
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