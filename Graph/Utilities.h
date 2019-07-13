//
//  Generic.h
//  Algorithms
//
//  Created by Harshavardhan K K on 04/07/16.
//  Copyright © 2016 Harshavardhan K. All rights reserved.
//

#ifndef Generic_h
#define Generic_h

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>

void print(T& value) {
    std::cout << value;
}

template <typename T>



void arrayCopy(T* array, T* dest_array, int sourcePos, int destPos, int source_length) {
    
    int j = 0;
    
    for (int i = sourcePos; i < source_length; i++) {
        dest_array[destPos + j++] = array[i];
    }
    
}

template <typename T>

void displayArray(T* array, int size) {
    
   // int l = sizeof(array) / sizeof(*array);
    
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }

    cout << '\n';
    
}

template <typename T>

void display(vector<T> &vec) {
    
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << '\n';
}

template <typename T>

void swapValue(T* value, T* anValue) {
    
    T temp = *value;
    *value = *anValue;
    *anValue = temp;
}

int binarySearch(int value, int left, int right, int *array) {
    
    int mid = (right - left) / 2;
    
    if(array[mid] == value) {
        return mid;
        
    } else if(value > array[mid]) {
        return binarySearch(value, mid + 1, right, array);
        
    } else {
        return binarySearch(value, 0, mid, array);
    }
    
    return -1;
}

void split() {
    
}


#endif /* Generic_h */
