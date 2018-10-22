// Copyright srcmake.com 2018.
#include <iostream>

namespace srcmake
    {
    /////////////////////////////////////
    /////// CLASS DEFINITION ////////////
    /////////////////////////////////////
    template<class T>
    class vector
        {
        private:
            int mSize;
            int mCapacity;
            T* mArray;
            void CreateArray(int);
            void DeleteArray();
            void FillArrayWithValue(T);
            void CheckIfArrayIsTooSmall();
            void CheckIfArrayIsTooBig();
            void DoubleArraySize();
            void ReduceArraySize();

        public:
            vector();
            vector(int);
            vector(int, T);
            ~vector();
        };
    /////////////////////////////////////
    /////////////////////////////////////


    /////////////////////////////////////
    ///////// CONSTRUCTORS //////////////
    /////////////////////////////////////
    // Empty constructor. 
    // The size of the array is 0 (there are no elements).
    // We create the array a capacity of 1 to start.
    template<class T>
    vector<T>::vector(): mSize(0)
        {
        std::cout << "Called srcmake::vector empty constructor.\n";

        CreateArray(1);
        }

    // Constructor - The user specified the size of the array.
    template<class T>
    vector<T>::vector(int capacity): mSize(0), mCapacity(capacity)
        {
        std::cout << "Called srcmake::vector size constructor.\n";

        CreateArray(mCapacity);
        }
    
    // Constryctor - The user specified the size and what they want the array to be filled with.
    template<class T>
    vector<T>::vector(int capacity, T initialValue): mSize(capacity), mCapacity(capacity)
        {
        std::cout << "Called srcmake::vector size, initial value constructor.\n";

        CreateArray(mCapacity);
        FillArrayWithValue(initialValue);
        }

    // Destructor - delete the array.
    template<class T>
    vector<T>::~vector()
        {
        std::cout << "Called srcmake::vector destructor.\n";

        DeleteArray();
        }
    /////////////////////////////////////
    /////////////////////////////////////


    /////////////////////////////////////
    ///// INTERNAL CLASS OPERATIONS /////
    /////////////////////////////////////
    // Create the array on the heap, make the pointer point to it, set the capacity.
    template<class T>
    void vector<T>::CreateArray(int arrayCapacity)
        {
        mCapacity = arrayCapacity;
        mArray = new T[arrayCapacity];
        // Todo: Add error handling here in case there's not enough RAM to create this array, or the arrayCapacity is negative. 
        }

    // Delete the array.
    template<class T>
    void vector<T>::DeleteArray()
        {
        delete [] mArray;
        }

    // Fill an array with the specified value.
    template<class T>
    void vector<T>::FillArrayWithValue(T value)
        {
        // TODO: Use an STL function to do this.
        for(int i = 0; i < mSize; i++)
            {
            mArray[i] = value;
            }
        }

    // Check if the array isn't big enough (to push the current element on).
    // If true, call DoubleArraySize.
    template<class T>
    void vector<T>::CheckIfArrayIsTooSmall()
        {
        // TODO Fill in
        }
    
    // Check if the array is small. If so, reduce the size.
    template<class T>
    void vector<T>::CheckIfArrayIsTooBig()
        {
        // TODO Fill in
        }

    // Make the array bigger. 
    template<class T>
    void vector<T>::DoubleArraySize()
        {
        // TODO Fill in
        }
    
    // Make the array smaller (3/4 the current size).
    template<class T>
    void vector<T>::ReduceArraySize()
        {
        // TODO Fill in
        }
    /////////////////////////////////////
    /////////////////////////////////////
    
    
    /////////////////////////////////////
    ///// OPERATORS /////
    /////////////////////////////////////
    // []
    // = 
    // Iterator for for-each loop
    /////////////////////////////////////
    /////////////////////////////////////
    
    
    /////////////////////////////////////
    ///// EXTERNAL FUNCTIONS /////
    /////////////////////////////////////
    // size
    // push back
    // erase
    // insert
    /////////////////////////////////////
    /////////////////////////////////////
    }