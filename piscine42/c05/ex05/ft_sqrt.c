/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: maoliiny <maoliiny@student.hive.fi>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/26 20:34:39 by maoliiny		  #+#	#+#			 */
/*   Updated: 2025/02/27 11:02:51 by maoliiny         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long int	st;
	long int	mid;
	long int	ed;
	long int	ans;

	st = 0;
	ed = nb;
	ans = 0;
	if (nb == 1 || nb == 0)
		return (nb);
	while (st <= ed)
	{
		mid = (st + ed) / 2;
		if (mid * mid == nb)
			return (mid);
		if (mid * mid < nb)
		{
			st = mid + 1;
			ans = mid;
		}
		else
			ed = mid - 1;
	}
	return (0);
}
