#pragma once
#include <stdio.h>
#include <cstddef>
#include <iterator>
#include <memory>
template <typename T>
class Vector {
public:
//member types
using value_type = T;
using allocator_type = std::allocator<T>;
using size_type = std::size_t;
using difference_type = std::ptrdiff_t;
using reference = value_type&;
using const_reference = const value_type&;
using pointer = value_type*;
using const_pointer = const value_type*;
using iterator = value_type*;
using const_iterator = const value_type*;
using reverse_iterator = std::reverse_iterator<iterator>;
using const_reverse_iterator = std::reverse_iterator<const_iterator>;
private:
    T* elem;
    size_type sz;
    size_type cap;    
public:
    //constructors, destructor, assignment operators
    Vector();//konstruktorius
    Vector(size_type s);//konstruktorius su dydziu
    Vector(const Vector& r);//kopijavimo konstruktorius
    Vector& operator=(const Vector& r);//kopijavimo priskyrimo operatorius
    Vector(Vector&& r);//perkelimo(move) konstruktorius
    Vector& operator=(Vector&& r);//perkelimo(move) priskyrimo operatorius
    ~Vector();//destruktorius

    //member functions
    void assign (size_type count, const T& value);
    void assign (std::initializer_list<T> ilist);
    template <typename InputIt>
    void assign (InputIt first, InputIt last);
    template< typename R>
    constexpr void assign_range( R&& r );
    allocator_type get_allocator() const;
    //element access
    reference at(size_type pos);
    reference operator[]( size_type pos);
    reference front();
    reference back();
    T* data() noexcept;
    //iterators
    iterator begin() noexcept;
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;
    iterator end() noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;
    reverse_iterator rbegin() noexcept;
    const_reverse_iterator rbegin() const noexcept;
    const_reverse_iterator crbegin() const noexcept;
    reverse_iterator rend() noexcept;
    const_reverse_iterator rend() const noexcept;
    const_reverse_iterator crend() const noexcept;
};