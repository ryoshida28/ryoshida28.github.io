/*
 * Azulejos: https://open.kattis.com/problems/azulejos
 * 
 * Problem Setup: Given two sets of paired numbers (p_i,h_i) find an ordering
 *      for the sets in which all p are in non-decreasing order and the h of
 *      the first set of pairs is greater than h of the second set of pairs.
 *      Output the ordering by the indexes (starting at 1) the pairs as given
 *      in the input. Output 'impossible' if there is no solution.
 * 
 * Example:
 *  Input:
 *      4
 *      3 2 1 2
 *      2 3 4 3
 *      2 1 2 1
 *      2 2 1 3
 *  Output:
 *      3 2 4 1
 *      4 2 1 3
 * 
 * ---------------------------------------------------------------------------
 * Solution: Greedy
 * 
 *      Iterate through each (p,h) pair for each set sorted by p. This will
 *      satisfy the first constraint of the output having p in non-decreasing
 *      order. At each price (does not have to be same between sets) find
 *      which set has more pairs with that specific p. Iterate over the pairs
 *      in that set for that specific p in order from greates h to smalles h.
 *      Find the pair in the other set that is either greater than or less
 *      than (depending if it is the front or back row) the height of the pair
 *      at the location of the iterator. Add the indexes of the two pairs to
 *      the output. We can greedily assume that this must be correct. 
 * 
 *      Because we must iterate over sorted collections and remove from
 *      sorted collections it is most efficient to do so with Binary Search
 *      Trees. C++ provides a Red-Black Tree implementation in its STL with
 *      the std::set, std::multiset, std::map, std::multimap. In this instance
 *      std::map and std::multimap are most convenient. 
 */



#include <bits/stdc++.h>

typedef int Price;
typedef int Height;
typedef int Index;

typedef std::multimap<Height, Index> HeightTree;     // The HeightTree stores all the heights in a BST allowing for inorder iteration and
                                                // O(logN) removal

typedef std::map<Price, HeightTree> PriceTree;  // Note: may potentially change to vector<pair<Price, HeightTree>> and sort by Price
                                                // The PriceTree maps a price to a height tree allowing for the sorting of prices

int main() {

    int n; std::scanf("%d", &n);

    std::string price1, height1, price2, height2;
    std::getline(std::cin,price1);  // Clear input buffer to end of line
    std::getline(std::cin,price1);
    std::getline(std::cin,height1);
    std::getline(std::cin,price2);
    std::getline(std::cin,height2);

    std::istringstream P1(price1), H1(height1), P2(price2), H2(height2);

    PriceTree back, front;

    for (int i = 1; i <= n; ++i) {

        int back_price; P1 >> back_price;
        int back_height; H1 >> back_height;
        back[back_price].insert(std::pair<Height, Index>(back_height, i));

        int front_price; P2 >> front_price;
        int front_height; H2 >> front_height;
        front[front_price].insert(std::pair<Height, Index>(front_height, i));
    }


    PriceTree::iterator back_it = back.begin();
    PriceTree::iterator front_it = front.begin();

    PriceTree::iterator back_stop = back.end();
    PriceTree::iterator front_stop = front.end();

    

    bool impossible = false;
    std::vector<int> back_indexes;
    std::vector<int> front_indexes;
    while (back_it != back_stop && front_it != front_stop) {


        if (back_it->second.size() > front_it->second.size()) {
            HeightTree::reverse_iterator front_heights = front_it->second.rbegin();
            HeightTree::reverse_iterator front_heights_stop = front_it->second.rend();

            for (; front_heights != front_heights_stop; ++front_heights) {
                std::pair<Height,Index> front_azulejos  = *front_heights;
                HeightTree::iterator back_azulejos_it = back_it->second.upper_bound(front_azulejos.first);

                if (back_azulejos_it != back_it->second.end()) {
                    std::pair<Height,Index> back_azulejos = *back_azulejos_it;
                    back_indexes.push_back(back_azulejos.second);
                    front_indexes.push_back(front_azulejos.second);
                    back_it->second.erase(back_azulejos_it);            // Remove node
                } else {
                    impossible = true;
                    break;
                }
            }

            ++front_it;
        } else {
            HeightTree::reverse_iterator back_heights = back_it->second.rbegin();
            HeightTree::reverse_iterator back_heights_stop = back_it->second.rend();

            for (; back_heights != back_heights_stop; ++back_heights) {
                std::pair<Height, Index> back_azulejos = *back_heights;
                HeightTree::iterator front_azulejos_it = --front_it->second.lower_bound(back_azulejos.first);

                if (front_azulejos_it != front_it->second.end() && back_azulejos.first > front_azulejos_it->first) {
                    std::pair<Height,Index> front_azulejos = *front_azulejos_it;
                    back_indexes.push_back(back_azulejos.second);
                    front_indexes.push_back(front_azulejos.second);
                    front_it->second.erase(front_azulejos_it);
                } else {
                    impossible = true;
                    break;
                }
            }

            ++back_it;
        }

        if (impossible)
            break;


        if (back_it->second.empty()) {
            ++back_it;
        }
        
    }


    if (impossible) {
        std::cout << "impossible" << std::endl;
    } else {
        std::ostringstream backss, frontss;
        backss << back_indexes[0];
        frontss << front_indexes[0];
        for (int i = 1; i < n; ++i) {
            backss << ' ' << back_indexes[i];
            frontss << ' ' << front_indexes[i];
        }
        std::cout << backss.str() << std::endl;
        std::cout << frontss.str() << std::endl;
    }

    return 0;
}