#include <iostream>

using namespace std;

int* Corollary(int*, int);
int* Permute(int*, int);
int* HeapSort(int*);

struct Node
{
    int ID;
    int LeftChild;
    int RightChild;
};

int main()
{
    // Declare Number of Vertex in graph G
    int num_nodes;
    cout << "Number of Vertex : ";
    cin >> num_nodes;

    // Declare each vertex degree in graph G
    int *degSequence = new int[num_nodes];
    for (int i = 0; i < num_nodes; i++){
        cout << "Vertex " << i + 1 << " degree : ";
        cin >> degSequence[i];
    }

    // Determine whether the degSequence is a graph or not
    bool isGraph = false;
    while(true){
        if (degSequence[0] == 0 && degSequence[num_nodes - 1] == 0) {
            isGraph = true;
            break;
        }
        else if (degSequence[num_nodes - 1] < 0){
            isGraph = false;
            break;
        }
        else{
            // By Corollary 1.1.7
            degSequence = Corollary(degSequence, num_nodes);

            // Permutation
            num_nodes--;
            degSequence = Permute(degSequence, num_nodes);
        }
    }
    cout << "Finish ! " << endl;
    if (isGraph) cout << "This is a Graph";
    else cout << "This is not a Graph";

    return 0;
}

int* Corollary(int* degSequence, int num_nodes)
{
    int* new_degSequence = new int[num_nodes - 1];

    for (int i = 0; i < num_nodes - 1; i++){
        if (i < degSequence[0])
            new_degSequence[i] = degSequence[i + 1] - 1;
        else
            new_degSequence[i] = degSequence[i + 1];
    }
    return new_degSequence;
}

int* Permute(int* degSequence, int num_nodes)
{
    int* new_degSequence = new int[num_nodes];
    int temp;

    // For testing
    //cout << "Before Permute" << endl;
    //for (int i = 0; i < num_nodes ; i++){
    //    cout << degSequence[i] << endl;
    //}

    // Bubble Sort
    for (int i = 0; i < num_nodes; i++){
        for (int j = i + 1; j < num_nodes; j++){
            if (degSequence[i] < degSequence[j]){
                temp = degSequence[i];
                degSequence[i] = degSequence[j];
                degSequence[j] = temp;
            }
        }
        new_degSequence[i] = degSequence[i];
    }

    // For testing
    //cout << "After Permutation" << endl;
    //for (int i = 0; i < num_nodes ; i++){
    //    cout << degSequence[i] << endl;
    //}

    return new_degSequence;
}

int* HeapSort(int* degSequence)
{
    return degSequence;
}
