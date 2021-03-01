#include <iostream>
using namespace std;
class Frog{
    private:
        int curPos = 0;
        int longJumpDist;
        int longJumpTimes = 0;
        int calDistGoBack(int target,int src);
    public:
        Frog(int ljd) ;
        // dirt = 1 <-> 正向，dirt = 0 <-> 反向  
        bool shortJump(int dirt,int distGoBack);
        int longJume();
        // bool goHome(int home);
        bool goHome();
};

// 下标0表示起点，下标1表示终点
int block[26][2];
int numOfBlock=0;
int dest = 1000000001;
int nextBlockS = 0;
int main(){
    int numOfCase,longJumpDist;
    cin >> numOfCase;
    for (size_t i = 0; i < numOfCase; i++)
    {
        cin >> longJumpDist >> numOfBlock;
        Frog frog(longJumpDist);
        for(int j = 0; j < numOfBlock ;j++){
            cin >> block[j][0] >> block[j][0];
        }
    }
    

    return 0;
}

Frog::Frog(int ljd){
    this->longJumpDist = ljd;
}

bool Frog::shortJump(int dirt,int distGoBack){
    if(dirt = 1){
        int distBeforeNextBlockS = ( (block[nextBlockS][0] - curPos) % 2 ) == 0 ? 2 : 1;
        this->curPos = nextBlockS - distBeforeNextBlockS;
    }else{
        // int addedDist = (this->curPos - nextBlockS)%2==0 ? 1: 2;
        // int distGoBack = this->curPos - nextBlockS - addedDist;
        this->curPos -= distGoBack;
        if(nextBlockS > 0 && this->curPos <= block[nextBlockS-1][1]){
            return false;
        }
    }
    return true;
}
int Frog::longJume(){
    int nextStand = this->curPos + this->longJumpDist;
    int distGoBack = 0;
    if(nextStand > dest){
        distGoBack =  this->calDistGoBack(dest,nextStand);
    }
    for(int i = 0 ; i< numOfBlock;i++){
        if (this->curPos <= block[i][1] && this->curPos >= block[i][0]){
            distGoBack = this->calDistGoBack(block[i][0],nextStand);
            break;
        }
    }
    return distGoBack;

}

int Frog::calDistGoBack(int target,int src){
    int added;
    if( (src-target)%2 ==0 ){
        added = 2;
    }else{
        added = 1;
    }
    return target - src - added;
}