#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    bool flag=false;

    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }



};
class Trie{
    private : Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    bool startsWith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};

int main(){
    Trie t;
    t.insert("apple");
    t.insert("apps");
    t.insert("yarn");
    cout<<t.search("apps");
    cout<<t.startsWith("yayyy");
    //o/p:10

}