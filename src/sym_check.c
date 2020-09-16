void sym_check(int* pos, table_t* t) {
    for (int i = 0; i < 4; i++) {
        rotate(pos);
        if (check(pos,t) != 0ULL) {
            return;
        }
    } 
    flip(pos);
    if (check(pos,t) != 0ULL) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        rotate(pos);
        if (check(pos,t) != 0ULL) {
            return;
        }
    } 
    flip(pos);
    if (check(pos,t) != 0ULL) {
        return;
    }
}