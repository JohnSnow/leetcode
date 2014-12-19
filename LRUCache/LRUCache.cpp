#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

// Old implementation, use stl. kind of slow
/*class LRUCache{*/
//public:
    //LRUCache(int capacity):cap(capacity),cnt(0) {
    //}

    //int get(int key) {
        //std::list<std::pair<int, int> >::iterator _lru_it;
        //map<int, std::list< std::pair<int, int> >::iterator >::iterator _cache_it;
        //_cache_it = _cache.find(key);
        //if (_cache_it == _cache.end()) {
            //return -1;
        //} else {
            //_lru_it = _cache_it->second;
            //update_exist_lru(_lru_it);
            //_cache[key] = _lru.begin();
            //return _lru.front().second;
        //}
    //}

    //void set(int key, int value) {

        //bool full = false;
        //std::list<std::pair<int, int> >::iterator _lru_it;
        //map<int, std::list<std::pair<int, int> >::iterator >::iterator _cache_it;
        //_cache_it = _cache.find(key);

        //if (_cache_it != _cache.end()) {
            //_lru_it = _cache_it->second;
            //update_exist_lru(_lru_it, value);
            //_cache[key] = _lru.begin();

        //} else {
            //if (cnt == cap) {
                //_cache.erase(_lru.back().first);
                //cnt--;
                //full = true;
            //}
            //cnt++;
            //update_new_lru(std::pair<int, int> (key, value), full);
            //_cache[key] = _lru.begin();
        //}
    //}

    //void update_exist_lru(std::list<std::pair<int, int> >::iterator it)
    //{
        //int key = (*it).first;
        //int value = (*it).second;
        //_lru.erase(it);
        //_lru.push_front(std::pair<int, int> (key, value));
    //}

    //void update_exist_lru(std::list<std::pair<int, int> >::iterator it, int value)
    //{
        //int key = (*it).first;
        //_lru.erase(it);
        //_lru.push_front(std::pair<int, int> (key, value));
    //}

    //void update_new_lru(std::pair<int, int> kp, bool full)
    //{
        //if(full) {
            //_lru.pop_back();
        //}
        //_lru.push_front(kp);
    //}

//private:
    //size_t cap;
    //size_t cnt;

    //map<int, std::list<std::pair<int, int> >::iterator > _cache;

    //std::list<std::pair<int, int> > _lru;
/*};*/


class Node
{
public:
    int  _key;
    int  _value;

    Node *_prev;
    Node *_next;
};

class DList
{
public:
    DList() {
        _head = new Node();
        _tail = new Node();
        _head->_prev = NULL;
        _head->_next = _tail;
        _tail->_prev = _head;
        _tail->_next = NULL;
    }

    ~DList()
    {
        delete _head;
        delete _tail;
    }

    void insertFront(Node *node) {
        node->_prev =_head;
        node->_next = _head->_next;
        _head->_next->_prev = node;
        _head->_next = node;
    }

    void detach(Node *node) {
        node->_next->_prev = node->_prev;
        node->_prev->_next = node->_next;
    }

    Node *pop_back() {
        Node *last = _tail->_prev;
        detach(last);
        return last;
    }

    bool isEmpty() {
        return _head->_next == _tail;
    }

private:
    Node  *_head;
    Node  *_tail;
};

class LRUCache
{
public:
    LRUCache (int capability)
    {
        _list = new DList();
        _entries = new Node[capability];
        for (int i=0; i< capability; i++) {
            _free_container.push_back(_entries+i);
        }
    }

    ~LRUCache()
    {
        delete _list;
        delete[] _entries;
    }

    int get(int key)
    {
        Node *node = _map[key];
        if(node) {
            _list->detach(node);
            _list->insertFront(node);
            return node->_value;
        }
        else
        {
            return -1;
        }
    }

    void set(int key, int value)
    {
        Node *node = _map[key];
        if(node) {
            _list->detach(node);
            node->_value = value;
            _list->insertFront(node);
        }
        else
        {
            if(_free_container.empty()) {
                node = _list->pop_back();
                _map.erase(node->_key);
            }
            else
            {
                node = _free_container.back();
                _free_container.pop_back();
            }
            node->_key = key;
            node->_value = value;
            _list->insertFront(node);
            _map[key] = node;
        }
    }

private:

    std::vector<Node *> _free_container;
    std::unordered_map<int, Node* > _map;
    DList *_list;
    Node *_entries;

};



int main(int argc, const char *argv[])
{
    LRUCache * cache = new LRUCache(1);
    cache->set(2,1);
    std::cout << cache->get(1) << std::endl;
    cache->set(2,2);
    std::cout << cache->get(2)  << std::endl;
    cache->set(3,1);
    std::cout << cache->get(2) << std::endl;
    cache->set(4,2);
    std::cout << cache->get(4) << std::endl;
    return 0;
}

