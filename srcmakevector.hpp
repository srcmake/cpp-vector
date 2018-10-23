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
            void ChangeArrayCapacityTo(const int);

        public:
            vector();
            vector(int);
            vector(int, T);
            ~vector();
            T operator [ ] (const int);
            int size();
            void push_back(const T);
            void erase(const int);
            void insert(const int, const T);
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
        if(mCapacity == mSize)
            {
            DoubleArraySize();
            }
        }
    
    // Check if the array is small. If so, reduce the size.
    template<class T>
    void vector<T>::CheckIfArrayIsTooBig()
        {
        if(mCapacity == 2*mSize)
            {
            ReduceArraySize();
            }
        }

    // Make the array bigger. 
    template<class T>
    void vector<T>::DoubleArraySize()
        {
        auto newCapacity = mCapacity*2;
        ChangeArrayCapacityTo(newCapacity);
        }
    
    // Make the array smaller (3/4 the current size).
    template<class T>
    void vector<T>::ReduceArraySize()
        {
        auto newCapacity = mCapacity*3/4;
        if(newCapacity > 0)
            {
            ChangeArrayCapacityTo(newCapacity);
            }
        }

    // Change the array's capacity to the specified new capacity.
    template<class T>
    void vector<T>::ChangeArrayCapacityTo(const int newCapacity)
        {
        // Create a new array with the specified new capacity. 
        T* newArray = new T[newCapacity];
        
        // Copy the current array to the new array.
        for(int i = 0; i < mSize; i++)
            {
            newArray[i] = mArray[i];
            }

        // Delete the current array.
        DeleteArray();

        // Make the pointer point to the new array.
        mArray = newArray;

        std::cout << "Resized the array from " << mCapacity << " to " << newCapacity << ".\n";

        // Update the capacity variable.
        mCapacity = newCapacity;
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
    T vector<T>::operator [ ] (const int index)
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
    void vector<T>::push_back(const T element)
        {
        // TODO: Error handling if the element is the wrong type.
        std::cout << "Pushing an element into the array.\n";

        // Check if the array needs to be made larger.
        CheckIfArrayIsTooSmall();
        
        // Add this element to the array.
        mArray[mSize] = element;
        
        // Increment the size.
        mSize += 1;
        }

    // erase - Remove the element at the specified index.
    template<class T>
    void vector<T>::erase(const int index)
        {
        // TODO: Error handling if index is out of range.
        // TODO: Error handling if there are no elements to delete.
        // TODO: Make sure unit testing handles weird edge cases for capacities and sizes.
        std::cout << "Erasing an element from the array.\n";
        
        // Copy the elements from [index+1, size-1] to [index, size-2].
        for(int i = index; i <= mSize-2; i++)
            {
            mArray[i] = mArray[i+1];
            }
        
        // Delete the element at size-1. (NOTE: This isn't really necessary. This shouldn't get accessed by the user anyway. It will only get overwritten if push_back is called onto the element.)
        mArray[mSize-1] = 0;

        // Update the size variables.
        mSize -= 1;

        // Check if we need to resize the array, if the capacity is too large.
        CheckIfArrayIsTooBig();
        }

    // insert
    template<class T>
    void vector<T>::insert(const int index, const T element)
        {
        // TODO Fill in
        // Check if the array needs to be made larger.
        // Copy the elements from [index, size-1] to [index+1, size].
        // Set the array at the index to the element.
        // Update the size variable.
        // TODO: Error handling if index is out of range.
        // TODO: Error handling if the element is the wrong type.
        }
    /////////////////////////////////////
    /////////////////////////////////////
    }