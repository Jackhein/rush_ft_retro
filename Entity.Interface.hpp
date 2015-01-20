/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.Interface.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 13:15:16 by tbalea            #+#    #+#             */
/*   Updated: 2015/01/11 11:44:11 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_INTERFACE_HPP
# define ENTITY_INTERFACE_HPP

# include <iostream>
# include <string>
# include <cmath>
#include <ncurses.h>
#include <ctime>
#include <cstdlib>

class EntityInterface {
	public:
		//	Getter
		virtual float getX( void ) const = 0;
		virtual float getY( void ) const = 0;
		virtual int getDmg( void ) const = 0;
		virtual char getC( void ) const = 0;

		//	Setter
		virtual void setX( float x ) = 0;
		virtual void setY( float y ) = 0;
		virtual void setDmg( int dmg ) = 0;
		virtual void setC( char c ) = 0;
};

#endif
