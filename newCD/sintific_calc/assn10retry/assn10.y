%{
#include<stdio.h>
#include<math.h>
%}

%union{
    float fval;
}

%token<fval>NUMBER
%token END
%token SQRT
%token LOG SIN COS TAN SEC COSEC COT
%right '^'
%left '+' '-'
%left '*' '/'
%left SQRT
%nonassoc UMINUS
%left LOG SIN COS TAN SEC COSEC COT

%type<fval>expression

%%
statement:
expression END {printf(" = %.4f \n ",$1);return 0;};
expression:
expression '+' expression {$$ = $1 + $3;}
|expression '-' expression {$$ = $1 - $3;}
|expression '*' expression {$$ = $1 * $3;}
|expression '/' expression {if($3==0){printf("divider cant be zero");return 0;}else{$$ = $1 / $3;}}
|expression '^' expression {$$ = pow($1,$3);}
|SQRT expression {$$ = sqrt($2);};expression:'-'expression %prec UMINUS{$$=-$2;}
|SIN expression {$$ = sin($2*3.14/180);}
|COS expression {$$ = cos($2*3.14/180);}
|TAN expression {$$ = tan($2*3.14/180);}
|SEC expression {$$ = 1/(sin($2*3.14/180));}
|COSEC expression {$$ = 1/(cos($2*3.14/180));}
|COT expression {$$ = 1/(tan($2*3.14/180));}
|NUMBER {$$ = $1;}




%%

int main(){
    yyparse();
}

int yyerror(char* s){
    printf("%s\n",s);
    return 0;
}

int yywrap(){
    return 0; 
}