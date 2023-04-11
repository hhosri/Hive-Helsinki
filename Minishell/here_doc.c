/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: corellan <corellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 13:41:04 by hel-hosr          #+#    #+#             */
/*   Updated: 2023/04/11 10:17:18 by corellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	repl_dol_aux(t_env *env, char **temp, int len_var, int idx_wrd)
{
	char	**arr_tmp;
	int		i;

	i = 0;
	arr_tmp = ft_split(env->env[idx_wrd], '=');
	if (arr_tmp == NULL)
		return (i + 1);
	while ((arr_tmp[1] != NULL) && (arr_tmp[1][i] != '\0'))
	{
		if (arr_tmp[1][i] == '\\' && arr_tmp[1][i + 1] == '"')
		{
			i++;
			continue ;
		}
		(*temp) = ft_strjoin_c((*temp), arr_tmp[1][i]);
		i++;
	}
	ft_free_split(arr_tmp);
	return (len_var);
}

static int	replace_dollar(t_env *env, char *line_str, int i, char **temp)
{
	int		len_var;
	int		len_env;
	int		idx_wrd;
	char	*needle;

	len_var = separator_char(line_str, (i + 1));
	if (len_var == (i + 1))
	{
		(*temp) = ft_strjoin_c((*temp), '$');
		return (i + 1);
	}
	needle = (char *)malloc(sizeof(char) * ((len_var - (i + 1)) + 1));
	if (needle == NULL)
		return (i + 1);
	ft_strlcpy(needle, (line_str + (i + 1)), ((len_var - (i + 1)) + 1));
	needle = ft_strjoin_c(needle, '=');
	len_env = ft_array_len(env->env);
	idx_wrd = ft_find_word_array(env->env, needle);
	free(needle);
	if (len_env == idx_wrd)
		return (len_var);
	return (repl_dol_aux(&(*env), &(*temp), len_var, idx_wrd));
}

static void	here_doc_pros(t_env *env, char **line_str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup("");
	while ((*line_str)[i])
	{
		if ((*line_str)[i] == '\\' && (*line_str)[i + 1] == '$')
		{
			temp = ft_strjoin_c(temp, '$');
			i += 2;
		}
		else if ((*line_str)[i] == '$')
			i = replace_dollar(&(*env), (*line_str), i, &temp);
		else
		{
			temp = ft_strjoin_c(temp, (*line_str)[i]);
			i++;
		}
	}
	free((*line_str));
	(*line_str) = ft_strdup(temp);
	free(temp);
}

static void	h_doc_helper(t_env *env, char *delimiter, char *line_str)
{
	while (1)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGINT, handle_sig);
		line_str = readline("> ");
		if ((!line_str || \
			ft_strncmp(delimiter, line_str, ft_strlen(delimiter)) == 0) && \
				g_should_process)
		{
			free(line_str);
			break ;
		}
		if (!g_should_process)
		{
			free(line_str);
			break ;
		}
		here_doc_pros(&(*env), &line_str);
		env->all_lines = ft_strjoin_free(env->all_lines, line_str);
		env->all_lines = ft_strjoin_c(env->all_lines, '\n');
		free(line_str);
	}
	printf("%s\n", env->all_lines);
}

void	here_doc(char **st, t_env *env)
{	
	char	*line_str;
	char	**temp;

	line_str = NULL;
	temp = ft_custom_split((*st));
	temp = ft_process_arg(temp, (*st));
	env->all_lines = ft_strdup("");
	h_doc_helper(env, temp[0], line_str);
	ft_free_split(temp);
	free((*st));
	(*st) = ft_strdup(env->all_lines);
	free(env->all_lines);
}
