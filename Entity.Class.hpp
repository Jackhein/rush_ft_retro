/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:12:10 by tbalea            #+#    #+#             */
/*   Updated: 2015/01/11 13:35:14 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_CLASS_HPP
# define ENTITY_CLASS_HPP

# include <cmath>
# include "Entity.Interface.hpp"

class Entity : virtual public EntityInterface {
	public:
		//	Constructor
		Entity( void );
		Entity( char c, float x, float y, int dmg );

		//	Destructor
		virtual ~Entity( void );

		//	Copy
		Entity( Entity const & copy );
		Entity & operator=( Entity const & copy );

		//	Getter
		virtual char getC( void ) const;
		virtual float getX( void ) const;
		virtual float getY( void ) const;
		virtual int getDmg( void ) const;

		//	Setter
		virtual void setC( char c );
		virtual void setX( float x );
		virtual void setY( float y );
		virtual void setDmg( int dmg );

	protected:
		char _c;
		float _x;
		float _y;
		int _dmg;
};

#endif
