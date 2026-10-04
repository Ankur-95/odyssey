# Day 5 -

## Today's Tasks
Arrays, strings, I/O
Raw arrays, std::string, std::cin/cout, string operations


Declare and iterate raw arrays — understand decay to pointer

Use std::string: find, substr, append, compare, size

Read from stdin: name + 3 sensor values

Format output with fixed, setprecision

Task: read 5 joint angles from user, print them formatted as a robot state table


---

### Arrays
What is Array ? 
- Array are the fixed size data structure that stores collection of elements similar data type ini sequential memory address.
- okk that was heavy.. We know how to create variables right ? so whenever you create two variables, the computer stores them in random memory address even if you create them simultaneously. But with the array we can store any no. of items with any data types in the memory that too in sequential address.


Ok Ankur i get it you need an array for storing the data in sequential memory address, but whats the point behind it ?
- Due to sequential memory address, computer can acces the data all at once, thus increasing the access speed .
- Decreases the overall time and space complexity. Dont know whatare these let it be, we will learn it afterwards.

Properties of Arrays :
1. Homogeneous: Every element of array must be of exact same data type.
2. Contiguous : Continuous and sequential memory.
3. Fixed size 
4. 0th Index: Counting of the array starts with zero. i.e First element is assigned index-no. 0


Declaration and Initialization :
The syntax of array can be understand with the foolowing :

type array_name[size]; 
--This is the declaration where we will be declaring the array..
Btw  Its not always necessary to specify the size of array explicitly it can directly holds the data and create the array of that particular size.

Initialization of Array:
i m explaining it directly by an ex:
int values[4] = {0,1,2,3}

#### Array Decay → Pointer
- Array decay is the automatic, silent conversion of an array's identity (its type and size) into a plain pointer to its first element the exact moment it is passed into a function. It loses its "array" status and becomes a simple memory address box.
- The function only holds a pointer to first item, it is completely blind to how big the array is.
Ex: 


// The function takes a pointer to the first item and the total size
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " "; // Accesses sequential memory slots
    }
    std::cout << "\n";
}

int main() {
    int robsens[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Pass the array (decays to pointer) and its explicit size
    printArray(robsens, 10); 
    return 0;
}

---
### String Operation
Some string operation which can be performed on the string are as follows:
1. size()
Returns the number of characters in the string.
Syntax:
string.size()
2. find()
Used to check if a word exists, always compare the result directly against std::string::npos.
What --> std::string::npos does ?
It is a special constant which is returned in the function which cannot return a normal index.
It stands for "No Position".
Under the hood, it is just the number -1 stored as an unsigned maximum integer value.
Syntax:
string.find("word you need to find ")
3. substr
This method is used to extract a smaller piece (a substring) out of an existing string.
Syntax :
string.substr(start_index, length);
Ex: 
int main(){
    std::string branch = "Robotics and Automation";
    std::string field = branch.substr(0,7)
    std::cout<< field<< "\n";
}
Output: Robotics
4. append()
The append() method is used to add characters or strings to the very end of an existing string.
It directly modifies the original string variable.
Syntax:
string.append(text_to_add);
5. compare()
Used for comparing two strings and returns the result(but exactly what ?) 
Syntax : string1.compare(string2)
6. cin>> vs getline()
cin>> reads a word/numbers whereas, syntax:std::cin>>
getline() reads entire line    

--- 
Chatgpt: Add some more info about tasks giving/explaining the tasks.
 ## Task-1 : Raw Array 
 ### Create an array containing 5 sensor readings.
 creating an array is as simple as creating variable, wait its not as simple as creating but it is just like creating the variable
 In the task file we have declared an array "sensor_data" and initialized it with 5 values and wrote a program to iterate through the array while printing each reading with its sensor no. 
 Here is the task file: [Code_1](code1.cpp) 
 Chatgpt jus for you : // ## Task-1 : Raw Array 
// ### Create an array containing 5 sensor readings.
# include <iostream>
int main(){
    int sensor_data[5] = { 17, 26, 34, 1, 7};
    int a = 1;
    for (int i = 0; i < 5; i++){
        std::cout << "Sensor Number " << a << ":" << " Data : " << sensor_data[i] << std::endl;
        a++;
    }
} 

--- 
## Task-2: Array Function
### Create a function that receives an array and prints its elements.
Similar to task_1 just here instead of doing it directly, we are doing it as functions.. so that we can work on functions side by side.
Here is the task file: [Code_2](code2.cpp)   
 
--- 
## Task-3: String operation
### Create a string representing a robot-related name and perform operations.
this task is designed to enhance our string operation knowledge and understanding.
here we have created a variable and assigned some sort of string value to it.. 
Operations like: Printing size , searching for a word, extracting a part of it, appending soething, comparing 
Here is the task file: [Code_3](code3.cpp) 

---
## Task-4: Sensor Input
### Write a program that asks the user for inputs and display it appropriately
Store the data taken as input from the and then display them back to the user.
Here is the task file: [Code_4](code4.cpp) 

