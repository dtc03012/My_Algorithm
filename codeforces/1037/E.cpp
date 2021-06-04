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
int ans[MAX],n,m,k,ck[MAX];
set<int> s[MAX],vv;
pi arr[MAX];
void solve(int tc){
	scanf("%d%d%d",&n,&m,&k);
	for(int e=0;e<m;e++){
		int x,y;
		scanf("%d%d",&x,&y);
		s[x].insert(y);
		s[y].insert(x);
		arr[e] = mk(x,y);
	}
	priority_queue<pi> pq;
	for(int e=1;e<=n;e++){
		pq.push(mk(-sz(s[e]),e));
	}
	int tot = n;
	for(int e=m-1;e>=0;e--){
		while(!pq.empty()){
			pi xx = pq.top();
			int pos = xx.y;
			if(sz(s[pos])!=-xx.x||ck[pos]){
				pq.pop();
				continue;
			}
			if(-xx.x<k){
				pq.pop();
				for(auto q : s[pos]){
					s[q].erase(pos);
					pq.push(mk(-sz(s[q]),q));
				}
				ck[pos] = 1;
				s[pos].clear();
				tot--;
			}else break;
		}
		ans[e] = tot;
		int f1 = arr[e].x;
		int f2 = arr[e].y;
		s[f1].erase(f2);
		s[f2].erase(f1);
		pq.push(mk(-sz(s[f1]),f1));
		pq.push(mk(-sz(s[f2]),f2));
	}
	for(int e=0;e<m;e++) printf("%d\n",ans[e]);
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