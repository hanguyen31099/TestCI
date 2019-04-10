#include<iostream>
#include<string.h>
#include<stack>
#include <stdlib.h>
using namespace std;
int main(){
	string str;
	getline(cin,str);
	string s;
	stack<int> MyStack;
	int k;
	for(int i=0;i<str.length();i++){
		if(str[i]!=' '){
			s = s + str[i];
		}
		if(i==(str.length()-1)||str[i]==' '){
			k = atoi(s.c_str());
			MyStack.push(k);
			s= "";
		}
	}
	while(!MyStack.empty()){
		cout << MyStack.top() <<" ";
		MyStack.pop();
	}

}
