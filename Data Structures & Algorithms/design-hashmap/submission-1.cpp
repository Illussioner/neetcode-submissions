class MyHashMap {
private:
    struct ListNode{
        int key,val;
        ListNode* next;
        ListNode(int key=-1, int val = -1, ListNode* next
        = nullptr) : key(key), val(val), next(next) {}
    };
    vector<ListNode*> map;
    int hash(int key) {
        return key % map.size();
    }
public:
    MyHashMap(): map(10000) {
        for(auto& bucket : map){
            bucket = new ListNode();
        }
    }
    
    void put(int key, int value) {
        ListNode* cur = map[hash(key)];
        while(cur->next){
            if(cur->next->key==key){
                cur->next->val = value;
                return;
            }
            cur = cur->next;
        }
        cur->next = new ListNode(key,value);
    }
    
    int get(int key) {
        ListNode* cur = map[hash(key)]->next;
        while(cur){
            if(cur->key==key){
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int key) {
        ListNode* curr = map[hash(key)];
        while(curr->next){
            if(curr->next->key==key){
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */