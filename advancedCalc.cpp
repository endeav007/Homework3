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
int main(){

    //Variables
    char userInput[100];

    cout << "Enter in your operation: "; 
    //Gets input from stdin
    fgets(userInput, sizeof(userInput), stdin);
    int size = 0;

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