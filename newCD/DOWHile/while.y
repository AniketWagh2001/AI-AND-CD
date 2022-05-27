%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%token ID NUM DO LE GE EQ NE OR AND WHILE
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE
%left '+''-' INCR DECR
%left '*''/'
%right UMINUS
%left '!'
%%
S : ST {printf("Input accepted.\n");exit(0);};

ST : DO '{' ST1';''}' WHILE '(' E2 ')';
| WHILE'(' E2 ')' '{' ST1 ';''}';

ST1 : ST
| E

;
E : ID'='E
| E'+'E
| E'-'E
| E'*'E
| E'/'E
| E'<'E
| E'>'E
| E LE E
| E GE E
| E EQ E
| E NE E
| E OR E
| E AND E
| ID
| NUM
;

E2 : E'<'E
| E'>'E
| E LE E
| E GE E
| E EQ E
| E NE E
| E OR E
| E AND E
| ID
| NUM
;
%%
int main()
{
printf("Enter the expression : \n");
yyparse();
}
void yyerror()
{
printf("Input rejected");
}