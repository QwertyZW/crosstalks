#ifndef LEXER_H_
#define LEXER_H_

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
 * @brief Find if a string buf begins with a string candid
 * Return 0 on false, length of candid on true
 * TODO: care for \0
 */
int beginsWith(char buf[], char candid[]);

/*
 * @brief matches a keyword from the array above
 * return length of matched keyword
 * TODO: set return type 
 * TODO: maybe deglobalize and parameterize theKeywords
 *     probably not if we want to maintain the match func(buf) interface
 */
match matchKeyword(char buf[]);

/*
 * @brief matches a symbol that begins with a-zA-Z and ends with a-zA-Z0-9*
 * TODO: set return type 
 * TODO: maybe deglobalize and parameterize theKeywords
 *     probably not if we want to maintain the match func(buf) interface
 */
match matchSymbol(char buf[]);

/*
 * @brief check if given char is alpha or underscore
 */
int isAlphaOrUnderscore(char x);

/*
 * @brief check if given char is digit
 */
int isDigit(char x);

/*
 * @brief match a comment
 */
match matchComment(char buf[]);

/*
 * @brief match a string
 */
match matchString(char buf[]);

/*
 * @brief match a literal
 */
match matchLiteral(char buf[]);

/*
 * @brief match punctuation
 */
match singlePunctuation(char buf[]);

//TODO put this in the right place
//TODO do something about name spacing this enum
//tokens
enum{
    KWINT,
    KWCHAR,
    KWLONG,
    KWVOID,
    KWSHORT,
    KWFOR,
    KWIF,
    KWWHILE,
    KWELSE,
    KWSWITCH,
    KWCASE,
    KWDEFAULT,
    KWBREAK,
    KWCONTINUE,
    KURLYOPEN,
    KURLYCLOSE,
    PARENOPEN,
    PARENCLOSE,
    SQUAREOPEN,
    SQUARECLOSE,
    COMMA,
    MINUS,
    PLUS,
    DIV,
    MULT,
    TILDE,
    EXC,
    PERC,
    XOR,
    AMP,
    OR,
    EQ,
    BM
};


#endif