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

int vv[7] = {0,5,2,1,6,4,3};
int query(int t,int i,int j,int x){
	cout << "? " << t << " " << i << " " << j << " " << x << endl;
	// if(t==1){
	// 	return max(min(x,vv[i]),min(x+1,vv[j]));
	// }else{
	// 	return min(max(x,vv[i]),max(x+1,vv[j]));
	// }
	int k;
	cin >> k;
	return k;
}
const int MAX = 10101;
int arr[MAX],ans[MAX],n;
void ansv(){
	cout << "! ";
	for(int e=1;e<=n;e++) cout << ans[e] << " ";
	cout << endl;
}
void solve(int tc){
	cin >> n;
	memset(ans,-1,sizeof(ans));
	int x = query(2,1,2,1);
	int y = query(1,2,1,n-1);
	int x1 = query(2,1,3,1);
	int y1 = query(1,3,1,n-1);
	int x2 = query(2,2,1,1);
	int y2 = query(1,1,2,n-1);
	int x3 = query(2,3,1,1);
	int y3 = query(2,1,3,n-1);
	if(x==1) ans[1] = 1;
	else if(y==n) ans[1] = n;
	else if(x2==1) ans[1] = y;
	else if(y2==n) ans[1] = x;
	else if(x3==1) ans[1] = y1;
	else if(y3==n) ans[1] = x1;
	else if(x==x1||x==y1) ans[1] = x;
	else ans[1] = y;
	if(ans[1]<=(n/2)){
		for(int p=2;p<=n;p++){
			int z = query(1,1,p,n-1);
			ans[p] = z;
		}
		for(int p=2;p<=n;p++){
			if(ans[p]==ans[1]){
				int z = query(2,p,1,1);
				ans[p] = z;
			}
		}
	}else{
		for(int p=2;p<=n;p++){
			int z = query(2,p,1,1);
			ans[p] = z;
		}
		for(int p=2;p<=n;p++){
			if(ans[p]==ans[1]){
				int z = query(1,1,p,n-1);
				ans[p] = z;
			}
		}
	}
	ansv();
}


int main(void){
	/*
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	*/
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}