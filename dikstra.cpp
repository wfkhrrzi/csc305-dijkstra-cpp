#include <bits/stdc++.h>

using namespace std ;

int adjacencyMatrix[100][100] , numOfVertices  ;  //declaration of graph array and number of vertices set
char huruf[9] = {'A', 'B' , 'C', 'D' , 'E', 'F'};

int getNearestNode(int dist[] , bool visited[]){
    int key = 0 ; 
    int min = INT_MAX ; 
    for(int i=0;i <numOfVertices ; i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i] ; 
            key = i ; 
        }
    }
    return key ; 
}

void display(int dist[] , int displayNode[] ){
    for(int i =0 ;i < numOfVertices;i++){
       // stupid structured matrix gaming
		cout<<"        ";
       int temp = displayNode[i]; 
       cout<< i << "<-";
       while(temp!=-1)
       {
           cout<< temp << " <- " ;
           temp = displayNode[temp] ; 
           
       }
       
       cout<<endl; 
       cout<<"||||>    Distance = " << dist[i] ;
	   cout<<"   <||||" ;
       cout<<endl; 
   } 
   cout<<"\n\nNode reference : \n";
   for(int x = 0 ; x < numOfVertices; x++){
   	cout<< x << " => " << huruf[x] <<endl ;
   }
}


void dijkstra(int startVertex ){
    int displayNode[100] , dist[100] ; 
    bool visited[100] ={0} ; 
    fill(dist , dist+numOfVertices  , INT_MAX ) ; 

    dist[startVertex] =0 ; 
    displayNode[startVertex] =-1 ;
    
    for(int g = 0  ;g<numOfVertices-1 ; g++){
        int NeighbourNode = getNearestNode( dist ,  visited )  ; 
        visited[NeighbourNode] = true ;
        cout<< " min = " << NeighbourNode <<endl; 
        for(int col =0 ; col< numOfVertices ;col++){
            if(!visited[col] && (dist[NeighbourNode]+adjacencyMatrix[NeighbourNode][col]) <  dist[col] && adjacencyMatrix[NeighbourNode][col]!=9999)
            {
                displayNode[col] = NeighbourNode ; 
                dist[col] = dist[NeighbourNode] + adjacencyMatrix[NeighbourNode][col] ; 
            }
        }
    }
    
    display(dist , displayNode); 
}



int main(void) { 
    cout<<"Enter number of Vertices in the graph : " ; 
    cin>>numOfVertices ; 
    cout<<"Enter Adjacency matrix : \n" ; 
    for(int i = 0 ;i < numOfVertices ; i++){
        for(int j = 0 ; j< numOfVertices ; j++) {
            cin>>adjacencyMatrix[i][j] ;
        } 
    }
    int startVertex ; 
    cout<<"\nEnter source : " ;  cin>>startVertex ;
    dijkstra(startVertex) ; 
}