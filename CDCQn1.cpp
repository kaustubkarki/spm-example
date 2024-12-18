#include <stdio.h>
#include <stdbool.h>

void removeComments(const char *code, char *result) {
    bool inSingleLineComment = false;
    bool inMultiLineComment = false;
    int j = 0;

    for (int i = 0; code[i] != '\0'; ++i) {
        if (inSingleLineComment) {
            if (code[i] == '\n') {
                inSingleLineComment = false;
                result[j++] = code[i];
            }
        } else if (inMultiLineComment) {
            if (code[i] == '*' && code[i + 1] == '/') {
                inMultiLineComment = false;
                i++;  // Skip '/'
            }
        } else {
            if (code[i] == '/' && code[i + 1] == '/') {
                inSingleLineComment = true;
                i++;  // Skip '/'
            } else if (code[i] == '/' && code[i + 1] == '*') {
                inMultiLineComment = true;
                i++;  // Skip '*'
            } else {
                result[j++] = code[i];
            }
        }
    }

    result[j] = '\0';
}

int main() {
    const char *code = "#include <stdio.h>\n"
                       "int main() {\n"
                       "    // This is a single-line comment\n"
                       "    printf(\"Hello, World!\\n\"); /* This is a multi-line comment */\n"
                       "    /* This is another\n"
                       "       multi-line comment */\n"
                       "    return 0; // End of program\n"
                       "}\n";

    char cleanedCode[1024];
    removeComments(code, cleanedCode);

    printf("Original code:\n%s\n", code);
    printf("Cleaned code:\n%s\n", cleanedCode);

    return 0;
}

