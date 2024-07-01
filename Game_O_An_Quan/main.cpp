#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#define MAXX 800
#define MAXY 550
#define BGC 3
#define BGC2 10
#define ARC 12
#define Y 270

struct Point
{
    int x;
    int y;
};

int HienTai = 0, DaiDan = 0;
char c;
int Player, DaChon = 0, Game = 1;
int Score[2] = {0, 0};
int Computer, Diff;
char TextPlayer[2][9];
char TextPvP[][9] = {"Player 2", "Player 1"};
char TextPvC[][9] = {"Computer", "Player"};
char TxtSpace[] = "              ";
char TxtEasy[] = "Easy";
char TxtNormal[] = "Normal";
char TxtOAnQuan[] = "O An Quan";

int Abs(int x)
{
    return x > 0 ? x : -x;
}

void BackGround()
{
    int n = 8;
    setcolor(8);
    setfillstyle(1, 15);
    for (int i = 1; i < n; i++)
        rectangle(i, i, MAXX - i, MAXY - i);
    bar(n + 1, n + 1, MAXX - n, MAXY - n);
}

Point tdd[] = {{0, 0},
               {0, 0},
               {-25, -25},
               {25, -25},
               {-25, 25},
               {25, 25},
               {0, -25},
               {-25, 0},
               {25, 0},
               {0, 25},
               {-12, -12},
               {12, -12},
               {-12, 12},
               {12, 12},
               {-12, -25},
               {12, -25},
               {-12, 25},
               {12, 25},
               {-25, -12},
               {25, -12},
               {-25, 12},
               {25, 12}};
Point tddq[] = {{0, 0},
                {35, -75},
                {35, -60},
                {35, -45},
                {35, -30},
                {35, -15},
                {35, 0},
                {35, 15},
                {35, 30},
                {35, 45},
                {35, 60},
                {35, 75},
                {20, -75},
                {20, -60},
                {20, -45},
                {20, -30},
                {20, -15},
                {20, 0},
                {20, 15},
                {20, 30},
                {20, 45},
                {20, 60},
                {20, 75}};

class OAnQuan
{
  private:
  public:
    int conQuan;
    int soDan;
    void veDan();
} oaq[12];

void OAnQuan::veDan()
{
    int n, m;
    setcolor(8);
    if (HienTai % 6 == 0) {
        n = (HienTai + 1) * 100;
        circle(n + (1 - HienTai / 3) * tddq[this->soDan].x, Y + tddq[this->soDan].y, 3);
    } else {
        int n = (7 - Abs(6 - HienTai)) * 100;
        int m = Y - 50 + (HienTai / 6) * 100;
        circle(n + tdd[this->soDan].x, m + tdd[this->soDan].y, 3);
    }
}

void VeDan(int soO, int soDan)
{
    int n = (7 - Abs(6 - soO)) * 100;
    int m = Y - 50 + (soO / 6) * 100;
    circle(n + tdd[soDan].x, m + tdd[soDan].y, 3);
}

void VeQuan(int soO)
{
    int n = (soO + 1) * 100;
    ellipse(n, Y, 0, 360, 10, 20);
    setfillstyle(1, 4);
    floodfill(n, Y, 8);
}

void XoaQuan()
{
    setfillstyle(1, BGC2);
    setcolor(BGC2);
    if (HienTai == 0)
    {
    	pieslice(147, Y, 90, 270, 95);
    }
    else
    {
    	pieslice(653, Y, -90, 90, 95);
    }
}

void VeBan()
{
    line(150, Y - 100, 650, Y - 100);
    line(150, Y + 100, 650, Y + 100);
    arc(150, Y, 90, 270, 100);
    arc(650, Y, -90, 90, 100);
    setfillstyle(1, 10);
    floodfill(400, Y, 8);
    for (int i = 0; i <= 5; i++)
    {
    	line(150 + 100 * i, Y - 100, 150 + 100 * i, Y + 100);
    }
    line(150, Y, 650, Y);
    for (int i = 0; i < 12; i++)
	{
        if (i % 6)
		{
            for (int j = 1; j <= 5; j++)
            {
            	VeDan(i, j);
            }
        }
		else
		{
			VeQuan(i);
		}
    }
}

void XoaO()
{
    int n = (7 - Abs(6 - HienTai)) * 100;
    int m = Y - 50 + (HienTai / 6) * 100;
    setfillstyle(1, BGC2);
    bar(n - 48, m - 48, n + 49, m + 49);
}

void VeMuiTen()
{
    int m, n = (7 - Abs(6 - HienTai)) * 100;
    int k = (HienTai / 6) * 2 - 1;
    m = Y + k * 110;
    setcolor(ARC);
    line(n, m, n, m + 30 * k);
    line(n, m, n + 10 * k, m + 10 * k);
    line(n, m, n - 10 * k, m + 10 * k);
}
void XoaMuiTen()
{
    int m, n = (7 - Abs(6 - HienTai)) * 100;
    int k = (HienTai / 6) * 2 - 1;
    m = Y + k * 110;
    setcolor(15);
    line(n, m, n, m + 30 * k);
    line(n, m, n + 10 * k, m + 10 * k);
    line(n, m, n - 10 * k, m + 10 * k);
}

void ChonO()
{
    int n = (7 - Abs(6 - HienTai)) * 100;
    int m = Y - 50 + (HienTai / 6) * 100;
    setcolor(1);
    line(n - 24, m - 44, n - 44, m - 44);
    line(n - 44, m - 44, n - 44, m - 24);
    line(n + 24, m + 44, n + 44, m + 44);
    line(n + 44, m + 44, n + 44, m + 24);
}

void BoChonO()
{
    int n = (7 - Abs(6 - HienTai)) * 100;
    int m = Y - 50 + (HienTai / 6) * 100;
    setcolor(BGC2);
    line(n - 24, m - 44, n - 44, m - 44);
    line(n - 44, m - 44, n - 44, m - 24);
    line(n + 24, m + 44, n + 44, m + 44);
    line(n + 44, m + 44, n + 44, m + 24);
}

void UpdateScore()
{
    char *text = new char[14];
    sprintf(text, "%s: %d ", TextPlayer[Player], Score[Player]);
    setcolor(0);
    outtextxy(100, 50 + Player * 380, text);
    delete[] text;
}

void UpdateRemain(int Remain)
{
    char *text = new char[15];
    sprintf(text, "Remaining: %d ", Remain);
    setcolor(0);
    outtextxy(100, 90 + Player * 380, text);
    delete[] text;
}

void ClearRemain()
{
    outtextxy(100, 90 + Player * 380, TxtSpace);
}

void EndGame()
{
    char *text = new char[20];
    setcolor(0);
    sprintf(text, "%s: %d", TextPlayer[1], Score[1]);
    outtextxy(100, 170, text);
    sprintf(text, "%s: %d", TextPlayer[0], Score[0]);
    outtextxy(100, 250, text);
    sprintf(text, "Winner: %s", TextPlayer[Score[0] > Score[1] ? 0 : 1]);
    outtextxy(100, 330, text);
    delete[] text;
}

int PlayerTurn()
{
    int mx;
    while (DaChon != 2)
	{
        c = getch();
        switch (c)
		{
        	case 75:
            	if (DaChon == 0)
				{
                	XoaMuiTen();
                	do {
                    	HienTai -= (1 - 2 * Player);
                    	if (HienTai == Player * 12)
                        	HienTai = Player * 2 + 5;
                	} while (oaq[HienTai].soDan == 0);
                	VeMuiTen();
            	}
				else
				{
                	DaChon = 2;
                	mx = Player * 2 - 1;
            	}
            	break;
        	case 77:
            	if (DaChon == 0)
				{
                	XoaMuiTen();
                	do
					{
                    	HienTai += (1 - 2 * Player);
                    	if (HienTai == 6)
                    	{
                    		HienTai = Player * 10 + 1;
                    	}
                	} while (oaq[HienTai].soDan == 0);
                	VeMuiTen();
            	}
				else
				{
                	DaChon = 2;
                	mx = 1 - Player * 2;
            	}
            	break;
        	case 13:
            	if (DaChon == 0)
				{
                	UpdateRemain(oaq[HienTai].soDan);
                	ChonO();
                	DaChon = 1;
            	}
				else
				{
                	ClearRemain();
                	BoChonO();
                	DaChon = 0;
            	}
            	break;
        }
    }
    return mx;
}

int Calculate(int ComHT, int mx)
{
    int tmp = 0;
    OAnQuan ComOaq[12];
    for (int i = 0; i < 12; i++)
	{
        ComOaq[i].soDan = oaq[i].soDan;
        if (i % 6 == 0)
        {
        	ComOaq[i].conQuan = oaq[i].conQuan;
        }
    }
    int ComDD = ComOaq[ComHT].soDan;
    ComOaq[ComHT].soDan = 0;
    while (true)
	{
        if (ComDD == 0)
		{
            ComHT += mx;
            if (ComHT == 12)
            {
            	ComHT = 0;
            }
            else if (ComHT == -1)
            {
            	ComHT = 11;
            }
            if (ComHT % 6)
			{
                ComDD = ComOaq[ComHT].soDan;
                if (ComDD == 0)
				{
                    do
					{
                        ComHT += mx;
                        if (ComHT == 12)
                        {
                        	ComHT = 0;
                        }
                        else if (ComHT == -1)
                        {
                        	ComHT = 11;
                        }
                        else
                        {
                        }
                        if (ComHT % 6 == 0) 
						{
                            if (ComOaq[ComHT].conQuan) 
							{
                                if (ComOaq[ComHT].soDan >= 5) 
								{
                                    tmp += (ComOaq[ComHT].soDan + 10);
                                    ComOaq[ComHT].soDan = 0;
                                    ComOaq[ComHT].conQuan = 0;
                                }
								else
								{
									break;
								}
                            }
							else if (ComOaq[ComHT].soDan > 0) 
							{
                                tmp += ComOaq[ComHT].soDan;
                                ComOaq[ComHT].soDan = 0;
                            }
							else
							{
								break;
							}
                        }
						else if (ComOaq[ComHT].soDan > 0) 
						{
                            tmp += ComOaq[ComHT].soDan;
                            ComOaq[ComHT].soDan = 0;
                        }
						else
						{
							break;
						}
                        ComHT += mx;
                        if (ComHT == 12)
                        {
                            ComHT = 0;
                    	}
                        else if (ComHT == -1)
                        {
                        	ComHT = 11;
                        }
                        ComDD = ComOaq[ComHT].soDan;
                    } while (ComDD == 0);
                    break;
                }
                ComOaq[ComHT].soDan = 0;
            }
			else
                break;
        }
        ComDD--;
        ComHT += mx;
        if (ComHT == 12)
            ComHT = 0;
        else if (ComHT == -1)
            ComHT = 11;
        ComOaq[ComHT].soDan++;
    }
    return tmp;
}

int CalculateMax(int &mx)
{
    int max = Calculate(HienTai, 1);
    int Cell = HienTai, k = Calculate(HienTai, -1), Current = HienTai + 1;
    mx = 1;
    if (k > max)
	{
        max = k;
        mx = -1;
    }
    while (Current < 6)
	{
        if (oaq[Current].soDan > 0)
		{
            k = Calculate(Current, 1);
            if (k > max)
			{
                Cell = Current;
                max = k;
                mx = 1;
            }
            k = Calculate(Current, -1);
            if (k > max)
			{
                Cell = Current;
                max = k;
                mx = -1;
            }
        }
        Current++;
    }
    return Cell;
}

int ComputerTurn()
{
    int Cell, mx;
    if (Diff == 1)
	{
        int n = rand() % 5;
        mx = rand() % 2 * 2 - 1;
        delay(400);
        for (int i = 0; i < n; i++)
		{
            XoaMuiTen();
            do
			{
                HienTai++;
                if (HienTai == 6)
                    HienTai = 1;
            } while (oaq[HienTai].soDan == 0);
            VeMuiTen();
            delay(400);
        }
    }
	else
	{
        Cell = CalculateMax(mx);
        delay(400);
        int i = 0;
        while (HienTai != Cell)
		{
            XoaMuiTen();
            do
			{
                HienTai++;
            } while (oaq[HienTai].soDan == 0);
            VeMuiTen();
            delay(400);
        }
    }
    UpdateRemain(oaq[HienTai].soDan);
    ChonO();
    delay(400);
    return mx;
}

int PvP()
{
    return PlayerTurn();
}

int PvC()
{
    if (Player == 0)
        return ComputerTurn();
    	return PlayerTurn();
}

void MenuArrow(int Choice)
{
    Choice *= 100;
    line(180, 280 + Choice, 200, 280 + Choice);
    line(180, 290 + Choice, 200, 290 + Choice);
    line(193, 273 + Choice, 205, 285 + Choice);
    line(193, 297 + Choice, 205, 285 + Choice);
}

int Difficult()
{
    int Choice = 0, tmp = 0;
    setbkcolor(15);
    setfillstyle(1, 15);
    setcolor(8);
    for (int i = 1; i < 6; i++)
	{
        rectangle(568 - 20 * i, 333 - 12 * i, 572 + 20 * i, 337 + 12 * i);
        bar(570 - 20 * i, 335 - 12 * i, 570 + 20 * i, 335 + 12 * i);
        delay(40);
    }
    setcolor(4);
    outtextxy(544, 293, TxtEasy);
    outtextxy(535, 342, TxtNormal);
    line(495, 310, 515, 310);
    line(508, 303, 515, 310);
    line(508, 317, 515, 310);
    while (true)
	{
        c = getch();
        switch (c)
		{
        	case 72:
        	case 75:
        	case 77:
        	case 80:
            	setcolor(15);
            	line(495, 310 + tmp, 515, 310 + tmp);
            	line(508, 303 + tmp, 515, 310 + tmp);
            	line(508, 317 + tmp, 515, 310 + tmp);
            	Choice = 1 - Choice;
            	tmp = Choice * 48;
            	setcolor(4);
            	line(495, 310 + tmp, 515, 310 + tmp);
            	line(508, 303 + tmp, 515, 310 + tmp);
            	line(508, 317 + tmp, 515, 310 + tmp);
            	break;
        	case 13:
            	return Choice + 1;
        	case 27:
            	return 0;
        }
    }
}

void ClearDiff()
{
    setfillstyle(1, 15);
    bar(467, 272, 673, 398);
}

void MenuGame()
{
    BackGround();
    char TextMenu[][9] = {"1 Player", "2 Player"};
    int Choice = 0;
    char c;
    setbkcolor(15);
    settextstyle(4, 0, 8);
    setcolor(5);
    outtextxy(90, 70, TxtOAnQuan);
    setlinestyle(0, 0, 7);
    line(123, 73, 138, 66);
    line(153, 73, 138, 66);
    line(247, 66, 262, 73);
    line(277, 66, 262, 73);
    setcolor(8);
    setlinestyle(0, 0, 2);
    rectangle(220, 250, 420, 320);
    rectangle(200, 350, 400, 420);
    settextstyle(10, 0, 4);
    setcolor(2);
    MenuArrow(0);
    outtextxy(246, 270, TextMenu[0]);
    setcolor(12);
    outtextxy(226, 370, TextMenu[1]);
    while (true)
	{
        c = getch();
        switch (c)
		{
        	case 72:
        	case 75:
        	case 77:
        	case 80:
            	setcolor(15);
            	outtextxy(246, 270 + Choice * 100, TextMenu[Choice]);
            	outtextxy(226, 370 - Choice * 100, TextMenu[1 - Choice]);
            	rectangle(220, 250 + Choice * 100, 420, 320 + Choice * 100);
            	rectangle(200, 350 - Choice * 100, 400, 420 - Choice * 100);
           		MenuArrow(Choice);
            	setcolor(8);
            	Choice = 1 - Choice;
            	rectangle(220, 250 + Choice * 100, 420, 320 + Choice * 100);
            	rectangle(200, 350 - Choice * 100, 400, 420 - Choice * 100);
            	setcolor(2);
            	MenuArrow(Choice);
            	outtextxy(246, 270 + Choice * 100, TextMenu[Choice]);
            	setcolor(12);
            	outtextxy(226, 370 - Choice * 100, TextMenu[1 - Choice]);
            	break;
        	case 13:
            	if (Choice == 1)
				{
                	Computer = 0;
                	return;
            	}
            	Diff = Difficult();
            	if (Diff)
				{
                	Computer = 1;
                	return;
            	}
            	ClearDiff();
            	setbkcolor(15);
            	break;
        }
    }
}

int main()
{
    srand(time(NULL));
    initwindow(MAXX + 9, MAXY + 13);
    MenuGame();
    if (Computer == 0)
	{
        strcpy(TextPlayer[0], TextPvP[0]);
        strcpy(TextPlayer[1], TextPvP[1]);
    }
	else
	{
        strcpy(TextPlayer[0], TextPvC[0]);
        strcpy(TextPlayer[1], TextPvC[1]);
    }
    int (*P[2])();
    P[0] = &PvP;
    P[1] = &PvC;
    BackGround();
    setbkcolor(15);
    settextstyle(10, 0, 3);
    int mx, tmp;
    for (int i = 0; i < 12; i++)
	{
        if (i % 6 == 0)
		{
            oaq[i].soDan = 0;
            oaq[i].conQuan = 1;
        }
		else
		{
			oaq[i].soDan = 5;
		}
    }
    VeBan();
    HienTai = 7;
    setcolor(0);
    Player = 0;
    UpdateScore();
    Player = 1;
    UpdateScore();
    while (true)
	{
        VeMuiTen();
        mx = P[Computer]();
        DaChon = 0;
        XoaMuiTen();
        DaiDan = oaq[HienTai].soDan;
        oaq[HienTai].soDan = 0;
        XoaO();
        while (true)
		{
            delay(400);
            if (DaiDan == 0)
			{
                HienTai += mx;
                if (HienTai == 12)
                {
                	HienTai = 0;
                }
                else if (HienTai == -1)
                {
                	HienTai = 11;
                }
                else
                {
                }
                if (HienTai % 6)
				{
                    XoaO();
                    DaiDan = oaq[HienTai].soDan;
                    UpdateRemain(DaiDan);
                    if (DaiDan == 0)
					{
                        do
						{
                            HienTai += mx;
                            if (HienTai == 12)
                            {
                            	HienTai = 0;
                            }
                            else if (HienTai == -1)
                            {
                            	HienTai = 11;
                            }
                            else
                            {
                            }
                            if (HienTai % 6 == 0)
							{
                                if (oaq[HienTai].conQuan)
								{
                                    if (oaq[HienTai].soDan >= 5)
									{
                                        Score[Player] += (oaq[HienTai].soDan + 10);
                                        UpdateScore();
                                        oaq[HienTai].soDan = 0;
                                        oaq[HienTai].conQuan = 0;
                                        XoaQuan();
                                        if (oaq[6 - HienTai].soDan == 0 && oaq[6 - HienTai].conQuan == 0)
                                            Game = 0;
                                    }
									else
									{
										break;
									}
                                }
								else if (oaq[HienTai].soDan > 0)
								{
                                    Score[Player] += oaq[HienTai].soDan;
                                    UpdateScore();
                                    oaq[HienTai].soDan = 0;
                                    XoaQuan();
                                    if (oaq[6 - HienTai].soDan == 0 && oaq[6 - HienTai].conQuan == 0)
                                    {
                                    	Game = 0;
                                    }
                                }
								else
								{
									break;
								}
                            }
							else if (oaq[HienTai].soDan > 0)
							{
                                Score[Player] += oaq[HienTai].soDan;
                                UpdateScore();
                                oaq[HienTai].soDan = 0;
                                XoaO();
                            }
							else
							{
								break;
							}
                            HienTai += mx;
                            if (HienTai == 12)
                            {
                            	HienTai = 0;
                            }
                            else if (HienTai == -1)
                            {
                            	HienTai = 11;
                            }
                            DaiDan = oaq[HienTai].soDan;
                            delay(400);
                        } while (DaiDan == 0);
                        break;
                    }
                    oaq[HienTai].soDan = 0;
                    delay(400);
                }
				else
				{
					break;
				}
            }
            DaiDan--;
            UpdateRemain(DaiDan);
            HienTai += mx;
            if (HienTai == 12)
            {
            	HienTai = 0;
            }
            else if (HienTai == -1)
            {
            	HienTai = 11;
            }
            oaq[HienTai].soDan++;
            oaq[HienTai].veDan();
        }
        if (!Game)
        {
        	break;
        }
        ClearRemain();
        Player = 1 - Player;
        tmp = 1;
        do
		{
            HienTai = 6 * Player + tmp;
            tmp++;
        } while (oaq[HienTai].soDan == 0 && tmp <= 5);
        if (oaq[HienTai].soDan == 0)
		{
            Score[Player] -= 5;
            UpdateScore();
            setcolor(8);
            for (int i = 1 + 6 * Player; i < 6 + 6 * Player; i++)
			{
                VeDan(i, 1);
                oaq[i].soDan = 1;
            }
            HienTai = 6 * Player + 1;
        }
    }
    for (int i = 1; i < 6; i++)
        Score[0] += oaq[i].soDan;
    for (int i = 7; i < 12; i++)
        Score[1] += oaq[i].soDan;
    cleardevice();
    BackGround();
    setcolor(0);
    EndGame();
    getch();
    closegraph();
    return 0;
}