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
struct inf{
	int st;
	lld val,l,r;
	int wh;
};
struct inf2{
	lld val;
	int pri,st;
};
bool operator<(const inf2& a,const inf2& b){
	if(a.val!=b.val) return a.val < b.val;
	if(a.pri!=b.pri) return a.pri < b.pri;
	return a.st < b.st;
}
vector<inf> vv;
set<int> s;
lld what(lld l,lld r,int wh){
	if(wh==1) return l * r;
	if(wh==2) return l / r;
	if(wh==3) return l + r;
	return l - r;
}
void solve(int tc){
	string ss;
	cin >> ss;
	lld tot = 0;
	vector<pli> v;
	for(int e=0;e<sz(ss);e++){
		if(ss[e]>='0'&&ss[e]<='9'){
			tot = tot*10 + ss[e] - '0';
		}else{
			v.push_back(mk(tot,0));
			if(ss[e]=='*'){
				v.push_back(mk(0,1));
			}
			if(ss[e]=='/'){
				v.push_back(mk(0,2));
			}
			if(ss[e]=='+'){
				v.push_back(mk(0,3));
			}
			if(ss[e]=='-'){
				v.push_back(mk(0,4));
			}
			tot = 0;
		}
	}
	if(sz(v)==0){
		printf("%lld\n",tot);
		return;
	}
	priority_queue<inf2> q;
	v.push_back(mk(tot,0));
	for(int e=1;e<sz(v);e+=2){
		s.insert(sz(vv));
		lld tot = what(v[e-1].x,v[e+1].x,v[e].y);
		q.push({tot,-((v[e].y+1)/2),-sz(vv)});
		vv.push_back({sz(vv),tot,v[e-1].x,v[e+1].x,v[e].y});
	}
	while(!q.empty()&&sz(s)>1){
		inf2 xx = q.top();q.pop();
		xx.st *= -1;
		if(vv[xx.st].val!=xx.val) continue;
		set<int>::iterator it = s.lower_bound(xx.st);
		{
			if(it!=s.begin()){
				it--;
				int pos = *it;
				vv[pos].r = xx.val;
				lld tot = what(vv[pos].l,vv[pos].r,vv[pos].wh);
				vv[pos].val = tot;
				q.push({tot,-((vv[pos].wh+1)/2),-pos});
				it++;
			}
		}
		{
			it++;
			if(it!=s.end()){
				int pos = *it;
				vv[pos].l = xx.val;
				lld tot = what(vv[pos].l,vv[pos].r,vv[pos].wh);
				vv[pos].val = tot;
				q.push({tot,-((vv[pos].wh+1)/2),-pos});
			}
			it--;
		}
		s.erase(xx.st);
	}
	printf("%lld\n",vv[*s.begin()].val);
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