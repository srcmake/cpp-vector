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
            T operator [ ] (int index);
            int size();
            void push_back(T element);
            void erase(int index);
            void insert(int index, T element);
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
    /// MOVE SEMANTICS (Copy and Move) //
    /////////////////////////////////////
    // Copy Constructor
    // Copy Assignment Operator
    // Move Constructor
    // Move Assignment Operator
    /////////////////////////////////////
    /////////////////////////////////////

    
    /////////////////////////////////////
    ///// OPERATORS (EXTERNAL) /////
    /////////////////////////////////////
    // []
    template<class T>
    T vector<T>::operator [ ] (int index)
        {
        // TODO: Error handling to make sure the index is in range.
        return mArray[index];
        }

    // Iterator for for-each loop
    // TODO
    // begin() and end() here?
    /////////////////////////////////////
    /////////////////////////////////////
    
    
    /////////////////////////////////////
    ///// EXTERNAL FUNCTIONS /////
    /////////////////////////////////////
    // size - return the size of the vector. 
    template<class T>
    int vector<T>::size()
        {
        return mSize;
        }
    
    // push back - Add an element to the array.
    template<class T>
    void vector<T>::push_back(T element)
        {
        // TODO Fill in
        // TODO: Error handling if the element is the wrong type.
        }

    // erase - Remove the element at the specified index.
    template<class T>
    void vector<T>::erase(int index)
        {
        // TODO Fill in
        // TODO: Error handling if index is out of range.
        }

    // insert
    template<class T>
    void vector<T>::insert(int index, T element)
        {
        // TODO Fill in
        // TODO: Error handling if index is out of range.
        // TODO: Error handling if the element is the wrong type.
        }
    /////////////////////////////////////
    /////////////////////////////////////
    }