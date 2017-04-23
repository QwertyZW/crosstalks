#include "lexer.h"

//TODO maybe rollout homemade strlen

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

/*
 * TODO: the idea is to go through all the matcher functions
 * that `implement` the matcher interface
 */
int lex(char buf[]){
    match (*func[1])(char buf[]) = { &matchKeyword };
    match zz = func[0](buf);
    printf("%d", zz.length);
}
