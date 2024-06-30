#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// Function to find the final position of the query card after all moves
vector<int> findFinalPosition(vector<vector<int>>& cards, vector<vector<int>>& moves, int query) {
    unordered_map<int, pair<int, int>> cardPositions;

    // Initialize positions from the cards input
    for (const auto& card : cards) {
        int cardID = card[0];
        int row = card[1];
        int col = card[2];
        cardPositions[cardID] = {row, col};
    }

    // Process each move
    for (const auto& move : moves) {
        int cardID = move[0];
        int srcRow = move[1];
        int srcCol = move[2];
        int destRow = move[3];
        int destCol = move[4];

        // Update the position of the moved card
        cardPositions[cardID] = {destRow, destCol};

        // Check if there's another card at the destination
        for (auto it = cardPositions.begin(); it != cardPositions.end(); ++it) {
            if (it->first != cardID && it->second.first == destRow && it->second.second == destCol) {
                // Move the card down by one row
                it->second.first += 1;
            }
        }

        // Update the positions of other cards in the original column
        for (auto it = cardPositions.begin(); it != cardPositions.end(); ++it) {
            if (it->first != cardID && it->second.second == srcCol && it->second.first > srcRow) {
                it->second.first -= 1;
            }
        }
    }

    // Return the final position of the query card
    return {cardPositions[query].first, cardPositions[query].second};
}

// Function to parse a 2D vector from string input
vector<vector<int>> parse2DVector(const string& str) {
    vector<vector<int>> result;
    stringstream ss(str);
    char ch;
    int num;
    vector<int> temp;
    while (ss >> ch) {
        if (ch == '[') {
            temp.clear();
        } else if (ch == ']') {
            if (!temp.empty()) {
                result.push_back(temp);
            }
        } else if (isdigit(ch) || ch == '-') {
            ss.putback(ch);
            ss >> num;
            temp.push_back(num);
        }
    }
    return result;
}

int main() {
    string input;
   
    getline(cin, input);

    // Extract cards
    size_t posCards = input.find("cards=");
    size_t posMoves = input.find("moves=");
    size_t posQuery = input.find("query=");

    string cardsStr = input.substr(posCards + 6, posMoves - posCards - 7);
    string movesStr = input.substr(posMoves + 6, posQuery - posMoves - 7);
    int query = stoi(input.substr(posQuery + 6));

    vector<vector<int>> cards = parse2DVector(cardsStr);
    vector<vector<int>> moves = parse2DVector(movesStr);

    // Find final position of query card
    vector<int> result = findFinalPosition(cards, moves, query);

    // Output final position
    cout << "Output: [" << result[0] << "," << result[1] << "]" << endl;

    return 0;
}