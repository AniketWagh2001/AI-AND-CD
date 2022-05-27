/*	Implement word count program using LEX.*/

%{
int count = 0;
%}

%%

[a-zA-Z]* {count++;}
[\t]+ ;
[\n]+ ;

%%

int main(){
    yylex();
    printf("%d are the number of words",count);
    return 0;
}
int yywrap(){
    return(1);
}