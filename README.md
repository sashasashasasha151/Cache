# LFU cache
Simple realization of LFU cache with O(1) time complexity for all operations
### Cache semantics
```c++
template<typename T>
class Cache {
    Cache(size_t n)

    const T &Get(const std::string &key) 

    void Put(const std::string &key, const T &value) 

    void Put(const std::string &key, T &&value)
}
```