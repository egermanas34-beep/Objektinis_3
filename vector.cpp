#include "vector.h"

template <typename T>
Vector<T>::Vector() //defaultinis konstruktorius
{
    elem = nullptr;
    sz = 0;
    cap = 0;
}
template <typename T>
Vector<T>::Vector(size_type s)//konstruktorius su dydziu
{
    elem = new T[s];
    sz = s;
    cap = s;
}
template <typename T>
Vector<T>::Vector(const Vector& r)//kopijavimo konstruktorius
{
    elem = new T[r.cap];
    sz = r.sz;
    cap = r.cap;
    for(size_type i = 0; i < sz; i++){
        elem[i] = r.elem[i];
    }
}
template <typename T>
Vector<T>::Vector(Vector&& r) //perkelimo(move) konstruktorius
{
    elem = r.elem;
    sz = r.sz;
    cap = r.cap;
    r.elem = nullptr;
    r.sz = 0;
    r.cap = 0;
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& r) //kopijavimo priskyrimo operatorius
{
    if(this == &r)
        return *this;
    
    delete[] elem;
    sz = r.sz;
    cap = r.cap;
    elem = new T[cap];
    for(size_type i=0; i<sz;i+=)
    elem[i] = r.elem[i];
    return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& r)//move priskyrimo operatorius
{
    if(this ==&r)
    returnt *this;
    delete[] elem;

    elem = r.elem;
    sz = r.sz;
    cap = r.cap;
    r.elem = nullptr;
    r.sz=0;
    r.cap = 0;
    return *this;

}
