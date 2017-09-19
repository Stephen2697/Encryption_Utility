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
 Function: Verify()
 Functionality: Take in the 'User_Code' and 'access_code' arrays. Then Utilise a For Loop to cross check these for a state of equality. The Function will then Return the correct result to Main() of this cross-equality comparison.
 Argument(s): Two Integer-Array Pointers; 1. 'User_Code' 2. 'access_code'
 Return: One Character Variable with a Binary style Value - 'Y' or 'N' - To symbolise whether the User's Code has been verified - 'Yes or No'.
 */
char Verify (int* User_Code, int* access_code)
{
    /*Index and Error-Checking Variable Declartions*/
    register int Index;
    
    /*Correct_counter acts as a counter which is incremented when individual array locations are equal,
     If This counter equals 4 the 'User_Code' is Deemed Correct, if not it is deemed incorrect in this program.*/
    int Correct_counter=0;
    
    /*Verified char variable is assigned characters 'N' or 'Y' via SYMBOLIC NAMING,
     It is initialised to 'N' - i.e. the Code has not been Verified*/
    char Verified = NO_LARGE;
    
    /*Conduct Verification via Loop*/
    for(Index=0; Index<SIZE; Index++)
    {
        /*If corresponding array positions equal, increment the Correct_counter variable,
         Otherwise iterate the Loop.*/
        if ((*(User_Code+Index)) == (*(access_code+Index)))
        {
            /*Incrementation*/
            Correct_counter++;
            
        } //end if
    } //end for
    
    /*Following the For Loop, If the Correct_counter equals 4 - The code has been Verified*/
    if (Correct_counter==4)
    {
        /*Assign 'Verified' the value 'Y' via SYMBOLIC NAMING to indicate Successful Verification*/
        Verified = YES_LARGE;
        
        /*Output Appropriate User Feedback*/
        printf("\nCORRECT CODE - You Have Entered The Correct Access Code, Welcome!\n");
    } //end if
    
    else
    {
        printf("\nERROR CODE - You Have Entered The Incorrect Access Code, You Can Decrypt This Code Or Try Again From The Main Menu.\n");
    } //end else
    
    /*Return to Main() - the Char Variable 'Verified' which is Designed to Contain 'Y' or 'N' characters in accordance to the SYMBOLIC NAMING SCHEME*/
    return(Verified);
    
} //end Verify()