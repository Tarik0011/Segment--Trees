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
#define  pb       push_back
const int mxn=2e5+123;
int a[mxn];
 
class St{
public:	vector<vector<int>>seg;
public:
	St(int n){
		seg.resize(4*n+1);
	}
	void build(int node,int s,int e){
		if(s==e){
			seg[node].pb(a[s]);
			return;
		}
		int mid=(s+e)>>1;
		int left=node*2;
		int right=node*2+1;
		build(left,s,mid);
		build(right,mid+1,e);

		int i=0,j=0,szl=seg[node*2].size();
	    int szr=seg[node*2+1].size();
	    while(i<szl && j<szr){
	        if(seg[node*2][i]<seg[node*2+1][j]) seg[node].pb(seg[node*2][i++]);
	        else seg[node].pb(seg[node*2+1][j++]);
	    }
	    while(i<szl) seg[node].pb(seg[node*2][i++]);
	    while(j<szr) seg[node].pb(seg[node*2+1][j++]);

	}
	
	int query(int node,int s,int e,int l,int r,int k){
		if(r<s || e<l)return 0;
		if(l<=s and e<=r){
			int res=upper_bound(seg[node].begin(),seg[node].end(),k)-seg[node].begin();
	        int x=seg[node].size()-res;
	        return x;
		}
		int mid=(s+e)>>1;
		int left=node*2;
		int right=node*2+1;
		int p1=query(left,s,mid,l,r,k);
		int p2=query(right,mid+1,e,l,r,k);
		return p1+p2;
	}
};
void solve(){
	 int n,q;
	 cin>>n;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	 St s(n);
	 s.build(1,1,n);
	 cin>>q;
	 while(q--){
	 	int u,v,k;
		cin>>u>>v>>k;
		int ans=s.query(1,1,n,u,v,k);
		cout<<ans<<endl;
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
