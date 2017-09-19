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
 Function: Decrypt()
 Functionality: This function acts as an Inverse to the Encrypt() function, performing the reverse operation. The function receives the address location of 'User_Code' and executes the following counter-operations;
 1. Target the Desired 3rd & 4th Digits, hold their values in the Tmp Variable
 2. Overwrite these two Digits with the 1st & 2nd Digits & Place the Temporary Values in the First & Second Digit Locations.
 3. Subtract 1 from each digit & if -1 Values occur overwrite them with 9.
 Argument(s): Integer Array Pointer - 'User_Code' - Encrypted
 Return: Integer Array Pointer - 'User_Code' - Decrypted
 */
int* Decrypt(int* User_Code)
{
    /*Declaring Basic Index & Temporary Value-Holding variables*/
    register int Index;
    int Tmp;
    
    /*Perform a Loop - With the Following Conditions:
     Starting at Element [3], by assigning Index the value 3 (SIZE - 1 = 3)
     Running While Index is greater than -1 (SIZE - 5 = -1)
     And Iteratively Decrementing the Index Variable*/
    for(Index=SIZE-1; Index>SIZE-5; Index--)
    {
        /*Utilising an If Statement to Target Index [2] & [3] - we then perform the follwing statements*/
        if (Index > (SIZE-3) && Index < (SIZE))
        {
            /*Hold the Targeted Value in 'Tmp' Variable*/
            Tmp = *(User_Code + Index);
            
            /*Perform Swap of Values*/
            *(User_Code + Index) = *(User_Code + (Index-2));
            *(User_Code + (Index-2)) = Tmp;
        } //end if
        
        /*Subtract 1 from each Digit*/
        *(User_Code + Index) -= 1;
        
        /*Only If Neccessary Revert any Minus One values to the value of Nine*/
        *(User_Code + Index) = ((*(User_Code + Index))== -1)? 9 : *(User_Code + Index);
    }  //end for
    
    /*Provide User Feedback of the Newly Decrypted Code*/
    printf("The Decrypted Code You Entered is: ");
    
    /*Print out the Code Value*/
    for(Index=0; Index<SIZE; Index++)
    {
        /*Iterate through the 'User_Code' array & print out the value at each location*/
        printf("[%d]", *(User_Code+ Index));
        
    } //end for
    
    /*Return the address of 'User_Code' to Main()*/
    return (User_Code);
    
} //end Decrypt()