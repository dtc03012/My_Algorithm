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
int arr[MAX],n,k,vis[MAX];
lld sum[MAX];
void solve(int tc){
	cin >> n >> k;
	for(int e=1;e<=n;e++){
		cin >> arr[e];
		sum[e] = sum[e-1] + arr[e];
	}
	priority_queue<pi> q;
	for(int e=1;e<=n;e++){
		int ll = 0,rr = n,mid,ans=0;
		while(ll<=rr){
			mid = (ll+rr)/2;
			if(e+mid-1>n){
				rr = mid - 1;
				continue;
			}
			if(sum[e+mid-1]-sum[e-1]<=k){
				ll = mid + 1;
				ans = max(ans,mid);
			}else rr = mid - 1;
		}
		q.push(mk(ans,e));
	}
	int ans = 0;
	while(!q.empty()){
		int xx = q.top().x;
		int wh = q.top().y;
		q.pop();
		if(wh+xx<=n&&wh+xx*2<=n&&vis[wh+xx]&&vis[wh+xx*2]){
			ans = xx;
			break;
		}else if(wh-xx>=1&&wh-xx*2>=1&&vis[wh-xx]&&vis[wh-xx*2]){
			ans = xx;
			break;
		}else if(wh+xx<=n&&wh-xx>=1&&vis[wh+xx]&&vis[wh-xx]){
			ans = xx;
			break;
		}
		vis[wh] = 1;
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