/*Implement lexical analyzer for subset of english language using LEX. Build symbol table to dynamically declare and lookup parts of speech.*/

%{
enum{
    LOOKUP = 0,
    VERB,
    NOUN,
    PREP,
    CONJ
};

int state;

int add_word(int type, char *word);
int lookup_word(char *word);
%}
%%

\n     {state = LOOKUP;}
^verb  {state = VERB;}
^noun  {state = NOUN;}
^prep  {state = PREP;}
^conj  {state = CONJ;}

[a-zA-Z]+ { 
                if(state!=LOOKUP){
                    add_word(state,yytext);
                }else{
                    switch(lookup_word(yytext)){
                        case VERB: printf("%s : verb\n", yytext); break;
                        case NOUN: printf("%s : noun\n", yytext); break;
                        case PREP: printf("%s : preposition\n",yytext); break;
                        case CONJ: printf("%s : conjection\n",yytext); break;
                        default:
                            printf("%s : doesn't recognize\n",yytext);
                            break;
                    }
                }
            }
. ;

%%

int main()
{
    yylex();
    return 0;
}

struct word{
    char *word_name;
    int word_type;
    struct word *next;
};

struct word *word_list;
extern void *malloc();

int add_word(int type, char *word)
{
    struct word *wp;

    if(lookup_word(word) != LOOKUP){
        printf("Word %s Already defiend", word);
        return 0;
    }
    wp = (struct word *) malloc(sizeof(struct word));
    wp->next = word_list;

    wp->word_name = (char *) malloc(strlen(word)+1);
    strcpy(wp->word_name, word);

    wp->word_type = type;
    word_list = wp;
    return 1;
}

int lookup_word(char* word){
    struct word *wp = word_list;
    for(;wp;wp=wp->next){
        if(strcmp(wp->word_name,word)==0)
            return wp->word_type;
    }
    return LOOKUP;
}

int yywrap()
{
    return 1;
}

