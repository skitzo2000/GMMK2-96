// Side LED Arrays
int side1[] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
int side2[] = {111, 112, 113, 114, 115, 116, 117, 118, 119, 120};
void set_glorious_side_96(char glorious_side, uint8_t r, uint8_t g, uint8_t b){
    uint8_t rgb[3];
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;
    int* this_side;
    if(glorious_side == 'r'){this_side = side1;}
    else {this_side = side2;}
    for(int i = 0; i < 9; i++ ){
        rgb_matrix_set_color(this_side[i], rgb[0], rgb[1], rgb[2]);
    }
}