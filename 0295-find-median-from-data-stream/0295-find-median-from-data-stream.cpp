class MedianFinder {
public:
    priority_queue<int>pq;
    priority_queue<int, vector<int>, greater<int>>rpq;
    int n;
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(pq.size()==0 || num<=pq.top()){
            if(pq.size() <= rpq.size()){
                pq.push(num);
            }
            else{
                rpq.push(pq.top());
                pq.pop();
                pq.push(num);
            }
        }
        else{
            if(rpq.size()<pq.size()){
                rpq.push(num);
            }
            else{
                int a = rpq.top();
                pq.push(min(a,num));
                rpq.pop();
                rpq.push(max(a,num));
            }
        }
    }
    
    double findMedian() {
        if((pq.size() + rpq.size())%2==0){
            cout<<pq.top()<<" "<<rpq.top()<<endl;
            return (1.00*(pq.top()+rpq.top()))/2.00;
        }
        cout<<pq.top()<<endl;
        return (1.00 *pq.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */