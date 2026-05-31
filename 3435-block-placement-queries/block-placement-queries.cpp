class Solution {
public:
    vector<int>seg;
    int n=50005;
    void construct(){
        seg.resize(4*n,0);
    }
    void updateSeg(int idx,int val,int i,int l,int r){
        if(l==r){
            seg[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            updateSeg(idx,val,2*i+1,l,mid);
        }
        else{
            updateSeg(idx,val,2*i+2,mid+1,r);
        }
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
    }

    int querySeg(int start,int end,int i,int l,int r){
        if(l>end || r<start) return 0;
        if(l>=start && r<=end) return seg[i];
        int mid=l+(r-l)/2;
        return max(querySeg(start,end,2*i+1,l,mid),querySeg(start,end,2*i+2,mid+1,r));
    }
    vector<bool> getResults(vector<vector<int>>& queries) {
        construct();
        set<int>st;
        st.insert(0);
        vector<bool>result;
        for(auto q : queries){
            if(q[0]==1){
                // add obstacle
                int x=q[1];
                auto it=st.upper_bound(x);
                if (it != st.end()) {
                    int next = *it;
                    updateSeg(next,next-x,0,0,n-1);
                 }       
                int pre=*prev(it);
                updateSeg(x,x-pre,0,0,n-1);
                st.insert(x);
            }
            else{
                int x=q[1];
                int sz=q[2];
                auto it =st.upper_bound(x);
                int pre=*prev(it);
                int maxGap=querySeg(0,pre,0,0,n-1);
                int best=max(maxGap,x-pre);
                result.push_back(best>=sz);
            }
        }
        return result;
    }
};