#include <cstdio>
#include <cctype>
const int MAX_N = 1e5, inf = 1<<30;

class Splay {
    static const int n = MAX_N+4, nil = n-1;
    int fa[n], ch[n][2], v[n], sz[n], ptr, &root;

    void set(int x, int d, int y) { fa[ch[x][d] = y] = x; }
    void up(int x) { sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + 1; }
    int type(int x) { return x == ch[fa[x]][1]; }

    int new_node(int c)
    {
        ch[ptr][0] = ch[ptr][1] = nil;
        v[ptr] = c;
        sz[ptr] = 1;
        return ptr++;
    }

    int rot(int x, int d)
    {
        int y = ch[x][d];
        set(fa[x], type(x), y);
        set(x, d, ch[y][d^1]);
        set(y, d^1, x);
        up(x);
        up(y);
    }

    void splay(int x, int p=0)
    {
        int y;
        while ((y = fa[x]) != p) {
            int z = fa[y], t1 = type(x);
            if (z != p) {
                int t2 = type(y);
                if (t1 == t2)
                    rot(z, t2), rot(y, t1);
                else
                    rot(y, t1), rot(z, t2);
            } else
                rot(y, t1);
        }
    }

    int find(int c, int b=0)
    {
        int x = root, y, z;
        while (x != nil) {
            y = x;
            if (v[x] != c && v[x] > c == b) {
                z = x;
                x = ch[x][b^1];
            } else
                x = ch[x][b];
        }
        if (y != z)
            splay(y, z);
        splay(z);
        return z;
    }

    public:

    Splay(): ptr(1), root(ch[0][0])
    {
        sz[nil] = 0;
        set(0, 0, new_node(-inf));
        set(1, 1, new_node(inf));
        up(1);
    }

    void insert(int c)
    {
        int l = find(c), r = ch[l][1], x = new_node(c);
        ch[l][1] = nil;
        set(0, 0, x);
        set(x, 0, l);
        set(x, 1, r);
        up(l);
        up(x);
    }

    void erase(int c)
    {
        int l = find(c), r = ch[l][1];
        while (ch[r][0] != nil)
            r = ch[r][0];
        splay(r, l);
        set(l, 1, ch[r][1]);
        up(l);
    }

    int predecessor(int c)
    {
        return v[find(c)];
    }

    int successor(int c)
    {
        return v[find(c, 1)];
    }

    int rank(int c)
    {
        return sz[ch[find(c)][0]] + 1;
    }

    int kth(int k)
    {
        ++k;
        int x = root;
        while (x != nil) {
            int s = sz[ch[x][0]];
            if (s+1 == k)
                return splay(x), v[x];
            if (s >= k)
                x = ch[x][0];
            else
                k -= s+1, x = ch[x][1];
        }
    }
} T;

template<typename t>
inline void read(t& x)
{
    char c = getchar();
    int sgn = 1;
    x = 0;
    while (!isdigit(c)) {
        sgn = c == '-' ? -1 : 1;
        c = getchar();
    }
    while (isdigit(c)) {
        x = x*10 + c - '0';
        c = getchar();
    }
    x *= sgn;
}

int main()
{
    int n;
    read(n);
    while (n--) {
        int opt, x;
        read(opt), read(x);
        switch (opt) {
            case 1:
                T.insert(x); break;
            case 2:
                T.erase(x); break;
            case 3:
                printf("%d\n", T.rank(x)); break;
            case 4:
                printf("%d\n", T.kth(x)); break;
            case 5:
                printf("%d\n", T.predecessor(x)); break;
            case 6:
                printf("%d\n", T.successor(x));
        }
    }
    return 0;
}