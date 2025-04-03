%{
#include <stdio.h>
#include <stdlib.h>
void yyerror(char *s);
int yylex(void);
int valid = 1;  // Flag to track validity
int declaration_count = 0;  // Count valid declarations
%}

%token INT FLOAT CHAR DOUBLE IDENTIFIER NUMBER SEMICOLON COMMA ASSIGN

%%

program:
    declaration_list
    {
        if (valid) {
            printf("\nAnalysis complete: %d valid declaration(s) found\n", declaration_count);
        } else {
            printf("\nAnalysis complete: Invalid declarations detected\n");
        }
    }
    ;

declaration_list:
    declaration
    | declaration_list declaration
    ;

declaration:
    type specifier_list SEMICOLON
    {
        declaration_count++;
        printf("Valid declaration found\n");
    }
    ;

type:
    INT
    | FLOAT
    | CHAR
    | DOUBLE
    ;

specifier_list:
    specifier
    | specifier_list COMMA specifier
    ;

specifier:
    IDENTIFIER
    | IDENTIFIER ASSIGN NUMBER
    ;

%%

void yyerror(char *s) {
    valid = 0;  // Set flag to invalid on any error
    fprintf(stderr, "Invalid declaration: %s\n", s);
}

int main() {
    printf("Enter C variable declarations (Ctrl+D to end):\n");
    yyparse();
    return 0;
}
