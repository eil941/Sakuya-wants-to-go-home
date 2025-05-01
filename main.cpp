#include"./header/include.h"
#include"./header/kansu.h"
#include"./header/map_01.h"
void delgraph() {
    DeleteGraph(haikei_001_01);
    DeleteGraph(haikei_001_02);
    DeleteGraph(haikei_chippu);
    DeleteGraph(PATYURI);
    DeleteGraph(GAMEOVER);
    DeleteGraph(talk);
    DeleteGraph(level_text);
    DeleteGraph(clear_text);
    DeleteGraph(kouma);
    DeleteGraph(kouma_map);
    DeleteGraph(bkouma);
    DeleteGraph(bsakuya);
    DeleteGraph(title);
    DeleteGraph(koakuma);
    DeleteGraph(tosyokan);
    DeleteGraph(merin);
    for (int i = 0; i < 13; i++) DeleteGraph(levelup[i]);
    for (int i = 0; i < 15; i++) DeleteGraph(levelup_black[i]);
    for (int i = 0; i < 6; i++) DeleteGraph(item[i]);
    for (int i = 0; i < 12; i++) DeleteGraph(playerimage[i]);
    for (int i = 0; i < 12; i++) DeleteGraph(patye[i]);
    for (int i = 0; i < 5; i++) {
        DeleteGraph(map_cave003[i]);
        DeleteGraph(map_cave006[i]);
        DeleteGraph(t_town04[i]);
    }
    for (int i = 0; i < 96; i++) {
        DeleteGraph(enemy_001[i]);
        DeleteGraph(enemy_002[i]);
        DeleteGraph(enemy_003[i]);
    }

}
void graph() {

    //�摜�ǂݍ���
    PATYURI = LoadGraph("./haikei/dairi_patyuri.bmp");
    GAMEOVER = LoadGraph("./haikei/GAMEOVER.bmp");
    talk = LoadGraph("./haikei/kaiwa3.bmp");
    level_text = LoadGraph("./haikei/LEVELUP/text/level_text.bmp");
    clear_text = LoadGraph("./haikei/gameclear.bmp");
    kouma = LoadGraph("./haikei/kouma.bmp");
    kouma_map = LoadGraph("./haikei/kouma_map.bmp");
    bkouma = LoadGraph("./haikei/kouma01.jpg");
    bsakuya = LoadGraph("./haikei/sakuya .bmp");
    title = LoadGraph("./haikei/title/title.bmp");
    koakuma = LoadGraph("./haikei/setting/koakuma.bmp");
    tosyokan = LoadGraph("./haikei/setting/tosyokan.bmp");

    levelupload_white();
    levelupload_black();


    //�A�C�e���摜
    item[0] = LoadGraph("./item/level_big.bmp");
    item[1] = LoadGraph("./item/level_small.bmp");
    item[2] = LoadGraph("./item/point_big.bmp");
    item[3] = LoadGraph("./item/point_small.bmp");
    item[4] = LoadGraph("./item/hp_big.bmp");
    item[5] = LoadGraph("./item/hp_small.bmp");

    // �摜�̕����ǂݍ���
    //character
    //LoadDivGraph("./character/player001-01-01.bmp", 12, 3, 4, 39, 39, playerimage);
    LoadDivGraph("./character/char_sakuya_2.bmp", 12, 3, 4, 32.33, 43, playerimage);
    //LoadDivGraph("./character/patyuri.bmp", 12, 3, 4, 39, 39, patye);
    //LoadDivGraph("./character/patye.bmp", 12, 3, 4, 32.33, 43, patye);
    patye[1] = LoadGraph("./character/patye_1.bmp");

    //map
    LoadDivGraph("./nekura_map/map/t_cave03.png", 5, 1, 5, 32, 32, map_cave003);
    LoadDivGraph("./nekura_map/map/t_cave06.png", 5, 1, 5, 32, 32, map_cave006);
    LoadDivGraph("./nekura_map/map/t_town04.png", 5, 1, 5, 32, 32, t_town04);
    //�G
    //LoadDivGraph("./enemy/enemy001.bmp", 96, 12, 8, 24, 32, enemy_001);
    LoadDivGraph("./enemy/enemy001_2.bmp", 96, 12, 8, 24, 32, enemy_001);
    //LoadDivGraph("./enemy/enemy002.bmp", 96, 6, 12, 32, 32, enemy_002);
    LoadDivGraph("./enemy/enemy003.bmp", 96, 12, 8, 24, 32, enemy_003);
    LoadDivGraph("./enemy/enemy003_2.bmp", 96, 12, 8, 24, 32, enemy_003);
    merin = LoadGraph("./enemy/merin_1.bmp");
}
void music_map() {
    StopSoundMem(title_bgm);
    PlaySoundMem(map_bgm, DX_PLAYTYPE_LOOP);
}
void music_back() {
    StopSoundMem(map_bgm);
    StopSoundMem(gameover_bgm);
    StopSoundMem(goal_bgm);
    PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP);
}
void goal_music() {
    StopSoundMem(map_bgm);
    PlaySoundMem(goal_bgm, DX_PLAYTYPE_LOOP);
}
void up_down(bool flag) {
    if (flag) {
        if (Key[KEY_INPUT_UP] == 1 || Key[KEY_INPUT_DOWN] == 1) PlaySoundMem(hit_se, DX_PLAYTYPE_BACK);
        if (Key[KEY_INPUT_Z] == 1) PlaySoundMem(check_se, DX_PLAYTYPE_BACK);
    }
}
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    //�E�B���h�E���[�h�ɐݒ�    DX���C�u��������������    �`���𗠉�ʂɐݒ�              ���ߐF�ݒ�   (R,G,B);     �o�b�N�O���E���h�Ŏ��s����
    ChangeWindowMode(true);     DxLib_Init();             SetDrawScreen(DX_SCREEN_BACK);    SetTransColor(0, 255, 0);    SetAlwaysRunFlag(false);

    //�E�B���h�E��
    SetMainWindowText("���͂��ƂɋA�肽��");

    //�E�B���h�E�T�C�Y�ύX true : �\  false : �s�\ 
    SetWindowSizeChangeEnableFlag(true);
    
    //�摜�̓ǂݍ���
    graph();

    //BGM�֌W
    title_bgm = LoadSoundMem("./music/title/title03.mp3");
    map_bgm = LoadSoundMem("./music/title/map01.mp3");
    gameover_bgm = LoadSoundMem("./music/title/gameover.mp3");
    goal_bgm = LoadSoundMem("./music/goal/goal001.mp3");

    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, title_bgm);
    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, map_bgm);
    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, gameover_bgm);
    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, goal_bgm);

    PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP);

    //SE�֌W
    hit_se= LoadSoundMem("./music/se/se_hit.mp3");
    pause_se = LoadSoundMem("./music/pause/pause_001.mp3");
    check_se = LoadSoundMem("./music/se/se_check.mp3");
    item_se = LoadSoundMem("./music/se/item/se_item.mp3");
    fight_hit_se= LoadSoundMem("./music/se/fight/se_fight_hit.mp3");
    fight_check_se= LoadSoundMem("./music/se/fight/se_fight_check.mp3");
    fight_battle_se= LoadSoundMem("./music/se/fight/se_fight_battle.mp3");
    level_se = LoadSoundMem("./music/se/level/se_level.mp3");

    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, hit_se);
    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, pause_se);
    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, check_se);
    ChangeVolumeSoundMem(((255.0 / 100.0) * 5 * 10.0) , item_se);
    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, fight_hit_se);
    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, fight_check_se);
    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, fight_battle_se);
    ChangeVolumeSoundMem((255.0 / 100.0) * 5 * 10.0, level_se);

    //�X�e�[�^�X������
    start();
    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {

        //�w�i
        DrawGraph(0, 0, bkouma, false);
        DrawGraph(0, -65, title, true);
        MENU();
        //SE�ǉ�
        up_down(se_flag);

        if (Key[KEY_INPUT_Q] == 1) break;
        if (Key[KEY_INPUT_Z] == 1) {
            //������
            shopdate[0] = 0, shopdate[1] = 0, shopdate[2] = 0,shopdate[3]=0;
            chflag = false;

            //�Q�[���X�^�[�g
            memset(map001_map_cp, 0, sizeof(map001_map_cp));
            if (SelectNum == 0) {

                //��Փx�I��
                diffreset();

                while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                    //�w�i�\��
                    DrawGraph(0, 0, bkouma, false);
                    DrawGraph(400, 20, koakuma, true);
                    diff(true);
                    chdiff();

                    //SE�ǉ�
                    up_down(se_flag);


                    //�I������
                    if (chflag == true) {
                        //�߂��I��
                        if (diffnum == 3) chflag = false;
                        break;
                    }
                    MOVECHARCTor();
                    DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                }
                //�߂邪�I������Ă��Ȃ�
                if (chflag == true) {
                    chflag = false;

                    if( music_flag == true) music_map();

                    //�X�e�[�^�X������
                    player_date[0] = 0;   //POINT
                    player_date[1] = 300; //HP
                    player_date[2] = 40;  //ATK
                    player_date[3] = 40;  //DEF
                    player_date[4] = 0;   //LEVEL UP
                    
                    //���x���A�b�v�֌W
                    nextlevel = 10; //10
                    level_flag = false;
                    lmovie = 0;
                    //lcnt = 0;
                    leveltime = 0;

                    player_x = 91, player_y = 213;
                    player_face_num = 0;
                    clear = 0;
                    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                        //clear++;
                        //�}�b�v�̓ǂݍ���
                        beformapload(clear + 1);
                        mapload(clear + 1);
                        //�v���C���[���̏�����
                        goal = false;

                        if (clear < 5) {
                            //�t�B�[���h�pBGM�ɕς���
                            //music_map();
                            while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                                map_date_01();
                                map_enemy_01();
                                MOVE();
                                FLAME();
                                FLAME_map_01();
                                event_map();
                                player_status();
                                event_enemy();
                                ITEM();

                                //���x�����A�b�v����
                                if (level_flag == 1) {
                                    LEVELUP();
                                    player_x = old_player_x, player_y = old_player_y;
                                    if (lmovie == 14 && Key[KEY_INPUT_Z] == 1) {
                                        level_flag = false;
                                        lmovie = 0;
                                    }
                                }
                                //�S�[��������
                                if (goal == true) {
                                    aftermapload(clear + 1);
                                    if (map001_map[player_x / 32][player_y / 32] == 100) {
                                        clear++;
                                        player_x = 91, player_y = 213;
                                        player_face_num = 0;
                                    }
                                    else if (map001_map[player_x / 32][player_y / 32] == 99) {
                                        clear--;
                                        player_x = 400, player_y = 213;
                                        player_face_num = 3;
                                    }
                                    break;
                                }

                                //SE�ǉ� �ꎞ��~��
                                if (se_flag && Key[KEY_INPUT_ESCAPE] == 1) PlaySoundMem(pause_se, DX_PLAYTYPE_BACK);
                                //�ꎞ��~
                                pause();                                

                                //�^�C�g���ɖ߂�
                                if (pauseflag == true) {
                                    break;
                                }
                                MOVECHARCTor();
                                DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                            }
                            //�^�C�g���ɖ߂�
                            if (pauseflag == true) {
                                pauseflag = false;
                                break;
                            }
                            MOVECHARCTor();
                            DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                        }
                        //�Q�[�����N���A����
                        else {
                            clear_y = 640;
                            pcnt = 420;
                            
                            //BGM��title�ɖ߂�
                            if (music_flag == true) goal_music();

                            while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                                map_date_01();
                                after(clear_y);                             

                                clear_y -= 2;
                                pcnt--;
                                //�����@�e�L�X�g�@�v���C���[
                                if (120 > clear_y) clear_y = 120;
                                if (350 > pcnt) pcnt = 350;
                                //�w�i
                                DrawGraph(30, 32, kouma, false);

                                //�v���C���[�̓���
                                if (pcnt == 350) DrawGraph(192, pcnt, playerimage[10], true);
                                else if (pcnt % 2 == 0) DrawGraph(192, pcnt, playerimage[9], true);
                                else DrawGraph(192, pcnt, playerimage[11], true);
                                
                                //�e�L�X�g
                                DrawGraph(0, clear_y, clear_text, true);
                                //������
                                MOVECHARCTor();
                                DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                                player_status();

                                //�^�C�g���ɖ߂�
                                if (pauseflag == true) {
                                    break;
                                }
                            }
                            //�^�C�g���ɖ߂�
                            if (pauseflag == true) {
                                pauseflag = false;
                                break;
                            }
                            MOVECHARCTor();
                            DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                        }
                        
                    }

                    //BGM��title�ɖ߂�
                    if (music_flag == true) music_back();
                }
                MOVECHARCTor();
                DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
            }
            //���܂�
            if (SelectNum == 1) {
                //��Փx�I��
                diffreset();

                while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                    //�w�i�\��
                    DrawGraph(0, 0, bkouma, false);
                    DrawGraph(400, 20, koakuma, true);

                    diff(false);
                    chdiff();

                    //SE�ǉ�
                    up_down(se_flag);

                    //�I������
                    if (chflag == true) {
                        //�߂��I��
                        if (diffnum == 3) chflag = false;
                        break;
                    }
                    MOVECHARCTor();
                    DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                }
                if (chflag == true) {
                    chflag = false;

                    while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                        //�w�i
                        DrawGraph(0, 0, bkouma, false);
                        MOVECHARCTor();
                        DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);

                        omake__MENU();

                        //SE�ǉ�
                        up_down(se_flag);

                        if (Key[KEY_INPUT_Q] == 1) break;
                        if (Key[KEY_INPUT_Z] == 1) {
                            if (omake_Select != 6) {
                                player_x = 91, player_y = 213;
                                goal = false;
                                player_face_num = 0;
                                //�}�b�v�̓ǂݍ���
                                beformapload(omake_Select);
                                mapload(omake_Select);

                                //�}�b�v�̕ύX
                                if (omake_Select != 0 && omake_Select != 1 && omake_Select != 3) map001_enemy[1][6] = 100;
                                map001_map[1][6] = 0;

                                //�X�e�[�^�X������
                                player_date[0] = 0 + ((omake_Select - 1) * 500);     //POINT
                                player_date[1] = 300 + ((omake_Select) * 150); //HP
                                player_date[2] = 40 + ((omake_Select) * 5);    //ATK
                                player_date[3] = 40 + ((omake_Select) * 5);    //DEF
                                player_date[4] = 0;     //special
                                player_date[5] = 10;    //LEVEL UP

                                //�t�B�[���h�pBGM�ɕύX
                                if (!CheckSoundMem(map_bgm) && music_flag == true) music_map();

                                while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                                    map_date_01();
                                    map_enemy_01();
                                    MOVE();
                                    FLAME();
                                    FLAME_map_01();
                                    event_map();
                                    player_status();
                                    event_enemy();
                                    ITEM();
                                    //�S�[��������
                                    if (goal == true) {
                                        break;
                                    }

                                    //���x�����A�b�v����
                                    if (level_flag == 1) {
                                        LEVELUP();
                                        player_x = old_player_x, player_y = old_player_y;
                                        if (lmovie == 14 && Key[KEY_INPUT_Z] == 1) {
                                            level_flag = false;
                                            lmovie = 0;
                                        }
                                    }
                                    //�ꎞ��~
                                    pause();
                                    //�^�C�g���ɖ߂�
                                    if (pauseflag == true) {
                                        break;
                                    }
                                    //DrawFormatString(0, 0, GetColor(255, 255, 255), "player_face_num : %d", player_face_num, false);
                                    //DrawFormatString(0, 0, GetColor(200, 200, 200), "[%d , %d]", player_x, player_y);
                                    //DrawFormatString(0, 40, GetColor(255,255,255), "x : y   %d : %d", player_x / 32,player_y/32);
                                    //DrawBox(player_y-24, player_x-24, player_y-32, player_x-32, GetColor(255, 255, 255), true);
                                    //DrawFormatString(0, 0, GetColor(255, 255, 255), "map001_enemy : %d", map001_enemy[player_x / 32][player_y / 32], false);
                                    MOVECHARCTor();
                                    DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                                }
                                if (music_flag == true) music_back();

                            }
                            //�߂��I��
                            else {
                                omake_Select = 0;
                                for (int i = 0; i < 7; i++) {
                                    if (i == 0) {
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
                                //�^�C�g���ɖ߂�
                                break;
                            }

                            MOVECHARCTor();
                            DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                            //�^�C�g���ɖ߂�
                            if (pauseflag == true) {
                                pauseflag = false;
                                break;
                            }
                        }
                    }
                }
            }
            //�ݒ�
            if (SelectNum == 2) {
                while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0) {
                    //�w�i
                    DrawGraph(0, 0, tosyokan, false);
                    DrawGraph(400, 20, koakuma, true);
                    //���j���[
                    setting();
                    setst(setnum);

                    //SE�ǉ�
                    up_down(se_flag);

                    //BGM�̉���
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[3] + 1.0) * 10.0, title_bgm);
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[3] + 1.0) * 10.0, map_bgm);
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[3] + 1.0) * 10.0, gameover_bgm);
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[3] + 1.0) * 10.0, goal_bgm);

                    //SE�̉���
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[5] + 1.0) * 10.0, hit_se);
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[5] + 1.0) * 10.0, pause_se);
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[5] + 1.0) * 10.0, check_se);
                    ChangeVolumeSoundMem((255.0 / 100.0) * ((double)((double)setstnum[5] + 1.0) * 10.0) , item_se);
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[5] + 1.0) * 10.0, fight_hit_se);
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[5] + 1.0) * 10.0, fight_check_se);
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[5] + 1.0) * 10.0, fight_battle_se);
                    ChangeVolumeSoundMem((255.0 / 100.0) * (double)((double)setstnum[5] + 1.0) * 10.0, level_se);



                    //�߂��I��
                    if (Key[KEY_INPUT_Z] == 1) {
                        if (setnum == setmenu_num-1) {
                            //window�̕ύX�J�n
                            delgraph();
                            screen();
                            graph();
                            //�X�s�[�h�ύX
                            ps();
                            //BGM
                            if (music_set() == 1) {
                                //�L��
                                if(music_flag==true) PlaySoundMem(title_bgm, DX_PLAYTYPE_LOOP);
                                //����
                                else StopSoundMem(title_bgm);
                            }
                            //SE
                            se_set();

                            //���j���[�̏�����
                            for (int i = 0; i < setmenu_num; i++) {
                                if(i==0) Set[i].x=80, Set[i].r = 0, Set[i].g = 0, Set[i].b = 255;
                                else Set[i].x = 100, Set[i].r = 255, Set[i].g = 255, Set[i].b = 255;
                            }
                            setnum = 0;
                            break;
                        }
                    }

                    MOVECHARCTor();
                    DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
                    
                }
            }
            //�Q�[���I��
            if (SelectNum == 3) break;
        }
        MOVECHARCTor();
        DrawGraph(640 - 48, 480 - 48 - 30, playerimage[MOVECHARCTOR], TRUE);
    }
    return 0;
}