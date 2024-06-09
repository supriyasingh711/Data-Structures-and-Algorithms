#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string findRoot(string& word,unordered_set<string>& st){
        //try all length substring starting from oth index
        for(int l=1;l<=word.length();l++){
            string root=word.substr(0,l);
            if(st.count(root)){
                return root;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary,string sentence){
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        stringstream ss(sentence);
        string word,result;
        while(getline(ss,word,' ')){
            result+=findRoot(word,st)+" ";
        }
        result.pop_back();
        return result;
    }
   
};
 int main(){
        vector<string> dictionary={"cat","bat","rat"};
        string sentence="The cattle was rattled by the battery";
        Solution obj;
        cout<<obj.replaceWords(dictionary,sentence);
        return 0;
    }