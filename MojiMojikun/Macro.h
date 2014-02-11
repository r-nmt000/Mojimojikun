#pragma once
//*********************************************************

//�@�@�@�@�@�@�@�@�@�@�}�N����`

//*********************************************************

#define USE_GLUT
#define GL_WIN_SIZE_X 640
#define GL_WIN_SIZE_Y 480

#define PI	3.141592

#define WAIT_TIME  ( 16 )     //�t���[�����[�g 30fps

//�F�X
#define RED			0
#define GREEN		1
#define BLUE		2
#define LIGHTBLUE	3
#define YELLOW		4
#define ORANGE		5
#define PURPLE		6
#define WHITE		7
#define BLACK		8

//************************
//�e���j���[�A�C�e���̍��W
//************************
//�Q�[���X�^�[�g
#define VIRTEX_X_START			180
#define VIRTEX_Y_START			205
//�Z���N�g���x��
#define VIRTEX_X_LEVEL			 40 
#define VIRTEX_Y_LEVEL			140
//�v���C���[��
#define VIRTEX_X_PLAYNUM		350
#define VIRTEX_Y_PLAYNUM		140
//�w����
#define VIRTEX_X_INST			  0
#define VIRTEX_Y_INST			260
//�L�����u���[�V������
#define VIRTEX_X_CAL			100
#define VIRTEX_Y_CAL			260
//�L�����u���[�V�����~�X
#define VIRTEX_X_CALMISS		100
#define VIRTEX_Y_CALMISS		260
//OK
#define VIRTEX_X_OK				300
#define VIRTEX_Y_OK				260
//���x���n�[�h
#define VIRTEX_X_LEVEL_HARD		 40
#define VIRTEX_Y_LEVEL_HARD		420
//���x���m�[�}��
#define VIRTEX_X_LEVEL_NORMAL	 40
#define VIRTEX_Y_LEVEL_NORMAL	420
//���x���C�[�W�[
#define VIRTEX_X_LEVEL_EASY		 40 
#define VIRTEX_Y_LEVEL_EASY		420
//�v���C����l
#define VIRTEX_X_PLAYNUM_ONE	350
#define VIRTEX_Y_PLAYNUM_ONE	420
//�v���C����l
#define VIRTEX_X_PLAYNUM_TWO	350
#define VIRTEX_Y_PLAYNUM_TWO	420
//�I��
#define VIRTEX_X_EXIT			280
#define VIRTEX_Y_EXIT			 80

//************************
//�e���j���[�A�C�e���̃T�C�Y
//************************
//�|���S���̈�ӂ̒����ƕ����Ԃ̋���
#define V_LEN_BIG				  7
#define SPACE_BIG				  6

#define V_LEN_BIGMID			  6
#define SPACE_BIGMID			  5

#define V_LEN_MID				  5
#define SPACE_MID				  4

#define V_LEN_MIDSMALL			  3.5
#define SPACE_MIDSMALL			  2.5

#define V_LEN_SMALL				  3
#define SPACE_SMALL				  2

//***************************
//�e���j���[�A�C�e���̈ړ���
//***************************
#define MOVE_Y_LEVEL		420
#define MOVE_Y_PLAYNUM		420

#define MOVE_Y_LEVEL_HARD	370
#define MOVE_Y_LEVEL_NORMAL	310
#define MOVE_Y_LEVEL_EASY	260

#define MOVE_Y_PLAYNUM_ONE	370
#define MOVE_Y_PLAYNUM_TWO	310

//********************************
//�e���j���[�A�C�e���̈ړ��X�s�[�h
//********************************
#define SPEED_LEVEL			30
#define SPEED_LEVEL_HARD	15
#define SPEED_LEVEL_NORMAL	15
#define SPEED_LEVEL_EASY	20
#pragma once
#define SPEED_PLAYNUM		30
#define SPEED_PLAYNUM_ONE	15
#define SPEED_PLAYNUM_TWO	15

//***************************
//�Q�[���̓�Փx
//***************************
#define EASY		0
#define NORMAL		1
#define HARD		2

//***************************
//�v���C���[��
//***************************
#define ONE_PLAYER	1
#define TWO_PLAYER	2

//***************************
//�����ړ�����
//***************************
#define UP			true
#define DOWN		false

//***************************
//�ǂ̎��
//***************************
#define T_WALL			0
#define	X_WALL			1
#define Y_WALL			2
#define	H_WALL			3
#define K_WALL			4
#define	V_WALL			5
#define RKAGI_WALL	    6
#define	LKAGI_WALL		7
#define KUNE_WALL	    8
#define	RIKISHI_WALL	9
#define	MANJI_WALL		  10
#define GYAKUMANJI_WALL	  11
#define	BASEBALL_WALL     12
#define MONSTERBALL_WALL  13

#define MO_WALL			14
#define ZI_WALL			101
#define O_WALL			102
//***************************
//���̂�
//***************************
//#define USE_POINTDRAWER