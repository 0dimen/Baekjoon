#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = a[start];
    }else{
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}

void update(vector <long long> &tree, int node, int start, int end, int index, long long diff){
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if(start != end){
        update(tree,node*2, start, (start+end)/2, index, diff);
        update(tree,node*2+1, (start+end)/2+1, end, index, diff);
    }
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right){
    if(left>end || right < start){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, left, right)+ sum (tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    vector<long long> a(n);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));
    vector<long long> tree(tree_size);
    m += k;
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
    }
    in
}