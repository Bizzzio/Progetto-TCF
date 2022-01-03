#include "menu.h"

void Menu::Draw()
{
    vector<string> voci {"Play","Instructions"};
    vector<string>::iterator i;
    /*for (i=voci.begin();i!=voci.end();i++)
        cout<<(*i)<<endl;*/
    for (int c=0; c<voci.size();c++)
        cout<<voci[c]<<endl;

    #ifdef _WIN32
	#define KEY_UP    72
	#define KEY_LEFT  75
	#define KEY_RIGHT 77
	#define KEY_DOWN  80
		/*cout<<"ciao";
		int ch;
		ch=getch();
		cout<<ch;
		getch();
		//system("cls");*/
		int c, ex;

    //while(1)

	
    /*{
        c = getch();

        if (c && c != 224)
        {
            cout << endl << "Not arrow: " << (char) c << endl;
        }
        else
        {
            switch(ex = getch())
            {*/
                //case KEY_UP     /* H */:
                //    cout << endl << "Up" << endl;//key up
                //    break;
                //case KEY_DOWN   /* K */:
                //    cout << endl << "Down" << endl;   // key down
                //    break;
                //case KEY_LEFT   /* M */:
                //    cout << endl << "Left" << endl;  // key left
                //    break;
                //case KEY_RIGHT: /* P */
                //    cout << endl << "Right" << endl;  // key right
                //    break;
                //default:
                //    cout << endl << (char) ex << endl;  // not arrow
                //    break;
            //}
        //}
    //}

	/*HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/

	#endif
}