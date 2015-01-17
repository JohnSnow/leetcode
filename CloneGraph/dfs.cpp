#include <vector>
#include <iostream>
#include <unordered_map>

using std::vector;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode*> hm;
        return dfs(node, hm);
    }

    UndirectedGraphNode* dfs(UndirectedGraphNode *node, std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode*>  &hm) {
        if(hm.find(node) != hm.end()) {
            return hm[node];
        }

        UndirectedGraphNode *copyNode = new UndirectedGraphNode(node->label);
        hm[node] = copyNode;
        for(unsigned i=0; i<node->neighbors.size(); i++) {
            copyNode->neighbors.push_back(dfs(node->neighbors[i], hm));
        }
        return copyNode;
    }
};
