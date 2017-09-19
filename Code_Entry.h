//SYMBOLIC NAMING SCHEME
#define SIZE 4
#define DEFAULT_CODE 4,5,2,3
#define CONTINUE 'C'
#define CONTINUE_SMALL 'c'
#define YES_LARGE 'Y'
#define YES_SMALL 'y'
#define NO_LARGE 'N'
#define END_PROGRAM 'E'

/*
Function: Code_Entry()
Functionality: Take In The User's Code Input, Looping until a Valid Code is entered. This is achieved through Input Formatting, 4 Digit Validation and Appropriate Error Feedback systems. This Function Operates Two Arrays, The First of Which is the character 'user_input' array and the second of which is an integer 'User_Code' array. The Function Converts entry from data type Char-Int only when A Valid code is enetered and transfers this Verified Code from 'user_input' into the 'User_Code' array.
Argument(s): None - Void.
Return: Integer Pointer - to the memory location of the validated Code Entry.
 */
int* Code_Entry(void)
{
    /*declare local variables required by function*/
    /*Loop Index variable...*/
    register int Index;
    
    /*Error checking variable, It will have three desired states;
     State One: 'Zero Value State' - No illegal entries have been made,
     State Two: 'One Value State' - Characters entered are NOT Digits,
     State Three: 'Two Value State' - Too Many Characters have been entered.
     State Four: 'Three Value State' - Too Few Characters have been entered.*/
    int illegal_entry_checker;
    
    /*Character Array takes in a MAXIMUM of 5 values from the User,
     This is a holding array used for Entry Validation only.
     The 5th element of the array is designed to maintain the 'NULL Terminating' Value of '\0',
     if this value changes we can assess that the user has entered too many characters.*/
    char user_input[SIZE+1];
    
    /*Used Throughout program to remove unwanted data from the input buffer*/
    char Unwanted_Chars;
    
    /*Finally the User's Correct code entry will be transferred to this array
     and this will be returned out of the function. Declared as Static int to allow the array to retain
     it's values even when the function is exited.*/
    static int User_Code[SIZE];
    
    /*do while Loop utilised to run atleast once and keep running until the User enters a Valid Code.*/
    do
    {
        /*Initialise & RE-Initialise the 4th & 5th element to '\0' for Error Checking Purposes*/
        *(user_input+SIZE) = *(user_input+(SIZE-1)) = '\0';
        /*Initialise & RE-Initialise the Entry-Checking variable to 0.*/
        illegal_entry_checker = 0;
        
        /*Prompt the User to Enter their Code*/
        printf("\nPlease Enter Your 4 Digit Access Number...\n");
        
        /*---Key Design Decision---*/
        /*This program Inputs the User's Code as a String into memory,
         Utilising Scanf to format the entry to take in a MAXIMUM 5 Charcter String
         Using an EXTRA element position to detect too many digit inputs*/
        scanf("%5s", user_input);
        
        /*Clear the input buffer of excess character entries until newline character or EOF is reached*/
        while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
        
        /*If the user has entered too many characters the 5th location will no longer equal '\0'*/
        if (*(user_input+SIZE)!= '\0')
        {
            /*Triggering State Three: 'Two Value State' - Too Many Characters have been entered.*/
            illegal_entry_checker = 2;
        } //end if
        
        /*If the user has entered too few characters the 4th location will no longer equal '\0'*/
        if (*(user_input+(SIZE-1)) == '\0')
        {
            /*Triggering State Four: 'Three Value State' - Too Few Characters have been entered.*/
            illegal_entry_checker = 3;
        } //end else if
        
        /*Otherwise we validate that each character in the User_input string is a Digit*/
        else
        {
            /*For Loop utilised to check each of the desired array positions*/
            for(Index=0; Index<SIZE; Index++)
            {
                /*Turnary Operator (Conditional Operator) - if a character is less than or greater than the ASCII value for '0'-48 and '9'-57...
                 The Error Checking variable will be assigned the value 1 - Triggering State Two: 'One Value State' - Characters entered are NOT Digits,
                 Otherwise no changes will be made.*/
                illegal_entry_checker = (*(user_input + Index)<48 || *(user_input + Index)>57 )? 1 : illegal_entry_checker;
                
            } //end for
        } //end else
        
        /*Comprehensive Feedback System - The Program Clearly Communicates the Inaccuracy in the user's entry*/
        if (illegal_entry_checker!=0)
        {
            /*Dealing With - State Two: 'One Value State' - Characters entered are NOT Digits*/
            if (illegal_entry_checker == 1)
            {
                printf("\nInput Error - There Has Been Atleast One Illegal Character Entered, Please Try again...\nEnter The Four Digits Of Your Access Code & Select Enter Afterwards\n");
            } //end if
            
            /*Dealing With - State Three: 'Two Value State' - Too Many Characters have been entered.*/
            else if (illegal_entry_checker == 2)
            {
                printf("\nInput Error - There Have Been Too Many Characters Entered, Please Try again...\nEnter The Four Digits Of Your Access Code & Select Enter Afterwards\n");
            } //end else if
            
            /*Dealing With - State Four: 'Three Value State' - Too Few Characters have been entered.*/
            else if (illegal_entry_checker == 3)
            {
                printf("\nInput Error - Too Few Characters entered, Try again...\nEnter The Four Digits Of Your Access Code & Select Enter Afterwards\n");
            } //end else if
        } //end if
        
    } /*Loop Continues Until the Program returns State One: 'Zero Value State' - No illegal entries have been made */
    while (illegal_entry_checker!=0);
    
    /*Basic User feedback to provide notification of Successful Input*/
    printf("\nYour Code Has Been Successfully Receieved as: ");
    
    /*Once these Code Statements Have been reached the program will Convert & Transfer the Code-Holding 'user_input' array to the Specified integer array 'User_Code'*/
    for(Index=0; Index<SIZE; Index++)
    {
        /*Pointer Notation Utilised for Transferring The User's Code - In Accordance with Program Specification.*/
        /*Conversion from Character ASCII to Integer is Achived by Subtracting The ASCII Value of Zero from each Digit Entered by the User.*/
        *(User_Code +Index) = *(user_input + Index) - 48;
        
        /*Program Outputs the Code they Entered for User's Benefit - to demonstrate successful input*/
        printf("[%d]", *(User_Code +Index));
        
    } //end for
    
    /*As Specified this function returns the pointer to the 'User_Code' Array to Main()*/
    return (User_Code);
} //end Code_Entry()