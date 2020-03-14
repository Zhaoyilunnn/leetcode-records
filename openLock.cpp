//
// Created by zyl on 2020/3/13.
//

#include "function_defs.h"

int Solution::openLock(vector<string> &deadends, string target) {
    int rot_time = 0;
    string begin_num = "0000";
    int isvisit[10000] = {0};
    queue<string>num_path;
    num_path.push(begin_num);
    isvisit[0] = 1;
    //把deadends中的数设置成无法访问
    for(auto & deadend : deadends){
        int index = (deadend[0]-'0')*1000 + (deadend[1]-'0')*100 + (deadend[2]-'0')*10 + (deadend[3]-'0');
        isvisit[index] = 1;
    }
    string num_up;
    string num_down;
    while(!num_path.empty()){
        num_up = num_path.front();
        num_down = num_path.front();
        for(int i=0;i<4;i++){
            if(num_up[i]=='9'){
                num_up[i] = '0';
            }
            else
            {
                num_up[i] += 1;
            }
            if(num_down[i]=='0'){
                num_down[i] = '9';
            }
            else
            {
                num_down[i] -= 1;
            }
            if(num_up == target || num_down == target){
                rot_time++;
                return rot_time;
            }
            //转换成数字,num_up、num_down为字符串
            int num_upint = (num_up[0]-'0')*1000 + (num_up[1]-'0')*100 + (num_up[2]-'0')*10 + (num_up[3]-'0');
            int num_downint = (num_down[0]-'0')*1000 + (num_down[1]-'0')*100 + (num_down[2]-'0')*10 +(num_down[3]-'0');
            if(isvisit[num_upint]==0){
                num_path.push(num_up);
            }
            if(isvisit[num_downint]==0){
                num_path.push(num_down);
            }
            num_path.pop();
        }
        rot_time++;
    }
    return -1;
}
