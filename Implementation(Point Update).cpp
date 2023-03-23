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
public:	vector<int>seg;
public:
	St(int n){
		seg.resize(4*n+1);
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
		if(r<s || e<l)return 0;
		if(l<=s and e<=r)return seg[node];
		int mid=(s+e)>>1;
		int left=node*2;
		int right=node*2+1;
		int p1=query(left,s,mid,l,r);
		int p2=query(right,mid+1,e,l,r);
		return p1+p2;
	}
	void update(int node,int s,int e,int idx,int val){
		if(idx>e || idx<s)return;
		if(s>=idx and e<=idx){
			seg[node]=val;
			return;
		}
		int mid=(s+e)>>1;
		int left=node*2;
		int right=node*2+1;
		update(left,s,mid,idx,val);
		update(right,mid+1,e,idx,val);
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
	 //for(int i=1;i<=n;i++)cout<<s.seg[i]<<" ";
	 //cout<<endl;
	 while(q--){
	 	int t;cin>>t;
	 	if(t==2){
	 		int l,r;
	 		cin>>l>>r;
	 		cout<<s.query(1,1,n,l,r)<<endl;
	 	}else{
	 		int idx,val;
	 		cin>>idx>>val;
	 		s.update(1,1,n,idx,val);
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
