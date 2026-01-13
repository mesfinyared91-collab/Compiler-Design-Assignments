
#include <iostream>
#include <string>
#include <cctype>
#include <unordered_set>

// Function to count identifiers in a C++ source code string
int countIdentifiers(const std::string& source) {

    static const std::unordered_set<std::string> keywords = {
        "int", "float", "double", "char", "bool", "void", "if", "else", "for",
        "while", "do", "return", "break", "continue", "class", "struct",
        "public", "private", "protected", "static", "const", "using",
        "namespace", "new", "delete", "this", "true", "false"
    };

    int count = 0;
    size_t i = 0;

    auto isIdentifierChar = [](char c, bool firstChar) {
        if (firstChar)
            return std::isalpha(c) || c == '_';
        return std::isalnum(c) || c == '_';
    };

    while (i < source.length()) {

        if (std::isspace(source[i])) { i++; continue; }

        // Skip single-line comments
        if (i + 1 < source.length() && source[i] == '/' && source[i + 1] == '/') {
            i += 2; while (i < source.length() && source[i] != '\n') i++; continue;
        }

        // Skip multi-line comments
        if (i + 1 < source.length() && source[i] == '/' && source[i + 1] == '*') {
            i += 2; while (i + 1 < source.length() && !(source[i] == '*' && source[i + 1] == '/')) i++; i += 2; continue;
        }

        // Skip string and character literals
        if (source[i] == '"' || source[i] == '\'') {
            char quote = source[i++];
            while (i < source.length() && source[i] != quote) {
                if (source[i] == '\\') i++; // Skip escape character
                i++;
            }
            i++;
            continue;
        }

        // Detect identifiers
        if (isIdentifierChar(source[i], true)) {
            std::string identifier;
            identifier += source[i++];
            while (i < source.length() && isIdentifierChar(source[i], false)) identifier += source[i++];

            // Count if not a keyword
            if (keywords.find(identifier) == keywords.end()) count++;
            continue;
        }

        i++;
    }

    return count;
}

int main() {
    std::string code = R"(
        int main() {
            int x = 10;
            int y = x + 5;
            int result = x + y;
            return result;
        }
    )";

    std::cout << "Identifiers count: " << countIdentifiers(code) << std::endl;
    return 0;
}
