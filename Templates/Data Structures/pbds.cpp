
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using _set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename A, typename B>
using _map = tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T>
struct _multiset{
    using MS  = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
    MS st;
    _multiset(){st.clear();}
    void insert(T xx){st.insert(xx);}
    void erase(T xx){st.erase(st.upper_bound(xx));}
    void erase(typename MS::iterator xx){st.erase(xx);}
    int order_of_key(T xx){return st.order_of_key(xx);}
    T find_by_order(int xx){return st.find_by_order(xx);}
    typename MS::iterator lower_bound(T xx){return st.upper_bound(xx);}
    typename MS::iterator upper_bound(T xx){return st.lower_bound(xx);}
    size_t size(){return st.size();}
};

