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

const int MAX = 2020202;
int arr[MAX],cnt[MAX];
void solve(int tc){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	int xx = -1;
	for(int e=1;e<=m;e++) cnt[arr[e]]++;
	for(int e=0;e<=n+1;e++){
		if(cnt[e]==0){
			xx = e;
			break;
		}
	}
	int result = 1e9;
	for(int e=m;e<=n;e++){
		result = min(result,xx);
		int ll = xx;
		if(arr[e-m+1]<xx){
			cnt[arr[e-m+1]]--;
			if(cnt[arr[e-m+1]]==0) xx = arr[e-m+1];
		}else{
			cnt[arr[e-m+1]]--;
		}
		if(e==n) break;
		if(arr[e+1]==xx){
			cnt[arr[e+1]]++;
			if(ll!=xx){
				xx = ll;
			}else{
				while(cnt[xx]) xx++;
			}
		}else{
			cnt[arr[e+1]]++;
		}
	}
	printf("%d",result);
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