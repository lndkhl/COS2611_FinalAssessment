/* ************************************************************************* */
/* ****************** Name: Lindokuhle Nsikelelo Nkambule ****************** */
/* *********************** Student Number: 21970858 ************************ */
/* ************************************************************************* */

#include <iostream>

#include <iomanip>
#include <fstream>
#include <sstream>
#include <limits>

#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <climits>
#include <iomanip>
#include <algorithm> // Required for std::transform
#include <cctype>    // Required for ::tolower

using namespace std;

string to_uppercase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::toupper);
    return result;
}


/* ************************************************************************* */
// the base class for all the items to be stored in the library
class LibraryItem {
private:
    string title;
    string author;
    bool isBorrowed;

public:
    LibraryItem(vector<string> line);
    LibraryItem(string title, string author);
    ~LibraryItem() {}
    string getTitle() const;
    string getAuthor() const;
    bool getIsBorrowed() const;
    void setTitle(string title);
    void setAuthor(string author);
    void setIsBorrowed(bool isBorrowed);
    virtual void displayInfo() {}
};

// output formatting values defined here
struct OutputWidth {
    const int INDEX_COL = 3;
    const int TITLE_COL = 30;
    const int AUTHOR_COL = 30;
    const int ADDITIONAL_INFO_COL = 30;
    const int IS_AVAILABLE_COL = 10;
    const int TOTAL_WIDTH = INDEX_COL + TITLE_COL + AUTHOR_COL \
                        + ADDITIONAL_INFO_COL + IS_AVAILABLE_COL;
};

const OutputWidth outputWidth;

// other const values defined here
const int LIBRARY_ITEM_VECTOR_SIZE = 5;
const int MAX_PAGE_SIZE = 5;
const int RETURN_TO_MAIN_MENU = 0;
const char BOOK = 'B';
const char MAGAZINE = 'M';
const char DELIMITER = '|';
enum class LibraryItemIndex { ITEM_TYPE, TITLE, AUTHOR, IS_BORROWED, \
                              ADDITIONAL_INFO };
enum class FilterType { BORROW, RETURN, GENERAL };
// helper functions that are used throughout the program
void printHorizontalBreak();
void printCenteredTitle(const string title);
string toLowercase(const string& input);
bool containsMatch(const vector<string>& words, const string& query);
bool to_bool(const string& s);
int min(const int a, const int b);
bool isPositiveInteger(const string& str);
vector<string> splitString(const string& input);
void processInput(const string& line);
/* ************************************************************************* */

/* ************************************************************************* */
class Book : public LibraryItem {
private:
    string genre;

public:
    Book(vector<string> line);
    Book(string title, string author, string genre);
    ~Book() {}
    string getGenre() const;
    void setGenre(string genre);
    bool operator==(const Book& other) const;
    friend ostream& operator<<(ostream& os, const Book& book);
    void displayInfo();
};

vector<Book> BOOKS;

void addBook();
int browseBooks(vector<Book>& books = BOOKS);
int filterBooks(FilterType filterType = FilterType::GENERAL,
                bool search = false);
int selectBook(const int index, vector<Book>& books = BOOKS);
int manageBook(Book& book);
void borrowBook(Book& book);
void returnBook(Book& book);
void printBookTableHeaders();
void displayBooks(vector<Book>& books = BOOKS, const int page = 0);
void nextBookListPage(int& page, vector<Book>& books = BOOKS);
void previousBookListPage(int& page);
void updateBooks(Book& book);
void displayBrowseBooksMenu(const int page, vector<Book>& books = BOOKS);
void displayManageBookMenu(const Book& book);
/* ************************************************************************* */

/* ************************************************************************* */
class Magazine : public LibraryItem {
private:
    string issueNumber;

public:
    Magazine(vector<string> line);
    Magazine(string title, string author, string issueNumber);
    ~Magazine() {}
    string getIssueNumber() const;
    void setIssueNumber(string issueNumber);
    bool operator==(const Magazine& other) const;
    friend ostream& operator<<(ostream& os, const Magazine& magazine);
    void displayInfo();
};

vector<Magazine> MAGAZINES;

void addMagazine();
int browseMagazines(vector<Magazine>& magazines = MAGAZINES);
int filterMagazines(FilterType filterType = FilterType::GENERAL,
                    bool search = false);
int selectMagazine(const int index, vector<Magazine>& magazines = MAGAZINES);
int manageMagazine(Magazine& magazine);
void borrowMagazine(Magazine& magazine);
void returnMagazine(Magazine& magazine);
void printMagazineTableHeaders();
void displayMagazines(vector<Magazine>& magazines = MAGAZINES,
                      const int page = 0);
void nextMagazineListPage(int& page, vector<Magazine>& magazines = MAGAZINES);
void previousMagazineListPage(int& page);
void updateMagazines(Magazine& magazine);
void displayBrowseMagazinesMenu(const int page,
                                const vector<Magazine>& magazines = MAGAZINES);
void displayManageMagazineMenu(const Magazine& magazine);
/* ************************************************************************* */

/* ************************************************************************* */
//
void mainMenu();
void mainSubMenu(char function);
//
int processMainSubMenuChoice(char function, char itemType);
//
void displayMainMenu();
void displayMainSubMenu(string specifier);
/* ************************************************************************* */

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
        
        vector<Location> locations;                    // list of all locations
        map<string, int> locationToIndex;           // mapping from location name to index
        vector<vector<Neighbor>> adjList;       // adjacency list representation
        vector<vector<int>> adjMatrix;          // adjacency matrix representation
        
    public:
        // this constructor initializes the graph with hardcoded Southern African locations
        SmartCityRouteManagement() {
            // adds major Southern African locations with realistic names
            // addLocation("Windhoek");     
            // addLocation("Gaborone");     
            // addLocation("Johannesburg"); 
            // addLocation("Harare");       
            // addLocation("Maputo");       
            // addLocation("Lusaka");       
            // addLocation("Pretoria");     
            
            // initialize adjacency list and matrix
            // resizeListAndMatrix();
            
            // add realistic road connections with approximate distances in km
            // addRoute("Windhoek", "Gaborone", 950);
            // addRoute("Windhoek", "Johannesburg", 1450);
            // addRoute("Gaborone", "Johannesburg", 550);
            // addRoute("Gaborone", "Harare", 1050);
            // addRoute("Johannesburg", "Pretoria", 60);
            // addRoute("Johannesburg", "Maputo", 550);
            // addRoute("Johannesburg", "Harare", 1150);
            // addRoute("Harare", "Lusaka", 570);
            // addRoute("Maputo", "Harare", 1200);
            // addRoute("Pretoria", "Maputo", 520);
            // addRoute("Lusaka", "Gaborone", 1250);
    }
    
    // this function adds a location to the network
    void addLocation(const string& locationName) {
        // check if location already exists
        if (locationToIndex.find(locationName) == locationToIndex.end()) {
            int index = locations.size();
            locations.emplace_back(locationName, index);
            locationToIndex[locationName] = index;
        }
    }
    
    // this function adds a road between two locations
    void addRoute(const string& location1, const string& location2, int distance) {
        // check if both locations exist
        if (locationToIndex.find(location1) == locationToIndex.end() || 
            locationToIndex.find(location2) == locationToIndex.end()) {
            cout << "Error: One or both locations not found!" << endl;
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
    }
    
    // this function displays the adjacency matrix
    void displayAdjacencyMatrix() {
        //
        cout << "\nAdjancency matrix:\n" << endl;
        // print column headers (location names)
        cout << setw(15) << " ";
        for (const auto& location : locations) {
            cout << setw(15) << location.name.substr(0, 12);
        }
        cout << endl;
        
        // print matrix rows
        for (int i = 0; i < locations.size(); i++) {
            // Row header (location name)
            cout << setw(15) << locations[i].name.substr(0, 12);
            
            // matrix values
            for (int j = 0; j < locations.size(); j++) {
                if (i == j) {
                    cout << setw(15) << "0";  // distance to self is 0
                } else {
                    cout << setw(15) << adjMatrix[i][j];
                }
            }
            cout << endl;
        }
        cout << "\nNote: 0 means no direct connection, numbers represent distance in km\n";
    }
    
    // this function displays the graph structure (connections between locations)
    void displayGraphStructure() {
        cout << "\nLocations and their direct connections:\n" << endl;
        
        for (int i = 0; i < locations.size(); i++) {
            cout << "• " << locations[i].name << " connects to:" << endl;
            
            if (adjList[i].empty()) {
                cout << "  No direct connections" << endl;
            } else {
                for (const auto& neighbor : adjList[i]) {
                    cout << "  → " << locations[neighbor.locationIndex].name 
                         << " (" << neighbor.distance << " km)" << endl;
                }
            }
            cout << endl;
        }
    }
    
    // BFS traversal to show reachable locations from a starting location
    void bfsTraversal(const string& startLocation) {
        // check if starting location exists
        if (locationToIndex.find(startLocation) == locationToIndex.end()) {
            cout << "Error: Location '" << startLocation << "' not found!" << endl;
            return;
        }
        
        int startIndex = locationToIndex[startLocation];
        vector<bool> visited(locations.size(), false);
        queue<int> q;
        
        cout << "\n=== BFS TRAVERSAL FROM " << startLocation << " ===\n" << endl;
        cout << "Order of visiting locations (showing reachability):" << endl;
        
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
                for (const auto& neighbor : adjList[current]) {
                    if (!visited[neighbor.locationIndex]) {
                        visited[neighbor.locationIndex] = true;
                        q.push(neighbor.locationIndex);
                    }
                }
            }
        }
        
        // show which locations are reachable
        cout << "\n\nReachable locations from " << startLocation << ":" << endl;
        for (int i = 0; i < locations.size(); i++) {
            if (visited[i]) {
                cout << "✓ " << locations[i].name << endl;
            }
        }
        cout << endl;
    }
    
    // Dijkstra's algorithm to find shortest path between two locations
    void dijkstraShortestPath(const string& startLocation, const string& endLocation) {
        // check if both locations exist
        if (locationToIndex.find(startLocation) == locationToIndex.end() || 
            locationToIndex.find(endLocation) == locationToIndex.end()) {
            cout << "Error: One or both locations not found!" << endl;
            return;
        }
        
        int startIndex = locationToIndex[startLocation];
        int endIndex = locationToIndex[endLocation];
        
        // arrays for Dijkstra's algorithm
        vector<int> distance(locations.size(), INT_MAX);
        vector<int> previous(locations.size(), -1);
        vector<bool> visited(locations.size(), false);
        
        // priority queue: (distance, location index)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // initialize starting location
        distance[startIndex] = 0;
        pq.push({0, startIndex});
        
        cout << "\n=== DIJKSTRA'S SHORTEST PATH: " << startLocation << " to " << endLocation << " ===\n" << endl;
        
        // Dijkstra's algorithm
        while (!pq.empty()) {
            int current = pq.top().second;
            pq.pop();
            
            if (visited[current]) continue;
            visited[current] = true;
            
            // if we reached the destination, we can stop early
            if (current == endIndex) break;
            
            // explore all neighbors
            for (const auto& neighbor : adjList[current]) {
                int alt = distance[current] + neighbor.distance;
                
                if (alt < distance[neighbor.locationIndex]) {
                    distance[neighbor.locationIndex] = alt;
                    previous[neighbor.locationIndex] = current;
                    pq.push({alt, neighbor.locationIndex});
                }
            }
        }
        
        // display results
        if (distance[endIndex] == INT_MAX) {
            cout << "No path exists between " << startLocation << " and " << endLocation << "!" << endl;
            return;
        }
        
        // reconstruct the path
        stack<int> path;
        int current = endIndex;
        
        while (current != -1) {
            path.push(current);
            current = previous[current];
        }
        
        // display the shortest path and distance
        cout << "Shortest distance: " << distance[endIndex] << " km" << endl;
        cout << "Shortest path: ";
        
        while (!path.empty()) {
            cout << locations[path.top()].name;
            path.pop();
            if (!path.empty()) cout << " → ";
        }
        cout << endl;
        
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
            
            cout << "• " << locations[from].name << " to " << locations[to].name 
                 << ": " << adjMatrix[from][to] << " km" << endl;
        }
        cout << endl;
    }
    
    int getLocationsCount() {
        return locations.size();
    }

    void resizeListAndMatrix() {
        adjList.resize(locations.size());
        adjMatrix.resize(locations.size(), vector<int>(locations.size(), 0));
    }
};
// create the transport network
SmartCityRouteManagement network;

/* ************************************************************************* */
// stores the library items in memory during program execution for quick access

// makes initializing LibraryItem object from file line input easier
LibraryItem::LibraryItem(vector<string> line) {
    title = line[static_cast<int>(LibraryItemIndex::TITLE)];
    author = line[static_cast<int>(LibraryItemIndex::AUTHOR)];
    isBorrowed = to_bool(line[static_cast<int>(LibraryItemIndex::IS_BORROWED)]);
}
// makes initializing LibraryItem object from user input easier
LibraryItem::LibraryItem(string title, string author) {
    this->title = title;
    this->author = author;
    isBorrowed = false;
}
// sets the LibraryItem's title
void LibraryItem::setTitle(string title) {
    this->title = title;
}
// sets the LibraryItem's author
void LibraryItem::setAuthor(string author) {
    this->author = author;
}
// sets the isBorrowed attribute of the LibraryItem
void LibraryItem::setIsBorrowed(bool isBorrowed) {
    this->isBorrowed = isBorrowed;
}
// returns the LibraryItem's title
string LibraryItem::getTitle() const {
    return title;
}
// returns the LibraryItem's author
string LibraryItem::getAuthor() const {
    return author;
}
// returns the LibraryItem's isBorrowed attribute
bool LibraryItem::getIsBorrowed() const {
    return isBorrowed;
}

// prints a standard width horizontal break
void printHorizontalBreak() {
    for (int i = 0; i < outputWidth.TOTAL_WIDTH; i++) {
        cout << "=";
    }
    cout << endl;
}
// prints a centered a title
void printCenteredTitle(string title) {
    int paddingWidth = (outputWidth.TOTAL_WIDTH - title.length()) / 2;
    // prints whitespace to pad the title
    for (int i = 0; i < paddingWidth; i++) {
        cout << " ";
    }
    // prints the title
    cout << title;
    // prints whitespace to pad the title
    for (int i = 0; i < paddingWidth; i++) {
        cout << " ";
    }
    cout << endl;
}
// returns a copy of the string in all lowercase
string toLowercase(const string& input) {
    string result;
    for (const char c : input) {
        result += tolower(c);
    }
    return result;
}
// checks if the query-string is in the given words (case insensitive)
bool containsMatch(const vector<string>& words, const string& query) {
    vector<string> results;
    string lowerQuery = toLowercase(query);
    //
    for (const string& word : words) {
        string lowerWord = toLowercase(word);
        /* returns true if the query-string is found in the current word,
        note that the find() function in the <string> library returns
        string::npos if no matches were found */
        if (lowerWord.find(lowerQuery) != string::npos) {
            return true;
        }
    }
    return false;
}
// converts a char to a boolean value
bool to_bool(const string& s) {
    return s != "0";
}
// returns the smaller of the two values
int min(const int a,const int b) {
    if (a <= b) {
        return a;
    }
    return b;
}
// validates user input
bool isPositiveInteger(const string& str) {
    /* this range-based for-loop checks that each character in the given string
     *  is a digit */
    for (const char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}
// parses a line of input
vector<string> splitString(const string& input) {
    vector<string> tokens;
    /* stringstream (defined in the <sstream> Standard library header)
     * allows us to read from and write to strings in the same manner as
     * reading from and writing to files */
    stringstream ss(input);
    string token;

    while (getline(ss, token, DELIMITER)) {
        // removes the newline character from the end of the string
        if (token[token.length() - 1] == '\r') {
            token.erase(token.length() - 1);
        }
        tokens.push_back(token);
    }
    return tokens;
}
// processes a line of input and adds the item to the library if it is valid
void processInput(const string& line) {
    vector<string> result;

    result = splitString(line);
    // checks that the input has the correct number of parameters
    if ((int)result.size() == LIBRARY_ITEM_VECTOR_SIZE) {
        // checks the item type, and adds the item to the appropriate vector
        if (result[static_cast<int>(LibraryItemIndex::ITEM_TYPE)][0] == BOOK) {
            Book current(result);
            BOOKS.push_back(current);
        }
        else if (result[static_cast<int>(LibraryItemIndex::ITEM_TYPE)][0] \
                   == MAGAZINE) {
            MAGAZINES.push_back(result);
        }
    }
}
/* ************************************************************************* */

/* ************************************************************************* */
// makes initializing a Book object from file line input easier
Book::Book(vector<string> line) : LibraryItem(line) {
    genre = line[static_cast<int>(LibraryItemIndex::ADDITIONAL_INFO)];
}
// makes initializing a Book object from user input easier
Book::Book(string title, string author, string genre) \
    : LibraryItem(title, author) {
    this->genre = genre;
}
// returns the genre of a Book object
string Book::getGenre() const {
    return genre;
}
// sets the Genre of a Book object
void Book::setGenre(string genre) {
    this->genre = genre;
}
// allows for more convenient comparison of Book objects
bool Book::operator==(const Book& other) const {
    return (this->getTitle() == other.getTitle()) \
           && (this->getAuthor() == other.getAuthor() \
               && (this->getGenre() == other.getGenre()));
}
// overrides the base class' displayInfo() function
void Book::displayInfo() {
    cout << setw(outputWidth.TITLE_COL) << left << LibraryItem::getTitle() \
         << setw(outputWidth.AUTHOR_COL) << left << LibraryItem::getAuthor() \
         << setw(outputWidth.ADDITIONAL_INFO_COL) << left << genre \
         << setw(outputWidth.IS_AVAILABLE_COL) << left << boolalpha << \
        !(LibraryItem::getIsBorrowed()) << endl;
}
/* allows us to more conveniently print the details of a Book object to
 * the console */
ostream& operator<<(ostream& os, const Book& book) {
    os << BOOK << DELIMITER << book.getTitle() << DELIMITER << \
        book.getAuthor() << DELIMITER << book.getIsBorrowed() << \
        DELIMITER << book.getGenre() << endl;

    return os;
}
// walks the user through adding a magazine to the library
void addBook() {
    string title, author, genre;
    string menuTitle = "ADD BOOK";

    printHorizontalBreak();
    printCenteredTitle(menuTitle);
    printHorizontalBreak();
    // prompts the user to enter the details of the magazine to be added
    cout << "Enter the title of the book:\n";
    // clears any remaining input and errors
    cin.clear();
    /* numeric_limits<streamsize>::max() sets the maximum number of
     * characters to ignore. Since this is the upper limit on the size
     * of a stream, this effectively tells cin to ignore any and all input
     * remaining in the buffer. */
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, title);
    cout << "Enter the name of the author:\n";
    getline(cin, author);
    cout << "Enter the genre of the book:\n";
    getline(cin, genre);
    cout << "Book added to library.\n";

    Book newBook(title, author, genre);
    BOOKS.push_back(newBook);
}
//
int browseBooks(vector<Book>& books) {
    int index = 1;
    int page = 0;

    do {
        displayBooks(books, page);
        displayBrowseBooksMenu(page, books);
        /* reads in user input as a string to allow for both int
         * and char input for this function */
        string input;
        cin >> input;
        // checks if input is a number
        if(isdigit(input[0])) {
            try {
                index = stoi(input);
                if (index > 0) {
                    index = selectBook(--index, books);
                }
            } catch(...) {
                cout << "Invalid input!\n";
            }
        }
        // checks if input is a single character
        else if(input.length() == 1) {
            switch(input[0]) {
            case 'N': nextBookListPage(page, books); break;
            case 'P': previousBookListPage(page); break;
            default: cout << "Invalid input!\n";
            }
        }
        else {
            cout << "Invalid input!\n";
        }
        // clears any remaining input and errors
        cin.clear();
        // detailed explanation on line 56
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (index != 0);

    return RETURN_TO_MAIN_MENU;
}
// filters the books to display to the user
int filterBooks(FilterType filterType, bool search) {
    string searchTerm;
    vector<Book> matches;

    // prompts the user for input in the case that they chose to search
    if (search) {
        if (filterType == FilterType::BORROW) {
            cout << "Enter the title of the book you want to borrow:\n";
        }
        else if (filterType == FilterType::RETURN) {
            cout << "Enter the title of the book you want to return:\n";
        }
        else {
            cout << "Enter a title or author or genre:\n";
        }
        // clears any remaining input and errors
        cin.clear();
        // detailed explanation on line 56
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, searchTerm);
    }
    // applies the filters to the library and groups matching items
    for (Book& book : BOOKS) {
        vector<string> params{book.getTitle(), book.getAuthor(), \
                        book.getGenre()};

        if ((filterType == FilterType::RETURN && !book.getIsBorrowed())
            || (filterType == FilterType::BORROW && book.getIsBorrowed())) {
            continue;
        }
        if (!search || (search && containsMatch(params, searchTerm))) {
            matches.push_back(book);
        }
    }
    // presents results to the user
    if (matches.size() > 0) {
        browseBooks(matches);
    }
    else {
        cout << "No matching items found.\n";
    }

    return RETURN_TO_MAIN_MENU;
}
// allows a user to specify a book to take further action on
int selectBook(const int index, vector<Book>& books) {

    if (index >= (int)books.size()) {
        cout << "Invalid input!\n";
        return RETURN_TO_MAIN_MENU;
    }

    printHorizontalBreak();
    cout << "You have selected: '" << books[index].getTitle() <<"' by '" << \
            books[index].getAuthor() << "'\n";

    return manageBook(books[index]);
}
// allows a user to borrow or return a book
int manageBook(Book& book) {
    int choice;

    do {
        displayManageBookMenu(book);

        if(!(cin >> choice))
        {
            // clears any remaining input and errors
            cin.clear();
            // detailed explanation on line 56
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch(choice) {
        case 1: {
            book.getIsBorrowed() == false ? borrowBook(book) \
                                          : returnBook(book);
            cout << "Book borrowed!\n";
            return 2;
        }
        case 2: return 2;
        default: {
            cout << "Invalid input!\n";
        }
        }
    } while (choice != RETURN_TO_MAIN_MENU);

    return RETURN_TO_MAIN_MENU;
}
// sets a book's isBorrowed attribute to true and updates the library
void borrowBook(Book& book) {
    book.setIsBorrowed(true);
    updateBooks(book);
}
// sets a book's isBorrowed attribute to false and updates the library
void returnBook(Book& book) {
    book.setIsBorrowed(false);
    updateBooks(book);
}
// prints the headers for the magazines table to the console
void printBookTableHeaders() {
    cout << setw(outputWidth.INDEX_COL) << left << "#" \
         << setw(outputWidth.TITLE_COL) << left << "Title" \
         << setw(outputWidth.AUTHOR_COL) << left << "Author" \
         << setw(outputWidth.ADDITIONAL_INFO_COL) << left << "Genre" \
         << setw(outputWidth.IS_AVAILABLE_COL) << left << "Available" << endl;
}
// handles printing a page of the list of books to the console
void displayBooks(vector<Book>& books, const int page) {
    int maxIndex = min((int)books.size(), (page * MAX_PAGE_SIZE) \
                                               + MAX_PAGE_SIZE);
    string title = "ENTER A BOOK'S INDEX NUMBER TO SELECT IT";

    printHorizontalBreak();
    printCenteredTitle(title);
    printHorizontalBreak();
    printBookTableHeaders();

    for(int index = MAX_PAGE_SIZE * page; index < maxIndex; index++) {
        cout << setw(outputWidth.INDEX_COL) << left << index + 1;
        books[index].displayInfo();
    }

    printHorizontalBreak();
    cout << "Page: " << page + 1 << endl;
    printHorizontalBreak();
}
// displays the next page of books
void nextBookListPage(int& page, vector<Book>& books) {
    if ((int)books.size() > (page * MAX_PAGE_SIZE) + MAX_PAGE_SIZE) {
        ++page;
    }
}
// display's the previous page of books
void previousBookListPage(int& page) {
    if (page > 0) {
        --page;
    }
}
/* finds the matching item in the library and updates its isBorrowed
 * attribute */
void updateBooks(Book& book) {
    for (Book& other : BOOKS) {
        if (other == book) {
            other.setIsBorrowed(book.getIsBorrowed());
        }
    }
}
// displays controls for the browse books page
void displayBrowseBooksMenu(const int page, vector<Book>& books) {

    if ((int)books.size() > (page * MAX_PAGE_SIZE) + MAX_PAGE_SIZE) {
        cout << "N. Next Page\n";
    }
    if (page > 0) {
        cout << "P. Previous Page\n";
    }
    cout << "\n0. Return To Main Menu\n";
    printHorizontalBreak();
    cout << "Enter your choice: ";
}
// allows a user to borrow or return a particular book
void displayManageBookMenu(const Book& book) {
    printHorizontalBreak();

    if (book.getIsBorrowed() == true) {
        cout << "1. Return Book\n";
    }
    else {
        cout << "1. Borrow Book\n";
    }

    cout << "2. Back\n";
    cout << "\n0. Return To Main Menu\n";

    printHorizontalBreak();
    cout << "Enter your choice (0-2): ";
}
/* ************************************************************************* */

/* ************************************************************************* */
// makes initializing a Magazine object from file line input easier
Magazine::Magazine(vector<string> line) : LibraryItem(line) {
    issueNumber = line[static_cast<int>(LibraryItemIndex::ADDITIONAL_INFO)];
}
// makes initializing a Magazine object from user input easier
Magazine::Magazine(string title, string author, string issueNumber) \
    : LibraryItem(title, author) {
    this->issueNumber = issueNumber;
}
// returns the issue-number of a Magazine object
string Magazine::getIssueNumber() const {
    return issueNumber;
}
// sets the issue-number of a Magazine object
void Magazine::setIssueNumber(string issueNumber) {
    this->issueNumber = issueNumber;
}
// allows for more convenient comparison of Magazine objects
bool Magazine::operator==(const Magazine& other) const {
    return (this->getTitle() == other.getTitle()) \
           && (this->getAuthor() == other.getAuthor() \
               && (this->getIssueNumber() == other.getIssueNumber()));
}
// overrides the base class' displayInfo() function
void Magazine::displayInfo() {
    cout << setw(outputWidth.TITLE_COL) << left << LibraryItem::getTitle() \
         << setw(outputWidth.AUTHOR_COL) << left << LibraryItem::getAuthor() \
         << setw(outputWidth.ADDITIONAL_INFO_COL) << left << issueNumber \
         << setw(outputWidth.IS_AVAILABLE_COL) << left << boolalpha << \
        !(LibraryItem::getIsBorrowed()) << endl;
}
/* allows us to more conveniently print the details of a Magazine object to
 * the console */
ostream& operator<<(ostream& os, const Magazine& magazine) {
    os << MAGAZINE << DELIMITER << magazine.getTitle() << DELIMITER << \
        magazine.getAuthor() << DELIMITER << magazine.getIsBorrowed() << \
        DELIMITER << magazine.getIssueNumber() << endl;

    return os;
}
// walks the user through adding a magazine to the library
void addMagazine() {
    string title, author, issueNumber;
    string menuTitle = "ADD MAGAZINE";

    printHorizontalBreak();
    printCenteredTitle(menuTitle);
    printHorizontalBreak();
    // prompts the user to enter the details of the magazine to be added
    cout << "Enter the title of the magazine:\n";
    // clears any remaining input and errors
    cin.clear();
    /* numeric_limits<streamsize>::max() sets the maximum number of
     * characters to ignore. Since this is the upper limit on the size
     * of a stream, this effectively tells cin to ignore any and all input
     * remaining in the buffer. */
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, title);
    cout << "Enter the name of the author:\n";
    getline(cin, author);
    cout << "Enter the issue number of the magazine:\n";
    getline(cin, issueNumber);
    cout << "Magazine added to library.\n";

    Magazine newMagazine(title, author, issueNumber);
    MAGAZINES.push_back(newMagazine);
}
// presents some or all of the magazines to the user for selection
int browseMagazines(vector<Magazine>& magazines) {
    int index = 1;
    int page = 0;

    do {
        displayMagazines(magazines, page);
        displayBrowseMagazinesMenu(page, magazines);
        /* reads in user input as a string to allow for both int
         * and char input for this function */
        string input;
        cin >> input;
        // checks if input is a number
        if(isdigit(input[0])) {
            try {
                index = stoi(input);
                if (index > 0) {
                    index = selectMagazine(--index, magazines);
                }
            } catch(...) {
                cout << "Invalid input!\n";
            }
        }
        // checks if input is a single character
        else if(input.length() == 1) {
            switch(input[0]) {
            case 'N': nextMagazineListPage(page, magazines); break;
            case 'P': previousMagazineListPage(page); break;
            default: cout << "Invalid input!\n";
            }
        }
        else {
            cout << "Invalid input!\n";
        }
        // clears any remaining input and errors
        cin.clear();
        // detailed explanation on line 56
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (index != 0);
    return RETURN_TO_MAIN_MENU;
}
// filters the magazines to display to the user
int filterMagazines(FilterType filterType, bool search) {
    string searchTerm;
    vector<Magazine> matches;

    // prompts the user for input in the case that they chose to search
    if (search) {
        if (filterType == FilterType::BORROW) {
            cout << "Enter the title of the magazine you want to borrow:\n";
        }
        else if (filterType == FilterType::RETURN) {
            cout << "Enter the title of the magazine you want to return:\n";
        }
        else {
            cout << "Enter a title or author or issue-number:\n";
        }
        // clears any remaining input and errors
        cin.clear();
        // detailed explanation on line 56
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, searchTerm);
    }
    // applies the filters to the library and groups matching items
    for (Magazine& magazine : MAGAZINES) {
        vector<string> params{magazine.getTitle(), magazine.getAuthor(), \
                                                    magazine.getIssueNumber()};

        if ((filterType == FilterType::RETURN && !magazine.getIsBorrowed())
            || (filterType == FilterType::BORROW && magazine.getIsBorrowed())) {
            continue;
        }
        if (!search || (containsMatch(params, searchTerm))) {
            matches.push_back(magazine);
        }
    }
    // presents results to the user
    if (matches.size() > 0) {
        browseMagazines(matches);
    }
    else {
        cout << "No matching items found.\n";
    }
    return RETURN_TO_MAIN_MENU;
}
// allows a user to specify a magazine to take further action on
int selectMagazine(const int index, vector<Magazine>& magazines) {

    if (index >= (int)magazines.size()) {
        cout << "Invalid input!\n";
        return RETURN_TO_MAIN_MENU;
    }

    printHorizontalBreak();
    cout << " You have selected: '" << magazines[index].getTitle() <<"' by '" \
         << magazines[index].getAuthor() << "'\n";

    return manageMagazine(magazines[index]);
}
// allows a user to borrow or return a magazine
int manageMagazine(Magazine& magazine) {
    int choice;

    do {
        displayManageMagazineMenu(magazine);

        if(!(cin >> choice))
        {
            // clears any remaining input and errors
            cin.clear();
            // detailed explanation on line 56
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch(choice) {
        case 1: {
            magazine.getIsBorrowed() == false ? borrowMagazine(magazine) \
                                              : returnMagazine(magazine);
            cout << "Magazine borrowed!\n";
            return 1;
        }
        case 2: return 2;
        default: {
            cout << "Invalid input!\n";
        }
        }
    } while(choice != RETURN_TO_MAIN_MENU);

    return RETURN_TO_MAIN_MENU;
}
// sets a magazine's isBorrowed attribute to true and updates the library
void borrowMagazine(Magazine& magazine) {
    magazine.setIsBorrowed(true);
    updateMagazines(magazine);
}
// sets a magazine's isBorrowed attribute to false and updates the library
void returnMagazine(Magazine& magazine) {
    magazine.setIsBorrowed(false);
    updateMagazines(magazine);
}
// prints the headers for the magazines table to the console
void printMagazineTableHeaders() {
    cout << setw(outputWidth.INDEX_COL) << left << "#" \
         << setw(outputWidth.TITLE_COL) << left << "Title" \
         << setw(outputWidth.AUTHOR_COL) << left << "Author" \
         << setw(outputWidth.ADDITIONAL_INFO_COL) << left << "Issue Number" \
         << setw(outputWidth.IS_AVAILABLE_COL) << left << "Available" << endl;
}
// handles printing a page of the list of magazines to the console
void displayMagazines(vector<Magazine>& magazines, const int page) {
    int maxIndex = min((int)magazines.size(), (page * MAX_PAGE_SIZE) \
                                                   + MAX_PAGE_SIZE);
    string title = "ENTER A MAGAZINE'S INDEX NUMBER TO SELECT IT";

    printHorizontalBreak();
    printCenteredTitle(title);
    printHorizontalBreak();
    printMagazineTableHeaders();

    for(int index = MAX_PAGE_SIZE * page; index < maxIndex; index++) {
        cout << setw(outputWidth.INDEX_COL) << left << index + 1;
        magazines[index].displayInfo();
    }

    printHorizontalBreak();
    cout << "Page: " << page + 1 << endl;
    printHorizontalBreak();
}
// displays the next page of magazines
void nextMagazineListPage(int& page, vector<Magazine>& magazines) {
    if ((int)magazines.size() > (page * MAX_PAGE_SIZE) + MAX_PAGE_SIZE) {
        ++page;
    }
}
// display's the previous page of magazines
void previousMagazineListPage(int& page) {
    if (page > 0) {
        --page;
    }
}
/* finds the matching item in the library and updates its isBorrowed
 * attribute */
void updateMagazines(Magazine& magazine) {
    for (Magazine& other : MAGAZINES) {
        if (other == magazine) {
            other.setIsBorrowed(magazine.getIsBorrowed());
        }
    }
}
// displays controls for the browse magazines page
void displayBrowseMagazinesMenu(const int page, \
                                const vector<Magazine>& magazines) {

    if ((int)magazines.size() > (page * MAX_PAGE_SIZE) + MAX_PAGE_SIZE) {
        cout << "N. Next Page\n";
    }
    if (page > 0) {
        cout << "P. Previous Page\n";
    }
    cout << "\n0. Return To Main Menu\n";
    printHorizontalBreak();
    cout << "Enter your choice: ";
}
// allows a user to borrow or return a particular magazine
void displayManageMagazineMenu(const Magazine& magazine) {

    printHorizontalBreak();

    if (magazine.getIsBorrowed() == true) {
        cout << "1. Return Magazine\n";
    }
    else {
        cout << "1. Borrow Magazine\n";
    }

    cout << "2. Back\n";
    cout << "\n0. Return To Main Menu\n";

    printHorizontalBreak();
    cout << "Enter your choice (0-2): ";
}
/* ************************************************************************* */

/* ************************************************************************* */
//
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
             * of a stream, this effectively tells cin to ignore any and all input
             * remaining in the buffer. */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 'y' && choice != 'n');

    if (choice == 'y') {
        return true;
    }
    return false;
}
//
void addRouteExtended() {
    string origin, destination;
    int distance;
    
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
    cout << "Enter the distance (in Km) between the the two locations:\n";
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

    network.addLocation(to_uppercase(origin));
    network.addLocation(to_uppercase(destination));
    network.addRoute(to_uppercase(origin), to_uppercase(destination), distance);

    cout << "Route Added.\n";
}

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
    cout << "Enter the distance (in Km) between the the two locations:\n";
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

    network.addLocation(to_uppercase(origin));
    network.addLocation(to_uppercase(destination));
    network.resizeListAndMatrix();
    network.addRoute(to_uppercase(origin), to_uppercase(destination), distance);

    cout << "Route Added.\n";
    
    if (network.getLocationsCount() > 2) {
        string description = "You have other locations in the city, would "\
                                "you like to set the distance to these "\
                                "locations now? (y/n): ";
        if (confirmOption(description)) {
            addRouteExtended();
        }
    }    
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
             * of a stream, this effectively tells cin to ignore any and all input
             * remaining in the buffer. */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    
        switch(choice) {
            case 1: addRouteWizard(); break;
            case 2: cout << "coming soon!\n"; break;
            case 3: network.displayAdjacencyMatrix(); break;
            case 4: network.displayGraphStructure(); break;
            case 0: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 0);
}
/* ************************************************************************* */

/* ************************************************************************* */
int main() {
    // launches the main menu
    mainMenu();

    // cout << "==================================================" << endl;
    // cout << "   SOUTHERN AFRICA TRANSPORT NETWORK ANALYZER" << endl;
    // cout << "==================================================" << endl;   
    
    // // display the network structure
    // network.displayGraphStructure();
    
    // // display adjacency matrix
    // network.displayAdjacencyMatrix();
    
    // // demonstrate BFS traversal
    // cout << "\n\n";
    // cout << "==================================================" << endl;
    // cout << "        BREADTH-FIRST SEARCH (BFS) DEMO" << endl;
    // cout << "==================================================" << endl;
    // network.bfsTraversal("Windhoek");
    
    // // demonstrate Dijkstra's algorithm
    // cout << "==================================================" << endl;
    // cout << "         DIJKSTRA'S ALGORITHM DEMO" << endl;
    // cout << "==================================================" << endl;
    // network.dijkstraShortestPath("Windhoek", "Maputo");
    // network.dijkstraShortestPath("Gaborone", "Lusaka");
    
    // // additional examples
    // cout << "==================================================" << endl;
    // cout << "           ADDITIONAL EXAMPLES" << endl;
    // cout << "==================================================" << endl;
    // network.dijkstraShortestPath("Johannesburg", "Harare");
    
    // cout << "==================================================" << endl;
    // cout << "   PROGRAM COMPLETED SUCCESSFULLY!" << endl;
    // cout << "==================================================" << endl;
       
    return 0;
}

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