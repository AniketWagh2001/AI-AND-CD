lower [a-z]
upper [ A-Z]
%%

[ \t]+ {printf(" ");}
{lower} { printf("%c",yytext[0]-32);}
{upper} {printf("%c",yytext[0]+32);}
. ;

%%
main( )
{
yylex();
}

int yywrap(){
    return 0;
}