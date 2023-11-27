#include <bits/stdc++.h>

#include "Developer.h"
#include "game.h"

#include "Developer.cpp"
#include "game.cpp"

/*
#include "gamer.h"
#include "gamer.cpp"

#include "Payment.h"
#include "Payment.cpp"
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>


using namespace std;

class game;
class gamer;
class Developer;
class Admin;
class Payment;








/*
enum game_types
{
    fps,
    tps,
    moba,
    sandbox,
    action_adventure,
    others,
    null
};
char *type_names[] = {"fps", "tps", "moba", "sandbox", "action-adventure", "others", "null"};
enum Medium
{
    bkash,
    paypal,
    visa,
    mastercard
};
char *Medium_names[] = {"bkash", "paypal", "visa", "mastercard"};


class game
{
private:
    static int cnt;
    int GameID;
    string Name;
    game_types Type;
    double Price;
    int developerID;
    string releaseDate;
    float rating;

public:
    game();
    float get_rating();
    float avg_rating(); // incomplete
    void set_info();
    void get_info();
    double get_price();
    int get_id();
    void disk_out();
    void disk_in(int);
    void set_price(double);
    int get_cnt();
   // void set_devID(Developer*);
};
*/

////////////////////////////////////////////////////////////////////////////////////////////////

class gamer
{
private:
    static int cnt;
    int id;
    double balance;
    int num_of_purchased_games;
    vector<int> library;

public:
    gamer();
    void show_balance();
    double get_balance();
    void add_balance();
    bool buy_game(game);
    int get_id();
    void show_library();
    void disk_out();
    void disk_in(int);
    int get_count();
    void dec_count();
};

///////////////////////////////////////////////////////////////////////////


class Payment
{
private:
    static int cnt;
    int ID;
    int gamerID;
    int gameID;
    string Date;
    Medium PaymentMedium;

public:
    friend class gamer;
    Payment();
    bool VerifyBalance(gamer, game);
    bool Transaction(gamer, game);
    void disk_out();
    void disk_in(int);

};

//////////////////////////////////////////////////////////////////////////////
/*
int game::cnt = 0;
game::game()
{
    GameID = cnt;
    Name = "x";
    Type = null;
    Price = 0;
    developerID = 0;
    releaseDate = "0";
    rating = 0;
}

/*void game::set_devID(Developer* dev)
{
    developerID = dev->get_devID();
} ///

void game::disk_out()
{
    ofstream out;
    out.open("game.dat", ios::app | ios::binary);
    out.write((char *)this, sizeof(*this));
}
void game::disk_in(int i)
{
    ifstream in;
    in.open("game.dat", ios::app | ios::binary);
    in.seekg(i * sizeof(game));
    in.read((char *)this, sizeof(*this));
}
int game::get_id()
{
    return GameID;
}
void game::set_info()
{
    cout << "Name of the game : ";
    cin >> Name;
    cout << "Type of the game : \n0.fps\n 1.tps \n 2.moba \n 3.sandbox \n 4.action-adventure \n 5.others";
    int temp;
    cin >> temp;
    Type = (game_types)temp;
    cout << "Enter price: ";
    cin >> Price;
   // set_devID(dev);
  // developerID = Developer::get_devID();

  cout<<"Enter Developer ID:";
  cin>>developerID;

    cout << "Enter the release date : " << endl;
    cin >> releaseDate;
}

void game::get_info()
{
    cout << "Name of the game : " << Name;
    cout << "Type of the game : " << type_names[Type];
    cout << "Price of the game : " << Price;
    cout << "Release Date : " << releaseDate;
    cout << "Rating : " << rating;
}
double game::get_price()
{
    return Price;
}

void game::set_price(double a)
{
    Price = a;
}

int game::get_cnt()
{
    return cnt;
}
*/

///////////////////////////////////////////////////////////////////////////////////

int gamer::cnt = 0;
gamer::gamer()
{
    id = cnt;
    balance = 100;
    num_of_purchased_games = 0;
    cnt++;
}
void gamer::disk_out()
{
    ofstream out;
    out.open("gamer.dat", ios::app | ios::binary);
    out.write((char *)this, sizeof(*this));
}
void gamer::disk_in(int i)
{
    ifstream in;
    in.open("gamer.dat", ios::app | ios::binary);
    in.seekg(i * sizeof(game));
    in.read((char *)this, sizeof(*this));
}
void gamer::show_library()
{
   // int i = num_of_purchased_games;
   vector<int>::iterator i;
    for (i = library.begin(); i != library.end(); i++)
    {
        game g;
        g.disk_in(*i);
        g.get_info();
    }
}
int gamer::get_id()
{
    return id;
}
void gamer::show_balance()
{
    cout << " Current balance is : " << balance << endl;
}
double gamer::get_balance()
{
    return balance;
}
void gamer::add_balance()
{
    cout << "Enter your credit card number : "; // for the sake of realism only
    int n;                                      // we are not implementing the gateway to the concerned bank account
    cin >> n;
    cout << "Card verified." << endl;
    cout << "Enter the amount that you want to transfer : ";
    int x;
    cin >> x;
    balance += x;
    cout << "Transaction completed! Credits added." << endl;
}
bool gamer::buy_game(game new_game)
{
    Payment *p;
    if (p->Transaction(*this, new_game))
    {
        balance -= new_game.get_price();
        cout << "Game purchased successfully" << endl;
        library.push_back(new_game.get_id());
        p->Transaction(*this, new_game);
        return 1;
    }
    else
    {
        cout << " Insufficient balance " << endl;
        return 0;
    }
}

int gamer:: get_count()
{
    return cnt;
}
void gamer:: dec_count()
{
    cnt--;
}

///////////////////////////////////////////////////////////////////////////////////////

int Payment::cnt = 0;
Payment::Payment()
{
    ID = cnt;
    cnt++;
    time_t now = time(0);
    Date = ctime(&now);
    cout << "Medium of Payment: \n0.bkash \n1.paypal \n2.visa \n3.mastercard\n";
    int temp;
    cin >> temp;
    PaymentMedium = (Medium)temp;
}
void Payment::disk_out()
{
    ofstream out;
    out.open("payment.dat", ios::app | ios::binary);
    out.write((char *)this, sizeof(*this));
}
void Payment::disk_in(int i)
{
    ifstream in;
    in.open("payment.dat", ios::app | ios::binary);
    in.seekg(i * sizeof(game));
    in.read((char *)this, sizeof(*this));
}
bool Payment::VerifyBalance(gamer gr, game g)
{
    double bal = gr.get_balance();
    double pri = g.get_price();
    if (bal >= pri)
        return 1;
    else
        return 0;
}
bool Payment::Transaction(gamer gr, game g)
{
    if (Payment::VerifyBalance(gr, g))
    {
        gameID = g.get_id();
        gamerID = g.get_id();
        return 1;
    }
    else
        return 0;
}


////////////////////////////////////////////////////////////////////////////////
/*

class Developer
{
private:
    static int cnt;
    int devID;
    string dev_type;
    string dev_name;
    double revenue;

public:
    Developer();
    void setprice(game&);
    void addGameRequest();
    void disk_out();
    void disk_in(int);
    int get_devID();
};

/////////////////////////////////////////////////////////////////////////////////////

int Developer::cnt=0;

Developer ::Developer()
{
    devID = cnt;
    cout << "Enter Developer name:";
    cin >> dev_name;
    cout << "Enter Developer type:";
    cin >> dev_type;
    revenue = 0;

    cnt++;
}

int Developer ::get_devID()
{

    return devID;
}

void Developer::disk_out()
{
    ofstream out;
    out.open("developer.dat", ios::app | ios::binary);
    out.write((char *)this, sizeof(*this));
}
void Developer::disk_in(int i)
{
    ifstream in;
    in.open("developer.dat", ios::app | ios::binary);
    in.seekg(i * sizeof(Developer));
    in.read((char *)this, sizeof(*this));
}

void Developer ::setprice(game &g_name)
{
    vector<game> vec;
    ifstream infile;
    infile.open("game.dat", ios::app | ios::binary);

    int temp = g_name.get_cnt();
    game *ptr = new game;

    for (int i = 0; i < temp; i++)
    {
        infile.seekg(i * sizeof(game));
        infile.read((char *)ptr, sizeof(game));
        if (ptr->get_id() != g_name.get_id())
        {
            vec.push_back(*ptr);
        }
    }
    delete ptr;

    infile.close();

    ofstream outfile;
    outfile.open("game.dat", ios::trunc | ios::binary);

    vector<game>::iterator p;



    for (p = vec.begin(); p < vec.end(); p++)
    {
        game gg = *p ;
        game *pp ;
        pp = &gg;
        outfile.write((char *)pp, sizeof(game));
    }



    double new_price;
    g_name.get_info();
    cout << "What should be the price of the game? Please enter :";
    cin >> new_price;
    g_name.set_price(new_price);
    *ptr = g_name;

    outfile.write((char *)ptr, sizeof(game));
    outfile.close();
    delete ptr;
}


void Developer::addGameRequest()
{
    ofstream game_file;
    game_file.open("pending_games.dat", ios::app | ios::binary);

    game *new_game = new game;

    new_game->set_info();

    game_file.write((char *)new_game, sizeof(new_game));
    game_file.close();
}
*/
/////////////////////////////////////////////////////////////////////////////////////

class Management_System
{

public :
    static  int id;
    //static int gamer_count, developer_count;
    int id2;
    string password;
    int user;

    Management_System ()
    {
        id2=id;
        id++;
    }

    void disk_out_gamer()
    {
        ofstream out;
        out.open("gamerpass.dat", ios::app | ios::binary);
        out.write((char *)this, sizeof(*this));
    }

    void disk_in_gamer(int i)
    {
        ifstream in;
        in.open("gamerpass.dat", ios::app | ios::binary);
        in.seekg(i * sizeof(Management_System));
        in.read((char *)this, sizeof(*this));
    }

    void registry (int user)
    {
        cout<<"Your id is "<<id2<<endl;
        cout<<"Please make a password for you: ";
        cin>>password;
        // cout<<"What type of user are you?\n"<<"1. Developer\n"<<"2. Gamer\n";
        //cin>>user;

        if (user==2)
        {
//            ofstream out;
//            out.open("gamerpass.dat",ios::app | ios::binary);
//            out.write((char*)this,sizeof(*this));
//            //gamer_count++;
//            out.close();

            disk_out_gamer();

//            ifstream in;
//            in.open("gamerpass.dat",ios::app|ios::binary);
//
//            Management_System *abc;
//            in.read((char*)abc, sizeof(*abc));
//            cout<<abc->id2<<"    "<<abc->password <<endl;
//            in.close();

            cout<<"Gamer user created successfully"<<endl;

            cout<<"Your Id :" <<id2<<endl;
            cout<<"Your pass :" <<password<<endl;

        }

        else if (user==1)
        {
            ofstream out;
            out.open("developerpass.dat",ios::app|ios::binary);
            out.write((char*)this,sizeof(*this));
            //developer_count++;

            cout<<"Developer user created successfully"<<endl;
        }
    }

    int get_id()
    {
        return id;
    }
    void dec_id()
    {
        id--;
    }



    ///No idea on how to implement the "Logout" function
};

int Management_System ::id=0;






class Admin
{
public:

    Management_System obj;
    string name;

//    void getname ()
//    {
//        //obj.registry();
//        cout<<"What's your name? ";
//        cin>>name;
//    }





    void approve_game ()
    {
        ifstream in;
        in.open("pending_games.dat",ios::app|ios::binary);
        int i=0;
        game* gem;

        while(!in.eof())
        {
            in.seekg(i*sizeof(game));
            in.read((char*)gem,sizeof(game));

            cout<<"Info of game number "<<i;
            gem->get_info();
            cout<<"Will you approve the game? "<<"1. Yes\n"<<"2. No\n";
            int a;
            cin>>a;

            if (a==1)
            {
                ofstream out;
                out.open("game.dat",ios::app|ios::binary);
                out.write((char*)gem,sizeof(game));
            }

            i++;
        }

        in.close();

        ofstream out;
        out.open("pending_games.dat",ios::trunc|ios::binary);
        out.close();

    }




    ///Incomplete. No idea how to implement it
    void Delete_Gamer()
    {

        vector<gamer> vec;
        ifstream infile;
        infile.open("gamer.dat", ios::app | ios::binary);


        gamer *ptr = new gamer;
        int temp = ptr->get_count() ;
        ptr->dec_count();




        int p;
        cout<<"What is the id? ";
        cin>>p;

        for (int i = 0; i < temp; i++)
        {
            infile.seekg(i * sizeof(gamer));
            infile.read((char *)ptr, sizeof(gamer));
            if (ptr->get_id() !=  p)
            {
                vec.push_back(*ptr);
            }
        }
        delete ptr;

        infile.close();

        ofstream outfile;
        outfile.open("gamer.dat", ios::trunc | ios::binary);

        vector<gamer>::iterator pitr;

        for (pitr = vec.begin(); pitr < vec.end(); pitr++)
        {
            gamer gg = *pitr ;
            gamer *pp ;
            pp = &gg;
            outfile.write((char *)pp, sizeof(gamer));
        }


    }


    ///Incomplete. No idea how to implement it
    void Delete_Developer()
    {


        vector<Developer> vec;
        ifstream infile;
        infile.open("developer.dat", ios::app | ios::binary);


        Developer *ptr = new Developer;
        int temp = ptr->get_count();
        ptr->dec_count();

        int p;
        cout<<"What is the id? ";
        cin>>p;

        for (int i = 0; i < temp; i++)
        {
            infile.seekg(i * sizeof(Developer));
            infile.read((char* )ptr, sizeof(Developer));
            if (ptr->get_devID() != p)
            {
                vec.push_back(*ptr);
            }
        }
        delete ptr;

        infile.close();

        ofstream outfile;
        outfile.open("developer.dat", ios::trunc | ios::binary);

        vector<Developer>::iterator pitr;

        for (pitr = vec.begin(); pitr < vec.end(); pitr++)
        {
            Developer gg = *pitr ;
            Developer *pp ;
            pp = &gg;
            outfile.write((char *)pp, sizeof(Developer));
        }


    }





    ///Incomplete. No idea how to implement it
    void Delete_Account ()
    {
        int a;
        cout<<"What kind of account do you wanna delete? "<<"1. Developer\n"<<"2. Gamer\n";
        cin>>a;

        if (a==1)
        {

            Delete_Developer();
        }

        else
        {
            Delete_Gamer();


        }
    }


    ///No idea on how to implement the "Maintainance" function

};


void Display()
{
    ifstream infile;

    infile.open("game.dat",ios::app|ios::binary);

    if(!infile)
    {
        cerr << "Error : File could not be opened"<<endl;
        exit(1);
    }

    game *ptr = new game;
    int i=0;

    while(!infile.eof())
    {
        infile.seekg(i*sizeof(game));
        infile.read((char *)ptr, sizeof(game));
        cout<<"game No "<<i+1<<endl;
        ptr -> get_info();

        i++;

    }

    delete ptr;
    infile.close();



}

///////////////////////////////////////////////////////////////////////

int temp_id;

bool login(int b)
{
    /*  int a;
      cout<<"What is your id? ";
      cin>>a;
      temp_id=a; */
    Management_System *man = new Management_System;

    int a;

    ifstream in;
    if (b==1)
    {

        cout<<"What is your id? ";
        cin>>a;
        temp_id=a;
        in.open("developerpass.dat",ios::app|ios::binary);
    }
    else if (b==2)
    {

        cout<<"What is your id? ";
        cin>>a;

        temp_id=a;
        //in.open("gamerpass.dat",ios::app|ios::binary);

        man->disk_in_gamer(temp_id);

        for (int i=0; i<  man->get_id(); i++)
        {
            cout<<"hellpsdopa"<<endl;
            in.seekg(i*sizeof(Management_System));
            in.read((char*)man,sizeof(Management_System));

            if (man->id2 == a)
            {
                cout<<"Type password: ";
                string pan;
                cin>>pan;

                cout<<man->password<<endl;

                if (man->password == pan )
                {
                    cout<<"Login successful\n"; // man->dec_id();
                    return 1;
                }
            }
        }


        cout<<"ldaslsdla"<<endl;
    }

    else if (b==3)
    {
        cout<<"Type Password: ";
        string ab="pass";
        string bc;
        cin>>bc;
        if (bc==ab)
        {
            cout<<"Login successful\n";// man->dec_id();
            return 1;
        }
    }
    else
    {
        cout<<"adsiks"<<endl;
        exit(0);
    }



//    for (int i=0; i<  man.get_id(); i++)
//    {
//        cout<<"hellpsdopa"<<endl;
//        in.seekg(i*sizeof(Management_System));
//        in.read((char*)man,sizeof(Management_System));
//
//        if (man.id2 == a)
//        {
//            cout<<"Type password: ";
//            string pan;
//            cin>>pan;
//
//            cout<<man->password<<endl;
//
//            if (man->password == pan )
//            {
//                cout<<"Login successful\n"; // man->dec_id();
//                return 1;
//            }
//        }
//    }
    //man->dec_id();

    cout<<"Login unsuccessful ";
    return 0;
}


void logout ()
{
    cout<<"Logging out. \n";
}


void start()
{
    int x;
    int i;
    cout<<"\n\t*********** Desi Game Store ***********\n"<<"\n\t\t\t    \n";
    cout<<"\n\t\t>>Please Choose Any Option To login \n";
    cout<<"1.Login as user \n2.Register as user"<<endl;
    cin>>x;
    if(x==1)
    {
        system("CLS");
        cout<<"\n\t*********** Desi Game Store ***********\n"<<"\n\t\t\t    \n";
        cout<<"\n\t\t>>Please Choose User Type \n";
        cout<<"1. Developer\n"<<"2. Gamer\n"<<"3.Admin\n4.Exit"<<endl;


        cin>>i;
        if(login( i )== 1)
        {
            if(i==1)
            {
                int temp;
                system("CLS");

                Developer obj_dev;
                obj_dev.disk_in(temp_id);

                cout<<"1.Add Game\n 2.Modify Price"<<endl;
                cin>>temp;
                if(temp == 1)
                {

                    obj_dev.addGameRequest();
                    cout<<"Game was added to pending list"<<endl;

                }
                if(temp==2)
                {
                    int gid;
                    cout<<"Enter GameID :" ;
                    cin>>gid;

                    game g_obj;
                    g_obj.disk_in(gid);

                    obj_dev.setprice(g_obj);

                }


            }
        }
    }
    else if(x==2)
    {
        int y;
        system("CLS");
        cout<<"\n\t*********** Desi Game Store ***********\n"<<"\n\t\t\t    \n";
        //scout<<"\n\t\t>>Please Choose User Type \n";
        cout<<"What type of user are you?\n"<<"1. Developer\n"<<"2. Gamer\n";
        cin>>y;
        if(y==2)
        {

            Management_System manage;
            manage.registry(y);

            gamer g_mer;
            g_mer.disk_out();
        }
        else if(y==1)
        {
            Developer deve;
            Management_System manage;

            manage.registry(y);
            deve.disk_out();
        }
    }




}

////////////////////////////////////////////////////////////////////////







int main()
{

    start();



    return 0;
}



