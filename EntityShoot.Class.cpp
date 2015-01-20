/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityShoot.Class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 21:24:07 by tbalea            #+#    #+#             */
/*   Updated: 2015/01/11 14:04:09 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityShoot.Class.hpp"


//	Constructor
EntityShoot::EntityShoot( void ) :
_shot(0), _cShot('~') {
	EntityMoving();
}

EntityShoot::EntityShoot( char c, float x, float y, int dmg, float dir, int life,
						int shot, char cShot, float dShot ) : Entity( c, x, y, dmg), EntityMoving(c, x, y, dmg, dir, life),
_shot(shot), _cShot(cShot), _dShot(dShot) {
	return ;
}

//	Destructor
EntityShoot::~EntityShoot( void ) {
}

//	Copy
EntityShoot::EntityShoot( EntityShoot const & copy ) :
	Entity( copy ), EntityMoving( copy ) {
	*this = copy;
	return;
}

EntityShoot & EntityShoot::operator=( EntityShoot const & copy ) {
	if ( this != & copy ) {
		this->_c = copy.getC();
		this->_x = copy.getX();
		this->_y = copy.getY();
		this->_dmg = copy.getDmg();
		this->_dir = copy.getDir();
		this->_life = copy.getLife();
		this->_shot = copy.getShot();
		this->_cShot = copy.getCShot();
		this->_dShot = copy.getDShot();
	}
	return * this;
}

//	Getter
int EntityShoot::getShot( void ) const {
	return this->_shot;
}

char EntityShoot::getCShot( void ) const {
	return this->_cShot;
}

float EntityShoot::getDShot( void ) const {
	return this->_dShot;
}

//	Setter
void EntityShoot::setShot( int shot ) {
	this->_shot = shot;
}

void EntityShoot::setCShot( char cShot ) {
	this->_cShot = cShot;
}

void EntityShoot::setDShot( float dShot ) {
	this->_dShot = dShot;
}

//	Function
EntityMoving *	EntityShoot::shoot( void ) {
	EntityMoving * shot = new EntityMoving( getCShot(), getX(), getY() + 1, getDmg(),
									getDShot(), getLife() );
	return shot;
}
