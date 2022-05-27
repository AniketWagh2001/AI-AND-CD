%option noyywrap
%{
#include "assn11.tab.h"
#include<math.h>
extern double vbltable[26];
%}
%%
([0-9]+|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?) {yylval.dval=atof(yytext);return NUMBER;}
[a-z] {yylval.vblno = yytext[0] - 'a'; return NAME;}
[\t] ;
\$ return 0;
\n|. return yytext[0];
%%