#include "vector.h"

template <typename T>
Vector<T>::Vector() {
    elem = nullptr;
    sz = 0;
    cap = 0;
};
template <typename T>
Vector<T>::Vector(size_type s){
    elem = new T[s];
    sz = s;
    cap = s;
}
template <typename T>
Vector<T>::Vector(const Vector& r){
    elem = new T[r.cap];
    sz = r.sz;
    cap = r.cap;
    for(size_type i = 0; i < sz; i++){
        elem[i] = r.elem[i];
    }
}