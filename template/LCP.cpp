const int MAX = 202020;
int n;
string s;
struct Node{
	int sa;
	pi rank;
	bool operator<(const Node& O)const{
		return rank < O.rank;
	}
};
int pos[MAX],sa[MAX],lcp[MAX],cnt[MAX];
Node node[MAX],arrnode[MAX];
void constructSA(){
	for(int e=0;e<n;e++){
		node[e].sa = e;
		node[e].rank = mk(s[e]-'a',(e<n-1?s[e+1]-'a':-1));
	}
	sort(node,node+n);
	for(int d=2;d<n;d*=2){
		int temp = node[0].rank.x,M = 0;
		node[0].rank.x = pos[node[0].sa] = 0;
		for(int e=1;e<n;e++){
			if(mk(temp,node[e-1].rank.y)==node[e].rank) node[e].rank.x = M;
			else{
				temp = node[e].rank.x;
				node[e].rank.x = ++M;
			}
			pos[node[e].sa] = e;
		}
		M++;
		for(int e=0;e<n;e++){
			int j = node[e].sa + d;
			node[e].rank.y = (j<n?node[pos[j]].rank.x:-1);
		}
		memset(cnt,0,sizeof(cnt));
		for(int e=0;e<n;e++) cnt[node[e].rank.y+1]++;
		for(int e=1;e<=M;e++) cnt[e] += cnt[e-1];
		for(int e=n-1;e>=0;e--) arrnode[--cnt[node[e].rank.y+1]] = node[e];
		memset(cnt,0,sizeof(cnt));
		for(int e=0;e<n;e++) cnt[arrnode[e].rank.x]++;
		for(int e=1;e<=M;e++) cnt[e] += cnt[e-1];
		for(int e=n-1;e>=0;e--) node[--cnt[arrnode[e].rank.x]] = arrnode[e];
	}
	for(int e=0;e<n;e++){
		pos[node[e].sa] = e;
		sa[e] = node[e].sa;
	}
}
void constructLCP(){
	for(int i=0,k=0;i<n;i++,k=max(k-1,0)){
		if(pos[i]==n-1) continue;
		for(int j=sa[pos[i]+1];i+k<n&&j+k<n&&s[i+k]==s[j+k];k++);
		lcp[pos[i]] = k;
	}
}