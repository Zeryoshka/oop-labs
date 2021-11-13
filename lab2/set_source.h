#ifndef SET_SOURCE_H
#define SET_SOURCE_H

#include "set.h"
#include <fstream>
#include <exception>

template<typename T> int hash_function(const T& value) {
    unsigned char* bytes = (unsigned char*) ((void*) &value);
    int sum = 0;
    for (int i = 0; i < sizeof(T); ++i) {
        sum += bytes[i];
    }
    return sum % HASH_MAP_SIZE;
}


namespace utils {
    template<typename T> unsigned char* serialise(const T& value) {
        unsigned char* bytes = (unsigned char*) ((void*) &value);
        return bytes;
    }

    template<typename T> T deserialise(const unsigned char* bytes) {
        T* element = (T*) ((void*) bytes);
        return *element;
    }
}


template<typename T> Set<T>::Set() {
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        _hash_map[i] = nullptr;
    _count = 0;
}

template<typename T> Set<T>::~Set() {
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        if (_hash_map[i] != nullptr)
            delete _hash_map[i];
}

template<typename T> Set<T>::Set(const Set<T>& other) {
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        Node<T>* list = other._hash_map[i];
        if (list == nullptr) {
            _hash_map[i] = nullptr;
        } else {
            Node<T>* new_list = _hash_map[i] = new Node<T>{list->value, nullptr};
            list = list->next;
            while (list != nullptr) {
                new_list->next = new Node<T>{list->value, nullptr};
                new_list = new_list->next;
                list = list->next;
            }
        }
    }
    _count = other._count;
}

template<typename T> Set<T>::Set(const std::string& file_path) : Set() {
    std::ifstream f(file_path);
    if (!f)
        throw std::runtime_error("Couldn't open file");

    while (!f.eof()) {
        unsigned char* bytes = new unsigned char[sizeof(T)];
        for (int i = 0; i < sizeof(T); ++i) {
            bytes[i] = f.get();
        }
        *this << utils::deserialise<T>(bytes);
        f.get();
    }
    f.close();
}

template<typename T> void Set<T>::add(const T& value) {
    int hash = hash_function<T>(value);
    if (hash > HASH_MAP_SIZE)
        throw std::out_of_range("hass error");

    Node<T>* list = _hash_map[hash];
    if (list == nullptr) {
        _hash_map[hash] = new Node<T>{value, nullptr};
        ++_count;
        return;
    }
    if (list->next == nullptr) {
        if (list->value == value)
            return;
    }
    while (list->next != nullptr) {
        if (list->value == value)
            return;
        list = list->next;
    }
    list->next = new Node<T>{value, nullptr};
    ++_count;
}

template<typename T> void Set<T>::clear() {
    for (int i = 0; i < HASH_MAP_SIZE; ++i)
        if (_hash_map[i] != nullptr) {
            Node<T>* list = _hash_map[i];
            while (list != nullptr) {
                Node<T>* del_list = list;
                list = list->next;
                delete del_list;
            }
            _hash_map[i] = nullptr;
            i = i + 1 - 1;
        }
    _count = 0;
}

template<typename T> void Set<T>::remove(const T& value) {
    int hash = hash_function<T>(value);
    if (hash > HASH_MAP_SIZE)
        throw std::out_of_range("has error");

    if (_hash_map[hash] == nullptr) {
        throw std::invalid_argument("value not in set");
    }
    if (_hash_map[hash]->value == value) {
        Node<T>* to_del = _hash_map[hash];
        _hash_map[hash] = _hash_map[hash]->next;
        delete to_del;
        --_count;
        return;
    }
    Node<T>* node = _hash_map[hash]->next;
    Node<T>* prev_node = _hash_map[hash];
    while (node != nullptr) {
        if (node->value == value) {
            prev_node->next = node->next;
            delete node;
            --_count;
            return;
        }
        prev_node = node;
        node = node->next;
    }
    throw std::invalid_argument("value not in set");
}

template<typename T> int Set<T>::count() const {
    return _count;
}

template<typename T> bool Set<T>::operator[] (const T& value) const{
    int hash = hash_function<T>(value);
    if (hash > HASH_MAP_SIZE)
        throw std::out_of_range("hass error");
    Node<T>* list = _hash_map[hash];
    while (list != nullptr) {
        if (list->value == value)
            return true;
        list = list->next;
    }
    return false;
}

template<typename T> Set<T>& Set<T>::operator<< (const T& value) {
    add(value);
    return *this;
}

template<typename T> Set<T>& Set<T>::operator>> (const T& value) {
    remove(value);
    return *this;
}

template<typename T> bool operator== (const Set<T> l_set, const Set<T> r_set) {
    if (r_set.count() != r_set.count())
        return false;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        Node<T>* list = l_set._hash_map[i];
        while (list != nullptr) {
            if (!r_set[list->value]) {
                return false;
            }
            list = list->next;
        }
    }
    return true;
}

template<typename T> bool operator!= (const Set<T> l_set, const Set<T> r_set) {
    return !(l_set == r_set);
}

template<typename T> Set<T> Set<T>::operator&& (const Set<T>& r_set) const {
    Set<T> new_set;
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        Node<T>* list = _hash_map[i];
        while (list != nullptr) {
            if (r_set[list->value]) {
                new_set << list->value;
            }
            list = list->next;
        }
    }
    return new_set;
}

template<typename T> void Set<T>::serialise(
    const std::string& file_path
) const {
    std::ofstream f(file_path);
    if (!f)
        throw std::runtime_error("Couldn't open file");
    for (int i = 0; i < HASH_MAP_SIZE; ++i) {
        Node<T>* list = _hash_map[i];
        while (list != nullptr) {
            unsigned char* ptr = utils::serialise<T>(list->value);
            for (int i = 0; i < sizeof(T); ++i) {
                f << ptr[i];
            }
            list = list->next;
            if (list != nullptr)
                f << std::endl;
        }
    }
    f.close();
}

#endif
