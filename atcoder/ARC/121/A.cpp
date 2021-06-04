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

const int MAX = 202020;
pair<pi,int> arr[MAX],arr2[MAX];
void solve(int tc){
	int n;
	cin >> n;
	for(int e=0;e<n;e++){
		cin >> arr[e].x.x >> arr[e].x.y;
		arr[e].y = e;
		arr2[e] = mk(mk(arr[e].x.y,arr[e].x.x),e);
	}
	sort(arr,arr+n);
	sort(arr2,arr2+n);
	vector<pair<int,pi> > v;
	for(int e=1;e<n;e++){
		v.push_back(mk(abs(arr[e].x.x-arr[0].x.x),mk(arr[e].y,arr[0].y)));
		v.push_back(mk(abs(arr2[e].x.x-arr2[0].x.x),mk(arr2[e].y,arr2[0].y)));
	}
	for(int e=2;e<n;e++){
		v.push_back(mk(abs(arr[e].x.x-arr[1].x.x),mk(arr[e].y,arr[1].y)));
		v.push_back(mk(abs(arr2[e].x.x-arr2[1].x.x),mk(arr2[e].y,arr2[1].y)));
	}
	for(int e=n-2;e>=1;e--){
		v.push_back(mk(abs(arr[e].x.x-arr[n-1].x.x),mk(arr[e].y,arr[n-1].y)));
		v.push_back(mk(abs(arr2[e].x.x-arr2[n-1].x.x),mk(arr2[e].y,arr2[n-1].y)));
	}
	for(int e=n-3;e>=1;e--){
		v.push_back(mk(abs(arr[e].x.x-arr[n-2].x.x),mk(arr[e].y,arr[n-2].y)));
		v.push_back(mk(abs(arr2[e].x.x-arr2[n-2].x.x),mk(arr2[e].y,arr2[n-2].y)));
	}
	sort(all(v));
	for(int e=0;e<sz(v);e++){
		if(v[e].y.x>v[e].y.y) swap(v[e].y.x,v[e].y.y);
	}
	int len = sz(v);
	if(v[len-1].y.x==v[len-2].y.x&&v[len-1].y.y==v[len-2].y.y){
		cout << v[len-3].x << endl;
	}else{
		cout << v[len-2].x << endl;
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