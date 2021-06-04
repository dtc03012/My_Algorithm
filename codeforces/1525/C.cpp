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

const int MAX = 303030;
vector<pair<int,pi> > v[2]; // 0 R , 1 L 
int ans[MAX],arr[MAX];
bool comp(pi a,pi b){
	if(a.x!=b.x) return a.x < b.x;
	return a.y < b.y;
}
bool tmr(pair<int,pi> a,pair<int,pi> b)
{
	return a.y.x < b.y.x;
}
void solve(int tc){
	for(int e=0;e<2;e++){
		v[e].clear();
	}
	int n,m;
	cin >> n >> m;
	for(int e=0;e<n;e++){
		cin >> arr[e];
		ans[e] = -1;
	}
	for(int e=0;e<n;e++){
		char s[2];
		cin >> s;
		if(s[0]=='R'){
			v[arr[e]%2].push_back(mk(0,mk(arr[e],e)));
		}else{
			v[arr[e]%2].push_back(mk(1,mk(arr[e],e)));
		}
	}
	for(int e=0;e<2;e++) sort(all(v[e]),tmr);
	for(int e=0;e<2;e++){
		queue<pi> ll;
		stack<pi> rr;
		for(int p=0;p<sz(v[e]);p++){
			if(v[e][p].x==0){
				rr.push(v[e][p].y);
			}else{
				if(sz(rr)){
					pi xx = rr.top();rr.pop();
					int x1 = xx.x;
					int pos1 = xx.y;
					int x2 = v[e][p].y.x;
					int pos2 = v[e][p].y.y;
					int dist = (x1+x2)/2 - x1;
					ans[pos1] = dist;
					ans[pos2] = dist;
				}else{
					ll.push(v[e][p].y);
				}
			}
		}
		while(sz(ll)>1){
			pi f1 = ll.front();ll.pop();
			pi f2 = ll.front();ll.pop();
			int x1 = f1.x;
			int pos1 = f1.y;
			int x2 = f2.x;
			int pos2 = f2.y;
			int dist = x2 - (x2-x1)/2;
			ans[pos1] = dist;
			ans[pos2] = dist;
		}
		while(sz(rr)>1){
			pi f1 = rr.top();rr.pop();
			pi f2 = rr.top();rr.pop();
			int x1 = f1.x;
			int pos1 = f1.y;
			int x2 = f2.x;
			int pos2 = f2.y;
			int dist = m - (x1-x2)/2 - x2;
			ans[pos1] = dist;
			ans[pos2] = dist;
		}
		if(sz(ll)&&sz(rr)){
			pi f1 = ll.front();ll.pop();
			pi f2 = rr.top();rr.pop();
			int x1 = f1.x;
			int pos1 = f1.y;
			int x2 = f2.x;
			int pos2 = f2.y;
			int dist = m - (x1+x2)/2 + x1;
			ans[pos1] = dist;
			ans[pos2] = dist;
		}
	}
	for(int e=0;e<n;e++) cout << ans[e] << " ";
	cout << "\n";
}


int main(void){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc = 1;
	
		cin >> tc;
	
	for(int test_number=1;test_number<=tc;test_number++){
		solve(test_number);
	}
	return 0;
}