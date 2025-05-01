int playerimage[96];


int Key[256];
int SelectNum;

int MOVECHARCTOR = 0;
int MOVECHARCTOr = 0;

int omake_Select = 0;
int omup;
int player_x = 0, player_y = 0, player_f[4] = { 1,4,7,10 }, player_walk;
int player_up[2] = { 9,11 }, playup = 0;
int player_down[2] = { 0,2 }, playdown = 0;
int player_right[2] = { 6,8 }, playright = 0;
int player_left[2] = { 3,5 }, playleft = 0;
int upct = 0, downct = 0, rightct = 0, leftct = 0;
int playerct = 0;
int player_face_num = 0;
bool player_face_flag;
