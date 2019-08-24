#include <list>
#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int cap;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }

    int get(int key) {
        auto it = map.find(key);
        if (it == map.end())
            return -1;
        auto kv = *map[key];
        cache.erase(map[key]);
        cache.push_front(kv);
        map[key] = cache.begin();
        return kv.second;
    }

    void put(int key, int value) {
        auto it = map.find(key);
        if (it == map.end()) {
            if (cache.size() == cap) {
                auto last = cache.back();
                map.erase(last.first);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
        else {
            cache.erase(map[key]);
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        }
    }
};