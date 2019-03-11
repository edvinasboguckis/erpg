//2015-01-21

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstdlib>

using namespace std;

void NewGame();
void LoadGame();
void Options();
int main();
int MainMenu();
void About();
void CreateWarrior();
void Battle();
void InitBattle();
int ophealth;
int opmana;
int plhealth;
int plmana;
int playerlevel;
int oplevel;
int playerxp;
int defophealth;
int defopmana;
int defplhealth;
int defplmana;
void errorshit();
void errorshit2();
string gamever="v0.9 alpha(c++)";

int MainMenu()
{
	system("cls");
	cout<<"Welcome to ERPG "<<gamever<<endl;
	cout<<"Select the option!"<<endl;
	cout<<""<<endl;
	cout<<"1. New Game. \2. Load Game. \n3. Options. \n4. About. \n5. Exit. \n \n"<<endl;
	int MainMenuInput=0;
	cin>>MainMenuInput;
	switch (MainMenuInput)
	{
	case 1:
		NewGame();
		break;
	case 2:
		LoadGame();
		break;
	case 3:
		Options();
		break;
	case 4:
		About();
		break;
	case 5:
		system("cls");
        cout<<"Exiting..."<<endl;
        Sleep(1000);
        ExitGame(0);
		break;
	default:
		cout<<"Stop messing around, just enter appropriate number!"<<endl;
        Sleep(1000);
        MainMenu();
		break;
	}
}

void NewGame()
{
	system("cls");
	cout<<"Enter your profile name: ";
	string ProfileName;
	cin>>ProfileName;
	Sleep(400);
	ofstream profilesave ("profile.prf"); profilesave<<ProfileName; profilesave.close();
    ofstream EraseProfile ("Playerstats.tat"); EraseProfile<<"1"; EraseProfile.close();
    ofstream Erasexp ("Playerxp.tat"); Erasexp<<"0"; Erasexp.close();
	cout<<""<<endl;
	cout<<"Profile '"<<ProfileName<<"' Created!"<<endl;
	Sleep(1000);
	CreateWarrior();
}

void CreateWarrior()
{
	system("cls");
	cout<<"Select Character! \n1. Krasnuxaman. \n2. Captain Estonia."<<endl;  
	int WarriorSelection=0;
    ofstream Playerstats ("Playerstats.tat"); Playerstats << "1"; Playerstats.close();
	cin>>WarriorSelection;
	if(WarriorSelection==1)
	{
		ofstream WriteWarriorToFile ("Warrior.chr"); WriteWarriorToFile<<"1";WriteWarriorToFile.close();
		cout<<"Warrior 'Krasnuxaman' created! \n"<<endl;
		system("pause");
	}
	else if(WarriorSelection==2)
	{
	    ofstream WriteWarriorToFile ("Warrior.chr"); WriteWarriorToFile<<"2";WriteWarriorToFile.close();
		cout<<"Warrior 'Captain Estonia' created! \n"<<endl;
		system("pause");
	}
	else
	{ 
        errorshit2();
	}
    InitBattle();
}

void InitBattle()
{
    ifstream playerlevelread ("Playerstats.tat"); playerlevelread >> playerlevel; playerlevelread.close();
    ifstream playerxpread ("Playerxp.tat"); playerxpread >> playerxp; playerxpread.close();
    ofstream oplevelwrite ("opstat.tat"); oplevelwrite << playerlevel; oplevelwrite.close();
    ifstream oplevel1 ("opstat.tat"); oplevel1 >> oplevel; oplevel1.close();
    Sleep(1000);
    system("cls");
    switch (playerlevel)
    {
        case 1:
        ophealth= rand() %400+700;
        opmana= rand() %100+100;
        plhealth= 1000;
        plmana= 150;
        break;
        case 2:
        ophealth= rand() %400+850;
        opmana= rand() %100+170;
        plhealth= 1100;
        plmana= 210;
        break;
    }
    defophealth=ophealth;
    defopmana=opmana;
    defplhealth=plhealth;
    defplmana=plmana;
    Battle();
}

void errorshit2()    // why 2 errors tho?
{
    cout<<"Wrong selection, try again"<<endl;
    Sleep(3000);
    NewGame();
}

void errorshit()
{
    cout<<"Wrong selection, try again"<<endl;
    Sleep(3000);
    Battle();
}

void Battle()
{
    system("cls");
    cout<<"----------------------"<<endl;
    cout<<"Player Level: "<<playerlevel<<" / 50"<<endl;
    cout<<"Player Exp: "<<playerxp<<" / 5000"<<endl;
    cout<<"----------------------"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Opponent: "<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Opponent Health: "<<ophealth<<" / "<<defophealth<<endl;
    cout<<"Opponent Mana: "<<opmana<<" / "<<defopmana<<endl;
    cout<<"----------------------"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"Player:"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"Player's Health: "<<plhealth<<" / "<<defplhealth<<endl;
    cout<<"Player's Mana: "<<plmana<<" / "<<defplmana<<endl;
    cout<<"----------------------"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    cout<<"1. Sword attack."<<endl;
    cout<<"2. Special attack (75 mana)"<<endl;
    cout<<""<<endl;
    cout<<""<<endl;
    int selection=0;
    cin>>selection;
    int plattack=0;
    int opattack=0;
    switch(selection)
    {
        case 1:
        cout<<"Player did Sword attack!"<<endl;
        Sleep(1000);
        switch (playerlevel)                                                                                //player attack
        {
            case 1:
            plattack= rand() %100+30;
            ophealth=ophealth-plattack;
             cout<<"Player did: "<<plattack<<" damage!"<<endl;
             break;
             case 2:
             plattack= rand() %100+90;
             ophealth=ophealth-plattack;
             cout<<"Player did: "<<plattack<<" damage!"<<endl;
             break;
        }
        Sleep(1000);
        break;
        case 2:
        if(plmana>0)
        {
                    cout<<"Player did Special attack!"<<endl;
                    plmana= plmana-75;
                    Sleep(1000);
        switch (playerlevel)
        {
            case 1:
            plattack= rand() %110+90;
            ophealth=ophealth-plattack;
             cout<<"Player did: "<<plattack<<" damage!"<<endl;
             break;
             case 2:
             plattack= rand() %95+135;
             ophealth=ophealth-plattack;
             cout<<"Player did: "<<plattack<<" damage!"<<endl;
             break;
        }
        Sleep(1000);
        }
        else
        {
            cout<<"Not Enough Mana, skipping attack!"<<endl;
            Sleep(1000);
        }
        break;
        default:
        system("cls");
        errorshit();
        break;
    }
    int opselection=0;
    if (opmana-75>=0)
    {
        opselection= rand() %1+1;
    }
    else
    {
        opselection=1;
    }
    
    switch (opselection)                                                                                //op attack
        { 
        case 1:
        cout<<"Opponent did Sword attack!"<<endl;
        Sleep(1000);
        switch (oplevel)
        {
            case 1:
            opattack= rand() %90+30;
            plhealth=plhealth-opattack;
             cout<<"Opponent did: "<<opattack<<" damage!"<<endl;
             break;
             case 2:
             opattack= rand() %120+90;
             plhealth=plhealth-opattack;
             cout<<"Opponent did: "<<opattack<<" damage!"<<endl;
             break;
        };
        break;
        case 2:
        Sleep(1000);
        cout<<"Opponent did Special attack!"<<endl;
        opmana=opmana-75;
        switch (oplevel)
        {
            case 1:
            opattack= rand() %110+90;
            plhealth=plhealth-opattack;
             cout<<"Opponent did: "<<opattack<<" damage!"<<endl;
             break;
             case 2:
             opattack= rand() %95+135;
             plhealth=plhealth-opattack;
             cout<<"Opponent did: "<<opattack<<" damage!"<<endl;
             break;
        }
         }
         Sleep(1500);
    if(plhealth<0)                                                                                         //won or lost
    {
        cout<<"Opponent Won!"<<endl;
            int PlayerGainedXp=0;
    PlayerGainedXp= rand() %200+210;
    playerxp=playerxp-PlayerGainedXp;
        cout<<"Player Lost "<<PlayerGainedXp<<" xp"<<endl;
        cout<<""<<endl;                                              
        ofstream playerxpwrite ("Playerxp.tat"); playerxpwrite << playerxp; playerxpwrite.close();
        cout<<""<<endl;
        system("pause");
    }
    else if(ophealth<0)
    {
        cout<<"Player Won!"<<endl;
            int PlayerGainedXp=0;
    PlayerGainedXp= rand() %200+210;
    playerxp=playerxp+PlayerGainedXp;
        cout<<"Player Gained "<<PlayerGainedXp<<" xp!"<<endl;
        ofstream playerxpwrite ("Playerxp.tat"); playerxpwrite << playerxp; playerxpwrite.close();
        cout<<""<<endl;
                if(playerxp>5000)
        {
            cout<<"Congrats!!! You have reached level 2"<<endl;
            system("pause");
            playerlevel=2;
            ofstream wlr ("Playerstats.tat"); wlr<<"2";wlr.close();
        }   
        cout<<""<<endl;
        system("pause");
    }
    else
    { 
        Battle();
    }
    system("cls");
    cout<<"------------------------"<<endl;
    cout<<"1. Continue playing."<<endl;
    cout<<"2. Return to main menu."<<endl;
    cout<<"------------------------"<<endl;
    int plsel;
    cin>>plsel;
    switch(plsel)
    {
        case 1:
        Sleep(1000);
        InitBattle();
        break;
        case 2:
        Sleep(1000);
        MainMenu();
        break;
    }
    MainMenu();
}

void LoadGame()
{
    system("cls");
	cout<<"Reading Load file..."<<endl;
    ifstream LoadStatsLevel ("Playerstats.tat"); LoadStatsLevel >> playerlevel; LoadStatsLevel.close();
    ifstream LoadStatsEx ("Playerxp.tat"); LoadStatsEx >> playerxp; LoadStatsEx.close();
    if (playerlevel<=0)
    {
        cout<<"Savegame was not found, please start New Game!"<<endl;
        Sleep(1500);
        MainMenu();
    }
    else if (playerlevel>5)
    {
        cout<<"Not a legitimate player level has been found, cheater! deleting your savegame!"<<endl;
        int del = 0;
        ofstream DeleteForgery ("Playerstats.tat"); del > DeleteForgery; DeleteForgery.close();
        ExitGame(0);
    }
	else
    {
        cout<<"Savegame Loaded succesefully!"<<endl;
        Sleep(1500);
        InitBattle();
    }
}

void Options()
{
	system("cls");
    string ausave;
    ifstream autosaveoptch ("Asopt.opt"); autosaveoptch>>ausave; autosaveoptch.close();
    cout<<"Autosave is: "<<ausave<<endl;
    cout<<"1. Enable."<<endl;
    cout<<"2. Disable."<<endl;
    cout<<"3. Back to Menu."<<endl;
    cin>>ausave;
    if (ausave=="1") 
    {    
    ofstream autosaveopt ("Asopt.opt"); autosaveopt<<"enabled"; autosaveopt.close();
    }
    else if (ausave=="2")
    {
    ofstream autosaveopt ("Asopt.opt"); autosaveopt<<"disabled"; autosaveopt.close();
    }
    else if (ausave=="3")
    {
        MainMenu();
    }
    else
    {
        cout<<"wrong input!";
        system("pause");
        Options();
    }
    Options();
}

void About()
{
	system("cls");
	cout<<"*******************"<<endl;
	cout<<"ERPG "<<gamever<<endl;
	cout<<"By PedoCarrot"<<endl;
	cout<<"*******************"<<endl;
	cout<<""<<endl;
	cout<<""<<endl;
	system("pause");
	MainMenu();
}

int ExitGame(int returnstatus)
{
    exit(returnstatus);
}

int main()
{
	MainMenu();
}



