#include <iostream>
#include <stack>
using namespace std;

class Frog{
    private:
        int curPos = 0;
        int longJumpDist;
        int longJumpTimes = 0;
        int distToStepBack = 0;
        stack<int> v;
    public:
        int shortJump(int nextBlock);
        int longJump(int numOfBlock,int block[][2]);
        int stepBack(int numOfBlock,int block[][2],int &nextBlock);
        int getCurPos();
        int getLongJumpTimes();
        Frog(int longJumpDist);
};

class Trip{
    private:
        int block[26][2];
        int numOfBlock = 0;
        int nextBlock = 0;
        int calNextBlock();
        Frog& frog;
    public:
        int goHome();

        void setBlock(int s, int t,int i);
        void setNumOfBlock(int num);
        Trip(Frog &f);

};

int dest = 1000000001;

int main(){

    int numOfCase,longJumpDist,numOfBlock,s,t,ret;
    cin >> numOfCase;
    for ( int i = 0; i< numOfCase;i++){
        cin >> longJumpDist >> numOfBlock;
        Frog frog = Frog(longJumpDist);
        Trip trip = Trip(frog);
        trip.setNumOfBlock(numOfBlock);

        for(int j = 0 ; j < numOfBlock;j++){
            cin >> s >> t;
            trip.setBlock(s,t,j);
        }
        trip.setBlock(dest+1,INT32_MAX,numOfBlock);
        if((longJumpDist%2)==0){
            ret = -1;
        }else{
            ret = trip.goHome();
        }
        
        cout << ret << endl;
    }
    return 0;
}

int Trip::goHome(){
    // 返回值~Ret为1表示成功，为0表示失败
    int shortJumpRet,longJumpRet,stepBackRet,res;
    while(frog.getCurPos()!=dest){
        shortJumpRet = frog.shortJump(block[nextBlock][0]);
        if(shortJumpRet == 1){
            break;
        }
        longJumpRet = frog.longJump(numOfBlock,block);
        if(longJumpRet == 1){
            nextBlock = calNextBlock();
            continue;
        }
        stepBackRet = frog.stepBack(numOfBlock,block,nextBlock);
        if(stepBackRet == 0){
            res = -1;
            break;
        }
    }
    res = res == -1 ? -1 : frog.getLongJumpTimes();
    return res;
}

int Trip::calNextBlock(){
    for(int i = 0; i< numOfBlock;i++){
        if( block[i][1] < frog.getCurPos() && block[i+1][0] > frog.getCurPos()){
            return i + 1;
        }
    }
}

void Trip::setBlock(int s, int t,int i){
    block[i][0]=s;
    block[i][1]=t;
}

void Trip::setNumOfBlock(int num){
    numOfBlock = num;
}

Trip::Trip(Frog &f):frog(f){

}

int Frog::shortJump(int nextBlock){
    int diff = nextBlock - curPos;
    int added = diff % 2 == 0 ? 2: 1;
    v.push(2);
    v.push((diff-added)/2);
    curPos = nextBlock - added;
    if(curPos == dest){
        return 1;
    }else{
        return 0;
    }
}

int Frog::longJump(int numOfBlock,int block[][2]){
    int nextPos = curPos + longJumpDist;
    for(int i = 0; i< numOfBlock;i++){
        
        if( nextPos <= block[i][1] && nextPos >= block[i][0]){
            distToStepBack = nextPos - block[i][0] + 1;
            if(distToStepBack % 2 != 0)
                distToStepBack+=1;
            return 0;
        }else 
        if(nextPos > block[i][1] && nextPos < block[i+1][0]){
            curPos = nextPos;
            longJumpTimes++;
            v.push(longJumpDist);
            v.push(1);
            return 1;
        }
    }
}

int Frog::stepBack(int numOfBlock,int block[][2],int &nextBlock){
    while(!v.empty()){
        int minusFlag = 0;
        int round = v.top();
        v.pop();
        int nextStepLength = v.top()==2?longJumpDist:2;
        if(nextStepLength != longJumpDist){
            minusFlag = 1;
        }
        int nextPos = curPos;
        for(int i =0; i < round;i++){
            nextPos = nextPos - v.top() + nextStepLength;

        }

    }

    int s , t;
    s = curPos - distToStepBack;
    t = curPos;
    for(int i = 0 ; i < numOfBlock;i++){
        for( int j = 0; j < 2; j++){
            if(block[i][j] <= t && block[i][j] >=s){
                return -1;
            }
        }
    }
    curPos = s + longJumpDist;
    longJumpTimes++;
    int i = 0;
    for( ; i < numOfBlock;i++){
        if(block[i][0]>curPos)
            break;
    }
    nextBlock = i;
    return 1;

}
int Frog::getCurPos(){
    return this->curPos;
}

int Frog::getLongJumpTimes(){
    return longJumpTimes;
}

Frog::Frog(int longJumpDist){
    this->longJumpDist = longJumpDist;
}