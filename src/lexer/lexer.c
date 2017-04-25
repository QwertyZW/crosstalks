#include "lexer.h"
/* 
 * TODO Implement escaping
 */
// maybe TODO maybe rollout homemade strlen

/* 
 * An array of keywords
 */
char* theKeywords[] = {
                     "int", 
                     "char", 
                     "long", 
                     "void", 
                     "short", 
                     "for", 
                     "if", 
                     "while", 
                     "else", 
                     "switch", 
                     "case", 
                     "default",
                     "break",
                     "continue"
                    };

/*
 * Find if a string buf begins with a string candid
 * Return 0 on false, length of candid on true
 * TODO: care for \0
 */
int beginsWith(char buf[], char candid[]){
    int x;
    if(buf == 0 || candid == 0)
        return 0;
        
    if(strlen(buf) < strlen(candid))
        return 0;

    for (x = 0; x < strlen(buf) && x < strlen(candid); x++){
        if(buf[x] == candid[x])
            continue;
        return 0;
    }
    return strlen(candid);
}

/*
 * matches a keyword from the array above
 * return length of matched keyword
 * TODO: set return type 
 * TODO: maybe deglobalize and parameterize theKeywords
 *     probably not if we want to maintain the match func(buf) interface
 */
match matchKeyword(char buf[]){
    match theMatch;
    theMatch.type = 0; 
    theMatch.length = 0;
    int i; 
    for (i=0; i < sizeof(theKeywords)/sizeof(theKeywords[0]); i++){    
        if(!beginsWith(buf, theKeywords[i])){
            continue;
        }
        theMatch.length = strlen(theKeywords[i]);
        theMatch.type = 1; 
        return theMatch;
    }
    return theMatch;
}

int isAlphaOrUnderscore(char x){
    return (x >= 'A' && x <= 'Z') || 
            (x >= 'a' && x <= 'z') ||
             x == '_';
}

int isDigit(char x){
    return x <= '9' && x >= '0';
}

match matchComment(char buf[]){
    match theMatch;
    theMatch.type = 0; 
    theMatch.length = 0;

    if (buf == 0)
        return theMatch;

    if (strlen(buf) < 2)
        return theMatch;

    if(!beginsWith(buf, "/*"))
        return theMatch;
    
    int i;
    for(i=1; i < strlen(buf); i++){
        if(buf[i-1] == '*' && buf[i] == '/'){
            // shouldn't require a type for this
            // just eat it
            theMatch.length = i+1;
            return theMatch;
        }
    }

    return theMatch;
}

/* matchString and matchLiteral are mergable*/
match matchString(char buf[]){
    match theMatch;
    theMatch.type = 0; 
    theMatch.length = 0;

    if (buf == 0)
        return theMatch;

    if (strlen(buf) < 1)
        return theMatch;

    if(!beginsWith(buf, "\""))
        return theMatch;
    
    int i;
    for(i=1; i < strlen(buf); i++){
        if(buf[i] == '"'){
            theMatch.length = i+1;
            return theMatch;
        }
    }

    return theMatch;
}

/* matchString and matchLiteral are mergable*/
match matchLiteral(char buf[]){
    match theMatch;
    theMatch.type = 0; 
    theMatch.length = 0;

    if (buf == 0)
        return theMatch;

    if (strlen(buf) < 1)
        return theMatch;

    if(!beginsWith(buf, "'"))
        return theMatch;
    
    int i;
    for(i=1; i < strlen(buf); i++){
        if(buf[i] == '\''){
            theMatch.length = i+1;
            return theMatch;
        }
    }

    return theMatch;
}

match matchSymbol(char buf[]){
    match theMatch;
    theMatch.type = 0; 
    theMatch.length = 0;
    if (buf == 0)
        return theMatch;

    if (strlen(buf) < 1)
        return theMatch;
    
    if(!isAlphaOrUnderscore(buf[0]))
        return theMatch;

    int i;
    for (i=0; i < strlen(buf); i++){
        if(!(isAlphaOrUnderscore(buf[i]) || isDigit(buf[i])))
            break;

    }
    theMatch.length = i;
    // TODO set type
    return theMatch;
}

match matchwhiteSpace(char buf[]){
    match theMatch;
    theMatch.type = 0; 
    theMatch.length = 0;

    if (buf == 0)
        return theMatch;

    if (strlen(buf) < 1)
        return theMatch;

    int i;
    for(i = 0; i < strlen(buf); i++){
        if(buf[i] != '\n' && buf[i] != '\t' && buf[i] != ' ' && buf[i] != '\r')
            break;
    }

    theMatch.length = i;
    return theMatch;
}

typedef struct{
    char punct;
    int type;
}TcharIntEl;

match matchSinglePunctuation(char buf[]){
    match theMatch;
    theMatch.type = 0; 
    theMatch.length = 0;
    TcharIntEl puncmap[] = {
        {'{', KURLYOPEN},
        {'}', KURLYCLOSE},
        {'(', PARENOPEN},
        {')', PARENCLOSE},
        {'[', SQUAREOPEN},
        {']', SQUARECLOSE},
        {',', COMMA},
        {'-', MINUS},
        {'+', PLUS},
        {'/', DIV},
        {'*', MULT},
        {'~', TILDE},
        {'!', EXC},
        {'%', PERC},
        {'^', XOR},
        {'&', AMP},
        {'|', OR},
        {'=', EQ},
        {'?', BM}
    };

    if (buf == 0)
        return theMatch;

    if (strlen(buf) < 1)
        return theMatch;

    theMatch.length = 1;
    for(int i = 0; i < sizeof(puncmap)/sizeof(puncmap[0]); i++){
        if(buf[0] == puncmap[i].punct){
            theMatch.type = puncmap[i].type;
            return theMatch;
        }
    }
    
    theMatch.length = 0;
    return theMatch;
}


/*
 * TODO: the idea is to go through all the matcher functions
 * that `implement` the matcher interface
 */
int lex(char buf[]){
    match (*func[1])(char buf[]) = { &matchKeyword };
    match zz = func[0](buf);
    printf("%d", zz.length);
}
