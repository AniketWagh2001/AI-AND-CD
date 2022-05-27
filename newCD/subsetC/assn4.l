/*1	Implement lexical analyzer for subset of 'C' language using LEX. Input filename as command line argument*/

%{

%}

%%

main|int|float|double|for|void|default|define|if|while {printf("%s is a keyword\n",yytext);}

\;|\"|\,|\.|\(|\)|\[|\]|\' {printf("%s is a delimiter\n",yytext);}

\+|\-|\*|\/|\%|\>|\<|\=|\== {printf("%s is a operator\n",yytext);}

[a-zA-Z]+ {printf("%s is a identifier\n",yytext);}

%%

int main(int argc,char *argv[])
{
    yyin = fopen(argv[1], "rb+");
    yylex();
    return 0;
}

int yywrap()
{
    return(1);
}