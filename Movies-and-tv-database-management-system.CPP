#include<fstream.h>
#include<ctype.h>
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<iomanip.h>
class SHOWS
{
	char actor_m[50];          //movie actor
	char actress_m[50];       //movie actress
	char actor_tv[50];           //tv actor
	char actress_tv[50];       //tv actress
	char genre_m[10];        //movie genre
	char genre_tv[10];        //tv genre
	float rating_tv;             //tv rating
	float rating_m;              //movie rating
	int year_m;               //year of release movie
	int year_tv;               //year of release tv show
	char title_m [50];      //title of movie
	char title_tv [50];        //title of tv show

	public:
		    void getdata_tv();
		    void getdata_m();
		    void putdata_tv();
		    void putdata_m();

			   SHOWS()
		    {
			rating_m=0;
			rating_tv=0;
		    }
		    char * gettitle_m()  //to return title of movie			
		    {
			return title_m;
		    }
		    char * gettitle_tv()  //to return title of tv show
		    {
			return title_tv;
		    }
		    int getyear_m()  //to return year of movie
		    {
			return year_m;
		    }
		    char * getactor_m() //to return actor of movie
		    {
			return actor_m;
		    }
		    char * getactress_m()  //to return actress of movie
		    {
			return actress_m;
		    }
		    char * getactor_tv()  //to return actor of tv show
		    {
			return actor_tv;
		    }
		    char * getactress_tv()  //to return actress of tv show
		    {
			return actress_tv;
		    }
		    int getyear_tv()  //to return year of tv show
		    {
			return year_tv;
		    }
};
void line()  //to create line with dash symbol
{
 	 for(int i=1;i<41;i++)
 	cout<<"--";
 	cout<<"\n";
}
 void star() //to create line with star symbol
{
            for(int i=1;i<41;i++)
            cout<<"**";
            cout<<"\n";
}
void border()
{
	char x =21;

	for(int i=2;i<=78;i++)
	{
		gotoxy(i,2);cout<<x;
		gotoxy(i,23);cout<<x;
	}
	for(i=2;i<23;i++)
	{
		gotoxy(2,i);cout<<x;
		gotoxy(78,i);cout<<x;
	}
}
void SHOWS::getdata_tv()
{
		cout<<"ENTER TILTLE:"; gets(title_tv);
		cout<<"ENTER NAME OF ACTOR:"; gets(actor_tv);
		cout<<"ENTER NAME OF ACTRESS:"; gets(actress_tv);
		cout<<"ENTER GENRE:"; gets(genre_tv);
		cout<<"ENTER RATINGS(1/10):"; cin>>rating_tv;
		cout<<"ENTER YEAR OF RELEASE:"; cin>>year_tv;
}
void SHOWS::getdata_m()
{
		cout<<"ENTER TILTLE:"; gets(title_m);
		cout<<"ENTER NAME OF ACTOR:"; gets(actor_m);
		cout<<"ENTER NAME OF ACTRESS:"; gets(actress_m);
		cout<<"ENTER RATINGS(1/10):"; cin>>rating_m;
		cout<<"ENTER GENRE:"; gets(genre_m);
		cout<<"ENTER YEAR OF RELEASE:"; cin>>year_m;
}
void SHOWS::putdata_tv()
{
      cout<<setw(15)<<strupr(title_tv)<<setw(15)<<strupr(actor_tv)<<setw(15)<<strupr(actress_tv)
      <<setw(11)<<strupr(genre_tv)<<setw(7)<<year_tv<<setw(7)<<rating_tv<<endl;
}
void SHOWS::putdata_m()
{
      cout<<setw(15)<<strupr(title_m)<<setw(15)<<strupr(actor_m)<<setw(15)<<strupr(actress_m)
      <<setw(11)<<strupr(genre_m)<<setw(7)<<year_m<<setw(7)<<rating_m<<endl;
}
/* ***********************************/
void display_m()  //display movie
{
	clrscr();

	fstream f("movies.dat",ios::binary|ios::in);
	SHOWS s;

	gotoxy(35,1);cout<<"MOVIES";
	cout<<endl;

	star();
	cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)<<"ACTRESS"
	<<setw(11)<<"GENRE"<<setw(7)<<"YEAR"<<setw(7)<<"RATING"<<endl;
	star();

	while(f.read((char*)&s,sizeof(s)))
		s.putdata_m();
	f.close();
	getch();
}
void display_tv()  //display tv show
{
	clrscr();

	fstream f("tvshows.dat",ios::binary|ios::in);
	SHOWS s;

	gotoxy(35,1);cout<<"TV SHOWS";
	cout<<endl;
	star();
	cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)<<"ACTRESS"
	<<setw(11)<<"GENRE"<<setw(7)<<"YEAR"<<setw(7)<<"RATING"<<endl;
	cout<<endl;
	star();

	while(f.read((char*)&s,sizeof(s)))
		s.putdata_tv();
	f.close();
	getch();
}
void new_movie()  //enter new movie
{
	clrscr();

	char ch;
	SHOWS s;
	s.getdata_m();
	fstream f1("movies.dat",ios::app|ios::binary);
	cout<<"\n\nDO YOU WANT TO SAVE THE RECORD(Y/N):\t";
	cin>>ch;
	toupper(ch);
	if(ch=='Y')
		f1.write((char*)&s,sizeof(s));
	f1.close();
}
void new_tv()  //enter new tv show
{
	clrscr();

	char ch;
	SHOWS s;
	s.getdata_tv();
	fstream f1("tvshows.dat",ios::app|ios::binary);
	cout<<"\n\nDO YOU WANT TO SAVE THE RECORD(Y/N):\t";
	cin>>ch;
	toupper(ch);
	if(ch=='Y')
		f1.write((char*)&s,sizeof(s));

	f1.close();
}

void modify_m()  //modify movie
{
	clrscr();
	fstream f1("movies.dat",ios::in | ios::out | ios::binary);
	SHOWS s;
	char  mody[50];
	long pos;
	char found='f';

	cout<<" ENTER THE MOVIE  YOU WANT TO MODIFY:";
	gets(mody);
	strupr(mody);
	cout<<endl<<endl;
	while(!f1.eof())
	{
		pos=f1.tellg();
		f1.read((char*)&s,sizeof(s));
	
		if(strcmp(mody,s.gettitle_m())==0)
		{
			s.getdata_m();
			f1.seekg(pos);
			f1.write((char*)&s,sizeof(s));
			found='t';
			break;
		}
	}
	if(found=='f')
		cout<<"\n\nRECORD NOT FOUND\n";
	f1.close();

	getch();
}
void modify_tv()  //modify tv show
{
	clrscr();

	fstream f1("tvshows.dat",ios::in | ios::out | ios::binary);

	SHOWS s;
	char  mody[50];
	long pos;
	char found='f';

	cout<<"ENTER THE TV SHOW  YOU WANT TO MODIFY:\t";
	gets(mody);
	strupr(mody);

	while(!f1.eof())
	{
		pos=f1.tellg();
		f1.read((char*)&s,sizeof(s));

		if(strcmp(mody,s.gettitle_tv())==0)
		{
			s.getdata_tv();
			f1.seekg(pos);
			f1.write((char*)&s,sizeof(s));
			found='t';
			break;
		}
	}
	if(found=='f')
		cout<<"\n\nRECORD NOT FOUND\n";

	f1.close();
	getch();
}
void delete_m()  //delete movie
{
	clrscr();

	fstream f1("movies.dat",ios::in|ios::binary);
	fstream f2("temp.dat",ios::out|ios::binary);
	SHOWS s;
	char del[50];
	int found=0;
	char confirm='N';
	cout<<"ENTER THE MOVIE YOU WANT TO DELETE:\t"; gets(del);
	strupr(del);

	while(f1.read((char*)&s,sizeof(s)))
	{
		if(strcmp(del,s.gettitle_m())==0)
		{
		            cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<
                                    setw(15)<<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7)
                                    <<"YEAR"<<setw(7)<<"RATING"<<endl;
			cout<<endl; star();

			s.putdata_m();
			found=1;
			cout<<"ARE YOU SURE WANT TO  DELETE THIS RECORD ?(Y/N):\t";
			cin>>confirm;
			toupper(confirm);
			getch();

			if(confirm=='N')
				f2.write((char*)&s,sizeof(s));
			else
				cout<<"RECORD DELETED";
		}
		else
			f2.write((char*)&s,sizeof(s));
	  }
	  if(found==0)
		 cout<<"\nRECORD NOT FOUND\n";

	  f1.close();
	  f2.close();

	  remove("movies.dat");
	  rename("temp.dat","movies.dat");
}
void delete_tv()  //delete tv show
{
	clrscr();
	fstream f1("tvshows.dat",ios::in|ios::binary);
	fstream f2("temp.dat",ios::out|ios::binary);

	SHOWS s;
	char del[50];
	int found=0;
	char confirm='n';

	cout<<"ENTER THE TV SHOW YOU WANT TO DELETE:\t";
	gets(del);
	strupr(del);
	while(f1.read((char*)&s,sizeof(s)))
	{
		if(strcmp(del,s.gettitle_tv())==0)
		{
                     		cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)
                                    <<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7)<<"YEAR"
                                    <<setw(7)<<"RATING"<<endl;
			cout<<endl; star();
			s.putdata_tv();
			found=1;

			cout<<" ARE YOU SURE WANT TO  DELETE THIS RECORD ?(Y/N):\t";
			cin>>confirm;
			toupper(confirm);
			getch();
			if(confirm=='N')
				f2.write((char*)&s,sizeof(s));
			else
				cout<<"RECORD DELETED";
		}
		else
			f2.write((char*)&s,sizeof(s));
	  }
	  if(found==0)
		 cout<<"\nRECORD NOT FOUND\n";

	  f1.close();
	  f2.close();
	  remove("tvshows.dat");
	  rename("temp.dat","tvshows.dat");
}
void s_name_m()  //search movie name
{
	clrscr();

	fstream f("movies.dat",ios::binary|ios::in);
	SHOWS s;
	char name[40];
	cout<<"ENTER MOVIE NAME TO BE SEARCHED:";
	gets(name);
	strupr(name);
	int found=0;
	while(f.read((char*)&s,sizeof(s)))
	{
		if(strcmp(name,s.gettitle_m())==0)
		{   
                                         cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)
                                         <<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7)
                                         <<"YEAR"<<setw(7)<<"RATING"<<endl;
                    		     cout<<endl; star();
                    
           			      s.putdata_m();
                   		      
                                          getch();
       			      found=1;
			       break;
		}
	}
	f.close();

	if(found==0)
		cout<<"SEARCH VALUE DOESN'T EXISTS";
}


void s_actor_m()  //search actor name of movie
{
	clrscr();
	fstream f("movies.dat",ios::binary|ios::in);
	SHOWS s;
	char name[40];

	cout<<"ENTER ACTOR WHOSE MOVIE IS TO BE SEARCHED:";
	gets(name);
	strupr(name);
	cout<<endl<<endl;
	int found=0;
	while(f.read((char*)&s,sizeof(s)))
	{
		if(strcmp(name,s.getactor_m())==0)
		{  
                                    cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)    
                                    <<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7) <<"YEAR"
                                    <<setw(7) <<"RATING"<<endl;
                                    cout<<endl; star();                                                                                                                                                                                                            
			s.putdata_m();
			getch();
			found=1;
			break;
		}
	}
	f.close();
	if(found==0)
		cout<<"SEARCH VALUE DOESN'T EXISTS";
}
void s_actress_m()  //search actress of movie
{
	clrscr();

	fstream f("movies.dat",ios::binary|ios::in);

	SHOWS s;
	char name[40];
	
            cout<<"ENTER ACTRESS WHOSE MOVIE IS TO BE SEARCHED:";
	gets(name);
	strupr(name);
	cout<<endl<<endl;
	int found=0;
	while(f.read((char*)&s,sizeof(s)))
	{
		if(strcmp(name,s.getactress_m())==0)
		{
		              cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)                                  
                                      <<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7)<<"YEAR"<<
                                      setw(7)<<"RATING"<<endl;
			  cout<<endl;star();
			   s.putdata_m();
			   getch();
           			   found=1;
              		   break;
		}
	}
	f.close();

	if(found==0)
		cout<<"SEARCH VALUE DOESN'T EXISTS";
}
void s_year_m()  //search year of movie
{
	clrscr();

	fstream f("movies.dat",ios::binary|ios::in);

	SHOWS s;
	int y;
	cout<<"ENTER YEAR:";
	cin>>y;
	cout<<endl<<endl;
	int found=0;
	while(f.read((char*)&s,sizeof(s)))
	{
		if(y==s.getyear_m())
		{
                                                   cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)
                                                   <<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7)<<"YEAR"
                                                   <<setw(7)<<"RATING"<<endl;
			               cout<<endl;star();
			               s.putdata_m();
			               getch();
			               found=1;
			               break;
		}
	}
	f.close();

	if(found==0)
	              cout<<"SEARCH VALUE DOESN'T EXISTS";
}
void searchmenu_m()  //search menu for movies
{
	int choice=0;

	while(choice!=3)
	{
		clrscr();

		cout<<"--SEARCH MENU--"<<endl;
		cout<<"1.SEARCH BY MOVIE NAME"<<endl;
		cout<<"2.SEARCH BY YEAR OF RELEASE"<<endl;
		cout<<"3.SEARCH BY ACTOR'S NAME"<<endl;
		cout<<"4.SEARCH BY ACTRESS'S NAME"<<endl;
		cout<<"5.EXIT"<<endl;
		cout<<"ENTER YOUR CHOICE:";
		cin>>choice;

		switch(choice)
		{
			case 1: s_name_m();
				getch();
				break;
			case 2: s_year_m();
				getch();
				break;
			case 3: s_actor_m();
				getch();
				break;
			case 4: s_actress_m();
				getch();
				break;
			case 5: cout<<endl<<endl;
                                                cout<<"EXITING";
				getch();
				exit(0);
				break;
			default:cout<<endl<<endl;
                                                 cout<<"INVALID CHOICE";
				getch();
				break;
		}
	}
}


void s_name_tv()  //search name of tv show
{
	clrscr();

	fstream f("tvshows.dat",ios::binary|ios::in);
	SHOWS s;
	char name[40];

	cout<<"ENTER TV SHOW NAME TO BE SEARCHED:";
	gets(name);
	strupr(name);
	cout<<endl<<endl;
	int found=0;

	while(f.read((char*)&s,sizeof(s)))
	{
		if(strcmp(name,s.gettitle_tv())==0)
		{
			cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)
                                    <<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7)<<"YEAR"
                                    <<setw(7)<<"RATING"<<endl;
                      		 
                                    cout<<endl;star();
  			
                                    s.putdata_tv();
			getch();
			found=1;
			 break;
		}
	}
	f.close();
	if(found==0)
		cout<<"SEARCH VALUE DOESN'T EXISTS";
}
void s_actor_tv()  //search actor of tv show
{
	clrscr();

	fstream f("tvshows.dat",ios::binary|ios::in);

	SHOWS s;
	char name[40];

	cout<<"ENTER ACTOR WHOSE TV SHOW IS TO BE SEARCHED:";
	gets(name);
	strupr(name);
	cout<<endl<<endl;
	int found=0;

	while(f.read((char*)&s,sizeof(s)))
	{
		if(strcmp(name,s.getactor_tv())==0)
		{
 		             cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)
                                     <<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7)<<"YEAR"
                                     <<setw(7)<<"RATING"<<endl;
                     		 cout<<endl; star();
 
			  s.putdata_tv();
 			  getch();
	 	              found=1;
			  break;
		}
	}
	f.close();

	if(found==0)
		cout<<"SEARCH VALUE DOESN'T EXISTS";
}
void s_actress_tv()  //search actress of tv show
{
	clrscr();

	fstream f("tvshows.dat",ios::binary|ios::in);
	SHOWS s;
	char name[40];

	cout<<"ENTER ACTRESS WHOSE TV SHOW IS TO BE SEARCHED:";
	gets(name);
	strupr(name);
	cout<<endl<<endl;
	int found=0;

	while(f.read((char*)&s,sizeof(s)))
	{
		if(strcmp(name,s.getactress_tv())==0)
		{
		                  cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)
                                          <<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7)
                                          <<"YEAR"<<setw(7) <<"RATING"<<endl;
                   	                  cout<<endl;star();
           			      
                                          s.putdata_tv();
			      getch();
			found=1;
			break;
		}
	}
	f.close();

	if(found==0)
		cout<<"SEARCH VALUE DOESN'T EXISTS";
}
void s_year_tv()  //search year of tv show
{
	clrscr();
	fstream f("tvshows.dat",ios::binary|ios::in);
	SHOWS s;
	int y;
	cout<<"ENTER YEAR:";
	cin>>y;
	cout<<endl<<endl;
	int found=0;
	while(f.read((char*)&s,sizeof(s)))
	{
		if(y==s.getyear_tv())
		{     
                                   cout<<setw(15)<<"TITLE"<<setw(15)<<"ACTOR"<<setw(15)
                                   <<"ACTRESS"<<setw(11)<<"GENRE"<<setw(7)<<"YEAR"<<
                                   setw(7)<<"RATING"<<endl;
		           cout<<endl;star();
		            s.putdata_tv();
			getch();
                 		found=1;
			break;
		}
	}
	f.close();

	if(found==0)
		cout<<"SEARCH VALUE DOESN'T EXISTS";
}
void searchmenu_tv()  //search menu for tv show
{
	int choice=0;
	while(choice!=3)
	{
		clrscr();

		cout<<"--SEARCH MENU--"<<endl;
		cout<<"1.SEARCH BY TV SHOW NAME"<<endl;
		cout<<"2.SEARCH BY YEAR OF RELEASE"<<endl;
		cout<<"3.SEARCH BY ACTOR'S NAME"<<endl;
		cout<<"4.SEARCH BY ACTRESS'S NAME"<<endl;
		cout<<"5.EXIT"<<endl;
		cout<<"ENTER YOUR CHOICE:";
		cin>>choice;

		switch(choice)
		{
			case 1: s_name_tv();
				getch();
				break;
			case 2: s_year_tv();
				getch();
				break;
			case 3: s_actor_tv();
				getch();
				break;
			case 4: s_actress_tv();
				getch();
				break;
			case 5: cout<<endl<<endl;
				cout<<"EXITING";
				getch();
				exit(0);
				break;
			default:cout<<endl<<endl;cout<<"INVALID CHOICE";
				getch();
				break;
		}
	}
}

void main()
{
	clrscr();

	char chh[7];
	int m=2;
	int n=0;
	char pass[7]="cs12b";

	while(n<=3)
	{
		cout<<"ENTER: ";

		for(int i=0;i<5;i++)
		{
			chh[i]=getch();
			cout<<"*";
		}
		cout<<endl;
			getch();
		if(strcmp(chh,pass)==0)
		{
			cout<<"\nWELCOME";
			getch();
			int ch=0;
		    while(ch!=3)
		    {
				clrscr();

				border();
				gotoxy(9,5);cout<<"**ENTERTAINMENT MENU**"<<endl;
				gotoxy(9,6);cout<<"1.TV SHOWS"<<endl;
				gotoxy(9,7);cout<<"2.MOVIES"<<endl;
				gotoxy(9,8);cout<<"3.EXIT"<<endl;
				gotoxy(9,9);cout<<"Enter your choice(1-3):"; cin>>ch;
				cout<<endl<<endl;

			if(ch==1)
			{
					clrscr();
					int ch1=0;
				while(ch1!=6)
				{
					clrscr();

					border();
					gotoxy(9,5);cout<<"**TV SHOWS MENU**"<<endl;
					gotoxy(9,6);cout<<"1.ENTER NEW TV SHOW DETAIL"<<endl;
					gotoxy(9,7);cout<<"2.DISPLAY ALL RECORDS"<<endl;
					gotoxy(9,8);cout<<"3.SEARCH YOUR FAVORITE TV SHOWS "<<endl;
					gotoxy(9,9);cout<<"4.DELETE A RECORD"<<endl;
					gotoxy(9,10);cout<<"5.MODIFY"<<endl;
					gotoxy(9,11);cout<<"6.EXIT"<<endl;
					gotoxy(9,12);cout<<"ENTER CHOICE(1-6):";
					cin>>ch1;

					switch(ch1)
					{

						case 1: clrscr();
							new_tv();
							getch();
							break;
						case 2: clrscr();
							display_tv();
							getch();
							break;
						case 3: clrscr();
							searchmenu_tv();
							getch();
							break;
						case 4: clrscr();
							delete_tv();
							getch();
							break;
						case 5: clrscr();
							modify_tv();
							getch();
							break;
						case 6: clrscr();
							cout<<"EXITING PROGRAM....";
							getch();
							exit(0);
						default:clrscr();
							cout<<"INVALID CHOICE";
					}
			}
		}
		else if(ch==2)
		{
			int ch2=0;

			while(ch2!=6)
			{
				clrscr();

				border();
				gotoxy(9,5); cout<<"EXPERIENCE THE THEATRE LIKE EFFECT"<<endl;
				gotoxy(9,6); cout<<"A |_1_| |_2_| |_3_| |_4_| |_5_|"<<endl;
				gotoxy(9,7); cout<<"B |_1_| |_2_| |_3_| |_4_| |_5_|"<<endl;
				gotoxy(9,8); cout<<"C |_1_| |_2_| |_3_| |_4_| |_5_|"<<endl;

				cout<<endl<<endl;

				gotoxy(9,9);cout<<"**MOVIES DATABASE MENU**"<<endl;
				gotoxy(9,10);cout<<"1.ENTER NEW MOVIE DETAIL"<<endl;
				gotoxy(9,11);cout<<"2.DISPLAY ALL RECORDS"<<endl;
				gotoxy(9,12);cout<<"3.SEARCH YOUR FAVORITE MOVIES"<<endl;
				gotoxy(9,13);cout<<"4.DELETE A RECORD"<<endl;
				gotoxy(9,14);cout<<"5.MODIFY"<<endl;
				gotoxy(9,15);cout<<"6.EXIT"<<endl;
				gotoxy(9,16);cout<<"ENTER CHOICE(1-6):"; cin>>ch2;

				switch(ch2)
				{
					case 1: clrscr();
						new_movie();
						getch();
						break;
					case 2: clrscr();
						display_m();
						getch();
						break;
					case 3: clrscr();
						searchmenu_m();											getch();
						break;
					case 4: clrscr();
						delete_m();
						getch();
						break;
					case 5: clrscr();
						modify_m();
						getch();
						break;
					case 6: clrscr();
						cout<<"EXITING PROGRAM....";
						getch();
						exit(0);
						break;
					default: cout<<"INVALID CHOICE";
				}
			}
		}
		if(ch==3)
		{
			clrscr();
			cout<<"EXITING PROGRAM...."; getch();
		}
	}
		break;
		}
		else
		{
			n++;

			if(n==3)
				exit(0);


			cout<<"\nINCORRECT PASSWORD\n";
			cout<<"Number of chances left: "<<m--;

			cout<<endl;
		}
	}
	getch();
}

