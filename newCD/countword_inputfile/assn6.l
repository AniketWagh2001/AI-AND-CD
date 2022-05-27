/*Implement word count program using LEX. Input filename as command line argument.*/

%{
int count = 0;    
%}

%%

[a-zA-Z]* {count++;}

[\t]+;
[\n]+;

%%
int main(int argc, char *argv[]){
    yyin = fopen(argv[1],"rb+");
    yylex();
    printf("%d are the number of words in the file",count);
    return 0;
}

int yywrap(){
    return(1);
}