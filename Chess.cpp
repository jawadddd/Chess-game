#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include "GameData.cpp"

using namespace std;
struct Chess{
    GameData GameState;
    string PlayerNames[2];
    bool GameActive = false;
} Game;

string getPlayerinfo(){
    string Name="";
    cout<< "\nEnter Player Name\n";
    do{
        cin.clear();
        fflush(stdin);
        getline(cin, Name);
    }while(Name.length() == 0);
    return Name;
}

int SaveGame(){

      // If we have an active game then save it for future along with player names
    // The function will ask the user to specify a file name and save the entire game into it
   ofstream h_for_hacker("brownmunde.txt");
   for(int i = 0;i< 8;i++ )
    {
       for(int j =0 ; j< 8 ;j++)
       {
            h_for_hacker<<Game.GameState.Board[i][j].PieceColor<<" "<<Game.GameState.Board[i][j].Code<<" ";
       }
        h_for_hacker<<endl;
    }
   h_for_hacker.close();
    return 0;
}
int LoadGame(){
    // The function will ask the user to specify a file name and save the entire game into it
    ifstream g_for_gamer;
    g_for_gamer.open("brownmunde.txt");
    if(g_for_gamer.fail()==1)
    {
        cout<<"File not found";
        return -2;
    }
    int iii;
    int jjj;
    for(int i = 0 ; i< 8;i++)
    {
        for(int j=0;j<8;j++)
        {
            g_for_gamer >> iii;
            switch(iii)
            {
                case 0:
                {
                    Game.GameState.Board[i][j].PieceColor = BLACK;
                    break;
                }
                case 1:
                {
                    Game.GameState.Board[i][j].PieceColor = WHITE;
                    break;
                }
            }
            g_for_gamer >> jjj;
            switch(jjj)
            {
                case 0:
                {
                    Game.GameState.Board[i][j].Code = NONE;
                    break;
                }
                case 1:
                {
                    Game.GameState.Board[i][j].Code = PAWN;
                    break;
                }
                case 2:
                {
                    Game.GameState.Board[i][j].Code = ROOK;
                    break;
                }
                case 3:
                {
                    Game.GameState.Board[i][j].Code = BISHOP;
                    break;
                }
                case 4:
                {
                    Game.GameState.Board[i][j].Code = KNIGHT;
                    break;
                }
                case 5:
                {
                    Game.GameState.Board[i][j].Code = QUEEN;
                    break;
                }
                case 6:
                {
                    Game.GameState.Board[i][j].Code = KING;
                    break;
                }
            }
        }
    }
    g_for_gamer.close();
    return 0;
}

void ShowGame(){

    cout<< Game.PlayerNames[1]<<"\tvs\t"<<Game.PlayerNames[0]<<endl;

    for(int r = 0; r < 8; r++ ){
        cout<<endl<<r;
        for(int c = 0; c < 8; c++){
            switch(Game.GameState.Board[r][c].Code){
                case NONE:
                    cout<<"\t..";
                break;
                default:
                    cout<<"\t";
                    if(Game.GameState.Board[r][c].PieceColor == BLACK)
                        cout<<"B";
                    else
                        cout<<"W";

                    switch(Game.GameState.Board[r][c].Code){
                    case PAWN:
                        cout<<"P";
                    break;

                    case ROOK:
                        cout<<"R";
                    break;

                    case KNIGHT:
                        cout<<"kN";
                    break;

                    case BISHOP:
                        cout<<"B";
                    break;

                    case QUEEN:
                        cout<<"Q";
                    break;

                    case KING:
                        cout<<"K";
                    break;
                    }
                break;
            }
        }
        cout<<endl<<endl;
    }
    cout<<endl;
    for(int c = 0; c< 8; c++)
        cout<<"\t"<<c;
    cout<<"\n";
}

void initNewGame(){
    cout<<"Enter First(WHITE) Player's Info"<<endl;
    Game.PlayerNames[1] = getPlayerinfo();
    cout<<"\n\nEnter Second(BLACK) Player's Info"<<endl;
    Game.PlayerNames[0] = getPlayerinfo();
    initGame(Game.GameState);
}

int PlayGame(){
    chessMove Move;
    ShowGame();
    int hacker;
    while(!isCheckmate(Game.GameState, Game.GameState.TurningPlayer)){
        cout<<Game.PlayerNames[Game.GameState.TurningPlayer];
        if(Game.GameState.TurningPlayer == WHITE)
            cout<<" (WHITE) To Move";
        else
            cout<<" (BLACK) To Move";

        cout<<"\n\n"<<"Please enter your move  (use format FROM (Row# Column#) TO (Row# Column#) ) {Negative Value to move to the main menu}"<<endl;

        SaveGame();
        hacker=0;
        while(isfacingCheck(Game.GameState, Game.GameState.TurningPlayer))
        {
            if(hacker==0)
            {
                cout<<"DRIVE CAREFULLY!!!!!!!!!!!!!!!Facing Check is here"<<endl;
            }
            else
            {
                cout<<"THERE IS Still Facing Check!!!!!!!!!!!DANGER ZONE ,PLZ TAKE MOVE THAT CAN BREAK CHECK"<<endl;

            }
            hacker++;
            cin >> Move.FromRow>>Move.FromColumn;
            cin>>Move.ToRow>>Move.ToColumn;
            if(Move.FromRow < 0 || Move.FromColumn < 0 || Move.ToColumn < 0 || Move.ToRow < 0){
                cout<< "Moving to main menu \n";
                return 0;
            }


            if(!MakeMove(Game.GameState, Move))
            {
                if(Game.GameState.TurningPlayer == BLACK)
                    Game.GameState.TurningPlayer = WHITE;
                else
                    Game.GameState.TurningPlayer = BLACK;
            }
        }
        if(hacker!=0)
        {
            LoadGame();
            MakeMove(Game.GameState, Move);
            ShowGame();
        }
        else
        {
            cin >> Move.FromRow>>Move.FromColumn;
            cin>>Move.ToRow>>Move.ToColumn;

            if(Move.FromRow < 0 || Move.FromColumn < 0 || Move.ToColumn < 0 || Move.ToRow < 0){
                cout<< "Moving to main menu \n";
                return 0;
            }
            else
            {
                MakeMove(Game.GameState, Move);
                ShowGame();
            }
        }
    }

    return 0;

}

int main(){
    int choice = 0;
    do{
        do{
            cout<<"1. New Game\n2. Restart Game\n3. Save Game\n4. Load Game\n5. Exit\n\n Enter Your Choice(1-5) ";
            cin>>choice;
        }while(choice< 1 || choice > 5);

        switch(choice){
        case 1:
            initNewGame();
            PlayGame();
        break;
        case 2:
            PlayGame();
        break;
        case 3:
            SaveGame();
        break;
        case 4:
            LoadGame();
        break;
        case 5:
            return 0;
        break;
        }
    }while(1);
    return 0;
}
