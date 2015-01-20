/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CElement.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 03:48:20 by ibakayok          #+#    #+#             */
/*   Updated: 2015/01/11 17:27:17 by ibakayok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CElement.hpp"


CElement::CElement( CElement const & copy ) {
	*this = copy;
	return ;
}

CElement::CElement( void ) : entite(NULL),mouvant(NULL), shooteur(NULL), next(NULL) {
	return ;
}

CElement::CElement(Entity *objet) : entite(objet),mouvant(NULL), shooteur(NULL), next(NULL) {

	return ;
}

CElement::CElement(EntityMoving *objet) : entite(NULL), mouvant(objet), shooteur(NULL), next(NULL) {
	return ;
}

CElement::CElement(EntityShoot *objet) : entite(NULL), mouvant(NULL), shooteur(objet), next(NULL) {
	return ;
}

CElement::~CElement(void) {
	if (this->entite)
		delete this->entite;
	this->entite = NULL;

	if (this->mouvant)
		delete this->mouvant;
	this->mouvant = NULL;

	if (this->shooteur)
		delete this->shooteur;
	this->shooteur = NULL;
	return ;
}

Entity * 	CElement::getEntity(void)
{
	if (this->mouvant != NULL)
		return this->mouvant;
	if (this->shooteur != NULL)
		return this->shooteur;
	else
		return this->entite;
}

CElement *	CElement::addobjet(Entity *objet) {
	CElement    *nouv = this;

	if (this == NULL) {
		nouv = new CElement(objet);
	}
	else
		this->next = this->next->addobjet(objet);

	return nouv;
}

CElement *	CElement::addobjet(EntityMoving *objet) {
	CElement    *nouv = this;

	if (this == NULL)
		nouv = new CElement(objet);
	else
		this->next = this->next->addobjet(objet);
	return nouv;
}

CElement *	CElement::addobjet(EntityShoot *objet) {
	CElement    *nouv = this;

	if (this == NULL) {
		nouv = new CElement(objet);
	}
	else
		this->next = this->next->addobjet(objet);

	return nouv;
}

void CElement::delobjet(CElement *past) {

	if (past != NULL)
		past->next = this->next;

	delete this;
}

CElement & CElement::operator=( CElement const & copy ) {
	if ( this != & copy ) {
		this->entite = copy.entite;
		this->mouvant = copy.mouvant;
		this->shooteur = copy.shooteur;
	}
	return * this;
}
