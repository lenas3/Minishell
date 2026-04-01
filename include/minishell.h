#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

// int	is_quote_open(char *str);
char			**ft_split(char const *s, char c); //kullanmıyo olabilirm
t_token			*new_token(t_token_type type, char *value);
t_token_type	get_value(char *str, int i);
t_token 		*get_tokens(char *str);
int 			pipe_ctrl(char *str, int i);
char 			**split_to_commands(char *str);
int 			ft_strlen(char *str);
char			*ft_strdup(const char *str); //kullanmıyo olabilirm
char 			*trim(char *str);
int 			prompt(t_shell *shell); //readline basmalı
char			*ft_substr(char *str, int start, int len);

//önce WORD'e printable olmayan bir ascii değerini atadık. 
//sonraki gelenler yapı gereği 2, 3 olarak otomatik artıyor.
//enum default olarak 0'dan başlar. 0 = NULL çakışması yaşanmasın diye printable olmayan aralıktan başlıyoruz. 
typedef enum e_token_type
{
	WORD = 1,
	PIPE,
	REDIRECT_IN,
	REDIRECT_OUT,
	HEREDOC,
	APPEND
} t_token_type;

typedef struct s_token
{
	t_token_type type;
	char *value;
	struct s_token *next;
} t_token;
	
typedef struct s_redirect
{
	t_token_type type;
	char *target;
	struct s_redirect *next;
} t_redirect;

typedef struct s_cmd
{
	int argc;
	char **argv;
	struct s_cmd *next;
	t_redirect *redirects;
} t_cmd;

typedef struct s_minishell
{
	char **env;
	char *input;
	int exit_value;
	t_token *tokens;
	t_cmd *cmds;
} t_shell;

#endif