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
 Function: Encrypt()
 Functionality: This Function Operates to satisfy the Program Requirements for Code Encryption. To Acheieve this The previously validated Access Code undergoes the Encryption algorithm. Firstly Digits 1 & 2 are swapped with Digits 3 & 4 Respectively. Secondly Each Digit is Increased By 1. Thirdly if a Digit reaches the Value of 10 - reset it to Zero.
 Argument(s): Integer Pointer to the Validated User_Code
 Return: Integer Pointer to the ENCRYPTED & Validated User_Code
 */
int* Encrypt(int* User_Code)
{
    /*Declare necessary Index & Temporary Holding Variables*/
    register int Index;
    int Tmp;
    
    /*Provide User Feedback*/
    printf("\nYour Code Has Been Succesfully Encrypted To: ");
    
    /*Implement Encryption Algorithm to each position in Loop*/
    for(Index=0; Index<SIZE; Index++)
    {
        /*Target Swap the First two digits... *(User_Code + 0) & *(User_Code + 1)
         While Index is less than 2 - 'INDEX < (SIZE-2)'.*/
        if (Index < (SIZE-2))
        {
            /*Ytilise a temporary variable to hold initial values, to facilitate swap*/
            Tmp = *(User_Code + Index);
            
            /*Execute Swap*/
            *(User_Code + Index) = *(User_Code + (Index+2));
            *(User_Code + (Index+2)) = Tmp;
        } //end if
        
        /*Increment each digit*/
        *(User_Code + Index) += 1;
        
        /*Conditional (turnary) Operator implemented to deal with cases of digits equaling '10'*/
        *(User_Code + Index) = ((*(User_Code + Index))== 10)? 0 : *(User_Code + Index);
        
        /*Provide User feedback - Output Each Encrypted Digit One by One*/
        printf("[%d]", *(User_Code +Index));
        
    } //end for
    
    /*Output the Newly Encrypted Code Array Pointer to Main()*/
    return (User_Code);
} //end Encrypt()