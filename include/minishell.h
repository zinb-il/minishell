/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibentour <ibentour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:29:10 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/14 16:20:44 by ibentour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>

# include "signal.h"
# include "vars.h"
# include "libft.h"
# include "util.h"
# include "token.h"
# include "lexer.h"
# include "scan_grammar.h"
# include "node.h"
# include "visitor.h"
# include "ast.h"
# include "execution.h"
# include "builtins.h"

#	endif