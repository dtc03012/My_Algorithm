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


void solve(int tc){
	int n,k;
	scanf("%d%d",&n,&k);
	int base = 1;
	vector<int> v;
	while(true){
		if(k==2){
			v.push_back(base*(n/2));
			v.push_back(base*(n/2));
			break;
		}
		if(n<2*k){
			for(int e=0;e<k-(n%k);e++) v.push_back(base);
			for(int e=0;e<n%k;e++) v.push_back(base*2);
			break;
		}
		if(n%2){
			v.push_back(base);
			n--;
			k--;
		}else{
			base *= 2;
			n /= 2;
		}
	}
	for(int e=0;e<sz(v);e++) printf("%d ",v[e]);
	printf("\n");
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