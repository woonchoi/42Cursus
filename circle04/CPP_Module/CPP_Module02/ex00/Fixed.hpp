/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woonchoi <woonchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:26:15 by woonchoi          #+#    #+#             */
/*   Updated: 2022/04/18 16:55:12 by woonchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP_
# define FIXED_HPP_

# include <iostream>

class Fixed
{
	private:
		int	_fixed_point;
		static const int	_fractional_bits = 8;
	public:
		Fixed(void);
		Fixed(const Fixed& f);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed&	operator=(const Fixed& f);
		~Fixed(void);
};

#endif;