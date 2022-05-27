%{
int count = 0;
%}

%%

\.|\,|\(|\)|\; {count++;}

%%

int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "rb+");
    yylex();
    printf("%d",count);
    return 0;
}
int yywrap(){
    return 1;
}