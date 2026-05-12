#include <stdio.h>

template <typename T>
class Vector {
public:
using value_type = T;
using allocator_type = std::allocator<T>;
using size_type = std::size_t;
using difference_type = std::ptrdiff_t;
using reference = value_type&;
using const_reference = const value_type&;
using pointer = value_type*;
using const_pointer = const value_type*;
using iterator = value_type*;
using const iterator = const value_type*;
using reverse_iterator = std::reverse_iterator<iterator>;
using const_reverse_iterator = std::reverse_iterator<const_iterator>;
private:
    T* elem;
    size_t sz;
    size_t cap;    
public:
    Vector();
    
    ~Vector();
    
    void push_back(const T& value);
    


};