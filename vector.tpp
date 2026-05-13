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
    for(size_type i = 0; i < sz; i++){
        elem[i] = r.elem[i];
    }
    return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& r)//move priskyrimo operatorius
{
    if(this ==&r)
    return *this;
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
    for(size_type i = 0; i < sz; i++){
        elem[i] = value;
    }
}
template <typename T>
void Vector<T>::assign(std::initializer_list<T> ilist)//assign funkcija su initializer list
{
    delete[] elem;
    sz = ilist.size();
    cap = ilist.size();
    elem = (cap == 0 ) ? nullptr : new T[cap];//jei cap yra 0, tai elem bus nullptr, kitaip bus sukuriamas naujas masyvas
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
    elem = (cap == 0 ) ? nullptr : new T[cap];
    size_type i = 0;
    for(InputIt it = first; it != last; ++it){
        elem[i++] = *it;
    }
}
template <typename T>
template <typename R>
constexpr void Vector<T>::assign_range(R&& r)//assign funkcija su range
{
    delete[] elem;
    sz = static_cast<size_type>(std::distance(std::begin(r), std::end(r)));
    cap = sz;
    elem = (cap == 0 ) ? nullptr : new T[cap];
    size_type i = 0;
    for(auto&& value : r){
        elem[i++] = std::forward<decltype(value)>(value);
    }
}
template <typename T>
typename Vector<T>::allocator_type Vector<T>::get_allocator() const//get allocator funkcija
{
    return allocator_type();
}
template <typename T>
typename Vector<T>::reference Vector<T>::at(size_type pos)//at funkcija
{
    if((pos < 0) || (pos >= sz)){
        throw std::out_of_range("Index out of range");
    }
    return elem[pos];
}
template <typename T>
typename Vector<T>::reference Vector<T>::operator[](size_type pos)//operator []
{
    return elem[pos];
}
template <typename T>
typename Vector<T>::reference Vector<T>::front()//front funkcija
{
    return elem[0];
}
template <typename T>
typename Vector<T>::reference Vector<T>::back()//back funkcija
{
    return elem[sz - 1];
}
template <typename T>
T* Vector<T>::data() noexcept//data funkcija
{
    return elem;
}
template <typename T>
typename Vector<T>::iterator Vector<T>::begin() noexcept//begin funkcija
{
    return elem;
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::begin() const noexcept//const begin funkcija
{
    return elem;
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const noexcept//cbegin funkcija
{
    return elem;
}
template <typename T>
typename Vector<T>::iterator Vector<T>::end() noexcept//end funkcija
{
    return elem + sz;
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::end() const noexcept//const end funkcija
{
    return elem + sz;
}
template <typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const noexcept//cend funkcija
{
    return elem + sz;
}
template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin() noexcept//rbegin funkcija
{
    return reverse_iterator(end());
}
template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::rbegin() const noexcept//const rbegin funkcija
{
    return const_reverse_iterator(end());
}
template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const noexcept//crbegin funkcija
{
    return const_reverse_iterator(cend());
}
template <typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend() noexcept//rend funkcija
{
    return reverse_iterator(begin());
}
template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::rend() const noexcept//const rend funkcija
{
    return const_reverse_iterator(begin());
}
template <typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const noexcept//crend funkcija
{
    return const_reverse_iterator(cbegin());
}
template <typename T>
bool Vector<T>::empty() const noexcept//empty funkcija
{
    return sz == 0;
}
template <typename T>
typename Vector<T>::size_type Vector<T>::size() const noexcept//size funkcija
{
    return sz;
}
template <typename T>
typename Vector<T>::size_type Vector<T>::max_size() const noexcept//max size funkcija
{
    return std::allocator_traits<allocator_type>::max_size(allocator_type());
}
template <typename T>
typename Vector<T>::size_type Vector<T>::capacity() const noexcept//capacity funkcija
{
    return cap;
}
template <typename T>
void Vector<T>::reserve(size_type new_cap)//reserve funkcija
{
    if(new_cap > cap)
    {
        T* new_elem = new T[new_cap];
        for(size_type i =0; i < sz; i++)
        {
            new_elem[i] = elem[i];
        }
        delete[] elem;
        elem = new_elem;
        cap = new_cap;
    }
}
template <typename T>
void Vector<T>::shrink_to_fit()//shrink to fit funkcija
{
    if(sz < cap)
    {
        T* new_elem = (sz == 0) ? nullptr : new T[sz];
        for(size_type i = 0; i < sz; i++)
        {
            new_elem[i] = elem[i];
        }
        delete[] elem;
        elem = new_elem;
        cap = sz;
    }
}
template <typename T>
void Vector<T>::clear() noexcept//clear funkcija
{
    sz = 0;  
}
template <typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, const T& value)//insert funkcija su const T& value
{
    size_type index = pos - begin();
    if(sz >= cap)
    {
        reserve(cap == 0 ? 1 : cap * 2);
    }
    for(size_type i = sz; i > index; i--)
    {
        elem[i] = elem[i - 1];
    }
    elem[index] = value;
    ++sz;
    return begin() + index;
}
template <typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, T&& value)//insert funkcija su T&& value
{
    size_type index = pos - begin();
    if(sz >= cap)
    {
        reserve(cap == 0 ? 1 : cap * 2);
    }
    for(size_type i = sz; i > index; i--)
    {
        elem[i] = std::move(elem[i - 1]);
    }
    elem[index] = std::move(value);
    ++sz;
    return begin() + index;
}
template <typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, size_type count, const T& value)//insert funkcija su count ir value
{
    size_type index = pos - begin();
    if(sz + count > cap)
    {
        reserve((cap == 0) ? count : std::max(cap * 2, sz + count));
    }
    for(size_type i = sz; i >= index; i--)
    {
        elem[i + count - 1] = elem[i - 1];
    }
    for(size_type i = 0; i < count; i++)
    {
        elem[index + i] = value;
    }
    sz += count;
    return begin() + index;
}
template <typename T>
template <typename InputIt>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, InputIt first, InputIt last)//insert funkcija su iteratoriais
{
    size_type index = pos - begin();
    size_type count = static_cast<size_type>(std::distance(first, last));
    if(sz + count > cap)
    {
        reserve((cap == 0) ? count : std::max(cap * 2, sz + count));
    }
    for(size_type i = sz; i >= index; i--)
    {
        elem[i + count - 1] = elem[i - 1];
    }
    size_type i = 0;
    for(InputIt it = first; it != last; ++it)
    {
        elem[index + i] = *it;
        ++i;
    }
    sz += count;
    return begin() + index;
}
template <typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, std::initializer_list<T> ilist)//insert funkcija su initializer list
{
    size_type index = pos - begin();
    size_type count = ilist.size();
    if(sz + count > cap)
    {
        reserve((cap == 0) ? count : std::max(cap * 2, sz + count));
    }
    for(size_type i = sz; i >= index; i--)
    {
        elem[i + count - 1] = elem[i - 1];
    }
    size_type i = 0;
    for(const auto& value : ilist)
    {
        elem[index + i] = value;
        ++i;
    }
    sz += count;
    return begin() + index;
}
template <typename T>
constexpr typename Vector<T>::iterator Vector<T>::insert_range(const_iterator pos, std::initializer_list<T> ilist)
{
    size_type index = pos - begin();
    size_type count = ilist.size();
    if(sz + count > cap)
    {
        reserve((cap == 0) ? count : std::max(cap * 2, sz + count));
    }
    for(size_type i = sz; i >= index; i--)
    {
        elem[i + count - 1] = elem[i - 1];
    }
    size_type i = 0;
    for(const auto& value : ilist)
    {
        elem[index + i] = value;
        ++i;
    }
    sz += count;
    return begin() + index;
}