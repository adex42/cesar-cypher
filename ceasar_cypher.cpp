#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
string encrypt(string s, int key )
{
	string res="";
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
		{
			s[i]+=key;
			if (int(s[i])> 90)
			{
				s[i]=s[i]-26;
			}
			res+=s[i];

		}
		if (islower(s[i]))
		{
			s[i]+=key;
			if (int (s[i])> 122)
			{
				s[i]=s[i]-26;
			}
			res+=s[i];
		}
	}
	return res;
}
string decrypt(string s, int key)
{
	string res="";
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i]))
		{
			s[i]-=key;
			if (int(s[i])<65)
			{
				s[i]=s[i]+26;
			}
			res+=s[i];

		}
		else if (islower(s[i]))
		{
			s[i]-=key;
			if (int (s[i])<97)
			{
				s[i]=s[i]+26;
			}
			res+=s[i];
		}
		else
		{
			res+=s[i];
		}
	}
	return res;
}
void bruteforce(string s)
{

for (int key = 1; key <= 26; ++key)
{


	cout<<key<<" "<<decrypt(s,key)<<endl;
}
}
int main()
{

		char text[100];
		gets(text);
		int key;
		cin>>key;
		int choice;
		cout<<"Enter your choice:\n"<<"1.Encrypt\n"<<"2.Decrypt\n"<<"3.Brute Force\n";
		cin>>choice;
		switch(choice)
	{
		case(1):
			{
				cout<<"Encrypted Text:"<<encrypt(text,key)<<endl;
				break;
			}
		case(2):
			{
				cout<<"Decrypted Text:"<<decrypt(text,key)<<endl;
				break;
			}
		case(3):
		{	cout<<"Possible Solutions:"<<endl;
			bruteforce(text);
			break;
		}
	}

	return 0;
}
