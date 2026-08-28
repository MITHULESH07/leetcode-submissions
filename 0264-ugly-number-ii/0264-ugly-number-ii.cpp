class Solution {
public:
    int nthUglyNumber(int n) {
       priority_queue<long long,vector<long long>,greater<long long>>pq;
       set<long long>st;
       pq.push(1);
       for(int i = 1;i<n;i++){
        long long x = pq.top();
        pq.pop();
        if(!st.count(x*2)){
            st.insert(x*2);
            pq.push(x*2);
        }
        if(!st.count(x*3)){
            st.insert(x*3);
            pq.push(x*3);
        }
        if(!st.count(x*5)){
            st.insert(x*5);
            pq.push(x*5);
        }
       }
       return pq.top(); 
    }
};