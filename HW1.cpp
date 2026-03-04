//var 2
template<class T>
T* merge(const T* a, size_t sa, const T* b, size_t sb, T* c) {
    size_t i = 0, j = 0, k = 0;
    while (i < sa && j < sb) {
        if (a[i], b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < sa) c[k++] = a[i++];
    while (j < sb) c[k++] = b[j++];
    return c;
}
