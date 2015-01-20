/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityShoot.Class.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 21:10:00 by tbalea            #+#    #+#             */
/*   Updated: 2015/01/11 10:39:08 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYSHOOT_CLASS_HPP
# define ENTITYSHOOT_CLASS_HPP

# include "EntityShoot.Interface.hpp"

class EntityShoot :
	public virtual EntityShootInterface,
	public virtual EntityMoving
{
	public:
		//	Constructor
		EntityShoot( void );
		EntityShoot( char c, float x, float y, int dmg, float dir, int life,
					int shot, char cShot, float dShot );

		//	Destructor
		~EntityShoot( void );

		//	Copy
		EntityShoot( EntityShoot const & copy );
		EntityShoot & operator=( EntityShoot const & copy );

		//	Getter
		virtual int getShot( void ) const;
		virtual char getCShot( void ) const;
		virtual float getDShot( void ) const;

		//	Setter
		virtual void setShot( int shot );
		virtual void setCShot( char cShot );
		virtual void setDShot( float dShot );

		//	Function
		virtual EntityMoving *	shoot( void );
	protected:
		int _shot;
		char _cShot;
		float _dShot;
};

#endif
