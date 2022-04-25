#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/history.h>
#include "libft.h"

#define NON_QUOTE 0;
#define SQUOTE 1;
#define DQUOTE 2;

#define TOKEN 0;
#define CMDS 1;
#define CMD 2;
#define CMD_ARG 3;
#define REDIRECTS 4;
#define REDIRECT 5;
#define FILENAME 6;
#define PIPE 7;


typedef struct  s_word_token
{
    char    *str;
    int     token_type;
    int     quote_type;
    int     is_used;
}   t_word_token;

typedef struct  s_parse_list
{
    t_word_token        *token;
    struct s_parse_list *next;
}   t_parse_list;

typedef struct  s_parse_tree
{
    t_word_token    *token;
    struct s_parse_tree *left;
    struct s_parse_tree *right;
}   t_parse_tree;

typedef struct  s_mshell_info
{
    t_parse_list    *plist_head;
    t_parse_tree    *plist_root;
    int             parse_length;
}   t_mshell_info;

int is_space(char c)
{
    return (c == ' ' || (9 <= c && c <= 13));
}

int tokenize(t_mshell_info *info, char *str)
{
    char    *cur;
    char    *next;
    int     token_length;

    cur = str;
    while (*cur)
    {
        next = cur;
        while (*next)
        {
            token_length = next - cur;
            if (is_space(*next) && token_length == 0)
            {
                cur++;
                break;
            }
        }
    }
}

int parse(t_mshell_info *info, char *str)
{

}

int main(void)
{
    t_mshell_info   info;
    char            *str;

    init_mshell_info(&info);
    while (1)
    {
        str = readline("> ");
    }
}