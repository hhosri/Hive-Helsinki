/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:15:56 by corellan          #+#    #+#             */
/*   Updated: 2023/04/11 08:58:34 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/stat.h>
# include <termios.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/errno.h>
# define BUFFER 1024
# define NORM_START 0
# define RE_IN 1
# define RE_OUT 2
# define RERE_IN 3
# define RERE_OUT 4
# define PIPE 5
# define IN_OUT 6

int	g_should_process;

typedef struct s_lexer
{
	int				token;
	int				i_split;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_lex_i
{
	int		i;
	int		j;
	int		k;
	int		fl;
	t_lexer	*le;
}	t_lex_i;

typedef struct s_sp_arg
{
	int		p;
	int		q;
	int		t;
	size_t	i;
	size_t	j;
	size_t	len;
	size_t	temp;
}	t_sp_arg;

typedef struct s_args
{
	int				pos;
	struct s_args	*next;
}	t_args;

typedef struct s_export
{
	int				index;
	struct s_export	*next;
}	t_export;

typedef struct s_m_arg
{
	int		**fd;
	t_lexer	*lexe;
	t_lexer	*begin;
	int		i;
	int		idx;
	int		n_redir;
	int		lex_size;
	int		len;
	int		fdin;
	int		fdout;
	int		flag_in;
	int		flag_out;
	int		flag_err;
	int		flag_pipe;
	int		wait;
	int		n_pipe;
	int		c_pipe;
	char	**path;
	pid_t	pid[BUFFER];
}	t_m_arg;

typedef struct s_env
{
	char	**env;
	char	**str;
	char	**args;
	char	***c_arg;
	char	**arr;
	char	oldpwd[BUFFER];
	char	newpwd[BUFFER];
	int		level;
	int		flag;
	char	*new_str;
	int		set_f;
	int		exit_stts;
	int		is_inside;
	int		is_inside_2;
	int		is_inside_q;
	int		is_inside_dq;
	int		status;
	char	*all_lines;
	int		fl_mtt;
	int		ret;
}	t_env;

void		ft_copy_env(t_env *env, char **envp);
void		handle_shortcuts(void);
int			handle_ctrl_d(char *str, t_env *env);
void		collect_args(char *st, t_env *env);
void		handle_exlamation(t_env *env, char *st, int i);
char		*ft_strjoin_c(char *s1, char const c);
int			ft_wordcount_space(char const *str);
int			ft_find_word_array(char **array, char *needle);
int			ft_array_len(char **array);
long long	ft_atoll(char const *str);
int			ft_count_space(char *str);
int			ft_strlen_w_space(char const *str);
int			ft_am_i_valid_number(char const *str);
int			ft_am_i_a_number(char *str);
int			ft_line_checker(char *st, int *ret, t_env *env);
int			ft_check_symbols(char const *str);
int			ft_exit_check(char **array, char *str, int *ret, t_env *env);
char		**ft_custom_split(char const *s);
int			ft_check_single_quot(char const *str, int *i, int *j);
int			ft_check_double_quot(char const *str, int *i, int *j);
size_t		ft_len_single_quot(char const *s, size_t *st, t_sp_arg *sp);
size_t		ft_len_double_quot(char const *s, size_t *st, t_sp_arg *sp);
size_t		ft_count_char_arg(char const *str);
char		**ft_custom_split_free(char **array, size_t i);
size_t		ft_strlcpy_arg(char *d, char const *s, size_t size, t_sp_arg *sp);
int			check_char_now(const char *str, int i);
int			check_char_after(const char *str, int i);
int			check_char(const char *str, int i);
int			ft_check_dash_split_lexer(const char *str, int *i, int *j);
int			ft_echo(char **array, t_env *env);
size_t		ft_wordcount_args(char const *str, t_args **args);
void		ft_add_to_list_args(t_args **begin, int num);
int			ft_listsize_args(t_args **lst);
void		ft_free_list_args(t_args **lst);
void		ft_print_list_args(t_args **a);
int			ft_pwd(t_env *env);
int			ft_cd(char **path, t_env *env);
int			ft_env(t_env *env, char **array);
void		ft_add_variables(t_env *env, char *variable);
void		ft_add_variables_copy_back(t_env *env, char **array, int i);
int			ft_export(t_env *env, char **array);
void		ft_add_to_list_export(t_export **begin, int num);
int			ft_listsize_export(t_export **lst);
void		ft_free_list_export(t_export **lst);
void		ft_decide_what_print(char **array, t_export **exp);
void		ft_sort_and_print_strings(char **array);
void		ft_putstr_export(char *st, int fd);
int			ft_check_first_variable(char *variable);
void		ft_print_list_export(t_export **a);
void		check_and_process_d_quotes(char	**variable);
int			ft_check_plus(t_env *env, char *variable);
char		*ft_strdup_export(char const *src);
int			ft_unset(t_env *env, char **array);
int			ft_unset_mult(t_env *env, char **array);
char		*is_var_available(char *substr, t_env *env);
int			ft_check_s_quot_lexer(char const *str, int *i);
int			ft_check_d_quot_lexer(char const *str, int *i);
size_t		ft_len_s_quot_lexer(char const *s, int i);
size_t		ft_len_d_quot_lexer(char const *s, int i);
void		ft_free_list_lexer(t_lexer **lst);
void		ft_add_to_list_lexer(t_lexer **begin, int num, int index);
int			size_lex(t_lexer **lst);
void		ft_print_list_lexer(t_lexer **a);
int			ft_c_redic_in_a_row(t_lexer **a);
t_lexer		*ft_lexlast(t_lexer **lst);
void		ft_tokens_recognition(char const *str, t_lexer **lex);
int			ft_run_single_command(char **cmd, t_env *env);
int			ft_print_error_command(char **cmd, t_env *env, int flag);
char		**ft_split_lexer(char const *s);
char		**ft_process_lexer(char **arg, char *str);
char		**ft_process_arg(char **array, char *str);
char		*ft_find_path(char **cmd, t_env *env, int *flag);
int			ft_iterate_mult_args(char **ar, int *re, t_env *env, t_m_arg *arg);
void		ft_do_redirections(char **ar, t_m_arg *arg, t_env *env);
void		ft_redirections_input(char **ar, t_m_arg *arg, t_env *env);
void		ft_redirections_output(char **ar, t_m_arg *arg, t_env *env);
void		ft_reredirect_input(char **ar, t_m_arg *arg);
void		ft_redirect_out_append(char **ar, t_m_arg *arg, t_env *env);
int			catch_errors(char *st, t_env *env);
int			catch_empty(char **arr, t_lexer **lex, char *st);
int			ft_error_pipe(int err);
int			ft_error_redir(int err, char *st, int i);
int			ft_error_unsupported(void);
void		replace_var_val(t_env *env, char *var_value, int var_len);
int			check_here_doc(char ***arr, t_lexer **lex, t_env *env);
void		here_doc(char **st, t_env *env);
void		ft_process_rein(t_m_arg *arg);
void		ft_process_reout(t_m_arg *arg);
int			ft_exit_check_m1(char **array, int *ret, t_env *env);
int			ft_exit_check_m2(char **array, int *ret, t_env *env);
int			ft_export_mult(t_env *env, char **array);
int			ft_unset_mult(t_env *env, char **array);
int			ft_copy_d_qu_lex(char **d, const char *s, t_sp_arg *li, size_t si);
int			ft_copy_s_qu_lex(char **d, const char *s, t_sp_arg *li, size_t si);
int			ft_error_more_than_two(int err_num);
int			wordcount_spac_spe(char const *str);
int			ft_strlen_in(const char *str);
int			ft_strlen_out(const char *str);
int			ft_strlen_pipe(const char *str);
int			in_or_out_2(char *st, int i, t_env *env);
int			single_inside_double(char *st, int i);
int			separator_char(char *st, int last_idx);
void		ft_child(char *path, char **cmd, t_env *env, t_m_arg *arg);
void		ft_child_s(char *path, char **cmd, t_env *env);
void		handle_shortcuts2(int flag);
void		ft_setup_flag(int *flag, char **path, int i, char **array);
int			find_special_cases(char **cmd);
void		close_fd(t_m_arg *arg);
int			count_pipes(t_lexer **lst);
int			prepare_pipe_fd(int	***fd, t_m_arg *arg);
int			create_pipes(int ***fd, int *index, t_lexer **lex, char **arr);
void		ft_free_pipes(int ***fd);
void		close_pipes(t_m_arg *arg);
void		print_exit_stts(t_env *env);
void		disable_characters(int toggle);
void		handle_sig(int sig);

#endif