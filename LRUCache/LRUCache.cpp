#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <utility>

using std::map;

class LRUCache{
public:
    LRUCache(int capacity):cap(capacity),cnt(0) {
    }

    int get(int key) {
        std::list<std::pair<int, int> >::iterator _lru_it;
        map<int, std::list< std::pair<int, int> >::iterator >::iterator _cache_it;
        _cache_it = _cache.find(key);
        if (_cache_it == _cache.end()) {
            return -1;
        } else {
            _lru_it = _cache_it->second;
            update_exist_lru(_lru_it);
            _cache[key] = _lru.begin();
            return _lru.front().second;
        }
    }

    void set(int key, int value) {

        bool full = false;
        std::list<std::pair<int, int> >::iterator _lru_it;
        map<int, std::list<std::pair<int, int> >::iterator >::iterator _cache_it;
        _cache_it = _cache.find(key);

        if (_cache_it != _cache.end()) {
            _lru_it = _cache_it->second;
            update_exist_lru(_lru_it, value);
            _cache[key] = _lru.begin();

        } else {
            if (cnt == cap) {
                _cache.erase(_lru.back().first);
                cnt--;
                full = true;
            }
            cnt++;
            update_new_lru(std::pair<int, int> (key, value), full);
            _cache[key] = _lru.begin();
        }
    }

    void update_exist_lru(std::list<std::pair<int, int> >::iterator it)
    {
        int key = (*it).first;
        int value = (*it).second;
        _lru.erase(it);
        _lru.push_front(std::pair<int, int> (key, value));
    }

    void update_exist_lru(std::list<std::pair<int, int> >::iterator it, int value)
    {
        int key = (*it).first;
        _lru.erase(it);
        _lru.push_front(std::pair<int, int> (key, value));
    }

    void update_new_lru(std::pair<int, int> kp, bool full)
    {
        if(full) {
            _lru.pop_back();
        }
        _lru.push_front(kp);
    }

    void printElem() {
        std::cout << "==========================" << std::endl;
        for (std::list<std::pair<int, int> >::iterator it =  _lru.begin(); it != _lru.end(); it++) {
            std::cout << (*it).first << "-> " << (*it).second  << " " << std::endl;
        }
        std::cout << "*************************" << std::endl;
    }

private:
    size_t cap;
    size_t cnt;

    map<int, std::list<std::pair<int, int> >::iterator > _cache;

    std::list<std::pair<int, int> > _lru;
};


int main(int argc, const char *argv[])
{
    LRUCache *cache = new LRUCache(1);
    cache->set(2, 1);
    std::cout <<  cache->get(2) << std::endl;
    cache->set(3,2);
    std::cout <<  cache->get(2) << std::endl;
    std::cout <<  cache->get(3) << std::endl;


    return 0;
}

