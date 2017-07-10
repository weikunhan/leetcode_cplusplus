class Solution {
public:
    string getPermutation(int n, int k) {
        int pos = 0;
        vector<string> numbers;
        vector<int> factorial(n + 1);
        string sb;
        stringstream ss;
    
        // create an array of factorial lookup
        int sum = 1;
    factorial[0] = 1;
    for(int i=1; i<=n; i++){
        sum *= i;
        factorial[i] = sum;
    }
    // factorial[] = {1, 1, 2, 6, 24, ... n!}
    
    // create a list of numbers to get indices
    for(int i=1; i<=n; i++){
        numbers.push_back(to_string(i));
    }
    // numbers = {1, 2, 3, 4}
    
    k--;
    
    for(int i = 1; i <= n; i++){
        int index = k/factorial[n-i];
        sb.append(numbers[index]);
        numbers.erase(numbers.begin() + index);
        k-=index*factorial[n-i];
    }
    
    return sb; 
    }
};
