%option noyywrap
%{
#include"sql.tab.h"
#include<stdio.h>
#include<stdlib.h>
%}
alpha [._a-zA-Z]
digit [0-9]
%%
[ \t\n]+ ;
select {return SELECT;}
distinct {return DISTINCT;}
from {return FROM;}
where {return WHERE;}
and {return AND;}
OR {return OR;}
"group by" {return GROUPBY;}
"order by" {return ORDERBY;}
having {return HAVING;}
{digit}+ {return NUM;}
{alpha}({alpha}|{digit})* {return ID;}
"<" {return LT;}
">" {return GT;}
"<=" {return LE;}
">=" {return GE;}
"==" {return EQ;}
"!=" {return NE;}
\$ return 0;
\n|. return yytext[0];
%%