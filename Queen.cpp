#include <iostream>
#include <cstdlib>
#include <vector>
std::vector<int> queen(8,0);
bool isSafe(int pos, int queen_number){
    for(int i=0; i<queen_number; i++){
        if((pos==queen[i])||(pos==(queen[i]+queen_number-i)||(pos==(queen[i])-queen_number+i)))	return false;
    }
    return true;
}
void solve(int k){
    if(k==8){
        for(int i=0; i<8; i++)	std::cout<<queen[i]<<' ';
        std::cout<<'\n'; 
    }
    else{
        for(int i=0; i<8; i++){
            if(isSafe(i,k)){
                queen[k] = i;
                solve(k+1);
            }
        }
    }
}
int main (){
  solve(0);
  return 0;
}
