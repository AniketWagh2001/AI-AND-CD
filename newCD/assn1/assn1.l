/*1	Implement lexical analyzer for subset of English language using LEX.*/

%{
    

%}

%%
[\t]+ ;

is|am|are|were|was|be|being|been {printf("%s: is a verb\n", yytext);}

a|an|the {printf("%s is a article\n",yytext);}

if|then|and|but|or|so {printf("%s: is a conjuction", yytext);}

he|her|him|she|them|they {printf("%s: is a pronoun",yytext);}

[a-zA-z]+ {printf("%s: is a noun",yytext);}

%%

main()
{
    yylex();
}

int yywrap()
{
    return(1);
}