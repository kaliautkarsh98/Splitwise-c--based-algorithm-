#include<bits/stdc++.h>
#include<set>
using namespace std;
int main()
{
	//splitwise algorithm 
	int no_of_transactions,friends;
	cin>>no_of_transactions>>friends;
	
	int x,y,amount;
	//make an array to store the net amount each person will take at end 
	int net[10000]={0};
	int count =0;
	while(no_of_transactions--)
	{
		cin>>x>>y>>amount;
		net[x]=net[x]-amount;
		net[y]=net[y]+amount;
		
	}
	multiset <int> m;
	//mutliset and not set bcz maybe same amount might be involved in transaction and plus in sorted order 
	// initialize multiset 
	for(int i=0;i<friends;i++)
	{
		if(net[i]!=0)
		{
			m.insert(net[i]);
			
		}
	}
	// take one from left--> debit ones  and one from right --> credited and settle them 
	//until set is empty
	while(!m.empty())
	{
		auto low=m.begin();
		auto high=prev(m.end()); //m.end() point to the pointer next to last also m.end()-1 not allowed
		int debit= *low;
		int credit=*high;
		
		//erase 
		m.erase(low);
		m.erase(high);
		
		//settlement 
		int settlement_amount=min(-debit,credit);
		count++;
		//transfer the amount from debitor to creditor 
		
		debit=debit+settlement_amount;
		credit=credit-settlement_amount;
		// one of them will be zero cz of line 45 
		
		//non zero person in multiset 
		
		if(debit!=0)
		{
			m.insert(debit);
		}
		if(credit!=0)
		{
			m.insert(credit);
		}
		
	}
	cout<<count;
}
