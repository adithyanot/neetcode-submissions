class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+" ||tokens[i] == "-"||tokens[i] == "*"||tokens[i] == "/"){
                if(s.empty()){
                    return -1;
                }
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                int result;
                if(tokens[i] == "+"){
                    result = first + second;

                }
                if(tokens[i] == "-"){
                    result = first - second;

                }
                if(tokens[i] == "*"){
                    result = first * second;

                }
                if(tokens[i] == "/"){
                    result = first / second;

                }
                s.push(result);
                
            }else{
                s.push(stoi(tokens[i]));
            }
        }
        int answer = s.top();
        return answer;
        
    }
};
