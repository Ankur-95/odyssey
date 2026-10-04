// ## Task-2: Array Function
// ### Create a function that receives an array and prints its elements.

#include <iostream>

void printArray(int arr[], int size) {

    for (int i = 0; i < size; i++) {
        std::cout << "Element " << i << ": " << arr[i] << std::endl;
    }

}

int main(){
    std::cout << "Enter the size of the array: ";
    int size;
    std::cin >> size;
    int* arr = new int[size];   
    std::cout << "Enter " << size << " elements for the array:\n";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }    
    printArray(arr, size);
    delete[] arr; // Free the allocated memory
    return 0;
}
