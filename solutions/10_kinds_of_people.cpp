#include <bits/stdc++.h>


/*
 * Equivalence class represents all disjoint sets. Each disjoint set can be found
 * by moving up the tree through parents until the root is found: if the roots are 
 * same between two nodes they exist in the same disjoint set.
 * 
*/
class EqCl {

    private:
        std::unordered_map<int,int> parent;
        std::unordered_map<int,int> root_sizes;

        int compress_to_root(int i) {
            while (parent[i] != i)
                i = parent[i];
            return i;
        }

    public:
        void add_singleton(int i) {
            parent[i] = i;
            root_sizes[i] = 1;
        }

        bool in_same_class(int a, int b) {
            int root_a = compress_to_root(a);
            int root_b = compress_to_root(b);

            return root_a == root_b;
        }

        void merge(int a, int b) {
            int root_a = compress_to_root(a);
            int root_b = compress_to_root(b);

            if (root_a == root_b)
                return;

            if (root_sizes[root_a] > root_sizes[root_b]) {
                parent[root_b] = root_a;
                root_sizes.erase(root_b);
            } else {
                parent[root_a] = root_b;
                root_sizes.erase(root_a);
            }
        }

    
};




int main() {

    int r,c; scanf("%d %d", &r, &c);

    std::vector<std::vector<bool>> grid;

    // Build Equivalence Class
    EqCl eqcl;
    std::string row;
    getline(std::cin, row);
    for (int i = 0; i < r; ++i) {
        getline(std::cin, row);
        std::vector<bool> v;
        for (int j = 0; j < c; ++j) {
            bool coord_val = row[j] - '0';
            v.push_back(coord_val);
            eqcl.add_singleton(i*c + j);

            if (j > 0 && v[j-1] == coord_val) {
                eqcl.merge(i*c+j, i*c+j-1);
            }
            if (i > 0 && grid[i-1][j] == coord_val) {
                eqcl.merge(i*c+j, (i-1)*c+j);
            }
        }
        grid.push_back(v);
    }

    // Handle Queries
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int r1,c1,r2,c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        bool type = grid[r1-1][c1-1];

        if (type != grid[r2-1][c2-1]) {
            std::cout << "neither" << std::endl;
            continue;
        }

        if (eqcl.in_same_class((r1-1)*c + (c1-1), (r2-1)*c + (c2-1))) {
            if (type) 
                std::cout << "decimal" << std::endl;
            else 
                std::cout << "binary" << std::endl;
        } else {
            std::cout << "neither" << std::endl;
        }
        
    }

    return 0;
}