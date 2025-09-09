int bsort(struct student *s, int n) {
    int i;
    struct student temp;
    for(i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if((s+j)->roll > (s+j+1)->roll) {
                temp = *(s+j);
                *(s+j) = *(s+j+1);
                *(s+j+1) = temp;
            }
        }
    }
    return 0;
}