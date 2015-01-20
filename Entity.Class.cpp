/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.Class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:36:42 by tbalea            #+#    #+#             */
/*   Updated: 2015/01/11 13:35:19 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.Class.hpp"

//	Constructor
Entity::Entity( void ) :
_c(' '), _x(0), _y(0), _dmg(0) {
}

Entity::Entity( char c, float x, float y, int dmg ) :
	_c(c),
	_x(x),
	_y(y),
	_dmg(dmg)
{
}

//	Destructor
Entity::~Entity( void ) {
}


//	Copy
Entity::Entity( Entity const & copy ) {
	*this = copy;
	return ;
}

Entity & Entity::operator=( Entity const & copy ) {
	if ( this != & copy ) {
		this->_c = copy.getC();
		this->_x = copy.getX();
		this->_y = copy.getY();
		this->_dmg = copy.getDmg();
	}
	return * this;
}

//	Getter
char Entity::getC( void ) const {
	return this->_c;
}

float Entity::getX( void ) const {
	return this->_x;
}

float Entity::getY( void ) const {
	return this->_y;
}

int Entity::getDmg( void ) const {
	return this->_dmg;
}

//	Setter
void Entity::setC( char c ) {
	this->_c = c;
}

void Entity::setX( float x ) {
	this->_x = x;
}

void Entity::setY( float y ) {
	this->_y = y;
}

void Entity::setDmg( int dmg ) {
	this->_dmg = dmg;
}
