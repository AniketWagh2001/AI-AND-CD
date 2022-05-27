%{
#include<string.h>
enum{
    LOOKUP = 0,
    KEYWORD,
    OPERATOR,
    IDENTIFIER,
    DELIMITER
};

int state ;

int add_word(int type, char *word);
int lookup_word(char *word);

%}

%%

\n {state = LOOKUP;}
^keyword  {state = KEYWORD;}
^operator {state = OPERATOR;}
^identifier {state = IDENTIFIER;}
^delimiter {state = DELIMITER;}

[a-zA-Z]+ { 
    if(state!=LOOKUP){
        add_word(state,yytext);        
    }
    else{
        switch(lookup_word(yytext)){
            case KEYWORD: printf("%s is a keyword",yytext); break;
            case OPERATOR: printf("%s is a operator",yytext); break;
            case IDENTIFIER: printf("%s is a identifier",yytext); break;
            case DELIMITER: printf("%s is a delimiter",yytext); break;
                default:
                    printf("%s cant recognise the type",yytext);

        }
    }
}

. ;

%%

int main(){
    yylex();
    return 0;
}

struct word{
    char *word_name;
    int word_type;
    struct word *next;
};

struct word *word_list;

int add_word(int type, char *word){
    struct word *wp;

    if(lookup_word(word)!=LOOKUP){
        printf("%s is already available", word);
        return 0;
    }

    wp = (struct word *) malloc(sizeof(struct word));
    
    wp->next =  word_list;
    wp->word_name = (char *) malloc(strlen(word)+1);
    strcpy(wp->word_name, word);
    wp->word_type = type;
    word_list = wp;
    return 1;
}

int lookup_word(char *word){
    struct word *wp = word_list;
    for(;wp;wp = wp->next){
        if(strcmp(wp->word_name, word)==0){
            return wp->word_type;
        }
    }
    return LOOKUP;
     
}

int yywrap(){
    return 1;
}
