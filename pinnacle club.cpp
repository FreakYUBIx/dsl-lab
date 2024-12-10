#include <iostream>
#include <string.h>
using namespace std;

struct node
{
    string name;
    string prn;
    struct node *next;
};

typedef struct node node;

class club
{
private:
    node *sec;
    int count;

public:
		node *pres;
    club()
    {
        pres = NULL;
        sec = NULL;
        count = 0;
    }
    ~club();
    void create();
    void display();
    void insert();
    void count_mem();
    void concat(club &);
    void delete_mem();
    void reverse(node *);
};

club::~club()
{
	node *temp,*temp2;
	temp=pres;
	while(temp!=NULL)
	{
		temp2=temp;
		delete temp;
		temp=temp2->next;
	}
	cout<<"Descrutor called."<<endl;
}

void club::create() {
    node *newnode;
    newnode = new node;
    cout << "Enter president name: ";
    cin >> newnode->name;
    cout << "Enter president PRN: ";
    cin >> newnode->prn;
    newnode->next = NULL;
    pres = newnode;

    newnode = new node;
    cout << "Enter secretary name: ";
    cin >> newnode->name;
    cout << "Enter secretary PRN: ";
    cin >> newnode->prn;
    newnode->next = NULL;
    sec = newnode; 

    pres->next = sec;

    cout << "Enter number of club members: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        newnode = new node;
        cout << "Enter member name: ";
        cin >> newnode->name;
        cout << "Enter member PRN: ";
        cin >> newnode->prn;
        newnode->next = NULL;

        newnode->next = pres->next; 
        pres->next = newnode;
    }
}


void club ::display()
{
    node *temp = pres;
    cout<<endl;
    cout << "NAME" << "     " << "PRN" << endl;
    while (temp != NULL)
    {
        cout << temp->name << "     " << temp->prn << endl;
        if(temp==pres)
        	cout<<"\t --PRESIDENT"<<endl;
        if(temp==sec)
        	cout<<"\t --SECRETARY"<<endl;
        temp = temp->next;
    }
}

void club::count_mem()
{
	node *temp=pres;
	if(temp==NULL)
		cout<<"List is empty."<<endl;
	else
	{
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		cout<<"\nTotal members of club are : "<<count<<endl;
	}
}

void club::insert()
{
	cout<<"\nInsert a new member : "<<endl;
	node *temp=new node;
	node *newnode=new node;
	cout<<"\nEnter member name : ";
	cin>>newnode->name;
	cout<<"Enter member PRN : ";
	cin>>newnode->prn;
	newnode->next=NULL;
	
	if(pres==NULL)
		pres=newnode;
	else if(pres->next==NULL)
		sec=newnode;
	else
	{
		temp=pres;
		while(temp->next!=sec)
			temp=temp->next;
		temp->next=newnode;
		newnode->next=sec;
	}
}

void club::concat(club &l)
{
	sec->next=l.pres;
	sec=NULL;
	l.pres=NULL;
	sec=l.sec;
}

void club::delete_mem()
{
	node *temp=pres;
	string student_prn;
	node *prev=new node;
	cout<<"Enter PRN to be deleted : ";
	cin>>student_prn;
	for(temp=pres;temp->next!=NULL;temp=temp->next)
	{
		if(temp->prn==student_prn)
			break;
		prev=temp;
	}
	if(temp==pres){
		pres=temp->next;
		temp->next=NULL;
	}
	else if(temp==sec)
	{
		sec=prev;
		prev->next=NULL;
	}
	else
	{
		prev->next=temp->next;
		temp->next=NULL;
	}
	cout<<student_prn<<" deleted successfully"<<endl;
	delete temp;
}

void club::reverse(node *p)
{
	if(p->next!=NULL)
		reverse(p->next);
	cout<<p->name<<"\t"<<p->prn<<endl;
}

int main()
{
    club c1,c2;
    while(true)
    {
    	int ch;
    	cout<<"1.Create Club"<<endl;
    	cout<<"2.Display Club"<<endl;
    	cout<<"3.Add member to club."<<endl;
    	cout<<"4.Count memeber of club."<<endl;
    	cout<<"5.Delete member from club"<<endl;
    	cout<<"6.Combine two divisions."<<endl;
    	cout<<"7.Reverse the club members."<<endl;
    	cout<<"8.Exit."<<endl;
    	cout<<"\nEnter your choice : "<<endl;
    	cin>>ch;
    	
    	switch(ch);
    	{
    	 case 1:
    	 	c1.create();
    	 	break;
    	 case 2:
    	 	c1.display();
    	 	break;
    	 case 3:
    	 	c1.insert();
    	 	c1.display();
    	 	break;
    	 case 4:
    	 	c1.count_mem();
    	 	break;
    	 case 5:
    	 	c1.delete_mem();
    	 	c1.display();
    	 	break;
    	 case 6:
    	 	c1.concat(c2);
    	 	c1.display();
    	 	break;
    	 case 7:
    	 	c1.create();
    	 	c1.display();
    	 	node *temp=pres;
    	 	c1.reverse(temp);
    	 	break;
    	 case 8:
    	 	cout<<"\nEnd of Program."<<endl;
    	 	break;
    	 default:
    	 	cout<<"\nYou entered wrong choice."<<endl;
    	}
    }
}
