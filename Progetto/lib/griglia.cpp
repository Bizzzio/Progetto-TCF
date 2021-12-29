map<punto, *navi> grid;
vector fleet;
setflotta()
{
    fleet.push_back(new nave2) do
    {
        do
        {
            cout << "orizzontale verticale";
            cin >> a;
        } while (tolower(a) != 'h' || tolower(a) != 'v')
                cout
            << "metti il punto";
        cin >> x >> y;
        a = tolower(a); //da mettere altri controlli qua
        if (a == 'h')
            h = true;
        else if (a == 'v')
            h = false;
    }
    while (!fleet.back.ok(h, x, y))
        ;
    if (h)
    {
        //for che aggiunge tutti i punti (x+i, y) alla mappa
    }
    else
    {
        //for che aggiunge tutti i punti (x,y+i) alla mappa
    }
}