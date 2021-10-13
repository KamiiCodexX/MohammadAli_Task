#include <iostream>
#include <iomanip>
using namespace std;

//This function have default values as given in sample of the problem.
void Pets2U(char a[], int noa)
{
	int r=400, rem=0;	
	int b1=400, b2=800, b3=1600;

	int B1=0, B2=0, B3=0;
	
	for(int i=0;i<noa;i++)
	{
		if(a[i]=='S')
		{	
			B3++;
			rem=400;
		}
	}
	int j=0;
	while(j<noa)
	{

		if(a[j]=='R'||a[j]=='H')
		{
			if(rem>=r)
			{
				rem=rem-r;
			}
			else
			{
				B1++;
			}
		}
		else if(a[j]=='M')
		{
			B2++;
		}
		j++;
	}
	
	while(true)
	{

		if(B1==1)
		{
			if(rem>=400)
			{
				rem=rem-400;
			}
			break;
		}
		else if(B1>=4)
		{
			B3++;
			B1=B1-4;
		}
		else if(B1>=3)
		{
			B3++;
			B1=B1-3;
			rem=rem+400;
		}
		else if(B1>=2)
		{
			B2++;
			B1=B1-2;
		}
		else
		{
			break;
		}
	}
	
	while(true)
	{

		if(B2>=2)
		{
			B3++;
			B2=B2-2;
		}
		else if(B2>=1 && B1>=1)
		{
			B3++;
			B2=B2-1;
			B1=B1-1;
		}
		else
		{
			break;
		}
	}
	
	
	for(int i=0;i<noa;i++)
	{
		cout<<a[i]<<", ";	
	}
	cout<<setw(18);
	for(int i=0;i<B1;i++)
	{
		cout<<"B1, ";
	}
	
	for(int i=0;i<B2;i++)
	{
		cout<<"B2, ";
	}
	
	for(int i=0;i<B3;i++)
	{
		cout<<"B3, ";
	}
	
	cout<<endl<<endl;
	
}

//This function is used to handle the problem. I have used area formula (width x height) to assign boxes.
void Pets2U()
{
	int r=400, rem=0;	
	int noa=0; //no of animals in 1 order.
	
	cout<<"Enter Number of Animals in your order: "<<endl;
	cin>>noa;
	
	char a[noa]; //array containing type of pet.
	int B1=0, B2=0, B3=0; //Each representing type of box in each order.
	
	cout<<"Enter your order: "<<endl;
	for(int i=0;i<noa;i++)
	{
		do
		{
		cin>>a[i];
		}while(a[i]!='R'&&a[i]!='H'&&a[i]!='M'&&a[i]!='S');
		
		if(a[i]=='S') //Snake is a special case, it leaves area in Box3 which can only be assigned to Rats or Hedgehog.
		{	
			B3++;
			rem=400;
		}
	}
	
	int j=0;
	while(j<noa) //This loop will assign boxes to Rats, Hedgehog and Mongoose.
	{

		if(a[j]=='R'||a[j]=='H')
		{
			if(rem>=r)
			{
				rem=rem-r; //in case Box3 containing snake have space.
			}
			else
			{
				B1++;
			}
		}
		else if(a[j]=='M')
		{
			B2++;
		}
		j++;
	}
	
	//this loop will check if numbers of Box1 can be changed to Box3 or Box2 to minimize number of boxes.
	while(true)
	{

		if(B2>=1 && B1>=1)
		{
			if(B2==1 && B1==1)
			{
				B3++;
				B2=B2-1;
				B1=B1-1;
				rem=rem+400;
				break;
			}
			else if(B2>=1 && B1>=2)
			{
				B3++;
				B2=B2-1;
				B1=B1-2;
				break;
			}
			
		}
		else if(B1==1)
		{
			if(rem>=400)
			{
				rem=rem-400;
			}	
		}
		else if(B1>=4)
		{
			B3++;
			B1=B1-4;
		}
		else if(B1>=3)
		{
			B3++;
			B1=B1-3;
			rem=rem+400;
		}
		else if(B1>=2)
		{
			B2++;
			B1=B1-2;
		}
		else
		{
			break;
		}
	}
	
	//this loop will check if Box2 and Box1 can be used be changed to Box3 to minimize number of boxes.
	while(true)
	{
		
		if(B2>=2)
		{
			B3++;
			B2=B2-2;
		}
		else
		{
			break;
		}
	}
	
	//printing all boxes that will be used to deliever.
	for(int i=0;i<B1;i++)
	{
		cout<<"B1, ";
	}
	
	for(int i=0;i<B2;i++)
	{
		cout<<"B2, ";
	}
	
	for(int i=0;i<B3;i++)
	{
		cout<<"B3, ";
	}
	
	cout<<endl<<endl;
	
}


int main()
{
	int ch;
	
	char a[1]={'R'};
	char b[1]={'H'};
	char c[1]={'M'};
	char d[1]={'S'};
	char e[3]={'R', 'H', 'H'};
	char f[2]={'S', 'M'};
	char g[4]={'S', 'H', 'R', 'M'};
	char h[3]={'R', 'H', 'S'};
	bool run=true;
	
	//Menu
	while(run)
	{
		cout<<"Welcome to Pets2U."<<endl;
		cout<<"1. Buy Pets."<<endl<<"2. Sample Inputs."<<endl<<"3. Exit."<<endl;
		do
		{
			cout<<"Your Choice: ";
			cin>>ch;
		}while(ch<1 && ch>3);
		
		switch(ch)
		{
			case 1:
				Pets2U();
				break;
			
			case 2:				
				cout<<"Input"<<setw(18)<<"Output"<<endl;
				Pets2U(a,1);
				Pets2U(b,1);
				Pets2U(c,1);
				Pets2U(d,1);
				Pets2U(e,3);
				Pets2U(f,2);
				Pets2U(g,4);
				Pets2U(h,3);
				break;
					
			case 3:
				run=false;
				break;			
		}
		
	}

}

