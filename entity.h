#include "stdafx.h"

struct Entity
{
	uintptr_t get_engineptr();;
	void force_update();
	bool is_ingame();
	uintptr_t get_team(uintptr_t entity);
	uintptr_t get_health(uintptr_t entity);
	uintptr_t is_dormant(uintptr_t entity);
	uintptr_t get_crosshairid();
	uintptr_t get_entity_incross();
	void force_attack();
	D3DXVECTOR3 get_local_eyepos();
	D3DXVECTOR3 get_local_pos();
	D3DXMATRIX get_local_matrix();
	D3DXVECTOR3 get_local_view();
	void set_local_view(D3DXVECTOR3 angles);
	D3DXVECTOR3 get_local_punch();
	uintptr_t get_entbase(int index);
	bool is_alive(uintptr_t player_base);
	bool is_valid(uintptr_t player_base);
	D3DXVECTOR3	get_ent_pos(uintptr_t playerBase);
	D3DXVECTOR3 get_ent_eye(uintptr_t player_base);
	uintptr_t get_ent_matrix(uintptr_t player_base);
	D3DXVECTOR3	get_ent_bonepos(uintptr_t player_base, int bone_id);
};
extern Entity entity;