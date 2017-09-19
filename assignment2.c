/*PROGRAM IDENTIFIER: assignment2.c
PROGRAM SPECIFICATION: (see assignment.pdf documentation)
CREATION DATE: WED 22-02-2017
LAST MODIFIED V1.1 - 19/09/2017 - 15:10 (POST SUBMISSION)
AUTHOR: STEPHEN ALGER
LICENSE: ALL RIGHTS RESERVED © 2017
VERSION IDENTIFIER: 1.1*/

/*Program Information:
This is a 5 option menu driven program which utilises encryption and decryption functionality...
-This program takes in a User's specified 4 digit access code
-Once stored an encryption algorithm is applied
-Subsequently this code is Verified against the official 4 digit (encrypted) access code - array type int
Note: this is a modularised program with multiple functions.
Note: this program utilises pointer notation EXCLUSIVELY.*/

/*---------------------------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------------------------*/

//INTEGRATED LIBRARIES & FILES
#include <stdio.h>
//#include <stdbool.h>

//MULTIPLE FILES USED FOR MODULARISATION &
//DEBUGGING PURPOSES. - NOT REQUIRED IN SUBMISSION
#include "Code_Entry.h"
#include "Encrypt.h"
#include "Verify.h"
#include "Correct_Entry_Tracking.h"
#include "Decrypt.h"
#include "Exit.h"

//SYMBOLIC NAMING SCHEME
#define SIZE 4
#define DEFAULT_CODE 4,5,2,3
#define CONTINUE 'C'
#define CONTINUE_SMALL 'c'
#define YES_LARGE 'Y'
#define YES_SMALL 'y'
#define NO_LARGE 'N'
#define END_PROGRAM 'E'

//FUNCTION PROTOTYPES 
int* Code_Entry(void);
int* Encrypt(int*);
char Verify (int*, int*);
void Correct_Entry_Tracking(int*);
void Tracking_Error_Handling(int*);
int* Decrypt(int*);
char Exit(void);


/*
Function: main()
Functionality: In this C program main() acts as a skeleton function. 
This function operates to output the program menu, tackle menu selections 
and finally to implement a subsequent switch statement to call the neccessary 
sub-functions in this modularly-designed Program.
*/
int main()
{

    //Variable Declarations...
    /*Loop variable used to keep program running, 
    initialised to defined symbolic name - 'CONTINUE'.*/
    char Loop = CONTINUE;
    
    /*Declare switch array with 2 element positions, 
    for Input Validation purposes. Hardcoding Neccessary in this instance.*/
	char Switch_Identifier[2];
	
    /*Declare & initialise the pointer intended, 
    to hold the memory address of User_Code array.*/
    int* User_Code_Ptr = 0;
    
    
    /*Integer which tells the program whether a code
    which is being verified is new or not. This prevents the
    user from Encrypting & Decrypting in a loop - resulting in the
    correct/incorrect counter getting wrongly incremented*/
    int New_Code = 1;
    
    //int Overwrite_Tracking_array;
    //int Tracking_array[4];
    
    /*Declare & intialise the access code using SYMBOLIC NAME - 4,5,2,3. 
    -As per Program Specification.*/
    int access_code[SIZE] = {DEFAULT_CODE};
    
    /*Correct_Counter array is Utilised to count correct and incorrect entries,
    correct in position [0] and correct in position [1], initialise to zero.
    Hardcoding Neccessary in this instance.*/
    int Correct_Counter[2]={0};
    
    /*Declaration of variables to keep track of:
    1. Encryption Status 
    2. Decryption Status
    3. Code Entry Status
    These eliminate cases where for example:
    a user tries to encrypt When they have not entered a code to the program.*/
    int Already_Encrypted = 0;
    int Already_Decrypted = 0;
    int Code_Entered = 0;

    /*Declaration of an important character variable which will act as a buffer-flush system, 
    taking unwanted data out of the buffer.*/
    char Unwanted_Chars;
    
    /*Declare: Variable used to track if code entered is correct, 
    When cross examined with the the 'access_code' array, initialise to '1'.*/
    char Verified = '1';
    
    printf("\nHello, Welcome To This Encryption Service,\nAt The Menu Below Please Use A Number 1 to 5 To Indicate How You Would Like Us To Help You\n");
    
    /*Menu Loop which runs until the Loop Variable 
    has a value other than 'c' or 'C' - SYMBOLIC NAMES USED.*/
    while (Loop == CONTINUE || Loop == CONTINUE_SMALL)
    {
        /*assign & re-assign Switch_Identifier[1] position to '\0', important for menu error checking*/
        *(Switch_Identifier+1) = '\0';
        
        /*Display Menu to User*/
        printf("\nSelect How You Would Like To Utilise This Encryption Service:\n1. ENTER MY 4 DIGIT ACCESS CODE\n2. ENCRYPT MY CODE PREVIOUSLY ENTERED & VERIFY IT\n3. DECRYPT MY PREVIUSLY ENTERED CODE\n4. HOW MANY TIMES HAS MY CODE BEEN ENTERED CORRECTLY & INCORRECTLY?\n5. CLOSE ENCRYPTION SERVICE\n\n");
        
        /*Take in the user's choice*/
        scanf("%2s", Switch_Identifier);
        
        /*Clear the input buffer of any unwanted data*/
        while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
		
        /*Simple error check - Exectute these statements only if the user has entered no more than one digit*/
		if (*(Switch_Identifier+1) =='\0')
		{
			/*Utilise a switch statement using the value found at 'Switch_Identifier[0]'*/
			switch (*(Switch_Identifier+0))
			{
					
				//ENTER CODE
                /*The User has entered the value 1 & Intends to Enter A code to the Program*/
				case '1' :
				{
					/*call the Code_Entry function,
					 returning the address of the error-checked code.*/
					User_Code_Ptr = Code_Entry();
                
                    /*Keep track of Guidance metrics
                    1. Assign 1 to Code_Entered - i.e. There has been a code entered
                    2. Assign 0 to Already_Encrypted - i.e. The code has not been Encrypted
                    3. Assign 0 to Already_Decrypted - i.e. The code has not been Decrypted
                    4. Assign 1 to New_Code - i.e. a new code has been entered.*/
					Code_Entered= 1;
					Already_Encrypted = 0;
					Already_Decrypted = 0;
                    New_Code = 1;
					
					break;
				} //end case 1
					
				//ENCRYPT CODE
                /*The User has entered the Value 2 & Intends to Encrypt a Code*/
				case '2' :
				{
					/*if code has not been encrypted already and a code has actually already been entered*/
					if (Already_Encrypted == 0 && Code_Entered==1)
					{
						/*Call the Encrypt() function, Pass the address of the User_Code array in and Output the newly encrypted array, overwriting the previous contents (the non-encrypted code)*/
						User_Code_Ptr = Encrypt(User_Code_Ptr);
						
                        /*Only Verify if Code is Correct/ Incorrect if this is a New Code*/
                        if (New_Code == 1)
                        {
                            /*Call the Verify() function, Pass in both code arrays - 
                            1. the User_Code correct access_code and 
                            2. the correct access_code. 
                            The Function will Return a char value into 'Verified' which will be later interpreted by the program.*/
                            Verified = Verify(User_Code_Ptr, access_code);
                            
                            /*Conditional (turnary) operator, Correct_Counter[0] counts correct entries,
                             Correct_Counter[1] counts incorrect entries.
                             If the char variable - 'Verified' has the value 'Y' for YES, the correct counter is incremented
                             If not, the user has entered the wrong code and we increment the incorrect array position.*/
                            (Verified == YES_LARGE)? (*(Correct_Counter+0))++ : (*(Correct_Counter+1))++;
                            
                        } //end if
						
						/*Change the decryption tracker to Allow user to be able to decrypt the newly encrypted code*/
						Already_Decrypted = 0;
                        
                        /*Tracking Input - i.e. The code has been encrypted & is no longer a newly entered code*/
                        New_Code = 0;
					} //end if
					
                    /*else if the user has already encrypted - execute these statements*/
					else if (Already_Encrypted == 1)
					{
						/*provide user feedback - A single Code cannot be encrypted more than once.*/
						printf("\nACTION DENIED - You Can Only Encrypt Your Code Once - You Must Decrypt It Before You Can Re-Encrypt It!\n");
					} //end else if
					
                    /*Otherwise the user is trying to encrypt without even entering a code*/
					else
					{
						/*provide user feedback - A code must be entered to be encrypted.*/
						printf("\nACTION DENIED - You Must Enter A Code Before You Can Encrypt!\n");
					} //end else
					
					/*The 'Already_Encrypted' variable changes to 1 i.e. - TRUE*/
					Already_Encrypted =1;
					break;
				} //end case
					
				//DECRYPT CODE
                /*The User has entered the Value 3 & Intends to Decrypt a Code*/
				case '3' :
				{
					/*Check that specific conditions are met:
					 The code has previously been encrypted
					 AND A Code has actually been entered
					 AND The code hasnt already been decrypted*/
					if (Already_Encrypted == 1 && Code_Entered==1 && Already_Decrypted == 0)
					{
						/*Once these conditions have been met
						 The Decrypt() function is called and the User_Code is overwritten with the decrypted code*/
						User_Code_Ptr = Decrypt(User_Code_Ptr);
						
						/*For tracking purposes we change the 'Already_Decrypted' to 1 IE: TRUE*/
						Already_Decrypted = 1;
						
						/*Change the Encryption tracking variable to 0: i.e. 'no longer encrypted'*/
						Already_Encrypted = 0;
						
					} //end if
                
				    /*Execute if the user has already decrypted their code*/
					else if (Already_Decrypted == 1)
					{
						/*Provide user feedback in the case the user tries to decrypt the same code twice.*/
						printf("\nACTION DENIED - You Cannot Decrypt The Same Code Twice Consecutively!\n");
					} //end else if	
                
                    /*Execute if the user has not yet encrypted their code*/
					else if (Already_Encrypted != 1)
					{
						/*Provide user feedback in the case the user tries to decrypt an unencrypted code.*/
						printf("\nACTION DENIED - You Must Encrypt A Code Before You Can Decrypt!\n");
					} //end else if
					
                    /*Execute if the user has not yet entered their code*/
					else if (Code_Entered != 1)
					{
						/*Provide user feedback in the case the user tries to decrypt when no code has been entered.*/
						printf("\nACTION DENIED - You Must Enter A Code Before You Can Decrypt!\n");
					} //end else if
					
					break;
				} //end case
					
				//DISPLAY CORRECT & INCORRECT ENTRIES
                /*The User has entered the Value 4 
                & Wishes to see the number of times the code has been entered - 
                correctly & incorrectly*/
				case '4' :
				{
					/*call the correct/incorrect function tracker,
					 Passing the counter array through.*/
					Correct_Entry_Tracking(Correct_Counter);
					
					break;
				} //end case
					
				//EXIT PROGRAM
                /*The User has entered the Value 5 & Possibly intends to End the Program*/
				case '5' :
				{
					/*This Exit() function asks the user are they sure they want to terminate the program
					 Based on the user's response the program will end or re-run.*/
					Loop = Exit();
					break;
				} //end case
					
                //DEFAULT CASE
                /*The User has made an invalid menu selection*/
				default:
				{
					/*Provide user feedback - if the user enters an invalid menu selection*/
					puts("\nError In Menu Selection, Try Again!");
					break;
					
				} //end default
					
			}//end switch
		} //end out-most if
		
        /*If Data has been entered in the Switch_Identifier[1] position...
        This means that more than one character has been entered - invalid entry*/
		else
		{
            /*provide user feedback*/
			printf("\nError In Menu Selection, Try Again!\n");
            /*iterate the while loop once more i.e. re-output the menu*/
			Loop = CONTINUE;
		} //end else
    } //end while
	
} //end main


