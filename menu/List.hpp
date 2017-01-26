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
    
    list_node(T & newValue, T * next = nullptr, T * previous = nullptr) {
        
        value         = newValue;
        next_node     = next;
        previous_node = previous_node;
        
    }
    
};

template <typename T>
class list {
    
    list_node<T> * first_node;
    list_node<T> * last_node;
    size_t list_size;
    
public:
    
    list() {
        list_size  = 0;
        first_node = nullptr;
        last_node  = nullptr;
    }
    
    list(size_t items, T & ...);
    ~list() {
        
        if (list_size) {
            
            list_node<T> * next;
            
            for (list_node<T> * ptr = first_node; ptr != nullptr; ptr = next) {
                
                next = next -> next_node;
                delete ptr;
                
            }
            
        }
        
    }
    
    size_t length() {
        return list_size;
    }
    size_t size() {
        return list_size;
    }
    
    T & first() {
        
        if (first_node == nullptr) {
            throw out_of_range("Trying to access element outside memory bounds");
        }
        return first_node -> value;
        
    }
    
    T & last() {
        
        if (first_node == nullptr) {
            throw out_of_range("Trying to access element outside memory bounds");
        }
        return last() -> value;
        
    }
    
    T & at(size_t index) {
        
        if (index >= list_size or first_node == nullptr) {
            throw out_of_range("Trying to access element outside memory bounds");
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
        at(index);
    }
    
    void insert(T & value, size_t index) {
        
        if (index == list_size) {
            push_back(value);
            return;
        }
        
        if (not index) {
            push(value);
            return;
        }
        
        if (index > list_size) {
            throw out_of_range("Trying to access element outside memory bounds");
        }
        
        list_node<T> * node = new list_node<T>(value);
        
        list_node<T> * next = &at(index);
        list_node<T> * previous = next -> previous_node;
        
        node -> next_node = next;
        node -> previous_node = previous;
        
        previous -> next_node = node;
        next -> previous_node = node;
        
        ++list_size;
        
    }
    
    void remove(size_t index) {
        
    }
    
    void remove_first() {
        
    }
    
    void remove_last() {
        
    }
    
    void push(T & value) {
        
        list_node<T> * node = new list_node<T>(value);
        
        node -> next_node = first_node;
        first_node -> previous_node = node;
        
        first_node = node;
        
        ++list_size;
    
    }
    
    void push_back(T & value) {
        
        list_node<T> * node = new list_node<T>(value);
        
        node -> previous_node = last_node;
        last_node -> next_doe = node;
        
        last_node = node;
        
        ++list_size;
        
    }
    
};

#endif /* List_hpp */
