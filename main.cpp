#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pattern(int width, int height){ //500, 700
    int size = min(height, width); //smaller side

    vector<vector<int>> v; //[[x1,y1,x2,y2],[x1,y1,x2,y2]]

    int x = 0, y = 0;

    for (int i = size; i >= 30; i-=30, x+=10, y+=20){
        //Left triangles
        vector<int> l1 {x,y,x,y+i};     //p1->p2
        vector<int> l2 {x,y+i,x+i,y+i}; //p2->p3
        vector<int> l3 {x,y,x+i,y+i};   //p1->p3

        //Right triangles
        vector<int> l4 {y,x,y+i,x};     //p4->p5
        vector<int> l5 {y+i,x,y+i,x+i}; //p5->p6
        vector<int> l6 {y,x,y+i,x+i};   //p4->p6

        //Adding the lines to the vector
        v.push_back(l1);
        v.push_back(l2);
        v.push_back(l3);
        v.push_back(l4);
        v.push_back(l5);
        v.push_back(l6);
    }

    return v;
}

void printLines(vector<vector<int>> v){ //Extra, it isn't part of the pattern
    int i = 1;

    for (auto line: v){
        cout << "new Line (" << line.at(0) << ", " << line.at(2) << ", " << line.at(1) << ", " << line.at(3) << ", 'black');"<< endl; //x1,x2,y1,y2,'color'
    }
}

int main(){
    printLines(pattern(500,700));
    return 0;
}