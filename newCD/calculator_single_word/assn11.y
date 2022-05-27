%{
#include<stdio.h>
#include<math.h>
double memvar;
double vbltable[26];
%}

%union{
    double dval;
    int vblno;
}

%token <vblno> NAME
%token <dval> NUMBER
%token <dval> MEM
%left '-' '+'
%left '*' '/' '%'
%right '^'
%nonassoc UMINUS

%type <dval> expression
%%

start: statement'\n';
statement: NAME'='expression{vbltable[$1]=$3;}|expression{printf(" =%g\n",$1);};
expression:
expression'+'expression{$$=$1+$3;}
|expression'-'expression{$$=$1-$3;}
|expression'*'expression{$$=$1*$3;}
|expression'/'expression{$$=$1/$3;}
|expression'%'expression{$$=fmod($1,$3);}
|expression'^'expression{$$=pow($1,$3);}
|'('expression')'{$$=$2;}
|'-'expression %prec UMINUS{$$=-$2;}
| NUMBER {$$=$1;}
| NAME {$$=vbltable[$1];}
;
%%
int main(){
    printf("enter a math exp");
    yyparse();
}
int yyerror(char* s){
    printf("%s\n",s);
}

