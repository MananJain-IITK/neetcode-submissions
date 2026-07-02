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
    unordered_map<int, Node*> address;
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        Node* root = new Node(node->val);
        address[node->val] = root;
        for(auto ptr: node->neighbors){
            if(address.contains(ptr->val)) root->neighbors.push_back(address[ptr->val]);
            else{
                // Node* temp = new Node(ptr->val);
                root->neighbors.push_back(cloneGraph(ptr));
                // address[ptr->val] = temp;
            }
        }
        return root;
    }
};
