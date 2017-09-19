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
 Function: Exit()
 Functionality: Handles the User's selection to End Program. The program confirms the Exit command given by the user.
 Argument(s): None. Void.
 Return: Character Variable used in a Binary Style, this variable is designed to have one of two values, 'E' or 'C' i.e. to Exit or Continue Respectively.
 */
char Exit(void)
{
    /*Character Variable Declarations*/
    /*End_condition deals with The User's preference to terminate the program*/
    char End_condition;
    
    /*Unwanted_Chars deals with possible instances of unwanted user input*/
    char Unwanted_Chars;
    
    /*Prompt the User to Confirm Termination or Continue Running the program*/
    printf("\nAre You Sure You Want To Exit this Prorgam?\nType The Character 'Y' for Yes Or 'N' for No\n");
    
    /*Take in the User's Preference*/
    scanf("%c", &End_condition);
    
    /*clear the input buffer to avoid unwanted data input from user*/
    while ((Unwanted_Chars = getchar()) != '\n' && Unwanted_Chars != EOF );
    
    /*If the user wishes to terminate the program the following code is executed*/
    /*Note - SYMBOLIC NAMING USED - SEE TOP OF FILE*/
    if (End_condition == YES_LARGE || End_condition == YES_SMALL)
    {
        /*Output the program's course of action to gracefully terminate to the user*/
        printf("\nEncryption Service Ending, Come back soon!\n");
        
        /*Return the Character 'E' - SYMBOLIC NAME USED*/
        return(END_PROGRAM);
    } //end if
    
    /*Otherwise - Continue Program*/
    else
    {
        /*Output the program's continuation to the user*/
        printf("\nExit Cancelled\n");
        
        /*Return the Character 'C' - SYMBOLIC NAME USED*/
        return (CONTINUE);
    } //end else
    
} //end Exit()