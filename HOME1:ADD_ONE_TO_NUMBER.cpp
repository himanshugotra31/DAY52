// Q1. Add One To Number
// Solved
// character backgroundcharacter
// Stuck somewhere?
// Ask for help from a TA & get it resolved
// Get help from TA

// Problem Description

// Given a non-negative number represented as an array of digits, add 1 to the number ( increment the number represented by the digits ).

// The digits are stored such that the most significant digit is at the head of the list.

// NOTE: Certain things are intentionally left unclear in this question which you should practice asking the interviewer. For example: for this problem, following are some good questions to ask :

//     Q : Can the input have 0's before the most significant digit. Or in other words, is 0 1 2 3 a valid input?
//     A : For the purpose of this question, YES
//     Q : Can the output have 0's before the most significant digit? Or in other words, is 0 1 2 4 a valid output?
//     A : For the purpose of this question, NO. Even if the input has zeroes before the most significant digit.



// Problem Constraints

// 1 <= size of the array <= 1000000


// Input Format

// First argument is an array of digits.


// Output Format

// Return the array of digits after adding one.


// Example Input

// Input 1:

// [1, 2, 3]



// Example Output

// Output 1:

// [1, 2, 4]



// Example Explanation

// Explanation 1:

// Given vector is [1, 2, 3].
// The returned vector should be [1, 2, 4] as 123 + 1 = 124.


vector<int> Solution::plusOne(vector<int> &A) 
{
    int n=A.size();                                             //n=number of elements in vector 'A' 
    vector<int> B;                                              //Here we make an another vector 'B' which will not contain the zeroes present on starting of the number if present or we can say it will not contain 0's before the most significant digit.
    int skip=0;                                                 //'skip' will help us to erase only that 0's(zeroes) which are present before the most significant digit.
    for(int i=0;i<n;i++)                                        //this loop will make our vector 'B' or we can say it will make the final number without 0's before the most significant digit.
    {
        if(A[i]==0 and i!=n-1 and skip==0 and A[0]==0)          //this statement will allow us to erase only that 0's(zeroes) which are present before the most significant digit.
        {
            if(A[i+1]!=0)
            {
                skip+=1;
            }
        }
        else                                                    //this statement will push a value in Vector 'B'
        {
            B.push_back(A[i]);
        }
    }
    int m=B.size();                                             //m=number of elements in vector 'B' 
    int i=m-1;                                                  //here we are taking i, it will take the index of last digit of our entire number
    B[i]+=1;                                                    //here we are adding 1 to last digit or at last index
    while(B[i]==10)                                             //here we are using while loop because we want to check if any digit is equal to 10, then we can transfer the carry forward and then see the next digits 
    {                                                           
        if(B[i]==10 and i==0)                                   //this statement will run if our index came to 0 now, then there is no need to make B[0]=0, basically B[0] is first digit of our entire number/array, now we just have to make B[0]=1 and just add one more 0 at the end, because our loop can come to i=0, if only our entire number would be like this 9,99,999,9999,etc.
        {
            B[i]=1;
            B.push_back(0);
        }
        if(B[i]==10 and i!=0)                                   //this statement will run if our index is not equal to first digit i.e. 0, and the A[i]==10, then this statement will make A[i]=0 and and will add 1 to the left side digit i.e. A[i-1]+=1, then it will make i--
        {
            B[i]=0;
            B[i-1]+=1;
            i--;
        }
    }
    return B;                                                    //it will return our final number after adding 1 to it
}