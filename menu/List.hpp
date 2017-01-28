//
//  List.hpp
//  menu
//
//  Created by Filip Peterek on 26/01/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cstdarg>

class out_of_range {
    
    char * message;
    
public:
    
    out_of_range(const char * newMessage);
    ~out_of_range();
    const char * what() const throw();
    
};

template <typename T>
struct list_node {
    
    T value;
    list_node<T> * next_node;
    list_node<T> * previous_node;
    
    list_node() {
        
        next_node = nullptr;
        previous_node = nullptr;
        
    }
    
    list_node(const T & newValue, list_node * next = nullptr, list_node * previous = nullptr) {
        
        value         = newValue;
        next_node     = next;
        previous_node = previous;
        
    }
    
};

template <typename T>
class list {
    
    list_node<T> * first_node;
    list_node<T> * last_node;
    size_t list_size;
    
    list_node<T> * node_at_index(size_t index) {
        
        if (index >= list_size or first_node == nullptr) {
            throw out_of_range("Attempting to access element outside memory bounds");
        }
        
        list_node<T> * ptr;
        
        if (index > list_size / 2) {
            
            ptr = last_node;
            
            for (size_t counter = list_size - 1; counter > index; --counter) {
                ptr = ptr -> previous_node;
            }
            
        } else {
            
            ptr = first_node;
            
            for (size_t counter = 0; counter < index; ++counter) {
                ptr = ptr -> next_node;
            }
            
        }
        
        return ptr;
        
    }
    
public:
    
    static const size_t npos = -1;
    
    list() {
        list_size  = 0;
        first_node = nullptr;
        last_node  = nullptr;
    }
    
    list(const list<T> & orig) {
        
        for (size_t i = 0; i < orig.length(); ++i) {
            
            push_back(orig[i]);
            
        }
        
    }
    
    list(size_t count, ...) {
        
        list_size  = 0;
        first_node = nullptr;
        last_node  = nullptr;
        
        va_list args;
        va_start(args, count);
        
        for (int i = 0; i < count; ++i) {
            
            T new_val = va_arg(args, T);
            push_back(new_val);
            
        }
        
        va_end(args);
        
    }
    
    ~list() {
        
        for (size_t i = list_size; i > 0; --i) {
            remove_last();
        }
        
    }
    
    size_t length() const {
        return list_size;
    }
    size_t size() const {
        return list_size;
    }
    
    T & first() {
        
        if (first_node == nullptr) {
            throw out_of_range("Attempting to access element outside memory bounds");
        }
        return first_node -> value;
        
    }
    
    T & last() {
        
        if (first_node == nullptr) {
            throw out_of_range("Attempting to access element outside memory bounds");
        }
        return last_node -> value;
        
    }
    
    const T & first() const {
        
        if (first_node == nullptr) {
            throw out_of_range("Attempting to access element outside memory bounds");
        }
        return first_node -> value;
        
    }
    
    const T & last() const {
        
        if (first_node == nullptr) {
            throw out_of_range("Attempting to access element outside memory bounds");
        }
        return last_node -> value;
        
    }

    
    T & at(size_t index) {
        
        if (index >= list_size or first_node == nullptr) {
            throw out_of_range("Attempting to access element outside memory bounds");
        }
        
        list_node<T> * ptr;
        
        if (index > list_size / 2) {
            
            ptr = last_node;
            
            for (size_t counter = list_size - 1; counter > index; --counter) {
                ptr = ptr -> previous_node;
            }
        
        } else {
            
            ptr = first_node;
            
            for (size_t counter = 0; counter < index; ++counter) {
                ptr = ptr -> next_node;
            }
            
        }
        
        return ptr -> value;
        
    }
    
    T & operator[](size_t index) {
        return at(index);
    }
    
    const T & at(size_t index) const {
        
        if (index >= list_size or first_node == nullptr) {
            throw out_of_range("Attempting to access element outside memory bounds");
        }
        
        list_node<T> * ptr;
        
        if (index > list_size / 2) {
            
            ptr = last_node;
            
            for (size_t counter = list_size - 1; counter > index; --counter) {
                ptr = ptr -> previous_node;
            }
            
        } else {
            
            ptr = first_node;
            
            for (size_t counter = 0; counter < index; ++counter) {
                ptr = ptr -> next_node;
            }
            
        }
        
        return ptr -> value;
        
    }
    
    const T & operator[](size_t index) const {
        return at(index);
    }
    
    void insert(const T & value, size_t index) {
        
        if (index == list_size) {
            push_back(value);
            return;
        }
        
        if (not index) {
            push(value);
            return;
        }
        
        if (index > list_size) {
            throw out_of_range("Attempting to access element outside memory bounds");
        }
        
        list_node<T> * node = new list_node<T>(value);
        
        list_node<T> * next = node_at_index(index);
        list_node<T> * previous = next -> previous_node;
        
        node -> next_node = next;
        node -> previous_node = previous;
        
        previous -> next_node = node;
        next -> previous_node = node;
        
        ++list_size;
        
    }
    
    void insert(const T && value, size_t index) {
        
        insert(value, index);
        
    }
    
    void remove(size_t index) {
        
        if (index == list_size - 1) {
            remove_last();
            return;
        }
        
        if (not index) {
            remove_first();
            return;
        }
        
        if (index >= list_size) {
            throw out_of_range("Attempting to access element outside memory bounds");
        }
        
        list_node<T> * node_to_remove = node_at_index(index);
        list_node<T> * previous = node_to_remove -> previous_node;
        list_node<T> * next = node_to_remove -> next_node;
        
        previous -> next_node = next;
        next -> previous_node = previous;
        
        delete node_to_remove;
        --list_size;
        
    }
    
    void remove_first() {
        
        list_node<T> * next = first_node -> next_node;
        
        delete first_node;
        first_node = next;
        
        --list_size;
        
    }
    
    void remove_last() {
        
        list_node<T> * previous = last_node -> previous_node;
        
        delete last_node;
        last_node = previous;
        
        --list_size;
        
    }
    
    void push(const T & value) {
        
        list_node<T> * node = new list_node<T>(value);
        
        if (list_size) {
            
            node -> next_node = first_node;
            first_node -> previous_node = node;
            
        } else {
            
            last_node = node;
            
        }
        
        first_node = node;
        
        ++list_size;
    
    }
    
    void push(const T && value) {
        
        push(value);
        
    }
    
    void push_back(const T & value) {
        
        list_node<T> * node = new list_node<T>(value);
        
        if (list_size) {
            
            node -> previous_node = last_node;
            last_node -> next_node = node;
        
        } else {
            
            first_node = node;
            
        }
        
        last_node = node;
        
        ++list_size;
        
    }
    
    void push_back(const T && value) {
        push_back(value);
    }
    
    size_t find(const T & val_to_find) const {
        
        if (list_size == 0) {
            return list::npos;
        }
        
        list_node<T> * node = first_node;
        
        size_t index = 0;
        
        while (node != nullptr) {
            
            if (node -> value == val_to_find) {
                return index;
            }
            
            node = node -> next_node;
            
            ++index;
            
        }
        
        return list::npos;
        
    }
    
    size_t find(const T && val_to_find) const {
        return find(val_to_find);
    }
    
};

#endif /* List_hpp */
