#include <vector>

struct disjoint_set {
	std::vector<int> parent;

    void init(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

	// u always takes priority over v
    int union_merge(int u, int v) {
        u = find_parent(u);
        v = find_parent(v);
        if (u != v) {
            parent[v] = u;
			flatten(); // remove & call only once after finishing for better perf
        }
        return u;
    }

    void flatten() {
        for (int i = 0; i < parent.size(); i++)
			find_parent(i);
    }

    int find_parent(int x) {
        if (x == parent[x]) return x;
		parent[x] = find_parent(parent[x]);
        return parent[x];
    }

	void print() {
		for (auto &p : parent) printf("%d ", p);
		printf("\n");
	}
};

int main() {
	disjoint_set ds;
	ds.init(6);
	ds.print();
	ds.union_merge(1,2);
	ds.print();
	ds.union_merge(3,4);
	ds.print();
	ds.union_merge(0,5);
	ds.print();
	ds.union_merge(2,3);
	ds.print();

	//ds.union_merge(0,1);
	//ds.union_merge(4,5);
	//ds.print();

	ds.flatten();
	ds.print();
}
