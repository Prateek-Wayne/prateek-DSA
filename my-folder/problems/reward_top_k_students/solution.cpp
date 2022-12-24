class Solution {
public:
     struct cmp{//custom comparator for set
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2) const{
        if(p1.second!=p2.second){
            return (p1.second > p2.second);
        }
   
            return p1.first<p2.first;
        
    }  
};
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        set<string> pos(positive_feedback.begin() , positive_feedback.end());
        set<string> neg(negative_feedback.begin() , negative_feedback.end());
        set<pair<int , int> , cmp> val;
        map<int , int> mp;
        for(int i = 0 ; i<report.size() ; i++){
           stringstream s(report[i]);
            
            string word;

int sc = 0;
    while (s >> word){
        if(neg.find(word) != neg.end()){
            sc -= 1;
        }
        
        else if(pos.find(word) != pos.end()){
            sc += 3;
        }
    }
            
            mp[student_id[i]] = sc;
      
        }
        vector<int> ans;
        for(auto it: mp){
            val.insert({it.first , it.second});
        }
        
        for(auto it: val){
            k--;
          ans.push_back(it.first);
            if(k == 0) {
                break;
            }
        }
        
        
  return ans;
    }
};