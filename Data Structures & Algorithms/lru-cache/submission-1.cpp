class LRUCache {
public:
    class Node{
        public:
            Node* prev;
            Node* next;
            int key, val;
            Node(int k, int v){
                prev = nullptr;
                next = nullptr;
                key = k;
                val = v;
            }
    };
    unordered_map<int, Node*> mp;
    int capacity;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* node){
        Node* temp = head->next;
        node->prev = head;
        node->next = temp;
        head->next = node;
        temp->prev = node;
    }
    void deleteNode(Node* node){
        Node* n1 = node->prev;
        Node* n2 = node->next;

        n1->next = n2;
        n2->prev = n1;
    }
    int get(int key) {
        if(!mp.count(key)) return -1;

        Node* node = mp[key];
        int val = node->val;

        deleteNode(node);
        addNode(node);

        return val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            deleteNode(node);
            mp.erase(key);
        }
        if(mp.size() == capacity){
            Node* LRU = tail->prev;
            deleteNode(LRU);
            mp.erase(LRU->key);
        }

        Node* node = new Node(key, value);
        addNode(node);
        mp[key] = node;
    }
};
