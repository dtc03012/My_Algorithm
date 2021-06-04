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
int arr[MAX];
void solve(int tc){
	int n;
	lld k;
	cin >> n >> k;
	for(int e=0;e<n;e++) cin >> arr[e];
	sort(arr,arr+n);
	int xx = arr[0];
	for(int e=1;e<n;e++) xx = __gcd(xx,arr[e]);
	int ans = xx;
	set<int> s;
	for(int e=0;e<n;e++){
		for(int p=1;p*p<=arr[e];p++){
			if(arr[e]%p==0){
				int f1 = p;
				int f2 = arr[e]/p;
				if(f1<=arr[0]) s.insert(f1);
				if(f2<=arr[0]) s.insert(f2);
			}
		}
	} 
	for(auto e : s){
		if(arr[0]%e==0){
			int f1 = e;
			int f2 = arr[0]/e;
			{
				lld tot = 0;
				for(int p=1;p<n;p++){
					tot += arr[p]%f1;
				}
				if(k>=tot) ans = max(ans,f1);
			}
			{
				lld tot = 0;
				for(int p=1;p<n;p++){
					tot += arr[p]%f2;
				}
				if(k>=tot) ans = max(ans,f2);
			}
		}
	}
	cout << ans << "\n";
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