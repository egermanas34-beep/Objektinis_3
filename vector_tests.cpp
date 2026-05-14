#include <gtest/gtest.h>
#include <sstream>

#include "vector.h"

TEST(VectorTest, DefaultConstructor) {
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    EXPECT_EQ(vec.capacity(), 0);
}
TEST(VectorTest, SizeConstructor) {
    Vector<int> vec(5);
    EXPECT_EQ(vec.size(), 5);
    EXPECT_GE(vec.capacity(), 5);
    
}
TEST(VectorTest, InitializerListConstructor) {
    Vector<int> vec{1, 2, 3, 4, 5};
    EXPECT_EQ(vec.size(), 5);
    EXPECT_GE(vec.capacity(), 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], i + 1);
    }
}
TEST(VectorTest, CopyConstructor) {
    Vector<int> vec1{1, 2, 3};
    Vector<int> vec2 = vec1; // Copy constructor
    EXPECT_EQ(vec2.size(), vec1.size());
    EXPECT_GE(vec2.capacity(), vec1.size());
    for (size_t i = 0; i < vec2.size(); ++i) {
        EXPECT_EQ(vec2[i], vec1[i]);
    }
}
TEST(VectorTest, MoveConstructor) {
    Vector<int> vec1{1, 2, 3};
    Vector<int> vec2 = std::move(vec1); // Move constructor
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_GE(vec2.capacity(), 3);
    for (size_t i = 0; i < vec2.size(); ++i) {
        EXPECT_EQ(vec2[i], i + 1);
    }
    EXPECT_EQ(vec1.size(), 0); // vec1 should be empty after move
}
TEST(VectorTest, CopyAssignment) {
    Vector<int> vec1{1, 2, 3};
    Vector<int> vec2;
    vec2 = vec1; // Copy assignment
    EXPECT_EQ(vec2.size(), vec1.size());
    EXPECT_GE(vec2.capacity(), vec1.size());
    for (size_t i = 0; i < vec2.size(); ++i) {
        EXPECT_EQ(vec2[i], vec1[i]);
    }
}
TEST(VectorTest, MoveAssignment) {
    Vector<int> vec1{1, 2, 3};
    Vector<int> vec2;
    vec2 = std::move(vec1); // Move assignment
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_GE(vec2.capacity(), 3);
    for (size_t i = 0; i < vec2.size(); ++i) {
        EXPECT_EQ(vec2[i], i + 1);
    }
    EXPECT_EQ(vec1.size(), 0); // vec1 should be empty after move
}
TEST(VectorTest, Destructor)
{
    Vector<int>* vec = new Vector<int>{1, 2, 3};
    delete vec; // Destructor should be called without issues
}
TEST(VectorTest, Assign)
{
    Vector<int> vec;
    vec.assign(5, 42); // Assign 5 elements with value 42
    EXPECT_EQ(vec.size(), 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], 42);
    }
}
TEST(VectorTest, AssignInitializerList)
{
    Vector<int> vec;
    vec.assign({1, 2, 3, 4, 5}); // Assign from initializer list
    EXPECT_EQ(vec.size(), 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], i + 1);
    }
}
TEST(VectorTest, AssignRange)
{
    Vector<int> vec;
    Vector<int> source = {1, 2, 3, 4, 5};
    vec.assign(source.begin(), source.end()); // Assign from range
    EXPECT_EQ(vec.size(), source.size());
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec[i], source[i]);
    }
}
TEST(VectorTest, get_allocator)
{
    Vector<int> vec;
    auto allocator = vec.get_allocator();
    EXPECT_TRUE((std::is_same<decltype(allocator), std::allocator<int>>::value));
}
TEST(VectorTest, At)
{
    Vector<int> vec{1, 2, 3};
    EXPECT_EQ(vec.at(0), 1);
    EXPECT_EQ(vec.at(1), 2);
    EXPECT_EQ(vec.at(2), 3);
    EXPECT_THROW(vec.at(3), std::out_of_range); // Out of range access
}
TEST(VectorTest, OperatorIndex)
{
    Vector<int> vec{1, 2, 3};
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    
}
TEST(VectorTest, Front)
{
    Vector<int> vec{1, 2, 3};
    EXPECT_EQ(vec.front(), 1);
}
TEST(VectorTest, Back)
{
    Vector<int> vec{1, 2, 3};
    EXPECT_EQ(vec.back(), 3);
}
TEST(VectorTest, Data)
{
    Vector<int> vec{1, 2, 3};
    int* data = vec.data();
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 2);
    EXPECT_EQ(data[2], 3);
}
TEST(VectorTest, Begin)
{
    Vector<int> vec{1, 2, 3};
    auto it = vec.begin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}
TEST(VectorTest, End)
{
    Vector<int> vec{1, 2, 3};
    auto it = vec.end();
    EXPECT_EQ(it - vec.begin(), 3); // End iterator should be one past the last element
}
TEST(VectorTest, CBegin)
{
    Vector<int> vec{1, 2, 3};
    auto it = vec.cbegin();
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 3);
}
TEST(VectorTest, CEnd)
{
    Vector<int> vec{1, 2, 3};
    auto it = vec.cend();
    EXPECT_EQ(it - vec.cbegin(), 3); // CEnd iterator should be one past the last element
}
TEST(VectorTest, RBegin)
{
    Vector<int> vec{1, 2, 3};
    auto it = vec.rbegin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
}
TEST(VectorTest, CRBegin)
{
    Vector<int> vec{1, 2, 3};
    auto it = vec.crbegin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
}
TEST(VectorTest, REnd)
{
    Vector<int> vec{1, 2, 3};
    auto it = vec.rend();
    EXPECT_EQ(it - vec.rbegin(), 3); // REnd iterator should be one past the last element in reverse
}
TEST(VectorTest, CREnd)
{
    Vector<int> vec{1, 2, 3};
    auto it = vec.crend();
    EXPECT_EQ(it - vec.crbegin(), 3); // CREnd iterator should be one past the last element in reverse
}
TEST(VectorTest, Empty)
{
    Vector<int> vec;
    EXPECT_TRUE(vec.empty());
    vec.push_back(1);
    EXPECT_FALSE(vec.empty());
}
TEST(VectorTest, Size)
{
    Vector<int> vec;
    EXPECT_EQ(vec.size(), 0);
    vec.push_back(1);
    EXPECT_EQ(vec.size(), 1);
}
TEST(VectorTest, MaxSize)
{
    Vector<int> vec;
    EXPECT_GT(vec.max_size(), 0);
}
TEST(VectorTest, Capacity)
{
    Vector<int> vec;
    EXPECT_EQ(vec.capacity(), 0);
    vec.push_back(1);
    EXPECT_GE(vec.capacity(), 1);
}
TEST(VectorTest, Reserve)
{
    Vector<int> vec;
    vec.reserve(10);
    EXPECT_GE(vec.capacity(), 10);
}
TEST(VectorTest, ShrinkToFit)
{
    Vector<int> vec;
    vec.reserve(10);
    vec.shrink_to_fit();
    EXPECT_EQ(vec.capacity(), 0); // After shrink_to_fit, capacity should be reduced to size (which is 0)
}
TEST(VectorTest, Clear)
{
    Vector<int> vec{1, 2, 3};
    vec.clear();
    EXPECT_EQ(vec.size(), 0);
    EXPECT_TRUE(vec.empty());
}
TEST(VectorTest, Insert)
{
    Vector<int> vec{1, 3};
    auto it = vec.insert(vec.begin() + 1, 2); // Insert 2 at position 1
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}
TEST(VectorTest, InsertMove)
{
    Vector<int> vec{1, 3};
    int value = 2;
    auto it = vec.insert(vec.begin() + 1, std::move(value)); // Insert using move semantics
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}
TEST(VectorTest, InsertCountValue)
{
    Vector<int> vec{1, 4};
    auto it = vec.insert(vec.begin() + 1, 2, 2); // Insert two 2's at position 1
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(vec.size(), 4);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 2);
    EXPECT_EQ(vec[3], 4);
}
TEST(VectorTest, InsertInitializerList)
{
    Vector<int> vec{1, 4};
    auto it = vec.insert(vec.begin() + 1, {2, 3}); // Insert initializer list at position 1
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(vec.size(), 4);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 4);
}
TEST(VectorTest, InsertRange)
{
    Vector<int> vec{1, 4};
    Vector<int> to_insert = {2, 3};
    auto it = vec.insert(vec.begin() + 1, to_insert.begin(), to_insert.end()); // Insert range at position 1
    EXPECT_EQ(*it, 2);
    EXPECT_EQ(vec.size(), 4);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 4);
}
TEST(VectorTest, Emplace)
{
    Vector<std::pair<int, int>> vec;
    auto it = vec.emplace(vec.begin(), 1, 2); // Emplace a pair at the beginning
    EXPECT_EQ(it->first, 1);
    EXPECT_EQ(it->second, 2);
    EXPECT_EQ(vec.size(), 1);
}
TEST(VectorTest, EmplaceBack)
{
    Vector<std::pair<int, int>> vec;
    auto& ref = vec.emplace_back(1, 2); // Emplace a pair at the back
    EXPECT_EQ(ref.first, 1);
    EXPECT_EQ(ref.second, 2);
    EXPECT_EQ(vec.size(), 1);
}
TEST(VectorTest, Erase)
{
    Vector<int> vec{1, 2, 3, 4, 5};
    auto it = vec.erase(vec.begin() + 2); // Erase the element at index 2 (value 3)
    EXPECT_EQ(*it, 4); // The new element at index 2 should be 4
    EXPECT_EQ(vec.size(), 4);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 4);
    EXPECT_EQ(vec[3], 5);
}
TEST(VectorTest, EraseRange)
{
    Vector<int> vec{1, 2, 3, 4, 5};
    auto it = vec.erase(vec.begin() + 1, vec.begin() + 4); // Erase elements at indices 1 to 3 (values 2, 3, 4)
    EXPECT_EQ(*it, 5); // The new element at index 1 should be 5
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 5);
}
TEST(VectorTest, PushBack)
{
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}
TEST(VectorTest, PushBackMove)
{
    Vector<int> vec;
    int value1 = 1, value2 = 2, value3 = 3;
    vec.push_back(std::move(value1));
    vec.push_back(std::move(value2));
    vec.push_back(std::move(value3));
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}
TEST(VectorTest, AppendRange)
{
    Vector<int> vec;
    Vector<int> to_append = {1, 2, 3};
    vec.append_range(to_append); // Append range to the vector
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
}
TEST(VectorTest, PopBack)
{
    Vector<int> vec{1, 2, 3};
    vec.pop_back();
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
}
TEST(VectorTest, Resize)
{
    Vector<int> vec{1, 2, 3};
    vec.resize(5); // Resize to larger size
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 0); // New elements should be default-initialized to 0
    EXPECT_EQ(vec[4], 0);
    
    vec.resize(2); // Resize to smaller size
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
}
TEST(VectorTest, ResizeWithValue)
{
    Vector<int> vec{1, 2, 3};
    vec.resize(5, 42); // Resize to larger size with value
    EXPECT_EQ(vec.size(), 5);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    EXPECT_EQ(vec[2], 3);
    EXPECT_EQ(vec[3], 42); // New elements should be initialized to 42
    EXPECT_EQ(vec[4], 42);
    
    vec.resize(2, 42); // Resize to smaller size (value should not matter)
    EXPECT_EQ(vec.size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
}
TEST(VectorTest, Swap)
{
    Vector<int> vec1{1, 2, 3};
    Vector<int> vec2{4, 5, 6};
    vec1.swap(vec2); // Swap vec1 and vec2
    EXPECT_EQ(vec1.size(), 3);
    EXPECT_EQ(vec1[0], 4);
    EXPECT_EQ(vec1[1], 5);
    EXPECT_EQ(vec1[2], 6);
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
}
TEST(VectorTest, NonMemberSwap)
{
    Vector<int> vec1{1, 2, 3};
    Vector<int> vec2{4, 5, 6};
    swap(vec1, vec2); // Non-member swap function
    EXPECT_EQ(vec1.size(), 3);
    EXPECT_EQ(vec1[0], 4);
    EXPECT_EQ(vec1[1], 5);
    EXPECT_EQ(vec1[2], 6);
    EXPECT_EQ(vec2.size(), 3);
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
}
TEST(VectorTest, EraseValue)
{
    Vector<int> vec{1, 2, 3, 2, 4};
    erase(vec, 2); // Erase all occurrences of 2
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 3);
    EXPECT_EQ(vec[2], 4);
}
TEST(VectorTest, EraseIf)
{
    Vector<int> vec{1, 2, 3, 4, 5};
    erase_if(vec, [](int value) { return value % 2 == 0; }); // Erase even numbers
    EXPECT_EQ(vec.size(), 3);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 3);
    EXPECT_EQ(vec[2], 5);
}
TEST(VectorTest, EqualityOperators)
{
    Vector<int> vec1{1, 2, 3};
    Vector<int> vec2{1, 2, 3};
    Vector<int> vec3{4, 5, 6};
    
    EXPECT_TRUE(vec1 == vec2);
    EXPECT_FALSE(vec1 == vec3);
    EXPECT_TRUE(vec1 != vec3);
    EXPECT_FALSE(vec1 != vec2);
}
TEST(VectorTest, RelationalOperators)
{
    Vector<int> vec1{1, 2, 3};
    Vector<int> vec2{1, 2, 3};
    Vector<int> vec3{4, 5, 6};
    
    EXPECT_FALSE(vec1 < vec2);
    EXPECT_TRUE(vec1 < vec3);
    EXPECT_FALSE(vec3 < vec1);
    
    EXPECT_TRUE(vec1 <= vec2);
    EXPECT_TRUE(vec1 <= vec3);
    EXPECT_FALSE(vec3 <= vec1);
    
    EXPECT_FALSE(vec1 > vec2);
    EXPECT_FALSE(vec1 > vec3);
    EXPECT_TRUE(vec3 > vec1);
    
    EXPECT_TRUE(vec1 >= vec2);
    EXPECT_FALSE(vec1 >= vec3);
    EXPECT_TRUE(vec3 >= vec1);
}

