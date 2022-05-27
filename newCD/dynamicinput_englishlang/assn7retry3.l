%{
enum{
    LOOKUP = 0,
    NOUN,
    PRO,
    CONJ,
    VERB,
    PREP 
};
int state;

%}

%%
\n {state = LOOKUP;}
^noun {state = NOUN;}
^pronoun {state = PRO;}
^conj {state = CONJ;}
^verb {state = VERB;}
^prep {state = PREP;}

[a-zA-Z]+ {
    if(state!=LOOKUP){
        add_word(state,yytext);
    }
    else{
        switch(lookup_word(yytext)){
            case NOUN : printf("%s is a noun", yytext);break;
            case PRO : printf("%s is a pronoun", yytext);break;
            case VERB : printf("%s is a verb", yytext);break;
            case CONJ : printf("%s is a conjuction", yytext);break;
            case PREP : printf("%s is a prep", yytext);break;

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
    char word_name;
    int word_type;
    struct word *next;
};

struct word *word_list;

int add_word(int type, char *word){
    struct word *wp;

    if(lookup_word(word)!=LOOKUP){
        printf("word already exist");
        return 0;
    }

    wp = (struct word*)malloc(sizeof(struct word));
    wp->next = word_list;
    wp->word_name = (char *)malloc(strlen(word)+1);
    strcpy(word_name,word);
    wp->word_type=type;
    word_name = wp;
    return 1; 
}

int lookup_word(char *word){
    struct word *wp = word_list;

    for(;wp;wp = wp->next){
        if(strcmp(wp->word_name, word)){
            return wp->word_type;
        }
    }
    return LOOKUP;
}

