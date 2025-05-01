#include"./map_date.h"    
#include"./enemy.h"
//�}�b�v�̕\��
void map_date_01() {
    for (int i = 0; i < 640; i += 32) {
        for (int j = 0; j < 480; j += 32) {
            if (map001_map[j / 32][i / 32] == -1); //DrawGraph(i, j, haikei_chippu, false);
            else if (map001_map[j / 32][i / 32] == 99) DrawGraph(i, j, map_cave003[4], false);
            else if (map001_map[j / 32][i / 32] == 100) DrawGraph(i, j, map_cave003[4], false);
            else if (map001_map[j / 32][i / 32] == 0) DrawGraph(i, j, map_cave006[4], false);
            else if (map001_map[j / 32][i / 32] == 1) DrawGraph(i, j, map_cave003[4], false);
            else if (map001_map[j / 32][i / 32] == 2) DrawGraph(i, j, t_town04[3], false);
            else if (map001_map[j / 32][i / 32] == 3) DrawGraph(i, j, kouma_map, false);
        }
    }
}
//�G�A�L�����N�^�[�̕\��
void map_enemy_01() {
    for (int i = 0; i < 640; i += 32) {
        for (int j = 0; j < 480; j += 32) {
            //�G��\��
            if (map001_enemy[j / 32][i / 32] < 100 && map001_enemy[j / 32][i / 32] != 0) {
                if (map001_enemy[j / 32][i / 32] < 9) {
                    if (enemy_move[map001_enemy[j / 32][i / 32]] % (int)(64 * 0.75) < 16 * 0.75) DrawGraph(i, j, enemy_001[enemy_graph[map001_enemy[j / 32][i / 32] - 1]], true);
                    else if (enemy_move[map001_enemy[j / 32][i / 32]] % (int)(64 * 0.75) < 32 * 0.75) DrawGraph(i, j, enemy_001[enemy_graph[map001_enemy[j / 32][i / 32] - 1] + 1], true);
                    else if (enemy_move[map001_enemy[j / 32][i / 32]] % (int)(64 * 0.75) < 48 * 0.75) DrawGraph(i, j, enemy_001[enemy_graph[map001_enemy[j / 32][i / 32] - 1] + 2], true);
                    else if (enemy_move[map001_enemy[j / 32][i / 32]] % (int)(64 * 0.75) < 64 * 0.75) DrawGraph(i, j, enemy_001[enemy_graph[map001_enemy[j / 32][i / 32] - 1] + 1], true);
                    enemy_move_speed[map001_enemy[j / 32][i / 32]] = 1;
                }
                else if (map001_enemy[j / 32][i / 32] < 13) {
                    if (enemy_move[map001_enemy[j / 32][i / 32]] % (int)(64 * 0.75) < 16 * 0.75) DrawGraph(i, j, enemy_003[enemy_graph[map001_enemy[j / 32][i / 32] - 1]], true);
                    else if (enemy_move[map001_enemy[j / 32][i / 32]] % (int)(64 * 0.75) < 32 * 0.75) DrawGraph(i, j, enemy_003[enemy_graph[map001_enemy[j / 32][i / 32] - 1] + 1], true);
                    else if (enemy_move[map001_enemy[j / 32][i / 32]] % (int)(64 * 0.75) < 48 * 0.75) DrawGraph(i, j, enemy_003[enemy_graph[map001_enemy[j / 32][i / 32] - 1] + 2], true);
                    else if (enemy_move[map001_enemy[j / 32][i / 32]] % (int)(64 * 0.75) < 64 * 0.75) DrawGraph(i, j, enemy_003[enemy_graph[map001_enemy[j / 32][i / 32] - 1] + 1], true);
                    enemy_move_speed[map001_enemy[j / 32][i / 32]] = 1;
                }
                else DrawGraph(i, j, merin, true);
            }
            //�V���b�v��ǉ�
            else if (map001_enemy[j / 32][i / 32] == 100) DrawGraph(i, j - 20, patye[1], true);
            else if (map001_enemy[j / 32][i / 32] == 101) DrawGraph(i, j, item[0], true);
            else if (map001_enemy[j / 32][i / 32] == 102) DrawGraph(i, j, item[1], true);
            else if (map001_enemy[j / 32][i / 32] == 103) DrawGraph(i, j, item[2], true);
            else if (map001_enemy[j / 32][i / 32] == 104) DrawGraph(i, j, item[3], true);
            else if (map001_enemy[j / 32][i / 32] == 105) DrawGraph(i, j, item[4], true);
            else if (map001_enemy[j / 32][i / 32] == 106) DrawGraph(i, j, item[5], true);
            //�G�̓����̑����𐧌�
        }
    }
    for (int j = 0; j < 100; j++) {
        if (enemy_move_speed[j] == 1) {
            enemy_move[j]++;
            enemy_move_speed[j] = 0;
        }
    }
}
bool flame_flag = false;
void FLAME_map_01() {
    //map�f�[�^�@����
    if (map001_map[(player_x) / 32][(player_y) / 32] == 0|| map001_map[(player_x) / 32][(player_y) / 32] == 2) flame_flag = true; //
    else if (map001_map[(player_x + 4) / 32][(player_y) / 32] == 0 || map001_map[(player_x) / 32][(player_y) / 32] == 2) flame_flag = true; //��(��)�@�����蔻��
    else if (map001_map[(player_x + 4) / 32][(player_y - 10) / 32] == 0 || map001_map[(player_x) / 32][(player_y) / 32] == 2) flame_flag = true; //

    else if (map001_map[(player_x) / 32][(player_y) / 32] == -2) flame_flag = true; //
    else if (map001_map[(player_x + 4) / 32][(player_y) / 32] == -2) flame_flag = true; //��(��)�@�����蔻��
    else if (map001_map[(player_x + 4) / 32][(player_y - 10) / 32] == -2) flame_flag = true; //
    //�S�[������
    if (map001_map[player_x / 32][player_y / 32] == 100|| map001_map[player_x / 32][player_y / 32] == 99) goal = 1;
    //enemy�f�[�^�@����
    if (map001_enemy[(player_x) / 32][(player_y) / 32] != 0 && map001_enemy[(player_x) / 32][(player_y) / 32] <= 100) flame_flag = true; //
    else if (map001_enemy[(player_x + 4) / 32][(player_y) / 32] != 0 && map001_enemy[(player_x + 4) / 32][(player_y) / 32] <= 100) flame_flag = true; //��(��)�@�����蔻��
    else if (map001_enemy[(player_x + 4) / 32][(player_y - 10) / 32] != 0&&map001_enemy[(player_x + 4) / 32][(player_y - 10) / 32] <= 100) flame_flag = true; //
    //
    if (flame_flag == true) {
        player_x = old_player_x, player_y = old_player_y;
        flame_flag = false;
    }
}
bool event_face;
void event_map() {
    //shop
    if (Key[KEY_INPUT_Z] == 1) {

        if (map001_enemy[player_x / 32 + 1][player_y / 32] == 100 && player_face_num == 0 ||
            map001_enemy[player_x / 32 - 1][player_y / 32] == 100 && player_face_num == 3 ||
            map001_enemy[player_x / 32][player_y / 32 + 1] == 100 && player_face_num == 2 ||
            map001_enemy[player_x / 32][player_y / 32 - 1] == 100 && player_face_num == 1) {
            //player��char�̌�������v����
            event_face = true;
        }
        if (event_face == true) {
            //shop�@�ʒu�@������
            shop_num = -1;
            for (int i = 0; i < 5; i++) {
                SHOP[i].x = 400;
                SHOP[i].r = 255;
                SHOP[i].g = 255;
                SHOP[i].b = 255;
            }

            while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                if (CheckHitKey(KEY_INPUT_Q)) break;
                shop();
                //�߂��I�� shop��ʂ����
                if (shop_back == true) {
                    shop_back = false;
                    break;
                }
                DrawGraph(0, -10, PATYURI, true);
            }
        }
    }
}
bool graph_fight = false;
//�s�k���
int GAMEOVER;

//�U���񐔊i�[�p�ϐ�
int number;
//�G�A��l���@�퓬���̍U����
int pATK, eATK;
int pos_x, pos_y;
int eatknum, patknum;

int talk;

int game_y;
int gametime;
bool game_in = true;
void gameover() {

    game_y = 300;
    //�I����ʂ̏��̏�����(�s�k��)
    game[0].r = 0, game[0].g = 0, game[0].b = 255, game[0].x = 320;
    game[1].r = 255, game[1].g = 255, game[1].b = 255, game[1].x = 350;

    //BGM
    if (music_flag == true) {
        StopSoundMem(map_bgm);
        PlaySoundMem(gameover_bgm, DX_PLAYTYPE_LOOP);
    }
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
        //GAME OVER��\��
        DrawGraph(0, game_y, GAMEOVER, false);
        game_y -= 7;
        //���������ɂ����Ȃ��悤�ɐ�����t����   
        if (game_y < 0) game_y = 0;
        if(CheckHitKey(KEY_INPUT_Q)) break;
        //�����̈ړ����~�܂�������s
        if (game_y == 0) {
            //�����̊ԉ�ʂ��~�߂�    
            if (game_in == true) {
                gametime = 0;
                while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                    DrawGraph(0, 0, GAMEOVER, false);
                    MOVECHARCTor();
                    DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                    if (gametime / 60 != 1) break;
                    gametime++;
                }
                game_in = false;
            }
            //�s�k���̑I�����
            gamemenu();
            //SE�ǉ�
            if (se_flag == true) {
                if (Key[KEY_INPUT_UP] == 1 || Key[KEY_INPUT_DOWN] == 1) PlaySoundMem(hit_se, DX_PLAYTYPE_BACK);
                if (Key[KEY_INPUT_Z] == 1) PlaySoundMem(check_se, DX_PLAYTYPE_BACK);
            }

            if (CheckHitKey(KEY_INPUT_Z)) {
                //�����x�ނ�I��
                if (gamemenu_sum == 0) {
                    pauseflag = true;
                    
                    break;
                }
                //�^�C�g���ɖ߂��I��
                else {
                    pauseflag = true;
                    break;
                }
            }
        }
        MOVECHARCTor();
        DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
    }
}

int starttime;

bool level_flag = 0;

//SE
int fight_hit_se;
int fight_check_se;
int fight_battle_se;
int level_se;


void event_enemy() {
    event_face = false;
    if (Key[KEY_INPUT_Z] == 1) {
        //player��char�̌�������v����
        if (map001_enemy[player_x / 32 + 1][player_y / 32] != 100 && player_face_num == 0 && map001_enemy[player_x / 32 + 1][player_y / 32] != 0) graph_fight = true, pos_x = player_x / 32 + 1, pos_y = player_y / 32;
        else if (map001_enemy[player_x / 32 - 1][player_y / 32] != 100 && player_face_num == 3 && map001_enemy[player_x / 32 - 1][player_y / 32] != 0) graph_fight = true, pos_x = player_x / 32 - 1, pos_y = player_y / 32;
        else if (map001_enemy[player_x / 32][player_y / 32 + 1] != 100 && player_face_num == 2 && map001_enemy[player_x / 32][player_y / 32 + 1] != 0) graph_fight = true, pos_x = player_x / 32, pos_y = player_y / 32 + 1;
        else if (map001_enemy[player_x / 32][player_y / 32 - 1] != 100 && player_face_num == 1 && map001_enemy[player_x / 32][player_y / 32 - 1] != 0) graph_fight = true, pos_x = player_x / 32, pos_y = player_y / 32 - 1;
    }
    if (graph_fight == true) {
        number = 0;
        //�G�Ƀ_���[�W��^�����
        if ((player_date[2] - enemy_date[map001_enemy[pos_x][pos_y]].DEF) > 0) {
            if (enemy_date[map001_enemy[pos_x][pos_y]].HP % (player_date[2] - enemy_date[map001_enemy[pos_x][pos_y]].DEF) != 0) number = 1;
            number += (enemy_date[map001_enemy[pos_x][pos_y]].HP / (player_date[2] - enemy_date[map001_enemy[pos_x][pos_y]].DEF));
            //�퓬���̍U���͂��v�Z
            pATK = player_date[2] - enemy_date[map001_enemy[pos_x][pos_y]].DEF;
            eATK = enemy_date[map001_enemy[pos_x][pos_y]].ATK - player_date[3];
            if (pATK <= 0) pATK = 0;
            if (eATK <= 0) eATK = 0;
            patknum = 0;
            eatknum = -1;
        }
        //�G�Ƀ_���[�W��^�����Ȃ�
        else {
            if ((enemy_date[map001_enemy[pos_x][pos_y]].ATK - player_date[3]) > 0) {
                if (player_date[1] % (enemy_date[map001_enemy[pos_x][pos_y]].ATK - player_date[3]) != 0) number = 1;
                number += player_date[1] / (enemy_date[map001_enemy[pos_x][pos_y]].ATK - player_date[3]);
            }
            //�����Ƀ_���[�W���͂���Ȃ�
            else {
                number = 0;
            }
            patknum = 0;
            eatknum = 0;
            //�퓬���̍U���͂��v�Z
            eATK = enemy_date[map001_enemy[pos_x][pos_y]].ATK - player_date[3];
            pATK = player_date[2] - enemy_date[map001_enemy[pos_x][pos_y]].DEF;
            if (pATK <= 0) pATK = 0;
            if (eATK <= 0) eATK = 0;
        }
        //�퓬��ʏ�����
        fightnum = 0;
        fight[0].x = 300;
        fight[0].r = 0;
        fight[0].g = 0;
        fight[0].b = 255;
        fight[1].x = 310;
        fight[1].r = 0;
        fight[1].g = 0;
        fight[1].b = 0;


        while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
            MOVECHARCTor();
            DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);

            //�}�b�v�A�L��������\��
            map_date_01();
            map_enemy_01();
            player_status();
            DrawGraph(player_y - 30 + (30 - 24), player_x - 30 + (30 - 30), playerimage[player_walk], true);
            //�퓬��ʂ�\��
            //�g
            //DrawBox(0, 300, 416, 480, GetColor(80, 80, 80), true);
            //DrawBox(10, 310, 406, 470, GetColor(255, 255, 255), true);
            DrawGraph(0, 300, talk, true);
            //�X�e�[�^�X�\��
            DrawFormatString(120, 325, GetColor(0, 0, 0), "HP:%d  ATK:%d  DEF:%d�@POINT:%d", enemy_date[map001_enemy[pos_x][pos_y]].HP, enemy_date[map001_enemy[pos_x][pos_y]].ATK, enemy_date[map001_enemy[pos_x][pos_y]].DEF, enemy_date[map001_enemy[pos_x][pos_y]].POINT, false);
            DrawFormatString(20, 360, GetColor(0, 0, 0), "�^�_���[�W %4d �~ %4d = %5d ", pATK, number + patknum, pATK * (number + patknum), false);
            DrawFormatString(20, 390, GetColor(0, 0, 0), "��_���[�W %4d �~ %4d = %5d ", eATK, number + eatknum, eATK * (number + eatknum), false);
            if (number == 0) DrawFormatString(100, 430, GetColor(255, 0, 0), "�_���[�W��^����Ȃ�!!", false);
            else if (eATK * (number + eatknum) < player_date[1]) DrawFormatString(100, 430, GetColor(255, 0, 0), "          ����!!", false);
            else DrawFormatString(100, 430, GetColor(255, 0, 0), "          �s�k!!", false);
            if (Key[KEY_INPUT_Q] == 1) {
                graph_fight = false;
                break;
            }
            //�Z���N�g��ʂ̕\��
            fight_select();
            if (se_flag) {
                if(Key[KEY_INPUT_UP] == 1 || Key[KEY_INPUT_DOWN] == 1) PlaySoundMem(fight_hit_se, DX_PLAYTYPE_BACK);
                if (Key[KEY_INPUT_Z] == 1) PlaySoundMem(fight_check_se, DX_PLAYTYPE_BACK);
            }

            if (Key[KEY_INPUT_Z] == 1) {
                //�퓬�J�n��I��
                if (fightnum == 0) {
                    //�����Ƀ_���[�W���͂���Ȃ�
                    if (number == 0) {
                        //���������Ɍ��̉�ʂɖ߂�
                        graph_fight = false;
                        break;
                    }
                    //�v���C���[����������
                    else if (eATK * (number + eatknum) < player_date[1]) {

                        //SE�@�ǉ�
                        if (se_flag == true) PlaySoundMem(fight_battle_se, DX_PLAYTYPE_BACK);

                        player_date[0] += enemy_date[map001_enemy[pos_x][pos_y]].POINT;
                        player_date[1] -= eATK * (number + eatknum);
                        graph_fight = false;
                        player_date[4]++;
                        if (player_date[4] >= nextlevel ) {
                            //player_date[4] = 0;
                            //SE
                            if (se_flag == true) PlaySoundMem(level_se, DX_PLAYTYPE_BACK);
                            
                            nextlevel += ((4 + leveltime) + 10);
                            leveltime++;
                            player_date[1] += 150; //HP
                            player_date[2] += 5;   //ATK
                            player_date[3] += 5;   //DEF
                            level_flag = true;
                        }
                        //�G������
                        if (player_face_num == 0) map001_enemy[player_x / 32 + 1][player_y / 32] = 0;
                        else if (player_face_num == 1) map001_enemy[player_x / 32][player_y / 32 - 1] = 0;
                        else if (player_face_num == 2) map001_enemy[player_x / 32][player_y / 32 + 1] = 0;
                        else if (player_face_num == 3) map001_enemy[player_x / 32 - 1][player_y / 32] = 0;
                        if (player_date[4] == 0) {
                            player_date[1] += 150; //HP
                            player_date[2] += 5;   //ATK
                            player_date[3] += 5;   //DEF
                        }
                        break;
                    }
                    //�v���C���[��������
                    else {

                        player_date[1] -= eATK * (number + eatknum);
                        player_status();

                        // ���݌o�ߎ��Ԃ𓾂�
                        starttime = GetNowCount();
                        //0.175�b�Ԏ~�܂�
                        while (GetNowCount() - starttime < 175) {
                            // ���b�Z�[�W����
                            if (ProcessMessage() == -1) break;
                        }
                        gamemenu_sum = 0;
                        while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                            gameover();
                            if (CheckHitKey(KEY_INPUT_Q)) break;
                            graph_fight = false;
                            //�^�C�g���ɖ߂��I��
                            if (pauseflag == true) break;
                        }
                    }

                }
                //��߂��I��
                else {
                    graph_fight = false;
                    break;
                }
                if (pauseflag == true) break;
            }
        }
    }
}

void start() {
    for (int i = 101; i <= 106; i++) {
        enemy_date[i].HP = 1;
    }
}

//�}�b�v�f�[�^�@�ǂݍ���
void mapload(int a) {
    for (int i = 0; i < 640; i += 32) {
        for (int j = 0; j < 480; j += 32) {
            map001_map[j / 32][i / 32] = map001_map_cp[a][j / 32][i / 32];
            map001_enemy[j / 32][i / 32] = map001_enemy_cp[a][j / 32][i / 32];
        }
    }
}
void beformapload(int a) {
    if (map001_map_cp[a][0][0] == 0) {
        for (int i = 0; i < 640; i += 32) {
            for (int j = 0; j < 480; j += 32) {
                map001_map_cp[a][j / 32][i / 32] = map001_map_date[a][j / 32][i / 32];
                map001_enemy_cp[a][j / 32][i / 32] = map001_enemy_date[a][j / 32][i / 32];
            }
        }
    }
}
void aftermapload(int a) {
    for (int i = 0; i < 640; i += 32) {
        for (int j = 0; j < 480; j += 32) {
            map001_map_cp[a][j / 32][i / 32] = map001_map[j / 32][i / 32];
            map001_enemy_cp[a][j / 32][i / 32] = map001_enemy[j / 32][i / 32];
        }
    }
}

//SE �A�C�e��
int item_se;

void ITEM() {
    //item
    if (map001_enemy[player_x/32][player_y/32] >= 101) {
        //SE �ǉ�
        if (se_flag == true) PlaySoundMem(item_se, DX_PLAYTYPE_BACK);

        int now = map001_enemy[player_x / 32][player_y / 32];
        map001_enemy[player_x/32][player_y/32] = 0;
        if (now == 101) player_date[4] += 5;       //big power
        else if (now == 102) player_date[4]++;     //small power
        else if (now == 103) player_date[0] += 15; //big point
        else if (now == 104) player_date[0] += 5; //small point
        else if (now == 105)player_date[1] += 300; //big hp
        else if (now == 106) player_date[1] += 100;//small hp
        if (player_date[4] >= nextlevel) {
            //SE
            if (se_flag == true) PlaySoundMem(level_se, DX_PLAYTYPE_BACK);

            //player_date[4] = 0;
            nextlevel += ((4 + leveltime) + 10);
            leveltime++;
            level_flag = true;
            player_date[1] += 150; //HP
            player_date[2] += 5;   //ATK
            player_date[3] += 5;   //DEF
        }
    }
}
int lcnt = 0;
int lmovie = 0;
int level_text;


void LEVELUP() {
    
    lcnt++;
    if (lcnt % 5 == 0) {
        lmovie++;
        if (lmovie == 15) lmovie = 14;
    }
    //�g�̕\��
    DrawGraph(0, 300, talk, true);
    //���̕\��
    //DrawGraph(0, 300, level_text, true);
    DrawFormatString(50, 330, GetColor(0, 0, 0), "HP      +150", false);
    DrawFormatString(50, 380, GetColor(0, 0, 0), "ATTACK  +5", false);
    DrawFormatString(50, 430, GetColor(0, 0, 0), "DEFNES  +5               ���A�b�v����", false);
    //�A�j���[�V����
    DrawGraph(0, 0, levelup_black[lmovie], true);
}