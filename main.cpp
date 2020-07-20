    //
// Created by zyl on 2020/1/13.
//
#include "algorithms_data_structures.h"
#include "objects_oriented.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution solution;

    int value = 0;
    LRUCache* cache = new LRUCache(2);
//    cache->put(1, 1);
    cache->put(2, 1);
    cache->put(2, 2);
    value = cache->get(2);
    cache->put(3, 3);
    value = cache->get(2);
    cache->put(4, 4);
    value = cache->get(1);
    value = cache->get(3);
    value = cache->get(4);


    return 0;
}
