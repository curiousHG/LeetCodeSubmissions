class NumArray {
public:
    vector<int> tree;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        build(1, nums, 0, n-1);
        // for(int i= 0;i<4*n;i++)cout<<tree[i]<<" ";
        
        
    }
    void build(int v,vector<int> &nums, int tl,  int tr){
        if(tl==tr){
            tree[v] = nums[tl];
            return;
        }
        int tm = (tl+tr)/2;
        build(2*v,nums, tl, tm);
        build(2*v+1,nums, tm+1, tr);
        tree[v] = tree[2*v] + tree[2*v+1];
    }
    void up(int v, int tl, int tr,int val, int ind){
        if(tl==tr){
            tree[v] = val;
            return;
        }
        int tm = (tl+tr)/2;
        if(tm>=ind){
            up(2*v, tl, tm, val, ind);
        }else{
            up(2*v+1, tm+1, tr, val, ind);
        }
        tree[v] = tree[2*v]+tree[2*v+1];
    }
    int query(int v, int tl, int tr, int l, int r){
        if(l>r)return 0;
        if(tl==l && tr==r)return tree[v];
        int tm = (tl+tr)/2;
        return query(2*v, tl, tm, l, min(r, tm))+query(2*v+1, tm+1, tr, max(l, tm+1), r);
    }
    void update(int index, int val) {
        up(1, 0, n-1, val, index);
    }
    
    int sumRange(int left, int right) {
        return query(1,0,n-1,left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */