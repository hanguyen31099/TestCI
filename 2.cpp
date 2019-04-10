#include<iostream>
#include<string.h>
#include <stdlib.h>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
struct node{
	int data;
	int vitri;
	struct node *pLeft;
	struct node *pRight; 
};
typedef struct node NODE;
typedef NODE* TREE;

void KhoiTaoCay(TREE &t){
	t = NULL; 
}
void ThemNodeVaoCay(TREE &t, int x,int vt){
	if (t == NULL)
	{
		NODE *p = new NODE;
		p->data = x;
		p->vitri = vt;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else {
		if (x<t->data){
			ThemNodeVaoCay(t->pLeft, x,vt);
		}
		else{
			ThemNodeVaoCay(t->pRight, x,vt);
		}
	}
}
NODE *search(TREE t,int x){
	if(t!=NULL){
		if(t->data==x) return t;
		else if(t->data>x) return search(t->pLeft,x);
		else return search(t->pRight,x);
	}
}

using namespace std;
int main(){
	TREE t;
	KhoiTaoCay(t);
	string str;
	getline(cin,str);
	string s;
	int k,check[10000],check1[10000];
	queue<pii> MyQueue;
	int so = 0;
	memset(check,-1,sizeof(check));
	memset(check1,-1,sizeof(check1));
	for(int i=0;i<str.length();i++){
		if(str[i]!=' '){
			s = s + str[i];
		}
		if(i==(str.length()-1)||str[i]==' '){
			k = atoi(s.c_str());
			so++;
			MyQueue.push(make_pair(k,so));
			ThemNodeVaoCay(t, k,so);
			s = "";
		}
	}
	while(!MyQueue.empty()){
		pii top = MyQueue.front();
		if(256%top.first==0){
			int x = 256/top.first;
				NODE *p = search(t,x);
				if(p!=NULL){
					if(check[top.first]==-1&&check[p->data]==-1){
						cout << top.first << " and "<< p->data<< " in "<< top.second <<" and "<<p->vitri<< endl;
						check[top.first]= 0;
						check[p->data] = 0;
					}
					
				}
			
			
		}
		MyQueue.pop();
	}
}
//techkidsvn@gmail.com
