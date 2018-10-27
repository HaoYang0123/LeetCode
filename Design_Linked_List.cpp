//Leetcode 707
//自己写一个LinkedList，容易出错。
//有比较多的边界条件需要判断。

class MyNode {
public:
    int val;
    //MyNode* prev;
    MyNode* next;
    
public:
    MyNode(int v) {
        this->val=v;
        //prev=NULL;
        next=NULL;
    }    
};

class MyLinkedList {
public:
    MyNode* root;
    MyNode* tail;
    int count;
    /** Initialize your data structure here. */
    MyLinkedList() {
        root = NULL;
        tail = NULL;
        count = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= count) return -1;
        if(index == 0) return root->val;
        MyNode* cur = root;
        while(index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        ++count;
        MyNode* c = new MyNode(val);
        c->next = root;
        root = c;
        if(tail == NULL) tail = c;
        //write_log("Add head");
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ++count;
        MyNode* c = new MyNode(val);
        if(tail == NULL) {
            root = c;
            tail = c;
        }
        else {
            tail->next = c;
            tail = c;
        }
        //if(!write_log("Add tail"))
        //    cout<<"LLLL\t"<<tail->val<<endl;;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index == 0) {
            addAtHead(val);
        }
        else if(index < 0 || index > count) return;
        else if(index == count) {
            addAtTail(val);
        }
        else {
            ++count;
            MyNode* cur = root, * prev = root;
            int ori_index = index;
            while(index--) {
                prev = cur;
                cur = cur->next;
            }
            MyNode* c = new MyNode(val);
            prev->next = c;
            c->next = cur;
        }
        //write_log("Add index");
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= count) return;
        if(count==1) {
            root = NULL;
            tail = NULL;
        }
        else {
            if(index==0) root = root->next; 
            else {
                MyNode* cur = root, * prev = root;
                while(index--) {
                    prev = cur;
                    cur = cur->next;
                }
                prev->next = cur->next;
                if(prev->next == NULL) tail = prev;
            }
        }
        --count;
        //write_log("Delete");
    }
    
    bool write_log(const string & log) {
        cout<<log<<"\t"<<count<<endl;
        MyNode* ll = root;
        int l = 0;
        while(ll!=NULL) {
            cout<<ll->val<<"\t";
            ll=ll->next;
            ++l;
        }
        cout<<endl;
        if(count!=l) {
            cout<<"Size not same\t"<<count<<"\t"<<l<<endl;
            return false;
        }
        return true;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */
