#include <iostream>
#include <algorithm>
#include <map>

using std::map;
using std::min_element;

class LRUCache{
public:
    LRUCache(int capacity):cap(capacity),cnt(0) {
    }

    int get(int key) {
        _cache_it = _cache.find(key);
        if (_cache_it == _cache.end()) {
            return -1;
        } else {
            return _cache_it->second;
            _freq[_cache_it->first] += 1;
        }
    }

    void set(int key, int value) {

        map<int, int>::iterator _freq_it;

        _cache_it = _cache.find(key);
        if (_cache_it != _cache.end()) {
            _cache_it->second = value;
            _freq[_cache_it->first] += 1;
        } else {
            if (cnt == cap) {
                _freq_it = min_element(_freq.begin(), _freq.end(), LessBySecond);
                _cache.erase(_freq_it->first);
                cnt--;
            }
            _cache[key] = value;
            _freq[key] = 1;
            cnt++;
        }
    }

    void printElem() {
        for (map<int, int>::iterator it =  _cache.begin(); it != _cache.end(); it++) {
            std::cout << it->second  << " " << std::endl;
        }
    }

    template <typename Lhs, typename Rhs>
    bool LessBySecond(const Lhs &lhs, const Rhs &rhs)
    {
        return lhs.second < rhs.second;
    };

private:
    size_t cap;
    size_t cnt;

    map<int, int> _cache;
    map<int, int> _freq;
    map<int, int>::iterator _cache_it;

};

int main(int argc, const char *argv[])
{
    LRUCache *cache = new LRUCache(2);
    cache->set(1, 10);
    cache->set(2,5);
    cache->get(1);
    cache->printElem();
    cache->set(3,3);
    cache->printElem();


    return 0;
}

