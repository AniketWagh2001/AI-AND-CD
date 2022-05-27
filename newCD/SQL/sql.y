%{
#include <stdio.h>
#include <stdlib.h>
%}
%token ID NUM SELECT DISTINCT FROM WHERE AND OR HAVING GROUPBY ORDERBY LT GT LE GE EQ NE
%right '='
%left AND OR
%left LT GT LE GE EQ NE 
%%

S : st1 ';' {printf("\nThis select query is valid\n");exit(0);}
  ;

st1 : SELECT x FROM y 
    | SELECT x FROM y st2
    | SELECT DISTINCT x FROM y st2
    ;

st2 : WHERE cond
    | WHERE cond st3
    | st3
    |
    ;

st3 : GROUPBY x 
    | GROUPBY x st4
    | st4
    |
    ;

st4 : HAVING cond 
    | HAVING cond st5
    | st5
    |
    ;

st5 : ORDERBY x
    |
    ;

x   : ID ',' x
    | '*'
    | ID
    ;

y   : ID ',' y
    | ID
    ;

cond : cond OR cond
     | cond AND cond
     | E
     ;

E : F'='F
  | F LT F
  | F GT F
  | F LE F
  | F GE F
  | F NE F
  | F EQ F
  | F OR F
  | F AND F
  | F
  ;

F : ID
  | NUM
  ;

%%

main()
{
printf("\nEnter the select query:\n\n");
yyparse();
}
int yyerror(char *error)
{
printf("%s\n",error);
}
