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

const int MAX = 402020;
int arr[MAX];
int dfs(int l,int r,int k){
	if(k==-1) return 0;
	if(l>r) return 0;
	int mid = r + 1;
	for(int e=l;e<=r;e++){
		if(arr[e]&(1<<k)){
			mid = e;
			break;
		}
	}
	int lv = mid - l;
	int rv = r - mid + 1;
	if(lv%2){
		int num = 1;
		vector<vector<int> > go;
		vector<int> k1;
		k1.push_back(-1);
		k1.push_back(-1);
		go.push_back(k1);
		for(int e=l;e<mid;e++){
			int st = 0;
			for(int p=k-1;p>=0;p--){
				int cnt = 0;
				if(arr[e]&(1<<p)) cnt = 1;
				if(go[st][cnt]==-1){
					vector<int> k1;
					k1.push_back(-1);
					k1.push_back(-1);
					go.push_back(k1);
					go[st][cnt] = num++;
				}
				st = go[st][cnt];
			}
		}
		int ans = 2e9;
		for(int e=mid;e<=r;e++){
			int st = 0,vv = (1<<k);
			for(int p=k-1;p>=0;p--){
				int cnt = 0;
				if(arr[e]&(1<<p)) cnt = 1;
				if(go[st][cnt]==-1){
					vv += (1<<p);
					st = go[st][cnt^1];
				}else{
					st = go[st][cnt];
				}
			}
			ans = min(ans,vv);
		}
		return ans;
	}else{
		return max(dfs(l,mid-1,k-1),dfs(mid,r,k-1));
	}
}
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n*2;e++) cin >> arr[e];
	sort(arr,arr+n*2);
	cout << dfs(0,n*2-1,30);
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