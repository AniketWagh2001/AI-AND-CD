%{
    #include <stdio.h>
    #include <stdlib.h>
%}
%token ID NUM FOR LE GE EQ NE OR AND INCR DECR
%right '='
%left AND OR
%left '<' '>' LE GE EQ NE 
%left '+''-' INCR DECR
%left '*''/'
%right UMINUS
%left '!'
%%
S : ST {printf("Input accepted.\n");exit(0);};

ST : FOR '('E3';'E2';'E4')' '{' ST1';''}';

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
E4 : ID INCR
| ID DECR

E2 : E'<'E
| E'>'E
| E LE E
| E GE E
;

E3 : ID'='NUM
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