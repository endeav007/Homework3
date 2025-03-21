/*
* Autumn Austin
* CYB220 Homework 3
*
*/

#include <iostream>
#include <stdio.h>
#include <limits>
#include <climits>
#include <ctype.h>
#include <string>

using namespace std;

int validateUserInput(char array[], int size);
bool checkIfStandardOperation(char array[], int size);
int standardOperation(char array[], int size);
int specialOperation(char array[], int length);

int main(){

    //Variables
    char userInput[100];
    int size = 0;
    bool tooBig = false;


    /*

    cout << "Enter in your operation: "; 
    //Gets input from stdin

    
    fgets(userInput, sizeof(userInput), stdin);
    

    for(int i = 0; i < 100; i++){
        if(userInput[i] == '\n'){
            break;
        }
        size++;
    }
    cout << "Size is: " << size << endl;


    if(validateUserInput(userInput, size) == 0){
        cout << "Exiting due to issues with your input..." << endl;
        exit(1);
    }
    else
    {
        cout << "Your input was great!";
    }

    */

    char arr[] = {'1', '0', '+', 'A', 'B'};
    char arr2[] = {'2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '+', '3' , '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    char arr3[] = {'7', '7', '7', '7', '7', '*', '1', '0', '0', '0', '0', '0' };

    //standardOperation(arr3, 12);
    specialOperation(arr, 5);


    

    

    

}


// This fuction checks our user input to ensure we're only including numbers, letters, and a single operator
int validateUserInput(char array[], int size){
    bool foundOperator = false;
    
    if(!isalnum(array[0]) || !isalnum(array[size-1])){
        cout << "Operator must be in between two operands." << endl;
        return 0;
    }
    for(int i = 0; i < size; i++)
    {
        if( (array[i] == ' ') || ( !isalnum(array[i])) )
        {
            //checks if the symbol is a legal operation symbol, and if we haven't come across an operator yet 
            if(array[i] == ' '){
                cout << "Spaces are not allowed. Remove the space, then change your input." << endl;
                return 0;
            }
            else if( ((array[i] == '+') || (array[i] == '-') || (array[i] == '/') || (array[i] == '*') || (array[i] == '%') ) && (foundOperator == false))
            {
                cout << "allowed operator" << endl;
                foundOperator = true;
            }
            else if(foundOperator == true) // we should only have one operator per operation
            {
                cout << "You can only indicate one operator per operation! Remove the extra operator, and try again. " << endl;
                return 0;

            }
            else
            {
                cout << "You have an illegal operator in your input. Remove it, and try again." << endl;
                return 0;

            }
            
        }
    }
    return 1; 


}

// this will check what type of operation we're doing, assuming our user input is valid. 
bool checkIfStandardOperation(char array[], int size){

    bool foundOperator = false;
    int index = 0;
    int digitAmt = 0;
    int alphaAmt = 0;
    while(!foundOperator)
    {
        if(isdigit(array[index]))
        {
            digitAmt++;
        }
        else if(isalpha(array[index])){
            alphaAmt++;
        }
        else if(!isalnum(array[index]))
        {
            foundOperator = true;
        }
        index++;
    }
    

    if(alphaAmt > 0){
        if(isalpha(array[index])){
            cout << "Cannot have more than one string operand. Re-try your input." << endl;
            exit(1);
        }else{
            //cout << "nonstandard op";
            return false; // meaning we'll have a non standard operation with letters 
        }
        
    }
    else if (digitAmt > 0){
        if(isalpha(array[index])){
            //cout << "nonstandard op";
            return false; // we'll be dealing with letters 
        }else{
            //cout << "standard op";
            return true;
        }

    }

    return false;
}

int standardOperation(char array[], int size){
    string operand1 = "";
    string operand2 = "";
    char op;
    int opIndex = 0;
    int result;
    int num1;
    int num2;

    //will add each char to operand1, and stop once we find the operator index
    while(isdigit(array[opIndex]))
    {
        operand1 = operand1 + array[opIndex];
        opIndex++;
    }

    cout << opIndex << endl;
    cout << operand1 << endl;
    op = array[opIndex];
    cout << op << endl;

    opIndex++;

    //grabs the rest of the number
    while(opIndex < size)
    {
        operand2 = operand2 + array[opIndex];
        opIndex++;
    }
    
    cout << operand2 << endl;

    if( (operand2.length() >= 10) ||  (operand1.length() >= 10) ){
        cout << "Your input is too big and could cause overflow. Ending program." << endl;
        exit(1);

    }
    num1 = stoi(operand1);
    num2 = stoi(operand2);

    if(op == '+')
    {
        if (((num1 > 0) && (num2 >0) && (num1 > (INT_MAX - num2)))|| ((num1 < 0) && (num2 <0) && (num1 < (INT_MIN - num2))))
        {
            cout << "This addition will cause integer overflow! Ending program." <<endl;
	        exit(1);
        }
        else 
        {
            result = num1+num2;
            //cout << "The sum of integer1 and integer2 is: " << result <<endl;
            return result;
        }
        
    }
    else if(op == '-')
    {
        if(( ( (num1 > 0) && (num2 < 0) ) && ( (num1 > (INT_MAX - num2)) && num2 < (INT_MIN - num1)) || ( (num1 > 0) && (num2 < 0) ) && (num1 < (INT_MIN - num2) ) && num2 < (INT_MIN - num1 ) ))
        {
            cout << " Integer overflow!" << endl;
            exit(1);
        }
        else
        {
            result = num1-num2;
            //cout << "difference of integer1 and integer2 is: " << result << endl;
            return result;
        }
    }
    else if(op == '*')
    {
        if( ((num1 > (INT_MAX - num2)) || (num2 > (INT_MAX - num1)) ) || (((num1 - num2) < 0) || ((num2 - num1) < 0)))
        {
            cout << "This multiplication will cause integer overflow! Ending program." << endl;

        }
        else
        {
            result = num1*num2;
            //cout << "the mult of integer1 and integer2 is: " << result << endl;
            return result;

        }
    }
    else if (op == '/')
    {
        if((num2 == 0)){
            cout << "Cannot divide by zero. Ending program." << endl;
            exit(1);
          }
          else if ((num1 < (INT_MIN - num2)) && (num2 < 0) )
          {
            cout << "Integer Overflow!" << endl;
            exit(1);
          }
          else
          {
            result = num1/num2; 
            //cout << "The ratio of integer1 and integer2 is: " << result <<endl;
            return result;
        
          }
    }
    else if(op == '%')
    {
        if(num2 == 0){
            cout << "Mod by zero is not allowed. Ending program." << endl;
            exit(1);
        }
        else if ((num1 < (INT_MIN - num2)) && (num2 < 0)){

            result = num1%num2; 
            //cout << "The mod of integer1 and integer2 is: " << result <<endl;
            return result;

        }

    }

    return 0;

}

int specialOperation(char array[], int length)
{
    char stringArray[100] = {};
    string numString = "";
    char op;
    int opIndex;
    int num;
    
    //loop to locate the
    for(int i = 0; i < length; i++)
    {
        if( !isalnum(array[i]))
        {
            op = array[i];
            opIndex = i;
            break;
        }
    }

    //grabbing first operand before operator and ensuring it's a valid type

    for(int i = 0; i < opIndex; i++)
    {
        if(i == 0)
        {
            if(isdigit(array[i]))
            {
               numString = numString + array[i]; 

            }
            else if(isalpha(array[i]))
            {
                stringArray[i] == array[i];
            }
        }
        else
        {
            if(isdigit(array[i]) && isdigit(array[i-1]))
            {
               numString = numString + array[i]; 

            }
            else if(isalpha(array[i]) && isalpha(array[i-1]))
            {
                stringArray[i] == array[i];
            }
            else
            {
                cout << "Your operands are invalid and contain mixed input. Ending program." << endl;
                exit(1);
            }
        }

    }


    for(int i = opIndex+1; i < length; i++)
    {
        if(i == opIndex+1)
        {
            if(isalpha(array[i]) && isalpha(array[0])){
                cout << "Input can't have more than one string operand. Exiting. " << endl;
                exit(1);
            }
            if(isdigit(array[i]))
            {
               numString = numString + array[i]; 

            }
            else if(isalpha(array[i]))
            {
                stringArray[0] == array[i];
            }
        }
        else
        {
            if(isdigit(array[i]) && isdigit(array[i-1]))
            {
               numString = numString + array[i]; 

            }
            else if(isalpha(array[i]) && isalpha(array[i-1]))
            {
                stringArray[i - opIndex] == array[i];
            }
            else
            {
                cout << "Your operands are invalid and contain mixed input. Ending program." << endl;
                exit(1);
            }
        }

    }

    num = stoi(numString);

    if(op == '+')
    {
        
        

    }

    // example of how we can adjust char values and integers
    cout << char (int('a') + 3) << endl;
    return 0;
}

