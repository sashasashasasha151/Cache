#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <queue>

template<typename T>
class Cache {
private:
    int pr = 0;
    int min_time = 0;
    size_t size;
    std::list<std::pair<std::string,T>> elements;
    std::unordered_map<std::string, typename std::list<std::pair<std::string,T>>::iterator> keys;
public:
    explicit Cache(size_t n) {
        size = n;
    }

    ~Cache() = default;

    const T &Get(const std::string &key) {
        auto it = keys.find(key);
        if(key == elements.front().first) {
            return elements.begin()->second;
        }
        if (it != keys.end()) {
            elements.emplace_front(std::make_pair(key, it->second->second));
            elements.erase(it->second);
            it->second = elements.begin();
            return elements.begin()->second;
        } else {
            throw std::out_of_range("Out of range");
        }
    }

    void Put(const std::string &key, const T &value) {
        if (size == 0) {
            return;
        }
        if (elements.size() == size) {
            keys.erase(keys.find(elements.back().first));
            elements.pop_back();
        }
        elements.push_front({key,value});
        keys[key] = elements.begin();
    }

    void Put(const std::string &key, T &&value) {
        if (size == 0) {
            return;
        }
        if (elements.size() == size) {
            keys.erase(keys.find(elements.back().first));
            elements.pop_back();
        }
        elements.push_front({key,value});
        keys[key] = elements.begin();
    }
};


int main() {
    Cache<int> cache = Cache<int>(2);
    cache.Put("a", 1);
    cache.Put("b", 2);
    for (int i = 0; i < 10; ++i)
        std::cout << cache.Get("a") << std::endl;
    cache.Put("c", 3);
    try {
        std::cout << cache.Get("b");
    } catch (std::out_of_range) {
        std::cout << "Out of range";
    }
    return 0;
}