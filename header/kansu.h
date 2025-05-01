#include"./hensu.h"

int haikei_001_01;
int haikei_001_02;
int haikei_chippu;
int PATYURI;
int patye[15];

int clear_text;
int clear_y;
int kouma;
int kouma_map;
int pcnt;

int bkouma;
int bsakuya;

bool pauseflag = false;

int move_player_speed = 1;

int clear = 0;

// 0:money 1:HP 2:attck 3:defens 4: levelsum 5:�`:special 
int player_date[10] = { {0},{450},{50},{50},{0},{0} };
int leveltime = 0;

typedef struct {
    int x, y;       // ���W�i�[�p�ϐ�
    char name[128]; // ���ږ��i�[�p�ϐ�
    int r, g, b;    // �F�i�[�p�ϐ�
} MenuElement_t;
MenuElement_t Menu[6] = {
 {  80, 180, "�Q�[���X�^�[�g",0,0,255 }, // �^�O�̒��g�̏��ԂŊi�[�����Bx��80���Ay��100���Aname��"�Q�[���X�^�[�g"��
 { 100, 230, "���܂�" ,255,255,255},
 /*{ 100, 200, "�w���v" ,255,255,255},*/
 { 100, 280, "�ݒ�",255,255,255 },
 /*{ 100, 300, "�R���t�B�O",255,255,255 },*/
 { 100, 330, "�Q�[���I��" ,255,255,255},
};

int gpUpdateKey() {
    char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
    GetHitKeyStateAll(tmpKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�
    for (int i = 0; i < 256; i++) {
        if (tmpKey[i] != 0) { // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
            Key[i]++;     // ���Z
        }
        else {              // ������Ă��Ȃ����
            Key[i] = 0;   // 0�ɂ���
        }
    }
    return 0;
}
void MENU() {
    if (Key[KEY_INPUT_DOWN] == 1) { // ���L�[�������ꂽ�u�Ԃ�������

        SelectNum = (SelectNum + 1) % 4; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)

        for (int i = 0; i < 4; i++) {              // ���j���[���ڐ��ł���5���[�v����
            if (i == SelectNum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
                Menu[i].x = 80; // ���W��80�ɂ���
                Menu[i].r = 0;
                Menu[i].g = 0;
                Menu[i].b = 255;
            }
            else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
                Menu[i].x = 100;// ���W��100�ɂ���
                Menu[i].r = 255;
                Menu[i].g = 255;
                Menu[i].b = 255;
            }
        }
    }
    //��Ɠ���
    if (Key[KEY_INPUT_UP] == 1) {

        SelectNum = (SelectNum + 3) % 4;

        for (int i = 0; i < 4; i++) {
            if (i == SelectNum) {
                Menu[i].x = 80;
                Menu[i].r = 0;
                Menu[i].g = 0;
                Menu[i].b = 255;
            }
            else {
                Menu[i].x = 100;
                Menu[i].r = 255;
                Menu[i].g = 255;
                Menu[i].b = 255;
            }
        }
    }
    for (int i = 0; i < 4; i++) { // ���j���[���ڂ�`��
        DrawFormatString(Menu[i].x, Menu[i].y, GetColor(Menu[i].r, Menu[i].g, Menu[i].b), Menu[i].name);
        //DrawFormatString(0, 0, GetColor(255, 255, 255), "SelectNum  : %d", SelectNum);
    }
}

void MOVECHARCTor() {
    MOVECHARCTOr++;
    if (MOVECHARCTOr % 10 == 0) {
        MOVECHARCTOR++;
    }
    MOVECHARCTOR = (MOVECHARCTOR % 3) + 3;
   
}

int omake_num = 6;
MenuElement_t omake_menu[100] = {
{80,50 ,"SATGE 0",0,0,255},
{100,100 ,"SATGE 1",255,255,255},
{100,150 ,"SATGE 2",255,255,255},
{100,200 ,"SATGE 3",255,255,255},
{100,250 ,"SATGE 4",255,255,255},
{100,300 ,"SATGE 5",255,255,255},
{100,350 ,"�߂�",255,255,255}/*,
{100,400 ,"SATGE 8",255,255,255},
{100,450 ,"SATGE 9",255,255,255},
{100,500 ,"SATGE 10",255,255,255},
{100,0 ,"SATGE 11",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},
{100,0 ,"�f�[�^����",255,255,255},*/
};//184
void omake__MENU() {
    if (Key[KEY_INPUT_DOWN] == 1) { // ���L�[�������ꂽ�u�Ԃ�������

        omake_Select = (omake_Select + 1) % 7; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)

        for (int i = 0; i < 7; i++) {              // ���j���[���ڐ��ł���5���[�v����
            if (i == omake_Select) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
                omake_menu[i].x = 80; // ���W��80�ɂ���
                omake_menu[i].r = 0;
                omake_menu[i].g = 0;
                omake_menu[i].b = 255;
            }
            else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
                omake_menu[i].x = 100;// ���W��100�ɂ���
                omake_menu[i].x = 100;
                omake_menu[i].r = 255;
                omake_menu[i].g = 255;
                omake_menu[i].b = 255;
            }
        }
    }
    //��Ɠ���
    if (Key[KEY_INPUT_UP] == 1) {

        omake_Select = (omake_Select + 6) % 7;

        for (int i = 0; i < 7; i++) {
            if (i == omake_Select) {
                omake_menu[i].x = 80; // ���W��80�ɂ���
                omake_menu[i].r = 0;
                omake_menu[i].g = 0;
                omake_menu[i].b = 255;
            }
            else {
                omake_menu[i].x = 100;// ���W��100�ɂ���
                omake_menu[i].r = 255;
                omake_menu[i].g = 255;
                omake_menu[i].b = 255;
            }
        }
    }
    for (int i = 0; i < 7; i++) { // ���j���[���ڂ�`��
        DrawFormatString(omake_menu[i].x, omake_menu[i].y, GetColor(omake_menu[i].r, omake_menu[i].g, omake_menu[i].b), omake_menu[i].name);
    }
}
/*void omake_MENU() {
    if (Key[KEY_INPUT_DOWN] == 1) { // ���L�[�������ꂽ�u�Ԃ�������
        if (omake_Select != 99) {
            omake_Select = (omake_Select + 1) % 100; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)
            for (int i = 0 + omup; i < 10 + omup; i++) {              // ���j���[���ڐ��ł���10���[�v����
                if (i == omake_Select) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
                    omake_menu[i].x = 80; // ���W��80�ɂ���
                    omake_menu[i].r = 0;
                    omake_menu[i].g = 0;
                    omake_menu[i].b = 255;
                }
                else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
                    omake_menu[i].x = 100;// ���W��100�ɂ���
                    omake_menu[i].r = 255;
                    omake_menu[i].g = 255;
                    omake_menu[i].b = 255;
                }
            }
            if (omake_menu[omake_Select].y == 450) {
                omup++;
                int nuM = 50;
                for (int l = 0 + omup; l < 10 + omup; l++) {
                    omake_menu[l].y = nuM;
                    nuM += 50;
                }
            }
        }
    }
    //��Ɠ���
    if (Key[KEY_INPUT_UP] == 1) {
        if (omake_Select != 0) {
            omake_Select = (omake_Select + 99) % 100;
            for (int i = 0 + omup; i < 10 + omup; i++) {
                if (i == omake_Select) {
                    omake_menu[i].x = 80;
                    omake_menu[i].r = 0;
                    omake_menu[i].g = 0;
                    omake_menu[i].b = 255;
                }
                else {
                    omake_menu[i].x = 100;
                    omake_menu[i].r = 255;
                    omake_menu[i].g = 255;
                    omake_menu[i].b = 255;
                }
                if (omake_menu[omake_Select].y == 50 && omake_Select != 0) {
                    omup--;
                    int nuM = 50;
                    for (int l = 0 + omup; l < 10 + omup; l++) {
                        omake_menu[l].y = nuM;
                        nuM += 50;
                    }
                }
            }
        }
    }
    for (int k = omup; k < 10 + omup; k++) {
        DrawFormatString(omake_menu[k].x, omake_menu[k].y, GetColor(omake_menu[k].r, omake_menu[k].g, omake_menu[k].b), omake_menu[k].name);
        //DrawFormatString(0, 0, GetColor(255, 255, 255), "omake_Select  : %d", omake_Select);
    }
}*/
int old_player_x, old_player_y;
void MOVE() {
    player_face_flag = false;
    old_player_x = player_x;
    old_player_y = player_y;
    if (CheckHitKey(KEY_INPUT_UP)) {
        if (CheckHitKey(KEY_INPUT_LSHIFT)) {
            player_x -= move_player_speed;
            upct++;
        }
        player_x -= move_player_speed;
        player_walk = player_up[playup % 2];
        upct++;
        player_face_flag = true;
        player_face_num = 3;
        if (upct % 20 < upct) playup++, upct = 0;
    }
    if (CheckHitKey(KEY_INPUT_DOWN)) {
        if (CheckHitKey(KEY_INPUT_LSHIFT)) {
            player_x += move_player_speed;
            downct++;
        }
        player_x += move_player_speed;
        player_walk = player_down[playdown % 2];
        downct++;
        player_face_flag = true;
        player_face_num = 0;
        if (downct % 20 < downct) playdown++, downct = 0;
    }
    if (CheckHitKey(KEY_INPUT_RIGHT)) {
        if (CheckHitKey(KEY_INPUT_LSHIFT)) {
            player_y += move_player_speed;
            rightct++;
        }
        player_y += move_player_speed;
        player_walk = player_right[playright % 2];
        rightct++;
        player_face_flag = true;
        player_face_num = 2;
        if (rightct % 20 < rightct) playright++, rightct = 0;
    }
    if (CheckHitKey(KEY_INPUT_LEFT)) {
        if (CheckHitKey(KEY_INPUT_LSHIFT)) {
            player_y -= move_player_speed;
            leftct++;
        }
        player_y -= move_player_speed;
        player_walk = player_left[playleft % 2];
        leftct++;
        player_face_num = 1;
        player_face_flag = true;
        if (leftct % 20 < leftct) playleft++, leftct = 0;
    }
    if (player_face_flag == false) {
        player_walk = player_f[player_face_num];
    }
    if (CheckHitKey(KEY_INPUT_RIGHT) && CheckHitKey(KEY_INPUT_LEFT)) {
        if (CheckHitKey(KEY_INPUT_UP)) {
            player_walk = player_up[playup % 2];
            upct++;
            player_face_flag = true;
            player_face_num = 3;
            if (upct % 20 == 0) playup++;
        }
        if (CheckHitKey(KEY_INPUT_DOWN)) {
            player_walk = player_down[playdown % 2];
            downct++;
            player_face_flag = true;
            player_face_num = 0;
            if (downct % 20 == 0) playdown++;
        }
    }
    DrawGraph(player_y - 30 + (30 - 24), player_x - 30 + (30 - 30), playerimage[player_walk], true);
}
void FLAME() {
    //if (player_y < 0) player_y = 0;
    if (player_x > 480) player_x = 480;
    if (player_y > 640) player_y = 640;
    if (player_x < 0) player_x = 0;
    if (player_y < 0) player_y = 0;
}

//pause
MenuElement_t PAUSE[2] = {
 {250,250,"�Q�[���ɖ߂�",0,0,255},
 {270,300,"�^�C�g���ɖ߂�",255,255,255}
};
int pauseNum;

//SE
int hit_se;
int check_se;

bool se_flag = true;


//�ꎞ��~
void pause() {
    pauseNum = 0;
    PAUSE[0].x = 250;
    PAUSE[0].r = 0;
    PAUSE[0].g = 0;
    PAUSE[0].b = 255;
    PAUSE[1].x = 270;
    PAUSE[1].r = 255;
    PAUSE[1].g = 255;
    PAUSE[1].b = 255;
    if (CheckHitKey(KEY_INPUT_ESCAPE)) {

        //PlaySoundMem(pause_se, DX_PLAYTYPE_BACK);
        
        while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
            //SE�ǉ�
            if (se_flag && (Key[KEY_INPUT_UP] == 1 || Key[KEY_INPUT_DOWN] == 1)) PlaySoundMem(hit_se, DX_PLAYTYPE_BACK);

            //�I�����
            if (Key[KEY_INPUT_DOWN] == 1) { // ���L�[�������ꂽ�u�Ԃ�������

                pauseNum = (pauseNum + 1) % 2; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)

                for (int i = 0; i < 2; i++) {              // ���j���[���ڐ��ł���2���[�v����
                    if (i == pauseNum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
                        PAUSE[i].x = 250; // ���W��280�ɂ���
                        PAUSE[i].r = 0;
                        PAUSE[i].g = 0;
                        PAUSE[i].b = 255;
                    }
                    else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
                        PAUSE[i].x = 270;// ���W��300�ɂ���
                        PAUSE[i].r = 255;
                        PAUSE[i].g = 255;
                        PAUSE[i].b = 255;
                    }
                }
            }
            //��Ɠ���
            if (Key[KEY_INPUT_UP] == 1) {

                pauseNum = (pauseNum + 1) % 2;

                for (int i = 0; i < 2; i++) {
                    if (i == pauseNum) {
                        PAUSE[i].x = 250;
                        PAUSE[i].r = 0;
                        PAUSE[i].g = 0;
                        PAUSE[i].b = 255;
                    }
                    else {
                        PAUSE[i].x = 270;
                        PAUSE[i].r = 255;
                        PAUSE[i].g = 255;
                        PAUSE[i].b = 255;
                    }
                }
            }
            for (int i = 0; i < 2; i++) { // ���j���[���ڂ�`��
                DrawFormatString(PAUSE[i].x, PAUSE[i].y, GetColor(PAUSE[i].r, PAUSE[i].g, PAUSE[i].b), PAUSE[i].name);
            }
            if (CheckHitKey(KEY_INPUT_Z)) {
                if (se_flag == true) PlaySoundMem(check_se, DX_PLAYTYPE_BACK);
                //�Q�[���߂�
                if (pauseNum == 0) {
                    break;
                }
                //�^�C�g���ɖ߂�
                else if (pauseNum == 1) {
                    pauseflag = true;
                    break;
                }
            }

            DrawString(250, 100, "�ꎞ��~", GetColor(0, 0, 255), false);
            MOVECHARCTor();
            DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
            //�^�C�g���ɖ߂�
        }

    }
}
MenuElement_t SHOP[10] = {
 {400,300,"�̗�",255,255,255},
 {400,325,"�U����",255,255,255},
 {400,350,"�h���",255,255,255},
 //{400,375,"����",255,255,255},
 {400,400,"�߂�",255,255,255},
};
int shop_num;
char shop_string[10][128] = {
    {"���Ȃ��𖂖@�Ŏ菕�����Ă�����"},
    {"HP��%d�񕜂��閂�@�������Ă����� "},
    {"�U���͂�%d�A�b�v���@�������Ă����� "},
    {"�h��͂�%d�A�b�v���@�������Ă����� "},
    //{"���� %d"},
    {"����@�����s���́H"},
    {"�|�C���g������Ȃ����"},
};
//�V���b�v�֌W
//0:HP  1:attack 2:defense   3:special
int statusup[4] = { 150,3,3 }; //150,3,3
bool shopselect;
//�w�����������J�E���g 0: HP 1: attack 2:defense
int shopdate[4] = {0,0,0,0};
bool shop_back = false, buy = false;
int key_sum;

void shop() {
    //�L�[�̓��͏�Ԃ𓾂�
    key_sum = 0;
    //SE�ǉ�
    if (se_flag==true) {
        if (Key[KEY_INPUT_UP] == 1 || Key[KEY_INPUT_DOWN] == 1) PlaySoundMem(hit_se, DX_PLAYTYPE_BACK);
        if (Key[KEY_INPUT_Z] == 1) PlaySoundMem(check_se, DX_PLAYTYPE_BACK);
    }
    if (Key[KEY_INPUT_DOWN] == 1) { // ���L�[�������ꂽ�u�Ԃ�������

        shop_num = (shop_num + 1) % 4; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)
        buy = false;
        for (int i = 0; i < 4; i++) {              // ���j���[���ڐ��ł���4���[�v����
            if (i == shop_num) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
                SHOP[i].x = 380; // ���W��380�ɂ���
                SHOP[i].r = 0;
                SHOP[i].g = 0;
                SHOP[i].b = 255;
            }
            else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
                SHOP[i].x = 400;// ���W��400�ɂ���
                SHOP[i].r = 255;
                SHOP[i].g = 255;
                SHOP[i].b = 255;
            }
        }
    }
    //��Ɠ���
    if (Key[KEY_INPUT_UP] == 1) {
        buy = false;
        if (shop_num == -1) shop_num = 0;
        shop_num = (shop_num + 3) % 4;

        for (int i = 0; i < 4; i++) {
            if (i == shop_num) {
                SHOP[i].x = 380;
                SHOP[i].r = 0;
                SHOP[i].g = 0;
                SHOP[i].b = 255;
            }
            else {
                SHOP[i].x = 400;
                SHOP[i].r = 255;
                SHOP[i].g = 255;
                SHOP[i].b = 255;

            }
        }
    }
    for (int i = 0; i < 4; i++) { // ���j���[���ڂ�`��
        DrawFormatString(SHOP[i].x, SHOP[i].y, GetColor(SHOP[i].r, SHOP[i].g, SHOP[i].b), SHOP[i].name);
    }
    //���̕\���@����   
    shopselect = true;
    for (int i = 0; i < 4; i++) {
        if (SHOP[i].x == 380) {
            //DrawFormatString(300, 20, GetColor(255, 255, 255), shop_string[i + 1], player_date[i + 1]);

            //�����̕���\�����Ȃ�
            shopselect = false;
            if (Key[KEY_INPUT_Z] == 1) {
                if (shop_num != 3) {
                    //point������Ȃ�
                    if (player_date[0] - ((shopdate[i + 1] + 0) * 3 + 10) < 0) {
                        buy = true;
                    }
                    //point�����肽
                    else {
                        if (i == 0) player_date[i + 1] += statusup[0];
                        else player_date[i + 1] += statusup[1];
                        player_date[0] -= (shopdate[i + 1] * 3 + 10);
                        shopdate[i + 1] += 1;
                    }
                }
                else shop_back = true;
            }
            if (buy == false) {
                DrawFormatString(300, 40, GetColor(255, 255, 255), shop_string[i + 1], statusup[i]);
                if (shop_num != 3) DrawFormatString(300, 65, GetColor(255, 255, 255), "�K�v�ȃ|�C���g��%d��", shopdate[i + 1] * 3 + 10);
            }
            else DrawFormatString(300, 40, GetColor(255, 255, 255), shop_string[5]);
        }
    }
    //DrawFormatString(20, 0, GetColor(255, 255, 255), "shop_num : %d", shop_num);
    if (shopselect == true) DrawFormatString(300, 40, GetColor(255, 255, 255), shop_string[0]);
    //���݂�point,�X�e�[�^�X��\��
    DrawFormatString(450, 100+50, GetColor(195, 195, 195), "HP         %d", player_date[0 + 1]);
    DrawFormatString(450, 160+50, GetColor(195, 195, 195), "ATTACK     %d", player_date[1 + 1]);
    DrawFormatString(450, 220+50, GetColor(195, 195, 195), "DEFENSE    %d", player_date[2 + 1]);
    DrawFormatString(450, 400+50, GetColor(250, 244, 29), "POINT      %d", player_date[0]);
    MOVECHARCTor();
    DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);

}

//���̃��x���A�b�v�܂�
int nextlevel = 10;

//�X�e�[�^�X�\��
void player_status(){
    DrawFormatString(450, 100 + 50, GetColor(195, 195, 195), "HP           %d", player_date[0 + 1]);
    DrawFormatString(450, 160 + 50, GetColor(195, 195, 195), "ATTACK       %d", player_date[1 + 1]);
    DrawFormatString(450, 220 + 50, GetColor(195, 195, 195), "DEFENSE      %d", player_date[2 + 1]);
    DrawFormatString(450, 280 + 50, GetColor(195, 195, 195), "NEXT LEVEL   %d", nextlevel - player_date[4]);
    DrawFormatString(450, 400 + 50, GetColor(250, 244, 29), "POINT        %d", player_date[0]);
}

//�퓬�֌W
MenuElement_t fight[2] = {
    {300,360,"�퓬�J�n!!",0,0,255},
    {310,390,"��߂�",0,0,0}
};
int fightnum = 0;
void fight_select() {
    if (Key[KEY_INPUT_DOWN] == 1) { // ���L�[�������ꂽ�u�Ԃ�������

        fightnum = (fightnum + 1) % 2; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)

        for (int i = 0; i < 2; i++) {              // ���j���[���ڐ��ł���2���[�v����
            if (i == fightnum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
                fight[i].x = 300; // ���W��300�ɂ���
                fight[i].r = 0;
                fight[i].g = 0;
                fight[i].b = 255;
            }
            else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
                fight[i].x = 310;// ���W��310�ɂ���
                fight[i].r = 0;
                fight[i].g = 0;
                fight[i].b = 0;
            }
        }
    }
    //��Ɠ���
    if (Key[KEY_INPUT_UP] == 1) {

        fightnum = (fightnum + 1) % 2;

        for (int i = 0; i < 2; i++) {
            if (i == fightnum) {
                fight[i].x = 300;
                fight[i].r = 0;
                fight[i].g = 0;
                fight[i].b = 255;
            }
            else {
                fight[i].x = 310;
                fight[i].r = 0;
                fight[i].g = 0;
                fight[i].b = 0;
            }
        }
    }
    for (int i = 0; i < 2; i++) { // ���j���[���ڂ�`��
        DrawFormatString(fight[i].x, fight[i].y, GetColor(fight[i].r, fight[i].g, fight[i].b), fight[i].name);
    }
}

MenuElement_t game[2]{
    {320,370,"�����x��",0,0,255},
    {350,400,"�^�C�g���ɖ߂�",255,255,255 }
};
int gamemenu_sum;
void gamemenu() {
    if (Key[KEY_INPUT_DOWN] == 1 || Key[KEY_INPUT_UP] == 1) { // �L�[�������ꂽ�u�Ԃ�������

        gamemenu_sum = (gamemenu_sum + 1) % 2; // ���݂̑I�����ڂ�����炷(���[�v����)

        for (int i = 0; i < 2; i++) {              // ���j���[���ڐ��ł���2���[�v����
            if (i == gamemenu_sum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
                game[i].x = 320; // ���W��320�ɂ���
                game[i].r = 0;
                game[i].g = 0;
                game[i].b = 255;
            }
            else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
                game[i].x = 350;// ���W��350�ɂ���
                game[i].r = 255;
                game[i].g = 255;
                game[i].b = 255;
            }
        }
    }
    for (int i = 0; i < 2; i++) { // ���j���[���ڂ�`��
        DrawFormatString(game[i].x, game[i].y, GetColor(game[i].r, game[i].g, game[i].b), game[i].name);
    }
}

int levelup[13];
void levelupload_white() {
    levelup[0] = LoadGraph("./haikei/LEVELUP/white/edit/levelup01_white.bmp");
    levelup[1] = LoadGraph("./haikei/LEVELUP/white/edit/levelup02_white.bmp");
    levelup[2] = LoadGraph("./haikei/LEVELUP/white/edit/levelup03_white.bmp");
    levelup[3] = LoadGraph("./haikei/LEVELUP/white/edit/levelup04_white.bmp");
    levelup[4] = LoadGraph("./haikei/LEVELUP/white/edit/levelup05_white.bmp");
    levelup[5] = LoadGraph("./haikei/LEVELUP/white/edit/levelup06_white.bmp");
    levelup[6] = LoadGraph("./haikei/LEVELUP/white/edit/levelup07_white.bmp");
    levelup[7] = LoadGraph("./haikei/LEVELUP/white/edit/levelup08_white.bmp");
    levelup[8] = LoadGraph("./haikei/LEVELUP/white/edit/levelup09_white.bmp");
    levelup[9] = LoadGraph("./haikei/LEVELUP/white/edit/levelup10_white.bmp");
    levelup[10] = LoadGraph("./haikei/LEVELUP/white/edit/levelup11_white.bmp");
    levelup[11] = LoadGraph("./haikei/LEVELUP/white/edit/levelup12_white.bmp");
    levelup[12] = LoadGraph("./haikei/LEVELUP/white/edit/levelup13_white.bmp");
}
int levelup_black[15];
void levelupload_black() {
    levelup_black[0] = LoadGraph("./haikei/LEVELUP/black/edit/levelup01.bmp");
    levelup_black[1] = LoadGraph("./haikei/LEVELUP/black/edit/levelup02.bmp");
    levelup_black[2] = LoadGraph("./haikei/LEVELUP/black/edit/levelup03.bmp");
    levelup_black[3] = LoadGraph("./haikei/LEVELUP/black/edit/levelup04.bmp");
    levelup_black[4] = LoadGraph("./haikei/LEVELUP/black/edit/levelup05.bmp");
    levelup_black[5] = LoadGraph("./haikei/LEVELUP/black/edit/levelup06.bmp");
    levelup_black[6] = LoadGraph("./haikei/LEVELUP/black/edit/levelup07.bmp");
    levelup_black[7] = LoadGraph("./haikei/LEVELUP/black/edit/levelup08.bmp");
    levelup_black[8] = LoadGraph("./haikei/LEVELUP/black/edit/levelup09.bmp");
    levelup_black[9] = LoadGraph("./haikei/LEVELUP/black/edit/levelup10.bmp");
    levelup_black[10] = LoadGraph("./haikei/LEVELUP/black/edit/levelup11.bmp");
    levelup_black[11] = LoadGraph("./haikei/LEVELUP/black/edit/levelup12.bmp");
    levelup_black[12] = LoadGraph("./haikei/LEVELUP/black/edit/levelup13.bmp");
    levelup_black[13] = LoadGraph("./haikei/LEVELUP/black/edit/levelup14.bmp");
    levelup_black[14] = LoadGraph("./haikei/LEVELUP/black/edit/levelup15.bmp");
}

void after(int pos_y) {
    if (pos_y == 120) {
        DrawFormatString(450, 400, GetColor(0, 0, 255), "�^�C�g���ɖ߂�", false);
        if (CheckHitKey(KEY_INPUT_Z)) pauseflag = true;
    }
}

MenuElement_t Set[10]{
    {80,100,"WINDOW MODE",0,0,255},
    {100,150,"PLAYER SPPED",255,255,255},
    {100,200,"BGM",255,255,255},
    {100,250,"BGM VOLUME",255,255,255},
    {100,300,"SE",255,255,255},
    {100,350,"SE VOLUME",255,255,255},
    {100,400,"�߂�",255,255,255}
};
int setnum;

//�ݒ����
char setstring[10][100] = {
    {"�Q�[����ʂ̕ύX�ł��B\n�ύX�����f�����͖̂߂��Ă���ł��B"},
    {"�v���C���[�̃X�s�[�h��ύX�ł��܂��B\n�D���ȑ����ł���Ă��������B"},
    {"BGM�̗L����ݒ�ł��܂��B"},
    {"BGM�̑傫����ύX�ł��܂��B\n�������Ȃ��傫���ɂ����ق��������ł���B"},
    {"SE�ڗL����ݒ�ł��܂��B"},
    {"SE�̑傫����ύX�ł��܂��B\n�傫���͂��D�݂łǂ����B"},
};

int setmenu_num = 7; //�ݒ胁�j���[�̌�
void setting() {
    if (Key[KEY_INPUT_DOWN] == 1) { // ���L�[�������ꂽ�u�Ԃ�������

        setnum = (setnum + 1) % setmenu_num; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)

        for (int i = 0; i < setmenu_num; i++) {              // ���j���[���ڐ��ł���5���[�v����
            if (i == setnum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
                Set[i].x = 80; // ���W��80�ɂ���
                Set[i].r = 0;
                Set[i].g = 0;
                Set[i].b = 255;
            }
            else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
                Set[i].x = 100;// ���W��100�ɂ���
                Set[i].r = 255;
                Set[i].g = 255;
                Set[i].b = 255;
            }
        }
    }
    //��Ɠ���
    if (Key[KEY_INPUT_UP] == 1) {

        setnum = (setnum + setmenu_num-1) % setmenu_num;

        for (int i = 0; i < setmenu_num; i++) {
            if (i == setnum) {
                Set[i].x = 80;
                Set[i].r = 0;
                Set[i].g = 0;
                Set[i].b = 255;
            }
            else {
                Set[i].x = 100;
                Set[i].r = 255;
                Set[i].g = 255;
                Set[i].b = 255;
            }
        }
    }
    for (int i = 0; i < setmenu_num; i++) { // ���j���[���ڂ�`��
        DrawFormatString(Set[i].x, Set[i].y, GetColor(Set[i].r, Set[i].g, Set[i].b), Set[i].name);
    }
    if (setnum != 6) DrawFormatString(30, 30, GetColor(255, 255, 255), setstring[setnum], false);
}
int setstnum[10] = {0,0,0,4,0,4};
int setmod[10] = { 2,3,2,10,2,10 };
int setdate[10][10];

//int music_vol[] = {10,20,30,40,50,60,70,80,90};

int koakuma;
int tosyokan;
char setring[10][10][100] = {
    {{"�E�B���h�E"},{"�t���X�N���[��"}},
    {{"����"},{"����"},{"����"}},
    {{"�L��"},{"����"}},
    {{"10��"},{"20��"},{"30��"},{"40��"},{"50��"},{"60��"},{"70��"},{"80��"},{"90��"},{"100��"}},
    {{"�L��"},{"����"}},
    {{"10��"},{"20��"},{"30��"},{"40��"},{"50��"},{"60��"},{"70��"},{"80��"},{"90��"},{"100��"}},
};

bool music_flag = true;



void setst(int num) {
    if (setnum != setmenu_num - 1) {
        if (Key[KEY_INPUT_RIGHT] == 1) {
            setstnum[num] = (setstnum[num] + 1) % setmod[num];
        }
        if (Key[KEY_INPUT_LEFT] == 1) {
            setstnum[num] = (setstnum[num] + setmod[num] - 1) % setmod[num];
        }
    }
    for (int i = 0; i < setmenu_num; i++) {
        DrawFormatString(270, 100 + (50 * i), GetColor(255, 255, 255), setring[i][setstnum[i]], false);
    }
}

bool mode = true;

void screen() {
    if (mode == (bool)setstnum[0]) {
        mode ^= true;
    }
    //�X�N���[���̕ύX
    ChangeWindowMode(mode);
    //������
    DxLib_Init();
    SetDrawScreen(DX_SCREEN_BACK);
}
int MOVE_SPEED[4] = {1,2,10};
void ps() {
    move_player_speed = MOVE_SPEED[setstnum[1]];
}
int title;
bool music_set() {
    if (music_flag == (bool)setstnum[2]) {
        music_flag ^= true;
        return true;
    }
    return false;
}

bool se_set() {
    if (se_flag == (bool)setstnum[4]) {
        se_flag ^= true;
        return true;
    }
    return false;
}




MenuElement_t diffselect[4]{
 {  80, 180, "EASY",0,0,255 }, 
 { 100, 230, "NORMAL" ,255,255,255},
 { 100, 280, "HARD",255,255,255 },
 //{100,330,"RUNATIC,255,255,255},
 { 100, 380, "�߂�" ,255,255,255},
};

int diffnum;

int drop_point[4] = { 4,2,1,0 };
char diffstring[4][100] = {
    {"��ԊȒP�ł��ˁB�p�`�����[�l�̂Ƃ����\n��������������ł��܂���B"},
    {"���ʂ̓�Փx�炵���ł��ˁB\n�܂��͂����������Ă݂܂��傤�I"},
    {"POINT���Ȃ��Ȃ肪���ł��B\n�X�e�[�^�X�̊Ǘ����d�v�ł��ˁB\n������Ǌ撣���Ă��������B"}
};

void diff(bool f) {
    if (Key[KEY_INPUT_DOWN] == 1) { // ���L�[�������ꂽ�u�Ԃ�������

        diffnum = (diffnum + 1) % 4; // ���݂̑I�����ڂ�����ɂ��炷(���[�v����)

        for (int i = 0; i < 4; i++) {              // ���j���[���ڐ��ł���5���[�v����
            if (i == diffnum) {          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
                diffselect[i].x = 80; // ���W��80�ɂ���
                diffselect[i].r = 0;
                diffselect[i].g = 0;
                diffselect[i].b = 255;
            }
            else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
                diffselect[i].x = 100;// ���W��100�ɂ���
                diffselect[i].r = 255;
                diffselect[i].g = 255;
                diffselect[i].b = 255;
            }
        }
    }
    //��Ɠ���
    if (Key[KEY_INPUT_UP] == 1) {

        diffnum = (diffnum + 3) % 4;

        for (int i = 0; i < 4; i++) {
            if (i == diffnum) {
                diffselect[i].x = 80; // ���W��80�ɂ���
                diffselect[i].r = 0;
                diffselect[i].g = 0;
                diffselect[i].b = 255;
            }
            else {
                diffselect[i].x = 100;// ���W��100�ɂ���
                diffselect[i].r = 255;
                diffselect[i].g = 255;
                diffselect[i].b = 255;
            }
        }
    }
    for (int i = 0; i < 4; i++) { // ���j���[���ڂ�`��
        DrawFormatString(diffselect[i].x, diffselect[i].y, GetColor(diffselect[i].r, diffselect[i].g, diffselect[i].b), diffselect[i].name);
    }
    if (diffnum != 3) {
        DrawFormatString(100, 50, GetColor(255, 255, 255), "�G�̗��Ƃ�POINT��%d�ɂȂ�܂���", drop_point[diffnum], false);
        if(f==true) DrawFormatString(100, 100, GetColor(255, 255, 255), diffstring[diffnum], false);
    }
}
void diffreset() {
    diffselect[0].x = 80; // ���W��80�ɂ���
    diffselect[0].r = 0;
    diffselect[0].g = 0;
    diffselect[0].b = 255;
    for (int i = 1; i < 4; i++) {
        diffselect[i].x = 100;// ���W��100�ɂ���
        diffselect[i].r = 255;
        diffselect[i].g = 255;
        diffselect[i].b = 255;
    }
    diffnum = 0;
}