%option noyywrap

%%
"int"|"char"|"return"|"if"|"else"|"while"|"for"|"do"|"break"|"continue" { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9]* { printf("Identifier: %s\n", yytext); }
[0-9]+ { printf("Constant: %s\n", yytext); }
[0-9]+\.[0-9]+ { printf("Constant: %s\n", yytext); }
"//".* { }
"/*"[^*]*"*/" { printf("Comment: %s\n", yytext); }
"+"|"-"|"*"|"/"|"%"|"="|"=="|"!="|"<"|">"|"<="|">="|"&&"|"||"|"++"|"--" { printf("Operator: %s\n", yytext); }
[\(\)\{\}\[\];,] { printf("Punctuation: %s\n", yytext); }
[ \t\n]+ ;
[0-9@$%][a-zA-Z0-9_]+[@#$%]* { printf("Invalid identifier: %s\n", yytext); }

%%

#include <stdio.h>

extern FILE *yyin;  

int main(int argc, char *argv[]) {
    if (argc > 1) {  
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("Error: Cannot open file %s\n", argv[1]);
            return 1;
        }
    }
    yylex(); 
    fclose(yyin);
    return 0;
}
