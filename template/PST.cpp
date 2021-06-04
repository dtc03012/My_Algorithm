const int MAX = 505050;
struct Node{
	int val,wh;
	Node* left;
	Node* right;
	Node(int wh){
		this->val = 0;
		this->wh = wh;
		left = NULL;
		right = NULL;
	}
};
struct pst{
	int start = 1,st;
	Node* rt[MAX];
	pst(){
		start = 1;
		while(start<MAX) start *= 2;
		rt[0] = init(0,start);
		st = 1;
	}
	Node* init(int ns,int ne){
		if(ns+1==ne){
			Node* now = new Node(0);
			return now;
		}
		int mid = (ns+ne)/2;
		Node* now = new Node(0);
		now->left = init(ns,mid);
		now->right = init(mid,ne);
		return now;
	}
	void add(int x){
		rt[st] = add(rt[st-1],0,start,x,x+1);
		st++;
	}
	Node* add(Node* ln,int ns,int ne,int l,int r){
		if(ne<=l||r<=ns) return ln;
		if(ns>=l&&ne<=r){
			Node* now = new Node(st);
			now->val = ln->val + 1;
			return now;
		}
		int mid = (ns+ne)/2;
		Node* now = new Node(st);	
		now->left = add(ln->left,ns,mid,l,r);
		now->right = add(ln->right,mid,ne,l,r);
		now->val = now->left->val + now->right->val;
		return now;
	}
	void del(int k){
		for(int e=0;e<k;e++,st--){
			del(rt[st-1],0,start);
		}
	}
	void del(Node* now,int ns,int ne){
		if(ns+1==ne){
			delete now;
			return;
		}	
		int mid = (ns+ne)/2;
		if(now->left->wh==(st-1)) del(now->left,ns,mid);
		if(now->right->wh==(st-1)) del(now->right,mid,ne);
		delete now;
	}
	int fmin(int l,int r,int x){
		return fmin(rt[l-1],rt[r],0,start,1,x+1);	
	}
	int fmin(Node* lv,Node* rv,int ns,int ne,int l,int r){
		if(r<=ns||ne<=l) return 0;
		if(ns>=l&&ne<=r) return rv->val - lv->val;
		int mid = (ns+ne)/2;
		return fmin(lv->left,rv->left,ns,mid,l,r) + fmin(lv->right,rv->right,mid,ne,l,r);
	}
	int getXth(int l,int r,int x){
		return getXth(rt[l-1],rt[r],0,start,x);
	}
	int getXth(Node* lv,Node* rv,int ns,int ne,int k){
		if(ns+1==ne) return ns;
		int mid = (ns+ne)/2;
		int xx = rv->left->val  - lv->left->val;
		if(k<=xx) return getXth(lv->left,rv->left,ns,mid,k);
		return getXth(lv->right,rv->right,mid,ne,k-xx);
	}
	int bxor(int l,int r,int x){
		return bxor(rt[l-1],rt[r],0,start,x,(r-l+1),start/2);
	}
	int bxor(Node* lv,Node* rv,int ns,int ne,int x,int sz,int bit){
		if(ns+1==ne) return ns;
		int mid = (ns+ne)/2;
		int xx = rv->right->val - lv->right->val;
		if(xx==sz) return bxor(lv->right,rv->right,mid,ne,x,sz,bit/2);
		else if(xx==0) return bxor(lv->left,rv->left,ns,mid,x,sz,bit/2);
		else{
			if((x&bit)==bit){
				return bxor(lv->left,rv->left,ns,mid,x,sz-xx,bit/2);
			}else{
				return bxor(lv->right,rv->right,mid,ne,x,xx,bit/2);
			}
		}
	}
};