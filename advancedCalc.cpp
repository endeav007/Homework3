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

using namespace std;

int validateUserInput(char array[], int size);
bool checkIfStandardOperation(char array[], int size);
int main(){

    //Variables
    char userInput[100];
    int size = 0;
    bool tooBig = false;

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