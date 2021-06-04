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
map<pair<pi,pi>,int> mm;
map<pi,int> mm2;
pair<pi,pi> arr[MAX];
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=0;e<n;e++){
		scanf("%d%d%d",&arr[e].x.x,&arr[e].x.y,&arr[e].y.x);
		if(arr[e].x.x<0){
			arr[e].x.x *= -1;
			arr[e].x.y *= -1;
			arr[e].y.x *= -1;
		}
		if(arr[e].x.x==0){
			if(arr[e].x.y<0){
				arr[e].x.y *= -1;
				arr[e].y.x *= -1;
			}
			arr[e].y.y = abs(arr[e].x.y);
			arr[e].x.y /= abs(arr[e].x.y);
		}else if(arr[e].x.y==0){
			arr[e].y.y = abs(arr[e].x.x);
			arr[e].x.x /= abs(arr[e].x.x);
		}else{
			int xx = __gcd(abs(arr[e].x.x),abs(arr[e].x.y));
			arr[e].x.x /= xx;
			arr[e].x.y /= xx;
			arr[e].y.y = xx;
		}
		if(arr[e].y.x==0) arr[e].y.y = 0;
		else{
			int xx = __gcd(arr[e].y.x,arr[e].y.y);
			arr[e].y.x /= xx;
			arr[e].y.y /= xx;
		}
		mm[arr[e]]++;
		mm2[arr[e].x]++;
	}
	lld ans = 0;
	for(int e=0;e<n;e++){
		mm2[arr[e].x]--;
		mm[arr[e]]--;
		int cnt = (n-e-1) - mm2[arr[e].x];
		cnt += (mm[arr[e]]);
		ans += cnt;
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