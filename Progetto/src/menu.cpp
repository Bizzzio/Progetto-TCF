#include "menu.h"


void Menu::Draw()
{
    vector<string> voci {"Play","Instructions","Option","Credits"};
    vector<string>::iterator i;
    
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
		int c, ex, pos=0;
  cout << "Selezionare la configurazione usando le frecce" << endl;  
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  SetConsoleTextAttribute(h, 151);
  SetConsoleTextAttribute(h, 15);
  system("cls");
  for (int d=0; d<voci.size();d++)
  {
    if (d==0)
    {
       	SetConsoleTextAttribute(h, 10);
    		cout<<"--> "<<voci[d];
      	 SetConsoleTextAttribute(h, 15);
           cout<<endl;
    }
    else
      cout<<voci[d]<<endl;
  }
      
  
 
  

    while(c!=13)
		{   
            
             c=getch();
        if (c==0 || c==224)
        {
            switch(ex = getch())
            {
                case KEY_UP     /* H */:
                    //cout << endl << "Up" << endl;//key up
                		if(pos!=0)
                      	pos--;
                    break;
                case KEY_DOWN   /* K */:
                    //cout << endl << "Down" << endl;   // key down
                    if(pos<voci.size()-1)
                            pos++;
                    break;
  
                default:
                    break;
            }
          system("cls");
          for (int d=0; d<voci.size();d++){
        		if(d==pos){
              SetConsoleTextAttribute(h, 10);
              cout<<"--> "<<voci[d];
              SetConsoleTextAttribute(h, 15);
              cout<<endl;
            }
            else
                cout<<voci[d]<<endl;
          }
        }
    }

	//HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	/*for(int k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(h, k);
    cout << k << " I want to be nice today!" << endl;
  }
  SetConsoleTextAttribute(h, 15);*/

	#endif
}