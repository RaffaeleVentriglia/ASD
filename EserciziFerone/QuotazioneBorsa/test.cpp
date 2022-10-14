int search(a[], int in, int fi) {
    if(in+1==fi) {
        return in;
    }
    int med = (in+fi)/2;
    if(a[in] < a[med]) {
        return search(a, in, fi);
    } else {
        return search(a, med, fi);
    }
}
