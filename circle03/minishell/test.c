#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <readline/history.h>

#define TOKEN 1;
#define CMD 2;

typedef struct  s_word_token
{
    char    *str;
    int     type;
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
    int             parse_length;
    t_parse_tree    *plist_root;
}   t_mshell_info;


int check_double_quote_token(char *str)
{
    int     length;
    char    *cur;

    length = 0;
    cur = str;
    while (*cur && *cur != '\"')
    {
        cur++;
        length++;
    }
    if (!*cur)
        return (0);
    else
        return (length);
}

int check_single_quote_token(char *str)
{
    int     length;
    char    *cur;

    length = 0;
    cur = str;
    while (*cur && *cur != '\'')
    {
        cur++;
        length++;
    }
    if (!*cur)
        return (0);
    else
        return (length);
}

int quote_parse(char *str)
{
    int length;

    if (*str == '\"')
        length = check_double_quote_token(str);
    else if (*str == '\'')
        length = check_single_quote_token(str);
}

int parse_str(char const *str, t_mshell_info *info)
{
    char    *cur;
    char    *token;
    int     length;
    int     quote_length_temp;
    
    cur = str;
    length = 0;
    while (*cur)
    {
        if (*(cur + length) == '\"' || *(cur + length) == '\'')
        {
            if (length && !token)
                token = strncat(cur, length - 1);
            quote_length_temp = quote_parse(cur + length);
            if (quote_length_temp == 0)
                return (0);
            else if (quote_length_temp)
            {
            }
        }
        else if (*(cur + length) == ' ')
        {

        }
        length++;
    }
}

void    init_mshell_info(t_mshell_info *info)
{
    info->plist_head = 0;
    info->parse_length = 0;
    info->plist_root = 0;
}

int main(void)
{
    t_mshell_info   info;
    char            *str;

    init_mshell_info(&info);
    str = readline("> ");

}