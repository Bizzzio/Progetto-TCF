#ifndef MENUPLAY_H
#define MENUPLAY_H
#include "Play.h"

class MenuPlay : public Menu
{
	public:
    	virtual void Draw() const;
    private:
    	const vector<string> voci {"1 giocatore","2 giocatori"};
		
};

#endif
