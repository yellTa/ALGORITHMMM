#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool mapCmp(pair<string, int> &a, pair<string,int> &b){
    return a.second > b.second;
}

bool playCmp(pair<int,int> &a, pair<int,int> &b){
    if(a.first == b.first){
        return a.second < b.second; 
    }
    return a.first>b.first;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> answer;
    
    //1. plays count;
    unordered_map<string,int> tempMap;
    
    for(int i=0; i< genres.size(); i++){
        tempMap[genres[i]] += plays[i];
    }
    
    vector<pair<string,int>> map (tempMap.begin(), tempMap.end());
    //bigger plays first 
    sort(map.begin(), map.end(), mapCmp);
    
    //2. plays of genres
    for(auto i : map){
        string genre = i.first;
        //plays, idx
        vector<pair<int,int>> playMap;
        
        cout << genre << "\n";
        for(int j=0; j<genres.size(); j++){
            if(genres[j]==genre){
                playMap.push_back({plays[j],j});
            }
        }
        //sorting
        sort(playMap.begin(), playMap.end(), playCmp);
        
        //3. 많이 등록한거 두 개씩만 넣기 두 개 안되면 한 개만
        if(playMap.size()<2){
            answer.push_back(playMap[0].second);
        }else{
            for(int j=0; j<2; j++){
                answer.push_back(playMap[j].second);
            }
        }
        
    }
    
    
    return answer;
}