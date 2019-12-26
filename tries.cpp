#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	bool isTerminal;
	unordered_map<char, Node*>children;
	Node(char ch){
		this->data = ch;
		this->isTerminal = false;
	}
};

class tries{
public:
	Node *root;
	int count;
	tries(){
		this->root = new Node('\0');
		this->count = 0;
	}	
	void add(string str){
		Node *temp = root;
		//Node temp = new Node();
		
		for(int i = 0; i < (int)str.size(); i++){
			char ch = str[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
			}else{
				Node *new_node = new Node(ch);
				temp->children[ch] = new_node;
				temp = new_node;
			}
		}
		temp->isTerminal = true;
	}
	
	bool search(string str){
		Node *temp = root;
		for(int i = 0; i < (int)str.size(); i++){
			char ch = str[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
			}else{
				return false;
			}
		}
		return temp->isTerminal;
	}	
};

int main(){
	int n_string;
	cin>>n_string;
	
	tries t;
	while(n_string--){
		string str;
		cin>>str;
		//tries t;
		t.add(str);
	}
	int query;
	cin>>query;
	while(query--){
		string str;
		cin>>str;
		//tries t;
		if(t.search(str)){
			cout<<"string is found"<<'\n';
		}else{
			cout<<"string is not found"<<'\n';
		}
	}
	return 0;
}
