# Day 2 — Variables, types, I/O

## Today's Tasks
* Declare variables of every built-in type, print them
* Understand signed vs unsigned overflow with a small experiment
* Use const and constexpr — know the difference
* Practice all operators: +,-,*,/,%,<<,>>,&,|,^
* Use auto for type deduction — know when it helps/hurts
* Task: sensor unit converter (raw int → voltage as double → display string)


##

### Task 1 :
In C++ there are several types of Data types. While defining any particular variable it is required that we also have to define its type, meaning the type of data which it is going to store. Data Types are as follows :
1. **int** :- Integer :- Used for storing the Whole numbers(values) in the container.Generally it stores using 2-bits.
        Ex: 1,2,4  

2. **float** :- Used to store the decimal values. Generally it stores using 4-bits. Capable of storing digits upto 7 decimal points. 
        Ex: 1.2f, 4.9f  

3.**boolean** :- Used for storing the logical values i.e True or False.  

4.**Character** :- It is the data type which is used to store any character may be a letter, special symbol  or even a number.
        Ex: a,A,%,6  

5.String :-This is data type which you can say is the superset of character. In string you can store multiple character, numbers and symbols simultaneously.
        Ex: Yoo, you are reading a string.
6.Double :- Double is also a number storing data type similar to float, but it is more precise and can hold/carry number upto higher decimal point. Capable of storing digits upto 15-17 decimal points
        Ex: 15.115151515151
##

### Task 2 :
**Signed vs Unsigned Values**
1. Signed values :  
        -  Are the containers in which we can store both negative as well as positive numbers. The first bit in this containers represent and tells computer whether the given number is positive(0) or negative(1).  
        - Due to this reason of allocating one bit for sign, the range gets divided into half in comparison of same bit unsigned container.  
        - 8 bit signed container will hold values in following way: -127 to 127

2. Unsigned values :
        - Are the containers in which we can only store positive numbers.
        - 8 bit unsigned container will hold values in following way: 0 to 255
Program Explaining this concepts is [here](phase_1\week_1\day_2\code1.cpp)

**Some Concepts Related to signed and unsigned containers :**  
* Overflowing : It happens when the incoming values are larger than the capacity/range of the allocated container. This results in the setting the container back to its lowest/minimum value.  
Ex: Consider a 8-bit container storing max value i.e 255 now when you will add 1 more in this container, it will set the container bacak to 0.   
This is called as overflowing. 

* Underflowing : It happens when the incoming values are smaller than the capacity/range of the allocated container. This results in the setting the container back to its highest/maximum value.  
Ex: Consider a 8-bit container storing min value i.e 0 now when you will subtract 1 from this container, it will set the container bacak to 255.  

Program Explaining this concepts is [here](phase_1\week_1\day_2\readme.md).

Question :-
  
  Which one is safer for sensor values w.r.t robotics application ?  

  -Signed container are more safer and is more used considering that the sensors values can be both negative as well as positive.  
  -As we know parametrical values in real life rarely stays constant and positive, considering such conditions it is very much feasible to use signed container as compared to unsigned, even if that means lowering our storing capablities.

#

### Task 3 :
**Const and Constexpr :**
* const: Yeah normal constant i.e The values will be fixed, once given. It can be passed using user input. In this case, there is a possibility that the compiler would not know the value while running the program.   

* constexpr: It is similar to a normal constant. The only difference is that the compiler should know the value which is being stored in this constant. That means the program should know the value before running/executing the complete program.   

But whats the need ??
Some of the main needs or requirements for building the constexpr are as follows:
1. It increases the speed of execution, as calculation is done already it saves compute time as well as compute power.
2. It allows the user to use special features which require values beforehand.
3. It can determine the error at the compilation stage, thus preventing user window error.  
4. It makes your code faster, safer, and memory-efficient.
#

### Task 4 :
**Operator :** 
Just like in maths, in coding also we have operators such as:
1. +(Add): Offco used for giving you the sum of two numbers.
2. -(Subtract): Used to give th subtraction between two numbers.
3. *(Multiply): Used for giving the product of two numbers  
4. /(Divide): Used for giving the quotient of two numbers (in C++, it  chops off the decimal part if using whole numbers).  
5.% (Modulus): Used for giving only the remainder left over after dividing two numbers.  
6.<< (Left Shift): Used to shift binary bits to the left, which multiplies a number by 2 for every shift position.
7.>>(Right Shift): Used to shift binary bits to the right, which divides a number by 2 for every shift position
8.& (Bitwise AND): Used to compare two numbers in binary, giving a 1 only if both matching bits are 1.
9.| (Bitwise OR): Used to compare two numbers in binary, giving a 1 if at least one of the matching bits is 1.
10.^ (Bitwise XOR): Used to compare two numbers in binary, giving a 1 only if the matching bits are different from each other.

#
### Task 5 :
**auto :**
* What is mean by auto ?
-auto is keyword meaning 'automatic type deduction'. It is feature which lets the c++ compiler figure out the data type automatically.
- use cases:
-When types are long and complex.
-For clean and readable code.
-auto keeps the loop declaration clean so you can instantly see what the loop body is doing.  

- When it hurts ?
If the values comes from a function and the name doesnt make the auto forrce  the reader to guess