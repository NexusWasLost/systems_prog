#include  <bits/stdc++.h>
using namespace std ;
class trie {
	public:
	bool end=false;
	trie * links[26];
	trie(){
		for(int i=0;i<=25;i++){
			links[i]=nullptr;
		}
	}
};
void insert(int i , string &s, trie*&root){
	if(i==s.size()){
		root->end=true;
		return;
	}
	if(root->links[s[i]-'a']==nullptr){
		root->links[s[i]-'a']=new trie;
	}
	insert(i+1,s,root->links[s[i]-'a']);
	
}
bool search(int i, string &s , trie*&root){
	if(i==s.size())return root->end;
	if(root->links[s[i]-'a']==nullptr)return false;
	return search(i+1,s,root->links[s[i]-'a']);
	
}
bool startsWith(int i, string &s, trie *& root){
	if(i==s.size())return true;
	if(root->links[s[i]-'a']==nullptr)return false;
	return startsWith(i+1,s,root->links[s[i]-'a']);
}


int32_t main(){
	trie*root=new trie;
	while(true){
	
		cout<<"Enter a string : "<<endl;
		string s;
			cin>>s;
		cout<<"Enter an option : "<<endl;
			int a;
		cin>>a;
	
		if(a==1){
			
			insert(0,s,root);
		}else if(a==2){
			cout<<search(0,s,root)<<endl;
		}else if(a==3){
			cout<<startsWith(0,s,root)<<endl;
		}else{
			break;
		}
	}	
	
}
