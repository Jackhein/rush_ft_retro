/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityMoving.Class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 18:24:51 by tbalea            #+#    #+#             */
/*   Updated: 2015/01/11 19:43:29 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityMoving.Class.hpp"

//	Constructor
EntityMoving::EntityMoving( void ) :
_dir(0), _life(1) {
	Entity();
}

EntityMoving::EntityMoving( char c, float x, float y, int dmg, float dir,
						int life ) : Entity( c, x, y, dmg ),
_dir(dir), _life(life) {
	return ;
}

//	Destructor
EntityMoving::~EntityMoving( void ) {
}

//	Copy
EntityMoving::EntityMoving( EntityMoving const & copy ) :
	Entity( copy )
{
	*this = copy;
	return;
}

EntityMoving & EntityMoving::operator=( EntityMoving const & copy ) {
	if ( this != & copy ) {
		this->_c = copy.getC();
		this->_x = copy.getX();
		this->_y = copy.getY();
		this->_dmg = copy.getDmg();
		this->_dir = copy.getDir();
		this->_life = copy.getLife();
	}
	return * this;
}

//	Getter
float EntityMoving::getDir( void ) const {
	return this->_dir;
}

int	EntityMoving::getLife( void ) const {
	return this->_life;
}

//	Setter
void EntityMoving::setDir( float dir ) {
	this->_dir = dir;
}

void EntityMoving::setLife( int life ) {
	this->_life = life;
}

//	Function
void EntityMoving::mouvement( void ) {
	setY( getY() + cos(getDir()));
	setX( getX() + sin(getDir()));
	//setY(getY() - _dir);
}

void EntityMoving::touch( float x, float y, int dmg ) {
	if ( (int)getX() == (int)x && (int)getY() == (int)y )
	{
		setLife( getLife() - dmg );
		if ( getLife() <= 0 ) {
			delete this;
		}
	}
}
