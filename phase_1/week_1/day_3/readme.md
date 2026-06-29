# Day 3 — Control flow

## Today's Tasks  
* Explain all control loops
* Write a menu-driven program using switch  
* Nested if-else for robot state detection (idle/moving/fault)  
* Use range-based for on an initializer list  
* Practice break/continue with a search loop  
* Task: simulate a countdown timer that skips multiples of 3 and stops at fault code 7

--- 
## Task 1 : Explain all control loops

### Topics Covered

- if : if is a conditional statement with a single condition which is generally used for passing the standalone condition.  
Syntax : if (condition){ // Code to execute if the condition is true}  
Ex : if (robot_sens == True ){std::cout<<"Robot Sensor is on"}
- if-else : If-else is a conditional statement with dual conditions or options, Where one condition must be satisfied.  
Syntax :  if (condition){ // Code to execute if the condition is true ;} else{// Code to execute if the condition is false}
Ex: if (num1 > 0){std::cout<<"Number is Positive} else(num1 < 0){std::cout<<"Given Numbner is negative}
- else-if : Else-if is an upgraded version of if-else, it is used where we have multi conditions, that is, more than two conditions with the given parameter.   
Syntax:  if (condition_1){ // Code to execute if the condition is true ;} else if (condition_2) {// Code to execute if the condition 2 is True}
- switch : It is similar to if..else conditions, it makes structure more readable and structured. It is mostly used for single parameter checked across multiple parameter.  
Syntax: switch(expression){ case value1: //code to executed if its true; break;  case value2: //code to executed if its true; break; default:// Code to execute if expression matches no cases; break;} 
- for loop : For loop is control flow statement which is used to repeat the block of code for predetermined number of times(which is given along with the initialization)  
Syntax: for(Initialization; Expression/condition; Update )  
Ex: printing 1-10 numbers: for (int i = 1;i<=10;i++){std::cout<<i<<" " }
- while loop : While loop is similar to for loop and is also used repeating the block of code. The difference is that, in for loop we know the exact number of iterations but in while loop we dont have any exact iteration it is more of condition-based rather than going alone.  
Syntax: while(condition){ //Code to execute if the condition is true}
Ex: while(sens1=1){std::cout<<:"This line will be printing continuously until the condition gets false !}  
- do-while loop :The only diff between them is do-while will atleast once execute once regardless of condition.
syntax: do {
    // Code to execute
} while (condition); 

Think of those three loops in following ways:
1. For loop: Its used when no. of iterations are known.
2. While loop: It is used when the no. of iterations are not known.
3. Do-While loop: Used when the loop must execute at least once.  

- break : Break is the feature or you can say its a command which helps us to terminate system. After passing break  statement we have to close and terminate the full process.
- continue : Continue is the command which helps us to skip any particular iterations.  


- Switch : Switch is the conditional statement which is used wen multiple if-else cases are to be checked for any one(generally)or more parameter.
Syntax:
switch (expression){
    case value_1:{
       ##Block of code to be executed if this case is true
       break;
    }
    case value_2:{
         ##Block of code to be executed if this case is true
         break;
    }
    default:
        ##Block of code to be executed if none of the case satisfies
         break;

}
---

## Task 2 :  Write a menu-driven program using switch  

### Here is the [program](code1.cpp) for printing the action of the robot based on the input commands.
This particular exercise is added to understand the working of  switch conditions.  
Requirements are as follows:  
1 - Move Forward  
2 - Move Backward  
3 - Turn Left  
4 - Turn Right  
5 - Stop  
When user types the number it should perform the above action(For now I am just printing the commands) respectively.


## Task 3 : Nested if-else for robot state detection (idle/moving/fault)
### Inputs to be taken : 
#### To Determine the state of the robot while taking inputs of following parameters
- Battery Level
- Motor Status
- Fault Flag 

What does this exercise showcase or tells us ?
This Exercise helps us to understand what is the use case and exactly how to implement a nested loop. In the nested if -else loop the working of inner layer depends on the outer layer