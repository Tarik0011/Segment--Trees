/*
*   -------------- ?*?*? --------------
* |         In The Name of *Allah*     |
* |             Author : Tarik         |
* |                                    |
*  -------------- ?*?*? ---------------
*/
 
#include<bits/stdc++.h>
using namespace std;
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define  int       long long
 
const int mxn=2e5+123;
int a[mxn];
 
class St{
public:	vector<int>seg,lazy;
public:
	St(int n){
		seg.resize(4*n+1);
		lazy.resize(4*n+1);
	}
	void push_down(int node,int s,int e){
		int dx=lazy[node];
		lazy[node]=0;
		seg[node]+=dx*(e-s+1);
		if(s!=e){
			lazy[2*node]+=dx;
			lazy[2*node+1]+=dx;
		}
	}
	void build(int node,int s,int e){
		if(s==e){
			seg[node]=a[s];
			return;
		}
		int mid=(s+e)>>1;
		int left=node*2;
		int right=node*2+1;
		build(left,s,mid);
		build(right,mid+1,e);
		seg[node]=seg[left]+seg[right];
	}
	int query(int node,int s,int e,int l,int r){
		if(lazy[node]!=0){
			push_down(node,s,e);
		}
		if(r<s || e<l)return 0;
		if(l<=s and e<=r)return seg[node];
		int mid=(s+e)>>1;
		int left=node*2;
		int right=node*2+1;
		int p1=query(left,s,mid,l,r);
		int p2=query(right,mid+1,e,l,r);
		return p1+p2;
	}
	void update(int node,int s,int e,int qs,int qe,int val){
		if(lazy[node]!=0){
			push_down(node,s,e);	
		}
		if(s>qe || e<qs)return;
		if(s>=qs and e<=qe){
			seg[node]+=(e-s+1)*val;
			if(s!=e){
				lazy[2*node]+=val;
				lazy[2*node+1]+=val;
			}
			return;
		}
		int mid=(s+e)>>1;
		int left=node*2;
		int right=node*2+1;
		update(left,s,mid,qs,qe,val);
		update(right,mid+1,e,qs,qe,val);
		seg[node]=seg[left]+seg[right];
	}
};
void solve(){
	 int n,q;
	 cin>>n>>q;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	 St s(n);
	 s.build(1,1,n);
	 while(q--){
	 	int t;cin>>t;
	 	if(t==2){
	 		int l,r;
	 		cin>>l>>r;
	 		cout<<s.query(1,1,n,l,r)<<endl;
	 	}else{
	 		int l,r,val;
	 		cin>>l>>r>>val;
	 		s.update(1,1,n,l,r,val);
	 	}
	 }
	 
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
