/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafarauj <rafarauj@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 11:31:51 by lalgarra          #+#    #+#             */
/*   Updated: 2025/07/20 15:05:56 by lalgarra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

int		ft_arg_is_valid(char *str);
int		ft_atoi(char *chr);
void	ft_putnbr(int nb);
int		ft_input_cleaner(char *str);
void	populate_udlr(int array_udlr[4][4], char *arg);
void	ft_fill_space_solution(int array_solution_space[4][4][4]);
void	ft_cp_sol_spc(int src[4][4][4], int dst[4][4][4]);
void	ft_put_ar(int ar[4][4]);
int		ft_counting_zeros(
			int array_solution_space[4][4][4],
			int found_solution[4][4], int x, int y);
int		ft_is_solution(
			int array_solution_space[4][4][4], int found_solution[4][4]);
int		ft_apply_selection(
			int pos_x, int pos_y, int pos_z,
			int array_solution_space[4][4][4]);
int		ft_compute_udlr_value(
			int potential_solution[4][4],
			int nav_x, int dir_up,
			int idx);

#endif
