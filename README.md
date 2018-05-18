```
template<typename T>
class Cache {
    Cache(size_t n)

    const T &Get(const std::string &key) 

    void Put(const std::string &key, const T &value) 

    void Put(const std::string &key, T &&value)
}
```