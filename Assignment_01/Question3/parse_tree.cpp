
#include <iostream>
#include <string>
#include <memory>

// Node structure for parse tree
struct Node {
    std::string symbol;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> middle;
    std::shared_ptr<Node> right;

    Node(std::string s) : symbol(s), left(nullptr), middle(nullptr), right(nullptr) {}
};

// Recursive function to build parse tree for the given grammar and input
std::shared_ptr<Node> buildParseTree(const std::string& input, int start, int end) {
    if (start > end) return nullptr;

    // Base case: substring "10"
    if (end - start + 1 == 2 && input[start] == '1' && input[start + 1] == '0') {
        auto node = std::make_shared<Node>("S");
        node->left = std::make_shared<Node>("1");
        node->middle = std::make_shared<Node>("0");
        return node;
    }

    // Apply S → 1 S 0
    if (input[start] == '1' && input[end] == '0') {
        auto node = std::make_shared<Node>("S");
        node->left = std::make_shared<Node>("1");
        node->middle = buildParseTree(input, start + 1, end - 1);
        node->right = std::make_shared<Node>("0");
        return node;
    }

    // Input cannot be derived from grammar
    return nullptr;
}

// Function to print tree in readable indented format
void printParseTree(const std::shared_ptr<Node>& node, std::string indent = "") {
    if (!node) return;

    std::cout << indent << node->symbol << "\n";
    printParseTree(node->left, indent + "  ");
    printParseTree(node->middle, indent + "  ");
    printParseTree(node->right, indent + "  ");
}

int main() {
    std::string input = "1100";

    auto root = buildParseTree(input, 0, input.size() - 1);

    if (!root) {
        std::cout << "Input string cannot be derived from the grammar.\n";
    } else {
        std::cout << "Parse Tree for input \"" << input << "\":\n";
        printParseTree(root);
    }

    return 0;
}
