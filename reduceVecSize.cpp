#include <vector>
#include <iostream>
 
int main ()
{
    std::vector<int> v(60, 42);
    std::cout << v.capacity() << std::endl;
    v.erase(v.begin() + 2, v.begin() + 12);
    std::cout << v.capacity() << std::endl;
 
    std::vector<int>(v.begin(), v.end()).swap(v);
 
    std::cout << v.capacity() << std::endl;
}
