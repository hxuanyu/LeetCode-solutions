// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LFUCache cache = new LFUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.get(3);       // returns 3.
// cache.put(4, 4);    // evicts key 1.
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4
class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }

    void updateCountmap(int key) {
        auto count = cmap[key].first;
        auto iter = cmap[key].second;
        countmap[count].erase(iter);
        if (countmap[count].empty()) countmap.erase(count);

        countmap[count + 1].push_back(key);
        iter = countmap[count + 1].end();
        iter--;
        cmap[key] = make_pair(count + 1, iter);
    }

    int get(int key) {
        if (cap == 0) return -1;
        if (vmap.count(key) == 0) return -1;

        int val = vmap[key];
        updateCountmap(key);
        return val;
    }

    void put(int key, int value) {
        if (cap == 0) return;
        if (vmap.count(key)) {
            updateCountmap(key);
            vmap[key] = value;
        } else {
            if (cap == vmap.size()) { // if full
                auto iter = countmap.begin();
                auto count = iter->first;
                auto key = iter->second.front();
                iter->second.pop_front();
                if (iter->second.empty()) countmap.erase(count);
                cmap.erase(key);
                vmap.erase(key);
            }
            vmap[key] = value;
            countmap[1].push_back(key);
            auto iter = countmap[1].end();
            iter--;
            cmap[key] = make_pair(1, iter);
        }
    }

    map<int, int> vmap; // key - value
    map<int, pair<int, list<int>::iterator>> cmap; // key - count, iter
    map<int, list<int>> countmap; // count - keys;
    int cap;
};
