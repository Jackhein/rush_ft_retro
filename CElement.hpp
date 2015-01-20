/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CElement.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:48:27 by ibakayok          #+#    #+#             */
/*   Updated: 2015/01/18 17:44:39 by tbalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CELEMENT_HPP
#define CELEMENT_HPP

#include "EntityShoot.Class.hpp"

class CElement
{
public:
	Entity			*entite;
	EntityMoving	*mouvant;
	EntityShoot		*shooteur;
	CElement		*next;

	CElement *	addobjet(Entity *objet);
	CElement *	addobjet(EntityMoving *objet);
	CElement *	addobjet(EntityShoot *objet);
	virtual void delobjet(CElement *past);

	CElement(void);
	CElement(Entity *objet);
	CElement(EntityMoving *objet);
	CElement(EntityShoot *objet);
	CElement( CElement const & copy );
	virtual ~CElement(void);

	Entity *getEntity(void);

	CElement & operator=( CElement const & copy );
};

#endif
