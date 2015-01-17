#include <vector>
#include <deque>
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

        if(node == NULL) return NULL;

        std::deque<UndirectedGraphNode *> _nodeQ ;
        std::unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> _hashmap;


        _nodeQ.push_back(node);
        UndirectedGraphNode *copyNode = new UndirectedGraphNode(node->label);
        _hashmap[node] = copyNode;

        UndirectedGraphNode *cur = NULL;
        while(!_nodeQ.empty()) {
            cur = _nodeQ.front();
            _nodeQ.pop_front();

            int n = cur->neighbors.size();

            for(int i=0; i<n; i++) {
                UndirectedGraphNode *neighbor = cur->neighbors[i];
                if(_hashmap.find(cur->neighbors[i]) == _hashmap.end()) {
                    UndirectedGraphNode *new_copy = new UndirectedGraphNode(neighbor->label);
                    _hashmap[neighbor] = new_copy;
                    _hashmap[cur]->neighbors.push_back(new_copy);
                    _nodeQ.push_back(neighbor);
                } else {
                    _hashmap[cur]->neighbors.push_back(_hashmap[neighbor]);
                }
            }
        }
        return copyNode;
    }
};
