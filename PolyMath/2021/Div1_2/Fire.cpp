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
int arr[MAX];
vector<pi> k1,k2;
void solve(int tc){
	int n;
	scanf("%d",&n);
	for(int e=1;e<=n;e++) scanf("%d",&arr[e]);
	for(int e=1;e<=n;e++){
		k1.push_back(mk(arr[e],e));
	}
	sort(all(k1));
	int xx = (n-2);
	int ans = 1e9;
	for(int p=0;p<min(10,sz(k1));p++){
		for(int q=p+1;q<min(10,sz(k1));q++){
			int f1 = k1[p].x,f2 = k1[q].x;
			int w1 = k1[p].y,w2 = k1[q].y;
			if(abs(w1-w2)==1||(w1==1&&w2==n)||(w1==n&&w2==1)){
				int x1 = 1,x2 = xx;
				while(x2>=1){
					ans = min(ans,max(f1-x1,f2-x2));
					x1++;
					x2--;
				}
			}else{	
				int x1 = 2,x2 = xx;
				while(x2>=2){
					ans = min(ans,max(f1-x1,f2-x2));
					x1++;
					x2--;
				}
			}
		}
	}
	printf("%d\n",ans);
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