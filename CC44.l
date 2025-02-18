%option noyywrap
%{
    #include <stdio.h>

    int digit = 0;
    int up = 0;
    int low = 0;
    int sym = 0;
    int length = 0;
%}

%%

[a-z]+      { low++; length++; }
[A-Z]+      { up++; length++; }
[0-9]+      { digit++; length++; }
[* ,;#$@]   { sym++; length++; }

\n  { 
    if (low > 0 && up > 0 && sym > 0 && digit > 0 && length >= 9 && length < 15) {
        printf("Valid Password\n");
    } else {
        printf("Invalid Password\n");
    }
    low = up = digit = sym = length = 0;  
}

%%

int main() {
    printf("Enter string: ");
    yylex();
    return 0;
}
