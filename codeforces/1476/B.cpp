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

const int MAX = 101;
lld arr[MAX];
void solve(int tc){
	int n;
	lld k;
	scanf("%d%lld",&n,&k);
	for(int e=0;e<n;e++) scanf("%lld",&arr[e]);
	lld ll = 0,rr = 1e16,ans = 1e16,mid;
	while(ll<=rr){
		mid = (ll+rr)/2;
		lld tot = arr[0] + mid;
		bool suc = true;
		for(int e=1;e<n;e++){
			if(arr[e]*100>tot*k){
				suc = false;
				break;
			}
			tot += arr[e];
		}
		if(suc){
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
	
		scanf("%d",&tc);
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}