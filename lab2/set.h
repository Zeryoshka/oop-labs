#ifndef SET_H
#define SET_H

#define HASH_MAP_SIZE 1

template<typename T> int hash_function(const T& value);
template<typename T> unsigned char* serialise(const T& value);

template<typename T> struct Node {
    T value;
    Node<T>* next;
};

template<typename T> class Set {
public:
    Set();
    Set(const Set<T> &other);
    ~Set();

    Set(const std::string& file_path);
    void serialise(const std::string& file_path) const;

    void clear();
    int count() const;
    void add(const T& value);
    void remove(const T& value);

    Set<T>& operator<< (const T& value);
    Set<T>& operator>> (const T& value);
    Set<T> operator&& (const Set<T>& r_set) const;
    template<typename FT> friend bool operator== (const Set<FT> l_set, const Set<FT> r_set);
    template<typename FT> friend bool operator!= (const Set<FT> l_set, const Set<FT> r_set);
    bool operator[] (const T& value) const;

private:
    Node<T>* _hash_map[HASH_MAP_SIZE];
    int _count;
};

#include "set_source.h"
#endif
