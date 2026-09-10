class Node{
public:
    int key;
    Node* prev, *next;
    Node(int key){
        this->prev = NULL;
        this->next = NULL;
        this->key = key;
    }
};
class LRUCache {
public:
    int capacity, curr_size;
    map<int,int>mp;
    map<int, Node*> node;
    Node* head, * tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        curr_size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if(node.find(key) != node.end()){
            access(node[key]);
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        mp[key] = value;
        if(node.find(key)!=node.end()){
            access(node[key]);
            return;
        }
        if(curr_size == capacity){
            Node * curr = head;
            head = head->next;
            if(head!=NULL){
                head->prev = NULL;
            }
            else{
                tail = NULL;
            }
            mp.erase(curr->key);
            node.erase(curr->key);
            delete curr;
            curr_size--;
        }
        Node * curr = new Node(key);
        mp[key] = value;
        node[key] = curr;
        if(head==NULL){
            head = curr;
            tail = curr;
        }    
        else{
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }
        curr_size++;
    }

    void access(Node* currN){
        if (currN == tail) {
            return;
        }
        Node* prevN,* nextN;
            prevN = currN->prev;
            nextN = currN->next;
            
            if(prevN!= NULL){
                prevN -> next = nextN;
            }
            if(nextN){
                nextN->prev = prevN;
            }

            if(currN==head){
                head = nextN;
            }
            currN->prev = tail;
            currN->next = NULL;

            tail->next = currN;
            tail = currN;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */