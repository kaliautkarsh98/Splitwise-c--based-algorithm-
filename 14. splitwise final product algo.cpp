#include<bits/stdc++.h>
#include<set>
#include<map>
using namespace std;

class person_compare {
public:
	bool operator()(pair<string,int> p1, pair<string,int> p2){
		return p1.second<p2.second;
	}
};
int main()
{
	//splitwise algorithm 
	int no_of_transactions,friends;
	cin>>no_of_transactions>>friends;
	
	map<string,int> net; //hashmap 
	string x,y;
	int amount;
	multiset <pair<string,int>, person_compare> m;
	while(no_of_transactions--)
	{
		cin>>x>>y>>amount;
		//zero initialization
		if(net.count(x)==0)
		{
			net[x]=0;
		}
		if(net.count(y)==0)
		{
			net[y]=0;
		}
		net[x]=net[x]-amount;
		net[y]=net[y]+amount;
		
	}
	//iterate over the persons and add them in the multiset who have non zero net 
	for(auto p:net)
	{
		string person=p.first;
		int amount =p.second;
		
		if(net[person]!=0)
		{
			m.insert(make_pair(person,amount)); //comparison will be held by first parameter by default so need to change 
		}
	}
	//make settlement 
	int count=0;
	while(!m.empty())
	{
		auto low=m.begin();
		auto high = prev(m.end());
		
		int debit = low->second;
		string debit_person =low->first;
		
		int credit=high->second;
		string credit_person = high->first;
		
		//pop them out 
		m.erase(low);
		m.erase(high);
		
		//settle 
		int settled_amount =min(-debit,credit);
		
		debit=debit+settled_amount;
		credit=credit-settled_amount;
		
		cout<<debit_person<<"will pay"<<settled_amount<<"to "<<credit_person<<endl;
		if(debit!=0)
		{
			m.insert(make_pair(debit_person,debit));
		}
		if(credit!=0)
		{
			m.insert(make_pair(credit_person,credit));
		}
		count++;
	}
	cout<<count;
}
