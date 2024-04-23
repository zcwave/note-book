// @Author : Sugar
// @Created Time : 2022-04-14 20:35:13
// @Description :

#include <stack>
#include <cctype>
#include <iostream>
using std::cin;
using std::cout;

void helpCommand();
void applyOperator(char op, std::stack<double> &operandStack);

int main(int argc,char **argv){
    cout << "RPN Calculator Simulation (type H for Help)" << std::endl;
    std::stack<double> operandStack;
    while (true){
        std::string line;
        cout << "> ";
        getline(cin, line);
        if (line.length() == 0)
            line = "Q";
        char ch = std::toupper(line[0]);
        if (ch == 'Q') break;
        else if (ch == 'H') helpCommand();
        else if (std::isdigit(ch)) operandStack.push(std::stod(line)); 
        else applyOperator(ch, operandStack);
    }
    return 0;
}


void applyOperator(char op, std::stack<double> &operandStack){
    double result;
    double rhs = operandStack.top(); 
    operandStack.pop();
    double lhs = operandStack.top();
    operandStack.pop();
    switch (op){
      case '+': result = lhs + rhs; break;
      case '-': result = lhs - rhs; break;
      case '*': result = lhs * rhs; break;
      case '/': result = lhs / rhs; break;
      default:break;
    }
    cout << result << std::endl;
    operandStack.push(result);
}

void helpCommand(){
    cout << "haha ...to be continue.." << std::endl;
}
