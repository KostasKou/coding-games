#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int parent;
    int current;
    bool explored = false;
    
    bool gateway = false;
};
int main()
{
    vector<vector<int>> neighbors;
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    vector<pair<node,node>> links;
    vector<node> nodes;
    vector<int> fringe;
    
    int current;
    cin >> n >> l >> e; cin.ignore();
    for(int i =0; i<n; i++){
        neighbors.push_back({});
    }
    
    node node;
    for(int i = 0 ; i<n; i++){
        node.current = i;
        nodes.push_back(node);
    }
    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();
        links.push_back(make_pair(nodes[n1],nodes[n2]));

    }
    
    
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        nodes[ei].gateway = true;
    }
   
    vector<int>::iterator it;
    //making a vector with the neighbors of each node 
    for(int i=0; i<n; i++){
        
        for(auto iter:links)
        {
            if(iter.first.current==i){
                it = find (neighbors[i].begin(), neighbors[i].end(), iter.second.current);
                if(it ==neighbors[i].end()){
                    neighbors[i].push_back(iter.second.current);
                }
            }
            else if(iter.second.current == i){
                it = find (neighbors[i].begin(), neighbors[i].end(), iter.first.current);
                if(it ==neighbors[i].end()){
                    neighbors[i].push_back(iter.first.current);
                }
            }
        }   
    }
    // int ap=0;
    // game loop
    int k=0;
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();
        k=0;//variable to track "front" of the fringe , a queue would be better for this job, in order not to mess with extra variables for tracking.
        
        while(1){
            nodes[si].explored = true;
            
            fringe.push_back(si);
            //goal check
            if(nodes[si].gateway){
                
                break;
            }
            //node's neighbors expansion if not explored
            for(int i=0 ; i < neighbors[si].size(); i++){
                
                if(!nodes[neighbors[si][i]].explored){
                    nodes[neighbors[si][i]].explored = true;
                    nodes[neighbors[si][i]].parent = nodes[si].current;
                    fringe.push_back(nodes[neighbors[si][i]].current);
                }
            }
            k++;
            si=fringe[k];
           
        }
        cout << nodes[si].current <<" "<<nodes[si].parent << endl;
        // delete of the link between gateway and parent
        for(int i =0; i<neighbors[nodes[si].current].size(); i++){
            if(neighbors[nodes[si].current][i]==nodes[si].parent){
               
                neighbors[nodes[si].current].erase(neighbors[nodes[si].current].begin()+i);
                
            }
        }
        // delete of the link between parent and gateway
        for(int i =0; i<neighbors[nodes[si].parent].size(); i++){
            if(neighbors[nodes[si].parent][i]==nodes[si].current){
                
                neighbors[nodes[si].parent].erase(neighbors[nodes[si].parent].begin()+i);
                
            }
        }
        fringe.clear();//clear the fringe for next round
        
        //marking all nodes NOT explored to start nexr round
        for(int i=0; i<nodes.size(); i++){
            if( nodes[i].explored)
            nodes[i].explored=false;
        }
    }
}
