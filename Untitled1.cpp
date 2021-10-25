#include <bits/stdc++.h>
using namespace std;
char product_name[30];
char product_id [10];
char product_amount [10];
char product_price [10];
char arrival_date [10];
char supplier_name[30];
fstream h;

void insert (){
 h.open("inventory.txt",ios::app);
 cout<<"Enter Medicine_name\n";
 //cin.ignore();
 //cin.getline(product_name,31);]
 cin>>product_name;
cout<<"Enter Medicine_id\n";
cin>>product_id;
cout<<"Enter Medicine_amount\n";
cin>>product_amount;
cout<<"Enter Medicine_price\n";
cin>>product_price;
cout<<"Enter arrival_date\n";
cin>>arrival_date;
cout<<"Enter supplier_name\n";
cin>>supplier_name;
h<<product_name<<"|"<<product_id<<"|"<<product_amount<<"|"<<product_price<<"|"<<arrival_date<<"|"<<supplier_name<<"\n";
h.close();

}
//------------------------------------------------------------------------------------------------
void show(){
	h.open("inventory.txt",ios::in|ios::out|ios::app);
	while(!h.eof()){

		h.getline(product_name,31,'|');
		cout<<product_name<<"\t" ;
		h.getline(product_id,11,'|');
		cout<<product_id<<"\t" ;
        h.getline(product_amount,11,'|');
        cout<<product_amount<<"\t" ;
        h.getline( product_price,11,'|');
        cout<<product_price<<"\t" ;
        h.getline(arrival_date,11,'|');
        cout<<arrival_date<<"\t" ;
        h.getline(supplier_name,31,'\n');
        cout<<supplier_name<<"\n" ;
	}
	h.close();
	cout<<"THE FILE END \n";
}
//..................................................................................
void search (){
	char search_key [10];
	cout<<"enter the Medicine id  that you need to search :\n ";
	cin>>search_key ;
	h.open("inventory.txt",ios::in|ios::out|ios::app);
	int tester=0;
		while(!h.eof())
		{
		h.getline(product_name,31,'|');
		h.getline(product_id,11,'|');
        h.getline(product_amount,11,'|');
        h.getline( product_price,11,'|');
        h.getline(arrival_date,11,'|');
        h.getline(supplier_name,31,'\n');
	    if(strcmp(search_key,product_id)==0)
        {
        	tester=1;
        cout<<"product found:\n"<<product_name<<"|"<<product_id<<"|"<<product_amount<<"|"<<product_price<<"|"<<arrival_date<<"|"<<supplier_name<<"\n";
	}
		}
	if (tester==0)
	{
		cout<<"product not found";
	}
	h.close();
}

void deletel(){
	fstream f;
	f.open("inventory2.txt",ios::in|ios::out|ios::app);
		h.open("inventory.txt",ios::in|ios::out|ios::app);
		char search_key [10];
	cout<<"enter the Medicine id  that you need to delete :\n ";
	cin>>search_key ;
	int tester=0;
		while(!h.eof()){

		h.getline(product_name,31,'|');
		h.getline(product_id,11,'|');
        h.getline(product_amount,11,'|');
        h.getline( product_price,11,'|');
        h.getline(arrival_date,11,'|');
        h.getline(supplier_name,31,'\n');
	    if(strcmp(search_key,product_id)==0)
        {
        	cout<<"Medicine_deleted"<<endl;
        	tester=1;
		}
		else{
			f<<product_name<<"|"<<product_id<<"|"<<product_amount<<"|"<<product_price<<"|"<<arrival_date<<"|"<<supplier_name<<"\n";
		}
	}
	if(tester==0){
		cout<<"Medicine not found\n";
	}
	f.close();
	h.close();
	     remove("inventory.txt");
        rename("inventory2.txt","inventory.txt");

}
//.......................................................................................................................................
void  update(){
		fstream f;
	f.open("inventory2.txt",ios::in|ios::out|ios::app);
		h.open("inventory.txt",ios::in|ios::out|ios::app);
		char search_key [10];
	cout<<"enter the Medicine id  that you need to update :\n ";
	cin>>search_key ;
	int tester=0;
		while(!h.eof()){

		h.getline(product_name,31,'|');
		h.getline(product_id,11,'|');
        h.getline(product_amount,11,'|');
        h.getline( product_price,11,'|');
        h.getline(arrival_date,11,'|');
        h.getline(supplier_name,31,'\n');
	    if(strcmp(search_key,product_id)==0)
        {
					tester=1;
					cout<<"Enter Medicine_name\n";
					cin>>product_name;
			        cout<<"Enter Medicine_id\n";
					cin>>product_id;
					cout<<"Enter Medicine_amount\n";
					cin>>product_amount;
					cout<<"Enter Medicine_price\n";
					cin>>product_price;
					cout<<"Enter arrival_date\n";
					cin>>arrival_date;
					cout<<"Enter supplier_name\n";
					cin>>supplier_name;
			    	f<<product_name<<"|"<<product_id<<"|"<<product_amount<<"|"<<product_price<<"|"<<arrival_date<<"|"<<supplier_name<<"\n";
		}
		else{
			f<<product_name<<"|"<<product_id<<"|"<<product_amount<<"|"<<product_price<<"|"<<arrival_date<<"|"<<supplier_name<<"\n";
		}
	}
	if(tester==0){
		cout<<"Medicine not found\n";
	}
	else{
		cout<<"Medicine updated \n";
	}
	f.close();
	h.close();
	     remove("inventory.txt");
        rename("inventory2.txt","inventory.txt");
}

int main(){
   int x;
   char m;
   do{
      cout<<"to insert new Medicine press 1\n to view all Medicines press 2 \n to search for a Medicine press 3 \n to delete Medicine press 4 \n to update Medicine press 5 \n ";
	  cin>> x;
	  switch(x){
	  	case 1:
	  		insert();
	  	    break;
		case 2:
		     show();
			 break;
	    case 3:
	    	search();
	    	break;
		case 4:
			deletel();
			break;
		case 5:
			update();
			break;
		default :
			cout<<"Error! \n";
	  }
	  cout<<"to continue press M or m\n ";
	  cin>>m;
   }while(m=='m'||m=='M');
   cout<<"process ended :D";
}
