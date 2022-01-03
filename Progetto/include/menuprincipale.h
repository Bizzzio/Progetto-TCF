#include "menu.h"
#include "MenuPlay.h"
class MenuPrincipale : public Menu
{
	public:
    	virtual void Draw() const;
	private:
		const vector<string> voci {"Play","Instructions","Options","Credits"};
        MenuPlay menuplay;
};