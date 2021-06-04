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

int arr[5] = {1};
int n;
int query(int x){
	if(x==0||x==n+1) return 1e9;
	cout << "? " << x << endl;
	return arr[x-1];
	int k;
	cin >> k;
	return k;
}
void ans(int x){
	cout << "! " << x << endl;
	exit(0);
}
void solve(int tc){
	cin >> n;
	int ll = 1,rr = n,mid;
	while(ll<=rr){
		mid = (ll+rr)/2;
		int f1 = query(ll);
		int f2 = query(rr);
		int f3 = query(mid);
		int xx = min({f1,f2,f3});
		if(xx==f1){
			int a = query(ll-1);
			int b = query(ll+1);
			if(f1<a&&f1<b) ans(ll);
			rr = mid + 1;
		}else if(xx==f2){
			int a = query(rr-1);
			int b = query(rr+1);
			if(f2<a&&f2<b) ans(rr);
			ll = mid - 1;
		}else if(xx==f3){
			int a = query(mid-1);
			int b = query(mid+1);
			if(f3<a&&f3<b) ans(mid);
			if(a>b) ll = mid + 1;
			else rr = mid - 1;
		}
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
		scanf("%d",&tc);
	*/
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}