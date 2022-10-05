/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_grammar.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:56:26 by ziloughm          #+#    #+#             */
/*   Updated: 2022/10/04 22:00:22 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef SCAN_GRAMMAR_H
# define SCAN_GRAMMAR_H

int	scann_op(t_token *token, t_token *tokens);
int	scann_redirec(t_token *token, t_token *tokens);
int	scann_lparenth(t_token *token, t_token *tokens);
int	scann_rparenth(t_token *token, t_token *tokens);
int	scann_grammar(t_token *tokens);

#	endif