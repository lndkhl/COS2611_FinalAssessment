/* ************************************************************************* */
/* ****************** Name: Lindokuhle Nsikelelo Nkambule ****************** */
/* *********************** Student Number: 21970858 ************************ */
/* ************************************************************************* */

// required for printing and formatting output to the terminal
#include <iostream>
#include <iomanip>
// required for data structures
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
// required for the algorithm to efficiently change the case of a string
#include <algorithm> // required for std::transform
#include <cctype>    // required for std::tolower
// required for getting information about the limits of fundamental data types
#include <limits> // required for clearing input buffer
#include <climits> // required for Djikstra's algorithm

using namespace std;

// output formatting values defined here
struct OutputWidth {
    const int COLUMN = 15;
    const int TOTAL = 105;
};

const OutputWidth outputWidth;
// these functions handle program output to the terminal
void mainMenu();
void displayMainMenu();
void viewAllMenu();
void displayViewAllMenu();
// these functions process user requests
void addRouteWizard();
void removeRouteWizard();
void findShortestRoute();
bool confirmOption(string description);
// these functions format output
void printCenteredTitle(string title);
void printHorizontalBreak();
string to_uppercase(const string& str);
// this class represents the graph (transport network)
class SmartCityRouteManagement {
    private:
        // this structure represents a location (vertex)
        struct Location {
            string name;
            int index;
            //
            Location(string n, int i) : name(n), index(i) {}
        };
        
        // this struct represents an adjacency list node
        struct Neighbor {
            int locationIndex;
            int distance;
            
            Neighbor(int idx, int dist) : locationIndex(idx), distance(dist) {}
        };
        
        vector<Location> locations;         // list of all locations
        map<string, int> locationToIndex;   // mapping location name to index
        vector<vector<Neighbor>> adjList;   // adjacency list representation
        vector<vector<int>> adjMatrix;      // adjacency matrix representation
        
    public:
        // default constructor
        SmartCityRouteManagement() {}
        // this function adds a location to the network
        void addLocation(const string& locationName);
        // this function adds a route between two locations
        void addRoute(const string& location1, const string& location2, 
                        int distance);
        // this function removes the route between two locations
        void removeRoute(const string& location1, const string& location2);
        // this function displays the adjacency matrix
        void displayAdjacencyMatrix();
        // this function displays the adjacency list
        void displayAdjacencyList();
        // BFS traversal to show reachable locations from a starting location
        void bfsTraversal(const string& startLocation);
        // Dijkstra's algorithm to find shortest path between two locations
        void dijkstraShortestPath(const string& startLocation,\
                                     const string& endLocation);
        //
        void resizeListAndMatrix();
};
// create the transport network
SmartCityRouteManagement network;

/* ********************************* Main ********************************* */
int main() {
    // launches the main menu
    mainMenu();
       
    return 0;
}
/* ************************************************************************ */

/* ******************** Start of Input/Output Functions ******************* */
// parses the user's input for the main menu
void mainMenu() {
    int choice;

     do {
        displayMainMenu();

        if(!(cin >> choice))
        {
            // clears any remaining input and errors
            cin.clear();
            /* numeric_limits<streamsize>::max() sets the maximum number of
             * characters to ignore. Since this is the upper limit on the size
             * of a stream, this effectively tells cin to ignore any and all 
             * input remaining in the buffer. */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
        switch(choice) {
            case 1: addRouteWizard(); break;
            case 2: removeRouteWizard(); break;
            case 3: viewAllMenu(); break;
            case 4: findShortestRoute(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);
}
// displays the main menu
void displayMainMenu() {
    string title = "MAIN MENU";

    printHorizontalBreak();
    printCenteredTitle(title);
    printHorizontalBreak();
    cout << "1. Add a route\n";
    cout << "2. Remove a route\n";
    cout << "3. View all\n";
    cout << "4. Find shortest path\n";
    cout << "\n0. Exit\n";
    printHorizontalBreak();
    cout << "Enter your choice (0-4): ";
}
// parses the user's input for the "View All" routes menu
void viewAllMenu() {
    int choice;

     do {
        displayViewAllMenu();

        if(!(cin >> choice))
        {
            // clears any remaining input and errors
            cin.clear();
            /* numeric_limits<streamsize>::max() sets the maximum number of
             * characters to ignore. Since this is the upper limit on the size
             * of a stream, this effectively tells cin to ignore any and all 
             * input remaining in the buffer. */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
        switch(choice) {
            case 1: network.displayAdjacencyMatrix(); return;
            case 2: network.displayAdjacencyList(); return;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);
}
// display the "View All" routes menu
void displayViewAllMenu() {
    string title = "VIEW ALL";

    printHorizontalBreak();
    printCenteredTitle(title);
    printHorizontalBreak();
    cout << "1. Adjacency Matrix\n";
    cout << "2. Adjacency List\n";
    cout << "\n0. Return To Main Menu\n";
    printHorizontalBreak();
    cout << "Enter your choice (0-2): ";
}
/* ********************* End of Input/Output Functions ********************* */

/* *************** Start of User-request Processing Functions ************** */
// walks the user through adding a route between two locations
void addRouteWizard() {
    string origin, destination;
    int distance;

    printHorizontalBreak();
    printCenteredTitle("ADD A ROUTE");
    printHorizontalBreak();
    // prompts the user to enter the details of the magazine to be added
    cout << "Enter the start location (origin):\n";
    // clears any remaining input and errors
    cin.clear();
    /* numeric_limits<streamsize>::max() sets the maximum number of
     * characters to ignore. Since this is the upper limit on the size
     * of a stream, this effectively tells cin to ignore any and all input
     * remaining in the buffer. */
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, origin);
    cout << "Enter the end location (destination):\n";
    getline(cin, destination);
    // validate input, ensure origin and destination are not the same
    if (to_uppercase(origin) == to_uppercase(destination)) {
        cout << "\nError: Origin and destination cannot be the same\n";
        return ;
    }

    cout << "Enter the distance (in km) between the the two locations:\n";

    if(!(cin >> distance))
    {
        // clears any remaining input and errors
        cin.clear();
        /* numeric_limits<streamsize>::max() sets the maximum number of
            * characters to ignore. Since this is the upper limit on the size
            * of a stream, this effectively tells cin to ignore any and all input
            * remaining in the buffer. */
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // validate input, ensure distance is positive
    if (distance < 1) {
        cout << "\nError: Invalid input\n";
        return ;
    }
    // add the locations and the route to the network
    network.addLocation(to_uppercase(origin));
    network.addLocation(to_uppercase(destination));
    network.resizeListAndMatrix();
    network.addRoute(to_uppercase(origin), to_uppercase(destination), distance);
}
// walks the user through removing a route between two locations
void removeRouteWizard() {
    string origin, destination;

    printHorizontalBreak();
    printCenteredTitle("REMOVE A ROUTE");
    printHorizontalBreak();
    // prompts the user to enter the details of the magazine to be added
    cout << "Enter the start location (origin):\n";
    // clears any remaining input and errors
    cin.clear();
    /* numeric_limits<streamsize>::max() sets the maximum number of
     * characters to ignore. Since this is the upper limit on the size
     * of a stream, this effectively tells cin to ignore any and all input
     * remaining in the buffer. */
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, origin);
    cout << "Enter the end location (destination):\n";
    getline(cin, destination);
    // validate input, ensure origin and destination are not the same
    if (to_uppercase(origin) == to_uppercase(destination)) {
        cout << "\nError: Origin and destination cannot be the same\n";
        return ;
    }
    // remove the route between the two locations
    network.removeRoute(to_uppercase(origin), to_uppercase(destination));
    network.resizeListAndMatrix();
}
// finds the shortest route between two locations
void findShortestRoute() {
    string origin, destination;

    printHorizontalBreak();
    printCenteredTitle("FIND SHORTEST ROUTE");
    printHorizontalBreak();
    // prompts the user to enter the details of the magazine to be added
    cout << "Enter the start location (origin):\n";
    // clears any remaining input and errors
    cin.clear();
    /* numeric_limits<streamsize>::max() sets the maximum number of
     * characters to ignore. Since this is the upper limit on the size
     * of a stream, this effectively tells cin to ignore any and all input
     * remaining in the buffer. */
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, origin);
    cout << "Enter the end location (destination):\n";
    getline(cin, destination);
    // validate input, ensure origin and destination are not the same
    if (to_uppercase(origin) == to_uppercase(destination)) {
        cout << "\nError: Origin and destination cannot be the same\n";
        return ;
    }
    
    network.dijkstraShortestPath(to_uppercase(origin), 
        to_uppercase(destination));
}
// prompts the user to confirm a choice
bool confirmOption(string description) {
    char choice;

    do {
        cout << endl;
        cout << description << endl;
        if(!(cin >> choice))
        {
            // clears any remaining input and errors
            cin.clear();
            /* numeric_limits<streamsize>::max() sets the maximum number of
             * characters to ignore. Since this is the upper limit on the size
             * of a stream, this effectively tells cin to ignore any and all 
             * input remaining in the buffer. */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 'y' && choice != 'n');

    if (choice == 'y') {
        return true;
    }
    return false;
}
/* **************** End of User-request Processing Functions *************** */

/* ***************** Start of Output-formatting Functions ****************** */
// prints a centered a title
void printCenteredTitle(string title) {
    int paddingWidth = (outputWidth.TOTAL - title.length()) / 2;
    // prints whitespace to pad the title
    for (int i = 0; i < paddingWidth; i++) {
        cout << " ";
    }
    // prints the title
    cout << title;
    cout << endl;
}
// prints a standard width horizontal break
void printHorizontalBreak() {
    for (int i = 0; i < outputWidth.TOTAL; i++) {
        cout << "=";
    }
    cout << endl;
}
// converts a string to uppercase
string to_uppercase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}
/* ****************** End of Output-formatting Functions ******************* */

/* ************** Start of SmartCityRouteManagement Functions ************** */
// this function adds a location to the network
void SmartCityRouteManagement::addLocation(const string& locationName) {
    // check if location already exists
    if (locationToIndex.find(locationName) == locationToIndex.end()) {
        int index = locations.size();
        locations.emplace_back(locationName, index);
        locationToIndex[locationName] = index;
    }
}     
// this function adds a route between two locations
void SmartCityRouteManagement::addRoute(const string& location1, 
                                const string& location2, int distance) {
    // check if both locations exist
    if (locationToIndex.find(location1) == locationToIndex.end() || 
        locationToIndex.find(location2) == locationToIndex.end()) {
        cout << "Error: One or both locations not found" << endl;
        return;
    }
    
    int idx1 = locationToIndex[location1];
    int idx2 = locationToIndex[location2];
    
    // add to adjacency list (both directions for undirected graph)
    adjList[idx1].emplace_back(idx2, distance);
    adjList[idx2].emplace_back(idx1, distance);
    
    // add to adjacency matrix (both directions)
    adjMatrix[idx1][idx2] = distance;
    adjMatrix[idx2][idx1] = distance;

    cout << "Route added.\n";   
}
// this function removes the route between two locations
void SmartCityRouteManagement::removeRoute(const string& location1, 
                                            const string& location2) {
    // check if both locations exist
    if (locationToIndex.find(location1) == locationToIndex.end() || 
        locationToIndex.find(location2) == locationToIndex.end()) {
        cout << "Error: One or both locations not found" << endl;
        return;
    }
    
    int idx1 = locationToIndex[location1];
    int idx2 = locationToIndex[location2];
    
    // remove from adjacency matrix (both directions)
    adjMatrix[idx1][idx2] = 0;
    adjMatrix[idx2][idx1] = 0;
    /* remove_if reorders the vector and returns an iterator to the */
    /* new logical end */
    vector<Neighbor>::iterator new_end_iterator1
                        = remove_if(adjList[idx1].begin(),
                        adjList[idx1].end(),[&](const Neighbor& n) {
        return n.locationIndex == idx2;
    });
    vector<Neighbor>::iterator new_end_iterator2
                        = remove_if(adjList[idx2].begin(),
                        adjList[idx2].end(),[&](const Neighbor& n) {
        return n.locationIndex == idx1;
    });
    // erase physically removes the elements from the vector
    adjList[idx1].erase(new_end_iterator1, adjList[idx1].end());
    adjList[idx2].erase(new_end_iterator2, adjList[idx2].end());

    cout << "Route removed.\n";   
}
// this function displays the adjacency matrix
void SmartCityRouteManagement::displayAdjacencyMatrix() {
    // print column headers (location names)
    cout << "\nAdjancency matrix:\n" << endl;
    cout << setw(outputWidth.COLUMN) << " ";
    for (const Location& location : locations) {
        cout << setw(outputWidth.COLUMN) << right
            << location.name.substr(0, 12);
    }
    cout << endl;

    for (unsigned int i = 0; i < locations.size(); i++) {
        cout << setw(outputWidth.COLUMN) << right
        << locations[i].name.substr(0, 12);;
        
        // matrix values
        for (unsigned int j = 0; j < locations.size(); j++) {
            if (i == j) {
                cout << setw(outputWidth.COLUMN)
                    << right << "0";  // distance to self is 0
            } else {
                cout << setw(outputWidth.COLUMN)
                    << right << adjMatrix[i][j];
            }
        }
        cout << endl;
    }
    cout << "\nNote: 0 means no direct connection,"
            " numbers represent distance in km\n";
}
// this function displays the adjacency list
void SmartCityRouteManagement::displayAdjacencyList() {
    cout << "\nLocations and their direct connections:\n" << endl;
    
    for (unsigned int i = 0; i < locations.size(); i++) {
        cout << "• " << locations[i].name << " connects to:" << endl;
        
        if (adjList[i].empty()) {
            cout << "  No direct connections" << endl;
        } else {
            for (const Neighbor& neighbor : adjList[i]) {
                cout << "  → " \
                    << locations[neighbor.locationIndex].name
                    << " (" << neighbor.distance << " km)" << endl;
            }
        }
        cout << endl;
    }
}
// BFS traversal to show reachable locations from a starting location
void SmartCityRouteManagement::bfsTraversal(const string& startLocation) {
    // check if starting location exists
    if (locationToIndex.find(startLocation) == locationToIndex.end()) {
        cout << "Error: Location '" << startLocation
            << "' not found" << endl;
        return;
    }
    
    int startIndex = locationToIndex[startLocation];
    vector<bool> visited(locations.size(), false);
    queue<int> q;
    
    cout << "\nBFS TRAVERSAL FROM " << startLocation << "\n" << endl;
    cout << "Order of visiting locations (showing reachability):"
        << endl;
    
    // start BFS from the specified location
    visited[startIndex] = true;
    q.push(startIndex);
    
    int level = 0;
    while (!q.empty()) {
        int levelSize = q.size();
        cout << "\nLevel " << level++ << ": ";
        
        for (int i = 0; i < levelSize; i++) {
            int current = q.front();
            q.pop();
            
            // visit the current location
            cout << locations[current].name;
            if (!q.empty() || i < levelSize - 1) {
                cout << " → ";
            }
            
            // add all unvisited neighbors to the queue
            for (const Neighbor& neighbor : adjList[current]) {
                if (!visited[neighbor.locationIndex]) {
                    visited[neighbor.locationIndex] = true;
                    q.push(neighbor.locationIndex);
                }
            }
        }
    }
    
    // show which locations are reachable
    cout << "\n\nReachable locations from " \
            << startLocation << ":" << endl;
    for (unsigned int i = 0; i < locations.size(); i++) {
        if (visited[i]) {
            cout << "✓ " << locations[i].name << endl;
        }
    }
    cout << endl;
}
// Dijkstra's algorithm to find shortest path between two locations
void SmartCityRouteManagement::dijkstraShortestPath(const string& origin,
                                const string& destination) {
    // check if both locations exist
    if (locationToIndex.find(origin) == locationToIndex.end() ||
        locationToIndex.find(destination) == locationToIndex.end()) {
        cout << "Error: One or both locations not found" << endl;
        return;
    }
    
    int startIndex = locationToIndex[origin];
    int endIndex = locationToIndex[destination];
    
    // arrays for Dijkstra's algorithm
    vector<int> distance(locations.size(), INT_MAX);
    vector<int> previous(locations.size(), -1);
    vector<bool> visited(locations.size(), false);
    
    // priority queue: (distance, location, index)
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                    greater<pair<int, int>>> pq;
    
    // initialize starting location
    distance[startIndex] = 0;
    pq.push({0, startIndex});
    
    cout << "\nDIJKSTRA'S SHORTEST PATH: " << origin
        << " to " << destination << "\n" << endl;

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();
        
        if (visited[current]) continue;
        visited[current] = true;
        
        // if we reached the destination, we can stop early
        if (current == endIndex) break;

        /* route comparison output */
        // reconstruct the path
        stack<int> currentPath;
        int iterator1 = current;
        
        while (iterator1 != -1) {
            currentPath.push(iterator1);
            iterator1 = previous[iterator1];
        }
        // display the shortest path and distance
        cout << "\nCurrent path: ";

        while (!currentPath.empty()) {
            cout << locations[currentPath.top()].name;
            currentPath.pop();
            if (!currentPath.empty()) cout << " → ";
        }

        cout << "\nCurrent distance: " << distance[current] << " km"
                << endl;
        /* *********************** */
        
        // explore all neighbors
        for (const Neighbor& neighbor : adjList[current]) {
            int alt = distance[current] + neighbor.distance;

            /* route comparison output */
            if (neighbor.locationIndex != startIndex) {
                
                cout << "\nPotential jump: " 
                    << locations[neighbor.locationIndex].name 
                    << " (+" << neighbor.distance << " km)\n";
                
                    if (neighbor.locationIndex == endIndex) {
                    cout << "Total distance: " << alt << " km\n";
                }
            }
            /* *********************** */

            if (alt < distance[neighbor.locationIndex]) {
                /* route comparison output */
                if (neighbor.locationIndex != startIndex 
                        && current != startIndex) {
                    // reconstruct the path
                    stack<int> shortestPath;
                    int iterator2 = current;
                    
                    while (iterator2 != -1) {
                        shortestPath.push(iterator2);
                        iterator2 = previous[iterator2];
                    }
                    // display the shortest path and distance
                    cout << "\nShortest path updated: ";

                    while (!shortestPath.empty()) {
                        cout << locations[shortestPath.top()].name;
                        shortestPath.pop();
                        if (!shortestPath.empty()) cout << " → ";
                    }
                    cout << " → " << locations[neighbor.locationIndex].name
                        << "\nDistance: " << alt << " km\n";
                }
                /* *********************** */

                distance[neighbor.locationIndex] = alt;
                previous[neighbor.locationIndex] = current;
                pq.push({alt, neighbor.locationIndex});
            }
        }
        cout << endl;
        for (int i = 0; i < outputWidth.TOTAL/2; i++) {
            cout << "*";
        }
        cout << endl;
    }
    // display results
    if (distance[endIndex] == INT_MAX) {
        cout << "No path exists between " << origin << " and "
        << destination << endl;
        return;
    }
    // reconstruct the path
    stack<int> path;
    int current = endIndex;
    
    cout << "\nShortest path: ";

    while (current != -1) {
        path.push(current);
        current = previous[current];
    }

    while (!path.empty()) {
        cout << locations[path.top()].name;
        path.pop();
        if (!path.empty()) cout << " → ";
    }
    // display the shortest path and distance
    cout << "\nShortest distance: " << distance[endIndex] << " km" 
            << endl;
    // show detailed route information
    cout << "\nDetailed route:" << endl;
    current = endIndex;
    stack<pair<int, int>> routeSegments;
    
    while (previous[current] != -1) {
        routeSegments.push({previous[current], current});
        current = previous[current];
    }
    
    while (!routeSegments.empty()) {
        int from = routeSegments.top().first;
        int to = routeSegments.top().second;
        routeSegments.pop();
        
        cout << "• " << locations[from].name << " to "
            << locations[to].name \
            << ": " << adjMatrix[from][to] << " km" << endl;
    }
    cout << endl;
}
// resizes the list and matrix (for use after adding/removing locations)
void SmartCityRouteManagement::resizeListAndMatrix() {
    adjList.resize(locations.size());
    adjMatrix.resize(locations.size(), 
        vector<int>(locations.size(), 0));
}
/* *************** End of SmartCityRouteManagement Functions *************** */

/* ************************************************************************* */
/*
Key Design decisions:                                                  
1. I repurposed the structure of the program (the menu driven aspect) from 
COS2614 Assessment 1 which required a similar structure.        
2. I repurposed the class for handling routes from COS2611 Assessment 3 which 
required similar functionality. I have included the original reflection that 
outlines the prompts used to obtain the class and algorithms. I did not use AI 
further in this Assessment, I just modified that code.
3. I used forward declaration in order to separate the code into logical  
sections, and to provide anyone reviewing the code an overview right at the 
beginning.
*/
/* ************************************************************************* */

/* ****************************** Reflection ******************************* */
/*
Prompts used:
1. Create a C++ program that models a simplified road network of Southern 
African cities using graph theory concepts. The program must represent cities 
as points (vertices) and roads as connections with distances (weighted edges).
2. Implement a Breadth-First Search (BFS) algorithm.
3. Implement Dijkstra's algorithm.
4. Explain the purpose and logic of each section in plain language, making the 
program understandable to a non-programmer or someone new to graph algorithms.

I had to prompt the AI to give more detailed explanations of how exactly 
Djikstra's algorithm works in order to verify that the implementation was indeed
correct. From this, I learned that if BFS finds any path, Dijkstra's algorithm 
finds the shortest path: "It's like having a super-efficient logistics manager 
who constantly calculates the quickest route to every city, updating their plans 
as they discover new, shorter paths.". This explanation made it clearer what was 
going on with the priority queue. I had already learned about BFS in Self 
Assessment 3. Overall, the assessment was straightforward and getting correct, 
explainable output was not an issue.
*/
/* ************************************************************************* */