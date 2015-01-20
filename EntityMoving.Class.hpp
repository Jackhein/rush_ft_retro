/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityMoving.Class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:15:53 by tbalea            #+#    #+#             */
/*   Updated: 2015/01/11 10:40:33 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYMOVING_CLASS_HPP
# define ENTITYMOVING_CLASS_HPP

# include "EntityMoving.Interface.hpp"


class EntityMoving :
	public virtual EntityMovingInterface,
	public virtual Entity
{
	public:
		//	Constructor
		EntityMoving( void );
		EntityMoving( char c, float x, float y, int dmg, float dir, int life );

		//	Destructor
		virtual ~EntityMoving( void );

		//	Copy
		EntityMoving( EntityMoving const & copy );
		EntityMoving & operator=( EntityMoving const & copy );

		//	Getter
		virtual float getDir( void ) const;
		virtual int getLife( void ) const;

		//	Setter
		virtual void setDir( float dir );
		virtual void setLife( int life );

		//	Function
		virtual void mouvement( void );
		virtual void touch( float x, float y, int dmg );

	protected:
		float _dir;
		int _life;
};

#endif
