/*
 * Return type for a match
 * type supposed to be an enum for tokens
 * length is the length of the match
 */

typedef struct{
    int length;
    int type;
}match;

/* 
 * An array of keywords
 */
char* intMatch[] = {
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
 * matches a keyword from the array above
 * return length of matched keyword
 * TODO: set return type 
 */
match matchKeyword(char buf[]){
    match theMatch;
    theMatch.type = 0; 
    theMatch.length = 0;
    int i; 
    for (i=0; i < sizeof(intMatch)/sizeof(intMatch[0]); i++){
        char* candid = intMatch[i];
        int nomatch = 0;

        int x;
        for (x = 0; x < strlen(buf) && x < strlen(candid); x++){
            if(buf[x] == candid[x]){ 
                continue;
            }else{
                nomatch = 1;
                break;
            }
        }
        
        if(nomatch){
            continue;
        }

        theMatch.length = strlen(candid);
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

int main(){
    lex("if");
    return 5;
}