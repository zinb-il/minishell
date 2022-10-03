/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:29:10 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/02 23:59:51 by ziloughm         ###   ########.fr       */
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

# include "libft.h"
# include "signal.h"
# include "vars.h"
# include "util.h"
# include "token.h"
# include "lexer.h"
# include "scan_grammar.h"
# include "node.h"
# include "visitor.h"
# include "ast.h"

#	endif