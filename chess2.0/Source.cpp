#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
void test(int t[8][8],int &check) {
	int cp=0,co=0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (t[i][j] == -6 || t[i][j]==6) {
					if(t[i][j] == -6){
					cp = cp + 1;
					cout << cp << endl;
					}else if(t[i][j] == 6){
						co=co+1;
					}
				}
		if (cp == 0) {
			check = 0;
			cout<<"black wins the game: congrat"<<endl;
		}else if(co==0){
			check=0;
			cout<<"white wins the game: congrat"<<endl;
		}
}

void depart(int t[8][8], int& tj, int& x, int& y) {
	int i = 1;
	do {
		cout << endl << "donner le ligne de la piece a deplacer : "; cin >> x;

		cout << "donner la colonne de la piece a deplacer : "; cin >> y;
	
	} while (tj==1 && t[x][y]<0  || tj ==2 && t[x][y]>0 || x<0 || x>7 || y<0 || y>7 || tj==2 && t[x][y]==0 || tj==1 && t[x][y]==0 );

}


void ariver(int t[8][8],int& x1, int& y1,int tj)
{
	do {
		cout << "donner le ligne d'arriver : "; cin >> x1;
		cout << "donner la colonne d'arriver : "; cin >> y1;
	} while (x1 > 7 || x1 < 0 || y1>7 || y1 < 0 || tj==1 && t[x1][y1]>0 || tj ==2 && t[x1][y1]<0);
}

void pawn_white(int t[8][8],int  x, int y,int  x1,int  y1,int tj) {
	if (x == 6 && t[x1][y1] >= 0 && (x1==x-1 || x1==x-2)) 
	{
		int cp=0;
		bool c=true;
		while(x-cp!=x1 && c==true)
		{
			cp=cp+1;
			if(t[x-cp][y]==0)
			{
				c=true;
			}else if(t[x-cp][y+cp]>0){
				c=true;
			}else if(t[x-cp][y-cp]>0){
				c=true;
			}else{cp=0;c=false;}
		}
		if(cp!=0 && x1==x-cp && y1 == y)
		{
		t[x][y]=0;
		t[x-cp][y]=-1;
		}else if(cp==1 && t[x-cp][y-cp]==t[x1][y1]){
			t[x][y]=0;
			t[x-cp][y-cp]=0;
			t[x-cp][y-cp]=-1;
		}else if(cp==1 && t[x-cp][y+cp]==t[x1][y1]){
			t[x][y]=0;
			t[x-cp][y+cp]=0;
			t[x-cp][y+cp]=-1;
		}
	}else if(x!=6 && t[x1][y1]>=0 && (x1==x-1 && y==y1) || (x1==x-1 && y1==y+1) ||(x1==x-1 && y1==y-1))
	{
		int cp=0;
		bool c=true;
		while(x-cp!=x1 && c==true)
		{
			cp=cp+1;
			if(t[x-cp][y]==0)
			{
				c=true;
			}else if(t[x-cp][y+cp]>=0){
				c=true;
			}else if(t[x-cp][y-cp]>=0){
				c=true;
			}else{cp=0;c=false;}
		}
		if((cp==1 || cp==2) && t[x-cp][y]==t[x1][y1] && t[x1][y1]>=0)
		{
		t[x][y]=0;
		t[x-cp][y]=-1;
		}else if(cp==1 && t[x-cp][y-cp]==t[x1][y1] && t[x1][y1]>0){
			t[x][y]=0;
			t[x-cp][y-cp]=0;
			t[x-cp][y-cp]=-1;
		}else if(cp==1 && t[x-cp][y+cp]==t[x1][y1] && t[x1][y1]>0){
			t[x][y]=0;
			t[x-cp][y+cp]=0;
			t[x-cp][y+cp]=-1;
		}
	}

}

void pawn_black(int t[8][8],int x,int y,int x1,int y1,int tj) {
if (x == 1 && t[x1][y1] <= 0 && (x1==x+1 || x1==x+2)) 
	{
		int cp=0;
		bool c=true;
		while(x+cp!=x1 && c==true)
		{
			cp=cp+1;
			if(t[x+cp][y]==0)
			{
				c=true;
			}else if(t[x+cp][y+cp]<0){
				c=true;
			}else if(t[x+cp][y-cp]<0){
				c=true;
			}else{cp=0;c=false;}
		}
		if(cp!=0 && x1==x+cp && y1 == y)
		{
		t[x][y]=0;
		t[x+cp][y]=1;
		}else if(cp==1 && t[x+cp][y-cp]==t[x1][y1]){
			t[x][y]=0;
			t[x+cp][y-cp]=0;
			t[x+cp][y-cp]=1;
		}else if(cp==1 && t[x-cp][y+cp]==t[x1][y1]){
			t[x][y]=0;
			t[x+cp][y+cp]=0;
			t[x+cp][y+cp]=1;
		}
	}else if(x!=1 && t[x1][y1]<=0 && (x1==x+1 && y==y1) || (x1==x+1 && y1==y+1) ||(x1==x+1 && y1==y-1))
	{
		int cp=0;
		bool c=true;
		while(x+cp!=x1 && c==true)
		{
			cp=cp+1;
			if(t[x+cp][y]==0)
			{
				c=true;
			}else if(t[x+cp][y+cp]<=0){
				c=true;
			}else if(t[x+cp][y-cp]<=0){
				c=true;
			}else{cp=0;c=false;}
		}
		if((cp==1 || cp==2) && t[x+cp][y]==t[x1][y1] && t[x1][y1]<=0)
		{
		t[x][y]=0;
		t[x-cp][y]=1;
		}else if(cp==1 && t[x+cp][y-cp]==t[x1][y1] && t[x1][y1]<0){
			t[x][y]=0;
			t[x+cp][y-cp]=0;
			t[x+cp][y-cp]=1;
		}else if(cp==1 && t[x+cp][y+cp]==t[x1][y1] && t[x1][y1]<0){
			t[x][y]=0;
			t[x+cp][y+cp]=0;
			t[x+cp][y+cp]=1;
		}
	}
}
void rider_white(int t[8][8], int x, int y, int x1, int y1,int tj) {
	if (t[x1][y1]>=0 && x1==x-2) {
		if (y1 == y + 1) {
			t[x][y] = 0;
			if (t[x1][y1] != 0) { t[x - 2][y + 1] = 0; }
			t[x - 2][y + 1] = -2;
		}else if(y1==y-1) {
			t[x][y] = 0;
			if (t[x1][y1] != 0) { t[x + 2][y - 1] = 0; }
			t[x - 2][y-1] = -2;
		}
	} else if ( x1 == x + 2 && t[x1][y1]>=0 && (y1 == y - 1 || y1 == y + 1)) {
		cout <<"nani3"<< endl;
		cout<<y1<<x1<<endl;
		if (y1 == y - 1) {
			cout << y1 << x1 << endl;
			t[x][y] = 0;
			if (t[x1][y1] != 0) { t[x + 2][y - 1] = 0; }
			t[x + 2][y-1] = -2;
		}
		if(y1 == y + 1) {
			cout << y1 << x1 << endl;
			t[x][y] = 0;
			if (t[x1][y1] != 0) { t[x + 2][y + 1] = 0; }
			t[x + 2][y + 1] = -2;
		}
	}else if (t[x1][y1]>=0 && (x1 == x + 1 || x1 == x - 1) && (y1 == y - 2 || y1 == y + 2))
	 {
		 if (y1 == y - 2 && x1 == x - 1) {
			 t[x][y] = 0;
			 if (t[x1][y1] != 0) { t[x - 1][y - 2] = 0; }
			 t[x - 1][y - 2] = -2;
		 }
		 if (y1 == y - 2 && x1 == x + 1) {
			 t[x][y] = 0;
			 if (t[x1][y1] != 0) { t[x + 1][y - 2] = 0; }
			 t[x + 1][y - 2] = -2;
		 }
		 if (y1==y+2 && x1 == x-1 ) {
			 t[x][y] = 0;
			 if (t[x1][y1] != 0) { t[x - 1][y + 2] = 0; }
			 t[x - 1][y + 2] = -2;
		 }
		 if (y1 == y + 2 && x1 == x + 1) {
			 t[x][y] = 0;
			 if (t[x1][y1] != 0) { t[x + 1][y + 2] = 0; }
			 t[x + 1][y + 2] = -2;
		 }
	 }
}
void rider_black(int t[8][8], int x, int y, int x1, int y1,int tj) {
	cout << "working" << endl;
	//rider going top left or right///
	if (t[x1][y1]<=0 && x1==x+2) {
		cout << "working" << endl;
		t[x][y] = 0;
		if (y1 == y - 1) {
			t[x + 2][y - 1] = 2;
		}
		else if(y1==y+1){ t[x + 2][y + 1] = 2;}
	}else if (t[x1][y1]<=0 && x1 == x - 2 && (y1 == y - 1 || y1 == y + 1)) {
		cout << "nani3" << endl;
		cout << y1 << x1 << endl;
		if (y1 == y - 1) {
			cout << y1 << x1 << endl;
			t[x][y] = 0;
			t[x - 2][y - 1] = 2;
		}
		if(y1==y+1) {
			cout << y1 << x1 << endl;
			t[x][y] = 0;
			t[x - 2][y + 1] = 2;
		}
	}else if (t[x1][y1]<=0 && (x1 == x + 1 || x1 == x - 1) && (y1 == y - 2 || y1 == y + 2))
	{
		if ((y1 == y - 2 && x1 == x - 1) && t[x1][y1]<=0) {
			t[x][y] = 0;
			if (t[x1][y1] != 0) { t[x - 1][y - 2] = 0; }
			t[x - 1][y - 2] = 2;
		}
		if (y1 == y - 2 && x1 == x + 1) {
			t[x][y] = 0;
			if (t[x1][y1] != 0) { t[x + 1][y - 2] = 0; }
			t[x + 1][y - 2] = 2;
		}
		if (y1 == y + 2 && x1 == x - 1) {
			t[x][y] = 0;
			if (t[x1][y1] != 0) { t[x - 1][y + 2] = 0; }
			t[x - 1][y + 2] = 2;
		}
		if (y1 == y + 2 && x1 == x + 1) {
			t[x][y] = 0;
			if (t[x1][y1] != 0) { t[x + 1][y + 2] = 0; }
			t[x + 1][y + 2] = 2;
		}
	}
}
void king(int t[8][8],int x,int y,int x1,int y1,int tj) {
	if (t[x][y] == -6) {
		if ((t[x1][y1] == 0 || t[x1][y1] != 0)) {
			if (t[x1][y1] == 0 && x1 == x - 1 && y1 == y) {
				t[x][y] = 0;
				t[x - 1][y] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x - 1 && y1 == y) {
				t[x][y] = 0;
				t[x - 1][y] = 0;
				t[x - 1][y] = -6;
			}
			else if (t[x1][y1] == 0 && x1 == x - 1 && y1 == y + 1) {
				t[x][y] = 0;
				t[x - 1][y + 1] = -6;
			}
			else if (t[x1][y1] == 0 && x1 == x - 1 && y1 == y - 1) {
				t[x][y] = 0;
				t[x - 1][y - 1] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x - 1 && y1 == y + 1) {
				t[x][y] = 0;
				t[x - 1][y + 1] = 0;
				t[x - 1][y + 1] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x - 1 && y1 == y - 1) {
				t[x][y] = 0;
				t[x - 1][y - 1] = 0;
				t[x - 1][y - 1] = -6;
			}else if (t[x1][y1] != 0 && x1 == x && y1 == y - 1) {
				t[x][y] = 0;
				t[x][y - 1] = 0;
				t[x][y - 1] = -6;
			}else if (t[x1][y1] == 0 && x1 == x && y1 == y - 1) {
				t[x][y] = 0;
				t[x - 1][y - 1] = -6;
			}else if (t[x1][y1] != 0 && x1 == x && y1 == y + 1) {
				t[x][y] = 0;
				t[x][y + 1] = 0;
				t[x][y + 1] = -6;
			}else if (t[x1][y1] == 0 && x1 == x && y1 == y - 1) {
				t[x][y] = 0;
				t[x][y - 1] = -6;
			}	if (t[x1][y1] == 0 && x1 == x + 1 && y1 == y) {
				t[x][y] = 0;
				t[x + 1][y] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x + 1 && y1 == y) {
				t[x][y] = 0;
				t[x + 1][y] = 0;
				t[x + 1][y] = -6;
			}
			else if (t[x1][y1] == 0 && x1 == x + 1 && y1 == y + 1) {
				t[x][y] = 0;
				t[x + 1][y + 1] = -6;
			}
			else if (t[x1][y1] == 0 && x1 == x + 1 && y1 == y - 1) {
				t[x][y] = 0;
				t[x + 1][y - 1] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x + 1 && y1 == y + 1) {
				t[x][y] = 0;
				t[x + 1][y + 1] = 0;
				t[x + 1][y + 1] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x + 1 && y1 == y - 1) {
				t[x][y] = 0;
				t[x + 1][y - 1] = 0;
				t[x + 1][y - 1] = -6;
			}
		}
	}
	else if (t[x][y] == 6) {
		if ((t[x1][y1] == 0 || t[x1][y1] != 0)) {
			if (t[x1][y1] == 0 && x1 == x - 1 && y1 == y) {
				t[x][y] = 0;
				t[x - 1][y] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x - 1 && y1 == y) {
				t[x][y] = 0;
				t[x - 1][y] = 0;
				t[x - 1][y] = -6;
			}
			else if (t[x1][y1] == 0 && x1 == x - 1 && y1 == y + 1) {
				t[x][y] = 0;
				t[x - 1][y + 1] = -6;
			}
			else if (t[x1][y1] == 0 && x1 == x - 1 && y1 == y - 1) {
				t[x][y] = 0;
				t[x - 1][y - 1] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x - 1 && y1 == y + 1) {
				t[x][y] = 0;
				t[x - 1][y + 1] = 0;
				t[x - 1][y + 1] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x - 1 && y1 == y - 1) {
				t[x][y] = 0;
				t[x - 1][y - 1] = 0;
				t[x - 1][y - 1] = -6;
			}else if (t[x1][y1] != 0 && x1 == x && y1 == y - 1) {
				t[x][y] = 0;
				t[x][y - 1] = 0;
				t[x][y - 1] = -6;
			}else if (t[x1][y1] == 0 && x1 == x && y1 == y - 1) {
				t[x][y] = 0;
				t[x - 1][y - 1] = -6;
			}else if (t[x1][y1] != 0 && x1 == x && y1 == y + 1) {
				t[x][y] = 0;
				t[x][y + 1] = 0;
				t[x][y + 1] = -6;
			}else if (t[x1][y1] == 0 && x1 == x && y1 == y - 1) {
				t[x][y] = 0;
				t[x][y - 1] = -6;
			}	if (t[x1][y1] == 0 && x1 == x + 1 && y1 == y) {
				t[x][y] = 0;
				t[x + 1][y] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x + 1 && y1 == y) {
				t[x][y] = 0;
				t[x + 1][y] = 0;
				t[x + 1][y] = -6;
			}
			else if (t[x1][y1] == 0 && x1 == x + 1 && y1 == y + 1) {
				t[x][y] = 0;
				t[x + 1][y + 1] = -6;
			}
			else if (t[x1][y1] == 0 && x1 == x + 1 && y1 == y - 1) {
				t[x][y] = 0;
				t[x + 1][y - 1] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x + 1 && y1 == y + 1) {
				t[x][y] = 0;
				t[x + 1][y + 1] = 0;
				t[x + 1][y + 1] = -6;
			}
			else if (t[x1][y1] != 0 && x1 == x + 1 && y1 == y - 1) {
				t[x][y] = 0;
				t[x + 1][y - 1] = 0;
				t[x + 1][y - 1] = -6;
			}
		}
	}
}

void rookw(int t[8][8],int x,int y,int x1,int y1,int tj) {
	int cp=0;
	bool f = true;
	//this while loop to register how much the user whants to go up or down///
	cout << "is he going her" << endl;
	if (y == y1 && x1 < x && t[x1][y1]>=0) {
		cout << x1 << x << cp << endl;
		if (x1 != x - cp && y1==y) {
			while (x1 != x - cp && f==true) {
				cout << x1 << x << cp << t[x - cp][y] << endl;
				cp = cp + 1;
				if (t[x - cp][y] == 0) {
					f = true;
				}else if(x-cp == x1 && y==y1){
					f=true;
				}
				else { f = false; cp = 0; }
			}
		}
			cout << cp << endl;
			if(cp!=0){
			t[x][y] = 0;
			t[x - cp][y] = 0;
			t[x - cp][y] = -3;}
	}else if(y==y1 && x1>x && t[x1][y1] >= 0){
			while (x1 != x +cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x + cp][y] == 0) {
					f = true;
				}else if(x1==x+cp && y1==y){
					f=true;
				}
				else { f = false; cp = 0; }
			}
			cout << f << endl;
			if(cp!=0){
			t[x][y] = 0;
			t[x + cp][y] = 0;
			t[x + cp][y] = -3;}
		}
	else if (x == x1 && y1<y && t[x1][y1] >= 0) {
		//this while loop registers how much the user whants to go up or down///
		cout << f << x << cp << endl;
			while (y1 != y - cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x][y-cp] == 0) {
					f = true;
				}else if(x1==x && y1==y-cp){
					f=true;
				}
				else { f = false; cp = 0; }
			}
		if(cp!=0){
		t[x][y] = 0;
		t[x][y - cp] = 0;
		t[x][y - cp] = -3;}
	}else if(x==x1 && y1>y && t[x1][y1] >= 0){
			while (y1 != y + cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x][y+cp] == 0) {
					f = true;
				}else if(x1==x && y1==y+cp){
					f=true;
				}
				else { f = false; cp = 0; }
			}
			if(cp!=0){
				cout << cp << endl;
				t[x][y] = 0;
				t[x][y + cp] = 0;
				t[x][y + cp] = -3;
			}
	}
}
void rookb(int t[8][8], int x, int y, int x1, int y1,int tj) {
		int cp=0;
	bool f = true;
	//this while loop to register how much the user whants to go up or down///
	cout << "is he going her" << endl;
	if (y == y1 && x1 < x && t[x1][y1]<=0) {
		cout << x1 << x << cp << endl;
		if (x1 != x - cp && y1==y) {
			while (x1 != x - cp && f==true) {
				cout << x1 << x << cp << t[x - cp][y] << endl;
				cp = cp + 1;
				if (t[x - cp][y] == 0) {
					f = true;
				}else if(x-cp == x1 && y==y1){
					f=true;
				}
				else { f = false; cp = 0; }
			}
		}
			cout << cp << endl;
			if(cp!=0){
			t[x][y] = 0;
			t[x - cp][y] = 0;
			t[x - cp][y] = 3;}
	}else if(y==y1 && x1>x && t[x1][y1] <= 0){
			while (x1 != x +cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x + cp][y] == 0) {
					f = true;
				}else if(x1==x+cp && y1==y){
					f=true;
				}
				else { f = false; cp = 0; }
			}
			cout << f << endl;
			if(cp!=0){
			t[x][y] = 0;
			t[x + cp][y] = 0;
			t[x + cp][y] = 3;}
		}
	else if (x == x1 && y1<y && t[x1][y1] >= 0) {
		//this while loop registers how much the user whants to go up or down///
		cout << f << x << cp << endl;
			while (y1 != y - cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x][y-cp] == 0) {
					f = true;
				}else if(x1==x && y1==y-cp){
					f=true;
				}
				else { f = false; cp = 0; }
			}
		if(cp!=0){
		t[x][y] = 0;
		t[x][y - cp] = 0;
		t[x][y - cp] = 3;}
	}else if(x==x1 && y1>y && t[x1][y1] >= 0){
			while (y1 != y + cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x][y+cp] == 0) {
					f = true;
				}else if(x1==x && y1==y+cp){
					f=true;
				}
				else { f = false; cp = 0; }
			}
			if(cp!=0){
				cout << cp << endl;
				t[x][y] = 0;
				t[x][y + cp] = 0;
				t[x][y + cp] = 3;
			}
	}
}
void bishopw(int t[8][8], int x, int y, int x1, int y1,int tj) {
	int cp = 0, co = 0;
	bool r = true;
	cout << t[x][y] << endl;
	if (x1 != x - cp && y1 != y - cp && t[x1][y1]>=0 && x1<x && y1<y) {
		cout << "nani1" << endl;
		while (x1 != x - cp && r==true) {
			cp = cp + 1;
			while (y1 != y - co) {
				co = co + 1;
			}
			if (t[x - cp][y - cp] >= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x - cp][y - co] = 0;
		t[x - cp][y - co] = -4;
	}else if (x1 != x - cp && y1 != y + cp && t[x1][y1] >= 0 && x1<x && y1>y) {
		cout << "nani2" << endl;
		while (x1 != x - cp && r == true) {
			cp = cp + 1;
			while (y1 != y + co) {
				co = co + 1;
			}
			if (t[x - cp][y + cp] >= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x - cp][y + co] = 0;
		t[x - cp][y + co] = -4;
	}else if (x1 != x + cp && y1 != y + co && t[x1][y1] >= 0 && x1 > x && y1>y) {
		cout << "nani3" << endl;
		while (x1 != x + cp && r == true) {
			cp = cp + 1;
			while (y1 != y + co) {
				co = co + 1;
			}
			if (t[x + cp][y + cp] >= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x + cp][y + co] = 0;
		t[x + cp][y + co] = -4;
	}else if (x1 != x + cp && y1 != y - co && t[x1][y1] >= 0 && x1>x && y1 < y) {
		cout << "nani4" <<r<< endl;
		while (x1 != x + cp && r == true) {
			cp = cp + 1;
			/*while (y1 != y - cp) {
				cp = cp + 1;
			}*/
			cout << cp << cp << r << endl;
			cout << t[x + cp][y - cp] << endl;
			if (t[x + cp][y - cp] >= 0) {
				r = true;
			}
			else { r = false; cp = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x + cp][y - cp] = 0;
		t[x + cp][y - cp] = -4;
	}
}
void bishopb(int t[8][8], int x, int y, int x1, int y1,int tj) {
	int cp = 0, co = 0;
	bool r = true;
	cout << t[x][y] << endl;
	if (x1 != x - cp && y1 != y - cp && t[x1][y1] <= 0 && x1 < x && y1 < y) {
		cout << "nani1" << endl;
		while (x1 != x - cp && r == true) {
			cp = cp + 1;
			while (y1 != y - co) {
				co = co + 1;
			}
			if (t[x - cp][y - cp] <= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x - cp][y - co] = 0;
		t[x - cp][y - co] = 4;
	}
	else if (x1 != x - cp && y1 != y + cp && t[x1][y1] <= 0 && x1<x && y1>y) {
		cout << "nani2" << endl;
		while (x1 != x - cp && r == true) {
			cp = cp + 1;
			while (y1 != y + co) {
				co = co + 1;
			}
			if (t[x - cp][y + cp] <= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x - cp][y + co] = 0;
		t[x - cp][y + co] = 4;
	}
	else if (x1 != x + cp && y1 != y + co && t[x1][y1] <= 0 && x1 > x && y1 > y) {
		cout << "nani3" << endl;
		while (x1 != x + cp && r == true) {
			cp = cp + 1;
			while (y1 != y + co) {
				co = co + 1;
			}
			if (t[x + cp][y + cp] <= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x + cp][y + co] = 0;
		t[x + cp][y + co] = 4;
	}
	else if (x1 != x + cp && y1 != y - co && t[x1][y1] <= 0 && x1 > x && y1 < y) {
		cout << "nani4" << r << endl;
		while (x1 != x + cp && r == true) {
			cp = cp + 1;
			/*while (y1 != y - cp) {
				cp = cp + 1;
			}*/
			cout << cp << cp << r << endl;
			cout << t[x + cp][y - cp] << endl;
			if (t[x + cp][y - cp] <= 0) {
				r = true;
			}
			else { r = false; cp = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x + cp][y - cp] = 0;
		t[x + cp][y - cp] = 4;
	}
}
void queenw(int t[8][8], int x, int y, int x1, int y1,int tj) {
	int cp = 0, co = 0;
	bool r = true;
	cout << t[x][y] << endl;
	if (x1 != x - cp && y1 != y - cp && t[x1][y1] >= 0 && x1 < x && y1 < y) {
		cout << "nani1" << endl;
		while (x1 != x - cp && r == true) {
			cp = cp + 1;
			while (y1 != y - co) {
				co = co + 1;
			}
			if (t[x - cp][y - cp] >= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x - cp][y - co] = 0;
		t[x - cp][y - co] = -5;
	}
	else if (x1 != x - cp && y1 != y + cp && t[x1][y1] >= 0 && x1<x && y1>y) {
		cout << "nani2" << endl;
		while (x1 != x - cp && r == true) {
			cp = cp + 1;
			while (y1 != y + co) {
				co = co + 1;
			}
			if (t[x - cp][y + cp] >= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x - cp][y + co] = 0;
		t[x - cp][y + co] = -5;
	}
	else if (x1 != x + cp && y1 != y + co && t[x1][y1] >= 0 && x1 > x && y1 > y) {
		cout << "nani3" << endl;
		while (x1 != x + cp && r == true) {
			cp = cp + 1;
			while (y1 != y + co) {
				co = co + 1;
			}
			if (t[x + cp][y + cp] >= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x + cp][y + co] = 0;
		t[x + cp][y + co] = -5;
	}
	else if (x1 != x + cp && y1 != y - co && t[x1][y1] >= 0 && x1 > x && y1 < y) {
		cout << "nani4" << r << endl;
		while (x1 != x + cp && r == true) {
			cp = cp + 1;
			/*while (y1 != y - cp) {
				cp = cp + 1;
			}*/
			cout << cp << cp << r << endl;
			cout << t[x + cp][y - cp] << endl;
			if (t[x + cp][y - cp] >= 0) {
				r = true;
			}
			else { r = false; cp = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x + cp][y - cp] = 0;
		t[x + cp][y - cp] = -5;
	}
//	int cp=0;
	bool f = true;
	//this while loop to register how much the user whants to go up or down///
	cout << "is he going her" << endl;
	if (y == y1 && x1 < x && t[x1][y1]<=0) {
		cout << x1 << x << cp << endl;
		if (x1 != x - cp && y1==y) {
			while (x1 != x - cp && f==true) {
				cout << x1 << x << cp << t[x - cp][y] << endl;
				cp = cp + 1;
				if (t[x - cp][y] == 0) {
					f = true;
				}else if(x-cp == x1 && y==y1){
					f=true;
				}
				else { f = false; cp = 0; }
			}
		}
			cout << cp << endl;
			if(cp!=0){
			t[x][y] = 0;
			t[x - cp][y] = 0;
			t[x - cp][y] = -5;}
	}else if(y==y1 && x1>x && t[x1][y1] <= 0){
			while (x1 != x +cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x + cp][y] == 0) {
					f = true;
				}else if(x1==x+cp && y1==y){
					f=true;
				}
				else { f = false; cp = 0; }
			}
			cout << f << endl;
			if(cp!=0){
			t[x][y] = 0;
			t[x + cp][y] = 0;
			t[x + cp][y] = -5;}
		}
	else if (x == x1 && y1<y && t[x1][y1] >= 0) {
		//this while loop registers how much the user whants to go up or down///
		cout << f << x << cp << endl;
			while (y1 != y - cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x][y-cp] == 0) {
					f = true;
				}else if(x1==x && y1==y-cp){
					f=true;
				}
				else { f = false; cp = 0; }
			}
		if(cp!=0){
		t[x][y] = 0;
		t[x][y - cp] = 0;
		t[x][y - cp] = -5;}
	}else if(x==x1 && y1>y && t[x1][y1] >= 0){
			while (y1 != y + cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x][y+cp] == 0) {
					f = true;
				}else if(x1==x && y1==y+cp){
					f=true;
				}
				else { f = false; cp = 0; }
			}
			if(cp!=0){
				cout << cp << endl;
				t[x][y] = 0;
				t[x][y + cp] = 0;
				t[x][y + cp] = -5;
			}
	}
}
void queenb(int t[8][8], int x, int y, int x1, int y1,int tj) {
	int cp = 0, co = 0;
	bool r = true;
	cout << t[x][y] << endl;
	if (x1 != x - cp && y1 != y - cp && t[x1][y1] <= 0 && x1 < x && y1 < y) {
		cout << "nani1" << endl;
		while (x1 != x - cp && r == true) {
			cp = cp + 1;
			while (y1 != y - co) {
				co = co + 1;
			}
			if (t[x - cp][y - cp] <= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x - cp][y - co] = 0;
		t[x - cp][y - co] = 5;
	}
	else if (x1 != x - cp && y1 != y + cp && t[x1][y1] <= 0 && x1<x && y1>y) {
		cout << "nani2" << endl;
		while (x1 != x - cp && r == true) {
			cp = cp + 1;
			while (y1 != y + co) {
				co = co + 1;
			}
			if (t[x - cp][y + cp] <= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x - cp][y + co] = 0;
		t[x - cp][y + co] = 5;
	}
	else if (x1 != x + cp && y1 != y + co && t[x1][y1] <= 0 && x1 > x && y1 > y) {
		cout << "nani3" << endl;
		while (x1 != x + cp && r == true) {
			cp = cp + 1;
			while (y1 != y + co) {
				co = co + 1;
			}
			if (t[x + cp][y + cp] <= 0) {
				r = true;
			}
			else { r = false; cp = 0; co = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x + cp][y + co] = 0;
		t[x + cp][y + co] = 5;
	}
	else if (x1 != x + cp && y1 != y - co && t[x1][y1] <= 0 && x1 > x && y1 < y) {
		cout << "nani4" << r << endl;
		while (x1 != x + cp && r == true) {
			cp = cp + 1;
			/*while (y1 != y - cp) {
				cp = cp + 1;
			}*/
			cout << cp << cp << r << endl;
			cout << t[x + cp][y - cp] << endl;
			if (t[x + cp][y - cp] <= 0) {
				r = true;
			}
			else { r = false; cp = 0; }
		}
		cout << r << co << cp << endl;
		t[x][y] = 0;
		t[x + cp][y - cp] = 0;
		t[x + cp][y - cp] = 5;
	}
//	int cp=0;
	bool f = true;
	//this while loop to register how much the user whants to go up or down///
	cout << "is he going her" << endl;
	if (y == y1 && x1 < x && t[x1][y1]<=0) {
		cout << x1 << x << cp << endl;
		if (x1 != x - cp && y1==y) {
			while (x1 != x - cp && f==true) {
				cout << x1 << x << cp << t[x - cp][y] << endl;
				cp = cp + 1;
				if (t[x - cp][y] == 0) {
					f = true;
				}else if(x-cp == x1 && y==y1){
					f=true;
				}
				else { f = false; cp = 0; }
			}
		}
			cout << cp << endl;
			if(cp!=0){
			t[x][y] = 0;
			t[x - cp][y] = 0;
			t[x - cp][y] = 5;}
	}else if(y==y1 && x1>x && t[x1][y1] <= 0){
			while (x1 != x +cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x + cp][y] == 0) {
					f = true;
				}else if(x1==x+cp && y1==y){
					f=true;
				}
				else { f = false; cp = 0; }
			}
			cout << f << endl;
			if(cp!=0){
			t[x][y] = 0;
			t[x + cp][y] = 0;
			t[x + cp][y] = 5;}
		}
	else if (x == x1 && y1<y && t[x1][y1] >= 0) {
		//this while loop registers how much the user whants to go up or down///
		cout << f << x << cp << endl;
			while (y1 != y - cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x][y-cp] == 0) {
					f = true;
				}else if(x1==x && y1==y-cp){
					f=true;
				}
				else { f = false; cp = 0; }
			}
		if(cp!=0){
		t[x][y] = 0;
		t[x][y - cp] = 0;
		t[x][y - cp] = 5;}
	}else if(x==x1 && y1>y && t[x1][y1] >= 0){
			while (y1 != y + cp && f == true) {
				cout << x1 << x << cp << endl;
				cp = cp + 1;
				if (t[x][y+cp] == 0) {
					f = true;
				}else if(x1==x && y1==y+cp){
					f=true;
				}
				else { f = false; cp = 0; }
			}
			if(cp!=0){
				cout << cp << endl;
				t[x][y] = 0;
				t[x][y + cp] = 0;
				t[x][y + cp] = 5;
			}
	}
}

void move(int t[8][8], int x, int y, int x1, int y1, int tj)
{
	if (t[x][y] == -1)
	{
	cout<<"lol1"<<endl;
		pawn_white(t, x, y, x1, y1, tj);
	}
	if (t[x][y] == 1)
	{
		pawn_black(t, x, y, x1, y1, tj);
	}
	if (t[x][y] == -2)
	{
		rider_white(t, x, y, x1, y1,tj);
	}
	if (t[x][y] == 2) {
		rider_black(t, x, y, x1, y1,tj);
	}
	if (t[x][y] == -4) {
		bishopw(t, x, y, x1, y1,tj);
	}
	if (t[x][y] == 4) {
		bishopb(t, x, y, x1, y1,tj);
	}
	if (t[x][y] == -3) {
		rookw(t, x, y, x1, y1,tj);
	}
	if (t[x][y] == 3) {
		rookb(t, x, y, x1, y1,tj);
	}
	if (t[x][y] == -5) {
		queenw(t, x, y, x1, y1,tj);
	}
	if (t[x][y] == 5) {
		queenb(t, x, y, x1, y1,tj);
	}
	if (t[x][y] == 6 || t[x][y] == -6) {
		king(t, x, y, x1, y1,tj);
	}
}
void init(int t[8][8], int& tj) {

	for (int i = 0; i < 8; i++) {
		t[1][i] = 1;
		t[6][i] = -1;//pawn
	}
	t[0][0] = 3;//rook
	t[0][1] = 2;//rider
	t[0][2] = 4;//bishop
	t[0][3] = 5;//queen
	t[0][4] = 6;//king
	t[0][5] = 4;//bishop
	t[0][6] = 2;//rider
	t[0][7] = 3;//rook
	t[7][0] = -3;//rook
	t[7][1] = -2;//rider
	t[7][2] = -4;//bishop
	t[7][3] = -5;//queen
	t[7][4] = -6;//king
	t[7][5] = -4;//bishop
	t[7][6] = -2;//rider
	t[7][7] = -3;//rook
	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			t[i][j] = 0;
		}
	}
	tj = 2;
}




int game(int t[8][8], int tj,bool h,int check) {
	int x, y, x1, y1;
	if(tj == 1){
		do{
		cout << "player 1";
		depart(t, tj, x, y);
		ariver(t,x1,y1,tj);
		move(t, x, y, x1, y1, tj);
		}while(t[x][y]!=0);
	}else{
		do{
		cout << "player 2";
		depart(t, tj, x, y);
		ariver(t,x1, y1,tj);
		move(t, x, y, x1, y1,tj);
		}while(t[x][y]!=0);
	}
	return check;
}

void afficher(int t[8][8],int &check) {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (t[i][j] == 1)
			{
				cout << " |  pb ";
			}
			else if (t[i][j] == -1)
			{
				cout << " |  pw ";
			}
			else if (t[i][j] == 3)
			{
				cout << " |  rb ";
			}
			else if (t[i][j] == -3)
			{
				cout << " |  rw ";
			}
			else if (t[i][j] == 2)
			{
				cout << " |  hb ";
			}
			else if (t[i][j] == -2)
			{
				cout << " |  hw ";
			}
			else if (t[i][j] == 4)
			{
				cout << " |  bb ";
			}
			else if (t[i][j] == -4)
			{
				cout << " |  bw ";
			}
			else if (t[i][j] == 5)
			{
				cout << " |  qb ";
			}
			else if (t[i][j] == -5)
			{
				cout << " |  qw ";
			}
			else if (t[i][j] == 6)
			{
				cout << " |  kb ";
			}
			else if (t[i][j] == -6)
			{
				cout << " |  kw ";
			}
			if (t[i][j] == 0)
			{
				cout << " |     ";
			}
		}
		cout << " |" << i << endl;
	}
	cout << "" << endl;
	cout << " |  0   |  1   |  2   |  3   |  4   |  5   |  6   |  7   |" << endl;

}

int main() {
		int tj = 0;
		int check = 1;//fach ykhser chi wahed echeck ayweli = 0 mazal matsewbat
		int t[8][8];
		bool h = true;
		init(t, tj);
		
		do {
			system("clear");
			afficher(t,check);
			game(t, tj,h,check);
			test(t, check);
			if (tj == 1)
			{
				tj = 2;
			}
			else tj = 1;

		} while (check > 0);
	
}
