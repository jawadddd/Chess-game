#include "GameData.h"
#include<iostream>
int zzz;
void PAWNPROMO(GameData& Game,int FR,int FC,int TR,int TC)
{
    if(Game.TurningPlayer==WHITE)
    {
        if(FR==1&&Game.Board[FR][FC].Code==PAWN)
        {
            cout<<" !!Pawn Promotion Time!! "<<endl<<"1.Enter 1 to promote pawn to queen "<<endl<<"2.Enter 2 to promote pawn to bishop "<<endl<<"3.Enter 3 to promote pawn to knight "<<endl<<"4.Enter 4 to promote pawn to rook"<<endl;
            cin>>zzz;
            Game.Board[TR][TC].PieceColor = Game.Board[FR][FC].PieceColor;
            Game.Board[FR][FC].Code = NONE;
            if(zzz==1)
            {
                Game.Board[TR][TC].Code=QUEEN;
            }
            if(zzz==2)
            {
                Game.Board[TR][TC].Code=BISHOP;
            }
            if(zzz==3)
            {
                Game.Board[TR][TC].Code=KNIGHT;
            }
            if(zzz==4)
            {
                Game.Board[TR][TC].Code=ROOK;
            }
        }
    }
    if(Game.TurningPlayer==BLACK)
    {
        if(FR==6&&Game.Board[FR][FC].Code==PAWN)
        {
            cout<<" !!Pawn Promotion Time!! "<<endl<<"1.Enter 1 to promote pawn to queen /n 2.Enter 2 to promote pawn to bishop /n 3.Enter 3 to promote pawn to knight /n 4.Enter 4 to promote pawn to rook"<<endl;
            cin>>zzz;
            Game.Board[TR][TC].PieceColor = Game.Board[FR][FC].PieceColor;
            Game.Board[FR][FC].Code = NONE;
            if(zzz==1)
            {
                Game.Board[TR][TC].Code=QUEEN;
            }
            if(zzz==2)
            {
                Game.Board[TR][TC].Code=BISHOP;
            }
            if(zzz==3)
            {
                Game.Board[TR][TC].Code=KNIGHT;
            }
            if(zzz==4)
            {
                Game.Board[TR][TC].Code=ROOK;
            }
        }
    }
}
int PAWNX(GameData& Game,int FR,int FC,int TR,int TC)
{
    if(Game.TurningPlayer==WHITE)
    {
        if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC&&TR!=FR+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE && Game.Board[TR+1][TC].Code==NONE && TR==FR-2 && TC==FC && FR==6&&TR!=FR+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK && Game.Board[TR+1][TC].Code==NONE && TR==FR-2 && TC==FC && FR==6&&TR!=FR+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].Code!=NONE&&TR==FR-1&&TC==FC+1&&TR!=FR+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].Code!=NONE&&TR==FR-1&&TC==FC-1&&TR!=FR+1)
        {
            return 1;
        }
    }
    if(Game.TurningPlayer==BLACK)
    {
        if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE && Game.Board[TR-1][TC].Code==NONE && TR==FR+2 && TC==FC && FR==1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==WHITE && Game.Board[TR-1][TC].Code==NONE && TR==FR+2 && TC==FC && FR==1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor!=Game.Board[FR][FC].PieceColor&&Game.Board[TR][TC].Code!=NONE&&TR==FR+1&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor!=Game.Board[FR][FC].PieceColor&&Game.Board[TR][TC].Code!=NONE&&TR==FR+1&&TC==FC-1)
        {
            return 1;
        }
    }
    return 0;
}
int ROOKX(GameData& Game,int FR,int FC,int TR,int TC)
{
    if(Game.TurningPlayer==WHITE)
    {
        if(Game.Board[TR][TC].PieceColor==BLACK)
        {
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }


            for(int i=FR-1; i>TR; i--)
            {
                int a5=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==a5-1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a5-1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto l;
                }
            }
l:
            //for down
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR+1; i<TR; i++)
            {
                int a6=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==a6+1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a6+1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto k;
                }
            }
k:
            //for left
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC-1; j>TC; j--)
            {
                int a7=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto j;
                }
            }
j:
            //for right
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC+1; j<TC; j++)
            {
                int a8=j;
                if(Game.Board[FR][a8].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR&&TC==a8+1)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto i;
                }
            }
i:
            ;
        }
        if(Game.Board[TR][TC].Code==NONE)
        {

            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }


            for(int i=FR-1; i>TR; i--)
            {
                int a5=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==a5-1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a5-1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto l1;
                }
            }
l1:
            //for down
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR+1; i<TR; i++)
            {
                int a6=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==a6+1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a6+1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto k1;
                }
            }
k1:
            //for left
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC-1; j>TC; j--)
            {
                int a7=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto j1;
                }
            }
j1:
            //for right
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC+1; j<TC; j++)
            {
                int a8=j;
                if(Game.Board[FR][a8].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR&&TC==a8+1)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto i1;
                }
            }
i1:
            ;



        }

    }



    if(Game.TurningPlayer==BLACK)
    {
        if(Game.Board[TR][TC].PieceColor==WHITE)
        {
            //for up
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==FR+1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR+1; i<TR; i++)
            {
                int a5=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==a5+1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a5+1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto failed;
                }
            }
            //for down
failed:
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==FR-1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR-1; i>TR; i--)
            {
                int a6=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==a6-1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a6-1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto a;
                }
            }
a:
            //for left
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==FC-1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC-1; j>TC; j--)
            {
                int a7=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto b;
                }
            }
b:
            //for right
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==FC+1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC+1; j<TC; j++)
            {
                int a8=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto c;
                }
            }
c:
            ;
        }
        if(Game.Board[TR][TC].Code==NONE)
        {

            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==FR+1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR+1; i<TR; i++)
            {
                int a5=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==a5+1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a5+1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto failed1;
                }
            }
            //for down
failed1:
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==FR-1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR-1; i>TR; i--)
            {
                int a6=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==a6-1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a6-1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto a1;
                }
            }
a1:
            //for left
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==FC-1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC-1; j>TC; j--)
            {
                int a7=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto b1;
                }
            }
b1:
            //for right
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==FC+1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC+1; j<TC; j++)
            {
                int a8=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto c1;
                }
            }
c1:
            ;


        }

    }
    return 0;
}

int KNIGHTX(GameData& Game,int FR,int FC,int TR,int TC)
{
    if(Game.TurningPlayer==WHITE)
    {
        if(Game.Board[TR][TC].PieceColor==BLACK||Game.Board[TR][TC].Code==NONE)
        {
            if(TR==FR-2&&TC==FC+1)
            {
                return 1;
            }
            if(TR==FR-2&&TC==FC-1)
            {
                return 1;
            }
            if(TR==FR+2&&TC==FC+1)
            {
                return 1;
            }
            if(TR==FR+2&&TC==FC-1)
            {
                return 1;
            }
            if(TC==FC+2&&TR==FR-1)
            {
                return 1;
            }
            if(TC==FC+2&&TR==FR+1)
            {
                return 1;
            }
            if(TC==FC-2&&TR==FR-1)
            {
                return 1;
            }
            if(TC==FC-2&&TR==FR+1)
            {
                return 1;
            }
        }
    }
    if(Game.TurningPlayer==BLACK)
    {
        if(Game.Board[TR][TC].PieceColor==WHITE||Game.Board[TR][TC].Code==NONE)
        {
            if(TR==FR+2&&TC==FC+1)
            {
                return 1;
            }
            if(TR==FR+2&&TC==FC-1)
            {
                return 1;
            }
            if(TR==FR-2&&TC==FC+1)
            {
                return 1;
            }
            if(TR==FR-2&&TC==FC-1)
            {
                return 1;
            }
            if(TC==FC-2&&TR==FR-1)
            {
                return 1;
            }
            if(TC==FC-2&&TR==FR+1)
            {
                return 1;
            }
            if(TC==FC+2&&TR==FR-1)
            {
                return 1;
            }
            if(TC==FC+2&&TR==FR+1)
            {
                return 1;
            }
        }
    }
    return 0;
}
int BISHOPX(GameData& Game,int FR,int FC,int TR,int TC)
{
    int i;
    int j;
    if(Game.TurningPlayer==WHITE)
    {
        //right up
        if(TR==FR-1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
        {
            return 1;
        }
        if(TR==FR-1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }
        for(i=FR-1,j=FC+1; i>TR&&j<TC; i--,j++)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==BLACK&&TR==a-1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a-1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }

            }
            else
            {
                goto q;
            }
        }
q:
        //left up
        if(TR==FR-1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
        {
            return 1;
        }
        if(TR==FR-1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }
        for(i=FR-1,j=FC-1; i>TR&&j>TC; i--,j--)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==BLACK&&TR==a-1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a-1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto w;
            }
        }
w:
        //left down
        if(TR==FR+1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
        {
            return 1;
        }
        if(TR==FR+1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR+1,j=FC-1; i<TR&&j>TC; i++,j--)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(TR==a+1&&TC==b-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
                {
                    return 1;
                }
                if(TR==a+1&&TC==b-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
                {
                    return 1;
                }

            }
            else
            {
                goto e;
            }
        }
e:
        //right down
        if(TR==FR+1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
        {
            return 1;
        }
        if(TR==FR+1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR+1,j=FC+1; i<TR&&j<TC; i++,j++)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==BLACK&&TR==a+1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(TR==a+1&&TC==b+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
                {
                    return 1;
                }
            }
            else
            {
                goto r;
            }
        }
r:
        ;
    }
    if(Game.TurningPlayer==BLACK)
    {
        //just opposite signs of rows particles for black all funtions
        //right up
        if(TR==FR-1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==WHITE)
        {
            return 1;
        }
        if(TR==FR-1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR-1,j=FC+1; i>TR&&j<TC; i--,j++)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==WHITE&&TR==a-1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a-1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto t;
            }
        }
t:
        //left up
        if(TR==FR-1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==WHITE)
        {
            return 1;
        }
        if(TR==FR-1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR-1,j=FC-1; i>TR&&j>TC; i--,j--)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==WHITE&&TR==a-1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a-1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto y;
            }
        }
y:
        //left down
        if(TR==FR+1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==WHITE)
        {
            return 1;
        }
        if(TR==FR+1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR+1,j=FC-1; i<TR&&j>TC; i++,j--)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==WHITE&&TR==a+1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a+1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto u;
            }
        }
u:
        //right down
        if(TR==FR+1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==WHITE)
        {
            return 1;
        }
        if(TR==FR+1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR+1,j=FC+1; i<TR&&j<TC; i++,j++)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==WHITE&&TR==a+1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a+1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto o;
            }
        }
o:
        ;
    }
    return 0;
}
int KINGX(GameData& Game,int FR,int FC,int TR,int TC)
{
    if(Game.TurningPlayer==WHITE)
    {
        if(Game.Board[TR][TC].PieceColor==BLACK&&TR==FR-1&&TC==FC)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK&&TR==FR-1&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK&&TR==FR&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK&&TR==FR+1&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK&&TR==FR+1&&TC==FC)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK&&TR==FR+1&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK&&TR==FR&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==BLACK&&TR==FR-1&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC+1)
        {
            return 1;
        }
    }
    if(Game.TurningPlayer==BLACK)
    {
        if(Game.Board[TR][TC].PieceColor==WHITE&&TR==FR+1&&TC==FC)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==WHITE&&TR==FR+1&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==WHITE&&TR==FR&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==WHITE&&TR==FR-1&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC-1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==WHITE&&TR==FR-1&&TC==FC)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==WHITE&&TR==FR-1&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==WHITE&&TR==FR&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].PieceColor==WHITE&&TR==FR+1&&TC==FC+1)
        {
            return 1;
        }
        if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC+1)
        {
            return 1;
        }
    }
    return 0;
}
int QUEENX(GameData& Game,int FR,int FC,int TR,int TC)
{
    if(Game.TurningPlayer==WHITE)
    {
        if(Game.Board[TR][TC].PieceColor==BLACK)
        {
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }


            for(int i=FR-1; i>TR; i--)
            {
                int a5=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==a5-1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a5-1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto l;
                }
            }
l:
            //for down
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR+1; i<TR; i++)
            {
                int a6=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==a6+1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a6+1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto k;
                }
            }
k:
            //for left
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC-1; j>TC; j--)
            {
                int a7=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto j;
                }
            }
j:
            //for right
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC+1; j<TC; j++)
            {
                int a8=j;
                if(Game.Board[FR][a8].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR&&TC==a8+1)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto i;
                }
            }
i:
            ;
        }
        if(Game.Board[TR][TC].Code==NONE)
        {

            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }


            for(int i=FR-1; i>TR; i--)
            {
                int a5=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==a5-1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a5-1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto l1;
                }
            }
l1:
            //for down
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR+1; i<TR; i++)
            {
                int a6=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==a6+1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a6+1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto k1;
                }
            }
k1:
            //for left
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC-1; j>TC; j--)
            {
                int a7=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto j1;
                }
            }
j1:
            //for right
            if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC+1; j<TC; j++)
            {
                int a8=j;
                if(Game.Board[FR][a8].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==BLACK&&Game.Board[TR][TC].PieceColor!=WHITE&&TR==FR&&TC==a8+1)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto i1;
                }
            }
i1:
            ;



        }

    }



    if(Game.TurningPlayer==BLACK)
    {
        if(Game.Board[TR][TC].PieceColor==WHITE)
        {
            //for up
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==FR+1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR+1; i<TR; i++)
            {
                int a5=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==a5+1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a5+1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto failed;
                }
            }
            //for down
failed:
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==FR-1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR-1; i>TR; i--)
            {
                int a6=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==a6-1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a6-1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto a;
                }
            }
a:
            //for left
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==FC-1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC-1; j>TC; j--)
            {
                int a7=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto b;
                }
            }
b:
            //for right
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==FC+1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC+1; j<TC; j++)
            {
                int a8=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto c;
                }
            }
c:
            ;
        }
        if(Game.Board[TR][TC].Code==NONE)
        {

            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==FR+1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR+1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR+1; i<TR; i++)
            {
                int a5=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==a5+1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a5+1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto failed1;
                }
            }
            //for down
failed1:
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==FR-1&&TC==FC)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TR==FR-1&&TC==FC)
            {
                return 1;
            }

            for(int i=FR-1; i>TR; i--)
            {
                int a6=i;
                if(Game.Board[i][FC].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TR==a6-1&&TC==FC)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TR==a6-1&&TC==FC)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto a1;
                }
            }
a1:
            //for left
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==FC-1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC-1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC-1; j>TC; j--)
            {
                int a7=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a7-1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto b1;
                }
            }
b1:
            //for right
            if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==FC+1&&TR==FR)
            {
                return 1;
            }
            if(Game.Board[TR][TC].Code==NONE&&TC==FC+1&&TR==FR)
            {
                return 1;
            }

            for(int j=FC+1; j<TC; j++)
            {
                int a8=j;
                if(Game.Board[FR][j].Code==NONE)
                {
                    if(Game.Board[TR][TC].PieceColor==WHITE&&Game.Board[TR][TC].PieceColor!=BLACK&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                    if(Game.Board[TR][TC].Code==NONE&&TC==a8+1&&TR==FR)
                    {
                        return 1;
                    }
                }
                else
                {
                    goto c1;
                }
            }
c1:
            ;


        }

    }


    int i;
    int j;
    if(Game.TurningPlayer==WHITE)
    {
        //right up
        if(TR==FR-1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
        {
            return 1;
        }
        if(TR==FR-1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }
        for(i=FR-1,j=FC+1; i>TR&&j<TC; i--,j++)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==BLACK&&TR==a-1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a-1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }

            }
            else
            {
                goto q;
            }
        }
q:
        //left up
        if(TR==FR-1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
        {
            return 1;
        }
        if(TR==FR-1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }
        for(i=FR-1,j=FC-1; i>TR&&j>TC; i--,j--)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==BLACK&&TR==a-1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a-1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto w;
            }
        }
w:
        //left down
        if(TR==FR+1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
        {
            return 1;
        }
        if(TR==FR+1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR+1,j=FC-1; i<TR&&j>TC; i++,j--)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(TR==a+1&&TC==b-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
                {
                    return 1;
                }
                if(TR==a+1&&TC==b-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
                {
                    return 1;
                }

            }
            else
            {
                goto e;
            }
        }
e:
        //right down
        if(TR==FR+1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==BLACK)
        {
            return 1;
        }
        if(TR==FR+1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR+1,j=FC+1; i<TR&&j<TC; i++,j++)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==BLACK&&TR==a+1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(TR==a+1&&TC==b+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
                {
                    return 1;
                }
            }
            else
            {
                goto r;
            }
        }
r:
        ;
    }
    if(Game.TurningPlayer==BLACK)
    {
        //just opposite signs of rows particles for black all funtions
        //right up
        if(TR==FR-1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==WHITE)
        {
            return 1;
        }
        if(TR==FR-1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR-1,j=FC+1; i>TR&&j<TC; i--,j++)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==WHITE&&TR==a-1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a-1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto t;
            }
        }
t:
        //left up
        if(TR==FR-1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==WHITE)
        {
            return 1;
        }
        if(TR==FR-1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR-1,j=FC-1; i>TR&&j>TC; i--,j--)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==WHITE&&TR==a-1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a-1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto y;
            }
        }
y:
        //left down
        if(TR==FR+1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==WHITE)
        {
            return 1;
        }
        if(TR==FR+1&&TC==FC-1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR+1,j=FC-1; i<TR&&j>TC; i++,j--)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==WHITE&&TR==a+1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a+1&&TC==b-1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto u;
            }
        }
u:
        //right down
        if(TR==FR+1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].PieceColor==WHITE)
        {
            return 1;
        }
        if(TR==FR+1&&TC==FC+1&&TR!=FR&&TC!=FC&&Game.Board[TR][TC].Code==NONE)
        {
            return 1;
        }

        for(i=FR+1,j=FC+1; i<TR&&j<TC; i++,j++)
        {
            int a=i;
            int b=j;
            if(Game.Board[i][j].Code==NONE)
            {
                if(Game.Board[TR][TC].PieceColor==WHITE&&TR==a+1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
                if(Game.Board[TR][TC].Code==NONE&&TR==a+1&&TC==b+1&&TR!=FR&&TC!=FC)
                {
                    return 1;
                }
            }
            else
            {
                goto o;
            }
        }
o:
        ;
    }




    return 0;
}
bool isValidMove(GameData& Game, chessMove Move)
{
    // this function will return true if the move specified by the Move parameter is a valid move
    // You might make more functions to breakdown the task of this function into subtasks

    int FR, FC, TR,TC;
    FR = Move.FromRow;
    FC = Move.FromColumn;
    TR = Move.ToRow;
    TC = Move.ToColumn;
    if(Game.Board[FR][FC].Code==PAWN)
    {
        int x1=PAWNX(Game,FR,FC,TR,TC);
        if(x1==1)
        {
            return true;
        }

    }


    if(Game.Board[FR][FC].Code==KNIGHT)
    {
        int x4=KNIGHTX(Game,FR,FC,TR,TC);
        if(x4==1)
        {
            return true;
        }
    }
    if(Game.Board[FR][FC].Code==BISHOP)
    {
        int x3=BISHOPX(Game,FR,FC,TR,TC);
        if(x3==1)
        {
            return true;
        }
    }
    if(Game.Board[FR][FC].Code==KING)
    {
        int x6=KINGX(Game,FR,FC,TR,TC);
        if(x6==1)
        {
            return true;
        }
    }
    if(Game.Board[FR][FC].Code==QUEEN)
    {
        int x5=QUEENX(Game,FR,FC,TR,TC);
        if(x5==1)
        {
            return true;
        }
    }
    if(Game.Board[FR][FC].Code==ROOK)
    {
        int x2=ROOKX(Game,FR,FC,TR,TC);
        if(x2==1)
        {
            return true;
        }
    }

    return false;
}
int MakeMove(GameData& Game, chessMove Move)
{
    //Function to make a move on the board
    // It will return 0 if the move is valid and a code of error to specify why the move is not valid otherwise

    // Follwoing is a very simple move example. Your code will support all types of moves including pawn promotion, castling and En Passant etc. Furthermore i must also add the move in the vector of moves used for keeping history.

    if(!isValidMove(Game, Move))
        return 1;
    int FR, FC, TR,TC;
    FR = Move.FromRow;
    FC = Move.FromColumn;
    TR = Move.ToRow;
    TC = Move.ToColumn;
    if(FR==1&&Game.Board[FR][FC].Code==PAWN&&Game.TurningPlayer==WHITE)
    {
        PAWNPROMO(Game,FR,FC,TR,TC);
		goto bro;
    }
    if(FR==6&&Game.Board[FR][FC].Code==PAWN&&Game.TurningPlayer==BLACK)
    {
        PAWNPROMO(Game,FR,FC,TR,TC);
        goto bro1;
    }
    Game.Board[TR][TC].Code =
        Game.Board[FR][FC].Code;
    Game.Board[TR][TC].PieceColor =
        Game.Board[FR][FC].PieceColor;
    Game.Board[FR][FC].Code = NONE;
bro:
bro1:
    if(Game.TurningPlayer == BLACK)
        Game.TurningPlayer = WHITE;
    else
        Game.TurningPlayer = BLACK;

    return 0;
}
void initGame(GameData& Game)
{

    for(int r = 0; r < 2; r++)
        for(int c= 0; c < 8; c++ )
            Game.Board[r][c].PieceColor = BLACK;

    for(int r = 2; r < 6; r++)
        for(int c= 0; c < 8; c++ )
            Game.Board[r][c].Code = NONE;

    for(int r = 6; r < 8; r++)
        for(int c= 0; c < 8; c++ )
            Game.Board[r][c].PieceColor = WHITE;


    Game.Board[0][0].Code = Game.Board[0][7].Code = ROOK;
    Game.Board[7][0].Code = Game.Board[7][7].Code = ROOK;

    Game.Board[0][1].Code = Game.Board[0][6].Code = KNIGHT;
    Game.Board[7][1].Code = Game.Board[7][6].Code = KNIGHT;

    Game.Board[0][2].Code = Game.Board[0][5].Code = BISHOP;
    Game.Board[7][2].Code = Game.Board[7][5].Code = BISHOP;

    Game.Board[0][3].Code = Game.Board[7][3].Code = QUEEN;
    Game.Board[0][4].Code = Game.Board[7][4].Code = KING;

    for(int c= 0; c < 8; c++ )
        Game.Board[1][c].Code = Game.Board[6][c].Code = PAWN;

    Game.TurningPlayer = WHITE;

    Game.MoveHistory = vector<chessMove>(1);
    return;
}

bool isfacingCheck(GameData& Game, Color Player)
{
    // This function must return true if player having Color Player is facing a check
    //XXX=FROM ROW AND YYY=FROM COLUMN
    int tr,tc,XXX,YYY;
    chessMove Move;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(Game.Board[i][j].Code==KING && Game.Board[i][j].PieceColor==Game.TurningPlayer&&Game.Board[i][j].Code!=NONE)
            {
                tr=i;
                tc=j;
            }
        }

    }
    if(Game.TurningPlayer == BLACK)
        Game.TurningPlayer = WHITE;
    else
        Game.TurningPlayer = BLACK;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            XXX=i;
            YYY=j;
            Move.FromRow=XXX;
            Move.FromColumn=YYY;
            Move.ToRow=tr;
            Move.ToColumn=tc;
            if(Game.Board[i][j].PieceColor==Game.TurningPlayer)
            {
                if(isValidMove(Game,Move))
                {
                    if(Game.TurningPlayer == BLACK)
                        Game.TurningPlayer = WHITE;
                    else
                        Game.TurningPlayer = BLACK;

                    return true;
                }
            }
        }
    }
    if(Game.TurningPlayer == BLACK)
        Game.TurningPlayer = WHITE;
    else
        Game.TurningPlayer = BLACK;
    return false;
}
bool isCheckmate(GameData& Game, Color Player)
{
    // This function must return true if player having Color Player is facing a checkmate
    return false;
}
void UNDO(int MoveCount)
{
    // A function to undo a number of moves
    return;
}
int SaveGame(string FileName)
{
    //Function to save a game data into a file.


}
int LoadGame (string FileName)
{
    // function to load games data from a file
}
