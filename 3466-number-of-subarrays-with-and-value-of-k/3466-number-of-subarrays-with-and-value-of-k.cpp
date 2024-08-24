#define ll int
template<typename Node, typename Update>
struct SegTree {
    vector<Node> tree;
    vector<ll> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a) { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while(s < 2 * n){
            s = s << 1;
        }
        tree.resize(s);
        fill(tree.begin(),tree.end(), Node());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index)  // Never change this
    {
        if (start == end)   {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void update(int start, int end, int index, int query_index, Update &u)  // Never Change this
    {
        if (start == end) {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right) { // Never change this
        if (start > right || end < left) // disjoint
            return Node();
        if (start >= left && end <= right) // complete overlap
            return tree[index];
        int mid = (start + end) / 2;
        // partial overlap
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, ll val) {  // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, index, new_update);
    }
    Node make_query(int left, int right) {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1{
    ll val; // may change
    Node1() { // Identity element
        val = (1<<30)-1;    // may change
    }
    Node1(ll p1) {  // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r) { // Merge two child nodes
        val = (l.val & r.val);  // may change
    }
};

struct Update1 {
    ll val; // may change
    Update1(ll p1) { // Actual Update
        val = p1; // may change
    }
    void apply(Node1 &a) { // apply update to given node
        a.val = (a.val & val); // may change
    }
};













class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long res=0;
        int j=0;
        SegTree<Node1,Update1> sgt(n,nums);
        for(int i=0;i<n;i++)
        {
           int ind1 = -1, ind2 = -1;
           int  l = i , h = n-1;
           while(l<=h)
           {
             int mid = (l+h)/2;
             int val = sgt.make_query(i,mid).val;
             if(val==k) {
                ind1=mid;
                l=mid+1;
             }
             else if(val<k){
                h=mid-1;
             }
             else l=mid+1;
           }
           if(ind1==-1) continue;
            l = i , h = n-1;
           while(l<=h)
           {
             int mid = (l+h)/2;
             int val=sgt.make_query(i,mid).val;
             if(val==k) {
                ind2=mid;
                h=mid-1;
             }
             else if(val<k){
                h=mid-1;
             }
             else l=mid+1;
           }

           res+=(ind1-ind2+1);


        }
        return res;
    }
};