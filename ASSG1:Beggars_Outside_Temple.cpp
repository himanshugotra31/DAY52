// There are N (N > 0) beggars sitting in a row outside a temple. Each beggar initially has an empty pot. When the devotees come to the temple, they donate some amount of coins to these beggars. Each devotee gives a fixed amount of coin(according to his faith and ability) to some K beggars sitting next to each other.

// Given the amount donated by each devotee to the beggars ranging from i to j index, where 1 <= i <= j <= N, find out the final amount of money in each beggar's pot at the end of the day, provided they don't fill their pots by any other means.

// Example:

// Input:
// N = 5, D = [[1, 2, 10], [2, 3, 20], [2, 5, 25]]

// Return: [10, 55, 45, 25, 25]

// Explanation:
// => First devotee donated 10 coins to beggars ranging from 1 to 2. Final amount in each beggars pot after first devotee: [10, 10, 0, 0, 0]

// => Second devotee donated 20 coins to beggars ranging from 2 to 3. Final amount in each beggars pot after second devotee: [10, 30, 20, 0, 0]

// => Third devotee donated 25 coins to beggars ranging from 2 to 5. Final amount in each beggars pot after third devotee: [10, 55, 45, 25, 25]



vector<int> Solution::solve(int A, vector<vector<int> > &B) 
{
    long int D=B.size();                 //number of devotees
    vector<int> raw;                     //initialised an array 'raw' which will help to make our prefix sum array which will carry number of coins a beggar have at the beginning of the day
    for(long int i=0;i<A;i++)
    {
        raw.push_back(0);                //initialised every element of array 'raw' with 0, since number of coins at the begining of day are 0
    }
    int x=0;                            
    while(D>0)                          //B[x][2]: Total number of coins given bye the devotee
    {                                   //B[x][1]: till where a devotee give the coins
                                        //B[x][0]: from where a devotee start to give coins
                                        //Here the input we are getting there the array starts from 1 to N and in our array in code it is from O to N-1.

        raw[B[x][0]-1]+=B[x][2];        //this line is adding coins at the starting index of the sub-array
        if((B[x][1]-1)!=A)              //this line is subtracting coins from the end+1 index of the sub-array
        {                               
            raw[B[x][1]]-=B[x][2];
        }
        x++;
        D--;
    }
    vector<int> ans;                     //initialised an array 'ans' which is a prefix sum array and will carry final number of coins a beggar have at the end of the day
    ans.push_back(raw[0]);
    for(long int i=1;i<A;i++)
    {
        ans.push_back(raw[i]+ans[i-1]);
    }
    return ans;
}

