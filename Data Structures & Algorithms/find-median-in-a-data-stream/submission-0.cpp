class MedianFinder {
    vector<int> numbers;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        for(int i=0;i<numbers.size();i++){
            if(num<=numbers[i]){
                numbers.insert(numbers.begin()+i,num);
                return;
            }
        }
        numbers.push_back(num);

        
    }
    
    double findMedian() {
        int n = numbers.size();
        if(n&1){
            int index = n/2;
            return numbers[index];
        }else{
            int i1 = (n-1)/2;
            int i2 = (n+1)/2;
            double res = (double)(numbers[i1] + numbers[i2])/2;
            return res;
        }
        
    }
};
