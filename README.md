--- Explicación del Algoritmo ---

Este algoritmo busca recolectar y retornar coordenadas de puntos en un vector de vectores
que forman triángulos, estas coordenadas disminuirán en un for siguiendo un patrón simple
hasta llegar a un tamaño muy pequeño. Dichas coordenadas serán puntos que conectados 
en pares dibujarán lineas en la versión gráfica.


--- Conteo de la Función ---

vector<vector<int>> pattern(int width, int height){
    int size = min(height, width);	--> 4
    vector<vector<int>> v;
    int x = 0, y = 0;	--> 2
    --> 1
    for (int i = size; i >= 30; i-=30, x+=10, y+=20){	--> 7	---> 31(n+1)

        vector<int> l1 {x,y,x,y+i};	--> 1
        vector<int> l2 {x,y+i,x+i,y+i};	--> 3
        vector<int> l3 {x,y,x+i,y+i};	--> 2

        vector<int> l4 {y,x,y+i,x};	--> 1
        vector<int> l5 {y+i,x,y+i,x+i};	--> 3
        vector<int> l6 {y,x,y+i,x+i};	--> 2

        v.push_back(l1);	--> 2
        v.push_back(l2);	--> 2
        v.push_back(l3);	--> 2
        v.push_back(l4);	--> 2
        v.push_back(l5);	--> 2
        v.push_back(l6);	--> 2
    }

    return v;	--> 1
}

N = El tamaño de un lado de cada triángulo
f(n) = 31n + 39
O(n)


--- Opcional ---

Para dibujar el algoritmo se hizo un programa en Java, se puede encontrar en la carpeta
"Dibujo". Para correrlo correctamente, se debe copiar la salida del programa original en
C++ y pegar en la función paint donde dice "Pegar Aqui".