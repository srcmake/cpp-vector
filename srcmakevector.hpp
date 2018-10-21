// Copyright srcmake.com 2018.
#include <iostream>

namespace srcmake
    {
    /////////////////////////////////////
    /// CLASS DEFINITION
    template<class T>
    class vector
        {
        private:
            int mSize;
            int mCapacity;

        public:
            // Constructors.
            vector();
            vector(int);
            vector(int, int);
        };
    /////////////////////////////////////

    template<class T>
    vector<T>::vector()
        {
        std::cout << "Called srcmake::vector empty constructor.\n";
        }
    
    template<class T>
    vector<T>::vector(int size)
        {
        std::cout << "Called srcmake::vector size constructor.\n";
        }
    
    template<class T>
    vector<T>::vector(int size, int initialValue)
        {
        std::cout << "Called srcmake::vector size, initial value constructor.\n";
        }
    }