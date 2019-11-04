#include <iostream>
#include <string>
//https://www.youtube.com/watch?v=714LTMNJy5M&t=267s is the cite where I got this process
using namespace std;
void printarray(int a[6][7]);        // declaring function for printing the month in the form of Calendar
void printmonth(int month,int year);    //declaring function to print the month
void printyear(int year);          //declaring function to print the year
int main()
{
     int year;
     int month;
     char ch;
     int option=0;
     cout<<"what do u want to print.Enter Options"<<endl;   //this will show the options
     cout<<"1.Calendar of a month"<<endl;
     cout<<"2.Calendar of whole year"<<endl;
     cin>>option;
     if(option==1)
     {cout<<"enter any month and year after 1500"<<endl;
     cin>>month>>ch>>year;}
     else if(option==2)
     {cout<<"enter year"<<endl;
     cin>>year;}
     else
     {cout<<"invalid option"<<endl;}
     if(option==1)
     {printmonth(month,year);}    //testing and calling printmonth function
     if(option==2)
     {printyear(year);}              //testing and calling printyear function
     return 0;
}
   void printarray(int a[6][7])    //defining the function of printarray
   {for(int i=0;i<6;i++)     //for the row of the array
     {for(int j=0;j<7;j++)  //for the column of the array
      {if(a[i][j]==0)     //print spaces instead of zeros
        cout<<"   ";
        if(a[i][j]<10&&a[i][j]>0)
         cout<<" "<<a[i][j]<<" "; //wont print zero and have spaces after and before
      else if(a[i][j]>=10)
         cout<<a[i][j]<<" ";  //printing spaces after every date
       }
     cout<<endl;}  //going to next line
   }

    void printmonth(int month,int year){    //defining printmonth function

     int y=year;
     int index_fin=0;  //the century code for doomday
      //The number was kept in the index finger traditionally
     int mid_fin=0;    //the quotient after dividing the last three digits of the year with 12.
     //The number was kept in the middle finger traditionally
     int ring_fin=0;   //the reminder after dividing the last three digits with 12.
      //The number was kept in the ring finger traditionally
     int pinky_fin=0;    //quotient after dividing the reminder with 4.
      //The number was kept in the pinky finger traditionally
     int total_fin=0;   //addition of the 4 variables above.
     int calendar[6][7]; //the array of calendar
     int doomday=0;  //the dates which follows the same day(eg;sunday,monday etc) in every year
     int i=0;  // counters
     int c=0;
     string dayarray[]={"S","M","Tu","W","Th","F","SA"}; //days
     string days[]={" S  M","Tu W Th","F  S"}; //days to print in the calendar
     string montharray[]={"P","JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
     cout<<"    "<<montharray[month]<<"    "<<year<<endl; //to prin the month and year with the calendar
     for(int i=0;i<3;i++)
     {cout<<days[i]<<"  ";}
     cout<<endl;   //to print the days with the calendar
     string firstday;   //the variable to find firstday
     if (year%400==0||(year%100!=0 && year%4==0))
     {total_fin=total_fin+2;}  //if the year is leap year 2 is added to the total of the variables

     for(y=y/100*100;y>1500;y=y-400)
     {if(y>=1500&&y<=1800)
     break;}   //to determine the century code of any century.

     year=year%100;
     mid_fin=year/12;  //
    // cout<<mid_fin<<"mf"<<endl;
     ring_fin=year%12;
    // cout<<ring_fin<<"rf"<<endl;
     if(ring_fin>=4)
     {pinky_fin=ring_fin/4;}
     else
     pinky_fin=0;
    //cout<<pinky_fin<<"pf"<<endl;
     if (y==1800)
       index_fin=5;  //century codes repeat every 400 years.
     if (y==1600)
       index_fin=2;
     if (y==1700)
       index_fin=0;
     if(y==1500)
       index_fin=3;
     //cout<<index_fin<<"if"<<endl;
     total_fin=index_fin+mid_fin+ring_fin+pinky_fin;
     total_fin=total_fin % 7; //taking the reminder of it and that will be converted into days
     //cout<<total_fin<<"tf"<<endl;

     if(year%400==0||(year%100!=0 && year%4==0)) //applicable for the leap years
     {if(month==1)
     {doomday=4;  //specific doomdays for each month
     if(total_fin>=3)    //after finding the day on the doomday
     {firstday=dayarray[total_fin-3];}  // we are now finding the day on the first day
     else
     {firstday=dayarray[total_fin+4];}}
     else if(month==2)
     {doomday=29;
     firstday=dayarray[total_fin];}
    else if(month==3)
   {doomday=14;
     if(total_fin>=6)
     {firstday=dayarray[total_fin-6];}
     else
     {firstday=dayarray[total_fin+1];}}
   else if(month==4)
   {doomday=4;
     if(total_fin>=3)
     firstday=dayarray[total_fin-3];
     else
     firstday=dayarray[total_fin+4];}
     else if(month==5)
     {doomday=9;
     if(total_fin>=1)
     firstday=dayarray[total_fin-1];
     else
     firstday=dayarray[total_fin+6];}
     else if(month==6)
     {doomday=6;
     if(total_fin>=5)
     firstday=dayarray[total_fin-5];
     else
     firstday=dayarray[total_fin+2];}
     else if(month==7)
     {doomday=11;
     if(total_fin>=3)
     firstday=dayarray[total_fin-3];
     else
     firstday=dayarray[total_fin+4];}
     else if(month==8)
     {doomday=8;
     firstday=dayarray[total_fin];}
     else if(month==9)
     {doomday=5;
     if(total_fin>=4)
     firstday=dayarray[total_fin-4];
     else
     firstday=dayarray[total_fin+3];}
     else if(month==10)
     {doomday=10;
     if(total_fin>=2)
     firstday=dayarray[total_fin-2];
     else
     firstday=dayarray[total_fin+5];}
     else if(month==11)
     {doomday=7;
     if(total_fin>=6)
     firstday=dayarray[total_fin-6];
     else
     firstday=dayarray[total_fin+1];
     }
     else
     {doomday=12;
     if(total_fin>=4)
     firstday=dayarray[total_fin-4];
     else
     firstday=dayarray[total_fin+3];}}

  else                     //for the non leap years
     {if(month==1)
       {doomday=3;
       if(total_fin>=2)
        {firstday=dayarray[total_fin-2];}
       else
        {firstday=dayarray[total_fin+5];}}
     else if(month==2)
        {doomday=28;
        if(total_fin>=6)
          {firstday=dayarray[total_fin-6];}
       else
          firstday=dayarray[total_fin+1];}
     else if(month==3)
        {doomday=14;
       if(total_fin>=6)
        firstday=dayarray[total_fin-6];
       else
        firstday=dayarray[total_fin+1];}
     else if(month==4)
       {doomday=4;
       if(total_fin>=3)
        firstday=dayarray[total_fin-3];
       else
        firstday=dayarray[total_fin+4];}
     else if(month==5)
       {doomday=9;
       if(total_fin>=1)
        firstday=dayarray[total_fin-1];
       else
        firstday=dayarray[total_fin+6];}
     else if(month==6)
       {doomday=6;
       if(total_fin>=5)
         firstday=dayarray[total_fin-5];
       else
         firstday=dayarray[total_fin+2];}
     else if(month==7)
      {doomday=11;
       if(total_fin>=3)
         firstday=dayarray[total_fin-3];
       else
       firstday=dayarray[total_fin+4];}
     else if(month==8)
       {doomday=8;
       firstday=dayarray[total_fin];}
     else if(month==9)
       {doomday=5;
       if(total_fin>=4)
        firstday=dayarray[total_fin-4];
       else
        firstday=dayarray[total_fin+3];}
     else if(month==10)
       {doomday=10;
       if(total_fin>=2)
         firstday=dayarray[total_fin-2];
       else
         firstday=dayarray[total_fin+5];}
     else if(month==11)
        {doomday=7;
       if(total_fin>=6)
        firstday=dayarray[total_fin-6];
       else
        firstday=dayarray[total_fin+1];}
     else
     {doomday=12;
       if(total_fin>=4)
        firstday=dayarray[total_fin-4];
       else
        firstday=dayarray[total_fin+3];}}
       if(firstday=="S"&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12))
         {int calendar[6][7]={                      //for printing the whole month with 31 days starting on sunday.
                        {1,2,3,4,5,6,7},
                        {8,9,10,11,12,13,14},
                        {15,16,17,18,19,20,21},
                        {22,23,24,25,26,27,28},
                        {29,30,31}
                      };

                  printarray(calendar);}
         if(firstday=="S"&&(month==4||month==6||month==9||month==11))
         {  int calendar[6][7]={
                           {1,2,3,4,5,6,7}, //for printing the whole month with 30 days starting on sunday.
                           {8,9,10,11,12,13,14},
                           {15,16,17,18,19,20,21},
                           {22,23,24,25,26,27,28},
                           {29,30}
                         };

                     printarray(calendar);}

         if(firstday=="M"&&(month==4||month==6||month==9||month==11))
         {  int calendar[6][7]={
                           {0,1,2,3,4,5,6},
                           {7,8,9,10,11,12,13},
                           {14,15,16,17,18,19,20},
                           {21,22,23,24,25,26,27},
                           {28,29,30,0,0,0,0}
                         };

                     printarray(calendar);}

        if(firstday=="M"&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12))
                                  {
                                    int calendar[6][7]={
                                                    {0,1,2,3,4,5,6},
                                                    {7,8,9,10,11,12,13},
                                                    {14,15,16,17,18,19,20},
                                                    {21,22,23,24,25,26,27},
                                                    {28,29,30,31,0,0,0}
                                                  };

                                              printarray(calendar);}
      if(firstday=="Tu"&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12))
                                     {  int calendar[6][7]={
                                                       {0,0,1,2,3,4,5,},
                                                     {6,7,8,9,10,11,12},
                                                     {13,14,15,16,17,18,19},
                                                    {20,21,22,23,24,25,26},
                                                    {27,28,29,30,31,0,0}
                                                         };

                                             printarray(calendar);}
     if(firstday=="Tu"&&(month==4||month==6||month==9||month==11))
                          {  int calendar[6][7]={
                                                 {0,0,1,2,3,4,5,},
                                                {6,7,8,9,10,11,12},
                                               {13,14,15,16,17,18,19},
                                               {20,21,22,23,24,25,26},
                                               {27,28,29,30,0,0,0}
                                                            };
                                     printarray(calendar);}
  if(firstday=="W"&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12))
                          {  int calendar[6][7]={
                                                 {0,0,0,1,2,3,4},
                                               {5,6,7,8,9,10,11},
                                         {12,13,14,15,16,17,18},
                                         {19,20,21,22,23,24,25},
                                         {26,27,28,29,30,31,0}
                                                  };

                                          printarray(calendar);}
  if(firstday=="W"&&(month==4||month==6||month==9||month==11))
                              {  int calendar[6][7]={
                                                   {0,0,0,1,2,3,4},
                                                  {5,6,7,8,9,10,11},
                                                 {12,13,14,15,16,17,18},
                                                {19,20,21,22,23,24,25},
                                                {26,27,28,29,30,0,0}
                                                            };
                                          printarray(calendar);}
  if(firstday=="Th"&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12))
                              {  int calendar[6][7]={
                                                   {0,0,0,0,1,2,3},
                                                {4,5,6,7,8,9,10},
                                              {11,12,13,14,15,16,17},
                                              {18,19,20,21,22,23,24},
                                              {25,26,27,28,29,30,31}
                                                      };
                                          printarray(calendar);}
if(firstday=="Th"&&(month==4||month==6||month==9||month==11))
                              {  int calendar[6][7]={
                                                   {0,0,0,0,1,2,3},
                                                  {4,5,6,7,8,9,10},
                                                  {11,12,13,14,15,16,17},
                                                  {18,19,20,21,22,23,24},
                                                 {25,26,27,28,29,30}
                                                    };
                                    printarray(calendar);}
  if(firstday=="F"&&(month==4||month==6||month==9||month==11))
                            {  int calendar[6][7]={
                                                  {0,0,0,0,0,1,2},
                                                  {3,4,5,6,7,8,9},
                                                 {10,11,12,13,14,15,16},
                                                {17,18,19,20,21,22,23},
                                                {24,25,26,27,28,29,30}
                                                      };
                                  printarray(calendar);}
if(firstday=="F"&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12))
                            {  int calendar[6][7]={
                                                {0,0,0,0,0,1,2},
                                              {3,4,5,6,7,8,9},
                                             {10,11,12,13,14,15,16},
                                          {17,18,19,20,21,22,23},
                                          {24,25,26,27,28,29,30},
                                          {31}
                                                };
                                printarray(calendar);}
  if(firstday=="SA"&&(month==1||month==3||month==5||month==7||month==8||month==10||month==12))
                              {  int calendar[6][7]={
                                                      {0,0,0,0,0,0,1},
                                                      {2,3,4,5,6,7,8},
                                                      {9,10,11,12,13,14,15},
                                                      {16,17,18,19,20,21,22},
                                                      {23,24,25,26,27,28,29},
                                                      {30,31}
                                                           };
                                        printarray(calendar);}
  if(firstday=="SA"&&(month==4||month==6||month==9||month==11))
                            {  int calendar[6][7]={
                                                    {0,0,0,0,0,0,1},
                                                    {2,3,4,5,6,7,8},
                                                  {9,10,11,12,13,14,15},
                                                  {16,17,18,19,20,21,22},
                                                  {23,24,25,26,27,28,29},
                                                    {30}
                                                       };
                                    printarray(calendar);}
  if(firstday=="S"&&(month==2)&&(year%400==0||(year%100!=0 && year%4==0)))
                            {  int calendar[6][7]={
                                                    {1,2,3,4,5,6,7},
/*for printing the month of february in leap year*/ {8,9,10,11,12,13,14},
                                                    {15,16,17,18,19,20,21},
                                                    {22,23,24,25,26,27,28},
                                                    {29},
                                                    {}
                                                   };
                                    printarray(calendar);}
  if(firstday=="S"&&(month==2)&&!(year%400==0||(year%100!=0 && year%4==0)))
                           {  int calendar[6][7]={
                                                  {1,2,3,4,5,6,7},
                                                  {8,9,10,11,12,13,14},
          /*not leap year*/                       {15,16,17,18,19,20,21},
                                                  {22,23,24,25,26,27,28},
                                                  {},
                                                  {}
                                                   };
                                    printarray(calendar);}
  if(firstday=="M"&&(month==2)&&(year%400==0||(year%100!=0 && year%4==0)))
                              {  int calendar[6][7]={
                                                  {0,1,2,3,4,5,6,},
                                                  {7,8,9,10,11,12,13},
                                                  {14,15,16,17,18,19,20},
                                                  {21,22,23,24,25,26,27},
                                                  {28,29},
                                                  {}
                                                   };
                                printarray(calendar);}
if(firstday=="M"&&(month==2)&&!(year%400==0||(year%100!=0 && year%4==0)))
                              {  int calendar[6][7]={
                                                      {0,1,2,3,4,5,6},
                                                      {7,8,9,10,11,12,13},
                                                      {14,15,16,17,18,19,20},
                                                      {21,22,23,24,25,26,27},
                                                      {28},
                                                        {}
                                                       };
                                  printarray(calendar);}
  if(firstday=="Tu"&&(month==2)&&(year%400==0||(year%100!=0 && year%4==0)))
                                {  int calendar[6][7]={
                                                      {0,0,1,2,3,4,5},
                                                    {6,7,8,9,10,11,12},
                                                    {13,14,15,16,17,18,19},
                                                  {20,21,22,23,24,25,26},
                                                    {27,28,29},
                                                      {}
                                                     };
                              printarray(calendar);}
  if(firstday=="Tu"&&(month==2)&&!(year%400==0||(year%100!=0 && year%4==0)))
                                  {  int calendar[6][7]={
                                                    {0,0,1,2,3,4,5},
                                                    {6,7,8,9,10,11,12},
                                                    {13,14,15,16,17,18,19},
                                                  {20,21,22,23,24,25,26},
                                                  {27,28},
                                                   {}
                                                       };
                              printarray(calendar);}
    if(firstday=="W"&&(month==2)&&(year%400==0||(year%100!=0 && year%4==0)))
                                  {  int calendar[6][7]={
                                                    {0,0,0,1,2,3,4},
                                                    {5,6,7,8,9,10,11},
                                                    {12,13,14,15,16,17,18},
                                                    {19,20,21,22,23,24,25},
                                                      {26,27,28,29},
                                                      {}
                                                   };
                              printarray(calendar);}
  if(firstday=="W"&&(month==2)&&!(year%400==0||(year%100!=0 && year%4==0)))
                                {  int calendar[6][7]={
                                                    {0,0,0,1,2,3,4},
                                                  {5,6,7,8,9,10,11},
                                                  {12,13,14,15,16,17,18},
                                                  {19,20,21,22,23,24,25},
                                                  {26,27,28},
                                                  {}
                                                 };
                              printarray(calendar);}
if(firstday=="Th"&&(month==2)&&(year%400==0||(year%100!=0 && year%4==0)))
                            {  int calendar[6][7]={
                                                  {0,0,0,0,1,2,3},
                                                 {4,5,6,7,8,9,10},
                                                {11,12,13,14,15,16,17},
                                                {18,19,20,21,22,23,24},
                                                {25,26,27,28,29},
                                                  {}
                                                 };
                            printarray(calendar);}
   if(firstday=="Th"&&(month==2)&&!(year%400==0||(year%100!=0 && year%4==0)))
                              {  int calendar[6][7]={
                                                    {0,0,0,0,1,2,3},
                                                    {4,5,6,7,8,9,10},
                                                    {11,12,13,14,15,16,17},
                                                    {18,19,20,21,22,23,24},
                                                    {25,26,27,28},
                                                    {}
                                                    };
                              printarray(calendar);}
  if(firstday=="F"&&(month==2)&&(year%400==0||(year%100!=0 && year%4==0)))
                              {  int calendar[6][7]={
                                                    {0,0,0,0,0,1,2},
                                                   {3,4,5,6,7,8,9},
                                                  {10,11,12,13,14,15,16},
                                                  {17,18,19,20,21,22,23},
                                                  {24,25,26,27,28},
                                                    {}
                                                  };
                              printarray(calendar);}
  if(firstday=="F"&&(month==2)&&!(year%400==0||(year%100!=0 && year%4==0)))
                                {  int calendar[6][7]={
                                                      {0,0,0,0,0,1,2},
                                                      {3,4,5,6,7,8,9},
                                                      {10,11,12,13,14,15,16},
                                                      {17,18,19,20,21,22,23},
                                                      {24,25,26,27,28},
                                                    {}
                                                     };
                                printarray(calendar);}
  if(firstday=="SA"&&(month==2)&&!(year%400==0||(year%100!=0 && year%4==0)))
                                {  int calendar[6][7]={
                                                      {0,0,0,0,0,0,1},
                                                     {2,3,4,5,6,7,8},
                                                    {9,10,11,12,13,14,15},
                                                    {16,17,18,19,20,21,22},
                                                    {23,24,25,26,27,28},
                                                      {}
                                                    };
                                printarray(calendar);}
if(firstday=="SA"&&(month==2)&&(year%400==0||(year%100!=0 && year%4==0)))
                                {  int calendar[6][7]={
                                                    {0,0,0,0,0,0,1},
                                                   {2,3,4,5,6,7,8},
                                                  {9,10,11,12,13,14,15},
                                                {16,17,18,19,20,21,22},
                                                {23,24,25,26,27,28,29},
                                                  {}
                                                    };
                              printarray(calendar);}
}
void printyear(int year){  //defining function print year
  for(int i=1;i<=12;i++)
  {printmonth(i,year);    //calling printmonth function for 12 times to print the whole year
  cout<<endl;}
}
