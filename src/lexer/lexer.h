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

#endif