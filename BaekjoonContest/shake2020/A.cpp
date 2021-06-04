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
typedef pair<string,string> ps;
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

const int MAX = 505;
ps arr[MAX];
string llt = "0900";
int lin[MAX],pos[MAX],ll[MAX],ans;
int n,t,p;
int diff(string a,string b){
	int f1 = (a[0]-'0')*10 + (a[1]-'0');
	int s1 = (b[0]-'0')*10 + (b[1]-'0');
	int tot = s1 - f1;
	int t1 = (a[2]-'0')*10 + (a[3]-'0');
	int k1 = (b[2]-'0')*10 + (b[3]-'0');
	if(t1>k1){
		tot--;
		tot *= 60;
		tot += (k1+60-t1);
	}else{
		tot *= 60;
		tot += (k1-t1);
	}
	return tot;
}
bool tmr(pair<string,int> a,pair<string,int> b){
	int wh1 = a.y;
	int wh2 = b.y;
	if(a.x!=b.x) return a.x < b.x;
	if(wh1*wh2<0) return wh1 < wh2;
	if(wh1>0&&wh2>0){
		int x1 = diff(arr[wh1].x,arr[wh1].y);
		int x2 = diff(arr[wh2].x,arr[wh2].y);
		return x1 < x2;
	}
	return wh1 < wh2;
}
void solve(int tc){
	scanf("%d%d%d",&n,&t,&p);
	for(int e=1;e<=t;e++) cin >> arr[e].x >> arr[e].y;
	vector<pair<string,int> > v;
	for(int e=1;e<=t;e++){
		v.push_back(mk(arr[e].x,e));
		v.push_back(mk(arr[e].y,-e));
	}
	sort(all(v),tmr);
	for(int e=0;e<sz(v);e++){
		if(v[e].y>0){
			memset(ll,-1,sizeof(ll));
			int lst = -1;
			for(int q=1;q<=n;q++){
				if(lin[q]) lst = q;
				else{
					if(lst==-1) ll[q] = 1e9;
					else ll[q] = q - lst;
				}
			}
			lst = -1;
			for(int q=n;q>=1;q--){
				if(lin[q]) lst = q;
				else{
					if(lst==-1) ll[q] = min(ll[q],(int)1e9);
					else ll[q] = min(ll[q],lst-q);
				}
			}
			int wh = 0,xx = -1;
			for(int q=1;q<=n;q++){
				if(ll[q]>wh){
					wh = ll[q];
					xx = q;
				}
			}
			if(xx!=-1){
				if(xx==p) ans += diff(llt,v[e].x);
				lin[xx] = 1;
				pos[v[e].y] = xx;
			}
		}else{
			v[e].y *= -1;
			if(pos[v[e].y]==p) llt = v[e].x;
			lin[pos[v[e].y]] = 0;
			pos[v[e].y] = 0;
		}
	}
	string last = "2100";
	ans += diff(llt,last);
	printf("%d",ans);
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