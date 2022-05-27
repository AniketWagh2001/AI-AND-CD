/*2	Implement a lexical analyzer to input 'C' program file and a)Count number of comments b) Eliminate comments and c) Store output in another file*/

%{

int count = 0;

%}

%%


"//".*\n {count++;}
"/*"[^*/]*"*/" {count++;}

%%

int main()
{
    yyin = fopen("input.txt","r");
    yyout=fopen("output.txt","w");
    yylex();
    fprintf(yyout,"\n\n NOTE: number of comments removed: %d",count);
    return 0;
}

int yywrap(){
    return 1;
}