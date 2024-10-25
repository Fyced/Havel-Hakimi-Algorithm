/*If it is wanted to make this program to also print the graph, be aware that it doesn't reorder the graphs from bigger to lower when 
Havel-Hakimi has been applied, in order to do that, it should be added(Changing the variable to the one in the method):
<code>sort(graphicSequence.begin(),graphicSequence.end(), greater<int>());</code>   To the HavelHakimiAlgorithm method
 NOTE: It only reorders them once in the main method after the numbers have been transformed into integers*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> numberOfSequence(string input){
    input = input.substr(1,input.length()-2);   //Erases the brackets {}
    input += ", ";          //It adds a comma in order to optimize the code (It doesn't have to distinguish if it is the last number)
    vector<int> numbers;
    while(input.length() > 1){  //While the string has values do this:
        string number = input.substr(0,input.find(","));    //Stores the first number possible of the string
        input = input.substr(input.find(",")+1);            //Erases the first number because it has been already stored 
        numbers.push_back(stoi(number));                    //Add the number to the vector that is going to be returned
    }
    return numbers; //Return the vector that has all the numbers provided by the user
}

//This method checks if the degree of the sum of vertices is even and if a vertex has a degree bigger than the number of vertices
bool eulerianGraph(vector<int> vec){
    if(vec[0] >= vec.size()){return false;} //As this vector is already ordered from bigger to lower, it only has to check the first one
    int degree = 0;
    for(int i = 0; i <= vec.size()-1; i++){ //Sums all the degrees of the vertices
        degree += vec[i];
        if(vec[i] < 0){return false;}   //Checks if there is a vertex that has a negative degree 
    }
    if(degree % 2 == 0 && degree > 0){return true;} else {return false;}    //It checks if the sum of degrees is even
}

//Applies Havel-Hakimi to the sequence
bool HavelHakimiAlgorithm(vector<int> graphicalSequence){
    while(graphicalSequence[0] > 0){
        if(eulerianGraph(graphicalSequence)){   //It checks if it's still a graph when Havel-Hakimi has been applied
        int temp = graphicalSequence[0];
        graphicalSequence.erase(graphicalSequence.begin()); //Erases the first vertex
        for(int i = 0; i < temp; i++){
            graphicalSequence[i] -= 1;  //It removes 1 from every vertex connected to the previous one
        }
    } else {return false;}
    }
    return true;
}

int main(){
    string inputGraphicSequence;    //Creation of a string that is going to store the input by the user
    cout << "Write the graphic sequence (Format: (x,x,x...))\n";    //Ask the user for the graphic sequence pending to evaluation
    cin >> inputGraphicSequence;

//Creates a vector which contains the graphical sequence from bigger to lower and now they are integers
    vector <int> graphicSequence = numberOfSequence(inputGraphicSequence);
    sort(graphicSequence.begin(),graphicSequence.end(), greater<int>());

//It checks if the sequence is a graphic sequence of a graph using Havel-Hakimi
    if(HavelHakimiAlgorithm(graphicSequence)){cout << "It's a graphic sequence from a graph";}
    else {cout << "It's not a graphic sequence from a graph";}

}