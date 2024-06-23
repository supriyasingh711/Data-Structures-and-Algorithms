#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    bool flag=false;
    int count=0;
    int cend=0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
        cend++;
    }
    bool isEnd(){
        return flag;
    }

};
class Trie{
    private:Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
                node->count++;
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    int countWordEqualTo(string word){
        Node* node=root;
        for(int i=0;i<word[i];i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
        node=node->get(word[i]);
        }
        return node->cend;

    }
    int countWordsStartingWith(string prefix){
        Node* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return 0;
            }
            node=node->get(prefix[i]);
        }
        return node->count;
    }

};
int main(){
    vector<string> arr={"apple","apps","apxl"};
    Trie t;
    for(int i=0;i<arr.size();i++){
            t.insert(arr[i]);
    }
    cout<<t.countWordEqualTo("apple")<<" ";
    cout<<t.countWordsStartingWith("ap")<<" "<<t.countWordsStartingWith("app");
}
