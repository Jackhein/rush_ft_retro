/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityMoving.Interface.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 16:44:21 by tbalea            #+#    #+#             */
/*   Updated: 2015/01/11 10:43:05 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYMOVING_INTERFACE_HPP
# define ENTITYMOVING_INTERFACE_HPP

# include "Entity.Class.hpp"

class EntityMovingInterface :
	public virtual EntityInterface
{
	public:
		//	Getter
		virtual float getDir( void ) const = 0;
		virtual int getLife( void ) const = 0;

		//	Setter
		virtual void setDir( float dir ) = 0;
		virtual void setLife( int Life ) = 0;

		//	Function
		virtual void mouvement( void ) = 0;
		virtual void touch( float x, float y, int dmg ) = 0;
};

#endif
