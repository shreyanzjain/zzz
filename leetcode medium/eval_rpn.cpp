/*
Stack 
The concept of a stack, a last-in/first-out construct, 
is integral to the left-to-right evaluation of RPN. 
In the example 3 4 -, first the 3 is put onto the stack, 
then the 4; the 4 is now on top and the 3 below it. 
The subtraction operator removes the top two items from the stack, 
performs 3 - 4, and puts the result of -1 onto the stack.
*/

class Solution {
public:
    void stackEval(stack<int> &eval, char ch){
        int r = eval.top();
        eval.pop();
        int l = eval.top();
        eval.pop();
        switch(ch){
            case '+':   
                eval.push(l + r);
                break;
            case '-':
                eval.push(l - r);
                break;
            case '/':
                eval.push(l / r);
                break;
            case '*':
                eval.push(l * r);
                break;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> eval;
        set<string> operators = {"+", "-", "/", "*"};
        for(int i = 0; i < tokens.size(); i++){
            if(operators.find(tokens[i]) != operators.end()){
                stackEval(eval, tokens[i][0]);
            }   else{
                eval.push(stoi(tokens[i]));
            }
        }
        return eval.top();
    }
};