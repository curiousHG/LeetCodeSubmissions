struct node{
    struct node *child[26];
    bool isend;
    
};
class Trie {
public:
    node* head;
    Trie() {
        head = new node();
    }
    void insert(string word) {
        node* cur = head;int k;
        for(int i= 0;i<word.length();i++){
            k = word[i]-'a';
            if(!cur->child[k]){
                cur->child[k] = new node();
            }
            cur = cur->child[k];
        }
        cur->isend=true;
    }
    
    bool search(string word) {
        node* cur = head;int k;
        for(int i= 0;i<word.size();i++){
            k= word[i]-'a';
            if(!cur->child[k])return false;
            cur = cur->child[k];
        }
        return cur->isend;
    }
    
    bool startsWith(string prefix) {
        node* cur = head;int k;
        for(int i= 0;i<prefix.size();i++){
            k= prefix[i]-'a';
            if(!cur->child[k])return false;
            cur = cur->child[k];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */