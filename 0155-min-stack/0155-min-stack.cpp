class MinStack {
public:
    typedef struct node{
        int v;
        int minUntilNow;
        node* next;
    }node;

    MinStack() : topN(nullptr){
        
    }
    
    void push(int val) {
        node* n = new node;
        n->v = n->minUntilNow = val;
        n->next = nullptr;
        
        if(topN == nullptr){
            topN = n;
        }

        else{
            n->minUntilNow = min(n->v,topN->minUntilNow);
            n->next = topN;
            topN = n;
        }
    }
    
    void pop() {
        topN = topN->next;
    }
    
    int top() {
        return topN->v;
    }
    
    int getMin() {
        return topN->minUntilNow;
    }

    private:
    node* topN;
};