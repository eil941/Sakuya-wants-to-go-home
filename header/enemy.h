//	enemy date
int enemy_001[100];
int enemy_002[100];
int enemy_003[100];
int merin;
struct enemy_status {
    int HP, ATK, DEF, POINT;
};
enemy_status enemy_date[110] = { 
 //HP ATK DEF POINT
    {50,60,25,2},
    //15
    {85,55,10,1},   // 1 P2
    {60,75,15,1},   // 2 P2
    {40,60,50,1},   // 3 P3
    //20
    {90,175,35,1}, // 6 P8 (25)
    {150,110,50,1}, // 5 P6
    {100,80,40,1}, // 4 P4
    //28~30
    {120,120,50,1},  // 7 28
    {100,105,75,1},   //  29
    {100,120,80,1}, //  30
    //31~35
    {110,250,0,0},   //  36 P13
    {160,120,70,0},  //  35 P15
    {155,150,75,0},   //  38 P18
    //boss(50)
    {300,300,70,30}
};
unsigned int enemy_move[100] = {};
                         //enemy001                enemy003
int enemy_graph[100] = { 24,27,30,33,72,75,78,81,  27,30,33,72 };
int enemy_move_speed[100] = {};


bool chflag;
void chdiff() {
    if (Key[KEY_INPUT_Z] == 1) {
        for (int i = 1; i < 12; i++) {
            enemy_date[i].POINT = drop_point[diffnum];
            if (i >= 10 && enemy_date[i].POINT > 0) enemy_date[i].POINT--;
        }
        chflag = true;
    }
}