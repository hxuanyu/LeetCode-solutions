// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        if (vmap.count(key) == 0) return -1; // not found
        int val = vmap[key].first;
        updateexisting(key, val);
        return val;
    }

    void updateexisting(int key, int val) {
        list_.erase(vmap[key].second);
        insertnew(key, val);
    }

    void insertnew(int key, int val) {
        list_.push_back(key);
        list<int>::iterator iter = list_.end();
        --iter;
        vmap[key] = make_pair(val, iter);
    }

    void put(int key, int value) {
        if (vmap.count(key)) { // if existing
            updateexisting(key, value);
        } else { // if not existing
            if (cap == vmap.size()) {// if full, remove front
                int keytoremove = *(list_.begin());
                list_.erase(list_.begin());
                vmap.erase(keytoremove);
            }
            insertnew(key, value);
        }
    }

    list<int> list_;
    map<int, pair<int, list<int>::iterator>> vmap;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
