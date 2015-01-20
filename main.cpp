/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibakayok <ibakayok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 02:55:37 by ibakayok          #+#    #+#             */
/*   Updated: 2015/01/12 15:34:14 by tbalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "CElement.hpp"

static const float _PI = 3.141592653;


void	ft_drawmap(WINDOW *win, int xmax, int ymax) // Draw EmptyMap
{
	static int	dance = 0;
	int			x;
	int			y;

	x = 0;
	while (x < xmax){
		y = 0;
		while (y < ymax){
			mvwaddch(win, x, y, ' ');
			if (x == 0 || x == xmax - 1)
				mvwaddch( win, x, y, '_');
			else if (y == 0 || y == ymax - 1)
				mvwaddch(win, x, y, '|');
			y++;
		}
		x++;
	}
	// animated bkgrd
	mvwaddch(win, ((dance / 2) % (xmax - 1)) + 1, (dance + 174) % ymax,'.');
	mvwaddch(win, ((dance / 4) % (xmax - 1)) + 1, (dance + 326) % ymax,'.');
	mvwaddch(win, ((dance / 6) % (xmax - 1)) + 1, (dance + 51651) % ymax,'.');
	mvwaddch(win, ((dance / 8) % (xmax - 1)) + 1, (dance + 7531) % ymax,'.');
	mvwaddch(win, ((dance / 16) % (xmax - 1)) + 1, (dance + 92135) % ymax,'.');
	mvwaddch(win, ((dance / 32) % (xmax - 1)) + 1, (dance + 111531) % ymax,'.');
	mvwaddch(win, ((dance / 64) % (xmax - 1)) + 1, (dance + 131351) % ymax,'.');
	mvwaddch(win, ((dance / 128) % (xmax - 1)) + 1, (dance + 151351) % ymax,'.');
	dance++;
}

void	ft_drawentity(WINDOW *win, Entity *objet) {
	if (objet != NULL)
		mvwaddch(win, (int)objet->getX(), (int)objet->getY(), objet->getC());
}

CElement	*ft_findpast(CElement *depart, CElement *objets) {
	CElement *past;

	past = depart;
	depart = depart->next;
	while (depart != NULL)
	{
		if (depart == objets)
			return (past);
		past = past->next;
		depart = depart->next;
	}
	return (NULL);
}

CElement	*ft_collider(CElement *depart, CElement *objets) {
	while (depart != NULL && depart->getEntity() != NULL && objets != NULL && objets->getEntity() != NULL)
	{
		if ((int)depart->getEntity()->getX() == (int)objets->getEntity()->getX() && (int)depart->getEntity()->getY() == (int)objets->getEntity()->getY() && depart != objets)
			return (depart);
		depart = depart->next;
	}
	return (NULL);
}

/*int	ft_updateentity(CElement *depart, Entity *objet)
{
	depart = depart;
	objet = objet;
	return 0;
}*/

int	ft_updateentity(CElement *objets, CElement *objet)
{
	CElement *	depart;
	CElement *	collider;
	CElement *	past;

	depart = objets;
	if (objet->mouvant != NULL){
		objet->mouvant->mouvement();
		if (objet->mouvant->getY() < 0 || objet->mouvant->getY() > 60){
			past = (ft_findpast(depart, objet));
			past->next = objet->next;
			delete objet;
		}
	}
	while (objets->next != NULL)
	{
		if ((collider = ft_collider(depart, objet)) != NULL) {
			if (collider == depart || objet == depart)
				return (2);
			if ((past = ft_findpast(depart, collider)) != NULL){
				past->next = collider->next;
				delete collider;
			}
			past = (ft_findpast(depart, objet));
			past->next = objet->next;
			delete objet;
			return (0);
		}
		objets = objets->next;
	}
	return (1);
}

CElement *	ft_activeentity(WINDOW *win, CElement *objets, int frame, int y, int x) {
	srand (time(NULL));
	CElement *	depart;
	int		diff = 50;
	int		ang;

	if (frame > 1000)
		diff = 120;
	if (frame > 40)
		diff = 60;
	if (frame > 12000)
		diff = 30;
	depart = objets;
	ft_drawmap(win, y, x);
	if ((frame % diff) == 0)
	{
		ang = rand();
		while (ang > 45)
			ang -= 45;
		objets = objets->addobjet(new EntityMoving('{' + (rand()) % 4, (rand() % y) + 1, x, 1, (ang * _PI /180) + ((7 * _PI)/8), 1));
	}
	while (frame >= 1200 && frame % diff == 0 && y-- > 0) {
		objets = objets->addobjet(new EntityMoving('*', y, x + 1, 1, _PI, 1));
	}
	if (frame % 2 == 0){
		while (objets != NULL)
		{
			if (objets != depart && objets->mouvant != NULL &&
				objets->mouvant->getDir() > (_PI / 2) &&
				objets->mouvant->getDir() < (3 * _PI / 2) &&
				objets->mouvant->getY() > depart->shooteur->getY() &&
				objets->mouvant->getX() != depart->shooteur->getX()) {
/*^*/
				if (objets->mouvant->getX() < depart->shooteur->getX())
					objets->mouvant->setDir((objets->mouvant->getDir() / 2) +
											atan( (depart->shooteur->getY()-
												objets->mouvant->getY()) /
												(objets->mouvant->getX() -
											 	depart->shooteur->getX())));
				else
					objets->mouvant->setDir(_PI + (objets->mouvant->getDir() / 2) -
											atan( (depart->shooteur->getY()-
												objets->mouvant->getY()) /
											 	(depart->shooteur->getX()
												- (objets->mouvant->getX()))));
			}
			if (ft_updateentity(depart, objets) == 2)
				return (NULL);
			objets = objets->next;
		}
	}
	objets = depart;
	while (objets != NULL)
	{
		ft_drawentity(win, objets->getEntity());
		objets = objets->next;
	}
	return depart;
}

int		main(void){
	WINDOW *	win;
	int			ch;
	CElement	*objets;
	int			frame;
	int 		x = 60;
	int			y = 16;
	int			sens = 0;
	int			rech = 0;

	srand (time(NULL));
	frame = 0;
	initscr();
	win = newwin(y, x, 0, 0);
	keypad(stdscr, true);
	curs_set(0);
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	objets = NULL;
	objets = objets->addobjet(new EntityShoot('>', 5, 3, 1, 0, 1, 1,'=', 0));
	while (objets)
	{
		timeout(20);
		if ((ch = getch()) != ERR) {
			if (objets != NULL && objets->getEntity() != NULL){
				if (ch == KEY_UP) {
					sens = 1;
				} else if (ch == KEY_DOWN) {
					sens = -1;
				} else if (ch != ' ') {
					sens = 0;
				}
				if (ch == KEY_UP && objets->getEntity()->getX() > 1)
					objets->getEntity()->setX(objets->getEntity()->getX() - 1);
/*				if (ch == KEY_UP && objets->getEntity()->getX() == 1)
					objets->getEntity()->setX(14);
*/				if (ch == KEY_DOWN && objets->getEntity()->getX() < 14)
					objets->getEntity()->setX(objets->getEntity()->getX() + 1);
/*				if (ch == KEY_DOWN && objets->getEntity()->getX() == 14)
					objets->getEntity()->setX(1);
				if (ch == KEY_LEFT && objets->getEntity()->getY() > 1)
					objets->getEntity()->setY(objets->getEntity()->getY() - 1);
				if (ch == KEY_RIGHT && objets->getEntity()->getY() < 2)
					objets->getEntity()->setY(objets->getEntity()->getY() + 1);
*/				if (rech == 0 && ch == ' ' && objets != NULL
						&& objets->shooteur != NULL) {
					objets = objets->addobjet(objets->shooteur->shoot());
					objets->shooteur->setDShot( -(sens * _PI) / 8 );
					sens = 0;
					rech = 1;
				}
			}
			if (ch == 27)
				break ;
        }
		if ( frame % 5 == 0)
			rech = 0;
		objets = ft_activeentity(win, objets, frame, y, x);
		wmove(win, 0, 0);
		if ( frame < 4000 )
			wprintw(win, "[SCORE:%d]", frame / 120);
		else if ( frame >= 4000 )
			wprintw(win, "[SCORE:%d]", frame / 60);
		else if ( frame >= 12000 )
			wprintw(win, "[SCORE:%d]", frame / 20);
		wrefresh(win);
		frame++;
	}
	while (getch() != 27) {
		if ( frame < 4000 )
			mvprintw(x / 2, y / 2, "[SCORE:%d]", frame / 120);
		else if ( frame >= 4000 )
			mvprintw(x / 2, y / 2, "[SCORE:%d]", frame / 60);
		else if ( frame >= 12000 )
			mvprintw(x / 2, y / 2, "[SCORE:%d]", frame / 20);
		mvprintw(1 + (x / 2), y / 2, "[PRESS ESC TO ESCAPE]");
	}
	return (0);
}
