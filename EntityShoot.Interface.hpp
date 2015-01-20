/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityShoot.Interface.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 19:48:20 by tbalea            #+#    #+#             */
/*   Updated: 2015/01/11 11:30:13 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYSHOOT_INTERFACE_HPP
# define ENTITYSHOOT_INTERFACE_HPP

# include "EntityMoving.Class.hpp"

class EntityShootInterface :
	public virtual EntityMovingInterface {
	public:
		//	Getter
		virtual int getShot( void ) const = 0;
		virtual char getCShot( void ) const = 0;
		virtual float getDShot( void ) const = 0;

		//	Setter
		virtual void setShot( int shot ) = 0;
		virtual void setCShot( char cShot ) = 0;
		virtual void setDShot( float dShot ) = 0;

		//	Function
		virtual EntityMoving * shoot( void ) = 0;
};

#endif

