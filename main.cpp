#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pattern(int width, int height){ //500, 700
    int size = min(height, width);	//smaller side	--> 4

    vector<vector<int>> v; //[[x1,y1,x2,y2],[x1,y1,x2,y2]]

    int x = 100, y = 100;	// --> 2
	// --> 1
    for (int i = size; i >= 30; i-=30, x+=10, y+=20){	// --> 7	---> 31(n+1)
        //Left triangles
        vector<int> l1 {x,y,x,y+i};     //p1->p2	--> 1
        vector<int> l2 {x,y+i,x+i,y+i}; //p2->p3	--> 3
        vector<int> l3 {x,y,x+i,y+i};   //p1->p3	--> 2

        //Right triangles
        vector<int> l4 {y,x,y+i,x};     //p4->p5	--> 1
        vector<int> l5 {y+i,x,y+i,x+i}; //p5->p6	--> 3
        vector<int> l6 {y,x,y+i,x+i};   //p4->p6	--> 2

        //Adding the lines to the vector
        v.push_back(l1);	// --> 2
        v.push_back(l2);	// --> 2
        v.push_back(l3);	// --> 2
        v.push_back(l4);	// --> 2
        v.push_back(l5);	// --> 2
        v.push_back(l6);	// --> 2
    }

    return v;	// --> 1
}

/*

N = El tamaño de un lado de cada triángulo
f(n) = 31n + 39
O(n)

*/


void printLines(vector<vector<int>> v){ //Extra, it isn't part of the pattern
    int j = 0;
    float size = 5.0;

	
    for (auto line: v){
    	if (j == 0){
    		cout << "g2.setStroke(new BasicStroke((float) " << size << "));" << endl; // Changes pen size
    		size -= 0.2;
    		j = 6;
		}
        cout << "g.drawLine(" << line.at(0) << ", " << line.at(1) << ", " << line.at(2) << ", " << line.at(3) << ");"<< endl; //x1,y1,x2,y2
        j--;
    }
}


int main(){
	// Test 1, width = 500 and height = 700
    printLines(pattern(500,700));
    
    // Test 2, width = 1000 and height = 300
    //printLines(pattern(1000,300));
    
    return 0;
}
