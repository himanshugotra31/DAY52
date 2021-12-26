vector<int> Solution::totalCoins(int A, vector<vector<int> > &B) {
    vector<int> coins(A, 0);
    for(int i = 0; i < B.size(); i++) {
        int leftIndex = B[i][0] - 1, rightIndex = B[i][1] - 1; 
        int donationByDevotee = B[i][2];
        coins[leftIndex] += donationByDevotee;
        if ((rightIndex + 1) < A) coins[rightIndex + 1] -= donationByDevotee;
    }
    for(int i = 1; i < A; i++) coins[i] = coins[i] + coins[i - 1];
    return coins;
}
