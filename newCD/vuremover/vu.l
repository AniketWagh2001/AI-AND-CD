%{
int count = 0;
%}

%%

[university] {count++;}

%%

int main(int argc, char *argv[]){
    yyin = fopen(argv[1], "rb+");
    yylex();
    printf("%d",count/2);
    return 0;
}
int yywrap(){
    return 1;
}