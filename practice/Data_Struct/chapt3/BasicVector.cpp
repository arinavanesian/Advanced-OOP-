#include <iostream>
#include <string>
using namespace std;
template <typename T>
class BasicVector
{
private:
    int cap;
    T *a;

public:
    BasicVector(int c) : cap(c)
    {
        a = new T[cap];
    };
    T &operator[](int i)
    {
        return a[i];
    }
    void printVect()
    {
        for (size_t i = 0; i < this->cap; i++)
        {
            cout << " " << a[i];
        }
    }
    ~BasicVector()
    {
        cout << "Basic Vector delted!" << endl;
        delete a;
    };
};

int main(int argc, char const *argv[])
{
    BasicVector<int> int_vect(10);
    int_vect[0] = 1;
    int_vect.printVect();
    return 0;
}
