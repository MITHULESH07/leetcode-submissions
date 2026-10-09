class NumArray {
public:
    int n;
    vector<int>t;
    vector<int>nums_copy;
    NumArray(vector<int>& nums) {
        n = nums.size();
        t.resize(n+1,0);
        nums_copy = nums;
        for(int i = 0; i < n;i++){
            add(i,nums[i]);
        }
    }

    void add(int index, int val){
        for(int i = index+1; i <= n;i+=(i&(-i))){
            t[i]+=val;
        }
    }
    
    void update(int index, int val) {
        int delta = val-nums_copy[index];
        nums_copy[index] = val;
        add(index,delta);
    }
    int query(int i){
        int sum = 0;
        for(i++; i > 0; i -= (i&(-i))){
            sum += t[i];
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return query(right);
        }
        else{
            return query(right) - query(left-1);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */