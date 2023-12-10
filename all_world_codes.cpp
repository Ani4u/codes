






































































































































































































############ DDA Line ##############
#include <graphics.h>
#include <iostream>
#include <math.h>
#include <dos.h>
using namespace std;
int main( )
{
float x,y,x1,y1,x2,y2,dx,dy,step;
int i,gd=DETECT,gm;
int color;
 
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 
cout<<"Enter the value of x1 and y1 : ";
cin>>x1>>y1;
cout<<"Enter the value of x2 and y2: ";
cin>>x2>>y2;
 
dx=abs(x2-x1);
dy=abs(y2-y1);
 
if(dx>=dy)
step=dx;
else
step=dy;
 
dx=dx/step;
dy=dy/step;
 
x=x1;
y=y1;
 
i=1;
while(i<=step)
{
putpixel(x,y,color);
x=x+dx;
y=y+dy;
i=i+1;
delay(1000);
}

closegraph();
return 0;
}


################## DDA CIRCLE ###################
#include<graphics.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    float x1,y1,x2,y2,x,y,k;
    int gd,gm,i,val,r;
    cout<<"Enter radius of a circle";
    cin>>r;
    initgraph(&gd,&gm,NULL);
    x1=r*cos(0);
    y1=r*sin(0);
    x=x1;
    y=y1;
    i=0;
    do
    {
        val=pow(2,i);
        i++;
    }while (val<r);
      k=1/pow(2,i-1);
    do
    {
        x2=x1+y1*k;
        y2=y1-k*x2;
        putpixel(200+x2,200+y2,15);
        x1=x2;
        y1=y2;    
    }while ((y1-y)<k||(x-x1)>k);  
    delay(9000);
    return 0;
    }

##################### MIDPOINT #########################

#include<graphics.h>
#include<iostream>
#include<cmath> 
using namespace std; 
int main() 
{ 
    float d; 
    int x,y,r,x1,y1,gd=0,gm; 
    cout<<"Enter the x1 coordinate "; 
    cin>>x1; 
    cout<<"Enter the y1 coordinate "; 
    cin>>y1; 
    cout<<"Enter the radius of circle "; 
    cin>>r; 
    initgraph(&gd,&gm,NULL); 
    x=0; 
    y=r; 
    d=1.25-r; 
    do 
    { 
        putpixel(y1+x,x1+y,15); 
        putpixel(x1+y,y1+x,RED); 
        putpixel(x1+y,y1-x,GREEN); 
        putpixel(y1+x,x1-y,YELLOW); 
        putpixel(y1-x,x1-y,15); 
        putpixel(x1-y,y1-x,RED); 
        putpixel(x1-y,y1+x,GREEN); 
        putpixel(y1-x,x1+y,YELLOW); 
        if(d<=0) 
        { 
            x++; 
            y=y; 
            d=d+2*x+1; 
        } 
        else 
        { 
            x++; 
            y=y-1; 
            d=d+2*(x-y)+1; 
        } 
    }while(x<y); 
    delay(7000); 
    return 0; 
}

################### BRESENHAM LINE ####################

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include<dos.h>
void bsline(int x,int y,int x2,int y2)
{
	int dx,dy,p;
	dx=x2-x;
	dy=y2-y;
	p = 2 * (dy) - (dx);
	while(x <= x2)
	{
		if(p < 0)
		{
			x=x+1;
			y=y;
			p = p + 2 * (dy);
		}
		else
		{
			x=x+1;
			y=y+1;
			p = p + 2 * (dy - dx);
		}
		putpixel(x,y,RED);
		delay(10);
	}
}
void main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"C:\\Tc\\BGI");
	int x1,x2,y1,y2;
	cout<<"Enter the x1,y1,x2,y2 values : ";
	cin>>x1>>y1>>x2>>y2;
	bsline(x1,y1,x2,y2);
	getch();
	closegraph();
}


##################### TRANSLATION ####################

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
void main()
{
	int gd=DETECT,gm,x1,x2,y1,y2,tx,ty;
	initgraph(&gd,&gm,"C:\\Tc\\BGI");
	cout<<"Enter the first co-ordinate of a line:";
	cin>>x1>>y1;
	cout<<"Enter the second co-ordinate of a line:";
	cin>>x2>>y2;
	line(x1,y1,x2,y2);
	cout<<"Enter the translation vector:";
	cin>>tx>>ty;
	setcolor(RED);
	x1=x1+tx;
	y1=y1+ty;
	x2=x2+tx;
	y2=y2+ty;
	line(x1,y1,x2,y2);
	getch();
	closegraph();
}

##################### ROTATION ####################

#include <math.h>
#include <iostream.h>
#include <conio.h>
#include <graphics.h>
void main()
{
	int gd=DETECT,gm,x1,x2,y1,y2,x4,y4;
	initgraph(&gd,&gm,"C:\\Tc\\BGI");
	float angle=0,ang;
	cout<<"\nROTATION OF A LINE\n";
	cout<<"Enter the first coordinate of a line:";
	cin>>x1>>y1;
	cout<<"Enter the second coordinate of a line:";
	cin>>x2>>y2;
	line(x1,y1,x2,y2);
	cout<<"Enter the angle:";
	cin>>ang;
	angle=(ang*3.14)⁄180;
	setcolor(RED);
	x4=x2-(((x2-x1)*cos(angle))-((y2-y1)+sin(angle)));
	y4=y2-(((x2-x1)*sin(angle))+((y2-y1)*cos(angle)));
	line(x2,y2,x4,y4);
	getch();
	closegraph();
}

###################### SCALING #########################

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
void main()
{
	int gd=DETECT,gm;
	float x1,y1,x2,y2,sx,sy;
	initgraph(&gd,&gm,"C:\\Tc\\BGI");
	cout<<"SCALING OF A LINE\n";
	cout<<"Enter the first coordinate of a line:";
	cin>>x1>>y1;
	cout<<"Enter the second coordinate of a line:";
	cin>>x2>>y2;
	line(x1,y1,x2,y2);
	cout<<"Enter the scaling factor:";
	cin>>sx>>sy;
	setcolor(RED);
	x1=x1*sx;
	y1=y1*sy;
	x2=x2*sx;
	y2=y2*sy;
	line(x1,y1,x2,y2);
	getch();
	closegraph();
}

################## CONCAVE POLYGON #####################

#include <conio.h>
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;
class point
{
 public:
 int x,y;
};
class poly
{
 private:
 point p[20];
 int inter[20],x,y;
 int v,xmin,ymin,xmax,ymax;
 public:
 int c;
 void read();
 void calcs();
 void display();
 void ints(float);
 void sort(int);
};
void poly::read()
{
 int i;
 cout<<"\n Scan Fill Algorithm ";
 cout<<"\n Enter Number Of Vertices Of Polygon: ";
 cin>>v;
 if(v>2)
 {
 for(i=0;i<v; i++) //ACCEPT THE VERTICES
 {
 cout<<"\nEnter co-ordinate no. "<<i+1<<" : ";
 cout<<"\n\tx"<<(i+1)<<"=";
 cin>>p[i].x;
 cout<<"\n\ty"<<(i+1)<<"=";
 cin>>p[i].y;
 }
 p[i].x=p[0].x;
 p[i].y=p[0].y;
 xmin=xmax=p[0].x;
 ymin=ymax=p[0].y;
 }
 else
 cout<<"\n Enter valid no. of vertices.";
}
void poly::calcs()
{
 for(int i=0;i<v;i++)
 {
 if(xmin>p[i].x)
 xmin=p[i].x;
 if(xmax<p[i].x)
 xmax=p[i].x;
 if(ymin>p[i].y)
 ymin=p[i].y;
 if(ymax<p[i].y)
 ymax=p[i].y;
 }
}
void poly::display()
{
 int ch1;
 char ch='y';
 float s,s2;
 do
 {
 cout<<"\n\nMENU:";
 cout<<"\n\n\t1 . Scan line Fill ";
 cout<<"\n\n\t2 . Exit ";
 cout<<"\n\nEnter your choice:";
 cin>>ch1;
 switch(ch1)
 {
 case 1:
 s=ymin+0.01;
 delay(100);
 cleardevice();
 while(s<=ymax)
 {
 ints(s);
 sort(s);
 s++;
 }
 break;
 case 2:
 exit(0);
 }
 cout<<"Do you want to continue?: ";
 cin>>ch;
 }while(ch=='y' || ch=='Y');
}
void poly::ints(float z)
{
 int x1,x2,y1,y2,temp;
 c=0;
 for(int i=0;i<v;i++)
 {
 x1=p[i].x;
 y1=p[i].y;
 x2=p[i+1].x;
 y2=p[i+1].y;
 if(y2<y1)
 {
 temp=x1;
 x1=x2;
 x2=temp;
 temp=y1;
 y1=y2;
 y2=temp;
 }
 if(z<=y2&&z>=y1)
 {
 if((y1-y2)==0)
 x=x1;
 else
 {
 x=((x2-x1)*(z-y1))/(y2-y1);
 x=x+x1;
 }
 if(x<=xmax && x>=xmin)
 inter[c++]=x;
 }
 }
}
void poly::sort(int z) // sorting
{
 int temp,j,i;
 for(i=0;i<v;i++)
 {
 line(p[i].x,p[i].y,p[i+1].x,p[i+1].y);
 }
 delay(100);
 for(i=0; i<c;i+=2)
 {
 delay(100);
 line(inter[i],z,inter[i+1],z);
 }
}
int main() //main
{
 int cl;
 initwindow(500,600);
 cleardevice();
 poly x;
 x.read();
 x.calcs();
 cleardevice();
 cout<<"\n\tEnter The Color You Want :(In Range 0 To 15 )->"; //selecting color
 cin>>cl;
 setcolor(cl);
 x.display();

 closegraph(); //closing graph
 getch();
 return 0;
}

######################### COHEN SOUTHERLAND #############################

#include <iostream>
#include <graphics.h>
using namespace std;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

// Define the rectangular clipping window
const int xMin = 50, yMin = 50, xMax = 100, yMax = 100;

int computeCode(double x, double y) {
    int code = INSIDE;

    if (x < xMin) {
        code |= LEFT;
    } else if (x > xMax) {
        code |= RIGHT;
    }

    if (y < yMin) {
        code |= BOTTOM;
    } else if (y > yMax) {
        code |= TOP;
    }

    return code;
}


void drawwindow(int xmin,int ymin,int xmax,int ymax)
{
	line(xmin,ymin,xmin,ymax);
	line(xmin,ymax,xmax,ymax);
	line(xmax,ymax,xmax,ymin);
	line(xmax,ymin,xmin,ymin);
}

void drawline(double x1,double y1,double x2,double y2)
{
	line(x1,y1,x2,y2);
}

void cohenSutherland(double x1, double y1, double x2, double y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if (!(code1 | code2)) { // Both endpoints are inside the clipping window
            accept = true;
            break;
        } else if (code1 & code2) { // Both endpoints are outside the same region
            break;
        } else {
            int codeOut = code1 ? code1 : code2;

            double x, y;
            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        cout << "Line segment after clipping: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
        	drawwindow(xMin,yMin,xMax,yMax);
        	drawline(x1,y1,x2,y2);
    } else {
        cout << "Line segment is completely outside the clipping window.\n";
    }
}

int main() {
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"");
	
    double x1, y1, x2, y2;
	drawwindow(xMin,yMin,xMax,yMax);
    cout << "Enter the coordinates of the line segment (x1 y1 x2 y2): ";
    cin >> x1 >> y1 >> x2 >> y2;

    cout << "Line segment before clipping: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
	drawline(x1,y1,x2,y2);
	
	delay(2000);
	cleardevice();
    cohenSutherland(x1, y1, x2, y2);
    getch();
closegraph();
    return 0;
}

######################### BRESENHAM CIRCLE ##########################

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void drawCircle(int x, int y, int xc, int yc);
void main()
{
	int gd = DETECT, gm;
	int r, xc, yc, pk, x, y;
	initgraph(&gd, &gm, "C:TCBGI");
	cout<<"Enter the center co-ordinates\n";
	cin>>xc>>yc;
	cout<<"Enter the radius of circle\n";
	cin>>r;
	pk = 3 - 2*r;
	x=0; y = r;
	drawCircle(x,y,xc,yc);
	while(x < y)
	{
		if(pk <= 0)
		{
			pk = pk + (4*x) + 6;
			drawCircle(++x,y,xc,yc);
		}
		else
		{
			pk = pk + (4*(x-y)) + 10;
			drawCircle(++x,--y,xc,yc);
		}
	}

	getch();
	closegraph();
}

void drawCircle(int x, int y, int xc, int yc)
{
	putpixel(x+xc,y+yc,GREEN);
	putpixel(-x+xc,y+yc,GREEN);
	putpixel(x+xc, -y+yc,GREEN);
	putpixel(-x+xc, -y+yc, GREEN);
	putpixel(y+xc, x+yc, GREEN);
	putpixel(y+xc, -x+yc, GREEN);
	putpixel(-y+xc, x+yc, GREEN);
	putpixel(-y+xc, -x+yc, GREEN);
}

########################## BRESENHAM CIRCLE ##########################3

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
void drawCircle(int x, int y, int xc, int yc);
void main()
{
	int gd = DETECT, gm;
	int r, xc, yc, pk, x, y;
	initgraph(&gd, &gm, "C:TCBGI");
	cout<<"Enter the center co-ordinates\n";
	cin>>xc>>yc;
	cout<<"Enter the radius of circle\n";
	cin>>r;
	pk = 3 - 2*r;
	x=0; y = r;
	drawCircle(x,y,xc,yc);
	while(x < y)
	{
		if(pk <= 0)
		{
			pk = pk + (4*x) + 6;
			drawCircle(++x,y,xc,yc);
		}
		else
		{
			pk = pk + (4*(x-y)) + 10;
			drawCircle(++x,--y,xc,yc);
		}
	}

	getch();
	closegraph();
}

void drawCircle(int x, int y, int xc, int yc)
{
	putpixel(x+xc,y+yc,GREEN);
	putpixel(-x+xc,y+yc,GREEN);
	putpixel(x+xc, -y+yc,GREEN);
	putpixel(-x+xc, -y+yc, GREEN);
	putpixel(y+xc, x+yc, GREEN);
	putpixel(y+xc, -x+yc, GREEN);
	putpixel(-y+xc, x+yc, GREEN);
	putpixel(-y+xc, -x+yc, GREEN);
}

################################################################################################################################################################################################################


############################### OPRETOR OVERLOADING #################################

#include <iostream>
using namespace std;
class complex
{
    int x, y;
public:
    complex()
    {
        x = 0;
        y = 0;
    }
    friend void operator>>(complex &u, complex &v)
    {
        cout << "Enter real part of 1st imaginary no (x1) : ";
        cin >> u.x;
        cout << "Enter imaginary part of 1st imaginary no (y1) : ";
        cin >> u.y;
        cout << "\nEnter real part of 1st imaginary no (x2) : ";
        cin >> v.x;
        cout << "Enter imaginary part of 1st imaginary no (y2) : ";
        cin >> v.y;
    }
    friend void operator<<(complex &u, complex &v)
    {
        cout << "\n\n1st complex no is : " << u.x << " + " << u.y << "i";
        cout << "\n2nd complex no is : " << v.x << " + " << v.y << "i";
    }
    friend void operator+(complex &u, complex &v)
    {
        complex add;
        add.x = u.x + v.x;
        add.y = u.y + v.y;
        if (add.y > 0)
        {
            cout << "Addition of two complex numbers:"
                 << "(" << add.x << "+" << add.y << "i)";
        }
        else
        {
            cout << "Addition of two complex numbers:"
                 << "(" << add.x << "+" << (-1) * add.y << "i)";
        }
    }
    friend void operator*(complex &u, complex &v)
    {
        complex multiply;
        multiply.x = (u.x * v.x) - (u.y * v.y);
        multiply.y = (u.x * v.y) + (u.y * v.x);
        if (multiply.y > 0)
        {
            cout << "Multiplication of two complex numbers:"
                 << "(" << multiply.x << "+" << multiply.y << "i)";
        }
        else
        {
            cout << "Multiplication of two complex numbers:"
                 << "(" << multiply.x << "+" << (-1) * multiply.y << "i)";
        }
    }
};
int main()
{
    complex a, b;
    operator>>(a, b);
    operator<<(a, b);
    char ch;
    char des;
    do
    {
        cout << endl
             << "\nPress '+' for addition and '*' for multiplication: ";
        cin >> ch;
        switch (ch)
        {
        case '+':
            a + b;
            break;
        case '*':
            a *b;
            break;
        default:
            cout << "Invalid choice\n";
        }
        cout << "\n\nDo you want to continue?(Y/N)";
        cin >> des;

    } while (des == 'y' || des == 'Y');
    return 0;
}

############################# STUDENT DATABASE #######################################

#include<iostream>
#include<string.h>
using namespace std;

class StudData;

class Student{
    string name;
    int roll_no;
    string cls;
    char* division;
    string dob;
    char* bloodgroup;
    static int count;

    public:

    Student()
    {
        name="";
        roll_no=0;
        cls="";
        division=new char;
        dob="dd/mm/yyyy";
        bloodgroup=new char[4];
    }

    ~Student()
    {
        delete division;
        delete[] bloodgroup;
    }

    static int getCount()
    {
        return count;
    }

    void getData(StudData*);
    void dispData(StudData*);
};

class StudData{
    string caddress;
    long int* telno;
    long int* dlno;
    friend class Student;

    public:

    StudData()
    {
        caddress="";
        telno=new long;
        dlno=new long;
    }
    
    ~StudData()
    {
        delete telno;
        delete dlno;
    }

    void getStudData()
    {
        cout<<"Enter Contact Address : ";
        cin.get();
        getline(cin,caddress);
        cout<<"Enter Telephone Number : ";
        cin>>*telno;
        cout<<"Enter Driving License Number : ";
        cin>>*dlno;
    }

    void dispStudData()
    {
        cout<<"Contact Address : "<<caddress<<endl;
        cout<<"Telephone Number : "<<*telno<<endl;
        cout<<"Driving License Number : "<<*dlno<<endl;
    }
};

inline void Student::getData(StudData* st)
{
    cout<<"Enter Student Name : ";
    getline(cin,name);
    cout<<"Enter Roll Number : ";
    cin>>roll_no;
    cout<<"Enter Class : ";
    cin.get();
    getline(cin,cls);
    cout<<"Enter Division : ";
    cin>>division;
    cout<<"Enter Date of Birth : ";
    cin.get();
    getline(cin,dob);
    cout<<"Enter Blood Group : ";
    cin>>bloodgroup;
    st->getStudData();
    count++;
}

inline void Student::dispData(StudData* st1)
{
    cout<<"Student Name : "<<name<<endl;
    cout<<"Roll Number : "<<roll_no<<endl;
    cout<<"Class : "<<cls<<endl;
    cout<<"Division : "<<division<<endl;
    cout<<"Date of Birth : "<<dob<<endl;
    cout<<"Blood Group : "<<bloodgroup<<endl;
    st1->dispStudData();
}

int Student::count;

int main()
{
    Student* stud1[100];
    StudData* stud2[100];
    int n=0;
    char ch;

    do
    {
        stud1[n]=new Student;
        stud2[n]=new StudData;
        stud1[n]->getData(stud2[n]);
        n++;
        cout<<"Do you want to add another student (y/n) : ";
        cin>>ch;
        cin.get();
    } while (ch=='y' || ch=='Y');

    for(int i=0;i<n;i++)
    {
        cout<<"---------------------------------------------------------------"<<endl;
        stud1[i]->dispData(stud2[i]);
    }

    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"Total Students : "<<Student::getCount();
    cout<<endl<<"---------------------------------------------------------------"<<endl;

    for(int i=0;i<n;i++)
    {
        delete stud1[i];
        delete stud2[i];
    }
    

    return 0;
}

############################################### IMPLEMENTATION INHERITANCE #######################################

# include<iostream>
# include<stdio.h>
using namespace std;
class publication              
 {
 private:
 string title;
 float price;
 public:
 void add()
 {
 cout << "\nEnter the Publication information : " << endl;
 cout << "Enter Title of the Publication : ";
cin.ignore();
getline(cin, title);
cout << "Enter Price of Publication in INR: ";
 cin >> price;
 }
 void display()
 {
 cout << "\n--------";
 cout << "\nTitle of Publication : " << title;
 cout << "\nPublication Price in INR : " << price;
 }
 };
 class book : public publication 
 {
 private:
 int page_count;
 public:
 void add_book()
 {
 try
 {
 add();
cout << "Enter Page Count of Book : ";
 cin >> page_count;
 if (page_count <= 0)
 {
 throw page_count;
 }
 }
 catch(...)
 {
 cout << "\nInvalid Page Count!!!";
 page_count = 0;
 }
 }
 void display_book()
 {
 display();
cout << "\nPage Count : " <<
page_count;
 cout << "\n--------\n";
 }
 };
 class tape : public publication     
 {
 private:
 float play_time;
 public:
 void add_tape()
 {
 try
 {
 add();
cout << "Enter Play Duration of the Tape : ";
 cin >> play_time;
 if (play_time <= 0)
 throw play_time;
 }
 catch(...)
 {
 cout << "\nInvalid Play Time!!!";
 play_time = 0;
 }
 }
 void display_tape()
 {
 display();
 cout << "\nPlay Time : " <<
play_time << " min";
 cout << "\n--------\n";
 }
 };
 int main()
 {
 book b1[10];            
 tape t1[10];            
 int ch, b_count = 0, t_count = 0;
 do
 {
 cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
 cout << "\n--------------------MENU-----------------------";
 cout << "\n1. Add Information to Books";
 cout << "\n2. Add Information to Tapes";
 cout << "\n3. Display Books Information";
 cout << "\n4. Display Tapes Information";
 cout << "\n5. Exit";
 cout << "\n\nEnter your choice : ";
 cin >> ch;
 switch(ch)
 {
 case 1:
 b1[b_count].add_book();
b_count ++;
break;
 case 2:
 t1[t_count].add_tape();
 t_count ++;
 break;
 case 3:
 cout << "\n* * * * BOOK PUBLICATION DATABASE SYSTEM * * * *";
 for (int j=0;j < b_count;j++)
 {
 b1[j].display_book();
 }
 break;
 case 4:
 cout << "\n* * * * TAPE PUBLICATION DATABASE SYSTEM * * * *";
 for (int j=0;j < t_count;j++)
 {
 t1[j].display_tape();
 }
 break;
 case 5:
 exit(0);
 }
 }while (ch != 5);
 return 0;
 }

###################################################### FILE HANDLING ################################################

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    char Give_Info[500];
    ofstream out_file;
    out_file.open("Information.txt",ios::out);
    cout<<"Enter information to store in file (Not more than 150 characters): ";
    fgets(Give_Info,500,stdin);
    out_file<<Give_Info;
    out_file.close();
    char Get_Info[500];
    ifstream in_file;
    in_file.open("Information.txt",ios::in);
    in_file.getline(Get_Info,500);
    cout<<"\n\nGiven Information is : \n";
    cout<<Get_Info;
    in_file.close();
    return 0;
}

############################################### FUNTION TEMPLATE #######################################

#include<iostream> 
using namespace std; 
int n; 
# define size 10 
template<class T> void sel (T A[size]) 
{   int i,j,min;     
    T temp;     
    for(i=0;i<n-1;i++) 
    { 
        min=i;         
        for(j=i+1;j<n;j++) 
        { 
            if(A[j]<A[min])             
            min=j; 
             
        } 
        temp=A[i]; 
        A[i]=A[min]; 
        A[min]=temp; 
 
    } 
    cout<<"\nSorted array";     
    for(i=0;i<n;i++) 
    { 
        cout<<" "<<A[i]; 
    } 
} 
int main() 
{ 
    int A[size];     
    float B[size]; 
    int i; 
 
    cout<<"\nEnter total number of elements : ";     
    cin>>n;     
    for(i=0;i<n;i++) 
    { 
         cout<<"\nEnter integer element : "; 
         cin>>A[i]; 
    } 
    sel(A); 
    cout<<"\nEnter total number of float elements : ";     
    cin>>n;     
    for(i=0;i<n;i++) 
    { 
         cout<<"\nEnter float element : "; 
         cin>>B[i]; 
    } 
    sel(B); 
} 

############################################## STL SEARCHING SORTING ####################################################

#include <iostream>
#include <algorithm> 
using namespace std;
class person {     
    public:
    string name;     
    string dob;     
    long tel;
    void getdata()
    {
        cout<<"ENTER NAME: "<<endl;         
        cin>>name;
        cout<<"ENTER BIRTHDATE: "<<endl;         
        cin>>dob;
        cout<<"ENTER PHONE NUMBER: "<<endl;         
        cin>>tel;
    }
    void displaydata()
    {
        cout<<"\nNAME :-"<<name<<endl;         
        cout<<"DATE OF BIRTH:-"<<dob<<endl;         
        cout<<"TELEPHONE :-"<<tel<<endl;
    }
};
bool compare(const person & a, const person & b)
{
    return a.name < b.name; }
int main()
{   int n,c;
    cout<<"ENTER TOTAL NUMBER OF RECORDS :-";
    cin>>n;     
    string z[n];     
    person p[n];     
    for(int i=0;i<n;i++)
    {
        p[i].getdata();
    }
   
    cout<<"*****SORTED RECORD******"<<endl;     
    sort(p, p+n, compare);     
    for(int i=0;i<n;i++)
    {
        p[i].displaydata();
    }
    cout<<endl;
    string nm;
    cout<<"ENTER NAME TO BE SEARCH: ";
    cin>>nm;
    for(int i=0;i<n;i++)
    {         z[i]=p[i].name;
    }
    
    if(binary_search(z, z+n, nm))
    {
        cout<<"****RECORD FOUND****";
    }
    else cout<<"****RECORD NOT FOUND****";
    return 0;
}

########################################### ASSOCIATIVE CONTAINER (POPULATION) ######################################

#include <iostream>
#include <map>
#include <string> 
using namespace std;
int main()
{
    map <string, int> populationMap;
    populationMap.insert(pair<string, int>("MH", 112));     
    populationMap.insert(pair<string, int>("UP", 199));     
    populationMap.insert(pair<string, int>("MP", 726));     
    populationMap.insert(pair<string, int>("AP", 845));
    map<string,int>::iterator iter = populationMap.end();
    cout<<"Size of populationMap : "<<populationMap.size()<<"\n";
    for(iter=populationMap.begin(); iter!=populationMap.end(); ++iter)
    {
        cout<<iter->first<<" : "<<iter->second<<" million\n";
    }
    string state;
    cout<<"\nEnter the state : ";     
    cin>>state;
    iter = populationMap.find(state);     
    if(iter!=populationMap.end())
        cout<<state<<" population is : "<<iter->second<<" million\n";
    else
    cout<<"Key is not in populationMap";
    populationMap.clear();
        return 0;
}
