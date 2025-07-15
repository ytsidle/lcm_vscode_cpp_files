#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cctype> // for isalpha, isdigit, isalnum

// 定义一个简单的Token类型来存储标记的类型和值
enum TokenType {
    IDENTIFIER, // 标识符，例如变量名
    NUMBER,     // 数字
    OPERATOR,   // 操作符，如 +, -, *, /
    UNKNOWN     // 未知类型
};

struct Token {
    TokenType type;
    std::string value;
};

// 词法分析函数
std::stack<Token> tokenize(const std::string& input) {
    std::stack<Token> tokens;
    size_t i = 0;

    while (i < input.length()) {
        if (std::isspace(input[i])) {
            // 跳过空白字符
            i++;
        } else if (std::isalpha(input[i])) {
            // 处理标识符
            std::string identifier;
            while (i < input.length() && std::isalnum(input[i])) {
                identifier += input[i++];
            }
            tokens.push({IDENTIFIER, identifier});
        } else if (std::isdigit(input[i])) {
            // 处理数字
            std::string number;
            while (i < input.length() && std::isdigit(input[i])) {
                number += input[i++];
            }
            tokens.push({NUMBER, number});
        } else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
            // 处理操作符
            std::string op(1, input[i]);
            tokens.push({OPERATOR, op});
            i++;
        } else {
            // 处理未知字符
            std::string unknown(1, input[i]);
            tokens.push({UNKNOWN, unknown});
            i++;
        }
    }

    return tokens;
}

// 打印栈中的所有标记
void printStack(std::stack<Token> tokens) {
    while (!tokens.empty()) {
        Token token = tokens.top();
        tokens.pop();
        std::cout << "Token(Type: " << token.type << ", Value: '" << token.value << "')\n";
    }
}

int main() {
    std::string input;
    std::cout << "command:";
    std::getline(std::cin, input);

    // 进行词法分析
    std::stack<Token> tokens = tokenize(input);

    // 打印分析结果
    printStack(tokens);

    return 0;
}
