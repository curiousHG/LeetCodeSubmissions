/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        if(node==NULL)return NULL;
        q.push(node);
        unordered_map<int, Node*> mp;
        while(!q.empty()){
            
            Node* temp = q.front();
            int v = temp->val;
            // cout<<v<<endl;
            if(mp.find(v)==mp.end()){
                mp[v] = new Node(v);
            }
            q.pop();
            for(auto next:temp->neighbors){
                int v2 = next->val;
                if(mp.find(v2)==mp.end()){
                    mp[v2] = new Node(v2);
                    q.push(next);
                }
                mp[v]->neighbors.push_back(mp[v2]);
            }
            
        }
        // for(auto &k:mp){
        //     cout<<k.first<<" ";
        // }
        return mp[node->val];
        
    }
};