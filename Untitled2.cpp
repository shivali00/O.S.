#include<iostream>
using namespace std;
int wait(int s1);
int signal(int sig);
void producer();
void consumer();
int s=1;
int e=10;
int f=0;
	
int main()
{
	int ch;
while(1)
{
	cout<<"1.Producer 2.Consumer 3.Exit\n";
	cin>>ch;
	if(ch==1)
	{
		if(s==1 && e!=0)	
             producer();
        else
        {
        	cout<<"Buffer is full.Producer cannot produce \n";
		continue;
		}
        
}
	if(ch==2)
	{
	if(s==1 && f!=0)	
             consumer();
        else
        {
        	cout<<"Buffer is empty.consumer cannot consume";
		continue;
		}
	}
    			
    if(ch==3) break;
}
return 0;
}
int wait(int s)
{
return --s;
}
int signal(int s)
{
	return ++s;
}
void producer()
{
	s=wait(s);
	e=wait(e);
	f=signal(f);
	cout<<"Producer is working and consumer is waiting.\n";
	s=signal(s);
}
void consumer()
{
	s=wait(s);
	f=wait(f);
	e=signal(e);
	cout<<"Consumer is working and producer is waiting \n";
	s=signal(s);
}
