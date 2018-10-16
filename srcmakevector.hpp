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
        };
    /////////////////////////////////////

    template<class T>
    vector<T>::vector()
        {
        std::cout << "Called srcmake::vector empty constructor.\n";
        }
    }