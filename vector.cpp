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
Vector<T>::~Vector()//destruktorius
{
    delete[] elem;
    sz = 0;
    cap = 0;
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
template <typename T>
void Vector<T>::assign(size_type count, const T& value)//assign funkcija su dviem parametrais
{
    delete[] elem;
    elem = new T[count];
    sz = count;
    cap = count;
    for(size_type i=0; i<sz; i++){
        elem[i] = value;
    }
}
template <typename T>
void Vector<T>::assign(std::initializer_list<T> ilist)//assign funkcija su initializer list
{
    delete[] elem;
    sz = ilist.size();
    cap = ilist.size();
    elem = new T[cap];
    size_type i = 0;
    for(const auto& value : ilist){
        elem[i++] = value;
    }
}
template <typename T>
template <typename InputIt>
void Vector<T>::assign(InputIt first, InputIt last)//assign funkcija su iteratoriais
{
    delete[] elem;
    sz = static_cast<size_type>(std::distance(first, last));
    cap = sz;
    elem = new T[cap];
    size_type i = 0;
    for(InputIt it = first; it != last; ++it){
        elem[i++] = *it;
    }
}
