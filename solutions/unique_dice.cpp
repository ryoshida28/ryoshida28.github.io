#include <bits/stdc++.h>

struct HashArray;

typedef std::array<int,6> Die;
typedef std::unordered_set<Die, HashArray> Orientations;

struct HashArray {
public:
    size_t operator() (const Die& d) const {
        std::hash<int> h;
        int hashed_val = 0;
        for (int i = 0; i < 6; ++i) {
            hashed_val = hashed_val * h(d[i])+7;
        }
        return hashed_val;
    }

};

struct HashOrientation {
    public:
    size_t operator() (const Orientations& o) const {
        HashArray h;
        int hashed_val = 1;
        const Die& d = *o.begin();
        for (int i = 0; i < 6; ++i) {
            hashed_val *= d[i];
        }
        return hashed_val;
    }
};

struct EqualOrientation {
    public:
    bool operator()(const Orientations& lhs, const Orientations& rhs) const {
        return rhs.count(*(lhs.begin()));
    }
};


int main() {

    int n; scanf("%d", &n);

    std::unordered_map<Orientations,int,HashOrientation,EqualOrientation> counts;
    for (int i = 0; i < n; ++i) {
        int top, bottom, front, back, left, right;
        scanf("%d %d %d %d %d %d", &top, &bottom, &front, &back, &left, &right);

        Die d ({top,bottom,front,back,left,right});
        Orientations o({d});

        if (counts.count(o)) {
            ++counts[o];
        } else {
            o.insert(d);
            o.insert(Die({top,bottom,back,front,right,left}));
            o.insert(Die({top,bottom,left,right,back,front}));
            o.insert(Die({top,bottom,right,left,front,back}));

            o.insert(Die({bottom,top,front,back,right,left}));
            o.insert(Die({bottom,top,back,front,left,right}));
            o.insert(Die({bottom,top,left,right,front,back}));
            o.insert(Die({bottom,top,right,left,back,front}));


            o.insert(Die({front,back,top,bottom,right,left}));
            o.insert(Die({front,back,bottom,top,left,right}));
            o.insert(Die({front,back,left,right,top,bottom}));
            o.insert(Die({front,back,right,left,bottom,top}));

            o.insert(Die({back,front,top,bottom,left,right}));
            o.insert(Die({back,front,bottom,top,right,left}));
            o.insert(Die({back,front,left,right,bottom,top}));
            o.insert(Die({back,front,right,left,top,bottom}));


            o.insert(Die({left,right,top,bottom,front,back}));
            o.insert(Die({left,right,bottom,top,back,front}));
            o.insert(Die({left,right,front,back,bottom,top}));
            o.insert(Die({left,right,back,front,top,bottom}));

            o.insert(Die({right,left,top,bottom,back,front}));
            o.insert(Die({right,left,bottom,top,front,back}));
            o.insert(Die({right,left,front,back,top,bottom}));
            o.insert(Die({right,left,back,front,bottom,top}));

            counts[o] = 1;
        }
    }

    int max = 0;
    for (const auto& kv : counts)
        max = std::max(max, kv.second);
    std::cout << max << std::endl;


    return 0;
}