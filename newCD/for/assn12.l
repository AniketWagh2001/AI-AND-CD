%{
    #include "assn12.tab.h"
%}

alpha [A-Za-z]
digit [0-9]

%%
[ \t\n]
for return FOR;
{digit}+ return NUM;
{alpha}({alpha}|{digit})* return ID;
"<=" return LE;
">=" return GE;
"==" return EQ;
"!=" return NE;
"||" return OR;
"&&" return AND;
"++" return INCR;
"--" return DECR;
. return yytext[0];
%%
int yywrap()
{
    return 1;
}